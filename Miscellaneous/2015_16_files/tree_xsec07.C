void tree_xsec07() {
  // LO / QED
  // Make sure uncertainty in histogram bins is calculated correctly
  // TH1::SetDefaultSumw2(kTRUE);
  string ploTitle = "Plot of m_{ZH}";
  const Int_t nBin = 100;

  TGraphErrors* g1 = new TGraphErrors();
  g1->SetName("g1");
  g1->SetMarkerColor(kRed + 1);
  g1->SetMarkerStyle(1);
  g1->SetMarkerSize(1);
  g1->SetLineColor(kRed);
  g1->SetLineWidth(2);

  std::ifstream in1("mZH05.txt"); 

  Int_t count = 0;
  do {
    std::string l1;
    std::getline(in1, l1);
    if (in1.bad()) break;

    if (l1[0] == '#') continue;

    std::stringstream parse(l1);

    Double_t x05, y05, e05;
    parse >> x05 >> y05 >> e05;
    g1->SetPoint(count, x05, y05);
    g1->SetPointError(count, 0., e05);

    count++;
    } while (!in1.eof());
  // g1->Draw("ap");
  
  // This is the frame histogram
  TH1F *frame_hist = new TH1F("", ploTitle.c_str(), nBin, 0., 1000.);
  //frame_hist->SetEntries(0);
  frame_hist->SetLineWidth(0);
  frame_hist->GetYaxis()->SetTitle("Cross section (fb)");
  frame_hist->GetYaxis()->SetTitleSize(23);
  frame_hist->GetYaxis()->SetTitleFont(43);
  frame_hist->GetYaxis()->SetTitleOffset(1.1);
  frame_hist->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  frame_hist->GetYaxis()->SetLabelSize(21);
  frame_hist->SetAxisRange(0.001, 0.14, "y");
  
// Declare first histogram
  TH1D *h1 = new TH1D("", ploTitle.c_str(),nBin,0.,1000.);
  h1->SetMarkerColor(kRed + 1);
  h1->SetLineColor(kRed);
  h1->SetFillColor(kRed);
  h1->SetLineWidth(2);
  h1->GetYaxis()->SetTitle("Cross Section (fb)");
  h1->GetYaxis()->SetTitleSize(23);
  h1->GetYaxis()->SetTitleFont(43);
  h1->GetYaxis()->SetTitleOffset(1.1);
  h1->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h1->GetYaxis()->SetLabelSize(21);
  h1->SetAxisRange(0.001, 0.14, "y");

  Double_t x105, y105, e105;
  Float_t xbin[nBin + 1];
  Float_t valuey[nBin + 1];
  for (Int_t i = 0; i < nBin; i++) { 

   valuey[i] = 1.;
   xbin[i] = 0. + ( (Float_t) i / (Float_t) nBin * 1000.);
   g1->GetPoint(i, x105, y105);
   e105 = g1->GetErrorY(i);
   h1->SetBinContent(i+1, y105);
   h1->SetBinError(i+1, e105);
 }
   xbin[nBin] = 1000.;
  //----------------------------Second Graph-----------------------------------//

 TGraphErrors* g2 = new TGraphErrors();
  g2->SetName("g2");
  g2->SetMarkerColor(kBlue + 1);
  g2->SetMarkerStyle(2);
  g2->SetMarkerSize(1);
  g2->SetLineColor(kBlue);
  g2->SetLineWidth(2);

 std::ifstream in2("mZH07.txt");

  Int_t cnt = 0;
  do {
    std::string l2;
    std::getline(in2, l2);
    if (in2.bad()) break;

    if (l2[0] == '#') continue;

    std::stringstream parse(l2);

    Double_t x08, y08, e08;
    parse >> x08 >> y08 >> e08;
    g2->SetPoint(cnt, x08, y08);
    g2->SetPointError(cnt, 0., e08);

    cnt++;
    } while (!in2.eof());
  // g2->Draw("psame");

  valuey[nBin] = 1.;
  TGraph *liner = new TGraph(nBin + 1, xbin, valuey);
  liner->SetLineColor(kYellow + 1);
  liner->SetLineWidth(2);

// Declare second histograms
  TH1D *h2 = new TH1D("h2", ploTitle.c_str(),nBin,0.,1000.);
  h2->SetMarkerColor(kBlue + 1);
  h2->SetLineColor(kBlue);
  h2->SetFillColor(kBlue);
  h2->SetLineWidth(2);
  h2->SetAxisRange(0.001, 0.12, "y");

  Double_t x108, y108, e108;
  for (Int_t ii = 0; ii < nBin; ii++) { 

   g2->GetPoint(ii, x108, y108);
   e108 = g2->GetErrorY(ii);
   h2->SetBinContent(ii+1, y108);
   h2->SetBinError(ii+1, e108);
 }

  TH1D *ratio_plot = new TH1D("ratio", ";;Ratio (NLO / LO)", nBin, 0., 1000.);
  ratio_plot->Divide(h2, h1, 1., 1.);
  ratio_plot->SetMarkerStyle(1);
  ratio_plot->SetMarkerColor(kBlack);
  ratio_plot->SetLineColor(kBlack);
  ratio_plot->SetFillColor(kBlack);
  ratio_plot->SetFillStyle(3002);
  //  ratio_plot->SetTitle("");
  //  ratio_plot->GetYaxis()->SetTitle("Ratio (LO / NLO)");
  ratio_plot->GetYaxis()->SetNdivisions(505);
  ratio_plot->GetYaxis()->SetTitleSize(23);
  ratio_plot->GetYaxis()->SetTitleFont(43);
  ratio_plot->GetYaxis()->SetTitleOffset(1.5);
  ratio_plot->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  ratio_plot->GetYaxis()->SetLabelSize(21);
  ratio_plot->SetAxisRange(0.01, 1.99, "y");

  ratio_plot->GetXaxis()->SetTitle("m_{ZH} (GeV)");
  ratio_plot->GetXaxis()->SetTitleSize(23);
  ratio_plot->GetXaxis()->SetTitleFont(43);
  ratio_plot->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  ratio_plot->GetXaxis()->SetLabelSize(21);
  ratio_plot->GetXaxis()->SetTitleOffset(3.5);

  TCanvas *c1 = new TCanvas("c1", "Graph with error bars", 200, 10, 1000, 1000);
  gStyle->SetOptStat(0);

  // Upper plot will be in pad1
  TPad *pad1 = new TPad("pad1", "pad1", 0., 0.29, 1., 1.);
  pad1->SetBottomMargin(0); // Upper and lower plot are joined
  pad1->SetGrid();
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();               // pad1 becomes the current pad

  //  g1->SetHistogram(frame_hist);
  //  g2->SetHistogram(frame_hist);
  //  frame_hist->Draw("func");

  //  g1->Draw("p");
  //  g2->Draw("psame");
  h2->GetYaxis()->SetTitleOffset(1.1);
  h2->GetYaxis()->SetTitle("d#sigma/dm_{ZH} (fb / 10 GeV)");
  h2->Draw("E2");
  h1->Draw("E2same");

  TLegend *leg = new TLegend(.55, .75, .88, .89);
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  leg->SetTextFont(42);
  leg->SetTextSize(0.03);

  leg->AddEntry(h2, "HAWK NLO QED", "fp");
  leg->AddEntry(h1, "HAWK LO", "fp");
  leg->Draw();

  // lower plot will be in pad
  c1->cd();          // Go back to the main canvas before defining pad2
  TPad *pad2 = new TPad("pad2", "pad2", 0., 0., 1., 0.29);
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.2);
  pad2->SetGrid();
  pad2->SetLogy();
  pad2->Draw();
  pad2->cd();       // pad2 becomes the current pad);

  ratio_plot->SetAxisRange(0.3,9.99,"Y"); //0.6min utk QCD
  ratio_plot->Draw("E2");
  liner->Draw("l");
  ratio_plot->Draw("E2same");

  TLegend *legr = new TLegend(.55, .75, .88, .89);
  legr->SetFillColor(0);
  legr->SetBorderSize(0);
  legr->SetTextFont(42);
  legr->SetTextSize(0.06);

  legr->AddEntry(ratio_plot, "Hawk NLO / LO", "fp");
  legr->Draw();

  c1->cd();
  c1->SaveAs("mZHQED.pdf");
  c1->Close();

}
//bins = getBinsFromTGraph(TGraph)
