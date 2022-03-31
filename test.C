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

Int_t test(){
  //
  double binEdgess[] = { 0.0, 0.2, 0.5, 1., 2., 4.,6.0};
  TH1D* h1 = new TH1D("h1", "h1 title", 6, binEdgess);
  //
  TRandom3 *rnd = new TRandom3(12123);
  for(Int_t i = 0;i<10000;i++){
    h1->Fill(rnd->Uniform(0,4));
  }
  h1->Draw();
  return 0;
}
