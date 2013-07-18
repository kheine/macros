#include <TROOT.h>
#include <TSystem.h>
#include <TH1.h>
#include <TH2.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <TColor.h>
#include <TChain.h>
#include <TPad.h>
#include <TStyle.h>
#include <TFile.h>
#include <TPostScript.h>
#include <TLegend.h>
#include <TMath.h>
#include <TString.h>
#include <TArrayF.h>
#include <TLine.h>
#include <TPaveText.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "/afs/naf.desy.de/user/k/kriheine/macros/PlottingUtils.C"

using namespace std;

void PlotPUUncertainty()
{
   gROOT->ProcessLine(".L PlottingUtils.C+");

   PlottingUtils::SetPlotStyle();

   // --- define output file for ps ---//
   TString outfile = "PUUncertaintyPlots/PUUncertaintyPlots.ps";

   // define input files
   TFile *PUUncertainty = TFile::Open("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/PUUncertainty_DR53X_MHT100.root");

   // open input file
   PUUncertainty->cd();

   TH1F* pile_up_histo_data_Njet2;
   gDirectory->GetObject("pile_up_histo_data_Njet2;1", pile_up_histo_data_Njet2);

   TH1F* pile_up_histo_data_Njet3_5;
   gDirectory->GetObject("pile_up_histo_data_Njet3_5;1", pile_up_histo_data_Njet3_5);

   TH1F* pile_up_histo_data_Njet6_7;
   gDirectory->GetObject("pile_up_histo_data_Njet6_7;1", pile_up_histo_data_Njet6_7);

   TH1F* pile_up_histo_data_Njet8;
   gDirectory->GetObject("pile_up_histo_data_Njet8;1", pile_up_histo_data_Njet8);

   TH1F* pile_up_histo_mc_Njet2;
   gDirectory->GetObject("pile_up_histo_mc_Njet2;1", pile_up_histo_mc_Njet2);

   TH1F* pile_up_histo_mc_Njet3_5;
   gDirectory->GetObject("pile_up_histo_mc_Njet3_5;1", pile_up_histo_mc_Njet3_5);

   TH1F* pile_up_histo_mc_Njet6_7;
   gDirectory->GetObject("pile_up_histo_mc_Njet6_7;1", pile_up_histo_mc_Njet6_7);

   TH1F* pile_up_histo_mc_Njet8;
   gDirectory->GetObject("pile_up_histo_mc_Njet8;1", pile_up_histo_mc_Njet8);

   // plot histos
   TString NJet_text = "N_{Jets} = 2";
   TCanvas *c = GetPlot(pile_up_histo_data_Njet2, pile_up_histo_mc_Njet2, NJet_text);

   c->Print(outfile + "[");
   c->Print("PUUncertaintyPlots/PUUncertainty_NJet2.png");
   c->Print(outfile);

   NJet_text = "3 #leq N_{Jets} #leq 5";
   c = GetPlot(pile_up_histo_data_Njet3_5, pile_up_histo_mc_Njet3_5, NJet_text);

   c->Print(outfile);
   c->Print("PUUncertaintyPlots/PUUncertainty_NJet3_5.png");

   NJet_text = "6 #leq N_{Jets} #leq 7";
   c = GetPlot(pile_up_histo_data_Njet6_7, pile_up_histo_mc_Njet6_7, NJet_text);

   c->Print(outfile);
   c->Print("PUUncertaintyPlots/PUUncertainty_NJet6_7.png");

   NJet_text = "N_{Jets} #geq 8";
   c = GetPlot(pile_up_histo_data_Njet8, pile_up_histo_mc_Njet8, NJet_text);

   c->Print(outfile);
   c->Print(outfile + "]");
   c->Print("PUUncertaintyPlots/PUUncertainty_NJet8.png");
}

TCanvas* GetPlot(TH1F *data_hist, TH1F* mc_hist, TString NJets)
{
   double MaxY = data_hist->GetMaximum();
   
   TCanvas *c = new TCanvas("c", "", 700, 700);
   c->SetLogy();

   data_hist->GetYaxis()->SetRangeUser(0.001, 2.2 * MaxY);
   data_hist->SetXTitle("N_{Vtx}");
   data_hist->SetYTitle("Prediction / # seed events ");
   data_hist->Draw();
   // mc_hist->SetMarkerColor(kRed);
   mc_hist->SetMarkerStyle(21);
   mc_hist->SetMarkerColor(kAzure-3);
   mc_hist->SetLineColor(kAzure-3);
   mc_hist->Draw("same");

   TLegend *leg = new TLegend(0.5, 0.3, 0.85, 0.42);
   leg->AddEntry( data_hist, "Data" , "lp");
   leg->AddEntry( mc_hist, "QCD madgraph" , "lp");
   leg->SetFillStyle(0);
   leg->SetLineStyle(1);
   leg->SetTextFont(42);
   leg->SetTextSize(0.035);

   leg->Draw("same");

   TPaveText* pt2 = new TPaveText(0.11, 0.855, 0.95, 0.935, "NDC");
   pt2->SetBorderSize(0);
   pt2->SetFillStyle(0);
   pt2->SetTextAlign(12);
   pt2->SetTextSize(0.03);
   pt2->AddText(NJets);
   pt2->AddText("CMS Preliminary, L = 19.5 fb^{  -1}, #sqrt{s} = 8 TeV");
   pt2->Draw();

   return c;
}
