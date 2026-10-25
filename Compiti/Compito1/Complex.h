#ifndef _COMPLEX
#define _COMPLEX

#include "TVector2.h"
#include <iostream>



class Complex: public TVector2{
 public:
 explicit Complex(double Re=0, double Im=0): TVector2(Re, Im){};
 Complex(const TVector2& z):TVector2 (z) {};
 
  double Real() const;
  double Img() const;
  Complex Conjugate() const;
  Complex operator*(const Complex&) const;
  Complex operator/(const Complex&) const;
  Complex Pow(int n) const;

};

std::ostream& operator<<(std::ostream& output, const Complex& z);
std::istream& operator>>(std::istream& input, Complex& z);

#endif

// Definisco due costruttori: il primo (explicit) da parte reale e immaginaria nel quale inglobo anche il default, ciò mi permette di costruire un complex anche specificando solo la componente reale; il secondo da const TVector2&; concedo la conversione implicita nel secondo al fine di riutilizzare diversi operatori della classe base, ossia somma, differenza e moltiplicazione per scalare; quest'ultima non è ambigua data la scelta di mettere explicit nel primo costruttore (in entrambe le configurazioni dell'operazione così facendo non si corre il rischio che lo scalare venga interpretato come complex con parte reale uguale allo scalare e parte immaginaria nulla).


// Per quanto riguarda la moltiplicazione e la divisione tra complessi, ho un overload degli operatori * e /; inoltre aggiungo la potenza (che fa uso della moltiplicazione).

// Definisco << e >> per stampa e lettura di un numero complesso.
