// Header (interface) file for simple Particle class

//***************************************************
// Conor Henderson, Univ of Alabama, August 2011
//***************************************************

// to declare a class, we use the C++ keyword 'class'


class Particle {

  // the 'members' of this Particle class will be the variables
  // for mass and momentum
  // we want them to be private, meaning they can only be accessed inside the class itself
  // so we define these as follows:

 private: 

  double fMass;
  double fP;

  // a sidenote: I have put an 'f' at the start of the variable names
  // this is the convention used inside of ROOT code to indicate variables
  // which are members of a class. In the source code, it is convenient
  // to use a convention to identify which variables are members, to separate them from 
  // variables which are external to the class. In CMS software, sometimes an '_' might be used for this convention, eg Mass_  instead of fMass.


  // now we want to list the public parts of the class
  // here we will put the functions that we want to be able to use for the class

 public:

  Particle();
  // the above function is very important - it is called the default constructor
  // for the class. All C++ classes must have a default instructor. 
  // this is the function that is called when you try to create an object of the class, 
  // without any arguments

  Particle(double mass, double p);

  // this is the normal constructor. It makes an object of the class with the given values for m and p


  // now some basic functions, to get and set values of mass and momentum
  double GetMass();

  double GetMomentum();

  void SetMass(double new_mass);

  void SetMomentum(double new_momentum);


  // here is our first function of the class to do something more than just basic
  // it calculates the particle energy from the mass and momentum
  
  double GetEnergy();

  // the code implementing all these functions can be found in the Particle.cc file

};

// and note the semicolon after the closing brace of the Particle class definition!
// this is very important
// it is easy to forget this semicolon
// but you will not be able to compile your code without it!
// and unfortunately the errors will not say "you  forgot the semicolon
// at the end of your class definition"
// instead the errors will appear to be unrelated things in subsequent lines!



