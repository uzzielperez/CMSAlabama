// take a tree from file and draw data 
// example of how to interact with a Tree in a simple way

{

  gROOT->Reset();

  // some nice cosmetic setting for plots
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1,0);


  // open file for reading  
  // this file was created in previous tree example macro
  TFile fin("example_tree.root");
  fin.ls();


  TTree *tree = (TTree *) fin.Get("ParticleTree");

  tree->Print();

  cout << "Tree has N entries = " << tree->GetEntries() <<endl;

  // Now let's see some of the things we can do with this tree:

  // we can see all the values for a specifc entry in the tree
  cout << endl;
  cout << "Displaying a particular entry in the tree: " <<endl;
  cout << endl;
  Int_t ientry = 34;
  tree->Show(ientry);

  cout << endl;
  cout << endl;
  cout << endl;



  // doing some rudimentary analysis:
  // let's examine the data for all cases where px>12, but only for those cases

  cout <<"Showing data for all entries where px>12:" <<endl;
  cout << endl;

  // for this we can use the TTree::Scan() function  
  tree->Scan("px:py:pz","px>12");
  // first argument are the leaves to be printed; 
  // second arg is the selection to be made on the entries 
  // - only entries for which the expression evaluates to TRUE will be displayed

  cout << endl;
  cout << endl;
  cout << endl;



  // but the most useful simple feature of a Tree is to draw the data from it
  // here are some examples

  // first make a canvas for all the plots to go in
  TCanvas *c1 = new TCanvas("c1","c1",800,600);
  // now let's subdivide the canvas into 4 panels
  // and put a plot in each one
  c1->Divide(2,2);


  // first do a simple plot of just one leaf
  c1->cd(1);
  tree->Draw("px");

  // we can also do more complicated plots:
  // plotting combinations of variables, or functions of variables
  c1->cd(2);
  tree->Draw("TMath::Sqrt(px*px+py*py+pz*pz)","px<109");
  // here the second argument is again a selection, which we call a 'cut'
  // only entries for which this expression evaluates to TRUE are considered
  // this idea of making a cut on only certain entries in the tree is very useful to us, and we do it a lot


  // here's how we could make a 2D plot, of 'ys vs x' - write it as 'y:x'
  c1->cd(3);
  tree->Draw("py:px","px<109","lego");

  // we also introduce the 3rd argument to Draw()
  // this is a graphical option
  // the options are the same as the ones you can give to histograms
  // this particular option means to draw a 'lego' plot:
  // for the y vs x 2D histogram, the number of entries in each bin
  // is shown as a column of certain height

  // here is the same info but presented in a different way
  c1->cd(4);
  tree->Draw("py:px","px<109","colz");
  // the colz option means to display the info of N events per bin 
  // (think of it as the z-axis for this 2D histo)
  // as a color code, and show a scale to explain what each colr corresponds to

  

  // normally we should close the file once we're done
  // I'm not doing it this time, because it would remove the tree
  // from memory, and you wouldnt be able to see the plots ...
  //  fin.Close();

}
