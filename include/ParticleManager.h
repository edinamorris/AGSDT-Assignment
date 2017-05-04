/// @file ParticleManager.h
/// @brief simple class to manage particles, manages creation, deleting and updating
/// @author Edina Morris
/// @version 1.0
/// @date 04/05/17

#ifndef PARTICLEMANAGER_H_
#define PARTICLEMANAGER_H_

#include "Particle.h"
#include "Scenes.h"
#include <vector>
#include <thread>

class ParticleManager
{
public:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief default constructor
  ParticleManager();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief default destructor
  ~ParticleManager();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief instance of particle
  Particle *system;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief instance of obstacles
  Scenes obstacles;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief vector for rain splash's
  std::vector<Particle> rainSplashes;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief c++11 thread
  std::thread *t;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief changing number of particles in the scene, linked to user interface slider
  void addParticle();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief calculating new position of particle with forces acting on it, eg gravity
  /// @param[in] _tid thread ID
  void calculateNewPos(int _tid);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief updating speed that particles fall
  void updateHeaviness();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief altering particles position based on wind direction and speed
  void outsideInfluence();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to run all updating functions
  void update();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief moves dead particles back to reset position
  void moveDeadParticles();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief checking particle collision with floor
  void checkCollision();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief checking particle collision with buildings
  void checkCollisionBuildings();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief creating and setting new splash particles
  /// @param[in] Id of current particle that is splashing
  void splash(int _particleId);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Proving the collision for the particles, for snow this will melt, for rain this will update the secondary particle's positiosn
  void colliding();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief updating the size of the particles
  void updateSize();
  //----------------------------------------------------------------------------------------------------------------------

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor method which returns the current number of particles
  /// @param[out] m_numberParticles current number of particles
  int getNumberOfParticles(){return m_numberParticles;}
  //----------------------------------------------------------------------------------------------------------------------

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method which sets class wind strength to incoming wind strength from UI
  /// @param[in] _windStrength the speed of the particle's fall rate
  void setWindStrength(int _windStrength){m_windStrength=_windStrength;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method which sets class heaviness to incoming heaviness from UI
  /// @param[in] _heaviness amount of particles
  void setHeaviness(int _heaviness){m_heaviness=_heaviness;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method which sets class scene selection to incoming scene selection from UI
  /// @param[in] _scene the current scene
  void setScene(int _scene){m_scene=_scene;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method which sets class rain flag to incoming rain flag from UI
  /// @param[in] _rain whether the system is raining
  void setRain(bool _rain){m_rain=_rain;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method which sets class snow flag to incoming snow flag from UI
  /// @param[in] _snow whether the system is snowing
  void setSnow(bool _snow){m_snow=_snow;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method which sets class wind speed to incoming wind speed from UI
  /// @param[in] _speed the current wind speed
  void setWindSpeed(int _speed){m_windSpeed=_speed;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method which sets class wind direction to incoming wind direction from UI
  /// @param[in] _direction the wind direction effect, 0 = north, 180 = south
  void setWind(int _direction){m_windDirection=_direction;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method which sets class particle size to incoming particle size from UI
  /// @param[in] _size the average size of a particle
  void setParticleSize(int _size){m_particleSize=_size;}
  //----------------------------------------------------------------------------------------------------------------------

private:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief current number of particles
  int m_numberParticles;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief default particle number, starting point before slider is used
  int m_defaultParticleNumber;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Number of particles to increment by as slider moves along
  int m_sliderIncrement;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the particle's fall rate
  float m_windStrength;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief number of particles, thickness of weather
  int m_heaviness;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief current toggleed scene
  int m_scene;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief if the system is set to rain
  bool m_rain;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief if the system is set to snow
  bool m_snow;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the wind speed which effects the particles movements
  float m_windSpeed;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the wind direction, 0 = north, 180 = south
  int m_windDirection;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the current particleSize slider value
  int m_particleSize;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the number of threads created
  int m_numberThreads;
  //----------------------------------------------------------------------------------------------------------------------
};

#endif //PARTICLEMANAGER_H_
