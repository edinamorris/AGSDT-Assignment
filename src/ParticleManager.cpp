#include "ParticleManager.h"
#include "NGLScene.h"

ParticleManager::ParticleManager()
{
    m_numberParticles=1000;
    //setting up particle system of rain/snow
    system=new Particle[m_numberParticles];

    //not accurate rain would be fall straight without wind
    //float randomRotationAll=rand()%360;
    //initial positions
    for(int i=0; i<m_numberParticles; i++)
    {
        float randomX =rand() %41 + (-20);
        float randomY =rand() %40 + (20);
        float randomZ =rand() %41 + (-20);
        float randomRotation=rand() %360;
        ngl::Vec3 particlePosition=ngl::Vec3(randomX, randomY, randomZ);
        ngl::Vec3 particleRotation=ngl::Vec3(0.0, randomRotation, 0.0);
        system[i].setPosition(particlePosition);
        system[i].setRotation(particleRotation);
    }
}

ParticleManager::~ParticleManager()
{

}

void ParticleManager::addParticle()
{

}

//gravity
void ParticleManager::calculateNewPos()
{
    if(m_windStrength<0.0)
    {
        m_windStrength=1.0;
    }
    else if(m_windStrength>100.0)
    {
        m_windStrength=1.0;
    }
    for(int i=0; i<m_numberParticles; i++)
    {
        ngl::Vec3 currentPos=system[i].getPosition();
        ngl::Vec3 newPosition=ngl::Vec3(currentPos.m_x, currentPos.m_y-=(0.1+(m_windStrength/300)), currentPos.m_z);
        system[i].setPosition(newPosition);

        /*ngl::Vec3 currentRot=system[i].getRotation();
        ngl::Vec3 newRotation=ngl::Vec3(currentRot.m_x, currentRot.m_y+=1, currentRot.m_z);
        system[i].setRotation(newRotation);*/
    }
}

void ParticleManager::updateHeaviness()
{

}

void ParticleManager::outsideInfluenece()
{

}

//calls all functions which calculate new particle position and rotation
void ParticleManager::update()
{
    calculateNewPos();
    deleteOldParticles();
}

//may not need this for now I'm just going to put positions of particles at top again
void ParticleManager::deleteOldParticles()
{
    for(int i=0; i<m_numberParticles; i++)
    {
        ngl::Vec3 currentPos=system[i].getPosition();
        if(currentPos.m_y<=-10)
        {
            float randomY =rand() %40 + (20);
            ngl::Vec3 particlePosition=ngl::Vec3(currentPos.m_x, randomY, currentPos.m_z);
            system[i].setPosition(particlePosition);
        }
    }
}

void ParticleManager::checkCollision()
{

}

void ParticleManager::collide()
{

}

//may need to delete whole system and restart each time user switches between rain and snow
void ParticleManager::changeParticles()
{

}
