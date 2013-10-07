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

void PlotJERClosure()
{
   setTDRStyle();

   // truncated RMS
   TFile* file_TruncatedRMS = new TFile("/afs/naf.desy.de/user/k/kriheine/macros/JER_RatioVsEta_AfterPLICorr_TruncatedRMS_InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation_ComparedToGaussFit_RatioClosure.root", "READ");

   //TFile* file_TruncatedRMS = new TFile("JER_RatioVsEta_AfterPLICorr_TruncatedRMS_TruncatedGenAsymm_ClosureTest.root", "READ");

   // GaussFit
   // TFile* file_GaussFit = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/JER_RatioVsEta_AfterPLICorr_GaussFitWidth_ClosureTest.root", "READ");

   // StandardDeviation
   TFile* file_StandardDeviation = new TFile("/afs/naf.desy.de/user/k/kriheine/macros/JER_RatioVsEta_AfterPLICorr_StandardDeviation_InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation_ComparedToGaussFit_RatioClosure.root", "READ");

   TH1D *RatioTruncatedRMS = new TH1D();
   //  TH1D *RatioGaussFit = new TH1D();
   TH1D *RatioStandardDeviation = new TH1D();

   // get histos from files
   file_TruncatedRMS->cd();
   gDirectory->GetObject("RatioVsEta", RatioTruncatedRMS);

   // file_GaussFit->cd();
   // gDirectory->GetObject("RatioVsEta", RatioGaussFit);

   file_StandardDeviation->cd();
   gDirectory->GetObject("RatioVsEta", RatioStandardDeviation);

   TH1D *RatioNominal = new TH1D(*RatioTruncatedRMS);
   RatioNominal->Reset();
   RatioNominal->SetBinContent(1, 1.052);
   RatioNominal->SetBinContent(2, 1.057);
   RatioNominal->SetBinContent(3, 1.096);
   RatioNominal->SetBinContent(4, 1.134);
   RatioNominal->SetBinContent(5, 1.288);
   RatioNominal->SetBinError(1, 0.0000000001);
   RatioNominal->SetBinError(2, 0.0000000001);
   RatioNominal->SetBinError(3, 0.0000000001);
   RatioNominal->SetBinError(4, 0.0000000001);
   RatioNominal->SetBinError(5, 0.0000000001);

   TCanvas *c = new TCanvas();
   RatioNominal->GetXaxis()->SetTitle("|#eta|");
   RatioNominal->GetYaxis()->SetRangeUser(1.0, 1.35);
   RatioNominal->GetYaxis()->SetTitle("MC_{smeared} /MC ratio (const fit)");
   RatioNominal->Draw();
   RatioTruncatedRMS->SetMarkerColor(kRed);
   RatioTruncatedRMS->Draw("same");
   //RatioGaussFit->SetMarkerColor(kBlue);
   //RatioGaussFit->Draw("same");
   RatioStandardDeviation->SetMarkerColor(kGreen);
   RatioStandardDeviation->Draw("same");

   TLegend *leg2 = new TLegend(0.19, 0.67, 0.39, 0.91);
   leg2->SetBorderSize(0);
   // leg2->SetBorderMode(0);
   leg2->SetFillColor(0);
   leg2->SetFillStyle(0);
   leg2->SetTextFont(42);
   leg2->SetTextSize(0.04);

   leg2->AddEntry(RatioNominal,"Input values", "pfl");
   leg2->AddEntry(RatioTruncatedRMS,"Truncated RMS 98.5%", "pfl");
   // leg2->AddEntry(RatioGaussFit,"Gauss Fit", "pfl");
   leg2->AddEntry(RatioStandardDeviation,"Standard Deviation", "pfl");

   leg2->Draw("same");

   //cmsPrel(-1, false , 8);

   c->Print("JERPlots/RatioClosureJER_InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation.png");
   c->Print("JERPlots/RatioClosureJER_InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation.eps");

}
