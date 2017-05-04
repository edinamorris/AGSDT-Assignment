/// @file Particle.cpp
/// @brief simple class holding each particle's attributes and setting to defaults
/// @author Edina Morris
/// @version 1.0
/// @date 04/05/17

#include "Particle.h"

Particle::Particle()
{
  m_size=ngl::Vec3(0,0,0);
  m_position=ngl::Vec3(0,0,0);
  m_rotation=ngl::Vec3(0,0,0);
  m_dead=false;
  m_colliding=false;
  m_life=0.0;
  m_maxLife=0.0;
}

Particle::~Particle()
{

}

