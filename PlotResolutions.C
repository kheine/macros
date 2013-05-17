#include <TROOT.h>
#include <TSystem.h>
#include <TF1.h>
#include <TH1.h>
#include <TH2.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TStyle.h>
#include <TFile.h>
#include <TPostScript.h>
#include <TLegend.h>
#include <TMath.h>
#include <TArrayF.h>
#include <TLine.h>
#include <TString.h>

#include <iostream>
#include <vector>
#include <string>

#include "/afs/naf.desy.de/user/k/kriheine/scratch/Kalibri/scripts/tdrstyle_mod.C"

using namespace std;

void PlotResolutions()
{
   setTDRStyle();
   tdrStyle->SetNdivisions(505, "X");

   double eta_bins[6] = {0., 0.5, 1.1, 1.7, 2.3, 5.0};
   
   TH1F *Res_2011Final = new TH1F("Data_MC_ratio_2011","", 5, eta_bins);
   TH1F *Res_2012AB = new TH1F("Data_MC_ratio_2012AB", "", 5, eta_bins);
   TH1F *Res_2012ABC = new TH1F("Data_MC_ratio_2012ABC", "", 5, eta_bins); // prompt reco datasets
   TH1F *Res_2012ABCD = new TH1F("Data_MC_ratio_2012ABCD", "", 5, eta_bins); // prompt reco datasets

   TH1F *Res_2012ABC_lowPU = new TH1F("Data_MC_ratio_2012ABC_lowPU", "", 5, eta_bins);
   TH1F *Res_2012ABC_highPU = new TH1F("Data_MC_ratio_2012ABC_highPU", "", 5, eta_bins);

   TH1F *Res_2012ABC_rereco_2012SQLV7 = new TH1F("Data_MC_ratio_2012ABC_rereco_2012SQLV7", "", 5, eta_bins); // A-C1 rereco, C2 prompt reco (HCP)
   TH1F *Res_2012ABC_rereco_2012FallV4 = new TH1F("Data_MC_ratio_2012ABC_rereco_2012FallV4", "", 5, eta_bins);
   TH1F *Res_2012ABC_rereco_2012SQLV7_chs = new TH1F("Data_MC_ratio_2012ABC_rereco_2012SQLV7_chs", "", 5, eta_bins); 
   TH1F *Res_2012ABC_rereco_2012FallV4_chs = new TH1F("Data_MC_ratio_2012ABC_rereco_2012FallV4_chs", "", 5, eta_bins);
   TH1F *Res_2012ABC_rereco_2012FallV4_residual = new TH1F("Data_MC_ratio_2012ABC_rereco_2012FallV4_residual", "", 5, eta_bins);
   TH1F *Res_2012ABC_rereco_2012FallV4_chs_residual = new TH1F("Data_MC_ratio_2012ABC_rereco_2012FallV4_chs_residual", "", 5, eta_bins);


   Res_2011Final->SetBinContent(1, 1.052);
   Res_2011Final->SetBinContent(2, 1.057);
   Res_2011Final->SetBinContent(3, 1.096);
   Res_2011Final->SetBinContent(4, 1.134);
   Res_2011Final->SetBinContent(5, 1.288);

   TGraphAsymmErrors *Res_2011 = new TGraphAsymmErrors(Res_2011Final);
   Res_2011->SetPointError(0, 0., 0., 0.063, 0.062);
   Res_2011->SetPointError(1, 0., 0., 0.057, 0.056);
   Res_2011->SetPointError(2, 0., 0., 0.065, 0.064);
   Res_2011->SetPointError(3, 0., 0., 0.094, 0.092);
   Res_2011->SetPointError(4, 0., 0., 0.200, 0.199);

   Res_2012AB->SetBinContent(1, 1.102);
   Res_2012AB->SetBinContent(2, 1.070);
   Res_2012AB->SetBinContent(3, 1.098);
   Res_2012AB->SetBinContent(4, 1.141);
   Res_2012AB->SetBinContent(5, 1.154);
   Res_2012AB->SetBinError(1, 0.011);
   Res_2012AB->SetBinError(2, 0.012);
   Res_2012AB->SetBinError(3, 0.020);
   Res_2012AB->SetBinError(4, 0.042);
   Res_2012AB->SetBinError(5, 0.085);

   Res_2012ABC->SetBinContent(1, 1.097);
   Res_2012ABC->SetBinContent(2, 1.100);
   Res_2012ABC->SetBinContent(3, 1.164);
   Res_2012ABC->SetBinContent(4, 1.270);
   Res_2012ABC->SetBinContent(5, 1.190);
   Res_2012ABC->SetBinError(1, 0.007);
   Res_2012ABC->SetBinError(2, 0.008);
   Res_2012ABC->SetBinError(3, 0.013);
   Res_2012ABC->SetBinError(4, 0.028);
   Res_2012ABC->SetBinError(5, 0.063);

   Res_2012ABCD->SetBinContent(1, 1.086);
   Res_2012ABCD->SetBinContent(2, 1.101);
   Res_2012ABCD->SetBinContent(3, 1.160);
   Res_2012ABCD->SetBinContent(4, 1.228);
   Res_2012ABCD->SetBinContent(5, 1.186);
   Res_2012ABCD->SetBinError(1, 0.006);
   Res_2012ABCD->SetBinError(2, 0.006);
   Res_2012ABCD->SetBinError(3, 0.011);
   Res_2012ABCD->SetBinError(4, 0.025);
   Res_2012ABCD->SetBinError(5, 0.063);

   Res_2012ABC_lowPU->SetBinContent(1, 1.105);
   Res_2012ABC_lowPU->SetBinContent(2, 1.102);
   Res_2012ABC_lowPU->SetBinContent(3, 1.165);
   Res_2012ABC_lowPU->SetBinContent(4, 1.245);
   Res_2012ABC_lowPU->SetBinContent(5, 1.113);
   Res_2012ABC_lowPU->SetBinError(1, 0.009);
   Res_2012ABC_lowPU->SetBinError(2, 0.010);
   Res_2012ABC_lowPU->SetBinError(3, 0.016);
   Res_2012ABC_lowPU->SetBinError(4, 0.035);
   Res_2012ABC_lowPU->SetBinError(5, 0.073);

   Res_2012ABC_highPU->SetBinContent(1, 1.086);
   Res_2012ABC_highPU->SetBinContent(2, 1.075);
   Res_2012ABC_highPU->SetBinContent(3, 1.134);
   Res_2012ABC_highPU->SetBinContent(4, 1.224);
   Res_2012ABC_highPU->SetBinContent(5, 1.143);
   Res_2012ABC_highPU->SetBinError(1, 0.011);
   Res_2012ABC_highPU->SetBinError(2, 0.013);
   Res_2012ABC_highPU->SetBinError(3, 0.021);
   Res_2012ABC_highPU->SetBinError(4, 0.048);
   Res_2012ABC_highPU->SetBinError(5, 0.114);

   Res_2012ABC_rereco_2012SQLV7->SetBinContent(1, 1.087);
   Res_2012ABC_rereco_2012SQLV7->SetBinContent(2, 1.111);
   Res_2012ABC_rereco_2012SQLV7->SetBinContent(3, 1.170);
   Res_2012ABC_rereco_2012SQLV7->SetBinContent(4, 1.307);
   Res_2012ABC_rereco_2012SQLV7->SetBinContent(5, 1.152);
   Res_2012ABC_rereco_2012SQLV7->SetBinError(1, 0.007);
   Res_2012ABC_rereco_2012SQLV7->SetBinError(2, 0.007);
   Res_2012ABC_rereco_2012SQLV7->SetBinError(3, 0.013);
   Res_2012ABC_rereco_2012SQLV7->SetBinError(4, 0.028);
   Res_2012ABC_rereco_2012SQLV7->SetBinError(5, 0.070);

   Res_2012ABC_rereco_2012FallV4->SetBinContent(1, 1.093);
   Res_2012ABC_rereco_2012FallV4->SetBinContent(2, 1.104);
   Res_2012ABC_rereco_2012FallV4->SetBinContent(3, 1.154);
   Res_2012ABC_rereco_2012FallV4->SetBinContent(4, 1.285);
   Res_2012ABC_rereco_2012FallV4->SetBinContent(5, 1.094);
   Res_2012ABC_rereco_2012FallV4->SetBinError(1, 0.007);
   Res_2012ABC_rereco_2012FallV4->SetBinError(2, 0.007);
   Res_2012ABC_rereco_2012FallV4->SetBinError(3, 0.012);
   Res_2012ABC_rereco_2012FallV4->SetBinError(4, 0.028);
   Res_2012ABC_rereco_2012FallV4->SetBinError(5, 0.064);

   Res_2012ABC_rereco_2012SQLV7_chs->SetBinContent(1, 1.092);
   Res_2012ABC_rereco_2012SQLV7_chs->SetBinContent(2, 1.109);
   Res_2012ABC_rereco_2012SQLV7_chs->SetBinContent(3, 1.162);
   Res_2012ABC_rereco_2012SQLV7_chs->SetBinContent(4, 1.259);
   Res_2012ABC_rereco_2012SQLV7_chs->SetBinContent(5, 1.262);
   Res_2012ABC_rereco_2012SQLV7_chs->SetBinError(1, 0.007);
   Res_2012ABC_rereco_2012SQLV7_chs->SetBinError(2, 0.007);
   Res_2012ABC_rereco_2012SQLV7_chs->SetBinError(3, 0.012);
   Res_2012ABC_rereco_2012SQLV7_chs->SetBinError(4, 0.026);
   Res_2012ABC_rereco_2012SQLV7_chs->SetBinError(5, 0.069);

   Res_2012ABC_rereco_2012FallV4_chs->SetBinContent(1, 1.094);
   Res_2012ABC_rereco_2012FallV4_chs->SetBinContent(2, 1.109);
   Res_2012ABC_rereco_2012FallV4_chs->SetBinContent(3, 1.157);
   Res_2012ABC_rereco_2012FallV4_chs->SetBinContent(4, 1.300);
   Res_2012ABC_rereco_2012FallV4_chs->SetBinContent(5, 1.243);
   Res_2012ABC_rereco_2012FallV4_chs->SetBinError(1, 0.007);
   Res_2012ABC_rereco_2012FallV4_chs->SetBinError(2, 0.007);
   Res_2012ABC_rereco_2012FallV4_chs->SetBinError(3, 0.011);
   Res_2012ABC_rereco_2012FallV4_chs->SetBinError(4, 0.026);
   Res_2012ABC_rereco_2012FallV4_chs->SetBinError(5, 0.065);

   Res_2012ABC_rereco_2012FallV4_residual->SetBinContent(1, 1.094);
   Res_2012ABC_rereco_2012FallV4_residual->SetBinContent(2, 1.106);
   Res_2012ABC_rereco_2012FallV4_residual->SetBinContent(3, 1.155);
   Res_2012ABC_rereco_2012FallV4_residual->SetBinContent(4, 1.272);
   Res_2012ABC_rereco_2012FallV4_residual->SetBinContent(5, 1.080);
   Res_2012ABC_rereco_2012FallV4_residual->SetBinError(1, 0.007);
   Res_2012ABC_rereco_2012FallV4_residual->SetBinError(2, 0.007);
   Res_2012ABC_rereco_2012FallV4_residual->SetBinError(3, 0.012);
   Res_2012ABC_rereco_2012FallV4_residual->SetBinError(4, 0.027);
   Res_2012ABC_rereco_2012FallV4_residual->SetBinError(5, 0.059);

   Res_2012ABC_rereco_2012FallV4_chs_residual->SetBinContent(1, 1.090);
   Res_2012ABC_rereco_2012FallV4_chs_residual->SetBinContent(2, 1.112);
   Res_2012ABC_rereco_2012FallV4_chs_residual->SetBinContent(3, 1.156);
   Res_2012ABC_rereco_2012FallV4_chs_residual->SetBinContent(4, 1.288);
   Res_2012ABC_rereco_2012FallV4_chs_residual->SetBinContent(5, 1.229);
   Res_2012ABC_rereco_2012FallV4_chs_residual->SetBinError(1, 0.007);
   Res_2012ABC_rereco_2012FallV4_chs_residual->SetBinError(2, 0.007);
   Res_2012ABC_rereco_2012FallV4_chs_residual->SetBinError(3, 0.011);
   Res_2012ABC_rereco_2012FallV4_chs_residual->SetBinError(4, 0.026);
   Res_2012ABC_rereco_2012FallV4_chs_residual->SetBinError(5, 0.064);

   ///////////////////////////////////////////////////////////////
  
   TCanvas *c = new TCanvas();
   Res_2012AB->SetXTitle("|#eta|");
   Res_2012AB->GetXaxis()->SetRangeUser(0., 5.);
   Res_2012AB->SetYTitle("Data/MC ratio (const fit)");
   Res_2012AB->GetYaxis()->SetRangeUser(0.8, 1.5);
   Res_2012AB->SetMarkerStyle(21);
   Res_2012AB->SetMarkerSize(1.4);
   Res_2012AB->SetLineColor(kPink-3);
   Res_2012AB->SetMarkerColor(kPink-3);
   Res_2012AB->Draw("e1p");
   Res_2011->SetMarkerStyle(20);
   Res_2011->SetMarkerSize(1.4);
   Res_2011->SetFillColor(kGray);
   Res_2011->SetFillStyle(3001);
   Res_2011->SetLineColor(kGray);
   Res_2011->DrawClone("e3psame");
   Res_2012AB->Draw("e1psame");
   Res_2012ABC->SetMarkerStyle(23);
   Res_2012ABC->SetMarkerSize(1.4);
   //  Res_2012ABC->SetMarkerColor(kBlue-3);
   Res_2012ABC->SetLineColor(kBlue-4);
   Res_2012ABC->SetMarkerColor(kBlue-4);
   Res_2012ABC->Draw("e1psame");
   Res_2012ABCD->SetMarkerStyle(33);
   Res_2012ABCD->SetMarkerSize(1.8);
   Res_2012ABCD->SetLineColor(kGreen+1);
   Res_2012ABCD->SetMarkerColor(kGreen+1);
   Res_2012ABCD->Draw("e1psame");

   Res_2011->SetPointError(0, 0., 0., 0., 0.);
   Res_2011->SetPointError(1, 0., 0., 0., 0.);
   Res_2011->SetPointError(2, 0., 0., 0., 0.);
   Res_2011->SetPointError(3, 0., 0., 0., 0.);
   Res_2011->SetPointError(4, 0., 0., 0., 0.);

   Res_2011->Draw("psame");

   cmsPrel();

   TLegend *leg = new TLegend(0.54, 0.17, 0.74, 0.4);
   leg->SetBorderSize(0);
   // leg->SetBorderMode(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   leg->SetTextFont(42);
   leg->SetTextSize(0.035);

   leg->AddEntry(Res_2011,"2011 (total error)", "pfl");
   leg->AddEntry(Res_2012AB,"2012 AB (stat. error)", "P");
   leg->AddEntry(Res_2012ABC,"2012 ABC (stat. error)", "P");
   leg->AddEntry(Res_2012ABCD,"2012 ABCD (stat. error)", "P");

   leg->Draw("same");

   c->Print("CompareResolutions_total.eps");
   c->Print("CompareResolutions_total.png");

   ///////////////////////////////////////////////////////////////

   Res_2011->SetPointError(0, 0., 0., 0.063, 0.062);
   Res_2011->SetPointError(1, 0., 0., 0.057, 0.056);
   Res_2011->SetPointError(2, 0., 0., 0.065, 0.064);
   Res_2011->SetPointError(3, 0., 0., 0.094, 0.092);
   Res_2011->SetPointError(4, 0., 0., 0.200, 0.199);

   Res_2012ABC_lowPU->SetXTitle("|#eta|");
   Res_2012ABC_lowPU->GetXaxis()->SetRangeUser(0., 5.);
   Res_2012ABC_lowPU->SetYTitle("Data/MC ratio (const fit)");
   Res_2012ABC_lowPU->GetYaxis()->SetRangeUser(0.8, 1.5);
   Res_2012ABC_lowPU->SetMarkerStyle(21);
   Res_2012ABC_lowPU->SetMarkerSize(1.4);
   Res_2012ABC_lowPU->SetLineColor(kGreen+1);
   Res_2012ABC_lowPU->SetMarkerColor(kGreen+1);
   Res_2012ABC_lowPU->Draw("e1p");
   Res_2011->SetMarkerStyle(20);
   Res_2011->SetMarkerSize(1.4);
   Res_2011->SetFillColor(kGray);
   Res_2011->SetFillStyle(3001);
   Res_2011->SetLineColor(kGray);
   Res_2011->DrawClone("e3psame");
   Res_2012ABC_lowPU->Draw("e1psame");
   Res_2012ABC->SetMarkerStyle(23);
   Res_2012ABC->SetMarkerSize(1.4);
   //  Res_2012ABC->SetMarkerColor(kBlue-3);
   Res_2012ABC->SetLineColor(kBlue-4);
   Res_2012ABC->SetMarkerColor(kBlue-4);
   Res_2012ABC->Draw("e1psame");

   Res_2011->SetPointError(0, 0., 0., 0., 0.);
   Res_2011->SetPointError(1, 0., 0., 0., 0.);
   Res_2011->SetPointError(2, 0., 0., 0., 0.);
   Res_2011->SetPointError(3, 0., 0., 0., 0.);
   Res_2011->SetPointError(4, 0., 0., 0., 0.);

   Res_2011->Draw("psame");

   cmsPrel();

   TLegend *leg = new TLegend(0.54, 0.17, 0.74, 0.4);
   leg->SetBorderSize(0);
   // leg->SetBorderMode(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   leg->SetTextFont(42);
   leg->SetTextSize(0.035);

   leg->AddEntry(Res_2011,"2011 (total error)", "pfl");
   leg->AddEntry(Res_2012ABC_lowPU,"2012 ABC nPV <= 15", "P");
   leg->AddEntry(Res_2012ABC,"2012 ABC (stat. error)", "P");

   leg->Draw("same");

   c->Print("CompareResolutions_lowPU.eps");
   c->Print("CompareResolutions_lowPU.png");

   ///////////////////////////////////////////////////////////////

   Res_2011->SetPointError(0, 0., 0., 0.063, 0.062);
   Res_2011->SetPointError(1, 0., 0., 0.057, 0.056);
   Res_2011->SetPointError(2, 0., 0., 0.065, 0.064);
   Res_2011->SetPointError(3, 0., 0., 0.094, 0.092);
   Res_2011->SetPointError(4, 0., 0., 0.200, 0.199);

   Res_2012ABC_highPU->SetXTitle("|#eta|");
   Res_2012ABC_highPU->GetXaxis()->SetRangeUser(0., 5.);
   Res_2012ABC_highPU->SetYTitle("Data/MC ratio (const fit)");
   Res_2012ABC_highPU->GetYaxis()->SetRangeUser(0.8, 1.5);
   Res_2012ABC_highPU->SetMarkerStyle(21);
   Res_2012ABC_highPU->SetMarkerSize(1.4);
   Res_2012ABC_highPU->SetLineColor(kOrange);
   Res_2012ABC_highPU->SetMarkerColor(kOrange);
   Res_2012ABC_highPU->Draw("e1p");
   Res_2011->SetMarkerStyle(20);
   Res_2011->SetMarkerSize(1.4);
   Res_2011->SetFillColor(kGray);
   Res_2011->SetFillStyle(3001);
   Res_2011->SetLineColor(kGray);
   Res_2011->DrawClone("e3psame");
   Res_2012ABC_highPU->Draw("e1psame");
   Res_2012ABC->SetMarkerStyle(23);
   Res_2012ABC->SetMarkerSize(1.4);
   //  Res_2012ABC->SetMarkerColor(kBlue-3);
   Res_2012ABC->SetLineColor(kBlue-4);
   Res_2012ABC->SetMarkerColor(kBlue-4);
   Res_2012ABC->Draw("e1psame");

   Res_2011->SetPointError(0, 0., 0., 0., 0.);
   Res_2011->SetPointError(1, 0., 0., 0., 0.);
   Res_2011->SetPointError(2, 0., 0., 0., 0.);
   Res_2011->SetPointError(3, 0., 0., 0., 0.);
   Res_2011->SetPointError(4, 0., 0., 0., 0.);

   Res_2011->Draw("psame");

   cmsPrel();

   TLegend *leg = new TLegend(0.54, 0.17, 0.74, 0.4);
   leg->SetBorderSize(0);
   // leg->SetBorderMode(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   leg->SetTextFont(42);
   leg->SetTextSize(0.035);

   leg->AddEntry(Res_2011,"2011 (total error)", "pfl");
   leg->AddEntry(Res_2012ABC_highPU,"2012 ABC nPV >= 16", "P");
   leg->AddEntry(Res_2012ABC,"2012 ABC (stat. error)", "P");

   leg->Draw("same");

   c->Print("CompareResolutions_highPU.eps");
   c->Print("CompareResolutions_highPU.png");

   ///////////////////////////////////////////////////////////////

   Res_2011->SetPointError(0, 0., 0., 0.063, 0.062);
   Res_2011->SetPointError(1, 0., 0., 0.057, 0.056);
   Res_2011->SetPointError(2, 0., 0., 0.065, 0.064);
   Res_2011->SetPointError(3, 0., 0., 0.094, 0.092);
   Res_2011->SetPointError(4, 0., 0., 0.200, 0.199);

   Res_2012ABC_highPU->SetXTitle("|#eta|");
   Res_2012ABC_highPU->GetXaxis()->SetRangeUser(0., 5.);
   Res_2012ABC_highPU->SetYTitle("Data/MC ratio (const fit)");
   Res_2012ABC_highPU->GetYaxis()->SetRangeUser(0.8, 1.5);
   Res_2012ABC_highPU->SetMarkerStyle(21);
   Res_2012ABC_highPU->SetMarkerSize(1.4);
   Res_2012ABC_highPU->SetLineColor(kOrange);
   Res_2012ABC_highPU->SetMarkerColor(kOrange);
   Res_2012ABC_highPU->Draw("e1p");
   Res_2012AB->SetMarkerStyle(21);
   Res_2012AB->SetMarkerSize(1.4);
   Res_2012AB->SetLineColor(kPink-3);
   Res_2012AB->SetMarkerColor(kPink-3);
   Res_2012AB->Draw("e1p");
   Res_2012ABC_lowPU->SetMarkerStyle(21);
   Res_2012ABC_lowPU->SetMarkerSize(1.4);
   Res_2012ABC_lowPU->SetLineColor(kGreen+1);
   Res_2012ABC_lowPU->SetMarkerColor(kGreen+1);
   Res_2012ABC_lowPU->Draw("e1p");
   Res_2011->SetMarkerStyle(20);
   Res_2011->SetMarkerSize(1.4);
   Res_2011->SetFillColor(kGray);
   Res_2011->SetFillStyle(3001);
   Res_2011->SetLineColor(kGray);
   Res_2011->DrawClone("e3psame");
   Res_2012AB->Draw("e1psame");
   Res_2012ABC_lowPU->Draw("e1psame");
   Res_2012ABC_highPU->Draw("e1psame");
   Res_2012ABC->SetMarkerStyle(23);
   Res_2012ABC->SetMarkerSize(1.4);
   //  Res_2012ABC->SetMarkerColor(kBlue-3);
   Res_2012ABC->SetLineColor(kBlue-4);
   Res_2012ABC->SetMarkerColor(kBlue-4);
   Res_2012ABC->Draw("e1psame");

   Res_2011->SetPointError(0, 0., 0., 0., 0.);
   Res_2011->SetPointError(1, 0., 0., 0., 0.);
   Res_2011->SetPointError(2, 0., 0., 0., 0.);
   Res_2011->SetPointError(3, 0., 0., 0., 0.);
   Res_2011->SetPointError(4, 0., 0., 0., 0.);

   Res_2011->Draw("psame");

   cmsPrel();

   TLegend *leg = new TLegend(0.54, 0.17, 0.74, 0.4);
   leg->SetBorderSize(0);
   // leg->SetBorderMode(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   leg->SetTextFont(42);
   leg->SetTextSize(0.035);

   leg->AddEntry(Res_2011,"2011 (total error)", "pfl");
   leg->AddEntry(Res_2012AB,"2012 AB (stat. error)", "P");
   leg->AddEntry(Res_2012ABC_lowPU,"2012 ABC nPV <= 15", "P");
   leg->AddEntry(Res_2012ABC_highPU,"2012 ABC nPV >= 16", "P");
   leg->AddEntry(Res_2012ABC,"2012 ABC (stat. error)", "P");

   leg->Draw("same");

   c->Print("CompareResolutions_all.eps");
   c->Print("CompareResolutions_all.png");

   ///////////////////////////////////////////////////////////////

   Res_2011->SetPointError(0, 0., 0., 0.063, 0.062);
   Res_2011->SetPointError(1, 0., 0., 0.057, 0.056);
   Res_2011->SetPointError(2, 0., 0., 0.065, 0.064);
   Res_2011->SetPointError(3, 0., 0., 0.094, 0.092);
   Res_2011->SetPointError(4, 0., 0., 0.200, 0.199);

   Res_2012ABC_rereco_2012SQLV7->SetXTitle("|#eta|");
   Res_2012ABC_rereco_2012SQLV7->GetXaxis()->SetRangeUser(0., 5.);
   Res_2012ABC_rereco_2012SQLV7->SetYTitle("Data/MC ratio (const fit)");
   Res_2012ABC_rereco_2012SQLV7->GetYaxis()->SetRangeUser(0.8, 1.5);
   Res_2012ABC_rereco_2012SQLV7->SetMarkerStyle(23);
   Res_2012ABC_rereco_2012SQLV7->SetMarkerSize(1.4);
   Res_2012ABC_rereco_2012SQLV7->SetLineColor(kBlue-4);
   Res_2012ABC_rereco_2012SQLV7->SetMarkerColor(kBlue-4);
   Res_2012ABC_rereco_2012SQLV7->Draw("e1p");
   Res_2011->SetMarkerStyle(20);
   Res_2011->SetMarkerSize(1.4);
   Res_2011->SetFillColor(kGray);
   Res_2011->SetFillStyle(3001);
   Res_2011->SetLineColor(kGray);
   Res_2011->DrawClone("e3psame");
   Res_2012ABC_rereco_2012SQLV7->Draw("e1psame");
   Res_2012ABC_rereco_2012FallV4->SetMarkerStyle(21);
   Res_2012ABC_rereco_2012FallV4->SetMarkerSize(1.4);
   Res_2012ABC_rereco_2012FallV4->SetLineColor(kPink-3);
   Res_2012ABC_rereco_2012FallV4->SetMarkerColor(kPink-3);
   Res_2012ABC_rereco_2012FallV4->Draw("e1psame");
 
   Res_2011->SetPointError(0, 0., 0., 0., 0.);
   Res_2011->SetPointError(1, 0., 0., 0., 0.);
   Res_2011->SetPointError(2, 0., 0., 0., 0.);
   Res_2011->SetPointError(3, 0., 0., 0., 0.);
   Res_2011->SetPointError(4, 0., 0., 0., 0.);

   Res_2011->Draw("psame");

   cmsPrel();

   TLegend *leg = new TLegend(0.54, 0.17, 0.74, 0.4);
   leg->SetBorderSize(0);
   // leg->SetBorderMode(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   leg->SetTextFont(42);
   leg->SetTextSize(0.035);

   leg->AddEntry(Res_2011,"2011 (stat. + sys. error)", "pfl");
   leg->AddEntry(Res_2012ABC_rereco_2012SQLV7,"2012 ABC, JEC: SQLV7 ", "P");
   leg->AddEntry(Res_2012ABC_rereco_2012FallV4,"2012 ABC, JEC: FallV4 ", "P");

   leg->Draw("same");

   c->Print("CompareResolutions_ABC_2JEC.eps");
   c->Print("CompareResolutions_ABC_2JEC.png");

   ///////////////////////////////////////////////////////////////

   Res_2011->SetPointError(0, 0., 0., 0.063, 0.062);
   Res_2011->SetPointError(1, 0., 0., 0.057, 0.056);
   Res_2011->SetPointError(2, 0., 0., 0.065, 0.064);
   Res_2011->SetPointError(3, 0., 0., 0.094, 0.092);
   Res_2011->SetPointError(4, 0., 0., 0.200, 0.199);

   Res_2012ABC_rereco_2012SQLV7_chs->SetXTitle("|#eta|");
   Res_2012ABC_rereco_2012SQLV7_chs->GetXaxis()->SetRangeUser(0., 5.);
   Res_2012ABC_rereco_2012SQLV7_chs->SetYTitle("Data/MC ratio (const fit)");
   Res_2012ABC_rereco_2012SQLV7_chs->GetYaxis()->SetRangeUser(0.8, 1.5);
   Res_2012ABC_rereco_2012SQLV7_chs->SetMarkerStyle(23);
   Res_2012ABC_rereco_2012SQLV7_chs->SetMarkerSize(1.4);
   Res_2012ABC_rereco_2012SQLV7_chs->SetLineColor(kBlue-4);
   Res_2012ABC_rereco_2012SQLV7_chs->SetMarkerColor(kBlue-4);
   Res_2012ABC_rereco_2012SQLV7_chs->Draw("e1p");
   Res_2011->SetMarkerStyle(20);
   Res_2011->SetMarkerSize(1.4);
   Res_2011->SetFillColor(kGray);
   Res_2011->SetFillStyle(3001);
   Res_2011->SetLineColor(kGray);
   Res_2011->DrawClone("e3psame");
   Res_2012ABC_rereco_2012SQLV7_chs->Draw("e1psame");
   Res_2012ABC_rereco_2012FallV4_chs->SetMarkerStyle(21);
   Res_2012ABC_rereco_2012FallV4_chs->SetMarkerSize(1.4);
   Res_2012ABC_rereco_2012FallV4_chs->SetLineColor(kPink-3);
   Res_2012ABC_rereco_2012FallV4_chs->SetMarkerColor(kPink-3);
   Res_2012ABC_rereco_2012FallV4_chs->Draw("e1psame");
 
   Res_2011->SetPointError(0, 0., 0., 0., 0.);
   Res_2011->SetPointError(1, 0., 0., 0., 0.);
   Res_2011->SetPointError(2, 0., 0., 0., 0.);
   Res_2011->SetPointError(3, 0., 0., 0., 0.);
   Res_2011->SetPointError(4, 0., 0., 0., 0.);

   Res_2011->Draw("psame");

   cmsPrel();

   TLegend *leg = new TLegend(0.39, 0.17, 0.59, 0.4);
   leg->SetBorderSize(0);
   // leg->SetBorderMode(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   leg->SetTextFont(42);
   leg->SetTextSize(0.035);

   leg->AddEntry(Res_2011,"2011 (stat. + sys. error)", "pfl");
   leg->AddEntry(Res_2012ABC_rereco_2012SQLV7_chs,"2012 ABC, JEC: SQLV7, CHS Jets ", "P");
   leg->AddEntry(Res_2012ABC_rereco_2012FallV4_chs,"2012 ABC, JEC: FallV4, CHS Jets ", "P");

   leg->Draw("same");

   c->Print("CompareResolutions_ABC_2JEC_chs.eps");
   c->Print("CompareResolutions_ABC_2JEC_chs.png");


   ///////////////////////////////////////////////////////////////

   Res_2011->SetPointError(0, 0., 0., 0.063, 0.062);
   Res_2011->SetPointError(1, 0., 0., 0.057, 0.056);
   Res_2011->SetPointError(2, 0., 0., 0.065, 0.064);
   Res_2011->SetPointError(3, 0., 0., 0.094, 0.092);
   Res_2011->SetPointError(4, 0., 0., 0.200, 0.199);

   Res_2012ABC_rereco_2012FallV4->SetXTitle("|#eta|");
   Res_2012ABC_rereco_2012FallV4->GetXaxis()->SetRangeUser(0., 5.);
   Res_2012ABC_rereco_2012FallV4->SetYTitle("Data/MC ratio (const fit)");
   Res_2012ABC_rereco_2012FallV4->GetYaxis()->SetRangeUser(0.8, 1.5);
   Res_2012ABC_rereco_2012FallV4->SetMarkerStyle(21);
   Res_2012ABC_rereco_2012FallV4->SetMarkerSize(1.4);
   Res_2012ABC_rereco_2012FallV4->SetLineColor(kPink-3);
   Res_2012ABC_rereco_2012FallV4->SetMarkerColor(kPink-3);
   Res_2012ABC_rereco_2012FallV4->Draw("e1p");
   Res_2011->SetMarkerStyle(20);
   Res_2011->SetMarkerSize(1.4);
   Res_2011->SetFillColor(kGray);
   Res_2011->SetFillStyle(3001);
   Res_2011->SetLineColor(kGray);
   Res_2011->DrawClone("e3psame");
   Res_2012ABC_rereco_2012FallV4->Draw("e1psame");
   Res_2012ABC_rereco_2012FallV4_chs->SetMarkerStyle(23);
   Res_2012ABC_rereco_2012FallV4_chs->SetMarkerSize(1.4);
   Res_2012ABC_rereco_2012FallV4_chs->SetLineColor(kBlue-4);
   Res_2012ABC_rereco_2012FallV4_chs->SetMarkerColor(kBlue-4);
   Res_2012ABC_rereco_2012FallV4_chs->Draw("e1psame");
 
   Res_2011->SetPointError(0, 0., 0., 0., 0.);
   Res_2011->SetPointError(1, 0., 0., 0., 0.);
   Res_2011->SetPointError(2, 0., 0., 0., 0.);
   Res_2011->SetPointError(3, 0., 0., 0., 0.);
   Res_2011->SetPointError(4, 0., 0., 0., 0.);

   Res_2011->Draw("psame");

   cmsPrel();

   TLegend *leg = new TLegend(0.5, 0.17, 0.7, 0.4);
   leg->SetBorderSize(0);
   // leg->SetBorderMode(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   leg->SetTextFont(42);
   leg->SetTextSize(0.035);

   leg->AddEntry(Res_2011,"2011 (stat. + sys. error)", "pfl");
   leg->AddEntry(Res_2012ABC_rereco_2012FallV4,"2012 ABC, AK5 PF Jets ", "P");
   leg->AddEntry(Res_2012ABC_rereco_2012FallV4_chs,"2012 ABC, AK5 PFchs Jets ", "P");

   leg->Draw("same");

   c->Print("CompareResolutions_ABC_ak5_ak5chs.eps");
   c->Print("CompareResolutions_ABC_ak5_ak5chs.png");
}

