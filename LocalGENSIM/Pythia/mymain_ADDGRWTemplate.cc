// Copyright (C) 2017 Torbjorn Sjostrand.
// PYTHIA is licenced under the GNU GPL version 2, see COPYING for details.
// Please respect the MCnet Guidelines, see GUIDELINES for details.

// http://home.thep.lu.se/~torbjorn/pythia8/worksheet8153.pdf

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
  pythia.readString("ExtraDimensionsLED:ffbar2gammagamma = on");
  pythia.readString("ExtraDimensionsLED:gg2gammagamma = on");
  pythia.readString("PhaseSpace:pTHatMin = 70.");
  pythia.readString("PhaseSpace:mHatMin = ${massMin}");
  pythia.readString("PhaseSpace:mHatMax = ${massMax}");

  // LED parameters
  pythia.readString("ExtraDimensionsLED:MD = ${md}"); // Fundamental scale of gravity, Ms = 4.
  pythia.readString("ExtraDimensionsLED:n = ${ned}"); // number of extradimensions, default =2 
  pythia.readString("ExtraDimensionsLED:LambdaT = ${lambdaT}"); // Ultraviolet cutoff for virtual graviton exchange
  //pythia.readString("ExtraDimensionsLED:CutoffMode = 2"); // 0 - all values of sHat contribute
  							// 1 - truncate contributing sHat region
							// 2 - Form factor using mu = renormScale2
							// 3 - Form factor using mu = E_jet
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
      if (pythia.event[i].id() == 22) iG = i;   // gamma ID = 22  
    pTG.fill( pythia.event[iG].pT() );
  // End of event loop. Statistics. Histogram. Done.
  }
  pythia.stat();
  cout << pTG;
  return 0;
}
