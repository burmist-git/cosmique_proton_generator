#ifndef cpv_hh
#define cpv_hh

//My
#include "cpvbase.hh"

//root
#include <TROOT.h>
#include <TMath.h>

class TChain;
class TFile;
class TTree;
class TString;
class TBranch;

static const Double_t earthR = 6371;                           // km
static const Double_t earthD = earthR*2;                       // km
static const Double_t satelliteH = 525;                        // km
static const Double_t satelliteH_from_c = earthR + satelliteH; // km
static const Double_t track_speed = TMath::C()/1000;           // km/s

class cpv: public cpvbase {
public:
  cpv(TString fileList) : cpvbase(fileList)
  {
  }

  cpv(TString file, Int_t key) : cpvbase(file, key)
  {
  }

  void Loop(TString histOut);
  
};

#endif
