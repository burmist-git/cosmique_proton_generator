//root
#include "TROOT.h"
#include "TString.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TVector3.h"
#include "TGraph.h"
#include "TMath.h"
#include "TFree.h"
#include "TBranch.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

//C, C++
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

TString getTrkInfoFileName(Int_t eventIDmy);
bool file_exists_test(TString inFileName);
void readDatTrkFile(TString fileName, Double_t &theta, Double_t &phi,
		    Double_t &x_int, Double_t &y_int, Double_t &z_int,
		    Double_t &xe0, Double_t &ye0, Double_t &ze0,
		    Double_t &distToEarth, Double_t &distToTerzina, Double_t &angleTrzinaTrk, Double_t &nphotons_per_m2);

int main(int argc, char *argv[]){
  if(argc == 3 && atoi(argv[1])==0){
    //theta       phi         x_int         y_int          z_int           xe0           ye0           ze0   distToEarth distToTerzina angleTrzinaTrk nphotons_per_m2
    //1.17783 4.71672 -3.75600184791 4.75931915385 6907.4891108 -14.3110148761 2444.12518573 5896.30158632 11.8148277637 12.9907018941 3.13758826212 6.80357827031
    //
    TString outputRootFile = argv[2];
    //
    Int_t eventID;
    Double_t theta;
    Double_t phi;
    Double_t x_int, y_int, z_int;
    Double_t xe0, ye0, ze0;
    Double_t distToEarth;
    Double_t distToTerzina;
    Double_t angleTrzinaTrk;
    Double_t nphotons_per_m2;
    //
    TFile *hfile = new TFile(outputRootFile.Data(), "RECREATE", "cosmique proton generator", 1);
    if (hfile->IsZombie()) {
      cout << "PROBLEM with the initialization of the output ROOT ntuple " 
	   << outputRootFile << ": check that the path is correct!!!"
	   << endl;
      assert(0);
    }
    TTree *tree = new TTree("T", "cosmique proton generator");
    hfile->SetCompressionLevel(2);
    tree->SetAutoSave(1000000);
    // Create new event
    TTree::SetBranchStyle(0);
    //
    //
    tree->Branch("eventID",&eventID, "eventID/I");
    //
    tree->Branch("theta",&theta, "theta/D");
    tree->Branch("phi",&phi, "phi/D");
    //
    tree->Branch("x_int",&x_int, "x_int/D");
    tree->Branch("y_int",&y_int, "y_int/D");
    tree->Branch("z_int",&z_int, "z_int/D");
    //
    tree->Branch("xe0",&xe0, "xe0/D");
    tree->Branch("ye0",&ye0, "ye0/D");
    tree->Branch("ze0",&ze0, "ze0/D");
    //
    tree->Branch("distToEarth",&distToEarth, "distToEarth/D");
    tree->Branch("distToTerzina",&distToTerzina, "distToTerzina/D");
    tree->Branch("angleTrzinaTrk",&angleTrzinaTrk, "angleTrzinaTrk/D");
    //
    tree->Branch("nphotons_per_m2",&nphotons_per_m2, "nphotons_per_m2/D");
    //
    TString  fileName;
    for(Int_t i = 0;i<110000;i++){
      eventID = i;
      fileName = getTrkInfoFileName(eventID);
      //cout<<fileName<<endl;
      if(i%1000==0)
	cout<<i<<endl;
      if(file_exists_test(fileName)){
	readDatTrkFile(fileName.Data(), theta, phi, x_int, y_int, z_int, xe0, ye0, ze0, distToEarth, distToTerzina, angleTrzinaTrk, nphotons_per_m2);
	tree->Fill();
      }
    }
    //
    hfile = tree->GetCurrentFile();
    hfile->Write();
    hfile->Close();
  }
  else{
    //------------------------------------------------
    cout<<" --> ERROR in input arguments "<<endl
	<<" runID [1] = 0 (execution ID number)"<<endl
	<<"       [3] - output root file"<<endl;
  }
  return 0;
}

TString getTrkInfoFileName(Int_t eventIDmy){
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

bool file_exists_test(TString inFileName){
  if (FILE *file = fopen(inFileName.Data(), "r")) {
    fclose(file);
    return true;
  }else {
    return false;
  }  
  return false;
}

void readDatTrkFile(TString fileName, Double_t &theta, Double_t &phi, 
		    Double_t &x_int, Double_t &y_int, Double_t &z_int, 
		    Double_t &xe0, Double_t &ye0, Double_t &ze0, 
		    Double_t &distToEarth, Double_t &distToTerzina, Double_t &angleTrzinaTrk, Double_t &nphotons_per_m2){
  x_int = -999.0;
  y_int = -999.0;
  z_int = -999.0;
  xe0 = -999.0;
  ye0 = -999.0;
  ze0 = -999.0;
  distToEarth = -999.0;
  distToTerzina = -999.0;
  angleTrzinaTrk = -999.0;
  nphotons_per_m2 = -999.0;
  //
  ifstream myfile(fileName.Data());
  string mot;
  if(myfile.is_open()){
    for(Int_t i = 0;i<12;i++)
      myfile>>mot;
    myfile>>theta>>phi>>x_int>>y_int>>z_int>>xe0>>ye0>>ze0>>distToEarth>>distToTerzina>>angleTrzinaTrk>>nphotons_per_m2;
    myfile.close();
  }
}
