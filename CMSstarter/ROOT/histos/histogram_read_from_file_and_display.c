// here we read an existing histogram from a ROOT file
// and display it

// Conor Henderson, University of Alabama, Feb 2013

{
  // we use the ROOT file 'histogram_output.root'
  // which was created by previous example in this tutorial

  TFile file_in("histogram_output.root");
  // by default, with no second argument, a TFile is opened for reading-only

  //list the objects stored in this file
  file_in.ls();

  // the object we want is the TH1F named 'example_h'
  // here is how we get it:
  TH1F *example_h = (TH1F *) file_in.Get("example_h");

  // first note that the 'example_h' on the left side is our choice of name
  // we could equally well have done the following and it would still work:
  //  TH1F *random_name_h = (TH1F *) file_in.Get("example_h");
  // but the 'example_h' on the right is needed because that is the ROOT name
  // saved with the object. Without this name, we could not get it back from
  // the file. So the following would NOT work:
  //  TH1F *example_h = (TH1F *) file_in.Get("some_other_name");

  // Also a comment on the (TH1F *) on the right side:
  // any ROOT object can be stored in a ROOT file.
  // so the function which finds and returns the object 'TFile::Get()'
  // must return the most generic base type possible (TObject)
  // we therefore have to explicitly *cast* the type to a TH1F
  // because we know that this particular object is really a TH1F
  // that's what the (TH1F *) achieves
  // (Dont worry too much about this if it isnt clear yet - just make sure
  // to do it when reading objects from files)

  


  // now we want to display this histogram
  // first we make a canvas:

  TCanvas *c1 = new TCanvas("c1","Display Canvas",800,600);
  // here the first 'c1' argument is the ROOT name of the object
  // and the 'Display Canvas' is the title of this canvas
  // then 800,600 are the width and height of the canvas in pixels
  // (this part  is optional)

  // the canvas will immediately appear on your screen
  // now we draw the histogram on the canvas

  example_h->Draw();

  // say we want to save this plot to use it in a talk or paper
  
  // we do this by saving the canvas
  c1->SaveAs("plot.pdf");
  c1->SaveAs("plot.gif");
  // this creates an output file with the given name (in the local directory)
  // ROOT reads the extension in the file name
  // and makes an output file in the appropriate format!

  
  
  // we should close the file once we are done
  // note that this will make the histogram disappear!
  //  file_in.Close();




}
