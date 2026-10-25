#ifndef _POLYGON
#define _POLYGON

#include "Vector2.h"
#include <vector>

class Polygon{
 public:
  Polygon(const std::vector<Vector2>& pts):m_pts(pts){}
  Polygon():Polygon(std::vector<Vector2>(0)){}
  void Add(const Vector2&);
  //void Translate(const Vector2&);
  //void Rotate(const Vector2&, double ang);
  void   Print();
  double Perimeter();
  double Area();
 private:
  std::vector<Vector2> m_pts;
};

#endif
