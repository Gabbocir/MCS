#ifndef _SQUARE
#define _SQUARE

#include "Rectangle.h"
#include "Vector2.h"

class Square: public Rectangle{
  public:
    using Rectangle::Rectangle;
    Square(double l):Rectangle(l,l),m_l(l){}
  private:
    double m_l;
};

#endif
