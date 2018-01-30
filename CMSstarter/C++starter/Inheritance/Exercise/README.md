#EXERCISE 
#Protons are particles with positive charge.
#Add a new member to the Proton class to store the charge of the proton 
#(+1 in units of e), and a new function to return this. Test using this in your program.
#ANSWER add new member in header file, store the charge value in the source code, 
#write the function in the source code, print in the program 

#Create for yourself a new class Photon which inherits from Particle, but sets the mass to zero.
# Then write an example program which uses this class, and make sure that you can compile and run it.

#First Compile the source code for the class 
#This creates Proton.o object file
g++ -c proton.cc

#To make a working executable
#If you are using a program using more than one class, all object files are needed 
g++ -o proton_example.exe proton_example.C Proton.o ../Classes/Particle.o

#To run 
./proton_example.exe
