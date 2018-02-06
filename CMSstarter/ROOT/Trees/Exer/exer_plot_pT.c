//Uzziel Perez
#include "TH1.h"

{
  gROOT->Reset();

  //cosmetics 
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);

  //read file 
  //TFile *f = TFile::Open("exer_vertex_2photons.root");
  TFile f("exer_vertex_2photons.root");
  f.ls();
  //f->ls();

  //TTree *tree = (TTree * ) f->Get("PhotonTree");
  TTree *tree = (TTree *) f.Get("PhotonTree");
  tree->Print();


  //TH1D *h1 = (TH1D*) f->Get("Photon1_px");

  //Simple plots
  TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
  c1->Divide(1,2); //1 row, 2 columns
  c1->cd(1); 
  tree->Draw("Photon1.px");
  c1->cd(2);
  tree->Draw("Photon2.px"); 

  TCanvas *c2 = new TCanvas("c2", "c2", 800, 600);
  c2->Divide(1,2); 
  c2->cd(1);
  tree->Draw("Photon1.py"); 
  c2->cd(2);
  tree->Draw("Photon2.py");

  TCanvas *c3 = new TCanvas("c3", "c3", 800, 600);
  c3->Divide(1,2);
  c3->cd(1);
  tree->Draw("Photon1.pz");
  c3->cd(2);
  tree->Draw("Photon2.pz");

  //We Want to plot the transverse momentum of the 2nd photon
  //for events where photon 1 pT is greater than 10GeV
  TCanvas *c4 = new TCanvas("c4", "c4", 800, 600);
  c4->Divide(1,2);
  c4->cd(1);
  tree->Draw("TMath::Sqrt(Photon1.px*Photon1.px+Photon1.py*Photon1.py+Photon1.pz*Photon1.pz)");
  c4->cd(2);
  tree->Draw("TMath::Sqrt(Photon2.px*Photon2.px+Photon2.py*Photon2.py+Photon2.pz*Photon2.pz)");

  TCanvas *c5 = new TCanvas();
  //pT1 = "TMath::Sqrt(Photon1.px*Photon1.px+Photon1.py*Photon1.py+Photon1.pz*Photon1.pz)"
  //pT2 = "TMath::Sqrt(Photon2.px*Photon2.px+Photon2.py*Photon2.py+Photon2.pz*Photon2.pz)"
  tree->Draw("TMath::Sqrt(Photon2.px*Photon2.px+Photon2.py*Photon2.py+Photon2.pz*Photon2.pz)"
               , "TMath::Sqrt(Photon1.px*Photon1.px+Photon1.py*Photon1.py+Photon1.pz*Photon1.pz)>10"); //Plot of Photon 2 pT for Photon1 greater than 10 GeV 



}
