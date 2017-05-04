/// @file Scenes.h
/// @brief simple class to hold scene data and check for collisions with bounding box class
/// @author Edina Morris
/// @version 1.0
/// @date 04/05/17

#ifndef SCENES_H_
#define SCENES_H_

#include "BBox.h"

/// @brief object structure holding position, scale and bounding box
/// @param position a vec3 holding the current position of the object
/// @param scale a vec3 holding the current scale of the object
/// @param sceneBox a Bbox type holding the bounding box of the object
typedef struct
{
  ngl::Vec3 position;
  ngl::Vec3 scale;
  Bbox sceneBox;

}object;

class Scenes
{
public:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief default constructor
  Scenes();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief default destructor
  ~Scenes();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief setting up positions for each building in scene 1
  void Scene1();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief setting up positions for each building in scene 2
  void Scene2();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief setting up positions for each building in scene 3
  void Scene3();
  //----------------------------------------------------------------------------------------------------------------------

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief checking for floor collide for each passed in particle
  /// @param[in] _particle bounding box for each particle
  bool floorCollide(Bbox _particle);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief checking for building collide for each passed in particle
  /// @param[in] _particle bounding box for each particle
  /// @param[in] _scene which scene should be checked for collision
  bool objectCollide(Bbox _particle, int _scene);
  //----------------------------------------------------------------------------------------------------------------------

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor to retrieve the number of obstacles
  /// @param[out] m_numberOfObstacles the current number of obstacles in current scene
  int getNumberObstacles(){return m_numberOfObstacles;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief accessor to retrieve the actual scene objects
  /// @param[out] m_sceneObjects returns the position, scale and boudning box of current objects
  object getSceneObjects(){return *m_sceneObjects;}
  //----------------------------------------------------------------------------------------------------------------------

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator method setting class scene to incoming scene flag
  /// @param[in] _scene the current scene flag
  void setScene(int _scene){m_scene=_scene;}
  //----------------------------------------------------------------------------------------------------------------------

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief setting up sceneObjects storage
  object *m_sceneObjects;
  //----------------------------------------------------------------------------------------------------------------------

private:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the number of obstacles in scene
  int m_numberOfObstacles;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the bounding box for the floor
  Bbox m_floorBbox;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief current floor flag
  int m_scene;
  //----------------------------------------------------------------------------------------------------------------------
};

#endif //SCENES_H_
