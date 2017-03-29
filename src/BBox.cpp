#include "BBox.h"

/**
 * @brief Bbox::Bbox
 * constuctor for all the parmaters necessary to work out bounding boxes of the objects
 * @param _xmin
 * @param _xmax
 * @param _ymin
 * @param _ymax
 * @param _zmin
 * @param _zmax
 */
Bbox::Bbox(float _xmin, float _xmax,float _ymin,float _ymax,float _zmin,float _zmax) :
    m_xmin(_xmin), m_xmax(_xmax), m_ymin(_ymin), m_ymax(_ymax), m_zmin(_zmin), m_zmax(_zmax)
{
  ;
}

/**
 * @brief Bbox::Bbox
 * @param _position
 * @param _size
 */
Bbox::Bbox(const ngl::Vec4& _position, const ngl::Vec4& _size)
{
  //setting up bounding box calculation variables
  m_xmin=_position.m_x;
  m_xmax=_position.m_x+_size.m_x;
  m_ymin=_position.m_y;
  m_ymax=_position.m_y+_size.m_y;
  m_zmin=_position.m_z;
  m_zmax=_position.m_z+_size.m_z;
}

/**
 * @brief Bbox::checkCollisionUp
 * @param _Bbox
 * @return false if there isnt an up collision
 */
bool Bbox::checkCollisionUp(const Bbox& _Bbox)
{
  if(m_zmin-0.1 > _Bbox.m_zmax)
  {
    return false;
  }
    return true;
}

/**
 * @brief Bbox::checkCollisionDown
 * @param _Bbox
 * @return false if there isnt an down collision
 */
bool Bbox::checkCollisionDown(const Bbox& _Bbox)
{
  if(_Bbox.m_zmin > m_zmax+0.1)
  {
    return false;
  }
    return true;
}

/**
 * @brief Bbox::checkCollisionLeft
 * @param _Bbox
 * @return false if there isnt an left collision
 */
bool Bbox::checkCollisionLeft(const Bbox& _Bbox)
{
  if(m_xmin-0.05 > _Bbox.m_xmax)
  {
    return false;
  }
    return true;
}

/**
 * @brief Bbox::checkCollisionPaddleSides
 * @param _Bbox
 * @return false if there isn't a collision with the paddle
 */
bool Bbox::checkCollisionPaddleSides(const Bbox& _Bbox)
{
  if(_Bbox.m_zmax < m_zmin)
  {
    return false;
  }

  if(_Bbox.m_zmin > m_zmax)
  {
    return false;
  }

  if(m_xmax < _Bbox.m_xmin)
  {
    return false;
  }

  if(m_xmin > _Bbox.m_xmax)
  {
    return false;
  }

  return true;
}

/**
 * @brief Bbox::checkCollisionTopBot
 * @param _Bbox
 * @return false if there isn't a collison with the top and bottom of the object
 */
bool Bbox::checkCollisionTopBot(const Bbox& _Bbox)
{
  if(_Bbox.m_zmax < m_zmin+0.3)
  {
    return false;
  }

  if(_Bbox.m_zmin > m_zmax)
  {
    return false;
  }

  if(m_xmax < _Bbox.m_xmin)
  {
    return false;
  }

  if(m_xmin > _Bbox.m_xmax)
  {
    return false;
  }
  return true;
}

/**
 * @brief Bbox::checkCollisionLeftSide
 * @param _Bbox
 * @return false if there isnt a collision with the left and right side of the object
 */
bool Bbox::checkCollisionLeftSide(const Bbox& _Bbox)
{
  if(_Bbox.m_xmax < m_xmin)
  {
    return false;
  }

  if(m_zmax < _Bbox.m_zmin)
  {
    return false;
  }

  if(m_zmin-0.3 > _Bbox.m_zmax)
  {
    return false;
  }

  if(m_xmax < _Bbox.m_xmin)
  {
    return false;
  }
  return true;
}

/**
 * @brief Bbox::checkCollisionRight
 * @param _Bbox
 * @return false if there isnt an right collision
 */
bool Bbox::checkCollisionRight(const Bbox& _Bbox)
{
  if(_Bbox.m_xmin > m_xmax+0.05)
  {
    return false;
  }
    return true;
}

/**
 * @brief Bbox::move
 * move bounding box
 * @param _offset
 */
void Bbox::move(const ngl::Vec4& _offset){

  m_xmax += _offset.m_x;
  m_xmin += _offset.m_x;

  m_ymax += _offset.m_y;
  m_ymin += _offset.m_y;

  m_zmax += _offset.m_z;
  m_zmin += _offset.m_z;

}



