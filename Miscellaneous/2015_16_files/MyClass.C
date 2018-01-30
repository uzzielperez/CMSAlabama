#define MyClass_cxx
#include "MyClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

void MyClass::Loop()
{
//   In a ROOT session, you can do:
//      root> .L MyClass.C
//      root> MyClass t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   
   //===== Histograms 
   TH1F *h1 = new TH1F("h1", "AllcosThetaStar", 100, -1, 1);  
   TH1F *h2 = new TH1F("h2", "HighPTcosThetaStar", 100, -1, 1);
   TH1F *gg = new TH1F("gg", "gg cosThetaStar",100, -1,1);
   TH1F *qq = new TH1F("qq", "qqbar cosThetaStar",100, -1,1); 
   //===== Counters
   int N_total = 0;
   int N_diphoton = 0;
   int total_selected = 0;
   int N_photon1 = 0;
   int N_photon2 = 0;
   int N_gluglu = 0;
   int N_qqbar = 0;

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
  //==== Loop over the events
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
     N_total++;
      
     h2->Fill(Diphoton_cosThetaStar);
      
     if ((Photon1_passHighPtID>=1)&& (Photon2_passHighPtID>=1)) continue;  
   // if ((Photon1_passHighPtID==true)&& (Photon2_passHighPtID==true)) continue; 
     h1->Fill(Diphoton_cosThetaStar);
     N_diphoton++;
     
    if (Event_interactingParton1PdgId){
      gg->Fill(Diphoton_cosThetaStar);
      N_gluglu++;
    }
    else if (Event_interactingParton2PdgId){
      qq->Fill(Diphoton_cosThetaStar);
      N_qqbar++;
    } 
     

   }//end of event loop 
   

   cout << "number of events" << " " << N_total << endl;
   cout << "number of diphotons" << " " << N_diphoton << endl;
   cout << "number of gluglu initiated events" << " " << N_gluglu << endl;
   cout << "number of qqbar initiated events" << " " << N_qqbar << endl;

   TFile *f = new TFile("RSGSpinAnalysis.root","RECREATE");
   h1->Write();
   h2->Write();
   gg->Write();
   qq->Write();

   TCanvas *cosThetaStar1 = new TCanvas("cosThetaStardistribution", "", 800, 600);
   h1->Draw();

   TCanvas *cosThetaStar2 = new TCanvas("cosThetaStardist", "", 800, 600);
   h2->Draw();

   TCanvas *ggcosThetaStar = new TCanvas("ggcosThetStar", "", 800, 600);
   gg->Draw();

   TCanvas *qqbarcosThetaStar = new TCanvas("qqbarcosThetaStar", "", 800, 600);
   qq->Draw();
   
   f->cd();
   f->Close();
}//end of method
