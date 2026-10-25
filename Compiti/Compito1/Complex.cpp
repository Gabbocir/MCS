#include "Complex.h"
#include <cmath>
#include <stdexcept> // Introdotto per la gestione della divisione per zero

double Complex::Real() const{
  return X();
}

double Complex::Img() const{
  return Y();
}

// Per i getters, utilizzo i metodi X() e Y() della classe base TVector2

Complex Complex::Conjugate() const{
  Complex zcon (X(),-Y());
  return zcon;
}


Complex Complex::operator*(const Complex& z) const{
  Complex res (Real()*z.Real()-Img()*z.Img(), Real()*z.Img()+Img()*z.Real());
  return res;
}

Complex Complex::operator/(const Complex& z) const{
  double denominatore = z.Real()*z.Real()+z.Img()*z.Img();
  if (denominatore==0){
     throw std::domain_error(
            "Viene richiesta una operazione che non si può svolgere (divisione con il denominatore uguale a zero!)"
        );
  } 
    return (*this*z.Conjugate())*(1.0/denominatore);
}


// Per la gestione della divisione per zero utilizzo throw che interrompe il calcolo e restituisce un messaggio di errore. L'unico difetto di questa configurazione è che la presenza di una numerical exception di fatto abortisce il resto del Main (opzione a mio avviso preferibile rispetto alla restituzione di un nan o un complex "fantasma" da interpretare come un calcolo non andato a buon fine).


Complex Complex::Pow(int n) const{
  Complex res (1,0);
  for (int i=0; i<std::abs(n); i++){
    res=res*(*this);
  } if(n<0){
    return Complex (1,0)/res;
  } else {
    return res;
  }
}

// La gestione di Pow fa utilizzo della moltiplicazione implementata in precedenza; in automatico si gestisce la numerical exception base nulla ed esponente negativo (richiamando l'errore della divisione per zero).
// Tramite AI (Chat GPT) verifico e correggo una bozza in cui avevo sbagliato la gestione dell'esponente negativo (mandavo il ciclo for per i intero minore di un numero negativo) tramite il metodo standard abs (che prende il modulo di n).
// Utilizzo un ciclo for in comune e gestisco in seguito il risultato in base al segno dell'esponente.

std::ostream& operator<<(std::ostream& output, const Complex& z) {
    if (z.Real() != 0) {
        output << z.Real();
    }

    if (z.Img() > 0) {
        if (z.Real() != 0) output << "+";
        if (z.Img() != 1) output << z.Img();
        output << "i";
    }
    else if (z.Img() < 0) {
        output << "-";
        if (z.Img() != -1) output << -z.Img();
        output << "i";
    }

    if (z.Real() == 0 && z.Img() == 0) {
        output << "0";
    }

    return output;
}

// Come abbellimento grafico, introduco una logica di controllo di stampa assistito da AI (Chat GPT); in autonomia avevo implementato la gestione del segno (con l'utilizzo di if, valutando il valore della parte immaginaria), che viene ulteriormente migliorata con la gestione di 1 (nella parte immaginaria stampa solo i) e degli 0.


std::istream& operator>>(std::istream& input, Complex& z){
  double Re, Im;
  input >> Re >> Im;
  z.SetX(Re); z.SetY(Im);
  return input;
}
//Ciao

