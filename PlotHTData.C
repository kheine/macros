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

void PlotHTData()
{
   gROOT->ProcessLine(".L PlottingUtils.C+");

   PlottingUtils::SetPlotStyle();

   gStyle->SetNdivisions(505, "X");
   gROOT->ForceStyle();

   TH1F* HT_seed_data = new TH1F("HT", "HT", 100, 0, 5000);
   TH1F* HT_seed_mc_pythia = new TH1F("HT_mc_pythia", "HT", 100, 0, 5000);
   TH1F* HT_seed_mc_madgraph = new TH1F("HT_mc_madgraph", "HT", 100, 0, 5000);
  
   string root_file;
   ifstream myfile1 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_prediction_535_Run2012A-13Jul2012-v1_pt10_withUncertainties_UseRebCorrection_data_v3.txt");
   if (myfile1.is_open()) {
      while( myfile1.good() ) {
         getline (myfile1,root_file);
         cout << root_file << endl;

         TString path = root_file;

         TH1F* HT_seed_data_temp; 
               
         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("HT_rec;1", HT_seed_data_temp);
         HT_seed_data->Add(HT_seed_data_temp);

         input_file->Close();
      }
      myfile1.close();
   }

   ifstream myfile2 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_prediction_535_Run2012A-recover-06Aug2012-v1_pt10_withUncertainties_UseRebCorrection_data_v3.txt");
   if (myfile2.is_open()) {
      while( myfile2.good() ) {
         getline (myfile2,root_file);
         cout << root_file << endl;

         TString path = root_file;
        
         TH1F* HT_seed_data_temp; 
               
         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("HT_rec;1", HT_seed_data_temp);
         HT_seed_data->Add(HT_seed_data_temp);

         input_file->Close();

      }
      myfile2.close();
   }

   ifstream myfile3 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_prediction_535_Run2012B-13Jul2012-v1_pt10_withUncertainties_UseRebCorrection_data_v3.txt");
   if (myfile3.is_open()) {
      while( myfile3.good() ) {
         getline (myfile3,root_file);
         cout << root_file << endl;

         TString path = root_file;
        
         TH1F* HT_seed_data_temp; 
               
         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("HT_rec;1", HT_seed_data_temp);
         HT_seed_data->Add(HT_seed_data_temp);

         input_file->Close();

      }
      myfile3.close();
   }

   ifstream myfile4 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_prediction_535_Run2012C-24Aug2012-v1_pt10_withUncertainties_UseRebCorrection_data_v3.txt");
   if (myfile4.is_open()) {
      while( myfile4.good() ) {
         getline (myfile4,root_file);
         cout << root_file << endl;

         TString path = root_file;
        
         TH1F* HT_seed_data_temp; 
               
         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("HT_rec;1", HT_seed_data_temp);
         HT_seed_data->Add(HT_seed_data_temp);

         input_file->Close();

      }
      myfile4.close();
   }

   ifstream myfile5 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_prediction_535_Run2012C-PromptReco-v2_pt10_withUncertainties_UseRebCorrection_data_v3.txt");
   if (myfile5.is_open()) {
      while( myfile5.good() ) {
         getline (myfile5,root_file);
         cout << root_file << endl;

         TString path = root_file;
        
         TH1F* HT_seed_data_temp; 
               
         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("HT_rec;1", HT_seed_data_temp);
         HT_seed_data->Add(HT_seed_data_temp);

         input_file->Close();

      }
      myfile5.close();
   }

   ifstream myfile6 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_prediction_535_Run2012D-PromptReco-v1_pt10_withUncertainties_UseRebCorrection_data_v3.txt");
   if (myfile6.is_open()) {
      while( myfile6.good() ) {
         getline (myfile6,root_file);
         cout << root_file << endl;

         TString path = root_file;
        
         TH1F* HT_seed_data_temp; 
               
         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("HT_rec;1", HT_seed_data_temp);
         HT_seed_data->Add(HT_seed_data_temp);

         input_file->Close();

      }
      myfile6.close();
   }

   ifstream myfile ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_pythia_DR53X_chs_TuneZ2star_pt10_withoutPUReweighting_DoNotUseRebCorrection_v1_mc.txt");
   if (myfile.is_open()) {
      while( myfile.good() ) {
         getline (myfile,root_file);
         cout << root_file << endl;

         TString path = root_file;
        
         TH1F* HT_seed_mc_temp; 
               
         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("HT_rec;1", HT_seed_mc_temp);
         HT_seed_mc_pythia->Add(HT_seed_mc_temp);

         input_file->Close();

      }
      myfile.close();
   }

   ifstream myfile1 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_madgraph_DR53X_chs_pt10_withoutPUReweighting_HT100-250_DoNotUseRebCorrection_v1_mc.txt");
   if (myfile1.is_open()) {
      while( myfile1.good() ) {
         getline (myfile1,root_file);
         cout << root_file << endl;

         TString path = root_file;
        
         TH1F* HT_seed_mc_temp; 
               
         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("HT_rec;1", HT_seed_mc_temp);
         HT_seed_mc_madgraph->Add(HT_seed_mc_temp);

         input_file->Close();
      }
      myfile1.close();
   }

   ifstream myfile2 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_madgraph_DR53X_chs_pt10_withoutPUReweighting_HT250-500_DoNotUseRebCorrection_v1_mc.txt");
   if (myfile2.is_open()) {
      while( myfile2.good() ) {
         getline (myfile2,root_file);
         cout << root_file << endl;

         TString path = root_file;
        
         TH1F* HT_seed_mc_temp; 
               
         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("HT_rec;1", HT_seed_mc_temp);
         HT_seed_mc_madgraph->Add(HT_seed_mc_temp);

         input_file->Close();
      }
      myfile2.close();
   }


   ifstream myfile3 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_madgraph_DR53X_chs_pt10_withoutPUReweighting_HT500-1000_DoNotUseRebCorrection_v1_mc.txt");
   if (myfile3.is_open()) {
      while( myfile3.good() ) {
         getline (myfile3,root_file);
         cout << root_file << endl;

         TString path = root_file;
        
         TH1F* HT_seed_mc_temp; 
               
         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("HT_rec;1", HT_seed_mc_temp);
         HT_seed_mc_madgraph->Add(HT_seed_mc_temp);

         input_file->Close();
      }
      myfile3.close();
   }

   ifstream myfile4 ("/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/filelist_madgraph_DR53X_chs_pt10_withoutPUReweighting_HT1000-Inf_DoNotUseRebCorrection_v1_mc.txt");
   if (myfile4.is_open()) {
      while( myfile4.good() ) {
         getline (myfile4,root_file);
         cout << root_file << endl;

         TString path = root_file;
        
         TH1F* HT_seed_mc_temp; 
               
         TFile* input_file = TFile::Open(path, "READ");
         input_file->cd("QCDfromSmearing");

         gDirectory->GetObject("HT_rec;1", HT_seed_mc_temp);
         HT_seed_mc_madgraph->Add(HT_seed_mc_temp);

         input_file->Close();
      }
      myfile4.close();
   }

   // --------------------------------------------------------------------------------------- //

   TCanvas *c = new TCanvas("c", "", PlottingUtils::CanvasPlot[2], PlottingUtils::CanvasPlot[3]);
   c->SetLogy();
   HT_seed_data->SetXTitle("seed HT [GeV]");
   HT_seed_data->SetYTitle("Events");
   HT_seed_data->Draw();
  
   TPaveText* pt = PlottingUtils::CMSLabelData("19.47");
   pt->Draw();

   c->Print("Plots/HT_data.png");

   // --------------------------------------------------------------------------------------- //

   TCanvas *c2 = new TCanvas("c2", "", PlottingUtils::CanvasPlot[2], PlottingUtils::CanvasPlot[3]);
   c2->SetLogy();
   HT_seed_data->SetXTitle("seed HT [GeV]");
   HT_seed_data->SetYTitle("Events");
   HT_seed_data->Draw();
   HT_seed_mc_pythia->Scale(19.466);
   HT_seed_mc_pythia->SetMarkerStyle(PlottingUtils::c_MarkerStyle[1]);
   HT_seed_mc_pythia->SetMarkerColor(PlottingUtils::c_MarkerColor[1]);
   HT_seed_mc_pythia->Draw("same");
   HT_seed_mc_madgraph->Scale(19.466);
   HT_seed_mc_madgraph->SetMarkerStyle(PlottingUtils::c_MarkerStyle[2]);
   HT_seed_mc_madgraph->SetMarkerColor(PlottingUtils::c_MarkerColor[2]);
   HT_seed_mc_madgraph->Draw("same");

   pt->Draw();

   TLegend* leg = PlottingUtils::Legend3Entries(HT_seed_data, HT_seed_mc_pythia, HT_seed_mc_madgraph,
                                                "Data", "Pythia QCD MC", "Madgraph QCD MC");
   leg->Draw("same");

   c2->Print("Plots/HT_data_plus_mc.png");

   // --------------------------------------------------------------------------------------- //

   TFile* seedHT = new TFile("SeedHT.root", "RECREATE");
   HT_seed_data->Write();
   seedHT->Write();
}
