#ifndef PARTICLEMANAGER_H
#define PARTICLEMANAGER_H

#include "Particle.h"
#include "Scenes.h"

class ParticleManager
{
public:
    ParticleManager();
    ~ParticleManager();
    //creation
    void addParticle();
    Particle *system;
    Scenes obstacles;
    //updating
    void calculateNewPos();
    void updateHeaviness();
    void outsideInfluenece();
    //void draw();
    //called from ngl, is used to run all the updating functions for each particle to find final new position
    void update();
    void deleteOldParticles();
    void checkCollision();
    //dependent on whether particle is rain or snow will do different things
    void collide();
    //changing from rain to snow or vice versa, clear up old particles start new system
    void changeParticles();
    void updateSize();

    //gets
    int getNumberOfParticles(){return m_numberParticles;}

    //mutators
    void setWindStrength(int _windStrength){m_windStrength=_windStrength;}
    void setHeaviness(int _heaviness){m_heaviness=_heaviness;}
    void setScene(int _scene){m_scene=_scene;}
    void setRain(bool _rain){m_rain=_rain;}
    void setSnow(bool _snow){m_snow=_snow;}
    void setWindSpeed(int _speed){m_windSpeed=_speed;}
    void setWind(int _direction){m_windDirection=_direction;}
    void setParticleSize(int _size){m_particleSize=_size;}

private:
    int m_numberParticles;
    int m_defaultParticleNumber;
    //increment number of particles
    int m_sliderIncrement;
    //User defined values using UI
    float m_windStrength;
    int m_heaviness; //thickness of rainfall
    int m_scene;
    bool m_rain;
    bool m_snow;
    float m_windSpeed;
    int m_windDirection;
    int m_particleSize;
};

#endif //PARTICLEMANAGER_H
