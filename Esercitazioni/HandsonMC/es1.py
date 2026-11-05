import ROOT
import math as m

rnd=ROOT.TRandom3()
rnd.SetSeed(123456789)

h=ROOT.TH1D("h","Dec. rad.", 100, 0, 5)
hm= ROOT.TH1D("hm","Dec. rad. meas.",100, 0, 5)
hr=ROOT.TH1D("hr","Dec. rad. ris.", 100, 0, 5)

tau1=0.1
tau2=1.0
f=0.3

tauACC=0.1

sigma=0.01

ntot=10000

for i in range(0,ntot):
    if rnd.Rndm()<f:
        #decadimento con tau1
        tau=tau1
    else:
        #decadimento con tau2
        tau=tau2

    t=-tau*m.log(1-rnd.Rndm())
    h.Fill(t)
    if rnd.Rndm()<(1-m.exp(-t/tauACC)):
        hm.Fill(t)
        tres=rnd.Gaus(t,sigma)
        hr.Fill(tres)
        
h.Draw()

hm.SetLineColor(2)
hm.Draw("SAME")

hr.SetLineColor(3)
hr.Draw("SAME")

ROOT.gApplication.Run(True)
