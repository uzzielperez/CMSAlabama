/// \file
/// \ingroup tutorial_tree
///  Read data from an ascii file and create a root file with an histogram and an ntuple.
///  See a variant of this macro in basic2.C.
///
/// \macro_code
///
/// \author Rene Brun

#include "Riostream.h"
void basic() {
// read file $ROOTSYS/tutorials/tree/basic.dat
// this file has 3 columns of float data
   TString dir = gSystem->UnixPathName(__FILE__);
   dir.ReplaceAll("basic.C","");
   dir.ReplaceAll("/./","/");
   ifstream in;
   in.open(Form("%sbasic.dat",dir.Data()));

   Float_t x,y,z;
   Int_t nlines = 0;
   auto f = TFile::Open("basic.root","RECREATE");
   TH1F h1("h1","x distribution",100,-4,4);
   TNtuple ntuple("ntuple","data from ascii file","x:y:z");

   while (1) {
      in >> x >> y >> z;
      if (!in.good()) break;
      if (nlines < 5) printf("x=%8f, y=%8f, z=%8f\n",x,y,z);
      h1.Fill(x);
      ntuple.Fill(x,y,z);
      nlines++;
   }
   printf(" found %d points\n",nlines);

   in.close();

   f->Write();

   //From CMingKuo
   
   TCanvas *c = new TCanvas("c", "c", 900, 600);
   c->Divide(2,2);
   c->cd(1);
   h1->GetXaxis()->SetTitle("P{x} (GeV)");
   h1->GetYaxis()->SetTitle("Entries");
   h1->SetLineWidth(1);
   h1->SetLineColor(2);
   h1->Draw();
   c->cd(2);

   h2->GetXaxis()->SetTitle("P{y} (GeV)");
   h2->GetYaxis()->SetTitle("Entries");
   h2->SetLineWidth(2);
   h2->SetLineColor(4);
   h1->Draw();
   c->cd(3);

   h3->GetXaxis()->SetTitle("P{z} (GeV)");
   h3->GetYaxis()->SetTitle("Entries");
   h3->SetLineWidth(2);
   h3->SetLineColor(6);
   h3->SetLineStyle(3);
   h3->Draw();
   c->cd(4);
   h2->Draw();
   h1->Draw("same");

   c->Print("myplots.pdf");

}
