#ifndef _PROTON
#define _PROTON

//#include <cmath>
#include "Particle.h"

class Proton: public Particle{
 public:
  using Particle::Particle;
  // Proton(): Particle(1.6*pow(10,-27), 1.6*pow(10,-19)){};
  Proton(): Particle(1.6e-27), 1.6e-19)){}; 
};

#endif
