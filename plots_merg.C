//C, C++
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include <time.h>

using namespace std;

TString getObjectName(TString namein, Int_t i);

Int_t plots_merg(){

  TString fileN;
  TString objectName;
  fileN = "./histMerge.root";

  TFile *f1 = new TFile(fileN.Data());

  //TH1D *h1_1 = (TH1D*)f1->Get("h1_nphotons_per_m2");
  //TH1D *h1_1_cut = (TH1D*)f1->Get("h1_nphotons_per_m2_cut");
  //TH1D *h1_1 = (TH1D*)f1->Get("h1_theta_deg");
  //TH1D *h1_1_cut = (TH1D*)f1->Get("h1_theta_deg_cut");
  //TH1D *h1_1 = (TH1D*)f1->Get("h1_distToEarth");
  //TH1D *h1_1_cut = (TH1D*)f1->Get("h1_distToEarth_cut");
  TH1D *h1_1 = (TH1D*)f1->Get("h1_distToTerzina");
  TH1D *h1_1_cut = (TH1D*)f1->Get("h1_distToTerzina_cut");

  h1_1->Rebin(4);
  h1_1_cut->Rebin(4);
  h1_1->SetTitle("");

  //TCanvas *c1 = new TCanvas("c1",fileN.Data(),10,10,800,800);
  TCanvas *c1 = new TCanvas("c1",fileN.Data(),10,10,600,600);
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetStatColor(kWhite);
  //gStyle->SetOptStat(kFALSE);
 
  h1_1->SetLineColor(kBlack);
  h1_1->SetLineWidth(3.0);
  h1_1_cut->SetLineColor(kRed);
  h1_1_cut->SetLineWidth(3.0);


  h1_1->Draw();
  h1_1_cut->Draw("sames");

  h1_1->SetMinimum(0.1);

  TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,"","brNDC");
  leg->AddEntry(h1_1,     "All events", "apl");
  leg->AddEntry(h1_1_cut, "Photon density > 400 (1/m/m)", "apl");
  leg->Draw();

  
  //h1_1->GetXaxis()->SetTitle("Photon density, 1/m/m");
  //h1_1->GetXaxis()->SetTitle("Track theta, deg");
  //h1_1->GetXaxis()->SetTitle("Height, km");
  h1_1->GetXaxis()->SetTitle("Distance to Terzina, km");
  //h1_1->GetXaxis()->SetRangeUPhoton densityser(-0.13,-0.12);

  /*
  for(i = 0;i<nChannels;i++){
    h1_Arr[i]->SetLineColor(colorArr[i]);
    h1_Arr[i]->SetLineWidth(3.0);
    if(i == 0){
      h1_Arr[i]->Draw();
      h1_Arr[i]->GetXaxis()->SetTitle("Value, Unit");
      //h1_1->GetXaxis()->SetRangeUser(-0.13,-0.12);
    }
    else
      h1_Arr[i]->Draw("same");
  }
  
  //h1_1->Fit("gaus");
  TString legInfo;
  TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,"","brNDC");
  for(i = 0;i<nChannels;i++){
    legInfo = "ch ";legInfo += i;
    leg->AddEntry(h1_Arr[i], legInfo.Data(), "l");
  }
  leg->Draw();
  */

  //mg->GetXaxis()->SetTitle("ValueX, Unit");
  //mg->GetYaxis()->SetTitle("ValueY, Unit");

  /*
  TString legInfo;

  for(i = 0;i<nChannels;i++){
    legInfo = "ch ";legInfo += i;
    leg->
  }

  */  

  return 0;
}
