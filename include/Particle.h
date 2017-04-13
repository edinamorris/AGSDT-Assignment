#ifndef PARTICLE_H
#define PARTICLE_H

#include <ngl/Vec3.h>

class Particle
{
public:
    Particle(float _maxLife, float _life, float _size, ngl::Vec3 _acceleration, ngl::Vec3 _position,
             ngl::Vec3 _direction, ngl::Vec3 _rotation);
    Particle();
    ~Particle();
    void draw();
    ngl::Vec3 getPosition(){return m_position;}
    ngl::Vec3 getRotation(){return m_rotation;}
    void setPosition(ngl::Vec3 _position){m_position.m_x=_position.m_x;
                                          m_position.m_y=_position.m_y;
                                          m_position.m_z=_position.m_z;}
    void setRotation(ngl::Vec3 _rotation){m_rotation.m_x=_rotation.m_x;
                                          m_rotation.m_y=_rotation.m_y;
                                          m_rotation.m_z=_rotation.m_z;}
private:
    float m_maxLife;
    float m_life;
    float m_size;
    ngl::Vec3 m_position;
    ngl::Vec3 m_acceleration;
    ngl::Vec3 m_direction;
    ngl::Vec3 m_rotation;
};

#endif //PARTICLE_H
