/// @file Particle.h
/// @brief simple class holding each particle's attributes
/// @author Edina Morris
/// @version 1.0
/// @date 04/05/17

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <ngl/Vec3.h>

class Particle
{
public:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief default constructor
  Particle();
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief default deconstructor
  ~Particle();
  //----------------------------------------------------------------------------------------------------------------------

  //accessors
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor method to get position of particle
  /// @param[out] m_position returns current position of particle
  ngl::Vec3 getPosition(){return m_position;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor method to get rotation of particle
  /// @param[out] m_rotation returns current rotation of particle
  ngl::Vec3 getRotation(){return m_rotation;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor method to get size of particle
  /// @param[out] m_size returns current size of particle
  ngl::Vec3 getSize(){return m_size;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor method to get random position modifier of particle
  /// @param[out] m_randomPosition returns random position of particle
  ngl::Vec3 getRandPosition(){return m_randomPosition;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor method to get random rotation modifier of particle
  /// @param[out] m_randomRotation returns random rotation of particle
  ngl::Vec3 getRandRotation(){return m_randomRotation;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor method to get random size modifier of particle
  /// @param[out] m_randomSize returns random size of particle
  ngl::Vec3 getRandomSize(){return m_randomSize;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor method to get death state of particle
  /// @param[out] m_dead returns current state of particle
  bool getDead(){return m_dead;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor method to get current collision state of particle
  /// @param[out] m_colliding returns current collision state of particle
  bool getColliding(){return m_colliding;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor method to get life counter of particle
  /// @param[out] m_life returns current life of particle
  float getLife(){return m_life;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor method to get maximum life time of particle
  /// @param[out] m_maxLife returns maximum life of particle
  float getMaxLife(){return m_maxLife;}  //for rainsplash
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor method to get drift modifier in X direction for particle, used in snow
  /// @param[out] m_driftX returns driftX for particle
  float getdriftX(){return m_driftX;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor method to get drift modifier in Z direction for particle, used in snow
  /// @param[out] m_driftZ returns driftZ for particle
  float getdrfitZ(){return m_driftZ;}
  //----------------------------------------------------------------------------------------------------------------------

  //mutators
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method to set class position to incoming position
  /// @param[in] _position incoming position of particle
  void setPosition(ngl::Vec3 _position){m_position=_position;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method to set class rotation to incoming rotation
  /// @param[in] _rotation incoming rotation of particle
  void setRotation(ngl::Vec3 _rotation){m_rotation=_rotation;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method to set class size to incoming size
  /// @param[in] _size incoming size of particle
  void setSize(ngl::Vec3 _size){m_size=_size;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method to set class random position modifier to incoming random position modifier
  /// @param[in] _randPos incoming random position modifier of particle
  void setRandPosition(ngl::Vec3 _randPos){m_randomPosition=_randPos;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method to set class random rotation modifier to incoming random rotation modifier
  /// @param[in] _randRot incoming random rotation modifier of particle
  void setRandRotation(ngl::Vec3 _randRot){m_randomRotation=_randRot;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method to set class particle size to incoming particle size
  /// @param[in] _size incoming size of particle
  void setRandomSize(ngl::Vec3 _size){m_randomSize=_size;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method to set class max life to incoming max life
  /// @param[in] _maxLife incoming max life length of particle
  void setMaxLife(float _maxLife){m_maxLife=_maxLife;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method to set class current particle life to incoming particle life
  /// @param[in] _life incoming life length of particle
  void setLife(float _life){m_life=_life;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method to set class particle death state to incoming death state
  /// @param[in] _dead incoming death state of particle/// @brief the random position modifier of particle for x,y,z
  void setDead(bool _dead){m_dead=_dead;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method to set class particle collision state to incoming collision state
  /// @param[in] _collide incoming collision state of particle
  void setColliding(bool _collide){m_colliding=_collide;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method to set class drifting modifier to incoming drifiting modifier for X direction
  /// @param[in] _driftX incoming drifting modifier for X direction of particle
  void setDriftX(float _driftX){m_driftX=_driftX;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method to set class drifting modifier to incoming drifiting modifier for Z direction
  /// @param[in] _driftZ incoming drifting modifier for Z direction of particle
  void setDriftZ(float _driftZ){m_driftZ=_driftZ;}
  //----------------------------------------------------------------------------------------------------------------------

private:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the size of particle for x,y,z
  ngl::Vec3 m_size;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the death state of particle
  bool m_dead;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the position of particle for x,y,z
  ngl::Vec3 m_position;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the rotation of particle for x,y,z
  ngl::Vec3 m_rotation;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the random size modifier of particle for x,y,z
  ngl::Vec3 m_randomSize;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the drift modifier in the x direction used for snow
  float m_driftX;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the drift modifier in the z direction used for snow
  float m_driftZ;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the collision state of the particle
  bool m_colliding;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the current life length of particle
  float m_life;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the maximum life length of particle
  float m_maxLife;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the random position modifier of particle for x,y,z
  ngl::Vec3 m_randomPosition;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the random rotation modifier of particle for x,y,z
  ngl::Vec3 m_randomRotation;
  //----------------------------------------------------------------------------------------------------------------------
};

#endif //PARTICLE_H_
