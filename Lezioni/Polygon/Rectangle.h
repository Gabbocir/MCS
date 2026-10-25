#ifndef _RECTANGLE
#define _RECTANGLE

#include "Polygon.h"
#include "Vector2.h"

class Rectangle: public Polygon{
  public:
    using Polygon::Polygon;
    Rectangle(double l,double h):Polygon(){
      Add(Vector2(0,0));
      Add(Vector2(l,0));
      Add(Vector2(l,h));
      Add(Vector2(0,h));
    }
  private:
    double m_l,m_h;
};

#endif
