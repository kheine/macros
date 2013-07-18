#include "PlottingUtils.C"

using namespace std;

void PlotQCDPredictionsMC()
{
   gROOT->ProcessLine(".L PlottingUtils.C+");
    
   PlottingUtils::SetPlotStyle();

   // which sample
   TString postfix = "madgraph_DR53X_chs_TuneZ2star_pt10_withoutPUReweighting_UseRebCorrection_v1";

   // legend entries + ratio title
   TString Hist1Legend = "R+S Prediction from MC";
   //TString Hist1Legend = "Smeared Generator Jets";
   TString Hist2Legend = "MC Expectation";
   TString StatUnc = "Stat. unc. MC";
   TString RatioTitle  = "(Pred-MC)/MC";
   //TString RatioTitle  = "(Gen-MC)/MC";

   // lumi text
   TString HistLabel = "CMS Simulation, L = 19.5 fb^{  -1}, #sqrt{s} = 8 TeV";
   //TString HistLabel = "Work in progress, L = 19.5 fb^{  -1}, #sqrt{s} = 8 TeV";

   // path to sample directory
   TString path = "/afs/naf.desy.de/user/k/kriheine/scratch/CMSSW_5_3_5/src/RA2Classic/QCDBkgRS/test/QCDPrediction/outpout_GetPrediction/" + postfix;

   // output .ps file
   TString psfile = "QCDPredictionPlots/QCDPrediction_" + postfix + ".ps";

   // --------------------------------------------------------------------------------------------- //
   // define input files
   vector<TFile*> files;
   files.push_back( new TFile(path + "/prediction_histos.root", "READ") );
   
   // open input file
   PlottingUtils::SetInputFiles(files);
    
   // --------------------------------------------------------------------------------------------- //
   // NJets
   TCanvas *c = PlottingUtils::DrawHistPlusCurveWithRatio("NJets_baseline_withoutMHT_pred_px", 
                                                          "NJets_baseline_withoutMHT_sel", "N_{Jets}", "Events/GeV",
                                                          "N_{Jets} #geq 3, #Delta#phi cut, H_{T} > 500 GeV", 
                                                          HistLabel, 
                                                          Hist1Legend, Hist2Legend, StatUnc,
                                                          RatioTitle);
   c->Print( psfile  + "[");
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/NJets_baseline_withoutMHT_" + postfix + ".pdf" );

   c = PlottingUtils::DrawHistPlusCurveWithRatio("NJets_baseline_withoutDeltaPhi_pred_px", 
                                                 "NJets_baseline_withoutDeltaPhi_sel", "N_{Jets}", "Events/GeV",
                                                 "N_{Jets} #geq 3, H_{T} > 500 GeV, #slash{H}_{T} > 200 GeV ", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle);
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/NJets_baseline_withoutDeltaPhi_" + postfix + ".pdf" );
 
   // --------------------------------------------------------------------------------------------- //
   // MHT for different HT + NJet bins
   c = PlottingUtils::DrawHistPlusCurveWithRatio("MHT_JetBin1_HTlow_pred_px", 
                                                 "MHT_JetBin1_HTlow_sel", "#slash{H}_{T} [GeV]", 
                                                 "Events/GeV", "N_{Jets} = 2, #Delta#phi cut, H_{T} = 500 - 1000 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle);
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/MHT_JetBin1_HTlow_" + postfix + ".pdf" );

   c = PlottingUtils::DrawHistPlusCurveWithRatio("MHT_JetBin2_HTlow_pred_px", 
                                                 "MHT_JetBin2_HTlow_sel", "#slash{H}_{T} [GeV]", 
                                                 "Events/GeV", "3 #leq N_{Jets} #leq 5, #Delta#phi cut, H_{T} = 500 - 1000 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle); 
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/MHT_JetBin2_HTlow_" + postfix + ".pdf" );
 
   c = PlottingUtils::DrawHistPlusCurveWithRatio("MHT_JetBin3_HTlow_pred_px", 
                                                 "MHT_JetBin3_HTlow_sel", "#slash{H}_{T} [GeV]", 
                                                 "Events/GeV", "6 #leq N_{Jets} #leq 7, #Delta#phi cut, H_{T} = 500 - 1000 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle); 
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/MHT_JetBin3_HTlow_" + postfix + ".pdf" );

   c = PlottingUtils::DrawHistPlusCurveWithRatio("MHT_JetBin4_HTlow_pred_px", 
                                                 "MHT_JetBin4_HTlow_sel", "#slash{H}_{T} [GeV]", 
                                                 "Events/GeV", "N_{Jets} #geq 8, #Delta#phi cut, H_{T} = 500 - 1000 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle); 
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/MHT_JetBin4_HTlow_" + postfix + ".pdf" );

   // --------------------------------------------------------------------------------------------- //
   c = PlottingUtils::DrawHistPlusCurveWithRatio("MHT_JetBin1_HThigh_pred_px", 
                                                 "MHT_JetBin1_HThigh_sel", "#slash{H}_{T} [GeV]", 
                                                 "Events/GeV", "N_{Jets} = 2, #Delta#phi cut, H_{T} #geq 1000 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle);
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/MHT_JetBin1_HThigh_" + postfix + ".pdf" );

   c = PlottingUtils::DrawHistPlusCurveWithRatio("MHT_JetBin2_HThigh_pred_px", 
                                                 "MHT_JetBin2_HThigh_sel", "#slash{H}_{T} [GeV]", 
                                                 "Events/GeV", "3 #leq N_{Jets} #leq 5, #Delta#phi cut, H_{T} #geq 1000 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle); 
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/MHT_JetBin2_HThigh_" + postfix + ".pdf" );

   c = PlottingUtils::DrawHistPlusCurveWithRatio("MHT_JetBin3_HThigh_pred_px", 
                                                 "MHT_JetBin3_HThigh_sel", "#slash{H}_{T} [GeV]", 
                                                 "Events/GeV", "6 #leq N_{Jets} #leq 7, #Delta#phi cut, H_{T} #geq 1000 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle); 
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/MHT_JetBin3_HThigh_" + postfix + ".pdf" ); 
 

   c = PlottingUtils::DrawHistPlusCurveWithRatio("MHT_JetBin4_HThigh_pred_px", 
                                                 "MHT_JetBin4_HThigh_sel", "#slash{H}_{T} [GeV]", 
                                                 "Events/GeV", "N_{Jets} #geq 8, #Delta#phi cut, H_{T} #geq 1000 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle); 
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/MHT_JetBin4_HThigh_" + postfix + ".pdf" ); 
   // --------------------------------------------------------------------------------------------- //
   // MHT for baseline
   c = PlottingUtils::DrawHistPlusCurveWithRatio("MHT_baseline_pred_px", 
                                                 "MHT_baseline_sel", "#slash{H}_{T} [GeV]", 
                                                 "Events/GeV", "N_{Jets} #geq 3, #Delta#phi cut, H_{T} > 500 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle);
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/MHT_baseline_" + postfix + ".pdf" );

   // --------------------------------------------------------------------------------------------- //
   // HT for baseline without MHT cut
   gStyle->SetNdivisions(505, "X");
   gROOT->ForceStyle();
   c = PlottingUtils::DrawHistPlusCurveWithRatio("deltaPhi_HT_prediction_px", 
                                                 "deltaPhi_HT_selection", "H_{T} [GeV]", 
                                                 "Events/GeV", "N_{Jets} #geq 3, #Delta#phi cut, H_{T} > 500 GeV", 
                                                 HistLabel, 
                                                 Hist1Legend, Hist2Legend, StatUnc,
                                                 RatioTitle);
   c->Print( psfile );
   c->Print( "QCDPredictionPlots/HT_baseline_withoutMHT_" + postfix + ".pdf" );

   c->Print( psfile + "]" );
}


