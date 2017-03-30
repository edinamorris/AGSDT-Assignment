#ifndef PARTICLE_H
#define PARTICLE_H

#include <ngl/Vec3.h>

class Particle
{
public:
    Particle(float _maxLife, float _life, float _size, ngl::Vec3 _acceleration, ngl::Vec3 _position,
             ngl::Vec3 _direction);
    Particle();
    ~Particle();
    void draw();
    ngl::Vec3 getPosition(){return m_position;}
    void setPosition(ngl::Vec3 _position){m_position.m_x=_position.m_x;
                                          m_position.m_y=_position.m_y;
                                          m_position.m_z=_position.m_z;}
private:
    float m_maxLife;
    float m_life;
    float m_size;
    ngl::Vec3 m_position;
    ngl::Vec3 m_acceleration;
    ngl::Vec3 m_direction;
};

#endif //PARTICLE_H
