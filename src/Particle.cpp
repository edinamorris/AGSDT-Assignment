#include "Particle.h"

Particle::Particle(float _size, ngl::Vec3 _position, ngl::Vec3 _rotation, bool _particleDead)
{
    m_size=_size;
    m_position=_position;
    m_rotation=_rotation;
}

Particle::Particle()
{
    //default constructor
}

Particle::~Particle()
{
    //clearing up particle memory
}

void Particle::draw()
{
    //drawing potentially should be dealt with in particle manager
}
