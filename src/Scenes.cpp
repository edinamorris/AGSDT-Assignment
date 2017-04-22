#include "Scenes.h"

Scenes::Scenes()
{
    m_floorBbox=Bbox(-100.0, 100.0, -10.5, -9.5, -100.0, 100.0);
    //default = no scene selected at start
    m_scene=0;
    m_numberOfObstacles=0;
}

Scenes::~Scenes()
{
    //destructor
}

void Scenes::Scene1()
{
    m_sceneObjects=0;
    //free old scene data
    delete m_sceneObjects;

    //create new memory for scene 1
    m_numberOfObstacles=14;
    m_sceneObjects=new object[m_numberOfObstacles];
    //manual scene creation
    m_sceneObjects[11].position=ngl::Vec3(-35, 0, 20);
    m_sceneObjects[11].scale=ngl::Vec3(20.0, 50.0, 20.0);
    m_sceneObjects[1].position=ngl::Vec3(-10, 0, 35);
    m_sceneObjects[1].scale=ngl::Vec3(40.0, 50.0, 20.0);
    m_sceneObjects[9].position=ngl::Vec3(-30, -4, 35);
    m_sceneObjects[9].scale=ngl::Vec3(40.0, 30.0, 20.0);
    m_sceneObjects[10].position=ngl::Vec3(-30, -4, -25);
    m_sceneObjects[10].scale=ngl::Vec3(40.0, 30.0, 40.0);
    m_sceneObjects[4].position=ngl::Vec3(-15, -2, 5);
    m_sceneObjects[4].scale=ngl::Vec3(40.0, 40.0, 10.0);
    m_sceneObjects[6].position=ngl::Vec3(-30, 2, -5);
    m_sceneObjects[6].scale=ngl::Vec3(15.0, 60.0, 35.0);
    m_sceneObjects[13].position=ngl::Vec3(35, 1, -25);
    m_sceneObjects[13].scale=ngl::Vec3(20.0, 55.0, 30.0);
    m_sceneObjects[12].position=ngl::Vec3(30, -6, -10);
    m_sceneObjects[12].scale=ngl::Vec3(15.0, 20.0, 20.0);
    m_sceneObjects[8].position=ngl::Vec3(30, -4, 5);
    m_sceneObjects[8].scale=ngl::Vec3(25.0, 30.0, 20.0);
    m_sceneObjects[2].position=ngl::Vec3(35, -1, 25);
    m_sceneObjects[2].scale=ngl::Vec3(20.0, 45.0, 40.0);
    m_sceneObjects[3].position=ngl::Vec3(20, -5, 35);
    m_sceneObjects[3].scale=ngl::Vec3(50.0, 25.0, 15.0);
    m_sceneObjects[7].position=ngl::Vec3(10, -2, -5);
    m_sceneObjects[7].scale=ngl::Vec3(20.0, 40.0, 20.0);
    m_sceneObjects[0].position=ngl::Vec3(15, 3, -25);
    m_sceneObjects[0].scale=ngl::Vec3(20.0, 65.0, 20.0);
    m_sceneObjects[5].position=ngl::Vec3(-5, -1, -20);
    m_sceneObjects[5].scale=ngl::Vec3(20.0, 45.0, 40.0);
    for(int i=0; i<m_numberOfObstacles; i++)
    {
        m_sceneObjects[i].sceneBox=Bbox(ngl::Vec3(m_sceneObjects[i].position.m_x-m_sceneObjects[i].scale.m_x/5,
                                                  m_sceneObjects[i].position.m_y,
                                                  m_sceneObjects[i].position.m_z-m_sceneObjects[i].scale.m_z/5),
                                        ngl::Vec3(m_sceneObjects[i].scale.m_x/2.5,
                                                  m_sceneObjects[i].scale.m_y/5,
                                                  m_sceneObjects[i].scale.m_z/2.5));
    }
}

void Scenes::Scene2()
{
    m_sceneObjects=0;
    //free old scene data
    delete m_sceneObjects;

    //create new memory for scene 2
    m_numberOfObstacles=8;
    m_sceneObjects=new object[m_numberOfObstacles];
    //manual scene creation
    m_sceneObjects[0].position=ngl::Vec3(-20, 1, 25);
    m_sceneObjects[0].scale=ngl::Vec3(25.0, 55.0, 10.0);
    m_sceneObjects[5].position=ngl::Vec3(0, -6, 0);
    m_sceneObjects[5].scale=ngl::Vec3(40.0, 20.0, 20.0);
    m_sceneObjects[7].position=ngl::Vec3(30, -2, -20);
    m_sceneObjects[7].scale=ngl::Vec3(30.0, 40.0, 60.0);
    m_sceneObjects[3].position=ngl::Vec3(0, 0, -30);//
    m_sceneObjects[3].scale=ngl::Vec3(35.0, 50.0, 20.0);
    m_sceneObjects[4].position=ngl::Vec3(-25, -4, -25);
    m_sceneObjects[4].scale=ngl::Vec3(30.0, 30.0, 30.0);
    m_sceneObjects[1].position=ngl::Vec3(-30, -7, -5);
    m_sceneObjects[1].scale=ngl::Vec3(20.0, 15.0, 60.0);
    m_sceneObjects[6].position=ngl::Vec3(30, -3, 20);
    m_sceneObjects[6].scale=ngl::Vec3(10.0, 35.0, 20.0);
    m_sceneObjects[2].position=ngl::Vec3(25, 0, 35);
    m_sceneObjects[2].scale=ngl::Vec3(30.0, 50.0, 15.0);
    for(int i=0; i<m_numberOfObstacles; i++)
    {
        m_sceneObjects[i].sceneBox=Bbox(ngl::Vec3(m_sceneObjects[i].position.m_x-m_sceneObjects[i].scale.m_x/5,
                                                  m_sceneObjects[i].position.m_y,
                                                  m_sceneObjects[i].position.m_z-m_sceneObjects[i].scale.m_z/5),
                                        ngl::Vec3(m_sceneObjects[i].scale.m_x/2.5,
                                                  m_sceneObjects[i].scale.m_y/5,
                                                  m_sceneObjects[i].scale.m_z/2.5));
    }
}

void Scenes::Scene3()
{
    m_sceneObjects=0;
    //free old scene data
    delete m_sceneObjects;

    //create new memory for scene 3
    m_numberOfObstacles=10;
    m_sceneObjects=new object[m_numberOfObstacles];
    //manual scene creation
    m_sceneObjects[9].position=ngl::Vec3(-30, -6, 25);
    m_sceneObjects[9].scale=ngl::Vec3(15.0, 20.0, 15.0);
    m_sceneObjects[1].position=ngl::Vec3(25, -7, -30);
    m_sceneObjects[1].scale=ngl::Vec3(25.0, 15.0, 20.0);
    m_sceneObjects[2].position=ngl::Vec3(20, -6, 25);
    m_sceneObjects[2].scale=ngl::Vec3(20.0, 20.0, 30.0);
    m_sceneObjects[3].position=ngl::Vec3(-35, -7, -25);
    m_sceneObjects[3].scale=ngl::Vec3(20.0, 15.0, 15.0);
    m_sceneObjects[7].position=ngl::Vec3(-5, -4, 15);
    m_sceneObjects[7].scale=ngl::Vec3(50.0, 30.0, 40.0);
    m_sceneObjects[5].position=ngl::Vec3(-15, -5, -10);
    m_sceneObjects[5].scale=ngl::Vec3(30.0, 25.0, 20.0);
    m_sceneObjects[6].position=ngl::Vec3(0, -6, -30);
    m_sceneObjects[6].scale=ngl::Vec3(50.0, 20.0, 15.0);
    m_sceneObjects[4].position=ngl::Vec3(10, -2, -15);
    m_sceneObjects[4].scale=ngl::Vec3(25.0, 40.0, 35.0);
    m_sceneObjects[8].position=ngl::Vec3(30, -6, 5);
    m_sceneObjects[8].scale=ngl::Vec3(20.0, 20.0, 45.0);
    m_sceneObjects[0].position=ngl::Vec3(-30, -4, 5);
    m_sceneObjects[0].scale=ngl::Vec3(25.0, 30.0, 30.0);
    for(int i=0; i<m_numberOfObstacles; i++)
    {
        m_sceneObjects[i].sceneBox=Bbox(ngl::Vec3(m_sceneObjects[i].position.m_x-m_sceneObjects[i].scale.m_x/5,
                                                  m_sceneObjects[i].position.m_y,
                                                  m_sceneObjects[i].position.m_z-m_sceneObjects[i].scale.m_z/5),
                                        ngl::Vec3(m_sceneObjects[i].scale.m_x/2.5,
                                                  m_sceneObjects[i].scale.m_y/5,
                                                  m_sceneObjects[i].scale.m_z/2.5));
    }
}

bool Scenes::floorCollide(Bbox _particle)
{
    if(m_floorBbox.checkCollisionDown(_particle))
    {
        //std::cout<<"floor \n";
        return true;
    }
    return false;
}

bool Scenes::objectCollide(Bbox _particle, int _scene)
{
    if(_scene==1)
    {
        Scene1();
    }
    else if(_scene==2)
    {
        Scene2();
    }
    else if(_scene==3)
    {
        Scene3();
    }
    for(int i=0; i<m_numberOfObstacles; i++)
    {
        //checking for each scene obstacle
        if(m_sceneObjects[i].sceneBox.checkCollisionDown(_particle))
        {
            //std::cout<<"obstacle\n";
            return true;
        }
    }
    return false;
}
