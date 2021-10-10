#include <TF1.h>
#include <iostream>
#include <math.h>
#include <string>
#include <TGraphAsymmErrors.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <valarray>
#include <TMultiGraph.h>

using namespace std;

void DrawPlots(){
  gStyle -> SetOptStat(0);
  //gStyle -> SetOptTitle(0);
  Double_t factor = 1.; 

  //plot var and corresponding number of tags
  TString var = "pTH";
  std::vector<std::string> tags{"TwoTags", "ThreeTags", "FourPlusTags"};

    //declare canvas instance
  TCanvas *can1 = new TCanvas("Canvas1", "Histograms", 600, 600);
  
  //select histo inputfile
  TFile* hisfilea = new TFile("/data/atlas/projects/adilData/PlotFiles/sig_Hplus_Wh_m800-0_77p_MC16a_0.-210.-0.-200.-100000.-100000.-200000.-125000.-1.0-1.0-2.5-200000._0.root", "OPEN");

  //sig_Hplus_Wh_m800-0_77p_MC16a_0.-210.-0.-200.-100000.-310000.-200000.-125000.-1.0-1.0-2.5-200000._0.root

  TFile* hisfiled = new TFile("/data/atlas/projects/adilData/PlotFiles/sig_Hplus_Wh_m800-0_77p_MC16d_0.-210.-0.-200.-100000.-100000.-200000.-125000.-1.0-1.0-2.5-200000._0.root", "OPEN");
  TFile* hisfilee = new TFile("/data/atlas/projects/adilData/PlotFiles/sig_Hplus_Wh_m800-0_77p_MC16e_0.-210.-0.-200.-100000.-100000.-200000.-125000.-1.0-1.0-2.5-200000._0.root", "OPEN");

  TFile* hisfilea2 = new TFile("/data/atlas/projects/adilData/PlotFiles/sig_Hplus_Wh_m1600-0_77p_MC16a_0.-210.-0.-200.-100000.-100000.-200000.-125000.-1.0-1.0-2.5-200000._0.root", "OPEN");
  TFile* hisfiled2 = new TFile("/data/atlas/projects/adilData/PlotFiles/sig_Hplus_Wh_m1600-0_77p_MC16d_0.-210.-0.-200.-100000.-100000.-200000.-125000.-1.0-1.0-2.5-200000._0.root", "OPEN");
  TFile* hisfilee2 = new TFile("/data/atlas/projects/adilData/PlotFiles/sig_Hplus_Wh_m1600-0_77p_MC16e_0.-210.-0.-200.-100000.-100000.-200000.-125000.-1.0-1.0-2.5-200000._0.root", "OPEN");

  TFile* hisfilea3 = new TFile("/data/atlas/projects/adilData/PlotFiles/ttbar_77p_MC16a_0.-210.-0.-200.-100000.-100000.-200000.-125000.-1.0-1.0-2.5-200000._0.root", "OPEN");
  TFile* hisfiled3 = new TFile("/data/atlas/projects/adilData/PlotFiles/ttbar_77p_MC16d_0.-210.-0.-200.-100000.-100000.-200000.-125000.-1.0-1.0-2.5-200000._0.root", "OPEN");
  TFile* hisfilee3 = new TFile("/data/atlas/projects/adilData/PlotFiles/ttbar_77p_MC16e_0.-210.-0.-200.-100000.-100000.-200000.-125000.-1.0-1.0-2.5-200000._0.root", "OPEN");
  //800,1600 for signal and ttbar, for data sets a,d and e so 9 files in total

  //======================
  // Get histograms
  //======================

  TFile *o1a = (TFile *)hisfilea->Get("Nominal");
  o1a = (TFile *)o1a->Get(var);
  TFile *o1d = (TFile *)hisfiled->Get("Nominal");
  o1d = (TFile *)o1d->Get(var);
  TFile *o1e = (TFile *)hisfilee->Get("Nominal");
  o1e = (TFile *)o1e->Get(var);

  TFile *o2a = (TFile *)hisfilea2->Get("Nominal");
  o2a = (TFile *)o2a->Get(var);
  TFile *o2d = (TFile *)hisfiled2->Get("Nominal");
  o2d = (TFile *)o2d->Get(var);
  TFile *o2e = (TFile *)hisfilee2->Get("Nominal");
  o2e = (TFile *)o2e->Get(var);
  
  TFile *o3a = (TFile *)hisfilea3->Get("Nominal");
  o3a = (TFile *)o3a->Get(var);
  TFile *o3d = (TFile *)hisfiled3->Get("Nominal");
  o3d = (TFile *)o3d->Get(var);
  TFile *o3e = (TFile *)hisfilee3->Get("Nominal");
  o3e = (TFile *)o3e->Get(var);

  //s - signal, MET - missing energy, 8 - 800 MeV, CR - Control Region 
  // TH1F *as2_8_CR = (TH1F*) o1a->Get("sig_Hplus_Wh_m800-0_"+ var + "_Merged_LepN_CR_TwoTags_Nominal");
  // TH1F* as2_16_CR = (TH1F*) o2a->Get("sig_Hplus_Wh_m1600-0_Lepton_Eta_Merged_LepP_CR_TwoTags_Nominal");
  // TH1F* bg_2_CR = (TH1F*) o3a->Get("ttbar_Lepton_Eta_Merged_LepP_CR_TwoTags_Nominal");
 

  //MET, Plepton, signal region
  TH1F* as2_8_SR = (TH1F*) o1a->Get("sig_Hplus_Wh_m800-0_"+ var + "_Merged_LepN_SR_"+ tags[1] +"_Nominal");
  TH1F* ds2_8_SR = (TH1F*) o1d->Get("sig_Hplus_Wh_m800-0_"+ var + "_Merged_LepN_SR_"+ tags[1] +"_Nominal");
  TH1F* es2_8_SR = (TH1F*) o1e->Get("sig_Hplus_Wh_m800-0_"+ var + "_Merged_LepN_SR_"+ tags[1] +"_Nominal");
  as2_8_SR->Add(ds2_8_SR);
  as2_8_SR->Add(es2_8_SR);
  //normalise histos
  as2_8_SR->Scale(factor/(as2_8_SR->Integral()));

  TH1F* as2_16_SR = (TH1F*) o2a->Get("sig_Hplus_Wh_m1600-0_"+ var + "_Merged_LepN_SR_"+ tags[1] +"_Nominal");
  TH1F* ds2_16_SR = (TH1F*) o2d->Get("sig_Hplus_Wh_m1600-0_"+ var + "_Merged_LepN_SR_"+ tags[1] +"_Nominal");
  TH1F* es2_16_SR = (TH1F*) o2e->Get("sig_Hplus_Wh_m1600-0_"+ var + "_Merged_LepN_SR_"+ tags[1] +"_Nominal");
  as2_16_SR->Add(ds2_16_SR);
  as2_16_SR->Add(es2_16_SR);
  as2_16_SR->Scale(factor/as2_16_SR->Integral());

  //two tags
  TH1F* abg_2_SR = (TH1F*) o3a->Get("ttbar_"+ var + "_Merged_LepN_SR_"+ tags[1] +"_Nominal");
  TH1F* dbg_2_SR = (TH1F*) o3d->Get("ttbar_"+ var + "_Merged_LepN_SR_"+ tags[1] +"_Nominal");
  TH1F* ebg_2_SR = (TH1F*) o3e->Get("ttbar_"+ var + "_Merged_LepN_SR_"+ tags[1] +"_Nominal");
  abg_2_SR->Add(dbg_2_SR);
  abg_2_SR->Add(ebg_2_SR);
  abg_2_SR->Scale(factor/abg_2_SR->Integral());

 //set line style
 /* as2_8_CR->SetLineColor(1);
  as2_16_CR->SetLineColor(2);
  bg_2_CR->SetLineColor(3);*/

  as2_8_SR->SetLineColor(1);
  as2_16_SR->SetLineColor(2);
  abg_2_SR->SetLineColor(3);

  //Draw histos

  //Signal region draw
  can1->SetLeftMargin(0.16);
  can1->SetBottomMargin(0.16);
  can1->cd();

  can1->SetLogy(0);

  as2_8_SR->GetXaxis()->SetTitle(var + "(GeV)");
  as2_8_SR->GetYaxis()->SetTitle("Events");
  as2_8_SR->Draw("hist same");     
  abg_2_SR->Draw("hist same");    
  as2_16_SR->Draw("hist same"); 
  
  auto legendmets = new TLegend(0.80, 0.90, 0.98, 1.0);
  legendmets->SetHeader(tags[1].data(),"R"); // option "C" allows to center the header
  legendmets->AddEntry(as2_8_SR, "800 GeV (had)","l");
  legendmets->AddEntry(as2_16_SR,"1600 GeV (had)","l");
  legendmets->AddEntry(abg_2_SR,"ttbar bg","l");
  
  legendmets->SetTextSize(0.02);
  legendmets->Draw();
    
  TString printVar = var + "_" + tags[1];
  TString printVarl = printVar + "_log";

  TString plot =  printVar + "_had" + string(".png");
  can1->Print(plot,"png");

}
