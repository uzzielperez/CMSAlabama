//Uzziel Perez
//Exercise
// in this example we construct a more complex tree
// closer to the style of what we'd do in a real HEP analysis

{

  gROOT->Reset();

  // create our tree
  TTree *tree = new TTree("PhotonTree","PhotonTree");

  //Structs
  struct event_info_struct{
    Int_t RunNumber;
    Int_t EventNumber;
  };

  

  struct photon_mom_struct{
    Double_t px;
    Double_t py;
    Double_t pz;
  };

  struct vertex_struct{
    Double_t vx;
    Double_t vy;
    Double_t vz; 
  };
 
  //Instances of structs
  event_info_struct this_event_info;
  photon_mom_struct photon1;
  photon_mom_struct photon2;
  vertex_struct vertex_info;

  //TREE Branches
  tree->Branch("EventInfo",&this_event_info,"RunNumber/I:EventNumber/I");
  tree->Branch("Photon1",&photon1,"px/D:py:pz");
  tree->Branch("Photon2",&photon2,"px/D:py:pz");
  tree->Branch("Vertex", &vertex_info, "vx/D:vy:vz");
  // we will assign the run number:
  this_event_info.RunNumber = 1;

  for(Int_t i=0;i<100;i++)   {
    
    // increment the event number to identify this event
    this_event_info.EventNumber = i+1;

    // and give random numbers for the photon momentum
    //gRandom->Gaus(mean, sigma);
    photon1.px = gRandom->Gaus(10,2);
    photon1.py = gRandom->Gaus(10,2);
    photon1.pz = gRandom->Gaus(20,5);
    
    photon2.px = gRandom->Gaus(10,2);
    photon2.py = gRandom->Gaus(10,2);
    photon2.pz = gRandom->Gaus(20,5);

    //mean position along z 0, width, 10 cm
    vertex_info.vx = vertex_info.vy = 0; 
    vertex_info.vz = gRandom->Gaus(0,10); //in Centimeters


    tree->Fill();
  }
  


  tree->Print();

  // save tree to file
  TFile file_out("exer_vertex_2photons.root","RECREATE");
  tree->Write();
  file_out.ls();
  // remember that it is not physically written till we close the file
  file_out.Close(); 

  
}
