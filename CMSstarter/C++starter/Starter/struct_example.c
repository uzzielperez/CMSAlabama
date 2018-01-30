// this example shows how to group related variables together, using 'structs'

//****************************************************
// Conor Henderson, University of Alabama, August 2011.
//****************************************************


#include <iostream>
using namespace std;


int main() 
{

  // suppose we are writing a program involving particles,
  // and that for each particle, we will make use of its mass and its momentum

  // we might create a variable for each of these quantities, like this:
  // double mass;
  // double momentum;
  
  // Now suppose, we are going to be working with two or more particles
  // In BASIC-style programming, we would probably create a list of variables:
  // double mass_1;
  // double mass_2;
  // double mass_3;
  // double momentum_1;
  // double momentum_2;
  // double momentum_3;
  // etc

  // This would do the job, but in C++ we can find a better solution

  // We know that mass_1 and momentum_1 are for the same particle
  // similarly for mass_2 and momentum_2, etc
  // it would be nice if we can also tell our program code that these variables are 'connected'  
  // We can do this using a 'struct', which is a data structure that can link together related variables

  // So instead we will make a struct which contains two variables: mass and momentum

  struct particle {
    double mass;
    double p;
  };
  // note the semicolon after the closing brace of the struct here
  // this is important
  // its easy to forget, but will cause lots of compilation problems
  // if it is omitted


  // we have chosen to call this struct defintion 'particle', 

  // now that we have defined this 'particle' struct, we can use it just like the basic data types (int, double, etc)! 

  // so we create an object which is an instance of this struct type:

  particle p1;

  // then we need to assign the values of the variables for this object
  // we do this with the following syntax:
  // object.variable = value;

  p1.mass = 0.938;
  p1.p = 50.0;

  // anytime we want to access the variables within the struct, 
  // we do it by writing object.variable

  cout << "Particle 1: mass = " << p1.mass;
  cout << "; momentum = " << p1.p <<endl;

  // and we can make a second 'particle' using the same defined struct

  particle p2;
  p2.mass = 0.938;
  p2.p = 25.0;

  cout << "Particle 2: mass = " << p2.mass;
  cout << "; momentum = " << p2.p <<endl;


  // You can see that this use of structs is much nicer than making tons of unrelated variables like:
  // double mass_1;
  // double mass_2;
  // double mass_3;
  // double momentum_1;
  // double momentum_2;
  // double momentum_3;
  // etc

  // in the unrelated case, its only the names of the variables that tell us that mass_1 and omomentum_1 are referring to the same particle
  // but with the struct, we know that p1.mass and p1.momentum are both properties of particle p1


  


  return 0;
}
