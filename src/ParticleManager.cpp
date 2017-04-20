#include "ParticleManager.h"
#include "NGLScene.h"

ParticleManager::ParticleManager()
{
    m_defaultParticleNumber=5000;
    m_heaviness=0.0;
    m_windStrength=0.0;
    m_rain=false;
    m_snow=false;
    m_windSpeed=0.0;
    m_north=false;
    m_south=false;
    m_east=false;
    m_west=false;
    m_numberParticles=m_defaultParticleNumber;
    m_sliderIncrement=100;
    //setting up particle system of rain/snow + temp value of adding 100 for each slider increment
    system=new Particle[m_numberParticles+(100*m_sliderIncrement)];

    //initial positions
    for(int i=0; i<m_numberParticles; i++)
    {
        float randomX =rand() %81 + (-40);
        float randomY =rand() %90 + (60);
        float randomZ =rand() %81 + (-40);
        ngl::Vec3 particlePosition=ngl::Vec3(randomX, randomY, randomZ);
        system[i].setPosition(particlePosition);
        //snow drifting setup
        float driftX=((float(rand()) / float(RAND_MAX)) * (0.01f - -0.01f)) + -0.01f;
        float driftZ=((float(rand()) / float(RAND_MAX)) * (0.01f - -0.01f)) + -0.01f;
        system[i].setDriftX(driftX);
        system[i].setDriftZ(driftZ);
    }
}

ParticleManager::~ParticleManager()
{

}

void ParticleManager::addParticle()
{
    m_numberParticles=m_defaultParticleNumber+(m_heaviness*m_sliderIncrement);
    //std::cout<<"number of particles > "<<m_numberParticles<<"\n";
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
    if(m_rain==true)
    {
        for(int i=0; i<m_numberParticles; i++)
        {
            ngl::Vec3 currentPos=system[i].getPosition();
            ngl::Vec3 newPosition=ngl::Vec3(currentPos.m_x, currentPos.m_y-=(0.1+(m_windStrength/300)), currentPos.m_z);
            system[i].setPosition(newPosition);
        }
    }
    //slower fall rate as mass is less and drag resistance is more
    //snow drifts slightly, so adding random effect for x and z
    else if(m_snow==true)
    {
        for(int i=0; i<m_numberParticles; i++)
        {
            ngl::Vec3 currentPos=system[i].getPosition();
            ngl::Vec3 newPosition=ngl::Vec3(currentPos.m_x+=system[i].getdriftX(),
                                            currentPos.m_y-=(0.05+(m_windStrength/300)),
                                            currentPos.m_z+=system[i].getdrfitZ());
            system[i].setPosition(newPosition);
        }
    }
}

//may not be needed
void ParticleManager::updateHeaviness()
{

}

void ParticleManager::outsideInfluenece()
{
//East wind movement
    if(m_east==true)
    {
        for(int i=0; i<m_numberParticles; i++)
        {
            ngl::Vec3 currentPos=system[i].getPosition();
            ngl::Vec3 newPosition=ngl::Vec3(currentPos.m_x, currentPos.m_y, currentPos.m_z-=(0.0003*m_windSpeed));
            system[i].setPosition(newPosition);

            ngl::Vec3 currentRot=system[i].getRotation();
            ngl::Vec3 newRotation=ngl::Vec3(10+(m_windSpeed/3), currentRot.m_y, 0.0);
            system[i].setRotation(newRotation);
        }
    }
    else if(m_west==true)
    {
        for(int i=0; i<m_numberParticles; i++)
        {
            ngl::Vec3 currentPos=system[i].getPosition();
            ngl::Vec3 newPosition=ngl::Vec3(currentPos.m_x, currentPos.m_y, currentPos.m_z+=(0.0003*m_windSpeed));
            system[i].setPosition(newPosition);

            ngl::Vec3 currentRot=system[i].getRotation();
            ngl::Vec3 newRotation=ngl::Vec3(350-(m_windSpeed/3), currentRot.m_y, 0.0);
            system[i].setRotation(newRotation);
        }
    }
    else if(m_north==true)
    {
        for(int i=0; i<m_numberParticles; i++)
        {
            ngl::Vec3 currentPos=system[i].getPosition();
            ngl::Vec3 newPosition=ngl::Vec3(currentPos.m_x-=(0.0003*m_windSpeed), currentPos.m_y, currentPos.m_z);
            system[i].setPosition(newPosition);

            ngl::Vec3 currentRot=system[i].getRotation();
            ngl::Vec3 newRotation=ngl::Vec3(0.0, currentRot.m_y, 350-(m_windSpeed/3));
            system[i].setRotation(newRotation);
        }
    }
    else if(m_south==true)
    {
        for(int i=0; i<m_numberParticles; i++)
        {
            ngl::Vec3 currentPos=system[i].getPosition();
            ngl::Vec3 newPosition=ngl::Vec3(currentPos.m_x+=(0.0003*m_windSpeed), currentPos.m_y, currentPos.m_z);
            system[i].setPosition(newPosition);

            ngl::Vec3 currentRot=system[i].getRotation();
            ngl::Vec3 newRotation=ngl::Vec3(0.0, currentRot.m_y, 10+(m_windSpeed/3));
            system[i].setRotation(newRotation);
        }
    }
}

//calls all functions which calculate new particle position and rotation
void ParticleManager::update()
{
    calculateNewPos();
    deleteOldParticles();
    outsideInfluenece();
    addParticle();
}

//may not need this for now I'm just going to put positions of particles at top again
void ParticleManager::deleteOldParticles()
{
    for(int i=0; i<m_numberParticles; i++)
    {
        ngl::Vec3 currentPos=system[i].getPosition();
        if((currentPos.m_y<=-10)||(system[i].getDead()))
        {
            float randomX =rand() %81 + (-40);
            float randomY =rand() %90 + (60);
            float randomZ =rand() %81 + (-40);
            ngl::Vec3 particlePosition=ngl::Vec3(randomX, randomY, randomZ);
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
