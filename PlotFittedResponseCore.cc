#include <TROOT.h>
#include <TSystem.h>
#include <TF1.h>
#include <TH1.h>
#include <TH2.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TStyle.h>
#include <TFile.h>
#include <TPostScript.h>
#include <TLegend.h>
#include <TMath.h>
#include <TArrayF.h>
#include <TLine.h>
#include <TPaveText.h>
#include <THStack.h>

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PlotFittedResponseCore(){

   gROOT->Reset();
   gROOT->SetStyle("Plain");
   gStyle->SetStatColor(0);
   gStyle->SetCanvasColor(0);
   gStyle->SetPadColor(0);
   gStyle->SetPadBorderMode(0);
   gStyle->SetCanvasBorderMode(0);
   gStyle->SetFrameBorderMode(0);
   gStyle->SetOptStat(0);
   gStyle->SetStatBorderSize(2);
   gStyle->SetOptTitle(1);
   gStyle->SetPadTickX(1);
   gStyle->SetPadTickY(1);
   gStyle->SetPadBorderSize(2);
   gStyle->SetPalette(51, 0);
   gStyle->SetPadBottomMargin(0.15);
   gStyle->SetPadTopMargin(0.15);
   gStyle->SetPadLeftMargin(0.15);
   gStyle->SetPadRightMargin(0.05);
   gStyle->SetTitleOffset(1.2, "X");
   gStyle->SetTitleOffset(1.6, "Y");
   gStyle->SetTitleOffset(1.0, "Z");
   gStyle->SetLabelSize(0.05, "X");
   gStyle->SetLabelSize(0.05, "Y");
   gStyle->SetLabelSize(0.05, "Z");
   gStyle->SetLabelOffset(0.02, "X");
   gStyle->SetLabelOffset(0.02, "Y");
   gStyle->SetLabelOffset(0.02, "Z");
   gStyle->SetTitleSize(0.05, "X");
   gStyle->SetTitleSize(0.05, "Y");
   gStyle->SetTitleSize(0.05, "Z");
   gStyle->SetTitleColor(1);
   gStyle->SetTitleFillColor(0);
   gStyle->SetTitleFontSize(0.05);
   gStyle->SetTitleY(0.99);
   gStyle->SetTitleX(0.15);
   gStyle->SetTitleBorderSize(0);
   gStyle->SetLineWidth(2);
   gStyle->SetHistLineWidth(2);
   gStyle->SetLegendBorderSize(0);
   gStyle->SetNdivisions(505, "X");
   gStyle->SetMarkerSize(0.8);
   gStyle->SetTickLength(0.03);
   gROOT->ForceStyle();
 
   vector<double> EtaBinEdges;
   EtaBinEdges.push_back(0.0);
   EtaBinEdges.push_back(0.3);
   EtaBinEdges.push_back(0.5);
   EtaBinEdges.push_back(0.8);
   EtaBinEdges.push_back(1.1);
   EtaBinEdges.push_back(1.4);
   EtaBinEdges.push_back(1.7);
   EtaBinEdges.push_back(2.0);
   EtaBinEdges.push_back(2.3);
   EtaBinEdges.push_back(2.8);
   EtaBinEdges.push_back(3.2);
   EtaBinEdges.push_back(4.1);
   EtaBinEdges.push_back(5.0);

   TFile *f1 = TFile::Open("/afs/naf.desy.de/user/k/kriheine/kriheine/QCDSmearing_MCClosure_8TeV_2012_DR53X_WithoutPUReweighting_chsJets_pt10_TuneZ2star_UseRebCorrection_v1/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/QCDSmearingClosure_OnMC_35.root");
   TFile *f2 = TFile::Open("/afs/naf.desy.de/user/k/kriheine/kriheine/QCDSmearing_MCClosure_8TeV_2012_WithoutPUReweighting_chsJets_pt13_madgraph_HT500-1000_v6/QCD_HT-500To1000_TuneZ2star_8TeV_madgraph_pythia6/QCDSmearingClosure_OnMC_31.root");
   //  TFile *f2 = TFile::Open("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_2_5/src/RA2Classic/QCDBkgRS/test/QCDSmearingClosure_OnMC.root");

   TCanvas* c = new TCanvas("c", "my Canvas", 500, 500);
   // TPad *p = new TPad("p", "p", 0, 0., 1, 1);
   //p->Draw();
   //p->cd();
 

   int rebin = 2;
   double rmin = 0.;
   double rmax = 2.;
   double ymin = 5;
  
   char dummy[1000];
   char dummy1[1000];
   char dummy2[1000];
 
   c->Print("ResponseCore.ps(");
 
   for (int iEta = 1; iEta < EtaBinEdges.size(); ++iEta) {

      sprintf(dummy1, "SigmaPtHist_total_Eta%i_Jet1", iEta - 1);
      cout << dummy1 << endl;

      sprintf(dummy2, "SigmaPt_total_Eta%i_Jet1", iEta - 1);
      cout << dummy2 << endl;

      TH1F* Res_1 = new TH1F();
      TH1F* Res_2 = new TH1F();
  
      Res_1 = (TH1F*) f1->FindObjectAny(dummy1);
      Res_2 = (TH1F*) f2->FindObjectAny(dummy1);
      //  Res_2 = (TH1F*) f2->FindObjectAny("SigmaPtHist_total_Eta8_Jet1");
    
      Res_1->SetLineColor(kBlue);
      Res_1->SetMarkerStyle(20);
      Res_1->SetMarkerColor(kBlue);
      TF1 *FitFunc = Res_1->GetFunction(dummy2);
      FitFunc->SetLineColor(kBlue);

      Res_2->SetLineStyle(2);
      Res_2->SetMarkerStyle(20);
      Res_2->SetMarkerColor(kRed);
      TF1 *FitFunc2 = Res_2->GetFunction(dummy2);
      // TF1 *FitFunc2 = Res_2->GetFunction("SigmaPt_total_Eta8_Jet1");
      FitFunc2->SetLineColor(kRed);
      Res_2->SetLineColor(kRed);

      Res_1->SetTitle("");
      Res_1->SetXTitle("p_{T} [GeV]");
      Res_1->SetYTitle("#sigma");

      Res_1->Draw("p");
      //  Res_2->Draw("psame");

      TLegend* leg = new TLegend(0.25, 0.70, 0.95, 0.83);
      leg->SetFillStyle(0);
      leg->SetLineStyle(1);
      leg->SetTextFont(42);
      leg->SetTextSize(0.045);
      leg->AddEntry(Res_1, "QCD flat pythia TuneZ2star ", "lp");
      // leg->AddEntry(Res_2, "madgraph", "lp");
      leg->Draw("same");

      TPaveText* pt = new TPaveText(0.11, 0.98, 0.95, 0.86, "NDC");
      pt->SetBorderSize(0);
      pt->SetFillStyle(0);
      pt->SetTextAlign(12);
      pt->SetTextSize(0.045);
      pt->AddText("CMS Simulation, #sqrt{s} = 8 TeV");
      sprintf(dummy, "%3.1f < |#eta| < %3.1f", EtaBinEdges.at(iEta - 1), EtaBinEdges.at(iEta));
      pt->AddText(dummy);
      pt->Draw("same");

      c->Print("ResponseCore.ps");
 
    //   if (iEta == 1)
//          c->Print("ResponseCore.pdf");

      //         if (iPt == 1 && iEta == 1) {
      //            c->Print("Response.ps(");
      //         } else if (iPt == 19 && iEta == 12) {
      //            c->Print("Response.ps)");
      //         } else {
      //            c->Print("Response.ps");
      //         }

      //  Res_1->Delete();
      //    Res_2->Delete();

   }

   c->Print("ResponseCore.ps)");

   //  return 0;
}
