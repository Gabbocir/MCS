
#include <cmath>
#include <fstream>
#include <vector>

#include <TGraph.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TH2D.h>
#include <TApplication.h>
#include <TStyle.h>
#include <TSystem.h>

#include "OdeSolver.h"
#include "Vector3.h"
#include "MatPoint.h"

using namespace std;

Vector3 ForzaInterna(unsigned int i,unsigned int j, double t, vector<MatPoint> p){
  //STEP 2 definizione forza interna
  // * ritorna la forza interna che il corpo j esercita su i
  double mi=p[i].Mass(); // Prendo la massa del punto i-esimo
  Vector3 Fij=mi*p[j].GravField(p[i].R()); // Calcolo la forza come prodotto tra la massa di mp i-esimo moltiplicata al Campo Gravitazione del mp j-esimo calcolato nel punto in cui si trova mp i-esimo
  return Fij;
}

Vector3 ForzaEsterna(unsigned int i, double t, vector<MatPoint> p){
  //STEP 2 definizione forza esterna
  // * ritorna la forza esterna sul corpo i
  return Vector3(); // Così torna la forza esterna nulla!
}

int main(){ 
  
  TApplication app("app",0,NULL);
  gStyle->SetOptStat(0);

  //Lettura dei dati dal file
  double mass;
  double x,y,z,vx,vy,vz;
  ifstream f("fileInput.dat");

  // STEP 1 - opzione 1
  OdeSolver ode("Rk2"); // * Creazione OdeSolver vuoto (senza passare vector<MatPoint>);
    
  while (f >> mass >> x >> y >> z >> vx >> vy >> vz){
    Vector3 R (x,y,z);
    Vector3 V (vx,vy,vz);
    MatPoint tmp (mass, 0, R, V);
    ode.AddMatPoint(tmp);  
  } // * Assegnazione dei MatPoint con il metodo AddMatPoint

  // Creazione classe OdeSolver (per la soluzione dell'equ. diff.)
  double giorno = 86400; // giorno in secondi
  ode.fInternal = ForzaInterna;
  ode.fExternal = ForzaEsterna;
  ode.DeltaT(0.5*giorno);

  
  //Creazione dei grafici (uno per pianeta)
  vector<TGraph> gr(ode.N());
  TCanvas c("c","",10,10,500,500);
  
  //Preparazione grafico delle coordinate dei pianeti
  double au = 1.5e8;   // unita' astronimica in km
  double size = 15*au;  // 5 unita' astronimiche
  c.DrawFrame(-size,-size,size,size);
  int color[10]={kOrange+1,kViolet+1,kGreen+2,kAzure+1,kRed+2,kRed-7,kCyan-8,kBlue-7,kBlue+1,kBlue+2};
  for (unsigned int i=0;i<ode.N();i++){
    gr[i].SetPoint(0,ode.GetMatPoint(i).R().X(),ode.GetMatPoint(i).R().Y());
    gr[i].SetMarkerColor(color[i]); gr[i].SetMarkerStyle(20); gr[i].SetMarkerSize(0.1);
    if (i==0) gr[i].SetMarkerSize(1);
    gr[i].Draw("P");
  }
  c.Modified(); c.Update();
  app.Run(true);

  //Run del metodo numerico + grafico in tempo reale delle coordinate e del mom. angolare totale
  while (ode.T()<365*giorno){
    ode.Step();
    for (unsigned int i=0;i<ode.N();i++){
      //STEP 4 riempimento delle grafico gr[i] con le coordinate aggiornate dei pianeti
      
      gr[i].AddPoint(ode.GetMatPoint(i).R().X(),ode.GetMatPoint(i).R().Y());
      // * accedere al MatPoint i-esimo, al vettore di coordinate spaziali, alla coordinata voluta
      // * inserire nel grafico gr[i] le coordinate X e Y
     
    } 
    c.Modified(); c.Update();
    gSystem->ProcessEvents();
  }

  app.Run(true);

  return 0;
  
  
}
