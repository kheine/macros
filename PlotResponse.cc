#include "PlottingUtils.C"

using namespace std;

void PlotResponse(){

   // gROOT->ProcessLine(".L PlottingUtils.C+");
   
   // PlottingUtils::SetPlotStyle();

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

   gROOT->ForceStyle();

   vector<double> PtBinEdges;
   vector<double> EtaBinEdges;
   PtBinEdges.push_back(0);
   PtBinEdges.push_back(20);
   PtBinEdges.push_back(30);
   PtBinEdges.push_back(50);
   PtBinEdges.push_back(80);
   PtBinEdges.push_back(120);
   PtBinEdges.push_back(170);
   PtBinEdges.push_back(230);
   PtBinEdges.push_back(300);
   PtBinEdges.push_back(380);
   PtBinEdges.push_back(470);
   PtBinEdges.push_back(570);
   PtBinEdges.push_back(680);
   PtBinEdges.push_back(800);
   PtBinEdges.push_back(1000);
   PtBinEdges.push_back(1300);
   PtBinEdges.push_back(1700);
   PtBinEdges.push_back(2200);
   PtBinEdges.push_back(2800);
   PtBinEdges.push_back(3500);

   EtaBinEdges.push_back(0.0);
   EtaBinEdges.push_back(0.3);
   EtaBinEdges.push_back(0.5);
   EtaBinEdges.push_back(0.8);
   EtaBinEdges.push_back(1.1);
   EtaBinEdges.push_back(1.4);
   EtaBinEdges.push_back(1.7);
   EtaBinEdges.push_back(2.0);
   EtaBinEdges.push_back(2.3);
   EtaBinEdges.push_back(2.8);
   EtaBinEdges.push_back(3.2);
   EtaBinEdges.push_back(4.1);
   EtaBinEdges.push_back(5.0);

   // TFile *f1 = TFile::Open(
   // "~/Resolution/MCJetResolution_Summer11_QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_fine_v3.root");
   //TFile *f2 = TFile::Open("~/Resolution/MCResolutions_Fall11_QCD_Pt-15to3000_TuneZ2_7TeV_pythia6_fine.root");

   TFile *f1 = TFile::Open("~/Resolution/MCJetResolutions_Summer12_DR53X_QCD_Pt_15to3000_TuneZ2star_Flat_8TeV_pythia6_withCHS_withoutPUReweighting.root");
   TFile *f2 = TFile::Open("~/Resolution/MCJetResolutions_Summer12_DR53X_QCD_HT_100ToInf_TuneZ2star_8TeV_madgraph_withCHS_withoutPUReweighting.root");

   TCanvas* c = new TCanvas("c", "my Canvas", 700, 700);
   c->SetLogy();
  
   int rebin = 2;
   double rmin = 0.;
   double rmax = 2.;
   double ymin = 5;

   TH1F* Res_1;
   TH1F* Res_2;

   char dummy[100];
   char dummy1[100];
   char dummy2[100];
   char* multiplicity = "_JetAll";

   c->Print("ResponseTemplate_b_all_pythia.ps(");

   for (int iPt = 1; iPt < 20; ++iPt) {

      for (int iEta = 1; iEta < 12; ++iEta) {

         sprintf(dummy1, "h_tot%s_ResponsePt_Pt%i_Eta%i", multiplicity, iPt - 1, iEta - 1);
         cout << dummy1 << endl;
         sprintf(dummy2, "h_b%s_ResponsePt_Pt%i_Eta%i", multiplicity, iPt - 1, iEta - 1);
         cout << dummy2 << endl;
         Res_1 = (TH1F*) f1->FindObjectAny(dummy1);
         //Res_2 = (TH1F*) f2->FindObjectAny(dummy1);
         Res_2 = (TH1F*) f1->FindObjectAny(dummy2);

         double Int1 = Res_1->Integral();
         double Int2 = Res_2->Integral();
         cout << Int1 << " " << Int2 << endl;
         Res_1->Scale(1. / Int1);
         Res_2->Scale(1. / Int1);
         //Res_2->Scale(Int1 / Int2);

         Res_1->Rebin(rebin);
         Res_1->SetLineWidth(2);
         Res_1->SetLineColor(kBlue);

         Res_2->Rebin(rebin);
         Res_2->SetLineWidth(2);
         Res_2->SetLineStyle(2);
         Res_2->SetLineColor(kRed);

         Res_1->SetTitle("");
         Res_1->SetXTitle("p_{T}^{reco}/p_{T}^{gen}");
         Res_1->SetYTitle("a.u.");
         Res_1->SetAxisRange(rmin, rmax, "X");

         Res_1->DrawCopy("hist");
         Res_2->Draw("samehist");


         TLegend* leg = new TLegend(0.16, 0.70, 0.51, 0.82);
         leg->SetFillStyle(0);
         leg->SetLineStyle(1);
         leg->SetTextFont(42);
         leg->SetTextSize(0.045);
         //leg->AddEntry(Res_1, "pythia", "l");
         //leg->AddEntry(Res_2, "madgraph", "l");
         leg->AddEntry(Res_1, "All jets", "l");
         leg->AddEntry(Res_2, "b jets", "l");
         leg->Draw("same");

         TPaveText* pt = new TPaveText(0.11, 0.94, 0.95, 0.86, "NDC");
         pt->SetBorderSize(0);
         pt->SetFillStyle(0);
         pt->SetTextAlign(12);
         pt->SetTextSize(0.03);
         sprintf(dummy, "%i GeV < p_{T}^{gen} < %i GeV, %3.1f < |#eta| < %3.1f", (int) PtBinEdges.at(iPt - 1),
                 (int) PtBinEdges.at(iPt), EtaBinEdges.at(iEta - 1), EtaBinEdges.at(iEta));
         pt->AddText(dummy);
         pt->AddText("CMS Simulation, L = 19.47 fb^{  -1}, #sqrt{s} = 8 TeV");
         pt->Draw();

         c->Print("ResponseTemplate_b_all_pythia.ps");

         if (iPt == 11 && iEta == 1)
            c->Print("ResponseTemplate_b_all_pythia.png");

         //         if (iPt == 1 && iEta == 1) {
         //            c->Print("Response.ps(");
         //         } else if (iPt == 19 && iEta == 12) {
         //            c->Print("Response.ps)");
         //         } else {
         //            c->Print("Response.ps");
         //         }

      }

   }

   c->Print("ResponseTemplate_b_all_pythia.ps)");

   //  return 0;
}
