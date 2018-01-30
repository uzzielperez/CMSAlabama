//Uzziel Perez


#include <vector>
#include "../../Classes/Exercise/particle.h"
#include <iostream>
#include <algorithm>

using namespace std;

//Comparison Function



bool compare(Particle a, Particle b){
  if (a.GetTransverseMomentum()<b.GetTransverseMomentum())
    return true;
  else
    return false;
}

//MAIN FUNCTION


int main()
{
  vector<Particle> photon_collection;
  
  double mass = 0.938;
  double px = 50;
  double py = 50; 
  double pz = 50; 

  Particle p1(mass, px, py, pz);
  Particle p2(mass,2*px, 2*py, 2*pz);
  Particle p3(mass, 0.5*px, 0.5*py, 0.5*pz);
  Particle p4(mass, 0.25*px, 0.25*py, 0.25*pz);
  Particle p5(mass, 3*px, 3*py, 3*pz);

  photon_collection.push_back(p1);
  photon_collection.push_back(p2);
  photon_collection.push_back(p3);
  photon_collection.push_back(p4);
  photon_collection.push_back(p5);

  //Print unsorted photon collection:

  for (vector<Particle>::iterator i=photon_collection.begin(); i != photon_collection.end(); ++i){
      //cout << *i<< endl; //Curious about what this would do?
      cout  <<"pT: " << i->GetTransverseMomentum() << endl;
  }

  //To sort
  
  sort(photon_collection.begin(), photon_collection.end(), compare);

  //Display Sorted Vector

cout <<"SORTED VECTOR: " << endl;
 for (vector<Particle>::iterator i=photon_collection.begin(); i != photon_collection.end(); ++i){
      //cout << *i<< endl; //Curious about what this would do?
      cout  <<"pT: " << i->GetTransverseMomentum() << endl;
  }




  return 0;
}
