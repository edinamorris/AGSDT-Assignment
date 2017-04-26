#include "Particle.h"

Particle::Particle(ngl::Vec3 _size, ngl::Vec3 _position, ngl::Vec3 _rotation, bool _particleDead)
{
    m_size=_size;
    m_position=_position;
    m_rotation=_rotation;
    m_dead=false;
}

Particle::Particle()
{
    //default constructor
}

Particle::~Particle()
{
    //clearing up particle memory
}

