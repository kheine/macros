#include "/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/scripts/tdrstyle_mod.C"
#include <TROOT.h>
#include <TF1.h>
#include <TH1.h>
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

#ifdef __MAKECINT__
#pragma link C++ class vector<TMatrixD>;
#endif

void PlotAsymmetry()
{
   setTDRStyle();

   gROOT->ProcessLine("#include <vector>");

   std::vector<std::vector<TH1D*> > DataAsymmetry_Alpha40_Eta_PtDist;
   std::vector<std::vector<TH1D*> > DataAsymmetry_Alpha30_Eta_PtDist;
   std::vector<std::vector<TH1D*> > DataAsymmetry_Alpha20_Eta_PtDist;
   std::vector<std::vector<TH1D*> > DataAsymmetry_Alpha10_Eta_PtDist;

   std::vector<std::vector<TH1D*> > MCAsymmetry_Alpha40_Eta_PtDist;
   std::vector<std::vector<TH1D*> > MCAsymmetry_Alpha30_Eta_PtDist;
   std::vector<std::vector<TH1D*> > MCAsymmetry_Alpha20_Eta_PtDist;
   std::vector<std::vector<TH1D*> > MCAsymmetry_Alpha10_Eta_PtDist;

   // -------------------------------------------------------------------------- //
   // resize vectors
   DataAsymmetry_Alpha40_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = DataAsymmetry_Alpha40_Eta_PtDist.begin(); it != DataAsymmetry_Alpha40_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   DataAsymmetry_Alpha30_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = DataAsymmetry_Alpha30_Eta_PtDist.begin(); it != DataAsymmetry_Alpha30_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   DataAsymmetry_Alpha20_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = DataAsymmetry_Alpha20_Eta_PtDist.begin(); it != DataAsymmetry_Alpha20_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   DataAsymmetry_Alpha10_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = DataAsymmetry_Alpha10_Eta_PtDist.begin(); it != DataAsymmetry_Alpha10_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   MCAsymmetry_Alpha40_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = MCAsymmetry_Alpha40_Eta_PtDist.begin(); it != MCAsymmetry_Alpha40_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   MCAsymmetry_Alpha30_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = MCAsymmetry_Alpha30_Eta_PtDist.begin(); it != MCAsymmetry_Alpha30_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   MCAsymmetry_Alpha20_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = MCAsymmetry_Alpha20_Eta_PtDist.begin(); it != MCAsymmetry_Alpha20_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   MCAsymmetry_Alpha10_Eta_PtDist.resize(5);
   for (std::vector<std::vector<TH1D*> >::iterator it = MCAsymmetry_Alpha10_Eta_PtDist.begin(); it != MCAsymmetry_Alpha10_Eta_PtDist.end(); ++it) {
      it->resize(15);
   }

   // -------------------------------------------------------------------------- //
   //// open root file
   TFile* file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/20122012ABCD_ReReco_CORR2012FallV5_AK5_MC_Su12Z253_pythia_kostas_DefaultTestTEstTest/dijetsFall10_TuneZ2_AK5PF_weighted_residuals_JERMatt/plots/KalibriPlots.root", "READ");
   //TFile* file = new TFile("/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/20122012ABCD_208686_CORR2012FallV5_AK5_MC_Su12Z253_pythia_kostas_DefaultTestTEstTest_alphaExclusive/dijetsFall10_TuneZ2_AK5PF_weighted_residuals_JERMatt/plots/KalibriPlots.root", "READ");


   TString hname_Data_40;
   TString hname_Data_30;
   TString hname_Data_20;
   TString hname_Data_10;

   TString hname_MC_40;
   TString hname_MC_30;
   TString hname_MC_20;
   TString hname_MC_10;

   // ----------------------------- //
   TTree t1("Cov_tree", "Tree with covariance matrices");

   std::vector<TMatrixD> Cov_Data_Eta0_Pt;
   std::vector<TMatrixD> Cov_Data_Eta1_Pt;
   std::vector<TMatrixD> Cov_Data_Eta2_Pt;
   std::vector<TMatrixD> Cov_Data_Eta3_Pt;
   std::vector<TMatrixD> Cov_Data_Eta4_Pt;
   std::vector<TMatrixD> Cov_MC_Eta0_Pt;
   std::vector<TMatrixD> Cov_MC_Eta1_Pt;
   std::vector<TMatrixD> Cov_MC_Eta2_Pt;
   std::vector<TMatrixD> Cov_MC_Eta3_Pt;
   std::vector<TMatrixD> Cov_MC_Eta4_Pt;

   std::vector<TMatrixD> *t_Cov_Data_Eta0_Pt = &Cov_Data_Eta0_Pt;
   std::vector<TMatrixD> *t_Cov_Data_Eta1_Pt = &Cov_Data_Eta1_Pt;
   std::vector<TMatrixD> *t_Cov_Data_Eta2_Pt = &Cov_Data_Eta2_Pt;
   std::vector<TMatrixD> *t_Cov_Data_Eta3_Pt = &Cov_Data_Eta3_Pt;
   std::vector<TMatrixD> *t_Cov_Data_Eta4_Pt = &Cov_Data_Eta4_Pt;
   std::vector<TMatrixD> *t_Cov_MC_Eta0_Pt = &Cov_MC_Eta0_Pt;
   std::vector<TMatrixD> *t_Cov_MC_Eta1_Pt = &Cov_MC_Eta1_Pt;
   std::vector<TMatrixD> *t_Cov_MC_Eta2_Pt = &Cov_MC_Eta2_Pt;
   std::vector<TMatrixD> *t_Cov_MC_Eta3_Pt = &Cov_MC_Eta3_Pt;
   std::vector<TMatrixD> *t_Cov_MC_Eta4_Pt = &Cov_MC_Eta4_Pt;

   t1.Branch("Cov_Data_Eta0_Pt","std::vector<TMatrixD>",&t_Cov_Data_Eta0_Pt);
   t1.Branch("Cov_Data_Eta1_Pt","std::vector<TMatrixD>",&t_Cov_Data_Eta1_Pt);
   t1.Branch("Cov_Data_Eta2_Pt","std::vector<TMatrixD>",&t_Cov_Data_Eta2_Pt);
   t1.Branch("Cov_Data_Eta3_Pt","std::vector<TMatrixD>",&t_Cov_Data_Eta3_Pt);
   t1.Branch("Cov_Data_Eta4_Pt","std::vector<TMatrixD>",&t_Cov_Data_Eta4_Pt);
   t1.Branch("Cov_MC_Eta0_Pt","std::vector<TMatrixD>",&t_Cov_MC_Eta0_Pt);
   t1.Branch("Cov_MC_Eta1_Pt","std::vector<TMatrixD>",&t_Cov_MC_Eta1_Pt);
   t1.Branch("Cov_MC_Eta2_Pt","std::vector<TMatrixD>",&t_Cov_MC_Eta2_Pt);
   t1.Branch("Cov_MC_Eta3_Pt","std::vector<TMatrixD>",&t_Cov_MC_Eta3_Pt);
   t1.Branch("Cov_MC_Eta4_Pt","std::vector<TMatrixD>",&t_Cov_MC_Eta4_Pt);

   //// get asymmetry histos
   for (unsigned int i_Eta = 0; i_Eta < 4; ++i_Eta) {
      for (unsigned int i_Dist = 0; i_Dist < 15; ++i_Dist) {
         // -------------------------------------------------------------------------- //
         //// Get the histos
         hname_Data_40 = Form("AbsAsymmetryVsPt40_AsymmetryVsMeanPt_data_L2L3res_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         hname_Data_30 = Form("AbsAsymmetryVsPt30_AsymmetryVsMeanPt_data_L2L3res_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         hname_Data_20 = Form("AbsAsymmetryVsPt20_AsymmetryVsMeanPt_data_L2L3res_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         hname_Data_10 = Form("AbsAsymmetryVsPt10_AsymmetryVsMeanPt_data_L2L3res_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);

         hname_MC_40 = Form("AbsAsymmetryVsPt40_AsymmetryVsMeanPt_MC_L2L3_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         hname_MC_30 = Form("AbsAsymmetryVsPt30_AsymmetryVsMeanPt_MC_L2L3_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         hname_MC_20 = Form("AbsAsymmetryVsPt20_AsymmetryVsMeanPt_MC_L2L3_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);
         hname_MC_10 = Form("AbsAsymmetryVsPt10_AsymmetryVsMeanPt_MC_L2L3_AbsEta%i_Distribution_%i", i_Eta, i_Dist+1);

         // -------------------------------------------------------------------------- //
         file->cd("AbsAsymmetryVsPt40");
         DataAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_Data_40);
         MCAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_MC_40);

         file->cd("AbsAsymmetryVsPt30");
         DataAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_Data_30);
         MCAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_MC_30);

         file->cd("AbsAsymmetryVsPt20");
         DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_Data_20);
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_MC_20);

         file->cd("AbsAsymmetryVsPt10");
         DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_Data_10);
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist) = (TH1D*) gDirectory->FindObjectAny(hname_MC_10);           

         // -------------------------------------------------------------------------- //
         // plot asymmetries
         TCanvas *c = new TCanvas("c1", "c1", 700, 700);
         c->SetLogy();
         TString title = MCAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->GetTitle();
         
         double max_y = MCAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximum();
         MCAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->GetXaxis()->SetTitle("(p_{T,1} - p_{T,2})/(p_{T,1} + p_{T,2})");
         MCAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetTitle("");
         MCAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetRangeUser(0.1, 3.5*max_y);
         MCAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->SetFillColor(38);
         MCAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(38);
         MCAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("hist");
         DataAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         DataAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(kBlack);
         DataAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerColor(kBlack);
         DataAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("same");
         
         TPaveText* pt = new TPaveText(0.16, 0.855, 0.95, 0.935, "NDC");
         pt->SetBorderSize(0);
         pt->SetFillStyle(0);
         pt->SetTextAlign(12);
         pt->SetTextFont(42);
         pt->SetTextSize(0.032);
         pt->AddText(title);
         pt->Draw("same");
         
         if(i_Eta == 0 && i_Dist == 0) c->Print("JERPlots/Asymmetry_Pt40.ps(");
         else if(i_Eta == 4 && i_Dist == 15) c->Print("JERPlots/Asymmetry_Pt40.ps)");
         else c->Print("JERPlots/Asymmetry_Pt40.ps");

         ///////////////////////////////////////////////
         TCanvas *c2 = new TCanvas("c2", "c2", 700, 700);
         c2->SetLogy();
         TString title2 = MCAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->GetTitle();
         
         double max_y2 = MCAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximum();
         MCAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->GetXaxis()->SetTitle("(p_{T,1} - p_{T,2})/(p_{T,1} + p_{T,2})");
         MCAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetTitle("");
         MCAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetRangeUser(0.1, 3.5*max_y2);
         MCAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->SetFillColor(38);
         MCAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(38);
         MCAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("hist");
         DataAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         DataAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(kBlack);
         DataAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerColor(kBlack);
         DataAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("same");
         
         TPaveText* pt2 = new TPaveText(0.16, 0.855, 0.95, 0.935, "NDC");
         pt2->SetBorderSize(0);
         pt2->SetFillStyle(0);
         pt2->SetTextAlign(12);
         pt2->SetTextFont(42);
         pt2->SetTextSize(0.032);
         pt2->AddText(title2);
         pt2->Draw("same");
         
         if(i_Eta == 0 && i_Dist == 0) c2->Print("JERPlots/Asymmetry_Pt30.ps(");
         else if(i_Eta == 4 && i_Dist == 15) c2->Print("JERPlots/Asymmetry_Pt30.ps)");
         else c2->Print("JERPlots/Asymmetry_Pt30.ps");

         ///////////////////////////////////////////////
         TCanvas *c3 = new TCanvas("c3", "c3", 700, 700);
         c3->SetLogy();
         TString title3 = MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetTitle();
         
         double max_y3 = MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximum();
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetXaxis()->SetTitle("(p_{T,1} - p_{T,2})/(p_{T,1} + p_{T,2})");
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetTitle("");
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetRangeUser(0.1, 3.5*max_y3);
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->SetFillColor(38);
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(38);
         MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("hist");
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
         
         if(i_Eta == 0 && i_Dist == 0) c3->Print("JERPlots/Asymmetry_Pt20.ps(");
         else if(i_Eta == 4 && i_Dist == 15) c3->Print("JERPlots/Asymmetry_Pt20.ps)");
         else c3->Print("JERPlots/Asymmetry_Pt20.ps");

         ///////////////////////////////////////////////
         TCanvas *c4 = new TCanvas("c4", "c4", 700, 700);
         c4->SetLogy();
         TString title4 = MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetTitle();
         
         double max_y4 = MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetMaximum();
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetXaxis()->SetTitle("(p_{T,1} - p_{T,2})/(p_{T,1} + p_{T,2})");
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetTitle("");
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetYaxis()->SetRangeUser(0.1, 3.5*max_y4);
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->SetFillColor(38);
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(38);
         MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("hist");
         DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerStyle(20);
         DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->SetLineColor(kBlack);
         DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->SetMarkerColor(kBlack);
         DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->Draw("same");
         
         TPaveText* pt4 = new TPaveText(0.16, 0.855, 0.95, 0.935, "NDC");
         pt4->SetBorderSize(0);
         pt4->SetFillStyle(0);
         pt4->SetTextAlign(12);
         pt4->SetTextFont(42);
         pt4->SetTextSize(0.032);
         pt4->AddText(title4);
         pt4->Draw("same");
         
         if(i_Eta == 0 && i_Dist == 0) c4->Print("JERPlots/Asymmetry_Pt10.ps(");
         else if(i_Eta == 4 && i_Dist == 15) c4->Print("JERPlots/Asymmetry_Pt10.ps)");
         else c4->Print("JERPlots/Asymmetry_Pt10.ps");

         // ------------------------------------------------------------------ //
         cout << "Weights: " << MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights() << endl;

         // get Covariance Matrix
         TMatrixD y_cov_data;
         TMatrixD y_cov_mc;
         y_cov_data.ResizeTo(4,4);
         y_cov_mc.ResizeTo(4,4);
            
         y_cov_data(0,0) = DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_data(0,1) = DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_data(0,2) = DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_data(0,3) = DataAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_data(1,1) = DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_data(1,2) = DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_data(1,3) = DataAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_data(2,2) = DataAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_data(2,3) = DataAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_data(3,3) = DataAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_data(1,0) = y_cov_data(0,1);
         y_cov_data(2,0) = y_cov_data(0,2);
         y_cov_data(3,0) = y_cov_data(0,3);
         y_cov_data(2,1) = y_cov_data(1,2);
         y_cov_data(3,1) = y_cov_data(1,3);
         y_cov_data(3,2) = y_cov_data(2,3);

         y_cov_mc(0,0) = MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_mc(0,1) = MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_mc(0,2) = MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_mc(0,3) = MCAsymmetry_Alpha10_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_mc(1,1) = MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_mc(1,2) = MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_mc(1,3) = MCAsymmetry_Alpha20_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_mc(2,2) = MCAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_mc(2,3) = MCAsymmetry_Alpha30_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_mc(3,3) = MCAsymmetry_Alpha40_Eta_PtDist.at(i_Eta).at(i_Dist)->GetSumOfWeights();
         y_cov_mc(1,0) = y_cov_mc(0,1);
         y_cov_mc(2,0) = y_cov_mc(0,2);
         y_cov_mc(3,0) = y_cov_mc(0,3);
         y_cov_mc(2,1) = y_cov_mc(1,2);
         y_cov_mc(3,1) = y_cov_mc(1,3);
         y_cov_mc(3,2) = y_cov_mc(2,3);

         if( i_Eta == 0 ) {
            t_Cov_Data_Eta0_Pt->push_back(y_cov_data);
            t_Cov_MC_Eta0_Pt->push_back(y_cov_mc);
         }
         if( i_Eta == 1 ) {
            t_Cov_Data_Eta1_Pt->push_back(y_cov_data);
            t_Cov_MC_Eta1_Pt->push_back(y_cov_mc);
         }
         if( i_Eta == 2 ) {
            t_Cov_Data_Eta2_Pt->push_back(y_cov_data);
            t_Cov_MC_Eta2_Pt->push_back(y_cov_mc);
         }
         if( i_Eta == 3 ) {
            t_Cov_Data_Eta3_Pt->push_back(y_cov_data);
            t_Cov_MC_Eta3_Pt->push_back(y_cov_mc);
         }
         if( i_Eta == 4 ) {
            t_Cov_Data_Eta4_Pt->push_back(y_cov_data);
            t_Cov_MC_Eta4_Pt->push_back(y_cov_mc);
         }

      }
   }

   t1.Fill();

   // write matrices to file
   TFile *matrix_file = new TFile("Matrix_outfile.root", "RECREATE");
   t1.Write();
   
   matrix_file->Write();
}
