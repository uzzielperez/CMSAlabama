#Compile source code for the class
g++ -c Particle.cc

# This makes an object file Particle.o
#(The -c option tells g++ to stop at 'compile' and don't try to link).

#To make executable, link with object file Particle.o 
g++ -o particle_example.exe particle_example.C Particle.o

