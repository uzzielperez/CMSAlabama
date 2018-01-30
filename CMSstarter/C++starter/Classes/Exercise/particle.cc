//Source Code for the Particle Class
//Uzziel Perez

#include "particle.h"
#include <math.h>

Particle::Particle()
{
  fMass = 0; 
  fpx = 0; 
  fpy = 0; 
  fpz = 0; 
}

Particle::Particle(double mass, double px, double py, double pz)
{
  fMass = mass; 
  fpx = px; 
  fpy = py; 
  fpz = pz; 
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
  return sqrt(fpx*fpx+fpy*fpy+fpz*fpz);
}

double Particle::GetEnergy()
{
  double p = GetMomentum(); 
  return sqrt(fMass*fMass + p*p);
}

double Particle::GetTransverseMomentum()
{
  return sqrt(fpx*fpx + fpy*fpy); 
}

double Particle::GetPhi()
{
  return atan(fpy/fpx); 
}
