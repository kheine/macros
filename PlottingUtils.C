#ifndef PlottingUtils
#define PlottingUtils

// ROOT includes
#include "TROOT.h"
#include "TSystem.h"
#include "TH1.h"
#include "TH2.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TChain.h"
#include "TPad.h"
#include "TStyle.h"
#include "TFile.h"
#include "TPostScript.h"
#include "TLegend.h"
#include "TMath.h"
#include "TString.h"
#include "TArrayF.h"
#include "TLine.h"
#include "TPaveText.h"
#include "TObject.h"
#include "TList.h"
#include "TDirectory.h"
#include "TClass.h"
#include "TKey.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TImage.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TMarker.h"

// STL include(s):
#include "iostream"
#include "fstream"
#include "vector"
#include "string"
using std::cout;
using std::endl;
using std::vector;
using std::iterator;

namespace PlottingUtils {

   // configuration --------------------------------------------------
   vector<TFile*> inputFiles;
   void SetInputFiles( vector<TFile*> &files ) { inputFiles = files; } 

   // constants, enums, global variables -----------------------------
   static Int_t c_LightBrown   = TColor::GetColor( "#D9D9CC" );
   static Int_t c_LightGray    = TColor::GetColor( "#DDDDDD" );

   const Int_t CanvasRatioPlot[]  = { 0, 0, 700, 700 };
   const Int_t CanvasPlot[]       = { 0, 0, 700, 700 };

   const Int_t c_MarkerStyle[] = { 20, 21, 22, 23, 24 };
   const Int_t c_MarkerColor[] = { kBlack, kAzure-3, kPink-3, kYellow-9, kGreen+1, kRed };
   const Int_t c_FillColor[]   = { kBlack, kAzure-3, kPink-3, kYellow-9, kGreen+1, kRed };
   const Int_t c_LineColor[]   = { kBlack, kAzure-3, kPink-3, kYellow-9, kGreen+1, kRed };

   // ----------------------------------------------------------------
  
   void SetPlotStyle() {

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
      gStyle->SetMarkerSize(0.9);
      gStyle->SetMarkerStyle(20);
      gStyle->SetMarkerColor(1);
  
      // For the statistics box:
      gStyle->SetOptStat(0);
      //gStyle->SetOptFit(1011);
  
      // Margins:
      gStyle->SetPadBottomMargin(0.25);
      gStyle->SetPadTopMargin(0.15);
      // gStyle->SetPadBottomMargin(0.3);
      //gStyle->SetPadTopMargin(0.12);
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
      gStyle->SetTitleOffset(1.25, "Y");
      gStyle->SetTitleOffset(0.5, "Z");
      gStyle->SetTitleSize(0.05, "XYZ");
      gStyle->SetTitleFont(42, "XYZ");
      //gStyle->SetTitleX(0.15);
      //gStyle->SetTitleY(0.99);

      // For the axis labels:
      gStyle->SetLabelSize(0.04, "XYZ");
      gStyle->SetLabelOffset(0.01, "XYZ");
      gStyle->SetLabelFont(42, "XYZ");

      // For the legend
      gStyle->SetLegendBorderSize(0);
   }

   TCanvas* DrawHistPlusCurveWithRatio(TString hname1, TString hname2, TString xTitle, TString yTitle, 
                                   TString HistTitle="", TString HistLabel="", TString Hist1Legend="",
                                   TString Hist2Legend="", TString RatioTitle="") {
      // vector<TFile*>::iterator it = inputFiles.begin();
      if( !inputFiles.at(0) ){
         cout << "No input Files are specified! ==> abort macro execution" << endl;
         exit(-1);
      }

      gStyle->SetPadBottomMargin(0.3);
      gStyle->SetPadTopMargin(0.12);

      TCanvas *c = new TCanvas("ca", "Comparison and ratio of two histos", CanvasRatioPlot[2], 
                               CanvasRatioPlot[3]);
      
      // retrieve histograms
      TH1F *h1, *h2;
      h1 = (TH1F*)inputFiles.at(0)->Get( hname1 );
      h2 = (TH1F*)inputFiles.at(0)->Get( hname2 );
      if (!h1) {
         cout << "*** Error: unknown histogram " << hname1 << " in file: " 
              << inputFiles.at(0) << " ==> skip plot!!!" << endl;
         return c;
      }
      if (!h2) {
         cout << "*** Error: unknown histogram " << hname2 << " in file: " 
              << inputFiles.at(0) << " ==> skip plot!!!" << endl;
         return c;
      }

      Double_t xMin1 = h1->GetXaxis()->GetXmin();
      Double_t xMax1 = h1->GetXaxis()->GetXmax();
     

      Int_t NBins = h1->GetNbinsX();
      Double_t yMin1 = h1->GetBinContent(h1->GetMaximumBin());
      for ( int i = 0; i < NBins; i++) {
         double min = h1->GetBinContent(i);
         if ( min < yMin1 && min != 0 ) yMin1 = min;
      }
      Double_t yMax1 = h1->GetBinContent(h1->GetMaximumBin());
      Double_t yRangeMax = 120.* yMax1;

      if( hname1.Contains("deltaPhi_HT") && hname2.Contains("deltaPhi_HT") ) {
         h1->SetBinContent(4, 0);
         h1->SetBinContent(5, 0);
         h2->SetBinContent(4, 0);
         h2->SetBinContent(5, 0);
      }

      h1->SetAxisRange(xMin1, xMax1, "X");
      h1->SetMarkerStyle(20);
      h1->SetMarkerSize(0.9);
      h1->SetMarkerColor(kBlack);
      h1->SetAxisRange(yMin1-(0.8*yMin1), yRangeMax, "Y");
      h2->SetAxisRange(xMin1, xMax1, "X");
      h2->SetAxisRange(yMin1-(0.8*yMin1), yRangeMax, "Y");
      h2->SetFillColor(c_LightGray);
      h2->SetLabelSize(0.045, "XYZ");
      h2->SetXTitle(xTitle);
      h2->SetYTitle(yTitle);
       
      TPad *pad1 = new TPad("pad1a", "pad1a", 0, 0.35, 1, 1);
      pad1->SetLogy();
      pad1->SetBottomMargin(0);
      pad1->Draw();
      pad1->cd();
  
      h2->DrawCopy("hist");
      h1->Draw("same");
      h2->SetFillColor(kAzure-3);
      h2->SetFillStyle(3354);
      h2->DrawCopy("e2same");
      h2->SetFillStyle(1001);
      h2->SetFillColor(c_LightGray);

      //TLegend* leg1 = new TLegend(0.44, 0.63, 0.91, 0.83);
      TLegend* leg1 = new TLegend(0.46, 0.65, 0.93, 0.85);
      leg1->SetFillStyle(0);
      leg1->SetLineStyle(1);
      leg1->SetTextFont(42);
      leg1->SetTextSize(0.045);
      leg1->AddEntry(h2, Hist2Legend, "lf");
      leg1->AddEntry(h1, Hist1Legend, "lep");
      leg1->Draw("same");
 
      // TPaveText* pt = new TPaveText(0.11, 0.98, 0.95, 0.86, "NDC");
      TPaveText* pt = new TPaveText(0.11, 1.00, 0.95, 0.88, "NDC");
      pt->SetBorderSize(0);
      pt->SetFillStyle(0);
      pt->SetTextAlign(12);
      pt->SetTextSize(0.045);
      pt->AddText(HistTitle);
      pt->AddText(HistLabel);
      pt->Draw();

      c->cd();
      TPad *pad2 = new TPad("pad2a", "pad2a", 0, 0, 1, 0.35);
      pad2->SetTopMargin(0);
      pad2->Draw();
      pad2->cd();
      TH1F* r = new TH1F(*h2);
      r->SetTitle("");
      r->SetLabelSize(0.095, "XYZ");
      r->SetLabelOffset(0.015, "XYZ");
      r->SetTitleSize(0.125, "XYZ");
      //r->SetTitleOffset(0.90, "X");
      r->SetTitleOffset(1.1, "X");
      r->SetTitleOffset(0.53, "Y");
      r->SetTickLength(0.05);
      r->SetYTitle(RatioTitle);
      r->SetStats(0);
      r->SetMarkerStyle(20);
      r->SetMarkerSize(0.9);
      r->SetMarkerColor(kBlack);
      r->Reset();
      r->Add(h1, 1);
      r->Add(h2, -1);
      r->Divide(h2);
      r->SetMaximum(1.2);
      r->SetMinimum(-1.2);
      r->Draw("ep");
      TLine l;
      l.DrawLine(xMin1, 0., xMax1, 0.);
      c->cd();
      return c;
   }

   TCanvas* Draw2CurvesWithRatio(TH1F* h1, TH1F* h2, TString xTitle, TString yTitle, 
                                   TString HistTitle="", TString HistLabel="", TString Hist1Legend="",
                                   TString Hist2Legend="", TString RatioTitle="") {
    
      gStyle->SetPadBottomMargin(0.3);
      gStyle->SetPadTopMargin(0.12);

      TCanvas *c = new TCanvas("ca", "Comparison and ratio of two histos", CanvasRatioPlot[2], 
                               CanvasRatioPlot[3]);
      
      Double_t xMin1 = h1->GetXaxis()->GetXmin();
      Double_t xMax1 = h1->GetXaxis()->GetXmax();

      TPad *pad1 = new TPad("pad1a", "pad1a", 0, 0.35, 1, 1);
      pad1->SetBottomMargin(0);
      pad1->Draw();
      pad1->cd();

      h1->SetXTitle(xTitle);
      h1->SetYTitle(yTitle);
      h1->SetLabelSize(0.045, "XYZ");
      h1->SetLabelOffset(0.015, "XYZ");
      h1->SetTitleSize(0.07, "Y");
      h1->SetTitleOffset(0.85, "Y");
      h1->Draw();
      h2->SetMarkerStyle(PlottingUtils::c_MarkerStyle[1]);
      h2->SetLineColor(PlottingUtils::c_LineColor[1]);
      h2->SetMarkerColor(PlottingUtils::c_MarkerColor[1]);
      h2->Draw("same");
         
      TLegend* leg1 = new TLegend(0.46, 0.65, 0.93, 0.85);
      // TLegend* leg1 = new TLegend(0.44, 0.63, 0.91, 0.83);
      leg1->SetFillStyle(0);
      leg1->SetLineStyle(1);
      leg1->SetTextFont(42);
      leg1->SetTextSize(0.045);
      leg1->AddEntry(h1, Hist1Legend, "lep");
      leg1->AddEntry(h2, Hist2Legend, "lep");
      leg1->Draw("same");
 
      //TPaveText* pt = new TPaveText(0.11, 0.98, 0.95, 0.86, "NDC");
      TPaveText* pt = new TPaveText(0.11, 1.00, 0.95, 0.88, "NDC");
      pt->SetBorderSize(0);
      pt->SetFillStyle(0);
      pt->SetTextAlign(12);
      pt->SetTextSize(0.045);
      pt->AddText(HistTitle);
      pt->AddText(HistLabel);
      pt->Draw();

      c->cd();
      TPad *pad2 = new TPad("pad2a", "pad2a", 0, 0, 1, 0.35);
      pad2->SetTopMargin(0);
      pad2->Draw();
      pad2->cd();
      TH1F* r = new TH1F(*h2);
      r->SetTitle("");
      r->SetLabelSize(0.095, "XYZ");
      r->SetLabelOffset(0.015, "XYZ");
      r->SetTitleSize(0.125, "XYZ");
      // r->SetTitleOffset(0.88, "X");
      r->SetTitleOffset(1.1, "X");
      r->SetTitleOffset(0.53, "Y");
      r->SetTickLength(0.05);
      r->SetYTitle(RatioTitle);
      r->SetStats(0);
      r->SetMarkerStyle(20);
      r->SetMarkerSize(0.9);
      r->SetMarkerColor(kBlack);
      r->SetLineColor(PlottingUtils::c_LineColor[0]);
      r->Reset();
      r->Add(h1, 1);
      r->Add(h2, -1);
      r->Divide(h2);
      r->SetMaximum(0.07);
      r->SetMinimum(-0.07);
      r->Draw("ep");
      TLine l;
      l.DrawLine(xMin1, 0., xMax1, 0.);
      c->cd();
      return c;
   }

   /// for Canvas size 700, 700 without ratio
   TPaveText* CMSLabelMC(TString lumi) { 
      TPaveText* pt1 = new TPaveText(0.11, 0.9, 0.95, 0.86, "NDC");
      pt1->SetBorderSize(0);
      pt1->SetFillStyle(0);
      pt1->SetTextAlign(12);
      pt1->SetTextSize(0.03);
      pt1->AddText("CMS Simulation, L = " + lumi + " fb^{  -1}, #sqrt{s} = 8 TeV");
      return pt1;
   }

   /// for Canvas size 700, 700 without ratio
   TPaveText* CMSLabelData(TString lumi) { 
      TPaveText* pt1 = new TPaveText(0.11, 0.9, 0.95, 0.86, "NDC");
      pt1->SetBorderSize(0);
      pt1->SetFillStyle(0);
      pt1->SetTextAlign(12);
      pt1->SetTextSize(0.03);
      pt1->AddText("CMS Preliminary, L = " + lumi + " fb^{  -1}, #sqrt{s} = 8 TeV");
      return pt1;
   }

   /// for Canvas size 700, 700 without ratio
   TLegend* Legend3Entries(TObject* hist1, TObject* hist2, TObject* hist3,
                           TString entry1, TString entry2, TString entry3) {
      TLegend* leg = new TLegend(0.5, 0.65, 0.7, 0.82);
      leg->SetFillStyle(0);
      leg->SetLineStyle(1);
      leg->SetTextFont(42);
      leg->SetTextSize(0.04);
      leg->AddEntry(hist1, entry1, "lep");
      leg->AddEntry(hist2, entry2, "lep");
      leg->AddEntry(hist3, entry3, "lep");
      return leg;
   }


}
#endif
