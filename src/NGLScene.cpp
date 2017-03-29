#include "NGLScene.h"
#include "ParticleManager.h"
#include <iostream>
#include <ngl/Vec3.h>
#include <ngl/Light.h>
#include <ngl/NGLInit.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/Material.h>
#include <ngl/ShaderLib.h>
#include <QColorDialog>
#include <QFont>


//----------------------------------------------------------------------------------------------------------------------
NGLScene::NGLScene( QWidget *_parent ) : QOpenGLWidget( _parent )
{

    // set this widget to have the initial keyboard focus
    setFocus();
    // re-size the widget to that of the parent (in this case the GLFrame passed in on construction)
    this->resize(_parent->size());
    m_rain=false;
    m_snow=false;
    m_scene1=false;
    m_scene2=false;
    m_scene3=false;
    m_weatherHeaviness=0;
    m_weatherStrength=0;
    m_fpsTimer =startTimer(0);
    m_fps=0;
    m_frames=0;
    m_timer.start();
    m_polyMode=GL_FILL;
}

void NGLScene::loadTexture()
{
    QImage image;
    bool loaded=image.load("textures/snowflake.bmp");
    if(loaded == true)
    {
        int width=image.width();
        int height=image.height();

        unsigned char *data = new unsigned char[ width*height*3];
        unsigned int index=0;
        QRgb colour;
        for( int y=0; y<height; ++y)
        {
            for( int x=0; x<width; ++x)
            {
                colour=image.pixel(x,y);

                data[index++]=qRed(colour);
                data[index++]=qGreen(colour);
                data[index++]=qBlue(colour);
            }
        }

    glGenTextures(1,&m_textureName);
    glBindTexture(GL_TEXTURE_2D,m_textureName);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);

    glGenerateMipmap(GL_TEXTURE_2D); //  Allocate the mipmaps

    }
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief create a cube and stuff it into a VBO on the GPU
/// @param[in] _scale a scale factor for the unit vertices
void NGLScene::createCube( GLfloat _scale )
{

   // vertex coords array
    GLfloat vertices[] = {
                         -1,1,-1,1,1,-1,1,-1,-1, -1,1,-1,-1,-1,-1,1,-1,-1, //back
                         -1,1,1,1,1,1,1,-1,1, -1,-1,1, 1,-1,1,-1,1,1,  //front
                         -1,1,-1, 1,1,-1, 1,1,1, -1,1,1, 1,1,1, -1,1,-1, // top
                         -1,-1,-1, 1,-1,-1, 1,-1,1, -1,-1,1, 1,-1,1, -1,-1,-1, // bottom
                         -1,1,-1,-1,1,1,-1,-1,-1, -1,-1,-1,-1,-1,1,-1,1,1, // left
                         1,1,-1,1,1,1,1,-1,-1, 1,-1,-1,1,-1,1,1,1,1, // left

                         };
    GLfloat texture[] = {
                        0,0,0,1,1,1 ,0,0,1,0,1,1, //back
                        0,1,1,0,1,1 ,0,0,1,0,0,1, // front
                        0,0,1,0,1,1 ,0,1,1,1,0,0, //top
                        0,0,1,0,1,1 ,0,1,1,1,0,0, //bottom
                        1,0,1,1,0,0 ,0,0,0,1,1,1, // left
                        1,0,1,1,0,0 ,0,0,0,1,1,1, // right

                        };

    // first we scale our vertices to _scale
    for(uint i=0; i<sizeof(vertices)/sizeof(GLfloat); ++i)
    {
        vertices[i]*=_scale;
    }

    // first we create a vertex array Object
    glGenVertexArrays(1, &m_vaoID);

    // now bind this to be the currently active one
    glBindVertexArray(m_vaoID);
    // now we create two VBO's one for each of the objects these are only used here
    // as they will be associated with the vertex array object
    GLuint vboID[2];
    glGenBuffers(2, &vboID[0]);
    // now we will bind an array buffer to the first one and load the data for the verts
    glBindBuffer(GL_ARRAY_BUFFER, vboID[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices)*sizeof(GLfloat), vertices, GL_STATIC_DRAW);
    // now we bind the vertex attribute pointer for this object in this case the
    // vertex data
    glVertexAttribPointer(0,3,GL_FLOAT,false,0,0);
    glEnableVertexAttribArray(0);
    // now we repeat for the UV data using the second VBO
    glBindBuffer(GL_ARRAY_BUFFER, vboID[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texture)*sizeof(GLfloat), texture, GL_STATIC_DRAW);
    glVertexAttribPointer(1,2,GL_FLOAT,false,0,0);
    glEnableVertexAttribArray(1);
}

// This virtual function is called once before the first call to paintGL() or resizeGL(),
//and then once whenever the widget has been assigned a new QGLContext.
// This function should set up any required OpenGL context rendering flags, defining display lists, etc.

//----------------------------------------------------------------------------------------------------------------------
void NGLScene::initializeGL()
{
    // we must call that first before any other GL commands to load and link the
    // gl commands from the lib, if that is not done program will crash
    ngl::NGLInit::instance();
    glClearColor( 0.4f, 0.4f, 0.4f, 1.0f ); // Grey Background
    // enable depth testing for drawing
    glEnable( GL_DEPTH_TEST );
    // enable multisampling for smoother drawing
    #ifndef USINGIOS_
      glEnable( GL_MULTISAMPLE );
    #endif
    // now to load the shader and set the values
    // grab an instance of shader manager
    ngl::ShaderLib* shader = ngl::ShaderLib::instance();
    // we are creating a shader called Phong to save typos
    // in the code create some constexpr
    constexpr auto shaderProgram = "Phong";
    constexpr auto vertexShader  = "PhongVertex";
    constexpr auto fragShader    = "PhongFragment";

    // create the shader program
    shader->createShaderProgram( shaderProgram );
    // now we are going to create empty shaders for Frag and Vert
    shader->attachShader( vertexShader, ngl::ShaderType::VERTEX );
    shader->attachShader( fragShader, ngl::ShaderType::FRAGMENT );
    // attach the source
    shader->loadShaderSource( vertexShader, "shaders/PhongVertex.glsl" );
    shader->loadShaderSource( fragShader, "shaders/PhongFragment.glsl" );
    // compile the shaders
    shader->compileShader( vertexShader );
    shader->compileShader( fragShader );
    // add them to the program
    shader->attachShaderToProgram( shaderProgram, vertexShader );
    shader->attachShaderToProgram( shaderProgram, fragShader );


    // now we have associated that data we can link the shader
    shader->linkProgramObject( shaderProgram );
    // and make it active ready to load values
    ( *shader )[ shaderProgram ]->use();

    // the shader will use the currently active material and light0 so set them
    //ngl::Material m( ngl::STDMAT::GOLD );
    // load our material values to the shader into the structure material (see Vertex shader)
    //m.loadToShader( "material" );

    createCube(0.2);
    loadTexture();
    m_text.reset( new ngl::Text(QFont("Arial",14)));
    m_text->setScreenSize(width(),height());

    // Now we will create a basic Camera from the graphics library
    // This is a static camera so it only needs to be set once
    // First create Values for the camera position
    ngl::Vec3 from( 0, 1, 2 );
    ngl::Vec3 to( 0, 0, 0 );
    ngl::Vec3 up( 0, 1, 0 );
    // now load to our new camera
    m_cam.set( from, to, up );
    // set the shape using FOV 45 Aspect Ratio based on Width and Height
    // The final two are near and far clipping planes of 0.5 and 10
    m_cam.setShape( 45.0f, 720.0f / 576.0f, 0.05f, 350.0f );
}

//----------------------------------------------------------------------------------------------------------------------
//This virtual function is called whenever the widget has been resized.
// The new size is passed in width and height.
void NGLScene::resizeGL( int _w, int _h )
{
    m_cam.setShape( 45.0f, static_cast<float>( _w ) / _h, 0.05f, 350.0f );
    m_win.width  = static_cast<int>( _w * devicePixelRatio() );
    m_win.height = static_cast<int>( _h * devicePixelRatio() );
}


void NGLScene::loadMatricesToShader()
{
    ngl::ShaderLib* shader = ngl::ShaderLib::instance();

    ngl::Mat4 MVP=m_transform.getMatrix() *m_mouseGlobalTX*m_cam.getVPMatrix();

    shader->setRegisteredUniform("MVP",MVP);
}

//----------------------------------------------------------------------------------------------------------------------
//This virtual function is called whenever the widget needs to be painted.
// this is our main drawing routine
void NGLScene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,m_win.width,m_win.height);
    //ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();

    ngl::ShaderLib *shader=ngl::ShaderLib::instance();
    (*shader)["Phong"]->use();

    // Rotation based on the mouse position for our global transform
    ngl::Mat4 rotX;
    ngl::Mat4 rotY;
    // create the rotation matrices
    rotX.rotateX( m_win.spinXFace );
    rotY.rotateY( m_win.spinYFace );
    // multiply the rotations
    m_mouseGlobalTX = rotY * rotX;
    // add the translations
    m_mouseGlobalTX.m_m[ 3 ][ 0 ] = m_modelPos.m_x;
    m_mouseGlobalTX.m_m[ 3 ][ 1 ] = m_modelPos.m_y;
    m_mouseGlobalTX.m_m[ 3 ][ 2 ] = m_modelPos.m_z;

	loadMatricesToShader();

    // now we bind back our vertex array object and draw
    glBindVertexArray(m_vaoID);		// select first VAO

    int instances=0;
    // need to bind the active texture before drawing
    glBindTexture(GL_TEXTURE_2D,m_textureName);
    glPolygonMode(GL_FRONT_AND_BACK,m_polyMode);

    //looping through to create a grid of cubes will replace with particle system
    for (float z=-14; z<15; z+=0.5)
    {
        for (float x=-14; x<15; x+=0.5)
        {
            m_transform.reset();
            {
                m_transform.setRotation(x*20,(x*z)*40,z*2);
                m_transform.setPosition(x,0.49,z);
                loadMatricesToShader();
                ++instances;
                glDrawArrays(GL_TRIANGLES, 0,36 );	// draw object
            }
        }
    }
    // calculate and draw FPS
    ++m_frames;
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    m_text->setColour(0,0,0);
    QString text=QString("Particles %1  %2 fps").arg(instances).arg(m_fps);
    m_text->renderText(10,20,text);

    //before textures
    //prim->draw("cube");
}

NGLScene::~NGLScene()
{
    // remove the texture now we are done
    glDeleteTextures(1,&m_textureName);
}

void NGLScene::timerEvent(QTimerEvent *_event)
{
    if(_event->timerId() == m_fpsTimer)
        {
            if( m_timer.elapsed() > 1000.0)
            {
                m_fps=m_frames;
                m_frames=0;
                m_timer.restart();
            }
         }
    // re-draw GL
    update();
    //update particleManager - runs all functions which calculates particles new positions
}

void NGLScene::toggleSnow(bool _snow)
{
    m_snow=_snow;
    if(m_snow==true)
    {
        std::cout<<"Snowing \n";
        m_rain=false;
        userValues.setSnow(false);
    }
    userValues.setSnow(_snow);
}

void NGLScene::toggleRain(bool _rain)
{
    m_rain=_rain;
    if(m_rain==true)
    {
        std::cout<<"Raining \n";
        m_snow=false;
        userValues.setSnow(false);
    }
    userValues.setRain(_rain);
}

void NGLScene::weatherStrength(int _strength)
{
    m_weatherStrength=_strength;
    std::cout<<"Weather strength is > "<<m_weatherStrength<<"\n";
    userValues.setWindStrength(_strength);
}

void NGLScene::weatherHeaviness(int _heaviness)
{
    m_weatherHeaviness=_heaviness;
    std::cout<<"Weather heaviness is > "<<m_weatherHeaviness<<"\n";
    userValues.setHeaviness(_heaviness);
}

void NGLScene::toggleScene1(bool _scene1)
{
    m_scene1=_scene1;
    std::cout<<"scene 1\n";
    userValues.setScene(1);
}

void NGLScene::toggleScene2(bool _scene2)
{
    m_scene2=_scene2;
    std::cout<<"scene 2\n";
    userValues.setScene(2);
}

void NGLScene::toggleScene3(bool _scene3)
{
    m_scene3=_scene3;
    std::cout<<"scene 3\n";
    userValues.setScene(3);
}

