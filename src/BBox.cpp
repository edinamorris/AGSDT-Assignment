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
Bbox::Bbox(const ngl::Vec3 &_position, const ngl::Vec3 &_size)
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
  if(m_ymin-0.1 > _Bbox.m_ymax)
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
  if(_Bbox.m_ymin > m_ymax+0.1)
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
void Bbox::move(const ngl::Vec3 &_offset){

  m_xmax += _offset.m_x;
  m_xmin += _offset.m_x;

  m_ymax += _offset.m_y;
  m_ymin += _offset.m_y;

  m_zmax += _offset.m_z;
  m_zmin += _offset.m_z;

}



