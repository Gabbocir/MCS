import ROOT
import math as m

R=1

rnd=ROOT.TRandom3()
rnd.SetSeed(123456789)
ntot=10000
nacc=0

for i in range(0,ntot):
    x=2*R*rnd.Rndm()-R
    y=2*R*rnd.Rndm()-R
    z=2*R*rnd.Rndm()-R # Genero nel cubo di lato R, tra -R e R, le 3 coordinate
    rsph=m.sqrt(x*x+y*y+z*z) # Distanza dal centro della sfera
    rc=m.sqrt(x*x+y*y)  # Distanza da asse del cilindro
    if rsph<R and rc>(R/2):
        nacc=nacc+1

p=nacc/ntot
ep=m.sqrt(p*(1-p)/ntot)
print(p)
vcubo= (2*R)**3
v=p*vcubo
ev=ep*vcubo
print(v)
print(ev)
vsfera=(4/3)*ROOT.TMath.Pi()*R**3
print(vsfera)
