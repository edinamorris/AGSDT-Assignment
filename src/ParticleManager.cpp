#include "ParticleManager.h"
#include "NGLScene.h"

ParticleManager::ParticleManager()
{
    m_numberParticles=1000;
    //setting up particle system of rain/snow
    system=new Particle[m_numberParticles];

    //initial positions
    for(int i=0; i<m_numberParticles; i++)
    {
        float randomX =rand() %41 + (-20);
        float randomZ =rand() %41 + (-20);
        ngl::Vec3 particlePosition=ngl::Vec3(randomX, 20.0, randomZ);
        system[i].setPosition(particlePosition);
    }
}

ParticleManager::~ParticleManager()
{

}

void ParticleManager::addParticle()
{

}

void ParticleManager::calculateNewPos()
{

}

void ParticleManager::updateHeaviness()
{

}

void ParticleManager::outsideInfluenece()
{

}

//calls all functions which calculate new particle position
void ParticleManager::update()
{
    for(int i=0; i<m_numberParticles; i++)
    {
        ngl::Vec3 currentPos=system[i].getPosition();
        ngl::Vec3 newPosition=ngl::Vec3(currentPos.m_x, currentPos.m_y-=0.1, currentPos.m_z);
        system[i].setPosition(newPosition);
    }
}

void ParticleManager::deleteOldParticles()
{

}

void ParticleManager::checkCollision()
{

}

void ParticleManager::collide()
{

}

void ParticleManager::changeParticles()
{

}
