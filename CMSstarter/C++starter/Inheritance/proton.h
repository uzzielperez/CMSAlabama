// Here is an example of C++ inheritance
// we will make a new class Proton
// which inherits from the previous class Particle
// (we also say that Proton is derived from the Particle class)

// The derived class will inherit all the members and methods of
// the parent class
// plus we can add members and methods specific for the derived class

// inheritance is one of the most powerful features of C++
// it is used a lot in large software projects
// this is just a very simple example 

//***************************************************
// Conor Henderson, Univ of Alabama, August 2011
//***************************************************

// we want our new class to inherit from Particle
// as usual, when we refer to the Particle class, we need to include its header
#include "../Classes/particle.h"

// to make a new class Proton which inherits from Particle, 
// we declare the class as follows:

class Proton: public Particle {

  // now the new class has inherited everything from Particle
  // if we want to add anything specific to Proton class, we would do it here
  // just as an example, let's add a new member for the lifetime of the particle

 private:

  double fLifetime; 

 public:

  Proton(); 
  // the default constructor for this class

  Proton(double p);
  // normal constructor

};


