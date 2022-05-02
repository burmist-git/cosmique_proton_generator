#ifndef merg_hh
#define merg_hh

//My
#include "mergbase.hh"

//root
#include <TROOT.h>

class TChain;
class TFile;
class TTree;
class TString;
class TBranch;


class merg: public mergbase {
public:
  merg(TString fileList) : mergbase(fileList)
  {
  }

  merg(TString file, Int_t key) : mergbase(file, key)
  {
  }

  void Loop(TString histOut);
  TString getTrkInfoFileName(Int_t eventIDmy);
  
};

#endif
