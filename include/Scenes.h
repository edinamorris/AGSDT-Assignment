#ifndef SCENES_H
#define SCENES_H

#include "BBox.h"

//object structure
typedef struct
{
    ngl::Vec3 position;
    ngl::Vec3 scale;
    Bbox sceneBox;

}object;

class Scenes
{
public:
    Scenes();
    ~Scenes();
    void Scene1();
    void Scene2();
    void Scene3();

    //collision
    bool floorCollide(Bbox _particle);
    bool objectCollide(Bbox _particle, int _scene);

    //accessors
    int getNumberObstacles(){return m_numberOfObstacles;}
    object getSceneObjects(){return *m_sceneObjects;}

    //mutators
    void setScene(int _scene){m_scene=_scene;}

    object *m_sceneObjects;

private:
    int m_numberOfObstacles;
    //boudning boxes for obstacles, delete for each scene change and refill
    //Bbox *m_sceneBoxes;
    Bbox m_floorBbox;
    int m_scene;
};

#endif //SCENES_H
