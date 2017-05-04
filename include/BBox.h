/// @file BBox.h
/// @brief basic bounding box class with collision check method
/// @author Edina Morris
/// @version 1.0
/// @date 04/05/17

#ifndef BBOX_H
#define BBOX_H

#include<iostream>
#include <ngl/Vec3.h>

///
/// \brief The Bbox class
///
class Bbox
{
public:
  /// @brief first bounding box constructor, takes position and size of incoming object and calculates bounding box
  /// @param [in] _position the objects position as a vec3
  /// @param [in] _size the objects size as a vec3
  Bbox(const ngl::Vec3& _position, const ngl::Vec3 & _size);

  /// @brief second bounding box constructor, takes the actual values for x,y,z min and max
  /// @param [in] _xMin minimum x value
  /// @param [in] _xMax maximum x value
  /// @param [in] _yMin minimum y value
  /// @param [in] _yMax maximum y value
  /// @param [in] _zMin minimum z value
  /// @param [in] _zMax maximum z value
  Bbox(float _xMin=0.0f, float _xMax=0.0f,float _yMin=0.0f,float _yMax=1.0f,float _zMin=1.0f,float _zMax=1.0f);

  /// @brief simple check collision between current bounding box and passed in bounding box, returns true if collision false if not
  /// @param [in] _Bbox Bounding box of object to check collision with passed in bounding box
  bool checkCollisionDown(const Bbox& _Bbox);

  /// @brief simple method to move bounding box in world space
  /// @param [in] _offset how much to move the bounding box by in x, y and z direction
  void move( const ngl::Vec3& _offset);

private:
  /// @brief minimum x coordinate of bounding box
  float m_xMin;
  /// @brief maximum x coordinate of bounding box
  float m_xMax;
  /// @brief minimum y coordinate of bounding box
  float m_yMin;
  /// @brief maximum y coordinate of bounding box
  float m_yMax;
  /// @brief minimum z coordinate of bounding box
  float m_zMin;
  /// @brief maximum z coordinate of bounding box
  float m_zMax;
};

#endif //BBOX_H_
