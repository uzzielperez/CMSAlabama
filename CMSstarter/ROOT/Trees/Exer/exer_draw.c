//Uzziel Perez
{
  gROOT->Reset();

  //cosmetics 
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);

  //read file 
  TFile f("more_complex_tree.root");
  f.ls();
  
  TTree *tree = (TTree * ) f.Get("PhotonTree");
  tree->Print();

  cout << "Tree has N entries = " << tree->GetEntries() <<endl; 
  
  //Tree Scan
  cout << "Showing all data for all entries where px>12:" << endl;
  cout << endl;

  tree->Scan("px:py:pz", "px>12");
  cout << endl;
  cout << endl;
  cout << endl;

 //Simple plots
  TCanvas *c1 = new TCanvas(); 
  tree->Draw("px");

  //Oddly, this does not work
  //TCanvas *c2 = new TCanvas();
  //tree->Draw("Photon_px");
  
  //Making Cuts
  //Draw("variable", "cut")
  TCanvas *c2 = new TCanvas();
  tree->Draw("TMath::Sqrt(px*px+py*py+pz*pz)","px<109");

  //Multiplots: 
  TCanvas *c3 = new TCanvas("c3", "c3", 800,600);
  c3->Divide(2,2);

  c3->cd(1);
  tree->Draw("px:py", "px<109", "lego");

  c3->cd(2);
  tree->Draw("px:py","px<109", "colz");

  c3->cd(3);
  tree->Draw("py:pz","pz<109", "surf");

  c3->cd(4);
  tree->Draw("px:py:pz", "px<109");



}
