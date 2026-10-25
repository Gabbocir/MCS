#ifndef _MATPOINT
#define _MATPOINT

#include "Particle.h"
#include "Vector3.h"

class MatPoint: public Particle{
 private:
  Vector3 m_R; // Vettore posizione
  Vector3 m_V; // Vettore velocità
  
 public:
  // using Particle::Particle;
  MatPoint(double mass, double charge, Vector3 R, Vector3 V):Particle(mass, charge), m_R(R), m_V(V){}; // Costruttore dove specifico mass e charge della classe base
  MatPoint(Particle p = Particle(), Vector3 R = Vector3(), Vector3 V = Vector3()):Particle(p), m_R(R), m_V(V){}; // Costruttore che fa uso della classe base particle con default

  Vector3 R(); // Getter per R
  Vector3 V(); // Getter per V
  void R (Vector3); // Setter per R
  void V (Vector3); // Setter per V
  Vector3 GravField(Vector3); // Campo gravitazionale con Vector3 (posizione dove calcolo) e MatPoint in automatico perché è un metodo
};

#endif
