// in this example we construct a more complex tree
// closer to the style of what we'd do in a real HEP analysis

{

  gROOT->Reset();

  // create our tree
  TTree *tree = new TTree("PhotonTree","PhotonTree");

  // now we will make an example of a branch with leaves
  // each leaf of a tree corresponds to a specific variable
  // to store for that entry
  // related leaves are grouped into a branch

  // our first set of info is the identification of the event
  // we specify each event first by a unique run number, then a unique 
  // event number within that run
  // we will make a branch with two leaves to store this info per event

  // as always, we first need some holding variables that we 
  // will use to store the desired info event by event.
  // when we have related leaves for a branch, it's convenient
  // to use a struct instead of individual variables

  // so declare our event info struct
  struct event_info_struct{
    Int_t RunNumber;
    Int_t EventNumber;
  };

  // the above just *declares* the struct
  // it does not make an actual *instance* of one
  // to do that:
  event_info_struct this_event_info;
  

  // we suppose that every event contains a photon
  // for every event, we want to store the momentum info of this photon
  // so we also create a struct for the photon momentm components:
  struct photon_mom_struct{
    Double_t px;
    Double_t py;
    Double_t pz;
  };
  // and again we must make an actual instance of this struct:
  photon_mom_struct this_photon_mom;
  // now photon_mom.px etc will hold the data to be filled into our tree
  
  
  // now we define the tree
  // it will have two branches
  // the first branch is for the event information
  // the second branch is for the photon momentum

  // so first, the event info branch
  // this branch will have two leaves

  tree->Branch("EventInfo",&this_event_info,"RunNumber/I:EventNumber/I");
  // first argument is the name of the branch
  // second argument is the address of the variable from which the branch 
  // will copy its information (when told to do so)
  // this is where a struct is convenient - we just tell the Branch
  // to start copying from the struct, and it fills in everything automatically from there 

  // we must make sure the leaflist (3rd argument to the function)
  // matches the order in which the variables are within the struct
  // it is also important that the types of variables match too
  // ie doubles to doubles, ints to ints etc...
  // the type is specified by '/I' for int, '/D' for double etc...
  // if the leaflist and the struct definition dont match,
  // then bad things will happen!


  // now the second branch, for the photon momentum
  tree->Branch("Photon",&this_photon_mom,"px/D:py:pz");
  // note that in the leaflist here, I didnt need to specify '/D' for py and pz
  // the convention is that subsequent leaves have the same type as previous 
  // leaves, unless said otherwise. so it was enough to specify 
  // the first one as type Double, then the others are assumed to also be double
  



  // now in this example we will just fill the tree with random numbers
  // in reality, we would obtain the information from real recorded events by the experiment

  // we will assign the run number:
  this_event_info.RunNumber = 1;

  for(Int_t i=0;i<100;i++)   {
    
    // increment the event number to identify this event
    this_event_info.EventNumber = i+1;

    // and give random numbers for the photon momentum
    this_photon_mom.px = gRandom->Gaus(10,2);
    this_photon_mom.py = gRandom->Gaus(10,2);
    this_photon_mom.pz = gRandom->Gaus(20,5);
    
    // the structs now hold the data we want for the event info, and the photon
    // so we can fill the tree now
    tree->Fill();
  }
  


  tree->Print();

  // save tree to file
  TFile file_out("more_complex_tree.root","RECREATE");
  tree->Write();
  file_out.ls();
  // remember that it is not physically written till we close the file
  file_out.Close(); 

  




}
