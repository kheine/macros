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

void GetExtrapolUnc()
{
   setTDRStyle();

   TString AsymmWidth = "TruncatedRMS";
   //TString AsymmWidth = "GaussFitWidth";

   // rereco
   TFile* Asymmetry_file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/2013_04_25_plots_v1_" + AsymmWidth + "_ResidualCorr_Z2pythia_PF/OutputResolutions2012.root", "READ");

   TFile* GenAsymmetry_file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/2013_04_25_plots_v1_StandardDeviation_GenAsymmetry_Z2pythia_PF/OutputResolutions2012.root", "READ");

   // ------------------------------------------------------------------ //

   // define histos + graphs
   std::vector<double> FirstPointForExtrapol_eta0;
   std::vector<double> FirstPointForExtrapol_eta1;
   std::vector<double> FirstPointForExtrapol_eta2;
   std::vector<double> FirstPointForExtrapol_eta3;
   std::vector<double> FirstPointForExtrapol_eta4;

   std::vector<double> FirstPointForExtrapolError_eta0;
   std::vector<double> FirstPointForExtrapolError_eta1;
   std::vector<double> FirstPointForExtrapolError_eta2;
   std::vector<double> FirstPointForExtrapolError_eta3;
   std::vector<double> FirstPointForExtrapolError_eta4;

   TH1D* SigmaData_eta0;
   TH1D* SigmaData_eta1;
   TH1D* SigmaData_eta2;
   TH1D* SigmaData_eta3;
   TH1D* SigmaData_eta4;

   TH1D* SigmaMC_eta0;
   TH1D* SigmaMC_eta1;
   TH1D* SigmaMC_eta2;
   TH1D* SigmaMC_eta3;
   TH1D* SigmaMC_eta4;

   TH1D* GenSigma_eta0;
   TH1D* GenSigma_eta1;
   TH1D* GenSigma_eta2;
   TH1D* GenSigma_eta3;
   TH1D* GenSigma_eta4;

   // ------------------------------------------------------------------ //

   // get objects from file
   Asymmetry_file->cd("AbsAsymmetryVsPt10;1");

   for (unsigned int i_Pt = 0; i_Pt < 15; ++i_Pt) {

      TGraphErrors* temp_eta0 = new TGraphErrors();
      TGraphErrors* temp_eta1 = new TGraphErrors();
      TGraphErrors* temp_eta2 = new TGraphErrors();
      TGraphErrors* temp_eta3 = new TGraphErrors();
      TGraphErrors* temp_eta4 = new TGraphErrors();
            
      double eta0_x_temp = 0.;
      double eta1_x_temp = 0.;
      double eta2_x_temp = 0.;
      double eta3_x_temp = 0.;
      double eta4_x_temp = 0.;

      double eta0_y_temp = 0.;
      double eta1_y_temp = 0.;
      double eta2_y_temp = 0.;
      double eta3_y_temp = 0.;
      double eta4_y_temp = 0.;

      double eta0_yError_temp = 0.;
      double eta1_yError_temp = 0.;
      double eta2_yError_temp = 0.;
      double eta3_yError_temp = 0.;
      double eta4_yError_temp = 0.;
         
      //// Get the histos
      char hname_eta0[100];
      char hname_eta1[100];
      char hname_eta2[100];
      char hname_eta3[100];
      char hname_eta4[100];

      // get no heavy flavor hists
      sprintf(hname_eta0, "%s_MeanPt%i", "ResolutionPlots_ExtrapolPtThree_ResolutionVsPt_AbsEta0", i_Pt);
      sprintf(hname_eta1, "%s_MeanPt%i", "ResolutionPlots_ExtrapolPtThree_ResolutionVsPt_AbsEta1", i_Pt);
      sprintf(hname_eta2, "%s_MeanPt%i", "ResolutionPlots_ExtrapolPtThree_ResolutionVsPt_AbsEta2", i_Pt);
      sprintf(hname_eta3, "%s_MeanPt%i", "ResolutionPlots_ExtrapolPtThree_ResolutionVsPt_AbsEta3", i_Pt);
      sprintf(hname_eta4, "%s_MeanPt%i", "ResolutionPlots_ExtrapolPtThree_ResolutionVsPt_AbsEta4", i_Pt);

      gDirectory->GetObject(hname_eta0, temp_eta0); 
      gDirectory->GetObject(hname_eta1, temp_eta1); 
      gDirectory->GetObject(hname_eta2, temp_eta2); 
      gDirectory->GetObject(hname_eta3, temp_eta3); 
      gDirectory->GetObject(hname_eta4, temp_eta4); 
      
      // get points for eta0
      temp_eta0->GetPoint(0, eta0_x_temp, eta0_y_temp);
      eta0_yError_temp = temp_eta0->GetErrorY(0);
      if( eta0_y_temp != 0 ) {
         FirstPointForExtrapol_eta0.push_back(eta0_y_temp);
         FirstPointForExtrapolError_eta0.push_back(eta0_yError_temp);
      }
      else {
         eta0_x_temp = 0;
         eta0_y_temp = 0;
         eta0_yError_temp = 0;
         temp_eta0->GetPoint(1, eta0_x_temp, eta0_y_temp);
         eta0_yError_temp = temp_eta0->GetErrorY(1);
         FirstPointForExtrapol_eta0.push_back(eta0_y_temp);
         FirstPointForExtrapolError_eta0.push_back(eta0_yError_temp);
      }

      // get points for eta1
      temp_eta1->GetPoint(0, eta1_x_temp, eta1_y_temp);
      eta1_yError_temp = temp_eta1->GetErrorY(0);
      if( eta1_y_temp != 0 ) {
         FirstPointForExtrapol_eta1.push_back(eta1_y_temp);
         FirstPointForExtrapolError_eta1.push_back(eta1_yError_temp);
      }
      else {
         eta1_x_temp = 0;
         eta1_y_temp = 0;
         eta1_yError_temp = 0;
         temp_eta1->GetPoint(1, eta1_x_temp, eta1_y_temp);
         eta1_yError_temp = temp_eta1->GetErrorY(1);
         FirstPointForExtrapol_eta1.push_back(eta1_y_temp);
         FirstPointForExtrapolError_eta1.push_back(eta1_yError_temp);
      }

      // get points for eta2
      temp_eta2->GetPoint(0, eta2_x_temp, eta2_y_temp);
      eta2_yError_temp = temp_eta2->GetErrorY(0);
      if( eta2_y_temp != 0 ) {
         FirstPointForExtrapol_eta2.push_back(eta2_y_temp);
         FirstPointForExtrapolError_eta2.push_back(eta2_yError_temp);
      }
      else {
         eta2_x_temp = 0;
         eta2_y_temp = 0;
         eta2_yError_temp = 0;
         temp_eta2->GetPoint(1, eta2_x_temp, eta2_y_temp);
         eta2_yError_temp = temp_eta2->GetErrorY(1);
         FirstPointForExtrapol_eta2.push_back(eta2_y_temp);
         FirstPointForExtrapolError_eta2.push_back(eta2_yError_temp);
      }

      // get points for eta3
      temp_eta3->GetPoint(0, eta3_x_temp, eta3_y_temp);
      eta3_yError_temp = temp_eta3->GetErrorY(0);
      if( eta3_y_temp != 0 ) {
         FirstPointForExtrapol_eta3.push_back(eta3_y_temp);
         FirstPointForExtrapolError_eta3.push_back(eta3_yError_temp);
      }
      else {
         eta3_x_temp = 0;
         eta3_y_temp = 0;
         eta3_yError_temp = 0;
         temp_eta3->GetPoint(1, eta3_x_temp, eta3_y_temp);
         eta3_yError_temp = temp_eta3->GetErrorY(1);
         FirstPointForExtrapol_eta3.push_back(eta3_y_temp);
         FirstPointForExtrapolError_eta3.push_back(eta3_yError_temp);
      }

      // get points for eta4
      temp_eta4->GetPoint(0, eta4_x_temp, eta4_y_temp);
      eta4_yError_temp = temp_eta4->GetErrorY(0);
      if( eta4_y_temp != 0 ) {
         FirstPointForExtrapol_eta4.push_back(eta4_y_temp);
         FirstPointForExtrapolError_eta4.push_back(eta4_yError_temp);
      }
      else {
         eta4_x_temp = 0;
         eta4_y_temp = 0;
         eta4_yError_temp = 0;
         temp_eta4->GetPoint(1, eta4_x_temp, eta4_y_temp);
         eta4_yError_temp = temp_eta4->GetErrorY(1);
         FirstPointForExtrapol_eta4.push_back(eta4_y_temp);
         FirstPointForExtrapolError_eta4.push_back(eta4_yError_temp);
      }
    

      temp_eta0->Clear();
      temp_eta1->Clear();
      temp_eta2->Clear();
      temp_eta3->Clear();
      temp_eta4->Clear();
   }
    
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta0_Data;1", SigmaData_eta0);
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta1_Data;1", SigmaData_eta1);
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta2_Data;1", SigmaData_eta2);
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta3_Data;1", SigmaData_eta3);
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta4_Data;1", SigmaData_eta4);

   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta0_MC;1", SigmaMC_eta0);
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta1_MC;1", SigmaMC_eta1);
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta2_MC;1", SigmaMC_eta2);
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta3_MC;1", SigmaMC_eta3);
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta4_MC;1", SigmaMC_eta4);

   GenAsymmetry_file->cd("AbsGenAsymmetryVsPt10;1");
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta0_MC;1", GenSigma_eta0);
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta1_MC;1", GenSigma_eta1);
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta2_MC;1", GenSigma_eta2);
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta3_MC;1", GenSigma_eta3);
   gDirectory->GetObject("ResolutionPlots_ResolutionVsPt_00_AbsEta4_MC;1", GenSigma_eta4);

   // ------------------------------------------------------------------ //

   // remove fit functions
   SigmaData_eta0->GetFunction("fit_const")->SetBit(TF1::kNotDraw);
   SigmaData_eta1->GetFunction("fit_const")->SetBit(TF1::kNotDraw);
   SigmaData_eta2->GetFunction("fit_const")->SetBit(TF1::kNotDraw);
   SigmaData_eta3->GetFunction("fit_const")->SetBit(TF1::kNotDraw);
   SigmaData_eta4->GetFunction("fit_const")->SetBit(TF1::kNotDraw);

   SigmaMC_eta0->GetFunction("fit_const")->SetBit(TF1::kNotDraw);
   SigmaMC_eta1->GetFunction("fit_const")->SetBit(TF1::kNotDraw);
   SigmaMC_eta2->GetFunction("fit_const")->SetBit(TF1::kNotDraw);
   SigmaMC_eta3->GetFunction("fit_const")->SetBit(TF1::kNotDraw);
   SigmaMC_eta4->GetFunction("fit_const")->SetBit(TF1::kNotDraw);

   GenSigma_eta0->GetFunction("fit_const")->SetBit(TF1::kNotDraw);
   GenSigma_eta1->GetFunction("fit_const")->SetBit(TF1::kNotDraw);
   GenSigma_eta2->GetFunction("fit_const")->SetBit(TF1::kNotDraw);
   GenSigma_eta3->GetFunction("fit_const")->SetBit(TF1::kNotDraw);
   GenSigma_eta4->GetFunction("fit_const")->SetBit(TF1::kNotDraw);


   TH1D* SigmaDataUP_eta0 = new TH1D(*SigmaData_eta0);
   TH1D* SigmaDataUP_eta1 = new TH1D(*SigmaData_eta1);
   TH1D* SigmaDataUP_eta2 = new TH1D(*SigmaData_eta2);
   TH1D* SigmaDataUP_eta3 = new TH1D(*SigmaData_eta3);
   TH1D* SigmaDataUP_eta4 = new TH1D(*SigmaData_eta4);

   TH1D* SigmaDataDOWN_eta0 = new TH1D(*SigmaData_eta0);
   TH1D* SigmaDataDOWN_eta1 = new TH1D(*SigmaData_eta1);
   TH1D* SigmaDataDOWN_eta2 = new TH1D(*SigmaData_eta2);
   TH1D* SigmaDataDOWN_eta3 = new TH1D(*SigmaData_eta3);
   TH1D* SigmaDataDOWN_eta4 = new TH1D(*SigmaData_eta4);

   SigmaDataUP_eta0->Reset();
   SigmaDataUP_eta1->Reset();
   SigmaDataUP_eta2->Reset();
   SigmaDataUP_eta3->Reset();
   SigmaDataUP_eta4->Reset();

   SigmaDataDOWN_eta0->Reset();
   SigmaDataDOWN_eta1->Reset();
   SigmaDataDOWN_eta2->Reset();
   SigmaDataDOWN_eta3->Reset();
   SigmaDataDOWN_eta4->Reset();

   // fill vectors with histos
   vector<TH1D*> GenSigma;
   GenSigma.push_back(GenSigma_eta0);
   GenSigma.push_back(GenSigma_eta1);
   GenSigma.push_back(GenSigma_eta2);
   GenSigma.push_back(GenSigma_eta3);
   GenSigma.push_back(GenSigma_eta4);

   vector<TH1D*> SigmaMC;
   SigmaMC.push_back(SigmaMC_eta0);
   SigmaMC.push_back(SigmaMC_eta1);
   SigmaMC.push_back(SigmaMC_eta2);
   SigmaMC.push_back(SigmaMC_eta3);
   SigmaMC.push_back(SigmaMC_eta4);
  
   for (unsigned int i_Pt = 0; i_Pt < 15; i_Pt++) {
      // fill upper variations

      double bin_content_eta0_UP = SigmaData_eta0->GetBinContent(i_Pt + 1) + 0.5*TMath::Abs((FirstPointForExtrapol_eta0.at(i_Pt) - SigmaData_eta0->GetBinContent(i_Pt + 1)));
      double bin_error_eta0_UP =  TMath::Sqrt(pow(SigmaData_eta0->GetBinError(i_Pt + 1)/2,2) + pow(FirstPointForExtrapolError_eta0.at(i_Pt)/2,2));

      if ( SigmaData_eta0->GetBinContent(i_Pt + 1) ) {
         SigmaDataUP_eta0->SetBinContent(i_Pt + 1, bin_content_eta0_UP);
         SigmaDataUP_eta0->SetBinError(i_Pt + 1, bin_error_eta0_UP);
      } 

      double bin_content_eta1_UP = SigmaData_eta1->GetBinContent(i_Pt + 1) + 0.5*TMath::Abs((FirstPointForExtrapol_eta1.at(i_Pt) - SigmaData_eta1->GetBinContent(i_Pt + 1)));
      double bin_error_eta1_UP =  TMath::Sqrt(pow(SigmaData_eta1->GetBinError(i_Pt + 1)/2,2) + pow(FirstPointForExtrapolError_eta1.at(i_Pt)/2,2));

      if ( SigmaData_eta1->GetBinContent(i_Pt + 1) ) {
         SigmaDataUP_eta1->SetBinContent(i_Pt + 1, bin_content_eta1_UP);
         SigmaDataUP_eta1->SetBinError(i_Pt + 1, bin_error_eta1_UP);
      } 

      double bin_content_eta2_UP = SigmaData_eta2->GetBinContent(i_Pt + 1) + 0.5*TMath::Abs((FirstPointForExtrapol_eta2.at(i_Pt) - SigmaData_eta2->GetBinContent(i_Pt + 1)));
      double bin_error_eta2_UP =  TMath::Sqrt(pow(SigmaData_eta2->GetBinError(i_Pt + 1)/2,2) + pow(FirstPointForExtrapolError_eta2.at(i_Pt)/2,2));

      if ( SigmaData_eta2->GetBinContent(i_Pt + 1) ) {
         SigmaDataUP_eta2->SetBinContent(i_Pt + 1, bin_content_eta2_UP);
         SigmaDataUP_eta2->SetBinError(i_Pt + 1, bin_error_eta2_UP);
      } 

      double bin_content_eta3_UP = SigmaData_eta3->GetBinContent(i_Pt + 1) + 0.5*TMath::Abs((FirstPointForExtrapol_eta3.at(i_Pt) - SigmaData_eta3->GetBinContent(i_Pt + 1)));
      double bin_error_eta3_UP =  TMath::Sqrt(pow(SigmaData_eta3->GetBinError(i_Pt + 1)/2,2) + pow(FirstPointForExtrapolError_eta3.at(i_Pt)/2,2));

      if ( SigmaData_eta3->GetBinContent(i_Pt + 1) ) {
         SigmaDataUP_eta3->SetBinContent(i_Pt + 1, bin_content_eta3_UP);
         SigmaDataUP_eta3->SetBinError(i_Pt + 1, bin_error_eta3_UP);
      } 

      double bin_content_eta4_UP = SigmaData_eta4->GetBinContent(i_Pt + 1) + 0.5*TMath::Abs((FirstPointForExtrapol_eta4.at(i_Pt) - SigmaData_eta4->GetBinContent(i_Pt + 1)));
      double bin_error_eta4_UP =  TMath::Sqrt(pow(SigmaData_eta4->GetBinError(i_Pt + 1)/2,2) + pow(FirstPointForExtrapolError_eta4.at(i_Pt)/2,2));

      if ( SigmaData_eta4->GetBinContent(i_Pt + 1) ) {
         SigmaDataUP_eta4->SetBinContent(i_Pt + 1, bin_content_eta4_UP);
         SigmaDataUP_eta4->SetBinError(i_Pt + 1, bin_error_eta4_UP);
      } 

      // -------------------------------- //

      // fill lower variations
      double bin_content_eta0_DOWN = SigmaData_eta0->GetBinContent(i_Pt + 1) - 0.5*TMath::Abs((FirstPointForExtrapol_eta0.at(i_Pt) - SigmaData_eta0->GetBinContent(i_Pt + 1)));
      double bin_error_eta0_DOWN =  TMath::Sqrt(pow(SigmaData_eta0->GetBinError(i_Pt + 1)/2,2) + pow(FirstPointForExtrapolError_eta0.at(i_Pt)/2,2));

      if ( SigmaData_eta0->GetBinContent(i_Pt + 1) ) {
         SigmaDataDOWN_eta0->SetBinContent(i_Pt + 1, bin_content_eta0_DOWN);
         SigmaDataDOWN_eta0->SetBinError(i_Pt + 1, bin_error_eta0_DOWN);
      } 

      double bin_content_eta1_DOWN = SigmaData_eta1->GetBinContent(i_Pt + 1) - 0.5*TMath::Abs((FirstPointForExtrapol_eta1.at(i_Pt) - SigmaData_eta1->GetBinContent(i_Pt + 1)));
      double bin_error_eta1_DOWN =  TMath::Sqrt(pow(SigmaData_eta1->GetBinError(i_Pt + 1)/2,2) + pow(FirstPointForExtrapolError_eta1.at(i_Pt)/2,2));

      if ( SigmaData_eta1->GetBinContent(i_Pt + 1) ) {
         SigmaDataDOWN_eta1->SetBinContent(i_Pt + 1, bin_content_eta1_DOWN);
         SigmaDataDOWN_eta1->SetBinError(i_Pt + 1, bin_error_eta1_DOWN);
      } 

      double bin_content_eta2_DOWN = SigmaData_eta2->GetBinContent(i_Pt + 1) - 0.5*TMath::Abs((FirstPointForExtrapol_eta2.at(i_Pt) - SigmaData_eta2->GetBinContent(i_Pt + 1)));
      double bin_error_eta2_DOWN =  TMath::Sqrt(pow(SigmaData_eta2->GetBinError(i_Pt + 1)/2,2) + pow(FirstPointForExtrapolError_eta2.at(i_Pt)/2,2));

      if ( SigmaData_eta2->GetBinContent(i_Pt + 1) ) {
         SigmaDataDOWN_eta2->SetBinContent(i_Pt + 1, bin_content_eta2_DOWN);
         SigmaDataDOWN_eta2->SetBinError(i_Pt + 1, bin_error_eta2_DOWN);
      } 

      double bin_content_eta3_DOWN = SigmaData_eta3->GetBinContent(i_Pt + 1) - 0.5*TMath::Abs((FirstPointForExtrapol_eta3.at(i_Pt) - SigmaData_eta3->GetBinContent(i_Pt + 1)));
      double bin_error_eta3_DOWN =  TMath::Sqrt(pow(SigmaData_eta3->GetBinError(i_Pt + 1)/2,2) + pow(FirstPointForExtrapolError_eta3.at(i_Pt)/2,2));

      if ( SigmaData_eta3->GetBinContent(i_Pt + 1) ) {
         SigmaDataDOWN_eta3->SetBinContent(i_Pt + 1, bin_content_eta3_DOWN);
         SigmaDataDOWN_eta3->SetBinError(i_Pt + 1, bin_error_eta3_DOWN);
      } 

      double bin_content_eta4_DOWN = SigmaData_eta4->GetBinContent(i_Pt + 1) - 0.5*TMath::Abs((FirstPointForExtrapol_eta4.at(i_Pt) - SigmaData_eta4->GetBinContent(i_Pt + 1)));
      double bin_error_eta4_DOWN =  TMath::Sqrt(pow(SigmaData_eta4->GetBinError(i_Pt + 1)/2,2) + pow(FirstPointForExtrapolError_eta4.at(i_Pt)/2,2));

      if ( SigmaData_eta4->GetBinContent(i_Pt + 1) ) {
         SigmaDataDOWN_eta4->SetBinContent(i_Pt + 1, bin_content_eta4_DOWN);
         SigmaDataDOWN_eta4->SetBinError(i_Pt + 1, bin_error_eta4_DOWN);
      } 
   }
   /*
   TCanvas *c = new TCanvas();
   c->SetLogx();
   SigmaData_eta0->Draw();
   SigmaDataUP_eta0->SetMarkerStyle(20);
   SigmaDataUP_eta0->SetMarkerColor(kRed);
   SigmaDataUP_eta0->Draw("same");
   SigmaDataDOWN_eta0->SetMarkerStyle(20);
   SigmaDataDOWN_eta0->SetMarkerColor(kBlue);
   SigmaDataDOWN_eta0->Draw("same");

   TCanvas *c2 = new TCanvas();
   c2->SetLogx();
   SigmaData_eta1->Draw();
   SigmaDataUP_eta1->SetMarkerStyle(20);
   SigmaDataUP_eta1->SetMarkerColor(kRed);
   SigmaDataUP_eta1->Draw("same");
   SigmaDataDOWN_eta1->SetMarkerStyle(20);
   SigmaDataDOWN_eta1->SetMarkerColor(kBlue);
   SigmaDataDOWN_eta1->Draw("same");

   TCanvas *c3 = new TCanvas();
   c3->SetLogx();
   SigmaData_eta2->Draw();
   SigmaDataUP_eta2->SetMarkerStyle(20);
   SigmaDataUP_eta2->SetMarkerColor(kRed);
   SigmaDataUP_eta2->Draw("same");
   SigmaDataDOWN_eta2->SetMarkerStyle(20);
   SigmaDataDOWN_eta2->SetMarkerColor(kBlue);
   SigmaDataDOWN_eta2->Draw("same");

   TCanvas *c4 = new TCanvas();
   c4->SetLogx();
   SigmaData_eta3->Draw();
   SigmaDataUP_eta3->SetMarkerStyle(20);
   SigmaDataUP_eta3->SetMarkerColor(kRed);
   SigmaDataUP_eta3->Draw("same");
   SigmaDataDOWN_eta3->SetMarkerStyle(20);
   SigmaDataDOWN_eta3->SetMarkerColor(kBlue);
   SigmaDataDOWN_eta3->Draw("same");

   TCanvas *c5 = new TCanvas();
   c5->SetLogx();
   SigmaData_eta4->Draw();
   SigmaDataUP_eta4->SetMarkerStyle(20);
   SigmaDataUP_eta4->SetMarkerColor(kRed);
   SigmaDataUP_eta4->Draw("same");
   SigmaDataDOWN_eta4->SetMarkerStyle(20);
   SigmaDataDOWN_eta4->SetMarkerColor(kBlue);
   SigmaDataDOWN_eta4->Draw("same");
   */
   // ------------------------------------------------------------------ //
   
   vector<TH1D*> SigmaDataUP;
   SigmaDataUP.push_back(SigmaDataUP_eta0);
   SigmaDataUP.push_back(SigmaDataUP_eta1);
   SigmaDataUP.push_back(SigmaDataUP_eta2);
   SigmaDataUP.push_back(SigmaDataUP_eta3);
   SigmaDataUP.push_back(SigmaDataUP_eta4);

   vector<TH1D*> SigmaDataDOWN;
   SigmaDataDOWN.push_back(SigmaDataDOWN_eta0);
   SigmaDataDOWN.push_back(SigmaDataDOWN_eta1);
   SigmaDataDOWN.push_back(SigmaDataDOWN_eta2);
   SigmaDataDOWN.push_back(SigmaDataDOWN_eta3);
   SigmaDataDOWN.push_back(SigmaDataDOWN_eta4);

   // ------------------------------------------------------------------ //
   
   // define helper histos
   TH1D* GenSigma_eta0_squared = new TH1D(*GenSigma_eta0);
   TH1D* GenSigma_eta1_squared = new TH1D(*GenSigma_eta1);
   TH1D* GenSigma_eta2_squared = new TH1D(*GenSigma_eta2);
   TH1D* GenSigma_eta3_squared = new TH1D(*GenSigma_eta3);
   TH1D* GenSigma_eta4_squared = new TH1D(*GenSigma_eta4);
  
   vector<TH1D*> GenSigma_squared;
   GenSigma_squared.push_back(GenSigma_eta0_squared);
   GenSigma_squared.push_back(GenSigma_eta1_squared);
   GenSigma_squared.push_back(GenSigma_eta2_squared);
   GenSigma_squared.push_back(GenSigma_eta3_squared);
   GenSigma_squared.push_back(GenSigma_eta4_squared);

   // ----------------------------------------------- //

   TH1D* SigmaMC_eta0_squared = new TH1D(*SigmaMC_eta0);
   TH1D* SigmaMC_eta1_squared = new TH1D(*SigmaMC_eta1);
   TH1D* SigmaMC_eta2_squared = new TH1D(*SigmaMC_eta2);
   TH1D* SigmaMC_eta3_squared = new TH1D(*SigmaMC_eta3);
   TH1D* SigmaMC_eta4_squared = new TH1D(*SigmaMC_eta4);

   vector<TH1D*> SigmaMC_squared;
   SigmaMC_squared.push_back(SigmaMC_eta0_squared);
   SigmaMC_squared.push_back(SigmaMC_eta1_squared);
   SigmaMC_squared.push_back(SigmaMC_eta2_squared);
   SigmaMC_squared.push_back(SigmaMC_eta3_squared);
   SigmaMC_squared.push_back(SigmaMC_eta4_squared);

   TH1D* corrected_SigmaMC_eta0_squared = new TH1D(*SigmaMC_eta0);
   TH1D* corrected_SigmaMC_eta1_squared = new TH1D(*SigmaMC_eta1);
   TH1D* corrected_SigmaMC_eta2_squared = new TH1D(*SigmaMC_eta2);
   TH1D* corrected_SigmaMC_eta3_squared = new TH1D(*SigmaMC_eta3);
   TH1D* corrected_SigmaMC_eta4_squared = new TH1D(*SigmaMC_eta4);

   vector<TH1D*> corrected_SigmaMC_squared;
   corrected_SigmaMC_squared.push_back(corrected_SigmaMC_eta0_squared);
   corrected_SigmaMC_squared.push_back(corrected_SigmaMC_eta1_squared);
   corrected_SigmaMC_squared.push_back(corrected_SigmaMC_eta2_squared);
   corrected_SigmaMC_squared.push_back(corrected_SigmaMC_eta3_squared);
   corrected_SigmaMC_squared.push_back(corrected_SigmaMC_eta4_squared);

   // ----------------------------------------------- //

   TH1D* SigmaDataUP_eta0_squared = new TH1D(*SigmaData_eta0);
   TH1D* SigmaDataUP_eta1_squared = new TH1D(*SigmaData_eta1);
   TH1D* SigmaDataUP_eta2_squared = new TH1D(*SigmaData_eta2);
   TH1D* SigmaDataUP_eta3_squared = new TH1D(*SigmaData_eta3);
   TH1D* SigmaDataUP_eta4_squared = new TH1D(*SigmaData_eta4);

   vector<TH1D*> SigmaDataUP_squared;
   SigmaDataUP_squared.push_back(SigmaDataUP_eta0_squared);
   SigmaDataUP_squared.push_back(SigmaDataUP_eta1_squared);
   SigmaDataUP_squared.push_back(SigmaDataUP_eta2_squared);
   SigmaDataUP_squared.push_back(SigmaDataUP_eta3_squared);
   SigmaDataUP_squared.push_back(SigmaDataUP_eta4_squared);

   TH1D* corrected_SigmaDataUP_eta0_squared = new TH1D(*SigmaData_eta0);
   TH1D* corrected_SigmaDataUP_eta1_squared = new TH1D(*SigmaData_eta1);
   TH1D* corrected_SigmaDataUP_eta2_squared = new TH1D(*SigmaData_eta2);
   TH1D* corrected_SigmaDataUP_eta3_squared = new TH1D(*SigmaData_eta3);
   TH1D* corrected_SigmaDataUP_eta4_squared = new TH1D(*SigmaData_eta4);

   vector<TH1D*> corrected_SigmaDataUP_squared;
   corrected_SigmaDataUP_squared.push_back(corrected_SigmaDataUP_eta0_squared);
   corrected_SigmaDataUP_squared.push_back(corrected_SigmaDataUP_eta1_squared);
   corrected_SigmaDataUP_squared.push_back(corrected_SigmaDataUP_eta2_squared);
   corrected_SigmaDataUP_squared.push_back(corrected_SigmaDataUP_eta3_squared);
   corrected_SigmaDataUP_squared.push_back(corrected_SigmaDataUP_eta4_squared);

   // ----------------------------------------------- //

   TH1D* SigmaDataDOWN_eta0_squared = new TH1D(*SigmaData_eta0);
   TH1D* SigmaDataDOWN_eta1_squared = new TH1D(*SigmaData_eta1);
   TH1D* SigmaDataDOWN_eta2_squared = new TH1D(*SigmaData_eta2);
   TH1D* SigmaDataDOWN_eta3_squared = new TH1D(*SigmaData_eta3);
   TH1D* SigmaDataDOWN_eta4_squared = new TH1D(*SigmaData_eta4);

   vector<TH1D*> SigmaDataDOWN_squared;
   SigmaDataDOWN_squared.push_back(SigmaDataDOWN_eta0_squared);
   SigmaDataDOWN_squared.push_back(SigmaDataDOWN_eta1_squared);
   SigmaDataDOWN_squared.push_back(SigmaDataDOWN_eta2_squared);
   SigmaDataDOWN_squared.push_back(SigmaDataDOWN_eta3_squared);
   SigmaDataDOWN_squared.push_back(SigmaDataDOWN_eta4_squared);

   TH1D* corrected_SigmaDataDOWN_eta0_squared = new TH1D(*SigmaData_eta0);
   TH1D* corrected_SigmaDataDOWN_eta1_squared = new TH1D(*SigmaData_eta1);
   TH1D* corrected_SigmaDataDOWN_eta2_squared = new TH1D(*SigmaData_eta2);
   TH1D* corrected_SigmaDataDOWN_eta3_squared = new TH1D(*SigmaData_eta3);
   TH1D* corrected_SigmaDataDOWN_eta4_squared = new TH1D(*SigmaData_eta4);

   vector<TH1D*> corrected_SigmaDataDOWN_squared;
   corrected_SigmaDataDOWN_squared.push_back(corrected_SigmaDataDOWN_eta0_squared);
   corrected_SigmaDataDOWN_squared.push_back(corrected_SigmaDataDOWN_eta1_squared);
   corrected_SigmaDataDOWN_squared.push_back(corrected_SigmaDataDOWN_eta2_squared);
   corrected_SigmaDataDOWN_squared.push_back(corrected_SigmaDataDOWN_eta3_squared);
   corrected_SigmaDataDOWN_squared.push_back(corrected_SigmaDataDOWN_eta4_squared);

   // ------------------------------------------------------------------ //
   
   // final corrected sigma histos
   TH1D* corrected_SigmaDataUP_eta0 = new TH1D(*SigmaData_eta0);
   TH1D* corrected_SigmaDataUP_eta1 = new TH1D(*SigmaData_eta1);
   TH1D* corrected_SigmaDataUP_eta2 = new TH1D(*SigmaData_eta2);
   TH1D* corrected_SigmaDataUP_eta3 = new TH1D(*SigmaData_eta3);
   TH1D* corrected_SigmaDataUP_eta4 = new TH1D(*SigmaData_eta4);

   vector<TH1D*> corrected_SigmaDataUP;
   corrected_SigmaDataUP.push_back(corrected_SigmaDataUP_eta0);
   corrected_SigmaDataUP.push_back(corrected_SigmaDataUP_eta1);
   corrected_SigmaDataUP.push_back(corrected_SigmaDataUP_eta2);
   corrected_SigmaDataUP.push_back(corrected_SigmaDataUP_eta3);
   corrected_SigmaDataUP.push_back(corrected_SigmaDataUP_eta4);

   TH1D* corrected_SigmaDataDOWN_eta0 = new TH1D(*SigmaData_eta0);
   TH1D* corrected_SigmaDataDOWN_eta1 = new TH1D(*SigmaData_eta1);
   TH1D* corrected_SigmaDataDOWN_eta2 = new TH1D(*SigmaData_eta2);
   TH1D* corrected_SigmaDataDOWN_eta3 = new TH1D(*SigmaData_eta3);
   TH1D* corrected_SigmaDataDOWN_eta4 = new TH1D(*SigmaData_eta4);

   vector<TH1D*> corrected_SigmaDataDOWN;
   corrected_SigmaDataDOWN.push_back(corrected_SigmaDataDOWN_eta0);
   corrected_SigmaDataDOWN.push_back(corrected_SigmaDataDOWN_eta1);
   corrected_SigmaDataDOWN.push_back(corrected_SigmaDataDOWN_eta2);
   corrected_SigmaDataDOWN.push_back(corrected_SigmaDataDOWN_eta3);
   corrected_SigmaDataDOWN.push_back(corrected_SigmaDataDOWN_eta4);

   TH1D* corrected_SigmaMC_eta0 = new TH1D(*SigmaMC_eta0);
   TH1D* corrected_SigmaMC_eta1 = new TH1D(*SigmaMC_eta1);
   TH1D* corrected_SigmaMC_eta2 = new TH1D(*SigmaMC_eta2);
   TH1D* corrected_SigmaMC_eta3 = new TH1D(*SigmaMC_eta3);
   TH1D* corrected_SigmaMC_eta4 = new TH1D(*SigmaMC_eta4);

   vector<TH1D*> corrected_SigmaMC;
   corrected_SigmaMC.push_back(corrected_SigmaMC_eta0);
   corrected_SigmaMC.push_back(corrected_SigmaMC_eta1);
   corrected_SigmaMC.push_back(corrected_SigmaMC_eta2);
   corrected_SigmaMC.push_back(corrected_SigmaMC_eta3);
   corrected_SigmaMC.push_back(corrected_SigmaMC_eta4);

   // ------------------------------------------------------------------ //

   // calc corrected histos
   for( int i = 0; i < corrected_SigmaMC.size(); i++) {
      GenSigma_squared.at(i)->Reset();
      SigmaDataUP_squared.at(i)->Reset();
      SigmaDataDOWN_squared.at(i)->Reset();
      SigmaMC_squared.at(i)->Reset();
      corrected_SigmaDataUP_squared.at(i)->Reset();
      corrected_SigmaDataDOWN_squared.at(i)->Reset();
      corrected_SigmaDataUP.at(i)->Reset();
      corrected_SigmaDataDOWN.at(i)->Reset();
      corrected_SigmaMC_squared.at(i)->Reset();
      corrected_SigmaMC.at(i)->Reset();

      GenSigma_squared.at(i)->Multiply(GenSigma.at(i), GenSigma.at(i), 1, 1); 
      SigmaDataUP_squared.at(i)->Multiply(SigmaDataUP.at(i), SigmaDataUP.at(i), 1, 1);
      SigmaDataDOWN_squared.at(i)->Multiply(SigmaDataDOWN.at(i), SigmaDataDOWN.at(i), 1, 1);
      SigmaMC_squared.at(i)->Multiply(SigmaMC.at(i), SigmaMC.at(i), 1, 1);

      corrected_SigmaDataUP_squared.at(i)->Add(SigmaDataUP_squared.at(i), 1);
      corrected_SigmaDataDOWN_squared.at(i)->Add(SigmaDataDOWN_squared.at(i), 1);
      corrected_SigmaDataUP_squared.at(i)->Add(GenSigma_squared.at(i), -1);
      corrected_SigmaDataDOWN_squared.at(i)->Add(GenSigma_squared.at(i), -1);

      corrected_SigmaMC_squared.at(i)->Add(SigmaMC_squared.at(i), 1);
      corrected_SigmaMC_squared.at(i)->Add(GenSigma_squared.at(i), -1);

      double bin_content_dataUP = 0;
      double bin_error_dataUP = 0;
      for( int j = 1; j < corrected_SigmaDataUP_squared.at(i)->GetNbinsX()+1; j++) {
         bin_content_dataUP = corrected_SigmaDataUP_squared.at(i)->GetBinContent(j);
         bin_error_dataUP = corrected_SigmaDataUP_squared.at(i)->GetBinError(j);
         if (bin_content_dataUP > 0) {
            corrected_SigmaDataUP.at(i)->SetBinContent(j, TMath::Sqrt(bin_content_dataUP));
            corrected_SigmaDataUP.at(i)->SetBinError(j, 1/(2*TMath::Sqrt(bin_content_dataUP))*bin_error_dataUP);
         }
      }

      double bin_content_dataDOWN = 0;
      double bin_error_dataDOWN = 0;
      for( int j = 1; j < corrected_SigmaDataDOWN_squared.at(i)->GetNbinsX()+1; j++) {
         bin_content_dataDOWN = corrected_SigmaDataDOWN_squared.at(i)->GetBinContent(j);
         bin_error_dataDOWN = corrected_SigmaDataDOWN_squared.at(i)->GetBinError(j);
         if (bin_content_dataDOWN > 0) {
            corrected_SigmaDataDOWN.at(i)->SetBinContent(j, TMath::Sqrt(bin_content_dataDOWN));
            corrected_SigmaDataDOWN.at(i)->SetBinError(j, 1/(2*TMath::Sqrt(bin_content_dataDOWN))*bin_error_dataDOWN);
         }
      }

      double bin_content_mc = 0;
      double bin_error_mc = 0;
      for( int j = 1; j < corrected_SigmaMC_squared.at(i)->GetNbinsX()+1; j++) {
         bin_content_mc = corrected_SigmaMC_squared.at(i)->GetBinContent(j);
         bin_error_mc = corrected_SigmaMC_squared.at(i)->GetBinError(j);
         if (bin_content_mc > 0) {
            corrected_SigmaMC.at(i)->SetBinContent(j, TMath::Sqrt(bin_content_mc));
            corrected_SigmaMC.at(i)->SetBinError(j, 1/(2*TMath::Sqrt(bin_content_mc))*bin_error_mc);
         }
      }
   }

   TCanvas *c = new TCanvas();
   c->SetLogx();
   //  corrected_SigmaData_eta0->Draw();
   corrected_SigmaDataUP_eta0->SetMarkerStyle(20);
   corrected_SigmaDataUP_eta0->SetMarkerColor(kRed);
   corrected_SigmaDataUP_eta0->Draw();
   corrected_SigmaDataDOWN_eta0->SetMarkerStyle(20);
   corrected_SigmaDataDOWN_eta0->SetMarkerColor(kBlue);
   corrected_SigmaDataDOWN_eta0->Draw("same");

   TCanvas *c2 = new TCanvas();
   c2->SetLogx();
   // corrected_SigmaData_eta1->Draw();
   corrected_SigmaDataUP_eta1->SetMarkerStyle(20);
   corrected_SigmaDataUP_eta1->SetMarkerColor(kRed);
   corrected_SigmaDataUP_eta1->Draw();
   corrected_SigmaDataDOWN_eta1->SetMarkerStyle(20);
   corrected_SigmaDataDOWN_eta1->SetMarkerColor(kBlue);
   corrected_SigmaDataDOWN_eta1->Draw("same");

   TCanvas *c3 = new TCanvas();
   c3->SetLogx();
   // corrected_SigmaData_eta2->Draw();
   corrected_SigmaDataUP_eta2->SetMarkerStyle(20);
   corrected_SigmaDataUP_eta2->SetMarkerColor(kRed);
   corrected_SigmaDataUP_eta2->Draw();
   corrected_SigmaDataDOWN_eta2->SetMarkerStyle(20);
   corrected_SigmaDataDOWN_eta2->SetMarkerColor(kBlue);
   corrected_SigmaDataDOWN_eta2->Draw("same");

   TCanvas *c4 = new TCanvas();
   c4->SetLogx();
   // corrected_SigmaData_eta3->Draw();
   corrected_SigmaDataUP_eta3->SetMarkerStyle(20);
   corrected_SigmaDataUP_eta3->SetMarkerColor(kRed);
   corrected_SigmaDataUP_eta3->Draw();
   corrected_SigmaDataDOWN_eta3->SetMarkerStyle(20);
   corrected_SigmaDataDOWN_eta3->SetMarkerColor(kBlue);
   corrected_SigmaDataDOWN_eta3->Draw("same");

   TCanvas *c5 = new TCanvas();
   c5->SetLogx();
   // corrected_SigmaData_eta4->Draw();
   corrected_SigmaDataUP_eta4->SetMarkerStyle(20);
   corrected_SigmaDataUP_eta4->SetMarkerColor(kRed);
   corrected_SigmaDataUP_eta4->Draw();
   corrected_SigmaDataDOWN_eta4->SetMarkerStyle(20);
   corrected_SigmaDataDOWN_eta4->SetMarkerColor(kBlue);
   corrected_SigmaDataDOWN_eta4->Draw("same");

   // ------------------------------------------------------------------ //

   // define/get ratio histos
   vector<TH1D*> DataMCRatiosUP;
   vector<TH1D*> DataMCRatiosDOWN;

   double xBins[6] = {0, 0.5, 1.1, 1.7, 2.3, 5.2};
   TH1D* RatioVsEtaUP = new TH1D("RatioVsEtaUP", "", 5, xBins);
   TH1D* RatioVsEtaDOWN = new TH1D("RatioVsEtaDOWN", "", 5, xBins);

   for( int i = 0; i < corrected_SigmaDataUP.size(); i++) {
      TH1D* ratio = (TH1D*) (SigmaMC_eta0->Clone());
      ratio->Divide(corrected_SigmaDataUP.at(i), corrected_SigmaMC.at(i));
    
      TF1 *fit_const = new TF1("fit_const", "[0]", ratio->GetXaxis()->GetXmin(), ratio->GetXaxis()->GetXmax());
      fit_const->SetParameters(1, 1);
      fit_const->SetParName(0, "const");
      ratio->Fit("fit_const", "EM", "same");
      ratio->GetYaxis()->SetTitle("Data/MC ratio (const fit)");

      DataMCRatiosUP.push_back(ratio);

      RatioVsEtaUP->SetBinContent(i+1, ratio->GetFunction("fit_const")->GetParameter(0));
      RatioVsEtaUP->SetBinError(i+1, ratio->GetFunction("fit_const")->GetParError(0));
   }

   for( int i = 0; i < corrected_SigmaDataDOWN.size(); i++) {
      TH1D* ratio = (TH1D*) (SigmaMC_eta0->Clone());
      ratio->Divide(corrected_SigmaDataDOWN.at(i), corrected_SigmaMC.at(i));
    
      TF1 *fit_const = new TF1("fit_const", "[0]", ratio->GetXaxis()->GetXmin(), ratio->GetXaxis()->GetXmax());
      fit_const->SetParameters(1, 1);
      fit_const->SetParName(0, "const");
      ratio->Fit("fit_const", "EM", "same");
      ratio->GetYaxis()->SetTitle("Data/MC ratio (const fit)");

      DataMCRatiosDOWN.push_back(ratio);

      RatioVsEtaDOWN->SetBinContent(i+1, ratio->GetFunction("fit_const")->GetParameter(0));
      RatioVsEtaDOWN->SetBinError(i+1, ratio->GetFunction("fit_const")->GetParError(0));
   }

   // ------------------------------------------------------------------ //

   /*
   TCanvas *test = new TCanvas();
   test->SetLogx();
   SigmaData_eta1->GetYaxis()->SetRangeUser(0.000001, 0.3);
   SigmaData_eta1->Draw();
   SigmaDataUP_eta1->SetMarkerColor(kPink);
   SigmaDataUP_eta1->Draw();
   corrected_SigmaDataUP_eta1->SetMarkerColor(kBlue);
   corrected_SigmaDataUP_eta1->Draw("same");
   corrected_SigmaMC_eta1->SetMarkerColor(kOrange);
   corrected_SigmaMC_eta1->Draw("same");
   SigmaMC_eta1->SetMarkerColor(kGreen);
   SigmaMC_eta1->Draw("same");
   GenSigma_eta0->SetMarkerColor(kGreen);
   GenSigma_eta0->Draw("same");
   */
   
   TCanvas *a1 = new TCanvas();
   DataMCRatiosUP.at(0)->Draw();
   DataMCRatiosDOWN.at(0)->SetMarkerColor(kBlue);
   DataMCRatiosDOWN.at(0)->Draw("same");

   TCanvas *a2 = new TCanvas();
   DataMCRatiosUP.at(1)->Draw();
   DataMCRatiosDOWN.at(1)->SetMarkerColor(kBlue);
   DataMCRatiosDOWN.at(1)->Draw("same");

   TCanvas *a3 = new TCanvas();
   DataMCRatiosUP.at(2)->Draw();
   DataMCRatiosDOWN.at(2)->SetMarkerColor(kBlue);
   DataMCRatiosDOWN.at(2)->Draw("same");

   TCanvas *a4 = new TCanvas();
   DataMCRatiosUP.at(3)->Draw();
   DataMCRatiosDOWN.at(3)->SetMarkerColor(kBlue);
   DataMCRatiosDOWN.at(3)->Draw("same");

   TCanvas *a5 = new TCanvas();
   DataMCRatiosUP.at(4)->Draw();
   DataMCRatiosDOWN.at(4)->SetMarkerColor(kBlue);
   DataMCRatiosDOWN.at(4)->Draw("same");


   TCanvas *c10 = new TCanvas("c", "c");
   RatioVsEtaUP->GetYaxis()->SetRangeUser(0.7, 1.7);
   RatioVsEtaUP->Draw();

   TCanvas *c11 = new TCanvas("c2", "c2");
   RatioVsEtaDOWN->GetYaxis()->SetRangeUser(0.7, 1.7);
   RatioVsEtaDOWN->Draw();

   TString outfile = "JER_RatioVsEta_WithExtrapolUnc_" + AsymmWidth + ".root";

   TFile* output = new TFile(outfile, "RECREATE");
   RatioVsEtaUP->Write();
   RatioVsEtaDOWN->Write();

   output->Write();
   
}
