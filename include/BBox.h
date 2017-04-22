#ifndef BBOX_H
#define BBOX_H

#include<iostream>
#include <ngl/Vec3.h>

class Bbox
{
public:
  Bbox(const ngl::Vec3& _position, const ngl::Vec3 & _size);
  Bbox(float _xmin=0.0f, float _xmax=0.0f,float _ymin=0.0f,float _ymax=1.0f,float _zmin=1.0f,float _zmax=1.0f);

  bool checkCollisionUp(const Bbox& _Bbox);
  bool checkCollisionDown(const Bbox& _Bbox);
  //need sides check

  void move( const ngl::Vec3& _offset);

private:
  float m_xmin;
  float m_xmax;
  float m_ymin;
  float m_ymax;
  float m_zmin;
  float m_zmax;
};

#endif //BBOX_H
