//root
#include "TGraph.h"

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

void load_all_particle_spectrum_vs_E( std::string dataFileIn,
				      TGraph *gr_all_particle_spectrum_vs_E_Gev,
				      TGraph *gr_all_particle_spectrum_vs_E_ev,
				      TGraph *gr_all_particle_spectrum_vs_E_Gev_integral);

Int_t all_particle_spectrum_vs_E_old(){
  
  TGraph *gr_all_particle_spectrum_vs_E_Gev = new TGraph();
  TGraph *gr_all_particle_spectrum_vs_E_ev = new TGraph();
  TGraph *gr_all_particle_spectrum_vs_E_Gev_integral = new TGraph();
  gr_all_particle_spectrum_vs_E_Gev->SetName("gr_all_particle_spectrum_vs_E_Gev");
  gr_all_particle_spectrum_vs_E_Gev->SetTitle("gr_all_particle_spectrum_vs_E_Gev");
  gr_all_particle_spectrum_vs_E_ev->SetName("gr_all_particle_spectrum_vs_E_ev");
  gr_all_particle_spectrum_vs_E_ev->SetTitle("gr_all_particle_spectrum_vs_E_ev");
  gr_all_particle_spectrum_vs_E_Gev_integral->SetName("gr_all_particle_spectrum_vs_E_Gev_integral");
  gr_all_particle_spectrum_vs_E_Gev_integral->SetTitle("gr_all_particle_spectrum_vs_E_Gev_integral");
  load_all_particle_spectrum_vs_E("all_particle_spectrum_vs_E.dat", gr_all_particle_spectrum_vs_E_Gev, gr_all_particle_spectrum_vs_E_ev, gr_all_particle_spectrum_vs_E_Gev_integral);
  //
  TCanvas *c1 = new TCanvas("c1","c1",10,10,1200,600);
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetStatColor(kWhite);
  //gStyle->SetOptStat(kFALSE);
  c1->Divide(2,1);
  //
  c1->cd(1);
  gPad->SetGridx();
  gPad->SetGridy();
  gPad->SetLogx();
  gPad->SetLogy();
  //
  gr_all_particle_spectrum_vs_E_Gev->SetTitle("");
  //
  gr_all_particle_spectrum_vs_E_Gev->SetLineColor(kBlack);
  gr_all_particle_spectrum_vs_E_Gev->SetLineWidth(3.0);
  //
  gr_all_particle_spectrum_vs_E_Gev->GetXaxis()->SetRangeUser(1.0e+16,1.0e+21);
  gr_all_particle_spectrum_vs_E_Gev->Draw("APL");
  //
  /*
  gr_all_particle_spectrum_vs_E_ev->SetLineColor(kBlack);
  gr_all_particle_spectrum_vs_E_ev->SetLineWidth(3.0);
  //
  gr_all_particle_spectrum_vs_E_ev->GetXaxis()->SetRangeUser(1.0e+16,1.0e+21);
  gr_all_particle_spectrum_vs_E_ev->Draw("APL");
  */
  //
  /*
  TCanvas *c2 = new TCanvas("c2","c2",10,10,600,600);
  gr_all_particle_spectrum_vs_E_Gev_integral->SetLineColor(kBlack);
  gr_all_particle_spectrum_vs_E_Gev_integral->SetLineWidth(3.0);
  //
  gr_all_particle_spectrum_vs_E_Gev_integral->Draw("APL");
  */
  
  return 0;
}

void load_all_particle_spectrum_vs_E( std::string dataFileIn, TGraph *gr_all_particle_spectrum_vs_E_Gev, TGraph *gr_all_particle_spectrum_vs_E_ev, TGraph *gr_all_particle_spectrum_vs_E_Gev_integral){
  std::ifstream fileIn(dataFileIn.c_str());
  double x;
  double y;
  if (fileIn.is_open()){
    while(fileIn>>x>>y){
      if(x>9.0e+15){
	gr_all_particle_spectrum_vs_E_Gev->SetPoint(gr_all_particle_spectrum_vs_E_Gev->GetN(),x/(1.0e+9),y/(TMath::Power(x/(1.0e+9),2.6)));
	gr_all_particle_spectrum_vs_E_ev->SetPoint(gr_all_particle_spectrum_vs_E_ev->GetN(),x,y/(TMath::Power(x/(1.0e+9),2.6)));
      }
    }
    fileIn.close();
  }
  else cout<<"Unable to open file"<<endl;
}

/*
void count_number_of_events_per_year( TGraph *gr_spectrum, Double_t eMin, Double_t eMax){
  //
  Int_t np = 1000000;
  Double_t xMin = eMin;
  Double_t xMax = eMax;
  Double_t dx = (xMax - xMin)/(np-1);
  Double_t integral_flux = 0.0;
  for(Int_t i = 0;i<np;i++){
    x = xMin + dx*i;
    gr_all_particle_spectrum_vs_E_Gev_integral->SetPoint(gr_all_particle_spectrum_vs_E_Gev_integral->GetN(),x,gr_all_particle_spectrum_vs_E_Gev->Eval(x));
    integral_flux = integral_flux + dx*gr_all_particle_spectrum_vs_E_Gev->Eval(x);
    //cout<<gr_all_particle_spectrum_vs_E_Gev->Eval(x)<<endl;
  }
  cout<<"integral_flux = "<<integral_flux<<endl;
}
*/
