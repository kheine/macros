#include "/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/scripts/tdrstyle_mod.C"
#include <TROOT.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

void PlotJERWithPLIConsidered()
{
   setTDRStyle();

   gStyle->SetNdivisions(505, "Y");
   gROOT->ForceStyle();

   // define which asymm width definition was used
   //TString AsymmWidth = "GaussFitWidth";
   //TString AsymmWidth = "TruncatedRMS";
   TString AsymmWidth = "StandardDeviation";

   //TString InfoText = "InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation_";
   //TString InfoText = "InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation_ComparedToGaussFit_";
   TString InfoText = "InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation_ComparedToGaussFit_RatioClosure";
 
   // TFile* Asymmetry_file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/2013_09_04_plots_TruncatedRMS_InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation/OutputResolutions2012.root", "READ");

   // TFile* Asymmetry_file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/2013_09_04_plots_StandardDeviation_InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation/OutputResolutions2012.root", "READ");

   // TFile* GenAsymmetry_file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/2013_09_04_plots_TruncatedRMS_InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation_Gen/OutputResolutions2012.root", "READ");

   // TFile* GenAsymmetry_file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/2013_09_04_plots_StandardDeviation_InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation_Gen/OutputResolutions2012.root", "READ");

   //TFile* TruthResolution_file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/20132013ABCD_ReReco_CORR2013SummerV1_AK5_MC_Su12Z253_kostas_ChangeAlphaRangeMoreFitPoints_v3/dijetsFall10_TuneZ2_AK5PF_weighted_residuals_JERMatt/plots/KalibriPlots.root", "READ");

   // ------------------------------------------------------------------ //

   // closure test files
   // TFile* Asymmetry_file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/2013_09_04_plots_TruncatedRMS_InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation_RatioClosure/OutputResolutions2012.root", "READ");
   TFile* Asymmetry_file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/2013_09_04_plots_StandardDeviation_InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation_RatioClosure/OutputResolutions2012.root", "READ");

   //TFile* GenAsymmetry_file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/2013_09_04_plots_TruncatedRMS_InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation_RatioClosure_Gen/OutputResolutions2012.root", "READ");
   TFile* GenAsymmetry_file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/L2andJERScripts/2013_09_04_plots_StandardDeviation_InclusiveAlpha_ReducedAlphaRangeMoreFitPoints_WithCorrelation_RatioClosure_Gen/OutputResolutions2012.root", "READ");

   TFile* TruthResolution_file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/MC2012Z253_CORR2013SummerV1_AK5_MC_Su12Z253_kostas_RatioClosure_v2/dijetsFall10_TuneZ2_AK5PF_weighted_residuals_JERMatt/plots/KalibriPlots.root", "READ");
  

   // define histos
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

   TH1D* TruthSigma_eta0;
   TH1D* TruthSigma_eta1;
   TH1D* TruthSigma_eta2;
   TH1D* TruthSigma_eta3;
   TH1D* TruthSigma_eta4; 

   // define scale factor for PLI correction --> can be used for systematic variation
   double PLI_scale = 1.0; // 0.75, 1.0 or 1.25

   // ------------------------------------------------------------------ //

   // get histos from file
   Asymmetry_file->cd("AbsAsymmetryVsPt10;1");
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

   TruthResolution_file->cd("MCTruthResponseVsPt25;1");
   gDirectory->GetObject("MCTruthResponseVsPt25_MCTruthResponseVsMeanPt_MC_L2L3_AbsEta0_GaussFitWidth", TruthSigma_eta0);
   gDirectory->GetObject("MCTruthResponseVsPt25_MCTruthResponseVsMeanPt_MC_L2L3_AbsEta1_GaussFitWidth", TruthSigma_eta1);
   gDirectory->GetObject("MCTruthResponseVsPt25_MCTruthResponseVsMeanPt_MC_L2L3_AbsEta2_GaussFitWidth", TruthSigma_eta2);
   gDirectory->GetObject("MCTruthResponseVsPt25_MCTruthResponseVsMeanPt_MC_L2L3_AbsEta3_GaussFitWidth", TruthSigma_eta3);
   gDirectory->GetObject("MCTruthResponseVsPt25_MCTruthResponseVsMeanPt_MC_L2L3_AbsEta4_GaussFitWidth", TruthSigma_eta4);

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

   // ------------------------------------------------------------------ //

   // scale GenHistos with chosen PLI scale factor
   GenSigma_eta0->Scale(PLI_scale);
   GenSigma_eta1->Scale(PLI_scale);
   GenSigma_eta2->Scale(PLI_scale);
   GenSigma_eta3->Scale(PLI_scale);
   GenSigma_eta4->Scale(PLI_scale);

   // ------------------------------------------------------------------ //

   // fill vectors with histos
   vector<TH1D*> GenSigma;
   GenSigma.push_back(GenSigma_eta0);
   GenSigma.push_back(GenSigma_eta1);
   GenSigma.push_back(GenSigma_eta2);
   GenSigma.push_back(GenSigma_eta3);
   GenSigma.push_back(GenSigma_eta4);

   vector<TH1D*> SigmaData;
   SigmaData.push_back(SigmaData_eta0);
   SigmaData.push_back(SigmaData_eta1);
   SigmaData.push_back(SigmaData_eta2);
   SigmaData.push_back(SigmaData_eta3);
   SigmaData.push_back(SigmaData_eta4);

   vector<TH1D*> SigmaMC;
   SigmaMC.push_back(SigmaMC_eta0);
   SigmaMC.push_back(SigmaMC_eta1);
   SigmaMC.push_back(SigmaMC_eta2);
   SigmaMC.push_back(SigmaMC_eta3);
   SigmaMC.push_back(SigmaMC_eta4);

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

   TH1D* SigmaData_eta0_squared = new TH1D(*SigmaData_eta0);
   TH1D* SigmaData_eta1_squared = new TH1D(*SigmaData_eta1);
   TH1D* SigmaData_eta2_squared = new TH1D(*SigmaData_eta2);
   TH1D* SigmaData_eta3_squared = new TH1D(*SigmaData_eta3);
   TH1D* SigmaData_eta4_squared = new TH1D(*SigmaData_eta4);

   vector<TH1D*> SigmaData_squared;
   SigmaData_squared.push_back(SigmaData_eta0_squared);
   SigmaData_squared.push_back(SigmaData_eta1_squared);
   SigmaData_squared.push_back(SigmaData_eta2_squared);
   SigmaData_squared.push_back(SigmaData_eta3_squared);
   SigmaData_squared.push_back(SigmaData_eta4_squared);

   TH1D* corrected_SigmaData_eta0_squared = new TH1D(*SigmaData_eta0);
   TH1D* corrected_SigmaData_eta1_squared = new TH1D(*SigmaData_eta1);
   TH1D* corrected_SigmaData_eta2_squared = new TH1D(*SigmaData_eta2);
   TH1D* corrected_SigmaData_eta3_squared = new TH1D(*SigmaData_eta3);
   TH1D* corrected_SigmaData_eta4_squared = new TH1D(*SigmaData_eta4);

   vector<TH1D*> corrected_SigmaData_squared;
   corrected_SigmaData_squared.push_back(corrected_SigmaData_eta0_squared);
   corrected_SigmaData_squared.push_back(corrected_SigmaData_eta1_squared);
   corrected_SigmaData_squared.push_back(corrected_SigmaData_eta2_squared);
   corrected_SigmaData_squared.push_back(corrected_SigmaData_eta3_squared);
   corrected_SigmaData_squared.push_back(corrected_SigmaData_eta4_squared);

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

   // ------------------------------------------------------------------ //

   // final corrected sigma histos
   TH1D* corrected_SigmaData_eta0 = new TH1D(*SigmaData_eta0);
   TH1D* corrected_SigmaData_eta1 = new TH1D(*SigmaData_eta1);
   TH1D* corrected_SigmaData_eta2 = new TH1D(*SigmaData_eta2);
   TH1D* corrected_SigmaData_eta3 = new TH1D(*SigmaData_eta3);
   TH1D* corrected_SigmaData_eta4 = new TH1D(*SigmaData_eta4);

   vector<TH1D*> corrected_SigmaData;
   corrected_SigmaData.push_back(corrected_SigmaData_eta0);
   corrected_SigmaData.push_back(corrected_SigmaData_eta1);
   corrected_SigmaData.push_back(corrected_SigmaData_eta2);
   corrected_SigmaData.push_back(corrected_SigmaData_eta3);
   corrected_SigmaData.push_back(corrected_SigmaData_eta4);

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
   for( int i = 0; i < corrected_SigmaData.size(); i++) {
      GenSigma_squared.at(i)->Reset();
      SigmaData_squared.at(i)->Reset();
      SigmaMC_squared.at(i)->Reset();
      corrected_SigmaData_squared.at(i)->Reset();
      corrected_SigmaData.at(i)->Reset();
      corrected_SigmaMC_squared.at(i)->Reset();
      corrected_SigmaMC.at(i)->Reset();

      GenSigma_squared.at(i)->Multiply(GenSigma.at(i), GenSigma.at(i), 1, 1); 
      SigmaData_squared.at(i)->Multiply(SigmaData.at(i), SigmaData.at(i), 1, 1);
      SigmaMC_squared.at(i)->Multiply(SigmaMC.at(i), SigmaMC.at(i), 1, 1);

      corrected_SigmaData_squared.at(i)->Add(SigmaData_squared.at(i), 1);
      corrected_SigmaData_squared.at(i)->Add(GenSigma_squared.at(i), -1);

      corrected_SigmaMC_squared.at(i)->Add(SigmaMC_squared.at(i), 1);
      corrected_SigmaMC_squared.at(i)->Add(GenSigma_squared.at(i), -1);


      double bin_content_data = 0;
      double bin_error_data = 0;
      for( int j = 1; j < corrected_SigmaData_squared.at(i)->GetNbinsX()+1; j++) {
         bin_content_data = corrected_SigmaData_squared.at(i)->GetBinContent(j);
         bin_error_data = corrected_SigmaData_squared.at(i)->GetBinError(j);
       
         if (bin_content_data > 0) {
            corrected_SigmaData.at(i)->SetBinContent(j, TMath::Sqrt(bin_content_data));
            corrected_SigmaData.at(i)->SetBinError(j, (1/(2*TMath::Sqrt(bin_content_data)))*bin_error_data);
          
         }
      }

      double bin_content_mc = 0;
      double bin_error_mc = 0;
      for( int j = 1; j < corrected_SigmaMC_squared.at(i)->GetNbinsX()+1; j++) {
         bin_content_mc = corrected_SigmaMC_squared.at(i)->GetBinContent(j);
         bin_error_mc = corrected_SigmaMC_squared.at(i)->GetBinError(j);

         if (bin_content_mc > 0) {
            corrected_SigmaMC.at(i)->SetBinContent(j, TMath::Sqrt(bin_content_mc));
            corrected_SigmaMC.at(i)->SetBinError(j, (1/(2*TMath::Sqrt(bin_content_mc)))*bin_error_mc);
         }
      }
   }


   // ------------------------------------------------------------------ //

   // define/get ratio histos
   vector<TH1D*> DataMCRatios;
   
   double xBins[6] = {0, 0.5, 1.1, 1.7, 2.3, 5.2};
   TH1D* RatioVsEta = new TH1D("RatioVsEta", "", 5, xBins);

   for( int i = 0; i < corrected_SigmaData.size(); i++) {
      TH1D* ratio = new TH1D(*SigmaMC_eta0);
      //ratio->Divide(corrected_SigmaData.at(i), corrected_SigmaMC.at(i), 1, 1);
      ratio->Divide(corrected_SigmaMC.at(i), corrected_SigmaData.at(i), 1, 1);
    
      TF1 *fit_const = new TF1("fit_const", "[0]", ratio->GetXaxis()->GetXmin(), ratio->GetXaxis()->GetXmax());
      fit_const->SetParameters(1, 1);
      fit_const->SetParName(0, "const");
      ratio->Fit("fit_const", "EM", "same");
      ratio->GetYaxis()->SetRangeUser(0.7, 1.4);
      ratio->GetYaxis()->SetTitle("Data/MC ratio (const fit)");

      DataMCRatios.push_back(ratio);

      RatioVsEta->SetBinContent(i+1, ratio->GetFunction("fit_const")->GetParameter(0));
      RatioVsEta->SetBinError(i+1, ratio->GetFunction("fit_const")->GetParError(0));

      TCanvas *plot = new TCanvas("plot", "plot", 700, 700);
      plot->SetLogx();
      ratio->Draw();

      TString ratio_text;
      ratio_text->Form("_Ratio_const_fit_eta%i.ps", i);
      if( i < 5 ) plot->Print("JERPlots/" + InfoText + AsymmWidth + ratio_text);
   }

   // ------------------------------------------------------------------ //

   // Make closure test
   MakeClosurePlot(SigmaMC_eta0, corrected_SigmaMC_eta0, GenSigma_eta0, TruthSigma_eta0, 0, AsymmWidth, InfoText);
   MakeClosurePlot(SigmaMC_eta1, corrected_SigmaMC_eta1, GenSigma_eta1, TruthSigma_eta1, 1, AsymmWidth, InfoText);
   MakeClosurePlot(SigmaMC_eta2, corrected_SigmaMC_eta2, GenSigma_eta2, TruthSigma_eta2, 2, AsymmWidth, InfoText);
   MakeClosurePlot(SigmaMC_eta3, corrected_SigmaMC_eta3, GenSigma_eta3, TruthSigma_eta3, 3, AsymmWidth, InfoText);
   MakeClosurePlot(SigmaMC_eta4, corrected_SigmaMC_eta4, GenSigma_eta4, TruthSigma_eta4, 4, AsymmWidth, InfoText);
   // ------------------------------------------------------------------ //
  
   //  TCanvas *b = new TCanvas();
   //b->SetLogx();
   //DataMCRatios.at(1)->Draw();

   // ------------------------------------------------------------------ //

   TCanvas *c3 = new TCanvas();
   RatioVsEta->GetYaxis()->SetRangeUser(0.7, 1.4);
   RatioVsEta->Draw();

   cout << "Ratio Bin 1: " << RatioVsEta->GetBinContent(1) << " +- " << RatioVsEta->GetBinError(1) << endl;
   cout << "Ratio Bin 2: " << RatioVsEta->GetBinContent(2) << " +- " << RatioVsEta->GetBinError(2) << endl;
   cout << "Ratio Bin 3: " << RatioVsEta->GetBinContent(3) << " +- " << RatioVsEta->GetBinError(3) << endl;
   cout << "Ratio Bin 4: " << RatioVsEta->GetBinContent(4) << " +- " << RatioVsEta->GetBinError(4) << endl;
   cout << "Ratio Bin 5: " << RatioVsEta->GetBinContent(5) << " +- " << RatioVsEta->GetBinError(5) << endl;

   // write result histo to root-file
   TString outfile = "JER_RatioVsEta_AfterPLICorr_" + AsymmWidth + "_" + InfoText + ".root";
   //TString outfile = "JER_RatioVsEta_AfterPLICorr_" + AsymmWidth + "_MBXS73500.root";
   //TString outfile = "JER_RatioVsEta_AfterPLICorr_" + AsymmWidth + "_ClosureTest.root";

   if (PLI_scale == 0.75) outfile = "JER_RatioVsEta_PLICorrDOWN_" + AsymmWidth + "_" + InfoText + ".root";
   if (PLI_scale == 1.25) outfile = "JER_RatioVsEta_PLICorrUP_" + AsymmWidth + "_" + InfoText + ".root";
  

   TFile* output = new TFile(outfile, "RECREATE");
   RatioVsEta->Write();

   output->Write();

}

// ------------------------------------------------------------------ //
void MakeClosurePlot(TH1D* asymm, TH1D* asymm_corr, TH1D* pli, TH1D* truth, int etaBin, TString AsymmWidth, TString InfoText)
{
   TF1 *res_func = new TF1("res_func", "TMath::Sqrt(sign([0])*pow([0]/x,2)+pow([1],2)*pow(x,[2]-1.)+pow([3],2))" );
   res_func->SetParameters(1.2, 0.5, 0.03, 0.1);

   TCanvas *c = new TCanvas();
   c->SetLogx();
   c->SetBottomMargin(0.25 + 0.75*c->GetBottomMargin()-0.25*c->GetTopMargin());
   c->cd();
   asymm_corr->Scale(TMath::Sqrt(2));
   asymm_corr->GetYaxis()->SetRangeUser(0.000001, 0.3);
   asymm_corr->GetXaxis()->SetTitle("");
   asymm_corr->GetYaxis()->SetTitle("#sigma");
   asymm_corr->SetMarkerStyle(20);
   asymm_corr->SetMarkerColor(kBlue-3);
   asymm_corr->GetXaxis()->SetLabelSize(0);
   asymm_corr->Draw();
   asymm->Scale(TMath::Sqrt(2));
   asymm->SetMarkerStyle(24);
   asymm->SetMarkerColor(kBlue-7);
   asymm->Draw("same");
   pli->Scale(TMath::Sqrt(2));
   pli->SetMarkerStyle(26);
   pli->SetMarkerColor(kBlue-9);
   pli->Draw("same");
   truth->SetMarkerColor(kRed);
   truth->SetMarkerStyle(20);
   truth->Draw("same");
   truth->Fit("res_func", "WLQ", "same", truth->GetBinCenter(truth->FindFirstBinAbove()), truth->GetBinCenter(truth->FindLastBinAbove()) );
   asymm_corr->Draw("same");

   TLegend *leg = new TLegend(0.45, 0.7, 0.85, 0.92);
   leg->AddEntry( asymm, "MC resolution (before PLI)" , "lp");
   leg->AddEntry( asymm_corr, "MC resolution" , "lp");
   leg->AddEntry( pli, "PLI" , "lp");
   leg->AddEntry( truth, "Truth resolution" , "lp");
   leg->SetFillStyle(0);
   leg->SetLineStyle(1);
   leg->SetTextFont(42);
   leg->SetTextSize(0.035);

   leg->Draw("same");
  
   Double_t xMin1 = asymm_corr->GetXaxis()->GetXmin();
   Double_t xMax1 = asymm_corr->GetXaxis()->GetXmax();

   TPad *pad2 = new TPad("pad2a", "pad2a", 0, 0, 1, 1);
   pad2->SetLogx();
   pad2->SetTopMargin(0.75 - 0.75*pad2->GetBottomMargin()+0.25*pad2->GetTopMargin());
   pad2->SetFillStyle(0);
   pad2->SetFrameFillColor(10);
   pad2->SetFrameBorderMode(0);
   pad2->Draw();
   pad2->cd();

   TH1D* r = new TH1D(*asymm_corr);
   r->SetXTitle(asymm->GetXaxis()->GetTitle());
   r->SetYTitle("#sigma - #sigma_{truth} ) / #sigma");
   r->GetXaxis()->SetLabelSize(gStyle->GetLabelSize("X"));
   r->GetYaxis()->SetLabelOffset(gStyle->GetLabelOffset("Y"));
   r->GetYaxis()->SetTickLength(gStyle->GetTickLength("Y")/0.3);
   r->SetStats(0);
   r->SetMarkerStyle(21);
   r->SetMarkerSize(1.12);
   r->SetMarkerColor(kBlack);
   r->Reset();
   r->Add(asymm_corr, 1);
   r->Add(truth, -1);
   r->Divide(asymm_corr);
   r->SetMaximum(0.5);
   r->SetMinimum(-0.5);
   r->Draw("ep");
   TLine l;
   l.DrawLine(xMin1, 0., xMax1, 0.);
   c->cd();

   TString title = asymm->GetTitle();
   title.Resize(21);

   TPaveText* pt = new TPaveText(0.16, 0.7, 0.95, 0.92, "NDC");
   pt->SetBorderSize(0);
   pt->SetFillStyle(0);
   pt->SetTextAlign(12);
   pt->SetTextFont(42);
   pt->SetTextSize(0.035);
   pt->AddText("PF Jets");
   pt->AddText(title);
   pt->AddText("");
   pt->AddText("");
   pt->Draw("same");

   TString Bin;
   Bin.Form("%i", etaBin);
   c->Print("JERPlots/Closure_eta" + Bin +"_" + AsymmWidth + "_" + InfoText + ".ps");
}
