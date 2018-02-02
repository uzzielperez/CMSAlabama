// simple program to illustrate input from a file instead of keyboard (ie STDIN)

//***************************************************
// Conor Henderson, Univ of Alabama, February 2013
//***************************************************

// to read/write with files instead of STDIN/STDOUT,
// instead of <iostream>, we use:
#include <fstream>

// but I'll still include iostream in case I want to write out helpful messages
#include <iostream>



using namespace std;

int main() 
{
  // first open the file to read from
  ifstream file_in("output_test.temp");

  
  // usually a good idea to check the file open operation worked!
  if(!file_in.is_open()) {
    cout << "Couldnt open file!" <<endl;
    cout << "Bailing out!" <<endl;
    return -1; 
  }

  //else continue

  // you can read a whole line at once with getline()
  // and treat it like a string
  
  // But here I know the format of my input data (2 columns of numbers)
  // so I tailor to it

  double col1, col2;
  
  // so I know the columns, but not how many lines in the file
  // (this is fairly typical of our siutations)
  // so I need to read the whole file
  // a helpful way to do this, and also to check for errors in teh reading
  // is to use the good() function 
  while(file_in.good()) {
    file_in >> col1 >> col2;

    cout <<"col1 = " <<col1 <<"; col2 = " << col2 <<endl;
  }
  

  // finally, close the file
  file_in.close();

}
