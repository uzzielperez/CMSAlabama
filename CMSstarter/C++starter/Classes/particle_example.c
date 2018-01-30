// example program making use of the Particle class

//***************************************************
// Conor Henderson, Univ of Alabama, August 2011
//***************************************************


#include "Particle.h" 
// to use the Particle class, we must include its header file
// this header will declare to the program what the class contains and what it can do


#include <iostream>
// now that we know what a header file is, we can explain that the above line includes
// the iostream functionality from the standard C++ library,
// which is what allows us to print our messages to the screen (via cout)
using namespace std;
// we still havent explained namespace yet though ...





// rememeber, all executable programs must have a main() function
// this is where program execution starts
int main() 
{

  double mass  = 0.938; //GeV (a proton)
  double mom  = 50 ; //GeV

  // now we create a Particle object which has these values
  // this will use the normal constructor defined in Particle.cc
  Particle p1(mass,mom);

  // and here is an example of how to use functions belonging to a class (its methods)
  cout << "Particle 1: mass = " << p1.GetMass();
  cout<< "; momentum = " << p1.GetMomentum();
  cout<< "; energy = " << p1.GetEnergy() << endl;

  // we can make another particle as a different object but using the same class
  // lets say it has the same mass but a different momentum.

  double mom2 = 25.0; 
  Particle p2(mass,mom2);

  cout << "Particle 2: mass = " << p2.GetMass();
  cout<< "; momentum = " << p2.GetMomentum();
  cout<< "; energy = " << p2.GetEnergy() << endl;

  


  return 0;

}

