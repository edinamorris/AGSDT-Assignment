#ifndef PARTICLE_H
#define PARTICLE_H

#include <ngl/Vec3.h>

class Particle
{
public:
    Particle();
    ~Particle();

    //accessors
    ngl::Vec3 getPosition(){return m_position;}
    ngl::Vec3 getRotation(){return m_rotation;}
    ngl::Vec3 getSize(){return m_size;}
    ngl::Vec3 getRandPosition(){return m_randomPosition;}
    ngl::Vec3 getRandRotation(){return m_randomRotation;}
    ngl::Vec3 getRandomSize(){return m_randomSize;}
    bool getDead(){return m_dead;}
    bool getColliding(){return m_colliding;}
    float getLife(){return m_life;}
    float getMaxLife(){return m_maxLife;}
    float getdriftX(){return m_driftX;}
    float getdrfitZ(){return m_driftZ;}

    //mutators
    void setPosition(ngl::Vec3 _position){m_position.m_x=_position.m_x;
                                          m_position.m_y=_position.m_y;
                                          m_position.m_z=_position.m_z;}
    void setRotation(ngl::Vec3 _rotation){m_rotation.m_x=_rotation.m_x;
                                          m_rotation.m_y=_rotation.m_y;
                                          m_rotation.m_z=_rotation.m_z;}
    void setSize(ngl::Vec3 _size){m_size.m_x=_size.m_x;
                                  m_size.m_y=_size.m_y;
                                  m_size.m_z=_size.m_z;}
    void setRandPosition(ngl::Vec3 _randPos){m_randomPosition.m_x=_randPos.m_x;
                                             m_randomPosition.m_y=_randPos.m_y;
                                             m_randomPosition.m_z=_randPos.m_z;}
    void setRandRotation(ngl::Vec3 _randRot){m_randomRotation.m_x=_randRot.m_x;
                                             m_randomRotation.m_y=_randRot.m_y;
                                             m_randomRotation.m_z=_randRot.m_z;}
    void setRandomSize(ngl::Vec3 _size){m_randomSize=_size;}
    void setMaxLife(float _maxLife){m_maxLife=_maxLife;}
    void setLife(float _life){m_life=_life;}
    void setDead(bool _dead){m_dead=_dead;}
    void setColliding(bool _collide){m_colliding=_collide;}
    //snow slight drifting
    void setDriftX(float _driftX){m_driftX=_driftX;}
    void setDriftZ(float _driftZ){m_driftZ=_driftZ;}

private:
    ngl::Vec3 m_size;
    bool m_dead;
    ngl::Vec3 m_position;
    ngl::Vec3 m_rotation;
    ngl::Vec3 m_randomSize;
    float m_driftX;
    float m_driftZ;
    //collision values
    bool m_colliding;
    float m_life;
    float m_maxLife;
    //for rainsplash
    ngl::Vec3 m_randomPosition;
    ngl::Vec3 m_randomRotation;
};

#endif //PARTICLE_H
