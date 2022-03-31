#ifndef cpvbase_hh
#define cpvbase_hh

#include <TROOT.h>

class TChain;
class TFile;
class TTree;
class TString;
class TBranch;
class TGraph;
class TH1D;
class TH2D;
class TProfile;

class cpvbase {

public :
  cpvbase(TString fileList);
  cpvbase(TString inFileName, Int_t keyID);
  ~cpvbase();
  Int_t GetEntry(Long64_t entry);
  Long64_t LoadTree(Long64_t entry);
  void Init(TTree *tree);
  void Loop(TString histOut);
  Bool_t Notify();
  void Show(Long64_t entry = -1);
  Int_t Cut(Long64_t entry);

protected :
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain
  Int_t           fCurrent; //!current Tree number in a TChain
  
  // Declaration of leaf types
  Double_t x0;
  Double_t y0;
  Double_t z0;
  Double_t vx;
  Double_t vy;
  Double_t vz;
  Double_t theta;
  Double_t phi;
  Double_t x_int;
  Double_t y_int;
  Double_t z_int;
  Double_t xe0;
  Double_t ye0;
  Double_t ze0;
  Double_t distToEarth;
  Double_t distToTerzina;
  Double_t angleTrzinaTrk;

  //Int_t   evt;
  //Int_t   run;
  //Float_t pValue;
  //...
  //...
  //
  //---------------------------------------------------
  // ADD HERE :
  //Tree name
  //const TString treeName = "arich";
  const TString treeName = "T";
  static const Int_t nChannels = 1;
  
  //---------------------------------------------------
  
  // List of branches
  //TBranch *b_evt;
  //TBranch *b_run;
  //TBranch *b_pValue;
  //...
  //...
  //
  //---------------------------------------------------
  // ADD HERE :
  // List of branches
  TBranch *b_x0;
  TBranch *b_y0;
  TBranch *b_z0;
  TBranch *b_vx;
  TBranch *b_vy;
  TBranch *b_vz;
  TBranch *b_theta;
  TBranch *b_phi;
  TBranch *b_x_int;
  TBranch *b_y_int;
  TBranch *b_z_int;
  TBranch *b_xe0;
  TBranch *b_ye0;
  TBranch *b_ze0;
  TBranch *b_distToEarth;
  TBranch *b_distToTerzina;
  TBranch *b_angleTrzinaTrk;
  //---------------------------------------------------
  void tGraphInit(TGraph *gr[nChannels], TString grName, TString grTitle);
  void h1D1Init(TH1D *h1D1[nChannels],TString h1name, TString h1Title,
		Int_t Nbin, Float_t Vmin, Float_t Vmax);
  void h2D2Init(TH2D *h2D1[nChannels],TString h2name, TString h2Title,
                Int_t Nbin1, Float_t Vmin1, Float_t Vmax1,
                Int_t Nbin2, Float_t Vmin2, Float_t Vmax2);
  void tProfInit(TProfile *tprof[nChannels],TString prname, TString prTitle,
                 Int_t Nbin, Float_t Vmin, Float_t Vmax);
  double getUnixTimeFromTime(double d_year, double d_month, double d_day, double d_hour, double d_min, double d_sec);  
  //
  void h2D2div(TH2D *h2D1_norm,TH2D *h2D1);
  
};

#endif
