/// @file ParticleManager.cpp
/// @brief contains methods for calculating new particle position after effects, deleting old particles and creating new ones
/// @author Edina Morris
/// @version 1.0
/// @date 04/05/17

#include "ParticleManager.h"
#include "NGLScene.h"
#include "Scenes.h"
#include <math.h>
#include <time.h>
#include <thread>

#define PI 3.14159265

ParticleManager::ParticleManager()
{
  m_defaultParticleNumber=5000;
  m_heaviness=0.0;
  m_windStrength=0.0;
  m_rain=false;
  m_snow=false;
  m_windSpeed=0.0;
  m_windDirection=0.0;
  m_scene=0;
  m_particleSize=5;
  m_numberParticles=m_defaultParticleNumber;
  m_sliderIncrement=100;
  //setting up particle system of rain/snow + temp value of adding 100 for each slider increment
  system=new Particle[m_numberParticles+(100*m_sliderIncrement)];
  //setting up threads
  m_numberThreads=2;
  t=new std::thread[m_numberThreads];
  //initial positions
  for(int i=0; i<m_numberParticles; i++)
  {
    float randomX =rand() %81 + (-40);
    float randomY =rand() %90 + (60);
    float randomZ =rand() %81 + (-40);
    ngl::Vec3 particlePosition=ngl::Vec3(randomX, randomY, randomZ);
    system[i].setPosition(particlePosition);
    //snow drifting setup
    float driftX=((float(rand()) / float(RAND_MAX)) * (0.02f - -0.02f)) + -0.02f;
    float driftZ=((float(rand()) / float(RAND_MAX)) * (0.02f - -0.02f)) + -0.02f;
    system[i].setDriftX(driftX);
    system[i].setDriftZ(driftZ);
    float randomScale=((float(rand()) / float(RAND_MAX)) * (0.2f - -0.2f)) + -0.2f;
    system[i].setRandomSize(ngl::Vec3(randomScale, randomScale, randomScale));
    ngl::Vec3 particleSize=ngl::Vec3((0.4),(0.4),(0.4));
    system[i].setSize(particleSize);
    float randomLife=rand() %75 + (50);
    system[i].setMaxLife(randomLife);
  }
}

ParticleManager::~ParticleManager()
{

}

void ParticleManager::addParticle()
{
  m_numberParticles=m_defaultParticleNumber+(m_heaviness*m_sliderIncrement);
}

//gravity
void ParticleManager::calculateNewPos(int _tid)
{
  if(m_rain==true)
  {
    for(int i=_tid*(m_numberParticles/m_numberThreads); i<(_tid+1)*(m_numberParticles/m_numberThreads); i++)
    //for(int i=0; i<m_numberParticles; i++)
    {
      if(system[i].getDead()!=true && system[i].getColliding()!=true)
      {
        ngl::Vec3 currentPos=system[i].getPosition();
        ngl::Vec3 newPosition=ngl::Vec3(currentPos.m_x, currentPos.m_y-=(0.1+(m_windStrength/300)), currentPos.m_z);
        system[i].setPosition(newPosition);
      }
    }
  }
  //slower fall rate as mass is less and drag resistance is more
  //snow drifts slightly, so adding random effect for x and z
   else if(m_snow==true)
   {
    for(int i=_tid*(m_numberParticles/m_numberThreads); i<(_tid+1)*(m_numberParticles/m_numberThreads); i++)
    //for(int i=0; i<m_numberParticles; i++)
    {
      if(system[i].getDead()!=true && system[i].getColliding()!=true)
      {
        ngl::Vec3 currentPos=system[i].getPosition();
        ngl::Vec3 newPosition=ngl::Vec3(currentPos.m_x+=system[i].getdriftX(),
                                        currentPos.m_y-=(0.05+(m_windStrength/300)),
                                        currentPos.m_z+=system[i].getdrfitZ());
        system[i].setPosition(newPosition);
      }
    }
  }
}

void ParticleManager::updateSize()
{
    if(m_rain==true)
    {
        for(int i=0; i<m_numberParticles; i++)
        {
            ngl::Vec3 randomSize=system[i].getRandomSize();
            ngl::Vec3 particleSize=ngl::Vec3(m_particleSize*0.1*(0.2),
                                             m_particleSize*0.1*(1.0+randomSize.m_y),
                                             m_particleSize*0.1*(0.2));
            system[i].setSize(particleSize);
        }
    }
    else if(m_snow==true)
    {
        for(int i=0; i<m_numberParticles; i++)
        {
            ngl::Vec3 randomSize=system[i].getRandomSize();
            ngl::Vec3 particleSize=ngl::Vec3(m_particleSize*0.1*(0.4+randomSize.m_x),
                                             m_particleSize*0.1*(0.4+randomSize.m_y),
                                             m_particleSize*0.1*(0.4+randomSize.m_z));
            system[i].setSize(particleSize);
        }
    }
}

void ParticleManager::outsideInfluence()
{
    if(m_windSpeed>0)
    {
        //dial wind direction rotation
        for(int i=0; i<m_numberParticles; i++)
        {
            ngl::Vec3 currentPos=system[i].getPosition();
            ngl::Vec3 newPosition=ngl::Vec3(currentPos.m_x+=(sin((-90+m_windDirection)*PI/180))*(0.0003*m_windSpeed),
                                            currentPos.m_y,
                                            currentPos.m_z+=(sin((180+m_windDirection)*PI/180))*(0.0003*m_windSpeed));
            system[i].setPosition(newPosition);
            ngl::Vec3 currentRot=system[i].getRotation();
            ngl::Vec3 newRotation=ngl::Vec3(360+(sin((m_windDirection)*PI/180))*(10+(m_windSpeed/3)),
                                            currentRot.m_y,
                                            360+(sin((-90+m_windDirection)*PI/180))*(10+(m_windSpeed/3)));
            system[i].setRotation(newRotation);
        }
    }
}

//calls all functions which calculate new particle position and rotation
void ParticleManager::update()
{
    //correcting wind strength if out of bounds
    if(m_windStrength<0.0)
    {
        m_windStrength=1.0;
    }
    else if(m_windStrength>100.0)
    {
        m_windStrength=1.0;
    }

    for(int i=0; i<m_numberThreads; i++)
    {
        t[i]=std::thread(&ParticleManager::calculateNewPos, this, i);
    }
    //calculateNewPos(0);
    updateSize();
    moveDeadParticles();
    outsideInfluence();
    addParticle();
    //floor
    checkCollision();
    checkCollisionBuildings();
    colliding();
    for(int i=0; i<m_numberThreads; i++)
    {
        t[i].join();
    }
}

//deals with moving particles back to the top again
void ParticleManager::moveDeadParticles()
{
    for(int i=0; i<m_numberParticles; i++)
    {
        //may need different method for rain and snow, snow particle will stay until melted whereas rain will turn dead before
        //collison has finished (splashing)
        if(system[i].getDead()&&system[i].getColliding()!=true)
        {
            system[i].setDead(false);
            float randomX =rand() %81 + (-40);
            float randomY =rand() %90 + (60);
            float randomZ =rand() %81 + (-40);
            ngl::Vec3 particlePosition=ngl::Vec3(randomX, randomY, randomZ);
            system[i].setPosition(particlePosition);
        }
    }
}

void ParticleManager::checkCollisionBuildings()
{
    Scenes collision;
    //for(int i=_tid*(m_numberParticles/m_numberThreads); i<(_tid+1)*(m_numberParticles/m_numberThreads); i++)
    for(int i=0; i<m_numberParticles; i++)
    {
        ngl::Vec3 currentPos=system[i].getPosition();
        ngl::Vec3 currentSize=system[i].getSize();
        //scene collision
        //for scene collision first do a check to see if particles are below a certain z number
        //only then go onto check for each particle all of the cubes, that way it will reduce calculations when theyre too high
        if(m_scene!=0)
        {
            if(currentPos.m_y<20 && system[i].getColliding()==false)
            {
                if(collision.objectCollide(Bbox(ngl::Vec3(currentPos.m_x, currentPos.m_y, currentPos.m_z),
                                            ngl::Vec3(currentSize.m_x,
                                                      currentSize.m_y,
                                                      currentSize.m_z)), m_scene))
                {
                    system[i].setDead(true);
                    //if rain then run function splash to create the new particles
                    if(m_rain==true)
                    {
                        splash(i);
                    }
                    system[i].setColliding(true);
                }
            }
        }
    }
}

void ParticleManager::checkCollision()
{
    Scenes collision;
    for(int i=0; i<m_numberParticles; i++)
    {
        //floor collision
        ngl::Vec3 currentPos=system[i].getPosition();
        ngl::Vec3 currentSize=system[i].getSize();
        if(system[i].getColliding()==false && (collision.floorCollide(Bbox(ngl::Vec3(currentPos.m_x, currentPos.m_y, currentPos.m_z),
                                    ngl::Vec3(currentSize.m_x,
                                              currentSize.m_y,
                                              currentSize.m_z)))))
        {
            system[i].setDead(true);
            //if rain then run function splash to create the new particles
            if(m_rain==true)
            {
                splash(i);
            }
            system[i].setColliding(true);
        }
        //catching any outliers
        else if(currentPos.m_y<=-20)
        {
            system[i].setDead(true);
        }
    }
}

//creating the rain particles from splash collision, passing in current particle number in order to generate new splash particle
//positions and sizes based off original
void ParticleManager::splash(int _particleId)
{
    //each splash will have a random number of particles created
    int randParticles=rand() %10 + (5);
    Particle indSplash;
    for(int i=0; i<randParticles; i++)
    {
        indSplash.setPosition(system[_particleId].getPosition());
        indSplash.setRotation(system[_particleId].getRotation());
        //may make slightly random rather than based off original
        indSplash.setSize((system[_particleId].getSize())/3);
        indSplash.setLife(0.0);
        float randomLife=rand() %15 + (15);
        indSplash.setMaxLife(randomLife);
        float randomRotationX=((float(rand()) / float(RAND_MAX)) * (1.0f - -1.0f)) + -1.0f;
        float randomRotationZ=((float(rand()) / float(RAND_MAX)) * (1.0f - -1.0f)) + -1.0f;
        float randomPositionX=((float(rand()) / float(RAND_MAX)) * (0.04f - -0.04f)) + -0.04f;
        float randomPositionY=((float(rand()) / float(RAND_MAX)) * (0.05f - -0.0f)) + -0.0f;
        float randomPositionZ=((float(rand()) / float(RAND_MAX)) * (0.04f - -0.04f)) + -0.04f;
        indSplash.setRandPosition(ngl::Vec3(randomPositionX, randomPositionY, randomPositionZ));
        indSplash.setRandRotation(ngl::Vec3(randomRotationX, 0.0, randomRotationZ));
        //push back onto rainParticle std::vector
        rainSplashes.push_back(indSplash);
    }
}

//snow particles will stick and melt, rain particles will splash and set off secondary particle system
void ParticleManager::colliding()
{
    float lifeIncrement=1.0;
    //loop through all particles and for all with collide set to true carry out colliding event
    for(int i=0; i<m_numberParticles; i++)
    {
        //snow melts
        if(m_snow==true)
        {
            float currentLife=system[i].getLife();
            if(currentLife < system[i].getMaxLife())
            {
                currentLife+=lifeIncrement;
                system[i].setLife(currentLife);
            }
            else
            {
                system[i].setLife(0.0);
                system[i].setColliding(false);
            }
        }
        //rain splashes
        if(m_rain==true)
        {
            float currentLife=system[i].getLife();
            if(currentLife < system[i].getMaxLife())
            {
                currentLife+=lifeIncrement*15;
                system[i].setLife(currentLife);
            }
            else
            {
                system[i].setLife(0.0);
                system[i].setColliding(false);
            }
        }
    }
    //loop through splash particles and update movement in arcing method, pop any that reach the end of their life
    for(int i=0; i<int(rainSplashes.size()); i++)
    {
        float currentLife=rainSplashes[i].getLife();
        float maxLife=rainSplashes[i].getMaxLife();
        if(currentLife<maxLife)
        {
            currentLife+=lifeIncrement*2;
            rainSplashes[i].setLife(currentLife);
            //move position in arcing motion
            ngl::Vec3 currentPosition=rainSplashes[i].getPosition();
            ngl::Vec3 currentRotation=rainSplashes[i].getRotation();

            currentRotation.m_x+=rainSplashes[i].getRandRotation().m_x;
            currentRotation.m_z+=rainSplashes[i].getRandRotation().m_z;

            currentPosition.m_x+=rainSplashes[i].getRandPosition().m_x;
            currentPosition.m_y+=rainSplashes[i].getRandPosition().m_y;
            currentPosition.m_z+=rainSplashes[i].getRandPosition().m_z;
            rainSplashes[i].setRotation(currentRotation);
            rainSplashes[i].setPosition(currentPosition);
        }
        //reached end of life so erase particle
        else
        {
            rainSplashes.erase(rainSplashes.begin()+i);
        }
    }
}
