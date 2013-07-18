#include "PlottingUtils.C"

using namespace std;

void PlotQCDPredictionsData()
{
   gROOT->ProcessLine(".L PlottingUtils.C+");
    
   PlottingUtils::SetPlotStyle();

   // which sample
   TString postfix = "Prediction_chsJets_535_Run2012ABCD_data_pt10_withUncertainties_UseRebCorrection_v3";

   // legend entries + ratio title
   TString Hist1Legend = "R+S Prediction from Data";
   TString Hist2Legend = "Selected Data";
   TString StatUnc = "Stat. unc. Data";
   TString RatioTitle  = "(Pred-Data)/Data";

   // lumi text
   TString HistLabel = "CMS Preliminary, L = 19.5 fb^{  -1}, #sqrt{s} = 8 TeV";
   //TString HistLabel = "Work in progress, L = 19.5 fb^{  -1}, #sqrt{s} = 8 TeV";
 
   // path to sample directory
   TString path = "/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/output_GetPrediction_WithUncertainties/" + postfix;

   // output .ps file
   TString psfile = "QCDPredictionPlots/QCD_" + postfix + ".ps";

   // --------------------------------------------------------------------------------------------- //
   // define input files
   vector<TFile*> files;
   files.push_back( new TFile(path + "/prediction_histos_nominal.root", "READ") );
   
   // open input file
   PlottingUtils::SetInputFiles(files);
    
   // --------------------------------------------------------------------------------------------- //
   // NJets
   TCanvas *c = PlottingUtils::DrawHistPlusCurveWithRatio("NJets_presel_HThigh_pred_raw_nominal_px", 
                                             "NJets_presel_HThigh_sel_nominal", "N_{Jets}", "Events",
                                             "N_{Jets} #geq 3, #Delta#phi cut inverted, H_{T} #geq 1000 GeV", 
                                             HistLabel, 
                                             Hist1Legend, Hist2Legend, StatUnc,
                                             RatioTitle);
   c->Print( psfile  + "[");
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/NJets_presel_HThigh_" + postfix + ".png" );
 
   // --------------------------------------------------------------------------------------------- //
   // HT
   c = PlottingUtils::DrawHistPlusCurveWithRatio("presel_HT_HThigh_prediction_nominal_px", 
                                                 "presel_HT_HThigh_selection_nominal", "H_{T} [GeV]", 
                                                 "Events", 
                                                 "N_{Jets} #geq 3, #Delta#phi cut inverted, H_{T} #geq 1000 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle);
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/HT_presel_HThigh_" + postfix + ".png" );

   // --------------------------------------------------------------------------------------------- //
   // MHT

   c = PlottingUtils::DrawHistPlusCurveWithRatio("presel_MHT_HThigh_prediction_nominal_px", 
                                                 "presel_MHT_HThigh_selection_nominal", "#slash{H}_{T} [GeV]",
                                                 "Events",
                                                 "N_{Jets} #geq 3, #Delta#phi cut inverted, H_{T} #geq 1000 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle); 
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/MHT_presel_HThigh_" + postfix + ".png" );

   // --------------------------------------------------------------------------------------------- //
   // Jet 1 Pt
 
   c = PlottingUtils::DrawHistPlusCurveWithRatio("presel_Jet1_Pt_HThigh_prediction_nominal_px", 
                                                 "presel_Jet1_Pt_HThigh_selection_nominal", "Jet_{1} p_{T} [GeV]",
                                                 "Events", 
                                                 "N_{Jets} #geq 3, #Delta#phi cut inverted, H_{T} #geq 1000 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle); 
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/Jet1Pt_presel_HThigh_" + postfix + ".png" );

   // Jet 1 eta
   c = PlottingUtils::DrawHistPlusCurveWithRatio("presel_Jet1_Eta_HThigh_prediction_nominal_px", 
                                                 "presel_Jet1_Eta_HThigh_selection_nominal", "Jet_{1} #eta",
                                                 "Events", 
                                                 "N_{Jets} #geq 3, #Delta#phi cut inverted, H_{T} #geq 1000 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle); 
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/Jet1Eta_presel_HThigh_" + postfix + ".png" );

   // --------------------------------------------------------------------------------------------- //
  
   c->Print( psfile + "]" );
}


