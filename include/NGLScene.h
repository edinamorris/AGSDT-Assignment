#ifndef NGLSCENE_H_
#define NGLSCENE_H_

#include <ngl/Camera.h>
#include <ngl/Transformation.h>
#include <ngl/Vec3.h>
#include <ngl/Text.h>
#include <ngl/Light.h>
#include <QTime>
#include <QEvent>
#include <QResizeEvent>
#include <QOpenGLWidget>
#include <memory>
#include "WindowParams.h"
#include "ParticleManager.h"
#include "Scenes.h"

/// @file NGLScene.h
/// @brief a basic Qt GL window class for ngl demos
/// @author Jonathan Macey
/// @version 1.0
/// @date 10/10/10
/// Revision History :
/// Initial Version 10/10/10 (Binary day ;-0 )
/// @class GLWindow
/// @brief our main glwindow widget for NGL applications all drawing elements are
/// put in this file
class NGLScene : public QOpenGLWidget
{
Q_OBJECT        // must include this if you use Qt signals/slots
public :
    /// @brief Constructor for GLWindow
    /// @param [in] _parent the parent window to create the GL context in
    //----------------------------------------------------------------------------------------------------------------------
    NGLScene(QWidget *_parent );

    /// @brief dtor
    ~NGLScene();
public slots :
    void toggleRain(bool _rain);
    void toggleSnow(bool _snow);
    void weatherStrength(int _strength);
    void weatherHeaviness(int _heaviness);
    void toggleScene1(bool _scene1);
    void toggleScene2(bool _scene2);
    void toggleScene3(bool _scene3);
    void windSpeed(int _speed);
    void windDirection(int _direction);
    void particleSize(int _size);

private :
    //testing signals and slots
    bool m_rain;
    bool m_snow;
    int m_weatherStrength;
    int m_weatherHeaviness;
    bool m_scene1;
    bool m_scene2;
    bool m_scene3;
    int m_windSpeed;
    int m_windDirection;
    int m_particleSize;

    ParticleManager particleSystem;
    Scenes objectCollision;

public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the windows params such as mouse and rotations etc
    //----------------------------------------------------------------------------------------------------------------------
    WinParams m_win;

    /// @brief  The following methods must be implimented in the sub class
    /// this is called when the window is created
    void initializeGL() override;

    /// @brief this is called whenever the window is re-sized
    /// @param[in] _w the width of the resized window
    /// @param[in] _h the height of the resized window
    void resizeGL(int _w , int _h) override;
    /// @brief this is the main gl drawing routine which is called whenever the window needs to be re-drawn
    void paintGL() override;

    /// @brief our model position
    ngl::Vec3 m_modelPos;
    /// @brief our camera
    ngl::Camera m_cam;
    /// @brief used to store the global mouse transforms
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Mat4 m_mouseGlobalTX;
    /// @brief our transform for objects
    ngl::Transformation m_transform;

    //light position
    ngl::Vec3 m_lightPos;

    /// @brief this method is called every time a mouse is moved
    /// @param _event the Qt Event structure
    void mouseMoveEvent (QMouseEvent * _event   ) override;

    /// @brief this method is called everytime the mouse button is pressed
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    void mousePressEvent ( QMouseEvent *_event  ) override;

    /// @brief this method is called everytime the mouse button is released
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    void mouseReleaseEvent (QMouseEvent *_event ) override;

    void wheelEvent( QWheelEvent* _event ) override;

    void loadMatricesToShader( );

    /// @brief create a VBO cube and store in a vao m_vaoID
    //----------------------------------------------------------------------------------------------------------------------
    void createCube( GLfloat _scale );
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief timer event used for the fps counter
    //----------------------------------------------------------------------------------------------------------------------
    void timerEvent(QTimerEvent *) override;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief ID for the cube VAO
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_vaoID;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief load the snow texture and store the id in m_textureName
    //----------------------------------------------------------------------------------------------------------------------
    void loadTextures();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief opengl texture id for the snow texture
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_textureNameSnow;
    //rain texture
    GLuint m_textureNameRain;
    //floor texture
    GLuint m_textureNameFloor;
    //obstacle texture
    GLuint m_textureNameObstacle;
    //highrise texture
    GLuint m_textureNameHighRise;

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief our font / text
    //----------------------------------------------------------------------------------------------------------------------
    std::unique_ptr<ngl::Text> m_text;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief our font / text
    //----------------------------------------------------------------------------------------------------------------------
    GLenum m_polyMode;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag for the fps timer
    //----------------------------------------------------------------------------------------------------------------------
    int m_fpsTimer;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the fps to draw
    //----------------------------------------------------------------------------------------------------------------------
    int m_fps;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief frame counter
    //----------------------------------------------------------------------------------------------------------------------
    int m_frames;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief timer used for FPS counting
    //----------------------------------------------------------------------------------------------------------------------
    QTime m_timer;

};

#endif
