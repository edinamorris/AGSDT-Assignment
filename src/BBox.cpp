/// @file BBox.cpp
/// @brief basic bounding box class implementation with collision check method
/// @author Edina Morris
/// @version 1.0
/// @date 04/05/17

#include "BBox.h"

Bbox::Bbox(float _xMin, float _xMax, float _yMin, float _yMax, float _zMin, float _zMax) :
    m_xMin(_xMin), m_xMax(_xMax), m_yMin(_yMin), m_yMax(_yMax), m_zMin(_zMin), m_zMax(_zMax)
{
  ;
}

Bbox::Bbox(const ngl::Vec3 &_position, const ngl::Vec3 &_size)
{
  //setting up bounding box calculation variables
  m_xMin=_position.m_x;
  m_xMax=_position.m_x+_size.m_x;
  m_yMin=_position.m_y;
  m_yMax=_position.m_y+_size.m_y;
  m_zMin=_position.m_z;
  m_zMax=_position.m_z+_size.m_z;
}

bool Bbox::checkCollisionDown(const Bbox& _Bbox)
{
  if((_Bbox.m_yMin > m_yMax+0.2)||(_Bbox.m_xMin > m_xMax+0.1)||(m_xMin-0.1>_Bbox.m_xMax)||
          (_Bbox.m_zMin > m_zMax+0.1)||(m_zMin-0.1>_Bbox.m_zMax))
  {
    return false;
  }
    return true;
}

void Bbox::move(const ngl::Vec3 &_offset){

  m_xMax += _offset.m_x;
  m_xMin += _offset.m_x;

  m_yMax += _offset.m_y;
  m_yMin += _offset.m_y;

  m_zMax += _offset.m_z;
  m_zMin += _offset.m_z;

}



