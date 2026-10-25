#ifndef _ELECTRON
#define _ELECTRON

//#include <cmath>
#include "Particle.h"

class Electron: public Particle{
 public:
  using Particle::Particle;
  //Electron(): Particle(9*pow(10,-31), -1.6*pow(10,-19)){}; così fa i calcoli, meglio non farglieli fare
  Electron(): Particle(9e-31, -1.6e-19){}; 
  
};

#endif
