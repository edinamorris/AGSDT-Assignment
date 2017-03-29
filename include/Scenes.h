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

private:
    int m_numberOfObstacles;
    //boudning boxes for obstacles, delete for each scene change and refill
    //Bbox *m_sceneBoxes = new Bbox[m_numberOfObstacles];

};

#endif //SCENES_H
