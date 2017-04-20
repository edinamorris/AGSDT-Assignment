#ifndef PARTICLE_H
#define PARTICLE_H

#include <ngl/Vec3.h>

class Particle
{
public:
    Particle(float _size, ngl::Vec3 _position, ngl::Vec3 _rotation, bool _particleDead);
    Particle();
    ~Particle();
    void draw();
    ngl::Vec3 getPosition(){return m_position;}
    ngl::Vec3 getRotation(){return m_rotation;}
    bool getDead(){return m_dead;}
    float getdriftX(){return m_driftX;}
    float getdrfitZ(){return m_driftZ;}
    void setPosition(ngl::Vec3 _position){m_position.m_x=_position.m_x;
                                          m_position.m_y=_position.m_y;
                                          m_position.m_z=_position.m_z;}
    void setRotation(ngl::Vec3 _rotation){m_rotation.m_x=_rotation.m_x;
                                          m_rotation.m_y=_rotation.m_y;
                                          m_rotation.m_z=_rotation.m_z;}
    //snow slight drifting
    void setDriftX(float _driftX){m_driftX=_driftX;}
    void setDriftZ(float _driftZ){m_driftZ=_driftZ;}
private:
    float m_size;
    bool m_dead;
    ngl::Vec3 m_position;
    ngl::Vec3 m_rotation;
    float m_driftX;
    float m_driftZ;
};

#endif //PARTICLE_H
