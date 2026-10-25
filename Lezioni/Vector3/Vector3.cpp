#include "Vector3.h"
#include <cmath>

double Vector3::X() const{
  return m_v[0];
}

void Vector3::X(double tmp){
  m_v[0] = tmp;
}

double Vector3::Y() const{
  return m_v[1];
}

void Vector3::Y(double tmp){
  m_v[1] = tmp;
}
double Vector3::Z() const{
  return m_v[2];
}

void Vector3::Z(double tmp){
  m_v[2] = tmp;
}

Vector3 Vector3::operator+(const Vector3& b) const{
  Vector3 sum;
  for (int i=0; i<3;i++){
    sum.m_v[i]= m_v[i]+b.m_v[i];
  }
  return sum;
}

double Vector3::ProdottoScalare(const Vector3& b) const{
  double ps=0;
  for (int i=0; i<3;i++){
    ps+= m_v[i]*b.m_v[i];
  }
  return ps;
}

double Vector3::Modulo() const{
  return std::sqrt(ProdottoScalare(*this));
}

Vector3 Vector3::Versore() const{
  return *this/Modulo();
}

Vector3 Vector3::operator-() const{
  Vector3 tmp;
  for (int i=0;i<3;i++){
    tmp.m_v[i] = -m_v[i]; 
  }
  return tmp;
}

Vector3 Vector3::operator*(double b) const{
  Vector3 res;
  for (int i=0;i<3;i++){
    res.m_v[i] = m_v[i]*b; 
  }
  return res;
}

Vector3 operator*(double b, const Vector3& V){
  return V*b; //riusa il metodo
}

Vector3 Vector3::operator/(double b) const {
    Vector3 res;

    for (int i = 0; i < 3; i++) {
        res.m_v[i] = m_v[i] / b;
    }

    return res;
}

void Vector3::Print() const {
  cout << "(" << m_v[0] << "," << m_v[1] << "," << m_v[2] << ")" << endl;
}

std :: ostream& operator<<(std::ostream& stream, const Vector3& v){
  stream << "(" << v.X() << "," << v.Y() << "," << v.Z() << ")";
  return stream;
} //v.X e non m_v perché c'è incapsulamento, devo legarmi ai metodi, se mettessi friend avrebbe accesso al private ma perdo il senso di c++

std :: istream& operator>>(std::istream& stream, Vector3& v){ //vettore non const devo modificarlo!
  double x,y,z;
  if (stream >> x >> y >> z)
    v = Vector3(x,y,z);
  return stream;
}

Vector3& Vector3::operator+=(const Vector3& b){
  for (int i=0;i<3;i++){
    m_v[i] += b.m_v[i]; 
  }
  return *this;
}

