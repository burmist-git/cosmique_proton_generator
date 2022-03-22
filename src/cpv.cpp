//my
#include "cpv.hh"

//root
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TString.h>
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TGraph.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TProfile.h>
#include <TRandom3.h>
#include <TMath.h>
#include <TVector3.h>
#include <TGraph2D.h>

//C, C++
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

void cpv::Loop(TString histOut){
  //
  TGraph2D *gr2D_sphere = new TGraph2D();
  gr2D_sphere->SetTitle("gr2D_sphere");
  gr2D_sphere->SetName("gr2D_sphere");
  //
  TGraph2D *gr2D_pint = new TGraph2D();
  gr2D_pint->SetTitle("gr2D_pint");
  gr2D_pint->SetName("gr2D_pint");
  //
  TGraph2D *gr2D_p0 = new TGraph2D();
  gr2D_p0->SetTitle("gr2D_p0");
  gr2D_p0->SetName("gr2D_p0");
  //
  TGraph2D *gr2D_pe0 = new TGraph2D();
  gr2D_pe0->SetTitle("gr2D_pe0");
  gr2D_pe0->SetName("gr2D_pe0");
  //
  Double_t thetaE;
  Double_t costhetaE;
  Double_t phiE;
  TVector3 v1;
  TRandom3 *rnd = new TRandom3(21341);
  //
  TH1D *h1_theta_deg = new TH1D("h1_theta_deg","h1_theta_deg",1000,0.0,180.0);
  TH1D *h1_phi_deg = new TH1D("h1_phi_deg","h1_phi_deg",1000,-10.0,370);
  TH1D *h1_distToEarth = new TH1D("h1_distToEarth","h1_distToEarth",1000,0.0,65.0);
  TH1D *h1_distToTerzina = new TH1D("h1_distToTerzina","h1_distToTerzina",1000,0.0,45.0);
  TH1D *h1_angleTrzinaTrk_deg = new TH1D("h1_angleTrzinaTrk_deg","h1_angleTrzinaTrk_deg",1000,0.0,190.0);
  //
  for(Int_t i = 0;i<1000;i++){
    costhetaE = rnd->Uniform(-1.0,1.0);
    thetaE = TMath::ACos(costhetaE);
    phiE = rnd->Uniform(0.0,TMath::TwoPi());
    v1.SetMagThetaPhi(earthR,thetaE,phiE);
    gr2D_sphere->SetPoint(gr2D_sphere->GetN(),v1.x(),v1.y(),v1.z());
  }
  //
  Long64_t nentries = fChain->GetEntriesFast();
  cout<<"nentries = "<<nentries<<endl;
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    if(angleTrzinaTrk>170.0/180.0*TMath::Pi()){
      gr2D_pint->SetPoint(gr2D_pint->GetN(),x_int,y_int,z_int);
      gr2D_p0->SetPoint(gr2D_p0->GetN(),x0,y0,z0);
      gr2D_pe0->SetPoint(gr2D_pe0->GetN(),xe0,ye0,ze0);
      //
      h1_theta_deg->Fill(theta*180.0/TMath::Pi());
      h1_phi_deg->Fill(phi*180.0/TMath::Pi());
      h1_distToEarth->Fill(distToEarth);
      h1_distToTerzina->Fill(distToTerzina);
      h1_angleTrzinaTrk_deg->Fill(angleTrzinaTrk*180.0/TMath::Pi());
    }
  }
  TFile* rootFile = new TFile(histOut.Data(), "RECREATE", " Histograms", 1);
  rootFile->cd();
  if (rootFile->IsZombie()){
    cout<<"  ERROR ---> file "<<histOut.Data()<<" is zombi"<<endl;
    assert(0);
  }
  else
    cout<<"  Output Histos file ---> "<<histOut.Data()<<endl;
  //
  gr2D_sphere->Write();
  gr2D_pint->Write();
  gr2D_p0->Write();
  gr2D_pe0->Write();
  //
  h1_theta_deg->Write();
  h1_phi_deg->Write();
  h1_distToEarth->Write();
  h1_distToTerzina->Write();
  h1_angleTrzinaTrk_deg->Write();
  //
  rootFile->Close();
}
