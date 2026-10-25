#include <iostream>

//Non scrivere using namespace nei file header (.h): verrebbe imposto a tutti i sorgenti che li includono

// Un template va inteso come una sorta di dichiarazione e fornito in un header file (che per`o deve contenere dichiarazione e definizione delle funzioni)

std ::ostream& operator <<(std::ostream& stream, const Vector3& v);
std ::istream& operator >>(std::istream& stream, Vector3& v);

class Vector3;
Vector3 operator*(double, const Vector3&);

class Vector3{
 public:
  Vector3(double x=0, double y=0, double z=0):m_v{x,y,z}{}

  double X() const ;  //getter non modifica
  void X(double);  //setter modifica
  double Y() const;  //getter non modifica
  void Y(double);  //setter modifica
  double Z() const;  //getter non modifica
  void Z(double);  //setter modifica
  
  Vector3 operator+(const Vector3&) const;
  Vector3 operator-() const;
  Vector3 operator*(double) const;
  Vector3 operator/(double) const;
  void Print() const;
  Vector3& operator+=(const Vector3&);
  double ProdottoScalare(const Vector3&) const; //double perché è scalare, non lo chiamo operator ma essendo in public prende un vettore e tra parentesi gli do il secondo (Potrei anche pensarlo come overload di operator* dandogli come input non il double ma il vettore

  double Modulo() const;
  Vector3 Versore() const;
  
  // Regola: ogni metodo che non modifica l’oggetto va dichiarato const; ogni oggetto letto (e non modificato) si passa per const&
 private:
  double m_v[3];
};
