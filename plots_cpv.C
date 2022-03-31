Int_t plots_cpv(){
  
  TString fileN;
  TString objectName;
  fileN = "./hist.root";
  TFile *f1 = new TFile(fileN.Data());

  TGraph2D *gr2D_sphere = (TGraph2D*)f1->Get("gr2D_sphere");
  TGraph2D *gr2D_pint = (TGraph2D*)f1->Get("gr2D_pint");
  TGraph2D *gr2D_p0 = (TGraph2D*)f1->Get("gr2D_p0");
  TGraph2D *gr2D_pe0 = (TGraph2D*)f1->Get("gr2D_pe0");

  TCanvas *c1 = new TCanvas("c1","c1",10,10,800,800);
  gr2D_sphere->SetMarkerColor(kBlack);
  gr2D_sphere->SetMarkerStyle(7);
  gr2D_pint->SetMarkerColor(kRed);
  gr2D_pint->SetMarkerStyle(7);
  gr2D_p0->SetMarkerColor(kBlue);
  gr2D_p0->SetMarkerStyle(4);
  gr2D_pe0->SetMarkerColor(kMagenta);
  gr2D_pe0->SetMarkerStyle(7);

  gr2D_sphere->SetTitle("");
  gr2D_sphere->Draw("P");
  gr2D_pint->Draw("sameP");
  gr2D_p0->Draw("sameP");
  gr2D_pe0->Draw("sameP");
  //gr2D_p0->SetTitle("");
  //gr2D_p0->Draw("P");
  //gr2D_pint->Draw("sameP");

  gr2D_sphere->GetXaxis()->SetTitle("x");
  gr2D_sphere->GetYaxis()->SetTitle("y");
  gr2D_sphere->GetZaxis()->SetTitle("z");

  return 0;
}
