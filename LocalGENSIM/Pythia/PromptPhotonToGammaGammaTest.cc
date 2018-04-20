// main02.cc is a part of the PYTHIA event generator.
// Copyright (C) 2017 Torbjorn Sjostrand.
// PYTHIA is licenced under the GNU GPL version 2, see COPYING for details.
// Please respect the MCnet Guidelines, see GUIDELINES for details.

// This is a simple test program. It fits on one slide in a talk.
// It studies the pT_Z spectrum at the Tevatron.

#include "Pythia8/Pythia.h"
using namespace Pythia8;
int main() {
  // Generator. Process selection. Tevatron initialization. Histogram.
  Pythia pythia;

  // Beam Parameter Settings 
  pythia.readString("Beams:idA = 2212"); //proton
  pythia.readString("Beams:idB = 2212"); //proton
  pythia.readString("Beams:eCM = 13000."); //CM energy of collision 
  
  // Settings for the Process Generation  
  pythia.readString("PromptPhoton:gg2gammagamma = on");
  pythia.readString("PromptPhoton:ffbar2gammagamma = on");
  pythia.readString("PhaseSpace:pTHatMin = 70.");
  pythia.readString("PhaseSpace:mHatMin = 1000.");
  pythia.readString("PhaseSpace:mHatMax = 2000.");
  
  // Initialize. 
  pythia.init();

  // Book histograms. 
  Hist pTG("process pT scale", 100, 1000., 2000.);
  
  // Begin event loop. Generate event. Skip if error. List first one.
  for (int iEvent = 0; iEvent < 1000; ++iEvent) {
    if (!pythia.next()) continue;
    // Loop over particles in event.Fill its pT.
    int iG = 0;
    for (int i = 0; i < pythia.event.size(); ++i)
      if (pythia.event[i].id() == 23) iG = i;   // What is the right event ID? 
    pTG.fill( pythia.event[iG].pT() );
  // End of event loop. Statistics. Histogram. Done.
  }
  pythia.stat();
  cout << pTG;
  return 0;
}
