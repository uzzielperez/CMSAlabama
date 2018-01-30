//Uzziel Perez

#include <vector>
#include <iostream>

//We will use the particle class to get pT
#include "particle.h"


using namespace std;

int main()
{
 
  //Ordinary way
  double mass = 0.938; //(Gev) proton
  double momx = 50;
  double momy = 50;
  double momz =50;

  //Create Particle Objects
  Particle p1(mass, momx, momy, momz);
  Particle p2(mass, momx/2, momy/2, momz/2);
  
  //Use Function to get the Transverse momentum and print out
  cout << "Particle 1 pT = " << p1.GetTransverseMomentum() << endl;
  cout << "Particle 2 pT = " << p2.GetTransverseMomentum() << endl;

  //*************USING VECTORS*******************
  vector<Particle> photon;
  photon.push_back(p1);
  photon.push_back(p2);

  cout << "Size of the vector: " << photon.size() << endl;
  cout << "Photon 1 pT: " << photon[0].GetTransverseMomentum()<<endl;
  cout << "Photon 2 pT: " << photon[1].GetTransverseMomentum()<<endl;

  //Iterating over the vector (This method is ok in practice but diminishes flexibility)
  for (int i  =0; i< photon.size(); i++){
    cout <<"Photon " << i+1<< " pT = " << photon[i].GetTransverseMomentum()<<endl;
  }

  //Usually, the right way to do it is like this:
  //for(std::vector<T>::iterator it = v.begin(); it != v.end(); ++it) {
  //    it->doSomething();
  //     }}
  
  for (vector<Particle>::iterator iter=photon.begin(); iter !=photon.end(); ++iter){
               cout << "pT = " <<  iter->GetTransverseMomentum() << endl;
  }
return 0;
}
