/// @file NGLScene.h
/// @brief a basic Qt GL window class for ngl demos
/// @author Jonathan Macey, edited by Edina Morris
/// @version 1.0
/// @date 10/10/10
/// Revision History :
/// Initial Version 10/10/10 (Binary day ;-0 )
/// @class GLWindow
/// @brief our main glwindow widget for NGL applications all drawing elements are
/// put in this file

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
#include <thread>
#include "WindowParams.h"
#include "ParticleManager.h"
#include "Scenes.h"

class NGLScene : public QOpenGLWidget
{
Q_OBJECT
public :
    //----------------------------------------------------------------------------------------------------------------------
  /// @brief Constructor for GLWindow
  /// @param [in] _parent the parent window to create the GL context in
  NGLScene(QWidget *_parent );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief dtor
  ~NGLScene();
  //----------------------------------------------------------------------------------------------------------------------

public slots :
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief when user toggles on rain from the user interface, turning rain on has the effect of turning snow off
  /// @param[in] _rain whether rain has been selected
  void toggleRain(bool _rain);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief when user toggles on snow from the user interface, turning snow on has the effect of turning rain off
  /// @param[in] _snow whether snow has been selected
  void toggleSnow(bool _snow);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief effects the speed of the falling weather by use of slider
  /// @param[in] _strength the speed of the weather fall
  void weatherStrength(int _strength);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief heaviness effects the number of particles and therefore the heaviness of the weather by use of slider
  /// @param[in] _heaviness the number of particles in system
  void weatherHeaviness(int _heaviness);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief when user switches to scene 1 from the user interface, scene selection is a radio button
  /// @param[in] _scene1 whether scene1 has been selected
  void toggleScene1(bool _scene1);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief when user switches to scene 2 from the user interface, scene selection is a radio button
  /// @param[in] _scene2 whether scene2 has been selected
  void toggleScene2(bool _scene2);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief when user switches to scene 3 from the user interface, scene selection is a radio button
  /// @param[in] _scene3 whether scene3 has been selected
  void toggleScene3(bool _scene3);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the wind speed effects how much particles move and angle by use of slider
  /// @param[in] _windSpeed of wind effect, how strong it is
  void windSpeed(int _speed);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the direction is controlled using a dial, north = 0 degrees, south =180
  /// @param[in] _direction of wind effect
  void windDirection(int _direction);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief makes the average particle size larger or smaller by use of slider
  /// @param[in] _size effects the average size of a particle
  void particleSize(int _size);
  //----------------------------------------------------------------------------------------------------------------------

private :
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief made true when toggleRain slot is called
  bool m_rain;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief made true when toggleSnow slot is called
  bool m_snow;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief value changed when weatherStrength slot is called
  int m_weatherStrength;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief value changed when weatherHeaviness slot is called
  int m_weatherHeaviness;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief made true when toggleScene1 slot is called
  bool m_scene1;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief made true when toggleScene2 slot is called
  bool m_scene2;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief made true when toggleScene3 slot is called
  bool m_scene3;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief value changed when windSpeed slot is called
  int m_windSpeed;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief value changed when windDirection slot is called
  int m_windDirection;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief value changed when particleSize slot is called
  int m_particleSize;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief class instances, used for getting particle attributes and scene object attributes
  ParticleManager particleSystem;
  Scenes objectCollision;
  //----------------------------------------------------------------------------------------------------------------------

public:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the windows params such as mouse and rotations etc
  WinParams m_win;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief  The following methods must be implimented in the sub class
  /// this is called when the window is created
  void initializeGL() override;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this is called whenever the window is re-sized
  /// @param[in] _w the width of the resized window
  /// @param[in] _h the height of the resized window
  void resizeGL(int _w , int _h) override;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this is the main gl drawing routine which is called whenever the window needs to be re-drawn
  void paintGL() override;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief our model position
  ngl::Vec3 m_modelPos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief our camera
  ngl::Camera m_cam;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief our light positions
  ngl::Vec3 *m_lightPos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief our number of lights
  int m_numberOfLights;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to store the global mouse transforms
  ngl::Mat4 m_mouseGlobalTX;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief our transform for objects
  ngl::Transformation m_transform;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called every time a mouse is moved
  /// @param _event the Qt Event structure
  void mouseMoveEvent (QMouseEvent * _event   ) override;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called everytime the mouse button is pressed
  /// inherited from QObject and overridden here.
  /// @param _event the Qt Event structure
  void mousePressEvent ( QMouseEvent *_event  ) override;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called everytime the mouse button is released
  /// inherited from QObject and overridden here.
  /// @param _event the Qt Event structure
  void mouseReleaseEvent (QMouseEvent *_event ) override;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called everytime the mouse wheel button is used
  /// inherited from QObject and overridden here.
  /// @param _event the Qt Event structure
  void wheelEvent( QWheelEvent* _event ) override;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method loads all matrices to shader
  void loadMatricesToShader( );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief create a VBO cube and store in a vao m_vaoID
  void createCube( GLfloat _scale );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief timer event used for the fps counter
  void timerEvent(QTimerEvent *) override;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief ID for the cube VAO
  GLuint m_vaoID;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief load the snow texture and store the id in m_textureName
  void loadTextures();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief opengl texture id for the snow texture
  GLuint m_textureNameSnow;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief opengl texture id for the rain texture
  GLuint m_textureNameRain;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief opengl texture id for the ground texture
  GLuint m_textureNameFloor;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief opengl texture id for the first building texture
  GLuint m_textureNameObstacle;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief opengl texture id for the second building texture
  GLuint m_textureNameHighRise;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief our font / text
  std::unique_ptr<ngl::Text> m_text;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief our font / text
  GLenum m_polyMode;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief flag for the fps timer
  int m_fpsTimer;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the fps to draw
  int m_fps;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief frame counter
  int m_frames;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief timer used for FPS counting
  QTime m_timer;
  //----------------------------------------------------------------------------------------------------------------------

};

#endif      // NGLSCENE_H_
