#include "Complex.h"
#include <iostream>

using namespace std;

int main(){
  Complex a,b;
  cout << "Inserire il numero complesso a (parte reale e parte immaginaria intervallati da uno spazio; e.g. 1 1 per 1+i)" << endl;
  cin >> a;
  
  cout << "Inserire il numero complesso b" << endl;
  cin >> b;

  
  cout << "La somma tra a e b è: " << a+b << endl;
  cout << "La differenza tra a e b è: " << a-b << endl;
  cout << "Il prodotto tra a e b è: " << a*b << endl;
  cout << "La divisione tra a e b è: " << a/b << endl;
  cout << "La potenza di a con esponente 2 vale: " << a.Pow(2) << endl;
  cout << "La potenza di a con esponente 0 vale: " << a.Pow(0) << endl;
  cout << "La potenza di a con esponente -1 vale: " << a.Pow(-1) << endl;
  cout << "Il  coniugato di a è: " << a.Conjugate() << endl;

  // Stampa delle operazioni richieste nella traccia per i complessi a e b.
  // Nella consegna si richiede di inserire a(1,1), b(1,2) e confrontare i risultati, che coincidono con i calcoli a mano.

  return 0;
}


// Versioni utilizzate: C++11 e ROOT 6.32.04.
// Istruzione di compilazione: make
// Istruzione di esecuzione: ./Main
