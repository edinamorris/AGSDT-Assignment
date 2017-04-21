#include "Scenes.h"

Scenes::Scenes()
{
    m_numberOfObstacles=10;
    m_sceneBoxes=new Bbox[m_numberOfObstacles];
    m_floorBbox=Bbox(-100.0, 100.0, -10.5, -9.5, -100.0, 100.0);
}

Scenes::~Scenes()
{
    //destructor
}

//will probably be done in nglscene as faster
void Scenes::Scene1()
{
    //scene 1 loading
}

void Scenes::Scene2()
{
    //scene 2 loading
}

void Scenes::Scene3()
{
    //scene 3 loading
}

void Scenes::getBoundingBoxes()
{
    //getting the boudning boxes for all objects  and storing them
}

bool Scenes::floorCollide(Bbox _particle)
{
    if(m_floorBbox.checkCollisionDown(_particle))
    {
        return true;
    }
    return false;
}
