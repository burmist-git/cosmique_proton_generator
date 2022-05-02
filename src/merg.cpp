//my
#include "merg.hh"

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
#include <TMath.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TProfile.h>
#include <TRandom3.h>

//C, C++
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

void merg::Loop(TString histOut){
  //Int_t i = 0;
  //  
  TH1D* h1_theta_deg = new TH1D("h1_theta_deg","theta deg",2000,0,200);
  TH1D* h1_phi_deg = new TH1D("h1_phi_deg","phi deg",2000,-360,360);
  TH1D* h1_angleTrzinaTrk_deg = new TH1D("h1_angleTrzinaTrk_deg","angleTrzinaTrk_deg",2000,-200,200);
  TH1D* h1_nphotons_per_m2 = new TH1D("h1_nphotons_per_m2","nphotons_per_m2",1000,0,1000);
  //
  TH1D* h1_x_int = new TH1D("h1_x_int","h1_x_int",1000,-10000,10000);
  TH1D* h1_y_int = new TH1D("h1_y_int","h1_y_int",1000,-10000,10000);
  TH1D* h1_z_int = new TH1D("h1_z_int","h1_z_int",1000,-10000,10000);
  TH1D* h1_xe0 = new TH1D("h1_xe0","h1_xe0",1000,-10000,10000);
  TH1D* h1_ye0 = new TH1D("h1_ye0","h1_ye0",1000,-10000,10000);
  TH1D* h1_ze0 = new TH1D("h1_ze0","h1_ze0",1000,-10000,10000);
  TH1D* h1_distToEarth = new TH1D("h1_distToEarth","h1_distToEarth",1000,0,100);
  TH1D* h1_distToTerzina = new TH1D("h1_distToTerzina","h1_distToTerzina",1000,0,100);
  //
  TH1D* h1_theta_deg_cut = new TH1D("h1_theta_deg_cut","theta deg_cut",2000,0,200);
  TH1D* h1_phi_deg_cut = new TH1D("h1_phi_deg_cut","phi deg_cut",2000,-360,360);
  TH1D* h1_angleTrzinaTrk_deg_cut = new TH1D("h1_angleTrzinaTrk_deg_cut","angleTrzinaTrk_deg_cut",2000,-200,200);
  TH1D* h1_nphotons_per_m2_cut = new TH1D("h1_nphotons_per_m2_cut","nphotons_per_m2_cut",1000,0,1000);
  //
  TH1D* h1_x_int_cut = new TH1D("h1_x_int_cut","h1_x_int_cut",1000,-10000,10000);
  TH1D* h1_y_int_cut = new TH1D("h1_y_int_cut","h1_y_int_cut",1000,-10000,10000);
  TH1D* h1_z_int_cut = new TH1D("h1_z_int_cut","h1_z_int_cut",1000,-10000,10000);
  TH1D* h1_xe0_cut = new TH1D("h1_xe0_cut","h1_xe0_cut",1000,-10000,10000);
  TH1D* h1_ye0_cut = new TH1D("h1_ye0_cut","h1_ye0_cut",1000,-10000,10000);
  TH1D* h1_ze0_cut = new TH1D("h1_ze0_cut","h1_ze0_cut",1000,-10000,10000);
  TH1D* h1_distToEarth_cut = new TH1D("h1_distToEarth_cut","h1_distToEarth_cut",1000,0,100);
  TH1D* h1_distToTerzina_cut = new TH1D("h1_distToTerzina_cut","h1_distToTerzina_cut",1000,0,100);
  //
  Double_t theta_deg;
  Double_t phi_deg;
  Double_t angleTrzinaTrk_deg;
  //
  Long64_t nentries = fChain->GetEntriesFast();
  cout<<"nentries = "<<nentries<<endl;
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    //
    theta_deg = theta*180.0/TMath::Pi();
    phi_deg = phi*180.0/TMath::Pi();
    angleTrzinaTrk_deg = angleTrzinaTrk*180.0/TMath::Pi();
    //
    h1_theta_deg->Fill(theta_deg);
    h1_phi_deg->Fill(phi_deg);
    h1_angleTrzinaTrk_deg->Fill(angleTrzinaTrk_deg);
    h1_nphotons_per_m2->Fill(nphotons_per_m2);
    //
    h1_x_int->Fill(x_int);
    h1_y_int->Fill(y_int);
    h1_z_int->Fill(z_int);
    h1_xe0->Fill(xe0);
    h1_ye0->Fill(ye0);
    h1_ze0->Fill(ze0);
    h1_distToEarth->Fill(distToEarth);
    h1_distToTerzina->Fill(distToTerzina);
    //
    //cuts
    if(nphotons_per_m2>500){
      //if((distToEarth >= (31-2)) && (distToEarth <= (31+2))){
      //if((theta_deg >= (68.18-0.2)) && (theta_deg <= (68.18+0.2))){
      //if(distToTerzina<10){
      h1_theta_deg_cut->Fill(theta_deg);
      h1_phi_deg_cut->Fill(phi_deg);
      h1_angleTrzinaTrk_deg_cut->Fill(angleTrzinaTrk_deg);
      h1_nphotons_per_m2_cut->Fill(nphotons_per_m2);
      //
      h1_x_int_cut->Fill(x_int);
      h1_y_int_cut->Fill(y_int);
      h1_z_int_cut->Fill(z_int);
      h1_xe0_cut->Fill(xe0);
      h1_ye0_cut->Fill(ye0);
      h1_ze0_cut->Fill(ze0);
      h1_distToEarth_cut->Fill(distToEarth);
      h1_distToTerzina_cut->Fill(distToTerzina);
      //cout<<eventID<<endl;
      cout<<getTrkInfoFileName(eventID)<<endl;
      //}
      //}
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
  h1_theta_deg->Write();
  h1_phi_deg->Write();
  h1_angleTrzinaTrk_deg->Write();
  h1_nphotons_per_m2->Write();
  //
  h1_x_int->Write();
  h1_y_int->Write();
  h1_z_int->Write();
  h1_xe0->Write();
  h1_ye0->Write();
  h1_ze0->Write();
  h1_distToEarth->Write();
  h1_distToTerzina->Write();
  //
  h1_theta_deg_cut->Write();
  h1_phi_deg_cut->Write();
  h1_angleTrzinaTrk_deg_cut->Write();
  h1_nphotons_per_m2_cut->Write();
  //
  h1_x_int_cut->Write();
  h1_y_int_cut->Write();
  h1_z_int_cut->Write();
  h1_xe0_cut->Write();
  h1_ye0_cut->Write();
  h1_ze0_cut->Write();
  h1_distToEarth_cut->Write();
  h1_distToTerzina_cut->Write();
  //
  rootFile->Close();
}

TString merg::getTrkInfoFileName(Int_t eventIDmy){
  // 
  //../easchersim/root/00000/trkInfo_0000021.dat
  //
  char buffer [8];
  sprintf(buffer ,"%07d", eventIDmy);
  TString rootDir = "../easchersim/root/";
  Int_t nFilesPerDir = 200;
  Int_t dirNameID = eventIDmy/nFilesPerDir;
  char buffer2 [6];
  sprintf(buffer2 ,"%05d", dirNameID);
  TString fileNameIDstr =  buffer2;
  rootDir += fileNameIDstr;
  rootDir += "/";
  //
  TString fileNameID =  buffer;
  //
  TString fileName = rootDir;
  fileName += "trkInfo_";
  //
  fileName += fileNameID;
  fileName += ".dat";
  //cout<<fileName<<endl;
  return fileName;
}
