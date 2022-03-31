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
				      TGraphErrors *gr_all_particle_spectrum_vs_E_Gev,
				      TGraph *gr_all_particle_spectrum_vs_E_ev);

Double_t getFlux(TF1 *f_cpf, Double_t el, Double_t er);

Double_t cpf(Double_t *x, Double_t *par){
  Double_t A  = par[0];
  Double_t B  = par[1];
  Double_t C  = par[2];
  Double_t val = A/(TMath::Power(x[0],B)) + C;
  return val;
}

Int_t all_particle_spectrum_vs_E(){
  //
  TGraphErrors *gr_all_particle_spectrum_vs_E_Gev = new TGraphErrors();
  TGraph *gr_all_particle_spectrum_vs_E_ev = new TGraph();
  //
  gr_all_particle_spectrum_vs_E_Gev->SetName("gr_all_particle_spectrum_vs_E_Gev");
  gr_all_particle_spectrum_vs_E_Gev->SetTitle("gr_all_particle_spectrum_vs_E_Gev");
  gr_all_particle_spectrum_vs_E_ev->SetName("gr_all_particle_spectrum_vs_E_ev");
  gr_all_particle_spectrum_vs_E_ev->SetTitle("gr_all_particle_spectrum_vs_E_ev");
  load_all_particle_spectrum_vs_E("all_particle_spectrum_vs_E.dat", gr_all_particle_spectrum_vs_E_Gev, gr_all_particle_spectrum_vs_E_ev);
  //
  TCanvas *c1 = new TCanvas("c1","c1",10,10,1200,600);
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetStatColor(kWhite);
  gStyle->SetOptStat(kFALSE);
  c1->Divide(2,1);
  //
  c1->cd(1);
  c1->SetRightMargin(0.01);
  c1->SetLeftMargin(0.13);
  c1->SetTopMargin(0.01);
  c1->SetBottomMargin(0.1);
  //
  gPad->SetGridx();
  gPad->SetGridy();
  gPad->SetLogx();
  gPad->SetLogy();
  //
  gPad->SetRightMargin(0.01);
  gPad->SetLeftMargin(0.13);
  gPad->SetTopMargin(0.01);
  gPad->SetBottomMargin(0.1);
  //
  gr_all_particle_spectrum_vs_E_Gev->SetTitle("");
  //
  gr_all_particle_spectrum_vs_E_Gev->SetLineColor(kBlack);
  gr_all_particle_spectrum_vs_E_Gev->SetLineWidth(3.0);
  //
  gr_all_particle_spectrum_vs_E_Gev->GetXaxis()->SetRangeUser(1.0e+16,1.0e+21);
  gr_all_particle_spectrum_vs_E_Gev->Draw("APL");
  //
  gr_all_particle_spectrum_vs_E_Gev->GetXaxis()->SetTitle("E, GeV");
  gr_all_particle_spectrum_vs_E_Gev->GetYaxis()->SetTitle("Flux, 1/GeV 1/m^2 1/s 1/sr");
  //
  //
  //Fit
  //
  const Int_t npar = 3;
  Double_t inParameters[npar];
  Double_t e_min  = 1.0*1.0e+7;
  Double_t e_max  = 1.0*1.0e+11;
  Double_t f_max  = 7.0*1.0e-15;
  Double_t f_min  = 1.0*1.0e-27;
  //inParameters[1] = 3.0;
  //inParameters[2] = 0.0;
  //inParameters[0] = f_max*TMath::Power(e_min,inParameters[1]);
  //inParameters[3] = 0.0;
  //
  inParameters[0] = 1.86773e+07;
  inParameters[1] = 3.09484e+00;
  inParameters[2] = -5.05398e-29;
  //
  TF1 *f_cpf = new TF1( "f_cpf", cpf, e_min, e_max, npar);
  f_cpf->SetParameters(inParameters);
  f_cpf->SetParName(0, "A");
  f_cpf->SetParName(1, "B");
  f_cpf->SetParName(2, "C");
  f_cpf->FixParameter(0,inParameters[0]);
  f_cpf->FixParameter(1,inParameters[1]);
  f_cpf->FixParameter(2,inParameters[2]);
  gr_all_particle_spectrum_vs_E_Gev->Fit("f_cpf","","",e_min, e_max);
  ///////////////////

  ///////////////////
  Double_t loge_min = TMath::Log10(e_min);
  Double_t loge_max = TMath::Log10(e_max);
  Double_t loge;
  Double_t el;
  Double_t er;
  Int_t nn = 101;
  const Int_t nnHist = 100;
  Double_t *binEdges = new Double_t[nnHist];
  ///////////////////

  ///////////////////
  Double_t earthR = 6371000.0;
  Double_t satelliteH = 525000.0;
  Double_t efficiency = 5.3e-9;
  Double_t efficiencyTime = 0.4;
  Double_t nYears = 3.0;
  //
  Double_t flux_de;
  Double_t particle_per_year;
  //
  Double_t flux_de_more;
  Double_t particle_per_year_more;
  //
  for(Int_t i = 0;i<(nn-1);i++){
    //
    loge = loge_min + (loge_max-loge_min)/(nn-1)*i;
    el = TMath::Power(10,loge);
    binEdges[i] = el;
  }
  //
  TH1D *h1_particle_per_year = new TH1D("h1_particle_per_year","h1_particle_per_year",nnHist-1,binEdges);
  TH1D *h1_particle_per_year_more = new TH1D("h1_particle_per_year_more","h1_particle_per_year_more",nnHist-1,binEdges);
  //
  for(Int_t i = 0;i<(nn-1);i++){
    //
    loge = loge_min + (loge_max-loge_min)/(nn-1)*i;
    el = TMath::Power(10,loge);
    loge = loge_min + (loge_max-loge_min)/(nn-1)*(i+1);
    er = TMath::Power(10,loge);
    //
    //cout<<"er - el = "<<er - el<<endl;
    //
    flux_de = getFlux(f_cpf,el,er);
    particle_per_year = TMath::Pi()*(earthR + satelliteH)*(earthR + satelliteH)*4*TMath::Pi()*flux_de*efficiency*efficiencyTime*3600.0*24.0*365.0*nYears;
    //cout<<particle_per_year<<endl;
    //h1_particle_per_year->SetBins(i+1, el, er);
    h1_particle_per_year->SetBinContent(i+1, particle_per_year);
    //
    flux_de_more = getFlux(f_cpf,el,e_max);
    particle_per_year_more = TMath::Pi()*(earthR + satelliteH)*(earthR + satelliteH)*4*TMath::Pi()*flux_de_more*efficiency*efficiencyTime*3600.0*24.0*365.0*nYears;
    h1_particle_per_year_more->SetBinContent(i+1, particle_per_year_more);
    //
    cout<<"particle_per_year      = "<<particle_per_year<<endl
	<<"particle_per_year_more = "<<particle_per_year_more<<endl;
    //binEdges[i] = el;
  }
  //
  //  
  ///////////////////
  //flux_de =  getFlux(f_cpf, e_min, e_max);
  //particle_per_year = TMath::Pi()*(earthR + satelliteH)*(earthR + satelliteH)*4*TMath::Pi()*flux_de*efficiency*efficiencyTime*3600.0*24.0*365.0;
  //cout<<particle_per_year<<endl;
  
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
  //  
  //
  c1->cd(2);
  gPad->SetRightMargin(0.01);
  gPad->SetLeftMargin(0.13);
  gPad->SetTopMargin(0.01);
  gPad->SetBottomMargin(0.1);
  //
  gPad->SetGridx();
  gPad->SetGridy();
  gPad->SetLogx();
  gPad->SetLogy();
  //
  h1_particle_per_year->SetTitle("");
  h1_particle_per_year_more->SetTitle("");
  //TCanvas *c2 = new TCanvas("c2","c2",10,10,600,600);
  h1_particle_per_year_more->SetLineColor(kRed);
  h1_particle_per_year_more->SetMarkerColor(kRed);
  h1_particle_per_year->SetLineColor(kBlack);
  h1_particle_per_year_more->SetLineWidth(3.0);
  h1_particle_per_year->SetLineWidth(3.0);
  h1_particle_per_year_more->Draw();
  h1_particle_per_year->Draw("same");
  h1_particle_per_year->GetXaxis()->SetTitle("E, GeV");
  h1_particle_per_year->GetYaxis()->SetTitle("Number of event during 3 years");
  h1_particle_per_year_more->GetXaxis()->SetTitle("E, GeV");
  h1_particle_per_year_more->GetYaxis()->SetTitle("Number of event during 3 years");
  //
  TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,"","brNDC");
  leg->AddEntry(h1_particle_per_year, "Per bin", "pl");
  leg->AddEntry(h1_particle_per_year_more, "Cumulated", "pl");
  leg->Draw();
  //
  //TCanvas *c2 = new TCanvas("c2","c2",10,10,600,600);
  //h1_particle_per_year_more->SetLineColor(kBlack);
  //h1_particle_per_year_more->SetLineWidth(3.0);
  //h1_particle_per_year_more->Draw();
  //
  return 0;
}

void load_all_particle_spectrum_vs_E( std::string dataFileIn, TGraphErrors *gr_all_particle_spectrum_vs_E_Gev, TGraph *gr_all_particle_spectrum_vs_E_ev){
  std::ifstream fileIn(dataFileIn.c_str());
  double x;
  double y;
  if (fileIn.is_open()){
    while(fileIn>>x>>y){
      if(x>9.0e+15){
	gr_all_particle_spectrum_vs_E_Gev->SetPoint(gr_all_particle_spectrum_vs_E_Gev->GetN(),x/(1.0e+9),y/(TMath::Power(x/(1.0e+9),2.6)));
	gr_all_particle_spectrum_vs_E_Gev->SetPointError((gr_all_particle_spectrum_vs_E_Gev->GetN()-1),0.05*x/(1.0e+9),0.10*(y/(TMath::Power(x/(1.0e+9),2.6))));
	gr_all_particle_spectrum_vs_E_ev->SetPoint(gr_all_particle_spectrum_vs_E_ev->GetN(),x,y/(TMath::Power(x/(1.0e+9),2.6)));
      }
    }
    fileIn.close();
  }
  else cout<<"Unable to open file"<<endl;
}

Double_t getFlux(TF1 *f_cpf, Double_t el, Double_t er){
  //
  Int_t n = 10000000;
  Double_t dx = (er - el)/n;
  Double_t x;
  Double_t integral_flux = 0.0;
  for(Int_t i = 0;i<n;i++){
    x = el + dx/2.0 + dx*i;
    integral_flux = integral_flux + dx*f_cpf->Eval(x);
    //cout<<f_cpf->Eval(x)<<endl;
  }
  //cout<<"integral_flux = "<<integral_flux<<endl;
  return integral_flux;
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
