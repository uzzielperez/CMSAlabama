// Simple tree example

//Conor Henderson, Univ of Alabama, March 2013

// trees are one of the most useful features of ROOT
// they are good for situations where you are processing lots of events
// and you want to store the same type of information for each one
// for this example we will imagine processing events which contain
// a photon. For each event, we want to store the px, py, pz components 
// of the photon's momentum for later analysis
// you  can think of this kinda like a table:
// we have columns to the table comprising the momentum components
// and then each row corresponds to a different event/photon,
// with the values appropriate for that event
// saving the information this way allows for more complicated analysis
// to be done on this information later


{
  gROOT->Reset();


  // define the tree
  TTree *ParticleTree = new TTree("ParticleTree","Particle Tree");
  
  // these variables will hold the values for the momentum components
  Float_t px,py,pz;
  
  // a TTree consists of Branches to hold the data 
  // for each branch, you give the name of the branch,
  // *and the address of the holding variable which will contain the data*

  // these are simple branches, with one Leaf
  // more generally, branches can have more than one leaf
  // the last option in the Branch constructor is the LeafList
  // this describes each of the leaves, and what type of data they are
  // in this case, the LeafList is just a single variable of type float(F)

  ParticleTree->Branch("px",&px,"px/F");
  ParticleTree->Branch("py",&py,"py/F");
  ParticleTree->Branch("pz",&pz,"pz/F");


  // fill the tree with random numbers in this example
  for(Int_t i=0;i<100;i++)   {

    // you have to make sure to update the px,py,pz variables
    // to actually contain the values that you want for this particular event
    // each tree entry is created by copying info from the holding variables
    // at the appropriate time
    px = gRandom->Gaus(10,2);
    py =  gRandom->Gaus(10,2);
    pz =  gRandom->Gaus(20,4);

    // once the values assigned to all holding variables are done,
    // then we call TTree::Fill()
    // this operation instructs the branches to copy the current data
    // from their holding variables to the tree
    // note that this function automatically creates a new entry 
    // in the tree, so you are not overwriting previous entries
    ParticleTree->Fill();
  }
 

  // even if I didnt change the px,py,pz, I could still create new
  //tree entries repeatedly using Fill(). For example:
  px = 110;
  py = 110;
  pz = 110;
  ParticleTree->Fill();
  ParticleTree->Fill();
  ParticleTree->Fill();
  ParticleTree->Fill();
  // and each time we called Fill() above, we made another entry
  // but the values were always the same ...


  // can test the tree was created and has entries
  ParticleTree->Print();

  // now save tree to file
  TFile fout("example_tree.root","RECREATE");
  ParticleTree->Write();
  fout.ls();
  fout.Close();

  // in the next example we will read the tree back from the file
  // and start to make use of the data stored in it

}
