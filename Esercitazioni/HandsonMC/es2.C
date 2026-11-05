{
  double L=0.01;
  double d=0.2;

  TRandom3 rnd;
  rnd.SetSeed(123456789);

  int ntot=100000;
  int n1=0;

  for(int i=0;i<ntot;i++){
    double phi=2*TMath::Pi()*rnd.Rndm(); // Estraggo uniformemente tra 0 e 1 poi moltiplico per 2pi e ho phi distribuito uniformemente tra 0 e 2 pigreco (Distribuzione d(phi))
    double costheta=2*rnd.Rndm()-1; // Estraggo uniformemente tra 0 e 1, moltiplico così stretcho e traslo così ho coseno estratto uniformemente tra -1 e 1 (guarda appunti la distribuzione è sen(teta)dteta=d(cos(teta)))
    double theta=acos(costheta);
    double alpha=d/costheta; // Fattore moltiplicativo per passare da versore a piano z=d
    if(theta> TMath::Pi()/2){
      continue;
    }
    double x=alpha*sin(theta)*cos(phi);
    double y=alpha*sin(theta)*sin(phi);
    if (abs(x)<L/2 && abs(y)<L/2){
      n1++; // Incremento n1 se x e y cascano dentro quadratino
    }
  }
  double p=(double)n1/ntot;
  double ep=sqrt(p*(1-p)/ntot); // Errore della binomiale
  cout << "Rapporto p=n1/ntot con errore: " << p << "+-" << ep << endl;
  double dml=L*L/(4*TMath::Pi()*d*d);
  cout << "Per d>>>L, si ottiene: " << dml << endl;
  
}
