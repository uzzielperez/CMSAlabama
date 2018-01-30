// THis is the cource code (implementation) for the Proton class

//***************************************************
// Conor Henderson, Univ of Alabama, August 2011
//***************************************************

// as always, must include the header
// or else the compiler would not know that we are talking about the Proton class

#include "Proton.h"

Proton::Proton()
{
  // default constructor
  SetMomentum(0);
 // and the proton mass is fixed value at 0.938
  SetMass(0.938);

  // we also have to set the lifetime, which is a new member only of Proton class
  // (not of Particle)

  fLifetime =   1e32 ; //(years)
}

Proton::Proton(double p)
{
  SetMomentum(p);
  // and the proton mass is fixed value at 0.938
  SetMass(0.938);

  // Just a point in passing:
  // the members of Particle class were declared private
  // this means they can only be accessed within the class Particle code itself
  // another option within C++ is to declare them 'protected'
  // in that case, they can also be accessed directly by any class
  // which inherits from Particle

  // so, if they had been 'protected' instead of private, we could do:
  //  fP = p;
  //  fMass = 0.938;


  // and finally the lifetime
  fLifetime =   1e32 ; //(years)

}

