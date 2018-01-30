// Here is a simple program to use our new class Proton,
// which inherits from Particle

//***************************************************
// Conor Henderson, Univ of Alabama, August 2011
//***************************************************

// for the standard terminal-printing ability ...
#include <iostream>
using namespace std;

// to use the Proton class, as always we need its header file
#include "Proton.h"

// note that we know Proton inherits from Particle
// does that mean that we also need to include hte Particle header here?
// The answer is No
// The reason is that the Proton.h header already includes Particle.h
// so when we include Proton.h, that has the effect of already including Particle.h
// The #include statement is an instruction to the compiler to literally copy 
// the contents of the named file into the current program source
// so '#include Proton.h' will literally copy all of Proton.h 
// into this source code
// and then when the compiler finds the '#include Particle.h' within Proton.h
// then it will continue to copy all of Particle.h in as well
// this goes on to whatever level of recursion thats needed
// (technically, the part of the compiler suite which handles these include 
// statements is called the preprocessor.)

int main() 
{

  // create a proton with some momentum
  Proton pr1(50.0);

  // example using some of the methods of the class
  cout << "Proton 1: mass = " << pr1.GetMass();
  cout<< "; momentum = " << pr1.GetMomentum();
  cout<< "; energy = " << pr1.GetEnergy() << endl;


  // and a second proton, for kicks ...
  Proton pr2(25.0);

  cout << "Proton 2: mass = " << pr2.GetMass();
  cout<< "; momentum = " << pr2.GetMomentum();
  cout<< "; energy = " << pr2.GetEnergy() << endl;



}
