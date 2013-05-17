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

#include "../scratch/CMSSW_5_2_5/src/RA2Classic/AdditionalInputFiles/RA2PlottingStyle.h"

using namespace std;

void GetControlPlotsQCD_RS()
{
   // RA2PlottingStyle::init();

 gROOT->Reset();
   gROOT->SetStyle("Plain");
   //gStyle->SetPalette(51, 0);

   //  gStyle->SetHatchesLineWidth(1.2);

   // For the canvas:
   gStyle->SetCanvasColor(0);
   //gStyle->SetCanvasBorderMode(0);

   // For the Pad:
   gStyle->SetPadColor(0);  
   gStyle->SetPadTickX(1);
   gStyle->SetPadTickY(1);
   gStyle->SetPadBorderSize(2);
   //gStyle->SetPadBorderMode(0);
  
   // For the frame:
   gStyle->SetFrameBorderMode(0);

   // For the histo:
   // gStyle->SetMarkerSize(0.7);
   // gStyle->SetMarkerStyle(20);
   // gStyle->SetMarkerColor(1);
  
   // For the statistics box:
   gStyle->SetOptStat(0);
   //gStyle->SetOptFit(1011);
  
   // Margins:
   gStyle->SetPadBottomMargin(0.25);
   gStyle->SetPadTopMargin(0.15);
   gStyle->SetPadLeftMargin(0.15);
   gStyle->SetPadRightMargin(0.1);
      
   // For the Global title:
   gStyle->SetOptTitle(0);
   gStyle->SetTitleColor(1);
   gStyle->SetTitleFillColor(10);
   gStyle->SetTitleTextColor(1); 
   gStyle->SetTitleFont(42);
   gStyle->SetTitleFontSize(0.05);
   gStyle->SetTitleBorderSize(0);

   // For the axis
   gStyle->SetNdivisions(510, "X");
   gStyle->SetNdivisions(510, "Y");
   gStyle->SetTickLength(0.03);

   // For the axis titles:
   gStyle->SetTitleOffset(1.4, "X");
   // gStyle->SetTitleOffset(1.25, "Y");
   gStyle->SetTitleOffset(1.2, "Y");
   gStyle->SetTitleOffset(0.5, "Z");
   //gStyle->SetTitleSize(0.05, "XYZ");
   gStyle->SetTitleSize(0.061, "XYZ");
   gStyle->SetTitleFont(42, "XYZ");
   //gStyle->SetTitleX(0.15);
   //gStyle->SetTitleY(0.99);

   // For the axis labels:
   gStyle->SetLabelSize(0.04, "XYZ");
   gStyle->SetLabelOffset(0.01, "XYZ");
   gStyle->SetLabelFont(42, "XYZ");

   // For the legend
   gStyle->SetLegendBorderSize(0);
  
   gROOT->ForceStyle();

//    gStyle->SetMarkerStyle(20);
//    gStyle->SetNdivisions(508, "X");
    
//    gROOT->ForceStyle();

   // --- define output file for ps ---//
   TString pt = "pt10";
   //TString outfile = "ControlPlotsQCD_RS/ControlPlots_pythia_DR53X_chsJets_TuneZ2star_" + pt + "_DoNotUseRebCorrection";
   //TString outfile = "ControlPlotsQCD_RS/ControlPlots_pythia_DR53X_chsJets_TuneZ2star_" + pt + "_UseRebCorrection";

   //TString outfile = "ControlPlotsQCD_RS/ControlPlots_madgraph_DR53X_chsJets_TuneZ2star_" + pt + "_DoNotUseRebCorrection";
   TString outfile = "ControlPlotsQCD_RS/ControlPlots_madgraph_DR53X_chsJets_TuneZ2star_" + pt + "_UseRebCorrection";
         
   TH1F* NJets_gen = new TH1F("NJets_gen", "NJets", 15, 0., 15);
   NJets_gen->Sumw2();
   TH1F* NJets_reco = new TH1F("NJets_reco", "NJets", 15, 0., 15);
   NJets_reco->Sumw2();
   TH1F* NJets_reb = new TH1F("NJets_reb", "NJets", 15, 0., 15);
   NJets_reb->Sumw2();
   TH1F* NJets_smear = new TH1F("NJets_smear", "NJets", 15, 0., 15);
   NJets_smear->Sumw2();
   TH1F* JetPt_gen = new TH1F("JetPt_gen", "Jet pt", 1000, 0., 1000.);
   JetPt_gen->Sumw2();
   TH1F* JetPt_reco = new TH1F("JetPt_reco", "Jet pt", 1000, 0., 1000.);
   JetPt_reco->Sumw2();
   TH1F* JetPt_reb = new TH1F("JetPt_reb", "Jet pt", 1000, 0., 1000.);
   JetPt_reb->Sumw2();
   TH1F* JetPt_smear = new TH1F("JetPt_smear", "Jet pt", 1000, 0., 1000.);
   JetPt_smear->Sumw2();
   TH1F* HT_gen = new TH1F("HT_gen", "HT_gen", 100., 0., 5000.);
   HT_gen->Sumw2();
   TH1F* HT_reco = new TH1F("HT_reco", "HT_reco", 100., 0., 5000.);
   HT_reco->Sumw2();
   TH1F* HT_reb = new TH1F("HT_reb", "HT_reb", 100., 0., 5000.);
   HT_reb->Sumw2();
   TH1F* HT_smear = new TH1F("HT_smear", "HT_smear", 100., 0., 5000.);
   HT_smear->Sumw2();
   TH1F* HT_JetBin1_gen = new TH1F("HT_JetBin1_gen", "HT_JetBin1_gen", 100., 0., 5000.);
   HT_JetBin1_gen->Sumw2();
   TH1F* HT_JetBin1_reco = new TH1F("HT_JetBin1_reco", "HT_JetBin1_reco", 100., 0., 5000.);
   HT_JetBin1_reco->Sumw2();
   TH1F* HT_JetBin1_reb = new TH1F("HT_JetBin1_reb", "HT_JetBin1_reb", 100., 0., 5000.);
   HT_JetBin1_reb->Sumw2();
   TH1F* HT_JetBin1_smear = new TH1F("HT_JetBin1_smear", "HT_JetBin1_smear", 100., 0., 5000.);
   HT_JetBin1_smear->Sumw2();
   TH1F* HT_JetBin2_gen = new TH1F("HT_JetBin2_gen", "HT_JetBin2_gen", 100., 0., 5000.);
   HT_JetBin2_gen->Sumw2();
   TH1F* HT_JetBin2_reco = new TH1F("HT_JetBin2_reco", "HT_JetBin2_reco", 100., 0., 5000.);
   HT_JetBin2_reco->Sumw2();
   TH1F* HT_JetBin2_reb = new TH1F("HT_JetBin2_reb", "HT_JetBin2_reb", 100., 0., 5000.);
   HT_JetBin2_reb->Sumw2();
   TH1F* HT_JetBin2_smear = new TH1F("HT_JetBin2_smear", "HT_JetBin2_smear", 100., 0., 5000.);
   HT_JetBin2_smear->Sumw2();
   TH1F* HT_JetBin3_gen = new TH1F("HT_JetBin3_gen", "HT_JetBin3_gen", 100., 0., 5000.);
   HT_JetBin3_gen->Sumw2();
   TH1F* HT_JetBin3_reco = new TH1F("HT_JetBin3_reco", "HT_JetBin3_reco", 100., 0., 5000.);
   HT_JetBin3_reco->Sumw2();
   TH1F* HT_JetBin3_reb = new TH1F("HT_JetBin3_reb", "HT_JetBin3_reb", 100., 0., 5000.);
   HT_JetBin3_reb->Sumw2();
   TH1F* HT_JetBin3_smear = new TH1F("HT_JetBin3_smear", "HT_JetBin3_smear", 100., 0., 5000.);
   HT_JetBin3_smear->Sumw2();
   TH1F* HT_JetBin4_gen = new TH1F("HT_JetBin4_gen", "HT_JetBin4_gen", 100., 0., 5000.);
   HT_JetBin4_gen->Sumw2();
   TH1F* HT_JetBin4_reco = new TH1F("HT_JetBin4_reco", "HT_JetBin4_reco", 100., 0., 5000.);
   HT_JetBin4_reco->Sumw2();
   TH1F* HT_JetBin4_reb = new TH1F("HT_JetBin4_reb", "HT_JetBin4_reb", 100., 0., 5000.);
   HT_JetBin4_reb->Sumw2();
   TH1F* HT_JetBin4_smear = new TH1F("HT_JetBin4_smear", "HT_JetBin4_smear", 100., 0., 5000.);
   HT_JetBin4_smear->Sumw2();
   TH1F* deltaPhiJet1Jet2_gen = new TH1F("deltaPhiJet1Jet2_gen", "deltaPhiJet1Jet2_gen", 50, 0, TMath::Pi());
   deltaPhiJet1Jet2_gen->Sumw2();
   TH1F* deltaPhiJet1Jet2_rec = new TH1F("deltaPhiJet1Jet2_rec", "deltaPhiJet1Jet2_rec", 50, 0, TMath::Pi());
   deltaPhiJet1Jet2_rec->Sumw2();
   TH1F* deltaPhiJet1Jet2_smeared = new TH1F("deltaPhiJet1Jet2_smeared", "deltaPhiJet1Jet2_smeared", 50, 0, TMath::Pi());
   deltaPhiJet1Jet2_smeared->Sumw2();
   TH1F* deltaPhiJet1Jet2_reb = new TH1F("deltaPhiJet1Jet2_reb", "deltaPhiJet1Jet2_reb", 50, 0, TMath::Pi());
   deltaPhiJet1Jet2_reb->Sumw2();
   TH1F* MHTall_gen = new TH1F("MHTall_gen", "MHTall_gen", 150., 0., 1500.);
   MHTall_gen->Sumw2();
   TH1F* MHTall_reco = new TH1F("MHTall_reco", "MHTall_reco", 150., 0., 1500.);
   MHTall_reco->Sumw2();
   TH1F* MHTall_reb = new TH1F("MHTall_reb", "MHTall_reb", 150., 0., 1500.);
   MHTall_reb->Sumw2();
   TH1F* MHTall_smear = new TH1F("MHTall_smear", "MHTall_smear", 150., 0., 1500.);
   MHTall_smear->Sumw2();

   string root_file;
   // open files for MC --- madgraph QCD ---- //
   ifstream myfile1 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_madgraph_DR53X_chs_pt10_withoutPUReweighting_HT100-250_UseRebCorrection_v1_mc.txt");
   //ifstream myfile1 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_madgraph_DR53X_chs_pt10_withoutPUReweighting_HT100-250_DoNotUseRebCorrection_v1_mc.txt");
   if (myfile1.is_open()) {
      while( myfile1.good() ) {
         getline (myfile1,root_file);
         cout << root_file << endl;

         TH1F* NJets_gen_temp;
         TH1F* NJets_reco_temp;
         TH1F* NJets_reb_temp;
         TH1F* NJets_smear_temp;
         TH1F* JetPt_gen_temp;
         TH1F* JetPt_reco_temp;
         TH1F* JetPt_reb_temp;
         TH1F* JetPt_smear_temp;
         TH1F* HT_JetBin1_gen_temp;
         TH1F* HT_JetBin1_reco_temp;
         TH1F* HT_JetBin1_reb_temp;
         TH1F* HT_JetBin1_smear_temp;
         TH1F* HT_JetBin2_gen_temp;
         TH1F* HT_JetBin2_reco_temp;
         TH1F* HT_JetBin2_reb_temp;
         TH1F* HT_JetBin2_smear_temp;
         TH1F* HT_JetBin3_gen_temp;
         TH1F* HT_JetBin3_reco_temp;
         TH1F* HT_JetBin3_reb_temp;
         TH1F* HT_JetBin3_smear_temp;
         TH1F* HT_JetBin4_gen_temp;
         TH1F* HT_JetBin4_reco_temp;
         TH1F* HT_JetBin4_reb_temp;
         TH1F* HT_JetBin4_smear_temp;
         TH1F* deltaPhiJet1Jet2_gen_temp;
         TH1F* deltaPhiJet1Jet2_rec_temp; 
         TH1F* deltaPhiJet1Jet2_smeared_temp;
         TH1F* deltaPhiJet1Jet2_reb_temp;
         TH1F* HTall_gen_temp;
         TH1F* HTall_reco_temp;
         TH1F* HTall_reb_temp;
         TH1F* HTall_smear_temp;
         TH1F* MHTall_gen_temp;
         TH1F* MHTall_reco_temp;
         TH1F* MHTall_reb_temp;
         TH1F* MHTall_smear_temp;
         
         TString path = root_file;

         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("NJets_gen;1", NJets_gen_temp);
         NJets_gen->Add(NJets_gen_temp);

         gDirectory->GetObject("NJets_reco;1", NJets_reco_temp);
         NJets_reco->Add(NJets_reco_temp);
    
         gDirectory->GetObject("NJets_reb;1", NJets_reb_temp); 
         NJets_reb->Add(NJets_reb_temp);
    
         gDirectory->GetObject("NJets_smear;1", NJets_smear_temp); 
         NJets_smear->Add(NJets_smear_temp);
        
         gDirectory->GetObject("JetPt_gen;1", JetPt_gen_temp); 
         JetPt_gen->Add(JetPt_gen_temp);

         gDirectory->GetObject("JetPt_reco;1", JetPt_reco_temp); 
         JetPt_reco->Add(JetPt_reco_temp);

         gDirectory->GetObject("JetPt_reb;1", JetPt_reb_temp); 
         JetPt_reb->Add(JetPt_reb_temp);
    
         gDirectory->GetObject("JetPt_smear;1", JetPt_smear_temp);
         JetPt_smear->Add(JetPt_smear_temp);

         gDirectory->GetObject("HT_gen;1", HTall_gen_temp); 
         HT_gen->Add(HTall_gen_temp);

         gDirectory->GetObject("HT_rec;1", HTall_reco_temp); 
         HT_reco->Add(HTall_reco_temp);

         gDirectory->GetObject("HT_reb;1", HTall_reb_temp); 
         HT_reb->Add(HTall_reb_temp);

         gDirectory->GetObject("HT_smeared;1", HTall_smear_temp); 
         HT_smear->Add(HTall_smear_temp);

         gDirectory->GetObject("HT_JetBin1_gen;1", HT_JetBin1_gen_temp); 
         HT_JetBin1_gen->Add(HT_JetBin1_gen_temp);

         gDirectory->GetObject("HT_JetBin1_rec;1", HT_JetBin1_reco_temp); 
         HT_JetBin1_reco->Add(HT_JetBin1_reco_temp);

         gDirectory->GetObject("HT_JetBin1_reb;1", HT_JetBin1_reb_temp); 
         HT_JetBin1_reb->Add(HT_JetBin1_reb_temp);

         gDirectory->GetObject("HT_JetBin1_smeared;1", HT_JetBin1_smear_temp); 
         HT_JetBin1_smear->Add(HT_JetBin1_smear_temp);

         gDirectory->GetObject("HT_JetBin2_gen;1", HT_JetBin2_gen_temp); 
         HT_JetBin2_gen->Add(HT_JetBin2_gen_temp);

         gDirectory->GetObject("HT_JetBin2_rec;1", HT_JetBin2_reco_temp); 
         HT_JetBin2_reco->Add(HT_JetBin2_reco_temp);

         gDirectory->GetObject("HT_JetBin2_reb;1", HT_JetBin2_reb_temp); 
         HT_JetBin2_reb->Add(HT_JetBin2_reb_temp);

         gDirectory->GetObject("HT_JetBin2_smeared;1", HT_JetBin2_smear_temp); 
         HT_JetBin2_smear->Add(HT_JetBin2_smear_temp);

         gDirectory->GetObject("HT_JetBin3_gen;1", HT_JetBin3_gen_temp); 
         HT_JetBin3_gen->Add(HT_JetBin3_gen_temp);

         gDirectory->GetObject("HT_JetBin3_rec;1", HT_JetBin3_reco_temp); 
         HT_JetBin3_reco->Add(HT_JetBin3_reco_temp);

         gDirectory->GetObject("HT_JetBin3_reb;1", HT_JetBin3_reb_temp); 
         HT_JetBin3_reb->Add(HT_JetBin3_reb_temp);

         gDirectory->GetObject("HT_JetBin3_smeared;1", HT_JetBin3_smear_temp); 
         HT_JetBin3_smear->Add(HT_JetBin3_smear_temp);

         gDirectory->GetObject("HT_JetBin4_gen;1", HT_JetBin4_gen_temp); 
         HT_JetBin4_gen->Add(HT_JetBin4_gen_temp);

         gDirectory->GetObject("HT_JetBin4_rec;1", HT_JetBin4_reco_temp); 
         HT_JetBin4_reco->Add(HT_JetBin4_reco_temp);

         gDirectory->GetObject("HT_JetBin4_reb;1", HT_JetBin4_reb_temp); 
         HT_JetBin4_reb->Add(HT_JetBin4_reb_temp);

         gDirectory->GetObject("HT_JetBin4_smeared;1", HT_JetBin4_smear_temp); 
         HT_JetBin4_smear->Add(HT_JetBin4_smear_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_gen;1", deltaPhiJet1Jet2_gen_temp); 
         deltaPhiJet1Jet2_gen->Add(deltaPhiJet1Jet2_gen_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_rec;1", deltaPhiJet1Jet2_rec_temp); 
         deltaPhiJet1Jet2_rec->Add(deltaPhiJet1Jet2_rec_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_smeared;1", deltaPhiJet1Jet2_smeared_temp); 
         deltaPhiJet1Jet2_smeared->Add(deltaPhiJet1Jet2_smeared_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_reb;1", deltaPhiJet1Jet2_reb_temp); 
         deltaPhiJet1Jet2_reb->Add(deltaPhiJet1Jet2_reb_temp);

         gDirectory->GetObject("MHTall_gen;1", MHTall_gen_temp); 
         MHTall_gen->Add(MHTall_gen_temp);

         gDirectory->GetObject("MHTall_rec;1", MHTall_reco_temp); 
         MHTall_reco->Add(MHTall_reco_temp);

         gDirectory->GetObject("MHTall_reb;1", MHTall_reb_temp); 
         MHTall_reb->Add(MHTall_reb_temp);

         gDirectory->GetObject("MHTall_smeared;1", MHTall_smear_temp); 
         MHTall_smear->Add(MHTall_smear_temp);

         input_file->Close();

      }
      myfile1.close();
   }

   ifstream myfile2 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_madgraph_DR53X_chs_pt10_withoutPUReweighting_HT250-500_UseRebCorrection_v1_mc.txt");
   //ifstream myfile2 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_madgraph_DR53X_chs_pt10_withoutPUReweighting_HT250-500_DoNotUseRebCorrection_v1_mc.txt");
   if (myfile2.is_open()) {
      while( myfile2.good() ) {
         getline (myfile2,root_file);
         cout << root_file << endl;

         TH1F* NJets_gen_temp;
         TH1F* NJets_reco_temp;
         TH1F* NJets_reb_temp;
         TH1F* NJets_smear_temp;
         TH1F* JetPt_gen_temp;
         TH1F* JetPt_reco_temp;
         TH1F* JetPt_reb_temp;
         TH1F* JetPt_smear_temp;
         TH1F* HT_JetBin1_gen_temp;
         TH1F* HT_JetBin1_reco_temp;
         TH1F* HT_JetBin1_reb_temp;
         TH1F* HT_JetBin1_smear_temp;
         TH1F* HT_JetBin2_gen_temp;
         TH1F* HT_JetBin2_reco_temp;
         TH1F* HT_JetBin2_reb_temp;
         TH1F* HT_JetBin2_smear_temp;
         TH1F* HT_JetBin3_gen_temp;
         TH1F* HT_JetBin3_reco_temp;
         TH1F* HT_JetBin3_reb_temp;
         TH1F* HT_JetBin3_smear_temp;
         TH1F* HT_JetBin4_gen_temp;
         TH1F* HT_JetBin4_reco_temp;
         TH1F* HT_JetBin4_reb_temp;
         TH1F* HT_JetBin4_smear_temp;
         TH1F* deltaPhiJet1Jet2_gen_temp;
         TH1F* deltaPhiJet1Jet2_rec_temp; 
         TH1F* deltaPhiJet1Jet2_smeared_temp;
         TH1F* deltaPhiJet1Jet2_reb_temp;
         TH1F* HTall_gen_temp;
         TH1F* HTall_reco_temp;
         TH1F* HTall_reb_temp;
         TH1F* HTall_smear_temp;
         TH1F* MHTall_gen_temp;
         TH1F* MHTall_reco_temp;
         TH1F* MHTall_reb_temp;
         TH1F* MHTall_smear_temp;
         
         TString path = root_file;

         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("NJets_gen;1", NJets_gen_temp);
         NJets_gen->Add(NJets_gen_temp);

         gDirectory->GetObject("NJets_reco;1", NJets_reco_temp);
         NJets_reco->Add(NJets_reco_temp);
    
         gDirectory->GetObject("NJets_reb;1", NJets_reb_temp); 
         NJets_reb->Add(NJets_reb_temp);
    
         gDirectory->GetObject("NJets_smear;1", NJets_smear_temp); 
         NJets_smear->Add(NJets_smear_temp);
        
         gDirectory->GetObject("JetPt_gen;1", JetPt_gen_temp); 
         JetPt_gen->Add(JetPt_gen_temp);

         gDirectory->GetObject("JetPt_reco;1", JetPt_reco_temp); 
         JetPt_reco->Add(JetPt_reco_temp);

         gDirectory->GetObject("JetPt_reb;1", JetPt_reb_temp); 
         JetPt_reb->Add(JetPt_reb_temp);
    
         gDirectory->GetObject("JetPt_smear;1", JetPt_smear_temp);
         JetPt_smear->Add(JetPt_smear_temp);

         gDirectory->GetObject("HT_gen;1", HTall_gen_temp); 
         HT_gen->Add(HTall_gen_temp);

         gDirectory->GetObject("HT_rec;1", HTall_reco_temp); 
         HT_reco->Add(HTall_reco_temp);

         gDirectory->GetObject("HT_reb;1", HTall_reb_temp); 
         HT_reb->Add(HTall_reb_temp);

         gDirectory->GetObject("HT_smeared;1", HTall_smear_temp); 
         HT_smear->Add(HTall_smear_temp);

         gDirectory->GetObject("HT_JetBin1_gen;1", HT_JetBin1_gen_temp); 
         HT_JetBin1_gen->Add(HT_JetBin1_gen_temp);

         gDirectory->GetObject("HT_JetBin1_rec;1", HT_JetBin1_reco_temp); 
         HT_JetBin1_reco->Add(HT_JetBin1_reco_temp);

         gDirectory->GetObject("HT_JetBin1_reb;1", HT_JetBin1_reb_temp); 
         HT_JetBin1_reb->Add(HT_JetBin1_reb_temp);

         gDirectory->GetObject("HT_JetBin1_smeared;1", HT_JetBin1_smear_temp); 
         HT_JetBin1_smear->Add(HT_JetBin1_smear_temp);

         gDirectory->GetObject("HT_JetBin2_gen;1", HT_JetBin2_gen_temp); 
         HT_JetBin2_gen->Add(HT_JetBin2_gen_temp);

         gDirectory->GetObject("HT_JetBin2_rec;1", HT_JetBin2_reco_temp); 
         HT_JetBin2_reco->Add(HT_JetBin2_reco_temp);

         gDirectory->GetObject("HT_JetBin2_reb;1", HT_JetBin2_reb_temp); 
         HT_JetBin2_reb->Add(HT_JetBin2_reb_temp);

         gDirectory->GetObject("HT_JetBin2_smeared;1", HT_JetBin2_smear_temp); 
         HT_JetBin2_smear->Add(HT_JetBin2_smear_temp);

         gDirectory->GetObject("HT_JetBin3_gen;1", HT_JetBin3_gen_temp); 
         HT_JetBin3_gen->Add(HT_JetBin3_gen_temp);

         gDirectory->GetObject("HT_JetBin3_rec;1", HT_JetBin3_reco_temp); 
         HT_JetBin3_reco->Add(HT_JetBin3_reco_temp);

         gDirectory->GetObject("HT_JetBin3_reb;1", HT_JetBin3_reb_temp); 
         HT_JetBin3_reb->Add(HT_JetBin3_reb_temp);

         gDirectory->GetObject("HT_JetBin3_smeared;1", HT_JetBin3_smear_temp); 
         HT_JetBin3_smear->Add(HT_JetBin3_smear_temp);

         gDirectory->GetObject("HT_JetBin4_gen;1", HT_JetBin4_gen_temp); 
         HT_JetBin4_gen->Add(HT_JetBin4_gen_temp);

         gDirectory->GetObject("HT_JetBin4_rec;1", HT_JetBin4_reco_temp); 
         HT_JetBin4_reco->Add(HT_JetBin4_reco_temp);

         gDirectory->GetObject("HT_JetBin4_reb;1", HT_JetBin4_reb_temp); 
         HT_JetBin4_reb->Add(HT_JetBin4_reb_temp);

         gDirectory->GetObject("HT_JetBin4_smeared;1", HT_JetBin4_smear_temp); 
         HT_JetBin4_smear->Add(HT_JetBin4_smear_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_gen;1", deltaPhiJet1Jet2_gen_temp); 
         deltaPhiJet1Jet2_gen->Add(deltaPhiJet1Jet2_gen_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_rec;1", deltaPhiJet1Jet2_rec_temp); 
         deltaPhiJet1Jet2_rec->Add(deltaPhiJet1Jet2_rec_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_smeared;1", deltaPhiJet1Jet2_smeared_temp); 
         deltaPhiJet1Jet2_smeared->Add(deltaPhiJet1Jet2_smeared_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_reb;1", deltaPhiJet1Jet2_reb_temp); 
         deltaPhiJet1Jet2_reb->Add(deltaPhiJet1Jet2_reb_temp);

         gDirectory->GetObject("MHTall_gen;1", MHTall_gen_temp); 
         MHTall_gen->Add(MHTall_gen_temp);

         gDirectory->GetObject("MHTall_rec;1", MHTall_reco_temp); 
         MHTall_reco->Add(MHTall_reco_temp);

         gDirectory->GetObject("MHTall_reb;1", MHTall_reb_temp); 
         MHTall_reb->Add(MHTall_reb_temp);

         gDirectory->GetObject("MHTall_smeared;1", MHTall_smear_temp); 
         MHTall_smear->Add(MHTall_smear_temp);

         input_file->Close();
      }
      myfile2.close();
   }

   ifstream myfile3 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_madgraph_DR53X_chs_pt10_withoutPUReweighting_HT500-1000_UseRebCorrection_v1_mc.txt");
   //ifstream myfile3 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_madgraph_DR53X_chs_pt10_withoutPUReweighting_HT500-1000_DoNotUseRebCorrection_v1_mc.txt");
   if (myfile3.is_open()) {
      while( myfile3.good() ) {
         getline (myfile3,root_file);
         cout << root_file << endl;

         TH1F* NJets_gen_temp;
         TH1F* NJets_reco_temp;
         TH1F* NJets_reb_temp;
         TH1F* NJets_smear_temp;
         TH1F* JetPt_gen_temp;
         TH1F* JetPt_reco_temp;
         TH1F* JetPt_reb_temp;
         TH1F* JetPt_smear_temp;
         TH1F* HT_JetBin1_gen_temp;
         TH1F* HT_JetBin1_reco_temp;
         TH1F* HT_JetBin1_reb_temp;
         TH1F* HT_JetBin1_smear_temp;
         TH1F* HT_JetBin2_gen_temp;
         TH1F* HT_JetBin2_reco_temp;
         TH1F* HT_JetBin2_reb_temp;
         TH1F* HT_JetBin2_smear_temp;
         TH1F* HT_JetBin3_gen_temp;
         TH1F* HT_JetBin3_reco_temp;
         TH1F* HT_JetBin3_reb_temp;
         TH1F* HT_JetBin3_smear_temp;
         TH1F* HT_JetBin4_gen_temp;
         TH1F* HT_JetBin4_reco_temp;
         TH1F* HT_JetBin4_reb_temp;
         TH1F* HT_JetBin4_smear_temp;
         TH1F* deltaPhiJet1Jet2_gen_temp;
         TH1F* deltaPhiJet1Jet2_rec_temp; 
         TH1F* deltaPhiJet1Jet2_smeared_temp;
         TH1F* deltaPhiJet1Jet2_reb_temp;
         TH1F* HTall_gen_temp;
         TH1F* HTall_reco_temp;
         TH1F* HTall_reb_temp;
         TH1F* HTall_smear_temp;
         TH1F* MHTall_gen_temp;
         TH1F* MHTall_reco_temp;
         TH1F* MHTall_reb_temp;
         TH1F* MHTall_smear_temp;
         
         TString path = root_file;

         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("NJets_gen;1", NJets_gen_temp);
         NJets_gen->Add(NJets_gen_temp);

         gDirectory->GetObject("NJets_reco;1", NJets_reco_temp);
         NJets_reco->Add(NJets_reco_temp);
    
         gDirectory->GetObject("NJets_reb;1", NJets_reb_temp); 
         NJets_reb->Add(NJets_reb_temp);
    
         gDirectory->GetObject("NJets_smear;1", NJets_smear_temp); 
         NJets_smear->Add(NJets_smear_temp);
        
         gDirectory->GetObject("JetPt_gen;1", JetPt_gen_temp); 
         JetPt_gen->Add(JetPt_gen_temp);

         gDirectory->GetObject("JetPt_reco;1", JetPt_reco_temp); 
         JetPt_reco->Add(JetPt_reco_temp);

         gDirectory->GetObject("JetPt_reb;1", JetPt_reb_temp); 
         JetPt_reb->Add(JetPt_reb_temp);
    
         gDirectory->GetObject("JetPt_smear;1", JetPt_smear_temp);
         JetPt_smear->Add(JetPt_smear_temp);

         gDirectory->GetObject("HT_gen;1", HTall_gen_temp); 
         HT_gen->Add(HTall_gen_temp);

         gDirectory->GetObject("HT_rec;1", HTall_reco_temp); 
         HT_reco->Add(HTall_reco_temp);

         gDirectory->GetObject("HT_reb;1", HTall_reb_temp); 
         HT_reb->Add(HTall_reb_temp);

         gDirectory->GetObject("HT_smeared;1", HTall_smear_temp); 
         HT_smear->Add(HTall_smear_temp);

         gDirectory->GetObject("HT_JetBin1_gen;1", HT_JetBin1_gen_temp); 
         HT_JetBin1_gen->Add(HT_JetBin1_gen_temp);

         gDirectory->GetObject("HT_JetBin1_rec;1", HT_JetBin1_reco_temp); 
         HT_JetBin1_reco->Add(HT_JetBin1_reco_temp);

         gDirectory->GetObject("HT_JetBin1_reb;1", HT_JetBin1_reb_temp); 
         HT_JetBin1_reb->Add(HT_JetBin1_reb_temp);

         gDirectory->GetObject("HT_JetBin1_smeared;1", HT_JetBin1_smear_temp); 
         HT_JetBin1_smear->Add(HT_JetBin1_smear_temp);

         gDirectory->GetObject("HT_JetBin2_gen;1", HT_JetBin2_gen_temp); 
         HT_JetBin2_gen->Add(HT_JetBin2_gen_temp);

         gDirectory->GetObject("HT_JetBin2_rec;1", HT_JetBin2_reco_temp); 
         HT_JetBin2_reco->Add(HT_JetBin2_reco_temp);

         gDirectory->GetObject("HT_JetBin2_reb;1", HT_JetBin2_reb_temp); 
         HT_JetBin2_reb->Add(HT_JetBin2_reb_temp);

         gDirectory->GetObject("HT_JetBin2_smeared;1", HT_JetBin2_smear_temp); 
         HT_JetBin2_smear->Add(HT_JetBin2_smear_temp);

         gDirectory->GetObject("HT_JetBin3_gen;1", HT_JetBin3_gen_temp); 
         HT_JetBin3_gen->Add(HT_JetBin3_gen_temp);

         gDirectory->GetObject("HT_JetBin3_rec;1", HT_JetBin3_reco_temp); 
         HT_JetBin3_reco->Add(HT_JetBin3_reco_temp);

         gDirectory->GetObject("HT_JetBin3_reb;1", HT_JetBin3_reb_temp); 
         HT_JetBin3_reb->Add(HT_JetBin3_reb_temp);

         gDirectory->GetObject("HT_JetBin3_smeared;1", HT_JetBin3_smear_temp); 
         HT_JetBin3_smear->Add(HT_JetBin3_smear_temp);

         gDirectory->GetObject("HT_JetBin4_gen;1", HT_JetBin4_gen_temp); 
         HT_JetBin4_gen->Add(HT_JetBin4_gen_temp);

         gDirectory->GetObject("HT_JetBin4_rec;1", HT_JetBin4_reco_temp); 
         HT_JetBin4_reco->Add(HT_JetBin4_reco_temp);

         gDirectory->GetObject("HT_JetBin4_reb;1", HT_JetBin4_reb_temp); 
         HT_JetBin4_reb->Add(HT_JetBin4_reb_temp);

         gDirectory->GetObject("HT_JetBin4_smeared;1", HT_JetBin4_smear_temp); 
         HT_JetBin4_smear->Add(HT_JetBin4_smear_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_gen;1", deltaPhiJet1Jet2_gen_temp); 
         deltaPhiJet1Jet2_gen->Add(deltaPhiJet1Jet2_gen_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_rec;1", deltaPhiJet1Jet2_rec_temp); 
         deltaPhiJet1Jet2_rec->Add(deltaPhiJet1Jet2_rec_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_smeared;1", deltaPhiJet1Jet2_smeared_temp); 
         deltaPhiJet1Jet2_smeared->Add(deltaPhiJet1Jet2_smeared_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_reb;1", deltaPhiJet1Jet2_reb_temp); 
         deltaPhiJet1Jet2_reb->Add(deltaPhiJet1Jet2_reb_temp);

         gDirectory->GetObject("MHTall_gen;1", MHTall_gen_temp); 
         MHTall_gen->Add(MHTall_gen_temp);

         gDirectory->GetObject("MHTall_rec;1", MHTall_reco_temp); 
         MHTall_reco->Add(MHTall_reco_temp);

         gDirectory->GetObject("MHTall_reb;1", MHTall_reb_temp); 
         MHTall_reb->Add(MHTall_reb_temp);

         gDirectory->GetObject("MHTall_smeared;1", MHTall_smear_temp); 
         MHTall_smear->Add(MHTall_smear_temp);

         input_file->Close();
      }
      myfile3.close();
   }

   ifstream myfile4 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_madgraph_DR53X_chs_pt10_withoutPUReweighting_HT1000-Inf_UseRebCorrection_v1_mc.txt");
   //ifstream myfile4 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_madgraph_DR53X_chs_pt10_withoutPUReweighting_HT1000-Inf_DoNotUseRebCorrection_v1_mc.txt");
   if (myfile4.is_open()) {
      while( myfile4.good() ) {
         getline (myfile4,root_file);
         cout << root_file << endl;

         TH1F* NJets_gen_temp;
         TH1F* NJets_reco_temp;
         TH1F* NJets_reb_temp;
         TH1F* NJets_smear_temp;
         TH1F* JetPt_gen_temp;
         TH1F* JetPt_reco_temp;
         TH1F* JetPt_reb_temp;
         TH1F* JetPt_smear_temp;
         TH1F* HT_JetBin1_gen_temp;
         TH1F* HT_JetBin1_reco_temp;
         TH1F* HT_JetBin1_reb_temp;
         TH1F* HT_JetBin1_smear_temp;
         TH1F* HT_JetBin2_gen_temp;
         TH1F* HT_JetBin2_reco_temp;
         TH1F* HT_JetBin2_reb_temp;
         TH1F* HT_JetBin2_smear_temp;
         TH1F* HT_JetBin3_gen_temp;
         TH1F* HT_JetBin3_reco_temp;
         TH1F* HT_JetBin3_reb_temp;
         TH1F* HT_JetBin3_smear_temp;
         TH1F* HT_JetBin4_gen_temp;
         TH1F* HT_JetBin4_reco_temp;
         TH1F* HT_JetBin4_reb_temp;
         TH1F* HT_JetBin4_smear_temp;
         TH1F* deltaPhiJet1Jet2_gen_temp;
         TH1F* deltaPhiJet1Jet2_rec_temp; 
         TH1F* deltaPhiJet1Jet2_smeared_temp;
         TH1F* deltaPhiJet1Jet2_reb_temp;
         TH1F* HTall_gen_temp;
         TH1F* HTall_reco_temp;
         TH1F* HTall_reb_temp;
         TH1F* HTall_smear_temp;
         TH1F* MHTall_gen_temp;
         TH1F* MHTall_reco_temp;
         TH1F* MHTall_reb_temp;
         TH1F* MHTall_smear_temp;
         
         TString path = root_file;

         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("NJets_gen;1", NJets_gen_temp);
         NJets_gen->Add(NJets_gen_temp);

         gDirectory->GetObject("NJets_reco;1", NJets_reco_temp);
         NJets_reco->Add(NJets_reco_temp);
    
         gDirectory->GetObject("NJets_reb;1", NJets_reb_temp); 
         NJets_reb->Add(NJets_reb_temp);
    
         gDirectory->GetObject("NJets_smear;1", NJets_smear_temp); 
         NJets_smear->Add(NJets_smear_temp);
        
         gDirectory->GetObject("JetPt_gen;1", JetPt_gen_temp); 
         JetPt_gen->Add(JetPt_gen_temp);

         gDirectory->GetObject("JetPt_reco;1", JetPt_reco_temp); 
         JetPt_reco->Add(JetPt_reco_temp);

         gDirectory->GetObject("JetPt_reb;1", JetPt_reb_temp); 
         JetPt_reb->Add(JetPt_reb_temp);
    
         gDirectory->GetObject("JetPt_smear;1", JetPt_smear_temp);
         JetPt_smear->Add(JetPt_smear_temp);

         gDirectory->GetObject("HT_gen;1", HTall_gen_temp); 
         HT_gen->Add(HTall_gen_temp);

         gDirectory->GetObject("HT_rec;1", HTall_reco_temp); 
         HT_reco->Add(HTall_reco_temp);

         gDirectory->GetObject("HT_reb;1", HTall_reb_temp); 
         HT_reb->Add(HTall_reb_temp);

         gDirectory->GetObject("HT_smeared;1", HTall_smear_temp); 
         HT_smear->Add(HTall_smear_temp);

         gDirectory->GetObject("HT_JetBin1_gen;1", HT_JetBin1_gen_temp); 
         HT_JetBin1_gen->Add(HT_JetBin1_gen_temp);

         gDirectory->GetObject("HT_JetBin1_rec;1", HT_JetBin1_reco_temp); 
         HT_JetBin1_reco->Add(HT_JetBin1_reco_temp);

         gDirectory->GetObject("HT_JetBin1_reb;1", HT_JetBin1_reb_temp); 
         HT_JetBin1_reb->Add(HT_JetBin1_reb_temp);

         gDirectory->GetObject("HT_JetBin1_smeared;1", HT_JetBin1_smear_temp); 
         HT_JetBin1_smear->Add(HT_JetBin1_smear_temp);

         gDirectory->GetObject("HT_JetBin2_gen;1", HT_JetBin2_gen_temp); 
         HT_JetBin2_gen->Add(HT_JetBin2_gen_temp);

         gDirectory->GetObject("HT_JetBin2_rec;1", HT_JetBin2_reco_temp); 
         HT_JetBin2_reco->Add(HT_JetBin2_reco_temp);

         gDirectory->GetObject("HT_JetBin2_reb;1", HT_JetBin2_reb_temp); 
         HT_JetBin2_reb->Add(HT_JetBin2_reb_temp);

         gDirectory->GetObject("HT_JetBin2_smeared;1", HT_JetBin2_smear_temp); 
         HT_JetBin2_smear->Add(HT_JetBin2_smear_temp);

         gDirectory->GetObject("HT_JetBin3_gen;1", HT_JetBin3_gen_temp); 
         HT_JetBin3_gen->Add(HT_JetBin3_gen_temp);

         gDirectory->GetObject("HT_JetBin3_rec;1", HT_JetBin3_reco_temp); 
         HT_JetBin3_reco->Add(HT_JetBin3_reco_temp);

         gDirectory->GetObject("HT_JetBin3_reb;1", HT_JetBin3_reb_temp); 
         HT_JetBin3_reb->Add(HT_JetBin3_reb_temp);

         gDirectory->GetObject("HT_JetBin3_smeared;1", HT_JetBin3_smear_temp); 
         HT_JetBin3_smear->Add(HT_JetBin3_smear_temp);

         gDirectory->GetObject("HT_JetBin4_gen;1", HT_JetBin4_gen_temp); 
         HT_JetBin4_gen->Add(HT_JetBin4_gen_temp);

         gDirectory->GetObject("HT_JetBin4_rec;1", HT_JetBin4_reco_temp); 
         HT_JetBin4_reco->Add(HT_JetBin4_reco_temp);

         gDirectory->GetObject("HT_JetBin4_reb;1", HT_JetBin4_reb_temp); 
         HT_JetBin4_reb->Add(HT_JetBin4_reb_temp);

         gDirectory->GetObject("HT_JetBin4_smeared;1", HT_JetBin4_smear_temp); 
         HT_JetBin4_smear->Add(HT_JetBin4_smear_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_gen;1", deltaPhiJet1Jet2_gen_temp); 
         deltaPhiJet1Jet2_gen->Add(deltaPhiJet1Jet2_gen_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_rec;1", deltaPhiJet1Jet2_rec_temp); 
         deltaPhiJet1Jet2_rec->Add(deltaPhiJet1Jet2_rec_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_smeared;1", deltaPhiJet1Jet2_smeared_temp); 
         deltaPhiJet1Jet2_smeared->Add(deltaPhiJet1Jet2_smeared_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_reb;1", deltaPhiJet1Jet2_reb_temp); 
         deltaPhiJet1Jet2_reb->Add(deltaPhiJet1Jet2_reb_temp);

         gDirectory->GetObject("MHTall_gen;1", MHTall_gen_temp); 
         MHTall_gen->Add(MHTall_gen_temp);

         gDirectory->GetObject("MHTall_rec;1", MHTall_reco_temp); 
         MHTall_reco->Add(MHTall_reco_temp);

         gDirectory->GetObject("MHTall_reb;1", MHTall_reb_temp); 
         MHTall_reb->Add(MHTall_reb_temp);

         gDirectory->GetObject("MHTall_smeared;1", MHTall_smear_temp); 
         MHTall_smear->Add(MHTall_smear_temp);

         input_file->Close();
      }
      myfile4.close();
   }



   /*string root_file;
   //ifstream myfile ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_pythia_DR53X_chs_TuneZ2star_pt10_withoutPUReweighting_UseRebCorrection_v1_mc.txt");
   ifstream myfile ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_pythia_DR53X_chs_TuneZ2star_pt10_withoutPUReweighting_DoNotUseRebCorrection_v1_mc.txt");
   if (myfile.is_open()) {
      while( myfile.good() ) {
         getline (myfile,root_file);
         cout << root_file << endl;
               
         TH1F* NJets_gen_temp;
         TH1F* NJets_reco_temp;
         TH1F* NJets_reb_temp;
         TH1F* NJets_smear_temp;
         TH1F* JetPt_gen_temp;
         TH1F* JetPt_reco_temp;
         TH1F* JetPt_reb_temp;
         TH1F* JetPt_smear_temp;
         TH1F* HT_gen_temp;
         TH1F* HT_reco_temp;
         TH1F* HT_reb_temp;
         TH1F* HT_smear_temp;
         TH1F* HT_JetBin1_gen_temp;
         TH1F* HT_JetBin1_reco_temp;
         TH1F* HT_JetBin1_reb_temp;
         TH1F* HT_JetBin1_smear_temp;
         TH1F* HT_JetBin2_gen_temp;
         TH1F* HT_JetBin2_reco_temp;
         TH1F* HT_JetBin2_reb_temp;
         TH1F* HT_JetBin2_smear_temp;
         TH1F* HT_JetBin3_gen_temp;
         TH1F* HT_JetBin3_reco_temp;
         TH1F* HT_JetBin3_reb_temp;
         TH1F* HT_JetBin3_smear_temp;
         TH1F* HT_JetBin4_gen_temp;
         TH1F* HT_JetBin4_reco_temp;
         TH1F* HT_JetBin4_reb_temp;
         TH1F* HT_JetBin4_smear_temp;
         TH1F* deltaPhiJet1Jet2_gen_temp;
         TH1F* deltaPhiJet1Jet2_rec_temp; 
         TH1F* deltaPhiJet1Jet2_smeared_temp;
         TH1F* deltaPhiJet1Jet2_reb_temp;
         TH1F* MHTall_gen_temp;
         TH1F* MHTall_reco_temp;
         TH1F* MHTall_reb_temp;
         TH1F* MHTall_smear_temp;
         
         TString path = root_file;

         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("NJets_gen;1", NJets_gen_temp);
         NJets_gen->Add(NJets_gen_temp);

         gDirectory->GetObject("NJets_reco;1", NJets_reco_temp);
         NJets_reco->Add(NJets_reco_temp);
    
         gDirectory->GetObject("NJets_reb;1", NJets_reb_temp); 
         NJets_reb->Add(NJets_reb_temp);
    
         gDirectory->GetObject("NJets_smear;1", NJets_smear_temp); 
         NJets_smear->Add(NJets_smear_temp);
        
         gDirectory->GetObject("JetPt_gen;1", JetPt_gen_temp); 
         JetPt_gen->Add(JetPt_gen_temp);

         gDirectory->GetObject("JetPt_reco;1", JetPt_reco_temp); 
         JetPt_reco->Add(JetPt_reco_temp);

         gDirectory->GetObject("JetPt_reb;1", JetPt_reb_temp); 
         JetPt_reb->Add(JetPt_reb_temp);
    
         gDirectory->GetObject("JetPt_smear;1", JetPt_smear_temp);
         JetPt_smear->Add(JetPt_smear_temp);

         gDirectory->GetObject("HT_gen;1", HT_gen_temp); 
         HT_gen->Add(HT_gen_temp);

         gDirectory->GetObject("HT_rec;1", HT_reco_temp); 
         HT_reco->Add(HT_reco_temp);

         gDirectory->GetObject("HT_reb;1", HT_reb_temp); 
         HT_reb->Add(HT_reb_temp);

         gDirectory->GetObject("HT_smeared;1", HT_smear_temp); 
         HT_smear->Add(HT_smear_temp);

         gDirectory->GetObject("HT_JetBin1_gen;1", HT_JetBin1_gen_temp); 
         HT_JetBin1_gen->Add(HT_JetBin1_gen_temp);

         gDirectory->GetObject("HT_JetBin1_rec;1", HT_JetBin1_reco_temp); 
         HT_JetBin1_reco->Add(HT_JetBin1_reco_temp);

         gDirectory->GetObject("HT_JetBin1_reb;1", HT_JetBin1_reb_temp); 
         HT_JetBin1_reb->Add(HT_JetBin1_reb_temp);

         gDirectory->GetObject("HT_JetBin1_smeared;1", HT_JetBin1_smear_temp); 
         HT_JetBin1_smear->Add(HT_JetBin1_smear_temp);

         gDirectory->GetObject("HT_JetBin2_gen;1", HT_JetBin2_gen_temp); 
         HT_JetBin2_gen->Add(HT_JetBin2_gen_temp);

         gDirectory->GetObject("HT_JetBin2_rec;1", HT_JetBin2_reco_temp); 
         HT_JetBin2_reco->Add(HT_JetBin2_reco_temp);

         gDirectory->GetObject("HT_JetBin2_reb;1", HT_JetBin2_reb_temp); 
         HT_JetBin2_reb->Add(HT_JetBin2_reb_temp);

         gDirectory->GetObject("HT_JetBin2_smeared;1", HT_JetBin2_smear_temp); 
         HT_JetBin2_smear->Add(HT_JetBin2_smear_temp);

         gDirectory->GetObject("HT_JetBin3_gen;1", HT_JetBin3_gen_temp); 
         HT_JetBin3_gen->Add(HT_JetBin3_gen_temp);

         gDirectory->GetObject("HT_JetBin3_rec;1", HT_JetBin3_reco_temp); 
         HT_JetBin3_reco->Add(HT_JetBin3_reco_temp);

         gDirectory->GetObject("HT_JetBin3_reb;1", HT_JetBin3_reb_temp); 
         HT_JetBin3_reb->Add(HT_JetBin3_reb_temp);

         gDirectory->GetObject("HT_JetBin3_smeared;1", HT_JetBin3_smear_temp); 
         HT_JetBin3_smear->Add(HT_JetBin3_smear_temp);

         gDirectory->GetObject("HT_JetBin4_gen;1", HT_JetBin4_gen_temp); 
         HT_JetBin4_gen->Add(HT_JetBin4_gen_temp);

         gDirectory->GetObject("HT_JetBin4_rec;1", HT_JetBin4_reco_temp); 
         HT_JetBin4_reco->Add(HT_JetBin4_reco_temp);

         gDirectory->GetObject("HT_JetBin4_reb;1", HT_JetBin4_reb_temp); 
         HT_JetBin4_reb->Add(HT_JetBin4_reb_temp);

         gDirectory->GetObject("HT_JetBin4_smeared;1", HT_JetBin4_smear_temp); 
         HT_JetBin4_smear->Add(HT_JetBin4_smear_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_gen;1", deltaPhiJet1Jet2_gen_temp); 
         deltaPhiJet1Jet2_gen->Add(deltaPhiJet1Jet2_gen_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_rec;1", deltaPhiJet1Jet2_rec_temp); 
         deltaPhiJet1Jet2_rec->Add(deltaPhiJet1Jet2_rec_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_smeared;1", deltaPhiJet1Jet2_smeared_temp); 
         deltaPhiJet1Jet2_smeared->Add(deltaPhiJet1Jet2_smeared_temp);

         gDirectory->GetObject("deltaPhiJet1Jet2_reb;1", deltaPhiJet1Jet2_reb_temp); 
         deltaPhiJet1Jet2_reb->Add(deltaPhiJet1Jet2_reb_temp);

         gDirectory->GetObject("MHTall_gen;1", MHTall_gen_temp); 
         MHTall_gen->Add(MHTall_gen_temp);

         gDirectory->GetObject("MHTall_rec;1", MHTall_reco_temp); 
         MHTall_reco->Add(MHTall_reco_temp);

         gDirectory->GetObject("MHTall_reb;1", MHTall_reb_temp); 
         MHTall_reb->Add(MHTall_reb_temp);

         gDirectory->GetObject("MHTall_smeared;1", MHTall_smear_temp); 
         MHTall_smear->Add(MHTall_smear_temp);

         input_file->Close();
         
      }
      myfile.close();
      }*/
   
   TString Title = "";
 
   TCanvas *c = new TCanvas("c", "", 700, 700);
   c->SetLogy();

   NJets_gen->SetBinContent(1, 0);
   NJets_gen->SetBinContent(2, 0);
   NJets_gen->SetBinContent(3, 0);
   // NJets_gen->GetXaxis()->SetRangeUser(2, 15);
   NJets_reb->SetBinContent(1, 0);
   NJets_reb->SetBinContent(2, 0);
   NJets_reb->SetBinContent(3, 0);
      //NJets_reb->GetXaxis()->SetRangeUser(2, 15);
   c = DrawComparison( NJets_reb, NJets_gen , "N_{Jets}", Title );

   c->Print(outfile + "_NJets.png");
   c->Print(outfile + ".ps(");
  
   // plot JetPt
   JetPt_gen->Rebin(5);
   JetPt_reb->Rebin(5);
   Title = "All jets";
   c = DrawComparison( JetPt_reb, JetPt_gen , "jet p_{T} [GeV]", Title);
  
   c->Print(outfile + ".ps");
   c->Print(outfile + "_JetPt.png");

   // plot deltaPhi 2 jets
   // Title = "";
   c= DrawComparison( deltaPhiJet1Jet2_reb, deltaPhiJet1Jet2_gen, "#Delta#phi(jet 1, jet 2)", Title);

   c->Print(outfile + ".ps");
   c->Print(outfile + "_DeltaPhiJet1Jet2.png");

   // plot HT
   HT_gen->Rebin(10);
   HT_reb->Rebin(10);
   c = DrawComparison( HT_reb, HT_gen , "HT [GeV]", Title);
  
   c->Print(outfile + ".ps");
   c->Print(outfile + "_HT.png");

   // plot HT_JetBin1
   HT_JetBin1_gen->Rebin(10);
   HT_JetBin1_reb->Rebin(10);
   Title = "2 Jets";
   c = DrawComparison( HT_JetBin1_reb, HT_JetBin1_gen , "HT [GeV]", Title);
 
   c->Print(outfile + ".ps");
   c->Print(outfile + "_HT_JetBin1.png");

   // plot HT_JetBin2
   HT_JetBin2_gen->Rebin(10);
   HT_JetBin2_reb->Rebin(10);
   Title = "3-5 Jets";
   c = DrawComparison( HT_JetBin2_reb, HT_JetBin2_gen , "HT [GeV]", Title);
 
   c->Print(outfile + ".ps");
   c->Print(outfile + "_HT_JetBin2.png");

   // plot HT_JetBin3
   HT_JetBin3_gen->Rebin(5);
   HT_JetBin3_reb->Rebin(5);
   Title = "6-7 Jets";
   c = DrawComparison( HT_JetBin3_reb, HT_JetBin3_gen , "HT [GeV]", Title);
 
   c->Print(outfile + ".ps");
   c->Print(outfile + "_HT_JetBin3.png");

   // plot HT_JetBin4
   HT_JetBin4_gen->Rebin(5);
   HT_JetBin4_reb->Rebin(5);
   Title = ">= 8 Jets";
   c = DrawComparison( HT_JetBin4_reb, HT_JetBin4_gen , "HT [GeV]", Title);
  
   c->Print(outfile + ".ps)");
   c->Print(outfile + "_HT_JetBin4.png");

   // plot MHT
   // c = DrawComparison( MHTall_reb, MHTall_gen , "MHT [GeV]");
  
   // c->Print(outfile + ".ps)");
   //c->Print(outfile + "_MHTall.png");
}


TCanvas* DrawComparison(TH1F* prediction, TH1F* selection, TString xTitle, TString Title)
{  
   double MinX = selection->GetXaxis()->GetXmin();
   double MaxX = selection->GetXaxis()->GetXmax();
   double MaxY = selection->GetMaximum();
   double YRangeMax = 120.*MaxY;
   TString titlePrediction;
   TString titleSelection;
   TString RatioTitle;
   
   titlePrediction = "Rebalanced events";
   titleSelection = "Generated events";
   RatioTitle = "(Reb-Gen)/Gen";
   
   Int_t c_LightBrown = TColor::GetColor( "#D9D9CC" );
   Int_t c_LightGray = TColor::GetColor( "#DDDDDD" );

   prediction->SetAxisRange(MinX, MaxX, "X");
   //  prediction->GetYaxis()->SetRangeUser(0.005, YRangeMax);
   prediction->GetYaxis()->SetRangeUser(0.05, YRangeMax);
   prediction->SetMarkerStyle(20);
   prediction->SetMarkerSize(0.9);
   prediction->SetMarkerColor(kBlack);
   prediction->SetXTitle(xTitle);
   prediction->SetYTitle("Events");
   selection->SetAxisRange(MinX, MaxX, "X");
   selection->GetYaxis()->SetRangeUser(0.05, YRangeMax);
   // selection->SetFillColor(c_LightBrown);
   selection->SetFillColor(c_LightGray);
   selection->SetTitle("");
   selection->SetXTitle(xTitle);
   selection->SetYTitle("Events");

   TCanvas *c = new TCanvas("ca", "Comparison and ratio of two histos", 700, 700);

   TPad *pad1 = new TPad("pad1a", "pad1a", 0, 0.35, 1, 1);
   pad1->SetLogy();
   pad1->SetBottomMargin(0);
   pad1->Draw();
   pad1->cd();
  
   selection->DrawCopy("hist");
   prediction->Draw("same");
   selection->SetFillColor(kAzure-3);
   selection->SetFillStyle(3354);
   selection->DrawCopy("e2same");

   selection->SetFillStyle(1001);
   //  selection->SetFillColor(c_LightBrown);
   selection->SetFillColor(c_LightGray);

   TLegend* leg1 = new TLegend(0.48, 0.63, 0.95, 0.83);
   leg1->SetFillStyle(0);
   leg1->SetLineStyle(1);
   leg1->SetTextFont(42);
   leg1->SetTextSize(0.045);
   leg1->AddEntry(selection, titleSelection, "lf");
   leg1->AddEntry(prediction, titlePrediction, "lep");
   leg1->Draw("same");
 
   TPaveText* pt = new TPaveText(0.11, 0.98, 0.95, 0.86, "NDC");
   pt->SetBorderSize(0);
   pt->SetFillStyle(0);
   pt->SetTextAlign(12);
   pt->SetTextSize(0.045);
   pt->AddText(Title);
   pt->AddText("CMS work in progress, #sqrt{s} = 8 TeV");
   pt->Draw();

   c->cd();
   TPad *pad2 = new TPad("pad2a", "pad2a", 0, 0, 1, 0.35);
   pad2->SetTopMargin(0);
   pad2->Draw();
   pad2->cd();
   TH1F* r = new TH1F(*selection);
   r->SetTitle("");
   r->SetLabelSize(0.08, "XYZ");
   r->SetLabelOffset(0.01, "XYZ");
   // r->SetTitleSize(0.09, "XYZ");
   r->SetTitleSize(0.125, "XYZ");
   r->SetTitleOffset(0.95, "X");
   r->SetTitleOffset(0.53, "Y");
   // r->SetTitleOffset(0.65, "Y");
   r->SetTickLength(0.05);
   r->SetYTitle(RatioTitle);
   r->SetStats(0);
   r->SetMarkerStyle(20);
   r->SetMarkerSize(0.9);
   r->SetMarkerColor(kBlack);
   r->Reset();
   r->Add(prediction, 1);
   r->Add(selection, -1);
   r->Divide(selection);
   r->SetMaximum(1.2);
   r->SetMinimum(-1.2);
   r->Draw("ep");
   TLine l;
   l.DrawLine(MinX, 0., MaxX, 0.);
   c->cd();
   return c;
}
