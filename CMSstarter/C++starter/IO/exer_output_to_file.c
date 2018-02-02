//Uzziel Perez

// to read/write with files instead of STDIN/STDOUT,
// instead of <iostream>, we use:
#include <fstream>

// but I'll still include iostream in case I want to write out helpful messages
#include <iostream>

using namespace std;


int main()
{
  // first open the file you want to write to

  // here the type of the object for an output file is ofstream
  ofstream file_out; 
  file_out.open("exer_output_test.temp");

  // and now you direct output to this file stream
  // like you do with cout

  // I will write two columns of numbers to this output file
// separated by tabs ("\t")
  
  file_out << "Include the square of the index" << endl;
  for(int i=0;i<10;i++) {
file_out << i << "\t" <<  100+i <<"\t" << i*i << endl;
    
  }

cout << " This program wrote to a file" << endl;

// finally, its important to close the file
file_out.close();

// now you can inspect the output file in your local directory and make sure it has
// the expected contents


}

