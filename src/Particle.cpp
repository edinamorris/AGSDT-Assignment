#include "Particle.h"

Particle::Particle(float _maxLife, float _life, float _size, ngl::Vec3 _acceleration, ngl::Vec3 _position,
                   ngl::Vec3 _direction)
{
    m_maxLife=_maxLife;
    m_life=_life;
    m_size=_size;
    m_acceleration=_acceleration;
    m_position=_position;
    m_direction=_direction;
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
