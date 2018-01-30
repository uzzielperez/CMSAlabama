// the implementation file (source code) for the Particle class


//***************************************************
// Conor Henderson, Univ of Alabama, August 2011
//***************************************************

// for the source file for any class, we must always include the header file for that class
// otherwise the compiler will not understand what functions you are talking about ...

#include "Particle.h"


#include <math.h>
// we will use the sqrt() function in the energy calculation
// to use this function, we need to include the Math header which defines it
// this math header is part of the standard C++ library
// once we have included it, we have access to all the math functions it defines
// see: http://www.cplusplus.com/reference/clibrary/cmath/


Particle::Particle() 
{
  // this is the default constructor
  // if we dont give any arguments, the mass and momentum will be zero
  fMass = 0;
  fP = 0;
}

Particle::Particle(double mass, double p) 
{
  // this is the normal constructor for an object of the class Particle
  // we create the object
  // and assign the appropriate values to its members

  fMass = mass;
  fP = p;

}

double Particle::GetMass() 
{
  return fMass;

}

void Particle::SetMass(double new_mass) 
{
  fMass = new_mass;
}


double Particle::GetMomentum()
{
  return fP;

}

void Particle::SetMomentum(double new_momentum)
{
  fP=new_momentum;

}

double Particle::GetEnergy()
{
  // this is the first function that does something more than basic
  // it calculates the energy of the particle from its mass and its momentum
  
  // by doing this inside the class itself, we can make our program code simpler
  // now in any program which uses this Particle class, we dont have to write code which 
  // calculates the energy of a particle.
  // we can just get the energy using particle.GetEnergy()

  return sqrt(fMass*fMass+fP*fP);
  
}


//Note that nowehere in this code is there a main() function
// so this code cannot be executed on its own
// a class is therefore not a program itself, it is just something that can be used in a program

