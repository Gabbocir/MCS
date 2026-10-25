#include "Vector3.h"
#include <iostream>

using namespace std;

int main (){
  Vector3 a;
  Vector3 b(2,2,1);
  Vector3 c(1);
  Vector3 d;
  Vector3 e(1,1,1);
  
  a=b+c;
  d=-c;
  
  cout << a.Z() << endl;
  cout << d.Y() << endl;
  
  
  return 0;
}
