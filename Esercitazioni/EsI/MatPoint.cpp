#include "MatPoint.h"
#include <cmath>

Vector3 MatPoint::R(){
  return m_R;
}

Vector3 MatPoint::V(){
  return m_V;
}

void MatPoint::R(Vector3 R){
  m_R=R;
}

void MatPoint::V(Vector3 V){
  m_V=V;
}

Vector3 MatPoint::GravField(Vector3 r){
  double m = Mass(); // A quanto pare this non è necessario
  Vector3 R = this->R();
  Vector3 differenza = r-R;
  double diff = differenza.Mod();
  Vector3 Field= -(m/pow(diff,3))*differenza;
  return Field;
}
