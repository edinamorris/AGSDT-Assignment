#ifndef SCENES_H
#define SCENES_H

#include "BBox.h"

class Scenes
{
public:
    Scenes();
    ~Scenes();
    void Scene1();
    void Scene2();
    void Scene3();

    void getBoundingBoxes();
    bool floorCollide(Bbox _particle);

private:
    int m_numberOfObstacles;
    //boudning boxes for obstacles, delete for each scene change and refill
    Bbox *m_sceneBoxes;
    Bbox m_floorBbox;
};

#endif //SCENES_H
