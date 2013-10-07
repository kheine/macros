#include "/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/scripts/tdrstyle_mod.C"
#include "PlottingUtils.C"
#include <TROOT.h>
#include <TF1.h>
#include <TH1.h>
#include <TH2.h>
#include <TString.h>
#include <TFile.h>
#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TPaveText.h>
#include <TMatrixD.h>
#include <TTree.h>

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

void PlotAsymmetry()
{
   //gROOT->ProcessLine(".L PlottingUtils.C+");
    
   //PlottingUtils::SetPlotStyle();

   setTDRStyle();

   gROOT->ProcessLine("#include <vector>");

   std::vector<std::vector<TH1D*> > DataAsymmetry_Alpha10_Eta_PtDist;
   std::vector<std::vector<TH1D*> > DataAsymmetry_Alpha12p5_Eta_PtDist;
   std::vector<std::vector<TH1D*> > DataAsymmetry_Alpha15_Eta_PtDist;
   std::vector<std::vector<TH1D*> > DataAsymmetry_Alpha17p5_Eta_PtDist;
   std::vector<std::vector<TH1D*> > DataAsymmetry_Alpha20_Eta_PtDist;
   std::vector<std::vector<TH1D*> > DataAsymmetry_Alpha22p5_Eta_PtDist;
   std::vector<std::vector<TH1D*> > DataAsymmetry_Alpha25_Eta_PtDist;

   std::vector<std::vector<TH1D*> > MCAsymmetry_Alpha10_Eta_PtDist;
   std::vector<std::vector<TH1D*> > MCAsymmetry_Alpha12p5_Eta_PtDist;
   std::vector<std::vector<TH1D*> > MCAsymmetry_Alpha15_Eta_PtDist;
   std::vector<std::vector<TH1D*> > MCAsymmetry_Alpha17p5_Eta_PtDist;
   std::vector<std::vector<TH1D*> > MCAsymmetry_Alpha20_Eta_PtDist;
   std::vector<std::vector<TH1D*> > MCAsymmetry_Alpha22p5_Eta_PtDist;
   std::vector<std::vector<TH1D*> > MCAsymmetry_Alpha25_Eta_PtDist;

   // -------------------------------------------------------------------------- //
   // resize vectors
   DataAsymmetry_Alpha10_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = DataAsymmetry_Alpha10_Eta_PtDist.begin(); it != DataAsymmetry_Alpha10_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   DataAsymmetry_Alpha12p5_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = DataAsymmetry_Alpha12p5_Eta_PtDist.begin(); it != DataAsymmetry_Alpha12p5_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   DataAsymmetry_Alpha15_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = DataAsymmetry_Alpha15_Eta_PtDist.begin(); it != DataAsymmetry_Alpha15_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   DataAsymmetry_Alpha17p5_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = DataAsymmetry_Alpha17p5_Eta_PtDist.begin(); it != DataAsymmetry_Alpha17p5_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   DataAsymmetry_Alpha20_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = DataAsymmetry_Alpha20_Eta_PtDist.begin(); it != DataAsymmetry_Alpha20_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   DataAsymmetry_Alpha22p5_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = DataAsymmetry_Alpha22p5_Eta_PtDist.begin(); it != DataAsymmetry_Alpha22p5_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   DataAsymmetry_Alpha25_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = DataAsymmetry_Alpha25_Eta_PtDist.begin(); it != DataAsymmetry_Alpha25_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }


   MCAsymmetry_Alpha10_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = MCAsymmetry_Alpha10_Eta_PtDist.begin(); it != MCAsymmetry_Alpha10_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   MCAsymmetry_Alpha12p5_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = MCAsymmetry_Alpha12p5_Eta_PtDist.begin(); it != MCAsymmetry_Alpha12p5_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   MCAsymmetry_Alpha15_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = MCAsymmetry_Alpha15_Eta_PtDist.begin(); it != MCAsymmetry_Alpha15_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   MCAsymmetry_Alpha17p5_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = MCAsymmetry_Alpha17p5_Eta_PtDist.begin(); it != MCAsymmetry_Alpha17p5_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   MCAsymmetry_Alpha20_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = MCAsymmetry_Alpha20_Eta_PtDist.begin(); it != MCAsymmetry_Alpha20_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   MCAsymmetry_Alpha22p5_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = MCAsymmetry_Alpha22p5_Eta_PtDist.begin(); it != MCAsymmetry_Alpha22p5_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   MCAsymmetry_Alpha25_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = MCAsymmetry_Alpha25_Eta_PtDist.begin(); it != MCAsymmetry_Alpha25_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   // -------------------------------------------------------------------------- //
   //// open root file
   TFile* file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/20132013ABCD_ReReco_CORR2013SummerV1_AK5_MC_Su12Z253_kostas_ChangeAlphaRangeMoreFitPointsAlphaExclusive_v2/dijetsFall10_TuneZ2_AK5PF_weighted_residuals_JERMatt/plots/KalibriPlots.root", "READ");
   //TFile* file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/20122012ABCD_ReReco_CORR2012FallV5_AK5_MC_Su12Z253_pythia_kostas_DefaultTestTEstTest/dijetsFall10_TuneZ2_AK5PF_weighted_residuals_JERMatt/plots/KalibriPlots.root", "READ");
   //TFile* file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/20122012ABCD_208686_CORR2012FallV5_AK5_MC_Su12Z253_pythia_kostas_DefaultTestTEstTest_alphaExclusive/dijetsFall10_TuneZ2_AK5PF_weighted_residuals_JERMatt/plots/KalibriPlots.root", "READ");

   TH2D *chi_ndf_Data_10 = new TH2D("chi_ndf_Data_10", "", 120, 0, 120, 120, 0, 120);
   TH2D *chi_ndf_Data_12p5 = new TH2D("chi_ndf_Data_12p5", "", 120, 0, 120, 120, 0, 120);
   TH2D *chi_ndf_Data_15 = new TH2D("chi_ndf_Data_15", "", 120, 0, 120, 120, 0, 120);
   TH2D *chi_ndf_Data_17p5 = new TH2D("chi_ndf_Data_17p5", "", 120, 0, 120, 120, 0, 120);
   TH2D *chi_ndf_Data_20 = new TH2D("chi_ndf_Data_20", "", 120, 0, 120, 120, 0, 120);
   TH2D *chi_ndf_Data_22p5 = new TH2D("chi_ndf_Data_22p5", "", 120, 0, 120, 120, 0, 120);
   TH2D *chi_ndf_Data_25 = new TH2D("chi_ndf_Data_25", "", 120, 0, 120, 120, 0, 120);
   TH2D *chi_ndf_MC_10 = new TH2D("chi_ndf_MC_10", "", 120, 0, 120, 120, 0, 120);
   TH2D *chi_ndf_MC_12p5 = new TH2D("chi_ndf_MC_12p5", "", 120, 0, 120, 120, 0, 120);
   TH2D *chi_ndf_MC_15 = new TH2D("chi_ndf_MC_15", "", 120, 0, 120, 120, 0, 120);
   TH2D *chi_ndf_MC_17p5 = new TH2D("chi_ndf_MC_17p5", "", 120, 0, 120, 120, 0, 120);
   TH2D *chi_ndf_MC_20 = new TH2D("chi_ndf_MC_20", "", 120, 0, 120, 120, 0, 120);
   TH2D *chi_ndf_MC_22p5 = new TH2D("chi_ndf_MC_22p5", "", 120, 0, 120, 120, 0, 120);
   TH2D *chi_ndf_MC_25 = new TH2D("chi_ndf_MC_25", "", 120, 0, 120, 120, 0, 120);
  
   //// get asymmetry histos
   for (unsigned int i_Eta = 0; i_Eta < 4; ++i_Eta) {
      for (unsigned int i_Dist = 0; i_Dist < 15; ++i_Dist) {
         // -------------------------------------------------------------------------- //
         //// Get the histos
         TString hname_Data_10 = Form("AbsAsymmetryVsPt10_AsymmetryVsMeanPt_data_L2L3res_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         TString hname_Data_12p5 = Form("AbsAsymmetryVsPt12.5_AsymmetryVsMeanPt_data_L2L3res_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         TString hname_Data_15 = Form("AbsAsymmetryVsPt15_AsymmetryVsMeanPt_data_L2L3res_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         TString hname_Data_17p5 = Form("AbsAsymmetryVsPt17.5_AsymmetryVsMeanPt_data_L2L3res_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         TString hname_Data_20 = Form("AbsAsymmetryVsPt20_AsymmetryVsMeanPt_data_L2L3res_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         TString hname_Data_22p5 = Form("AbsAsymmetryVsPt22.5_AsymmetryVsMeanPt_data_L2L3res_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         TString hname_Data_25 = Form("AbsAsymmetryVsPt25_AsymmetryVsMeanPt_data_L2L3res_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);


         TString hname_MC_10 = Form("AbsAsymmetryVsPt10_AsymmetryVsMeanPt_MC_L2L3_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         TString hname_MC_12p5 = Form("AbsAsymmetryVsPt12.5_AsymmetryVsMeanPt_MC_L2L3_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         TString hname_MC_15 = Form("AbsAsymmetryVsPt15_AsymmetryVsMeanPt_MC_L2L3_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         TString hname_MC_17p5 = Form("AbsAsymmetryVsPt17.5_AsymmetryVsMeanPt_MC_L2L3_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         TString hname_MC_20 = Form("AbsAsymmetryVsPt20_AsymmetryVsMeanPt_MC_L2L3_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         TString hname_MC_22p5 = Form("AbsAsymmetryVsPt22.5_AsymmetryVsMeanPt_MC_L2L3_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         TString hname_MC_25 = Form("AbsAsymmetryVsPt25_AsymmetryVsMeanPt_MC_L2L3_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);

         // -------------------------------------------------------------------------- //
         file->cd("AbsAsymmetryVsPt10");
         DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_Data_10);
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_MC_10);

         file->cd("AbsAsymmetryVsPt12.5");
         DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_Data_12p5);
         MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_MC_12p5);

         file->cd("AbsAsymmetryVsPt15");
         DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_Data_15);
         MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_MC_15);

         file->cd("AbsAsymmetryVsPt17.5");
         DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_Data_17p5);
         MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_MC_17p5);

         file->cd("AbsAsymmetryVsPt20");
         DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_Data_20);
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_MC_20);

         file->cd("AbsAsymmetryVsPt22.5");
         DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_Data_22p5);
         MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_MC_22p5);

         file->cd("AbsAsymmetryVsPt25");
         DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_Data_25);
         MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_MC_25);

         // -------------------------------------------------------------------------- //
         //Rebinning
         DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);
         DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);
         MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);        
         DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);
         MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);       
         DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);
         MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);       
         DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);      
         DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);
         MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);
         DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);
         MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->Rebin(3);

         if(DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);  
         if(MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);
         if(DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);
         if(MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);
         if(DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);
         if(MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);
         if(DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);
         if(MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);
         if(DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);
         if(MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);
         if(DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);
         if(MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);
         if(DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);
         if(MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus"))
         MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetFunction("gaus")->SetBit(TF1::kNotDraw);

         // -------------------------------------------------------------------------- //
         // Fit Histograms with double gaussian
         TF1 *double_gaus_MC_10 = new TF1("double_gaus_MC_10", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");
 
         if(MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_MC_10->SetParameter(1, max);
            double_gaus_MC_10->SetParameter(2, 0.2);       
                   
            MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_10","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_MC_10->SetParameter(1, double_gaus_MC_10->GetParameter(1));
            double_gaus_MC_10->SetParameter(2, double_gaus_MC_10->GetParameter(2));
            double_gaus_MC_10->SetParLimits(2, 0.001, 0.35);

            if( MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_10","ILL","", mean - 1.5 * width, mean + 1.5 * width) == 0 )

            chi_ndf_MC_10->Fill(double_gaus_MC_10->GetNDF(), double_gaus_MC_10->GetChisquare());
         }

         //////////////////

         TF1 *double_gaus_Data_10 = new TF1("double_gaus_Data_10 ", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");

         if(DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_Data_10->SetParameter(1, max);
            double_gaus_Data_10->SetParameter(2, 0.2);       
                   
            DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_10 ","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_Data_10->SetParameter(1, double_gaus_Data_10->GetParameter(1));
            double_gaus_Data_10->SetParameter(2, double_gaus_Data_10->GetParameter(2));
            double_gaus_Data_10->SetParLimits(2, 0.001, 0.35);

            if ( DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_10 ","ILL","", mean - 1.5 * width, mean + 1.5 * width) == 0)

            chi_ndf_Data_10->Fill(double_gaus_Data_10->GetNDF(), double_gaus_Data_10->GetChisquare());
         }

         ////////////////////////

         TF1 *double_gaus_MC_12p5 = new TF1("double_gaus_MC_12p5", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");
 
         if(MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_MC_12p5->SetParameter(1, max);
            double_gaus_MC_12p5->SetParameter(2, 0.2);       
                   
            MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_12p5","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_MC_12p5->SetParameter(1, double_gaus_MC_12p5->GetParameter(1));
            double_gaus_MC_12p5->SetParameter(2, double_gaus_MC_12p5->GetParameter(2));
            double_gaus_MC_12p5->SetParLimits(2, 0.001, 0.35);

            if (MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_12p5","ILL","", mean - 1.5 * width, mean + 1.5 * width)== 0)

            chi_ndf_MC_12p5->Fill(double_gaus_MC_12p5->GetNDF(), double_gaus_MC_12p5->GetChisquare());
         }

         //////////////////

         TF1 *double_gaus_Data_12p5 = new TF1("double_gaus_Data_12p5 ", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");

         if(DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_Data_12p5->SetParameter(1, max);
            double_gaus_Data_12p5->SetParameter(2, 0.2);       
                   
            DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_12p5 ","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_Data_12p5->SetParameter(1, double_gaus_Data_12p5->GetParameter(1));
            double_gaus_Data_12p5->SetParameter(2, double_gaus_Data_12p5->GetParameter(2));
            double_gaus_Data_12p5->SetParLimits(2, 0.001, 0.35);

            if( DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_12p5 ","ILL","", mean - 1.5 * width, mean + 1.5 * width) == 0)

            chi_ndf_Data_12p5->Fill(double_gaus_Data_12p5->GetNDF(), double_gaus_Data_12p5->GetChisquare());
         }

         ////////////////////////

         TF1 *double_gaus_MC_15 = new TF1("double_gaus_MC_15", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");
 
         if(MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_MC_15->SetParameter(1, max);
            double_gaus_MC_15->SetParameter(2, 0.2);       
                   
            MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_15","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_MC_15->SetParameter(1, double_gaus_MC_15->GetParameter(1));
            double_gaus_MC_15->SetParameter(2, double_gaus_MC_15->GetParameter(2));
            double_gaus_MC_15->SetParLimits(2, 0.001, 0.35);

            if( MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_15","ILL","", mean - 1.5 * width, mean + 1.5 * width) == 0)

            chi_ndf_MC_15->Fill(double_gaus_MC_15->GetNDF(), double_gaus_MC_15->GetChisquare());
         }

         //////////////////

         TF1 *double_gaus_Data_15 = new TF1("double_gaus_Data_15 ", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");

         if(DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_Data_15->SetParameter(1, max);
            double_gaus_Data_15->SetParameter(2, 0.2);       
                   
            DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_15 ","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_Data_15->SetParameter(1, double_gaus_Data_15->GetParameter(1));
            double_gaus_Data_15->SetParameter(2, double_gaus_Data_15->GetParameter(2));
            double_gaus_Data_15->SetParLimits(2, 0.001, 0.35);

            if(DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_15 ","ILL","", mean - 1.5 * width, mean + 1.5 * width) == 0)

            chi_ndf_Data_15->Fill(double_gaus_Data_15->GetNDF(), double_gaus_Data_15->GetChisquare());
         }

         ////////////////////////

         TF1 *double_gaus_MC_17p5 = new TF1("double_gaus_MC_17p5", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");
 
         if(MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_MC_17p5->SetParameter(1, max);
            double_gaus_MC_17p5->SetParameter(2, 0.2);       
                   
            MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_17p5","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_MC_17p5->SetParameter(1, double_gaus_MC_17p5->GetParameter(1));
            double_gaus_MC_17p5->SetParameter(2, double_gaus_MC_17p5->GetParameter(2));
            double_gaus_MC_17p5->SetParLimits(2, 0.001, 0.35);

            if(MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_17p5","ILL","", mean - 1.5 * width, mean + 1.5 * width) == 0)

            chi_ndf_MC_17p5->Fill(double_gaus_MC_17p5->GetNDF(), double_gaus_MC_17p5->GetChisquare());
         }

         //////////////////

         TF1 *double_gaus_Data_17p5 = new TF1("double_gaus_Data_17p5 ", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");

         if(DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_Data_17p5->SetParameter(1, max);
            double_gaus_Data_17p5->SetParameter(2, 0.2);       
                   
            DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_17p5 ","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_Data_17p5->SetParameter(1, double_gaus_Data_17p5->GetParameter(1));
            double_gaus_Data_17p5->SetParameter(2, double_gaus_Data_17p5->GetParameter(2));
            double_gaus_Data_17p5->SetParLimits(2, 0.001, 0.35);

            if(DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_17p5 ","ILL","", mean - 1.5 * width, mean + 1.5 * width) == 0)

            chi_ndf_Data_17p5->Fill(double_gaus_Data_17p5->GetNDF(), double_gaus_Data_17p5->GetChisquare());
         }

         ////////////////////////

         TF1 *double_gaus_MC_20 = new TF1("double_gaus_MC_20", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");
 
         if(MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_MC_20->SetParameter(1, max);
            double_gaus_MC_20->SetParameter(2, 0.2);       
                   
            MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_20","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_MC_20->SetParameter(1, double_gaus_MC_20->GetParameter(1));
            double_gaus_MC_20->SetParameter(2, double_gaus_MC_20->GetParameter(2));
            double_gaus_MC_20->SetParLimits(2, 0.001, 0.35);

            if(MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_20","ILL","", mean - 1.5 * width, mean + 1.5 * width) == 0)

            chi_ndf_MC_20->Fill(double_gaus_MC_20->GetNDF(), double_gaus_MC_20->GetChisquare());
         }

         //////////////////

         TF1 *double_gaus_Data_20 = new TF1("double_gaus_Data_20 ", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");

         if(DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_Data_20->SetParameter(1, max);
            double_gaus_Data_20->SetParameter(2, 0.2);       
                   
            DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_20 ","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_Data_20->SetParameter(1, double_gaus_Data_20->GetParameter(1));
            double_gaus_Data_20->SetParameter(2, double_gaus_Data_20->GetParameter(2));
            double_gaus_Data_20->SetParLimits(2, 0.001, 0.35);

            if(DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_20 ","ILL","", mean - 1.5 * width, mean + 1.5 * width) == 0)

            chi_ndf_Data_20->Fill(double_gaus_Data_20->GetNDF(), double_gaus_Data_20->GetChisquare());
         }

         ////////////////////////

         TF1 *double_gaus_MC_22p5 = new TF1("double_gaus_MC_22p5", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");
 
         if(MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_MC_22p5->SetParameter(1, max);
            double_gaus_MC_22p5->SetParameter(2, 0.2);       
                   
            MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_22p5","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_MC_22p5->SetParameter(1, double_gaus_MC_22p5->GetParameter(1));
            double_gaus_MC_22p5->SetParameter(2, double_gaus_MC_22p5->GetParameter(2));
            double_gaus_MC_22p5->SetParLimits(2, 0.001, 0.35);

            if(MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_22p5","ILL","", mean - 1.5 * width, mean + 1.5 * width) == 0)

            chi_ndf_MC_22p5->Fill(double_gaus_MC_22p5->GetNDF(), double_gaus_MC_22p5->GetChisquare());
         }

         //////////////////

         TF1 *double_gaus_Data_22p5 = new TF1("double_gaus_Data_22p5 ", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");

         if(DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_Data_22p5->SetParameter(1, max);
            double_gaus_Data_22p5->SetParameter(2, 0.2);       
                   
            DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_22p5 ","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_Data_22p5->SetParameter(1, double_gaus_Data_22p5->GetParameter(1));
            double_gaus_Data_22p5->SetParameter(2, double_gaus_Data_22p5->GetParameter(2));
            double_gaus_Data_22p5->SetParLimits(2, 0.001, 0.35);

            if(DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_22p5 ","ILL","", mean - 1.5 * width, mean + 1.5 * width) ==0)

            chi_ndf_Data_22p5->Fill(double_gaus_Data_22p5->GetNDF(), double_gaus_Data_22p5->GetChisquare());
         }

         ////////////////////////

         TF1 *double_gaus_MC_25 = new TF1("double_gaus_MC_25", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");
 
         if(MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_MC_25->SetParameter(1, max);
            double_gaus_MC_25->SetParameter(2, 0.2);       
                   
            MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_25","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_MC_25->SetParameter(1, double_gaus_MC_25->GetParameter(1));
            double_gaus_MC_25->SetParameter(2, double_gaus_MC_25->GetParameter(2));
            double_gaus_MC_25->SetParLimits(2, 0.001, 0.35);

            if(MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_MC_25","ILL","", mean - 1.5 * width, mean + 1.5 * width) ==0)

            chi_ndf_MC_25->Fill(double_gaus_MC_25->GetNDF(), double_gaus_MC_25->GetChisquare());
         }

         //////////////////

         TF1 *double_gaus_Data_25 = new TF1("double_gaus_Data_25 ", "[0]*exp(-0.5*((x+[1])/[2])^2)+[0]*exp(-0.5*((x-[1])/[2])^2)");

         if(DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetEntries() > 100) {

            double mean = DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMean(); 
            double width = DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetRMS();
            double max = DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetBinCenter(DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximumBin());
            
            double_gaus_Data_25->SetParameter(1, max);
            double_gaus_Data_25->SetParameter(2, 0.2);       
                   
            DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_25 ","NQILL","", mean - 4 * width, mean + 4 * width);

            double_gaus_Data_25->SetParameter(1, double_gaus_Data_25->GetParameter(1));
            double_gaus_Data_25->SetParameter(2, double_gaus_Data_25->GetParameter(2));
            double_gaus_Data_25->SetParLimits(2, 0.001, 0.35);

            if(DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->Fit("double_gaus_Data_25 ","ILL","", mean - 1.5 * width, mean + 1.5 * width) ==0)

            chi_ndf_Data_25->Fill(double_gaus_Data_25->GetNDF(), double_gaus_Data_25->GetChisquare());
         }
          
         // -------------------------------------------------------------------------- //
         // plot asymmetries
         TCanvas *c = new TCanvas("c1", "c1", 700, 700);
         c->SetLogy();
         TString title = MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetTitle();
         
         double max_y = MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximum();
         MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetXaxis()->SetTitle("(p_{T,1} - p_{T,2})/(p_{T,1} + p_{T,2})");
         MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetTitle("");
         MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetRangeUser(0.1, 100*max_y);
         MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->SetFillColor(38);
         MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(38);
         MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         MCAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("hist");
         DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(kBlack);
         DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerColor(kBlack);
         DataAsymmetry_Alpha25_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("same");
         
         TPaveText* pt = new TPaveText(0.16, 0.705, 0.95, 0.925, "NDC");
         pt->SetBorderSize(0);
         pt->SetFillStyle(0);
         pt->SetTextAlign(12);
         pt->SetTextFont(42);
         pt->SetTextSize(0.032);
         pt->AddText(title);
         pt->AddText(Form("#chi2 / ndf Data = %4.2f/%i", double_gaus_Data_25->GetChisquare(), double_gaus_Data_25->GetNDF()));
         pt->AddText(Form("Asymm. width Data = %4.3f #pm %4.4f", double_gaus_Data_25->GetParameter(2), double_gaus_Data_25->GetParError(2)));
         pt->AddText(Form("#chi2 / ndf MC = %4.2f/%i", double_gaus_MC_25->GetChisquare(), double_gaus_MC_25->GetNDF()));
         pt->AddText(Form("Asymm. width MC = %4.3f #pm %4.4f", double_gaus_MC_25->GetParameter(2), double_gaus_MC_25->GetParError(2)));
         pt->Draw("same");
         
         if(i_Eta == 0 && i_Dist == 11) c->Print("JERPlots/Asymmetry_Pt25_alphaExclusive.png");
         if(i_Eta == 0 && i_Dist == 0) c->Print("JERPlots/Asymmetry_Pt25_alphaExclusive.ps(");
         else if(i_Eta == 4 && i_Dist == 15) c->Print("JERPlots/Asymmetry_Pt25_alphaExclusive.ps)");
         else c->Print("JERPlots/Asymmetry_Pt25_alphaExclusive.ps");

         ///////////////////////////////////////////////
         TCanvas *c2 = new TCanvas("c2", "c2", 700, 700);
         c2->SetLogy();
         TString title2 = MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetTitle();
         
         double max_y2 = MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximum();
         MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetXaxis()->SetTitle("(p_{T,1} - p_{T,2})/(p_{T,1} + p_{T,2})");
         MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetTitle("");
         MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetRangeUser(0.1, 100*max_y2);
         MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetFillColor(38);
         MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(38);
         MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         MCAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw();//("hist");
         DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(kBlack);
         DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerColor(kBlack);
         DataAsymmetry_Alpha22p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("same");
         
         TPaveText* pt2 = new TPaveText(0.16, 0.855, 0.95, 0.935, "NDC");
         pt2->SetBorderSize(0);
         pt2->SetFillStyle(0);
         pt2->SetTextAlign(12);
         pt2->SetTextFont(42);
         pt2->SetTextSize(0.032);
         pt2->AddText(title2);
         pt2->Draw("same");
         
         if(i_Eta == 0 && i_Dist == 0) c2->Print("JERPlots/Asymmetry_Pt22p5_alphaExclusive.ps(");
         else if(i_Eta == 4 && i_Dist == 15) c2->Print("JERPlots/Asymmetry_Pt22p5_alphaExclusive.ps)");
         else c2->Print("JERPlots/Asymmetry_Pt22p5_alphaExclusive.ps");

         ///////////////////////////////////////////////
         TCanvas *c3 = new TCanvas("c3", "c3", 700, 700);
         c3->SetLogy();
         TString title3 = MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetTitle();
         
         double max_y3= MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximum();
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetXaxis()->SetTitle("(p_{T,1} - p_{T,2})/(p_{T,1} + p_{T,2})");
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetTitle("");
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetRangeUser(0.1, 100*max_y3);
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->SetFillColor(38);
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(38);
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw();//("hist");
         DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(kBlack);
         DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerColor(kBlack);
         DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("same");
         
         TPaveText* pt3 = new TPaveText(0.16, 0.855, 0.95, 0.935, "NDC");
         pt3->SetBorderSize(0);
         pt3->SetFillStyle(0);
         pt3->SetTextAlign(12);
         pt3->SetTextFont(42);
         pt3->SetTextSize(0.032);
         pt3->AddText(title3);
         pt3->Draw("same");
         
         if(i_Eta == 0 && i_Dist == 0) c3->Print("JERPlots/Asymmetry_Pt20_alphaExclusive.ps(");
         else if(i_Eta == 4 && i_Dist == 15) c3->Print("JERPlots/Asymmetry_Pt20_alphaExclusive.ps)");
         else c3->Print("JERPlots/Asymmetry_Pt20_alphaExclusive.ps");

         ///////////////////////////////////////////////
         TCanvas *c4 = new TCanvas("c4", "c4", 700, 700);
         c4->SetLogy();
         TString title4 = MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetTitle();
         
         double max_y4 = MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximum();
         MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetXaxis()->SetTitle("(p_{T,1} - p_{T,2})/(p_{T,1} + p_{T,2})");
         MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetTitle("");
         MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetRangeUser(0.1, 100*max_y4);
         MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetFillColor(38);
         MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(38);
         MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         MCAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw();//("hist");
         DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(kBlack);
         DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerColor(kBlack);
         DataAsymmetry_Alpha17p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("same");
         
         TPaveText* pt4 = new TPaveText(0.16, 0.855, 0.95, 0.935, "NDC");
         pt4->SetBorderSize(0);
         pt4->SetFillStyle(0);
         pt4->SetTextAlign(12);
         pt4->SetTextFont(42);
         pt4->SetTextSize(0.032);
         pt4->AddText(title4);
         pt4->Draw("same");
         
         if(i_Eta == 0 && i_Dist == 0) c4->Print("JERPlots/Asymmetry_Pt17p5_alphaExclusive.ps(");
         else if(i_Eta == 4 && i_Dist == 15) c4->Print("JERPlots/Asymmetry_Pt17p5_alphaExclusive.ps)");
         else c4->Print("JERPlots/Asymmetry_Pt17p5_alphaExclusive.ps");


         ///////////////////////////////////////////////
         TCanvas *c5 = new TCanvas("c5", "c5", 700, 700);
         c5->SetLogy();
         TString title5 = MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetTitle();
         
         double max_y5= MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximum();
         MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetXaxis()->SetTitle("(p_{T,1} - p_{T,2})/(p_{T,1} + p_{T,2})");
         MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetTitle("");
         MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetRangeUser(0.1, 100*max_y5);
         MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->SetFillColor(38);
         MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(38);
         MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         MCAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw();//("hist");
         DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(kBlack);
         DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerColor(kBlack);
         DataAsymmetry_Alpha15_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("same");
         
         TPaveText* pt5 = new TPaveText(0.16, 0.855, 0.95, 0.935, "NDC");
         pt5->SetBorderSize(0);
         pt5->SetFillStyle(0);
         pt5->SetTextAlign(12);
         pt5->SetTextFont(42);
         pt5->SetTextSize(0.032);
         pt5->AddText(title5);
         pt5->Draw("same");
         
         if(i_Eta == 0 && i_Dist == 0) c5->Print("JERPlots/Asymmetry_Pt15_alphaExclusive.ps(");
         else if(i_Eta == 4 && i_Dist == 15) c5->Print("JERPlots/Asymmetry_Pt15_alphaExclusive.ps)");
         else c5->Print("JERPlots/Asymmetry_Pt15_alphaExclusive.ps");


         ///////////////////////////////////////////////
         TCanvas *c6 = new TCanvas("c6", "c6", 700, 700);
         c6->SetLogy();
         TString title6 = MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetTitle();
         
         double max_y6= MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximum();
         MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetXaxis()->SetTitle("(p_{T,1} - p_{T,2})/(p_{T,1} + p_{T,2})");
         MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetTitle("");
         MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetRangeUser(0.1, 100*max_y6);
         MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetFillColor(38);
         MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(38);
         MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         MCAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw();//("hist");
         DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(kBlack);
         DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerColor(kBlack);
         DataAsymmetry_Alpha12p5_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("same");
         
         TPaveText* pt6 = new TPaveText(0.16, 0.855, 0.95, 0.935, "NDC");
         pt6->SetBorderSize(0);
         pt6->SetFillStyle(0);
         pt6->SetTextAlign(12);
         pt6->SetTextFont(42);
         pt6->SetTextSize(0.032);
         pt6->AddText(title6);
         pt6->Draw("same");
         
         if(i_Eta == 0 && i_Dist == 0) c6->Print("JERPlots/Asymmetry_Pt12p5_alphaExclusive.ps(");
         else if(i_Eta == 4 && i_Dist == 15) c6->Print("JERPlots/Asymmetry_Pt12p5_alphaExclusive.ps)");
         else c6->Print("JERPlots/Asymmetry_Pt12p5_alphaExclusive.ps");

         ///////////////////////////////////////////////
         TCanvas *c7 = new TCanvas("c7", "c7", 700, 700);
         c7->SetLogy();
         TString title7 = MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetTitle();
         
         double max_y7= MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximum();
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetXaxis()->SetTitle("(p_{T,1} - p_{T,2})/(p_{T,1} + p_{T,2})");
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetTitle("");
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetRangeUser(0.1, 100*max_y7);
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->SetFillColor(38);
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(38);
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("hist");
         DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(kBlack);
         DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerColor(kBlack);
         DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("same");
         
         TPaveText* pt7 = new TPaveText(0.16, 0.855, 0.95, 0.935, "NDC");
         pt7->SetBorderSize(0);
         pt7->SetFillStyle(0);
         pt7->SetTextAlign(12);
         pt7->SetTextFont(42);
         pt7->SetTextSize(0.032);
         pt7->AddText(title7);
         pt7->Draw("same");
         
         if(i_Eta == 0 && i_Dist == 11) c7->Print("JERPlots/Asymmetry_Pt10_alphaExclusive.png");
         if(i_Eta == 0 && i_Dist == 0) c7->Print("JERPlots/Asymmetry_Pt10_alphaExclusive.ps(");
         else if(i_Eta == 4 && i_Dist == 15) c7->Print("JERPlots/Asymmetry_Pt10_alphaExclusive.ps)");
         else c7->Print("JERPlots/Asymmetry_Pt10_alphaExclusive.ps");
      }
   }

   TF1 *lin1 = new TF1("lin1", "x", 0, 120);
   TF1 *lin2 = new TF1("lin2", "2*x", 0, 120);

   TCanvas *chi1 = new TCanvas("chi1", "chi1", 700, 700);
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_Data_25->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   TLatex *tex1 = new TLatex();
   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");

   TLatex *tex2 = new TLatex();
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");

   TLatex *tex3 = new TLatex();
   tex3->DrawLatex(40, 4, "Data 22.5 < #alpha < 25");

   chi1->Print("JERPlots/Chi_ndf.ps(");

   /////////////////////////////////////////////
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_MC_25->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");
   tex3->DrawLatex(40, 4, "MC 22.5 < #alpha < 25");

   chi1->Print("JERPlots/Chi_ndf.ps");

   /////////////////////////////////////////////
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_Data_22p5->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");
   tex3->DrawLatex(40, 4, "Data 20 < #alpha < 22.5");

   chi1->Print("JERPlots/Chi_ndf.ps");

   /////////////////////////////////////////////
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_MC_22p5->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");
   tex3->DrawLatex(40, 4, "MC 20 < #alpha < 22.5");

   chi1->Print("JERPlots/Chi_ndf.ps");

   /////////////////////////////////////////////
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_Data_20->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");
   tex3->DrawLatex(40, 4, "Data 17.5 < #alpha < 20");

   chi1->Print("JERPlots/Chi_ndf.ps");

   /////////////////////////////////////////////
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_MC_20->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");
   tex3->DrawLatex(40, 4, "MC 17.5 < #alpha < 20");

   chi1->Print("JERPlots/Chi_ndf.ps");

   /////////////////////////////////////////////
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_Data_17p5->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");
   tex3->DrawLatex(40, 4, "Data 15 < #alpha < 17.5");

   chi1->Print("JERPlots/Chi_ndf.ps");

   /////////////////////////////////////////////
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_MC_17p5->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");
   tex3->DrawLatex(40, 4, "MC 15 < #alpha < 17.5");

   chi1->Print("JERPlots/Chi_ndf.ps");

   /////////////////////////////////////////////
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_Data_15->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");
   tex3->DrawLatex(40, 4, "Data 12.5 < #alpha < 15");

   chi1->Print("JERPlots/Chi_ndf.ps");

   /////////////////////////////////////////////
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_MC_15->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");
   tex3->DrawLatex(40, 4, "MC 12.5 < #alpha < 15");

   chi1->Print("JERPlots/Chi_ndf.ps");

   /////////////////////////////////////////////
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_Data_12p5->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");
   tex3->DrawLatex(40, 4, "Data 10 < #alpha < 12.5");

   chi1->Print("JERPlots/Chi_ndf.ps");

   /////////////////////////////////////////////
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_MC_12p5->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");
   tex3->DrawLatex(40, 4, "MC 10 < #alpha < 12.5");

   chi1->Print("JERPlots/Chi_ndf.ps");

   /////////////////////////////////////////////
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_Data_10->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");
   tex3->DrawLatex(40, 4, "Data 0 < #alpha < 10");

   chi1->Print("JERPlots/Chi_ndf.ps");

   /////////////////////////////////////////////
   chi_ndf_Data_25->GetXaxis()->SetTitle("ndf");
   chi_ndf_Data_25->GetYaxis()->SetTitle("#chi2");
   chi_ndf_MC_10->Draw("colz");
   lin1->Draw("same");
   lin2->Draw("same");

   tex1->DrawLatex(45, 40, "#chi2/ndf = 1");
   tex2->DrawLatex(38, 70, "#chi2/ndf = 2");
   tex3->DrawLatex(40, 4, "MC 0 < #alpha < 10");

   chi1->Print("JERPlots/Chi_ndf.ps)");


}
