// Simple example to create and fill a histogram
// and save it to an output ROOT file

// Conor Henderson, University of Alabama, Feb 2013

{ 
// when we start like this with just an opening brace,
// this means that the ROOT command-line interpreter (called CINT)
// will just process all the commands below, one line at a time


  gROOT->Reset();
  // this clears ROOT session memory (sort of)
  // so that the commands here dont conflict with previous commands
  // in the same session
  //(remember that when you start a ROOT session, you open up
  // an environment, so there is a history ...)
  // when you start a new ROOT session, it starts from scratch though

  
  // create a histogram
  TH1F *example_h = new TH1F("example_h","An Example Histogram",100,0,500);
  // TH1 is the base class for ROOT histograms
  // TH1F is a derived class, specifically for histograms containing floats
  // here we are actually making a pointer to a TH1F object, using the new command
  // this is the usual way we work with objects in ROOT

  // the first argument to the TH1F constructor is the 'ROOT name' of the object
  // within a ROOT session, ROOT does its own book-keeping of objects 
  // which have been created.
  // the 'ROOT name' is a unique name given to every ROOT object
  // this is conceptually different from the variable name which you assign
  // the object in your programs.
  // For example, when an object is saved to a ROOT file, the 'ROOT name'
  // is saved as part of it. But the variable name that you referred to it
  // by yourself, is lost.
  // Having said that, we frequently make the variable name and ROOT name be the
  // same (as in the above example) for convenience.

  // the second argument is the histogram title, which will be displayed 
  // the next 3 arguments define the histogram binning:
  // Number of bins, starting point of bin range, end point
  // so in this example we make 100 bins from 0 to 500
  // each bin is therefore of width 5.

  // we usually want to label the axes of this histogram
  example_h->GetXaxis()->SetTitle("Example x-axis title");
  example_h->GetXaxis()->CenterTitle();
  example_h->GetYaxis()->SetTitle("Number of events");
  example_h->GetYaxis()->CenterTitle();
  

  // now we are going to do a simple loop and fill this histogram
  // imagine that we are processing a set of events
  // each event contains one photon
  // and we want to see the distribution of the transverse momentum of the photons in these events
  
  for(Int_t i=0;i<100;i++) {
    
    // in a real event loop, we would read the values from the stored event
    // but in this simple example, we'll just use random numbers instead

    Float_t photon_pt;
    photon_pt = gRandom->Gaus(250,50);
    // here we use ROOT's builtin random number generator, gRandom
    // and we ask for the random number from a Gaussian distribution, with mean 250 and width 50. 

    // we could print it if we want:
    // cout <<"Photon pt = " <<photon_pt<<endl;

    // now we fill the number into the histogram
    example_h->Fill(photon_pt);
    // the histogram itself determines which bin this particular
    // value goes in, then increments the count for that bin
    // at the end, the histogram shows the distribution of the variable
    // by showing how many entries were in each bin  
    
  }
  
  // now lets save the histogram to an output file
  // ROOT allows us to save actual ROOT objects to files
  // the file is a new type of file format, which we just call a ROOTfile,
  // and usually give it the extension .root

  TFile file_out("histogram_output.root","RECREATE");

  // TFile is the ROOT class for input/output files
  // here the file will be named "histogram_output.root"
  // and will be created in the local workign directory of the ROOT session
  // the second argument "RECREATE" means to create the file for writing
  // and if there is already a file with the same name, then erase the old file

  // now that the file is created, we tell the histogram to write itself to this file
  example_h->Write();

  // check what has been written to the file:
  // this prints current file contents
  file_out.ls(); 
  
  // the file isnt physically written until we explicitly close it:
  file_out.Close();
  



}
