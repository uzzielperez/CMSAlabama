//Exercise 
//Uzziel Perez

#include "particle.h"
#include <iostream>

using namespace std; 

int main()
{
  double mass = 0.938; //(GeV a proton)
  double momx = 50; //GeV
  double momy = 50; 
  double momz = 50; 

  Particle p1(mass, momx, momy, momz); 
  cout<< "Particle 1: mass = " << p1.GetMass(); 
  cout<< "; momentum  = " << p1.GetMomentum(); 
  cout<< "; pT = " << p1.GetTransverseMomentum(); 
  cout<< "; phi = " << p1.GetPhi(); 
  cout<< "; energy = " << p1.GetEnergy() << endl; 
  
  double mom2x = 25; 
  double mom2y = 25; 
  double mom2z = 25; 
  Particle p2(mass, mom2x, mom2y, mom2z); 
  cout<< "Particle 2: mass = " << p2.GetMass(); 
  cout<< "; momentum  = " << p2.GetMomentum(); 
  cout<< "; pT = " << p2.GetTransverseMomentum(); 
  cout<< "; phi = " << p2.GetPhi(); 
  cout<< "; energy = " << p2.GetEnergy() << endl; 

  return 0; 
}
