#include "Polygon.h"
#include <iostream>

void Polygon::Print(){
  for (auto x:m_pts){
    std::cout << "(" << x.X() << "," << x.Y() << ")" << std::endl;
  }
}

void Polygon::Add(const Vector2& vadd){
  m_pts.push_back(vadd);
}
