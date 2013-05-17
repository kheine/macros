#include "/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/scripts/tdrstyle_mod.C"
#include <TROOT.h>
#include <TF1.h>
#include <TH1.h>
#include <TString.h>
#include <TFile.h>
#include <TGraphErrors.h>
#include <TCanvas.h>

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

void CalcSysUncJER()
{
   setTDRStyle();

   // ------------------------------------------------------------------ //
   // get files with nominal value and variations
   // nominal values
   TFile* file_nominal = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/JER_RatioVsEta_AfterPLICorr_TruncatedRMS.root", "READ");

   // pli down
   TFile* file_pliDOWN = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/JER_RatioVsEta_PLICorrDOWN_TruncatedRMS.root", "READ");

   // pli up
   TFile* file_pliUP = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/JER_RatioVsEta_PLICorrUP_TruncatedRMS.root", "READ");

   // extrapol up + down
   TFile* file_extrapol = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/JER_RatioVsEta_WithExtrapolUnc_TruncatedRMS.root", "READ");

   // PU reweighting
   TFile* file_pu = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/JER_RatioVsEta_AfterPLICorr_TruncatedRMS_MBXS73500.root", "READ");

   // ------------------------------------------------------------------ //
   // define histos needed for uncertainties
   TH1D *RatioNominal = new TH1D();
   TH1D *RatioPLIDown = new TH1D();
   TH1D *RatioPLIUp = new TH1D();
   TH1D *RatioExtrapolDown = new TH1D();
   TH1D *RatioExtrapolUp = new TH1D();
   TH1D *RatioPUUp = new TH1D();

   // ------------------------------------------------------------------ //
   // get histos from files
   file_nominal->cd();
   gDirectory->GetObject("RatioVsEta", RatioNominal);

   file_pliDOWN->cd();
   gDirectory->GetObject("RatioVsEta", RatioPLIDown);

   file_pliUP->cd();
   gDirectory->GetObject("RatioVsEta", RatioPLIUp);

   file_extrapol->cd();
   gDirectory->GetObject("RatioVsEtaDOWN", RatioExtrapolDown);
   gDirectory->GetObject("RatioVsEtaUP", RatioExtrapolUp);

   file_pu->cd();
   gDirectory->GetObject("RatioVsEta", RatioPUUp);

   // calc symmetric PU errors
   TH1D *RatioPUDown = new TH1D(*RatioPUUp);
   RatioPUDown->Reset();
   RatioPUDown->Add(RatioPUUp);
   RatioPUDown->Add(RatioNominal, -1);
   RatioPUDown->Scale(-1);
   RatioPUDown->Add(RatioNominal);

   // ------------------------------------------------------------------ //
   // remove hist errors for unc. variations
   for (int i = 1; i < RatioNominal->GetNbinsX()+1; i++) {
      RatioPLIDown->SetBinError(i, 0.0001);
      RatioPLIUp->SetBinError(i, 0.0001);
      RatioExtrapolDown->SetBinError(i, 0.0001);
      RatioExtrapolUp->SetBinError(i, 0.0001);
      RatioPUDown->SetBinError(i, 0.0001);
      RatioPUUp->SetBinError(i, 0.0001);
   }

   // ------------------------------------------------------------------ //
   // calc lower bounds
   double eta0_sysUncDown = TMath::Sqrt(pow(RatioNominal->GetBinContent(1) - 
                                            RatioPLIDown->GetBinContent(1),2) + 
                                        pow(RatioNominal->GetBinContent(1) - 
                                            RatioExtrapolDown->GetBinContent(1),2));
   double eta1_sysUncDown = TMath::Sqrt(pow(RatioNominal->GetBinContent(2) - 
                                            RatioPLIDown->GetBinContent(2),2) + 
                                        pow(RatioNominal->GetBinContent(2) - 
                                            RatioExtrapolDown->GetBinContent(2),2));
   double eta2_sysUncDown = TMath::Sqrt(pow(RatioNominal->GetBinContent(3) - 
                                            RatioPLIDown->GetBinContent(3),2) + 
                                        pow(RatioNominal->GetBinContent(3) - 
                                            RatioExtrapolDown->GetBinContent(3),2));
   double eta3_sysUncDown = TMath::Sqrt(pow(RatioNominal->GetBinContent(4) - 
                                            RatioPLIDown->GetBinContent(4),2) + 
                                        pow(RatioNominal->GetBinContent(4) - 
                                            RatioExtrapolDown->GetBinContent(4),2));
   double eta4_sysUncDown = TMath::Sqrt(pow(RatioNominal->GetBinContent(5) - 
                                            RatioPLIDown->GetBinContent(5),2) + 
                                        pow(RatioNominal->GetBinContent(5) - 
                                            RatioExtrapolDown->GetBinContent(5),2));

   // ------------------------------------------------------------------ //
   // calc upper bounds
   double eta0_sysUncUp = TMath::Sqrt(pow(RatioPLIUp->GetBinContent(1) - 
                                          RatioNominal->GetBinContent(1),2) + 
                                      pow(RatioExtrapolUp->GetBinContent(1) - 
                                          RatioNominal->GetBinContent(1),2));
   double eta1_sysUncUp = TMath::Sqrt(pow(RatioPLIUp->GetBinContent(2) - 
                                          RatioNominal->GetBinContent(2),2) + 
                                      pow(RatioExtrapolUp->GetBinContent(2) - 
                                          RatioNominal->GetBinContent(2),2));                                
   double eta2_sysUncUp = TMath::Sqrt(pow(RatioPLIUp->GetBinContent(3) - 
                                          RatioNominal->GetBinContent(3),2) + 
                                      pow(RatioExtrapolUp->GetBinContent(3) - 
                                          RatioNominal->GetBinContent(3),2));
   double eta3_sysUncUp = TMath::Sqrt(pow(RatioPLIUp->GetBinContent(4) - 
                                          RatioNominal->GetBinContent(4),2) + 
                                      pow(RatioExtrapolUp->GetBinContent(4) - 
                                          RatioNominal->GetBinContent(4),2));
   double eta4_sysUncUp = TMath::Sqrt(pow(RatioPLIUp->GetBinContent(5) - 
                                          RatioNominal->GetBinContent(5),2) + 
                                      pow(RatioExtrapolUp->GetBinContent(5) - 
                                          RatioNominal->GetBinContent(5),2));

   // ------------------------------------------------------------------ //
   // show values on screen with sys. uncertainty
   cout << "eta 0 sys.: " << RatioNominal->GetBinContent(1) << " + " << eta0_sysUncUp << " - " << eta0_sysUncDown << endl;
   cout << "eta 1 sys.: " << RatioNominal->GetBinContent(2) << " + " << eta1_sysUncUp << " - " << eta1_sysUncDown << endl;
   cout << "eta 2 sys.: " << RatioNominal->GetBinContent(3) << " + " << eta2_sysUncUp << " - " << eta2_sysUncDown << endl;
   cout << "eta 3 sys.: " << RatioNominal->GetBinContent(4) << " + " << eta3_sysUncUp << " - " << eta3_sysUncDown << endl;
   cout << "eta 4 sys.: " << RatioNominal->GetBinContent(5) << " + " << eta4_sysUncUp << " - " << eta4_sysUncDown << endl;

   // ------------------------------------------------------------------ //
   // calc total errors
   double eta0_TotalUncDown = TMath::Sqrt(pow(RatioNominal->GetBinError(1),2) + pow(eta0_sysUncDown,2));
   double eta1_TotalUncDown = TMath::Sqrt(pow(RatioNominal->GetBinError(2),2) + pow(eta1_sysUncDown,2));
   double eta2_TotalUncDown = TMath::Sqrt(pow(RatioNominal->GetBinError(3),2) + pow(eta2_sysUncDown,2));
   double eta3_TotalUncDown = TMath::Sqrt(pow(RatioNominal->GetBinError(4),2) + pow(eta3_sysUncDown,2));
   double eta4_TotalUncDown = TMath::Sqrt(pow(RatioNominal->GetBinError(5),2) + pow(eta4_sysUncDown,2));  

   double eta0_TotalUncUp = TMath::Sqrt(pow(RatioNominal->GetBinError(1),2) + pow(eta0_sysUncUp,2));
   double eta1_TotalUncUp = TMath::Sqrt(pow(RatioNominal->GetBinError(2),2) + pow(eta1_sysUncUp,2));
   double eta2_TotalUncUp = TMath::Sqrt(pow(RatioNominal->GetBinError(3),2) + pow(eta2_sysUncUp,2));
   double eta3_TotalUncUp = TMath::Sqrt(pow(RatioNominal->GetBinError(4),2) + pow(eta3_sysUncUp,2));
   double eta4_TotalUncUp = TMath::Sqrt(pow(RatioNominal->GetBinError(5),2) + pow(eta4_sysUncUp,2));  

   // ------------------------------------------------------------------ //
   // fill total uncertainties to TGraph
   TGraphAsymmErrors *Res_2012 = new TGraphAsymmErrors(RatioNominal);
   Res_2012->SetPointError(0, 0., 0., eta0_TotalUncDown, eta0_TotalUncUp);
   Res_2012->SetPointError(1, 0., 0., eta1_TotalUncDown, eta1_TotalUncUp);
   Res_2012->SetPointError(2, 0., 0., eta2_TotalUncDown, eta2_TotalUncUp);
   Res_2012->SetPointError(3, 0., 0., eta3_TotalUncDown, eta3_TotalUncUp);
   Res_2012->SetPointError(4, 0., 0., eta4_TotalUncDown, eta4_TotalUncUp);

   // ------------------------------------------------------------------ //
   // show values on screen with tot. uncertainty
   cout << " // ------------------------------------------------------------------ // " << endl;
   cout << "eta 0 tot.: " << RatioNominal->GetBinContent(1) << " + " << eta0_TotalUncUp << " - " << eta0_TotalUncDown << endl;
   cout << "eta 1 tot.: " << RatioNominal->GetBinContent(2) << " + " << eta1_TotalUncUp << " - " << eta1_TotalUncDown << endl;
   cout << "eta 2 tot.: " << RatioNominal->GetBinContent(3) << " + " << eta2_TotalUncUp << " - " << eta2_TotalUncDown << endl;
   cout << "eta 3 tot.: " << RatioNominal->GetBinContent(4) << " + " << eta3_TotalUncUp << " - " << eta3_TotalUncDown << endl;
   cout << "eta 4 tot.: " << RatioNominal->GetBinContent(5) << " + " << eta4_TotalUncUp << " - " << eta4_TotalUncDown << endl;

   // ------------------------------------------------------------------ //
   // plot nominal value + separate uncertainties 
   TCanvas *c = new TCanvas();
   RatioNominal->GetXaxis()->SetTitle("|#eta|");
   RatioNominal->GetYaxis()->SetTitle("Data/MC ratio (const fit)");
   RatioNominal->GetXaxis()->SetRangeUser(0., 5.);
   RatioNominal->GetYaxis()->SetRangeUser(0.8, 1.5);
   RatioNominal->SetMarkerSize(1.);
   RatioNominal->Draw();
   RatioPLIDown->SetMarkerSize(1.2);
   RatioPLIDown->SetMarkerStyle(22);
   RatioPLIDown->SetMarkerColor(kRed+1);
   RatioPLIDown->Draw("same");
   RatioPLIUp->SetMarkerSize(1.2);
   RatioPLIUp->SetMarkerStyle(22);
   RatioPLIUp->SetMarkerColor(kRed+1);
   RatioPLIUp->Draw("same");
   RatioExtrapolDown->SetMarkerSize(1.);
   RatioExtrapolDown->SetMarkerStyle(21);
   RatioExtrapolDown->SetMarkerColor(kSpring+4);
   RatioExtrapolDown->Draw("same");
   RatioExtrapolUp->SetMarkerSize(1.);
   RatioExtrapolUp->SetMarkerStyle(21);
   RatioExtrapolUp->SetMarkerColor(kSpring+4);
   RatioExtrapolUp->Draw("same");
   RatioPUDown->SetMarkerSize(1.);
   RatioPUDown->SetMarkerStyle(23);
   RatioPUDown->SetMarkerColor(kCyan+1);
   RatioPUDown->Draw("same");
   RatioPUUp->SetMarkerSize(1.);
   RatioPUUp->SetMarkerStyle(23);
   RatioPUUp->SetMarkerColor(kCyan+1);
   RatioPUUp->Draw("same");
   RatioNominal->Draw("same");

   TLegend *leg = new TLegend(0.44, 0.17, 0.74, 0.4);
   leg->SetBorderSize(0);
   // leg->SetBorderMode(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   leg->SetTextFont(42);
   leg->SetTextSize(0.035);

   leg->AddEntry(RatioNominal,"Nominal JER + stat. unc.", "pfl");
   leg->AddEntry(RatioPLIDown,"PLI", "P");
   leg->AddEntry(RatioExtrapolDown,"Extrapolation", "P");
   leg->AddEntry(RatioPUUp, "PU weighing", "P");
  
   leg->Draw("same");

   c->Print("JER_2012_uncertainties.eps");
   c->Print("JER_2012_uncertainties.png");


   // ------------------------------------------------------------------ //
   // plot nominal values with total unc.
   TH1D *dummy = new TH1D(*RatioNominal);
   dummy->Reset();

   TCanvas *c2 = new TCanvas();
   dummy->GetXaxis()->SetTitle("|#eta|");
   dummy->GetYaxis()->SetTitle("Data/MC ratio (const fit)");
   dummy->GetXaxis()->SetRangeUser(0., 5.);
   dummy->GetYaxis()->SetRangeUser(0.8, 1.5);
   dummy->Draw();
  
   Res_2012->SetMarkerStyle(20);
   Res_2012->SetMarkerSize(1.4);
   Res_2012->SetFillColor(kYellow-3);
   Res_2012->SetFillStyle(3001);
   Res_2012->SetLineColor(kYellow-3);
   Res_2012->DrawClone("e3Psame");

   Res_2012->SetPointError(0, 0., 0., 0., 0.);
   Res_2012->SetPointError(1, 0., 0., 0., 0.);
   Res_2012->SetPointError(2, 0., 0., 0., 0.);
   Res_2012->SetPointError(3, 0., 0., 0., 0.);
   Res_2012->SetPointError(4, 0., 0., 0., 0.);

   Res_2012->GetXaxis()->SetRangeUser(0., 5.);
   Res_2012->Draw("psame");

   cmsPrel();

   TLegend *leg2 = new TLegend(0.54, 0.27, 0.74, 0.35);
   leg2->SetBorderSize(0);
   // leg2->SetBorderMode(0);
   leg2->SetFillColor(0);
   leg2->SetFillStyle(0);
   leg2->SetTextFont(42);
   leg2->SetTextSize(0.035);

   leg2->AddEntry(Res_2012," JER 2012 (total error)", "pfl");
  
   leg2->Draw("same");

   c2->Print("JER_2012.eps");
   c2->Print("JER_2012.png");

   // ------------------------------------------------------------------ //
   // plot nominal values with total unc. + 2011 comparison
   TH1D *Res_2011Final = new TH1D(*RatioNominal);
   Res_2011Final->Reset();
   Res_2011Final->SetBinContent(1, 1.052);
   Res_2011Final->SetBinContent(2, 1.057);
   Res_2011Final->SetBinContent(3, 1.096);
   Res_2011Final->SetBinContent(4, 1.134);
   Res_2011Final->SetBinContent(5, 1.288);

   TGraphAsymmErrors *Res_2011 = new TGraphAsymmErrors(Res_2011Final);
   Res_2011->SetPointError(0, 0., 0., 0.063, 0.062);
   Res_2011->SetPointError(1, 0., 0., 0.057, 0.056);
   Res_2011->SetPointError(2, 0., 0., 0.065, 0.064);
   Res_2011->SetPointError(3, 0., 0., 0.094, 0.092);
   Res_2011->SetPointError(4, 0., 0., 0.200, 0.199);

   TCanvas *c3 = new TCanvas();
   dummy->GetXaxis()->SetTitle("|#eta|");
   dummy->GetYaxis()->SetTitle("Data/MC ratio (const fit)");
   dummy->GetXaxis()->SetRangeUser(0., 5.);
   dummy->GetYaxis()->SetRangeUser(0.8, 1.5);
   dummy->Draw();

   Res_2011->SetMarkerStyle(26);
   Res_2011->SetMarkerSize(1.4);
   Res_2011->SetFillColor(kGray);
   Res_2011->SetFillStyle(3001);
   Res_2011->SetLineColor(kGray);
   Res_2011->DrawClone("e3psame");

   Res_2012->SetPointError(0, 0., 0., eta0_TotalUncDown, eta0_TotalUncUp);
   Res_2012->SetPointError(1, 0., 0., eta1_TotalUncDown, eta1_TotalUncUp);
   Res_2012->SetPointError(2, 0., 0., eta2_TotalUncDown, eta2_TotalUncUp);
   Res_2012->SetPointError(3, 0., 0., eta3_TotalUncDown, eta3_TotalUncUp);
   Res_2012->SetPointError(4, 0., 0., eta4_TotalUncDown, eta4_TotalUncUp);
  
   Res_2012->SetMarkerStyle(20);
   Res_2012->SetMarkerSize(1.4);
   // Res_2012->SetFillColor(kYellow-3);
   Res_2012->SetFillColor(kOrange+8);
   Res_2012->SetFillStyle(3003);
   //Res_2012->SetLineColor(kYellow-3);
   Res_2012->SetLineColor(kOrange+8);
   Res_2012->DrawClone("e3Psame");

   cmsPrel();

   Res_2012->SetPointError(0, 0., 0., 0., 0.);
   Res_2012->SetPointError(1, 0., 0., 0., 0.);
   Res_2012->SetPointError(2, 0., 0., 0., 0.);
   Res_2012->SetPointError(3, 0., 0., 0., 0.);
   Res_2012->SetPointError(4, 0., 0., 0., 0.);

   Res_2012->GetXaxis()->SetRangeUser(0., 5.);
   Res_2012->Draw("psame");

   Res_2011->SetPointError(0, 0., 0., 0., 0.);
   Res_2011->SetPointError(1, 0., 0., 0., 0.);
   Res_2011->SetPointError(2, 0., 0., 0., 0.);
   Res_2011->SetPointError(3, 0., 0., 0., 0.);
   Res_2011->SetPointError(4, 0., 0., 0., 0.);

   Res_2011->Draw("psame");

   TLegend *leg2 = new TLegend(0.54, 0.17, 0.74, 0.35);
   leg2->SetBorderSize(0);
   // leg2->SetBorderMode(0);
   leg2->SetFillColor(0);
   leg2->SetFillStyle(0);
   leg2->SetTextFont(42);
   leg2->SetTextSize(0.035);

   leg2->AddEntry(Res_2012," JER 2012 (total error)", "pfl");
   leg2->AddEntry(Res_2011," JER 2011 (total error)", "pfl");
  
   leg2->Draw("same");

   c3->Print("JER_2012_comp2011.eps");
   c3->Print("JER_2012_comp2011.png");


}
