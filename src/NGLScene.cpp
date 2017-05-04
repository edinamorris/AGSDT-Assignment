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
#include <time.h>
#include <boost/format.hpp>

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
    m_windSpeed=0;
    m_windDirection=0;
    m_particleSize=0;
    m_fpsTimer =startTimer(0);
    m_fps=0;
    m_frames=0;
    m_timer.start();
    m_polyMode=GL_FILL;
    m_modelPos.m_x=-40;
    m_modelPos.m_y=-5;
    m_numberOfLights=2;
    m_lightPos=new ngl::Vec3[m_numberOfLights];
    m_lightPos[0]=ngl::Vec3(1.55, 2.0, -4.3);
    m_lightPos[1]=ngl::Vec3(1.15, 0.01, 4.9);
}

//loading all textures in scene
void NGLScene::loadTextures()
{
    //snow
    QImage image;
    bool loaded=image.load("textures/snowflake.png");
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

    glGenTextures(1,&m_textureNameSnow);
    glBindTexture(GL_TEXTURE_2D,m_textureNameSnow);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);

    glGenerateMipmap(GL_TEXTURE_2D); //  Allocate the mipmaps

    }

    //rain
    loaded=image.load("textures/rain_1.png");
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

    glGenTextures(1,&m_textureNameRain);
    glBindTexture(GL_TEXTURE_2D,m_textureNameRain);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);

    glGenerateMipmap(GL_TEXTURE_2D); //  Allocate the mipmaps

    }

    //floor
    loaded=image.load("textures/concrete.jpg");
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

    glGenTextures(1,&m_textureNameFloor);
    glBindTexture(GL_TEXTURE_2D,m_textureNameFloor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);

    glGenerateMipmap(GL_TEXTURE_2D); //  Allocate the mipmaps

    }

    //building texture
    loaded=image.load("textures/building.png");
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

    glGenTextures(1,&m_textureNameObstacle);
    glBindTexture(GL_TEXTURE_2D,m_textureNameObstacle);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);

    glGenerateMipmap(GL_TEXTURE_2D); //  Allocate the mipmaps

    }

    //highrise texture
    loaded=image.load("textures/highrise.bmp");
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

    glGenTextures(1,&m_textureNameHighRise);
    glBindTexture(GL_TEXTURE_2D,m_textureNameHighRise);
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
                         1,1,-1,1,1,1,1,-1,-1, 1,-1,-1,1,-1,1,1,1,1, // right

                         };
    GLfloat texture[] = {
                        0,0,0,1,1,1 ,0,0,1,0,1,1, //back
                        0,0,0,1,1,1 ,1,0,1,1,0,0, // front - had to fix, texture values were wrong
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
    GLuint vboID[3];
    glGenBuffers(3, &vboID[0]);
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

    // normals
    glBindBuffer(GL_ARRAY_BUFFER, vboID[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices)*sizeof(GLfloat), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(2,3,GL_FLOAT,false,0,0);
    glEnableVertexAttribArray(2);
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

    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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

    shader->setRegisteredUniform("lightDiffuse", 1.0f,1.0f,1.0f,1.0f);
    shader->setShaderParam1f("Normalize",1);

    createCube(0.2);
    loadTextures();
    m_text.reset( new ngl::Text(QFont("Arial",14)));
    m_text->setScreenSize(width(),height());

    // Now we will create a basic Camera from the graphics library
    // This is a static camera so it only needs to be set once
    // First create Values for the camera position
    ngl::Vec3 from( 50, 10, 1);
    ngl::Vec3 to( 0, 7, 0 );
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

    ngl::Mat3 normalMatrix;
    ngl::Mat3 MV;
    MV=m_transform.getMatrix() *m_mouseGlobalTX*m_cam.getViewMatrix();
    // calculate normal matrix by getting the top 3x3 of the MV
    normalMatrix=MV;
    // then calculate the inverse
    normalMatrix.inverse();
    shader->setShaderParamFromMat3("normalMatrix",normalMatrix);
}

//----------------------------------------------------------------------------------------------------------------------
//This virtual function is called whenever the widget needs to be painted.
// this is our main drawing routine
void NGLScene::paintGL()
{
    //time
    //clock_t t;
    //t = clock();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,m_win.width,m_win.height);
    //ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();

    ngl::ShaderLib *shader=ngl::ShaderLib::instance();
    (*shader)["Phong"]->use();

    // Rotation based on the mouse position for our global transform
    ngl::Mat4 rotX;
    ngl::Mat4 rotY;
    // create the rotation matrices
    rotX.rotateX( 0 );
    rotY.rotateY( m_win.spinYFace );
    // multiply the rotations
    m_mouseGlobalTX = rotY * rotX;
    // add the translations
    m_mouseGlobalTX.m_m[ 3 ][ 0 ] = m_modelPos.m_x;
    m_mouseGlobalTX.m_m[ 3 ][ 1 ] = m_modelPos.m_y;
    m_mouseGlobalTX.m_m[ 3 ][ 2 ] = m_modelPos.m_z;

	loadMatricesToShader();

    for(int i=0; i<m_numberOfLights; i++)
    {
        std::string name=boost::str(boost::format("light[%d]") % i );

        shader->setShaderParam3f(name, m_lightPos[i].m_x, m_lightPos[i].m_y, m_lightPos[i].m_z);
    }

    // now we bind back our vertex array object and draw
    glBindVertexArray(m_vaoID);		// select first VAO

    shader->setRegisteredUniform("particle", false);
    //floor
    glBindTexture(GL_TEXTURE_2D,m_textureNameFloor);
    glPolygonMode(GL_FRONT_AND_BACK,m_polyMode);
    m_transform.reset();
    m_transform.setPosition(0, -10, 0);
    m_transform.setScale(250.0, 1.0, 250.0);
    loadMatricesToShader();
    glDrawArrays(GL_TRIANGLES, 0,36 );

    //drawing current scene
    if(m_scene1==true||m_scene2==true||m_scene3==true)
    {
        glBindTexture(GL_TEXTURE_2D,m_textureNameObstacle);
        glPolygonMode(GL_FRONT_AND_BACK,m_polyMode);
        //drawing obstacles
        for(int i=0; i<objectCollision.getNumberObstacles()/2; i++)
        {
            m_transform.reset();

            m_transform.setPosition(objectCollision.m_sceneObjects[i].position.m_x,
            objectCollision.m_sceneObjects[i].position.m_y,
            objectCollision.m_sceneObjects[i].position.m_z);
            m_transform.setScale(objectCollision.m_sceneObjects[i].scale.m_x,
            objectCollision.m_sceneObjects[i].scale.m_y,
            objectCollision.m_sceneObjects[i].scale.m_z);
            loadMatricesToShader();
            glDrawArrays(GL_TRIANGLES, 0,36 );
        }
        glBindTexture(GL_TEXTURE_2D,m_textureNameHighRise);
        glPolygonMode(GL_FRONT_AND_BACK,m_polyMode);
        //drawing obstacles
        for(int i=objectCollision.getNumberObstacles()/2; i<objectCollision.getNumberObstacles(); i++)
        {
            m_transform.reset();

            m_transform.setPosition(objectCollision.m_sceneObjects[i].position.m_x,
            objectCollision.m_sceneObjects[i].position.m_y,
            objectCollision.m_sceneObjects[i].position.m_z);
            m_transform.setScale(objectCollision.m_sceneObjects[i].scale.m_x,
            objectCollision.m_sceneObjects[i].scale.m_y,
            objectCollision.m_sceneObjects[i].scale.m_z);
            loadMatricesToShader();
            glDrawArrays(GL_TRIANGLES, 0,36 );
        }
    }

    int instances=particleSystem.getNumberOfParticles();

    if(m_snow==true)
    {
        shader->setRegisteredUniform("particle", true);
        // need to bind the active texture before drawing
        glBindTexture(GL_TEXTURE_2D,m_textureNameSnow);
        glPolygonMode(GL_FRONT_AND_BACK,m_polyMode);
        //drawing particles
        for(int i=0; i<particleSystem.getNumberOfParticles(); i++)
        {
            m_transform.reset();
            {
                ngl::Vec3 particlePosition=particleSystem.system[i].getPosition();
                ngl::Vec3 particleRotation=particleSystem.system[i].getRotation();
                ngl::Vec3 particleSize=particleSystem.system[i].getSize();
                m_transform.setPosition(particlePosition.m_x,
                                        particlePosition.m_y,
                                        particlePosition.m_z);
                m_transform.setRotation(particleRotation.m_x,
                                        particleRotation.m_y,
                                        particleRotation.m_z);
                m_transform.setScale(particleSize.m_x,
                                     particleSize.m_y,
                                     particleSize.m_z);
                loadMatricesToShader();
                //++instances;
                glDrawArrays(GL_TRIANGLES, 0,36 );	// draw object
            }
        }
    }
    else if(m_rain==true)
    {
        shader->setRegisteredUniform("particle", true);
        // need to bind the active texture before drawing
        glBindTexture(GL_TEXTURE_2D,m_textureNameRain);
        glPolygonMode(GL_FRONT_AND_BACK,m_polyMode);
        //drawing particles
        for(int i=0; i<particleSystem.getNumberOfParticles(); i++)
        {
            m_transform.reset();
            {
                ngl::Vec3 particlePosition=particleSystem.system[i].getPosition();
                ngl::Vec3 particleRotation=particleSystem.system[i].getRotation();
                ngl::Vec3 particleSize=particleSystem.system[i].getSize();
                m_transform.setPosition(particlePosition.m_x,
                                        particlePosition.m_y,
                                        particlePosition.m_z);
                m_transform.setRotation(particleRotation.m_x,
                                        particleRotation.m_y,
                                        particleRotation.m_z);
                m_transform.setScale(particleSize.m_x,
                                     particleSize.m_y,
                                     particleSize.m_z);
                loadMatricesToShader();
                //++instances;
                glDrawArrays(GL_TRIANGLES, 0,36 );	// draw object
            }
        }
        for(int i=0; i<int(particleSystem.rainSplashes.size()); i++)
        {
            ngl::Vec3 particlePosition=particleSystem.rainSplashes[i].getPosition();
            ngl::Vec3 particleRotation=particleSystem.rainSplashes[i].getRotation();
            ngl::Vec3 particleSize=particleSystem.rainSplashes[i].getSize();
            m_transform.setPosition(particlePosition.m_x,
                                    particlePosition.m_y,
                                    particlePosition.m_z);
            m_transform.setRotation(particleRotation.m_x,
                                    particleRotation.m_y,
                                    particleRotation.m_z);
            m_transform.setScale(particleSize.m_x,
                                 particleSize.m_y,
                                 particleSize.m_z);
            loadMatricesToShader();
            glDrawArrays(GL_TRIANGLES, 0,36 );	// draw object
        }
    }

    // calculate and draw FPS
    ++m_frames;
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    m_text->setColour(0,0,0);
    QString text=QString("Particles %1  %2 fps").arg(instances).arg(m_fps);
    m_text->renderText(10,20,text);

    //t = clock() - t;
    //printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
}

NGLScene::~NGLScene()
{
    // remove the texture now we are done
    glDeleteTextures(1,&m_textureNameRain);
    glDeleteTextures(1,&m_textureNameSnow);
    glDeleteTextures(1,&m_textureNameFloor);
    glDeleteTextures(1,&m_textureNameObstacle);
    glDeleteTextures(1,&m_textureNameHighRise);
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
    if(m_snow==true||m_rain==true)
    {
        particleSystem.update();
    }
}

void NGLScene::toggleSnow(bool _snow)
{
    m_snow=_snow;
    if(m_snow==true)
    {
        std::cout<<"Snowing \n";
        m_rain=false;
        particleSystem.setSnow(false);
    }
    particleSystem.setSnow(_snow);
}

void NGLScene::toggleRain(bool _rain)
{
    m_rain=_rain;
    if(m_rain==true)
    {
        std::cout<<"Raining \n";
        m_snow=false;
        particleSystem.setSnow(false);
    }
    particleSystem.setRain(_rain);
}

void NGLScene::weatherStrength(int _strength)
{
    m_weatherStrength=_strength;
    particleSystem.setWindStrength(_strength);
}

void NGLScene::weatherHeaviness(int _heaviness)
{
    m_weatherHeaviness=_heaviness;
    particleSystem.setHeaviness(_heaviness);
}

void NGLScene::toggleScene1(bool _scene1)
{
    m_scene1=_scene1;
    objectCollision.setScene(1);
    objectCollision.Scene1();
    particleSystem.setScene(1);
}

void NGLScene::toggleScene2(bool _scene2)
{
    m_scene2=_scene2;
    particleSystem.setScene(2);
    objectCollision.setScene(2);
    objectCollision.Scene2();
}

void NGLScene::toggleScene3(bool _scene3)
{
    m_scene3=_scene3;
    particleSystem.setScene(3);
    objectCollision.setScene(3);
    objectCollision.Scene3();
}

void NGLScene::windSpeed(int _speed)
{
    m_windSpeed=_speed;
    particleSystem.setWindSpeed(_speed);
}

void NGLScene::windDirection(int _direction)
{
    m_windDirection=_direction;
    //correcting angle
    if(m_windDirection<180)
    {
        m_windDirection+=180;
    }
    else
    {
        m_windDirection-=180;
    }
    particleSystem.setWind(m_windDirection);
}

void NGLScene::particleSize(int _size)
{
    m_particleSize=_size;
    particleSystem.setParticleSize(m_particleSize);
}
