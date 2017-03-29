#ifndef PARTICLEMANAGER_H
#define PARTICLEMANAGER_H

#include "Particle.h"

class ParticleManager
{
public:
    ParticleManager();
    ~ParticleManager();
    //creation
    void addParticle();
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

    //gets
    int getNumberOfParticles(){return m_numberParticles;}

    //mutators
    void setWindStrength(int _windStrength){m_windStrength=_windStrength;}
    void setHeaviness(int _heaviness){m_heaviness=_heaviness;}
    void setScene(int _scene){m_scene=_scene;}
    void setRain(bool _rain){m_rain=_rain;}
    void setSnow(bool _snow){m_snow=_snow;}

private:
    int m_numberParticles;
    Particle *system;
    //User defined values using UI
    int m_windStrength;
    int m_heaviness; //thickness of rainfall
    int m_scene;
    bool m_rain;
    bool m_snow;

};

#endif //PARTICLEMANAGER_H
