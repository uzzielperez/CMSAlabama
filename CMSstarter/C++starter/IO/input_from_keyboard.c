// simple program to illustrate reading input from keyboard

//***************************************************
// Conor Henderson, Univ of Alabama, February 2013
//***************************************************

// screen output and keyboard input
// (aka STDOUT and STDIN)
// are provided by:
#include <iostream>

using namespace std;

int main() 
{

  // to read an input from keyboard, we use cin
  // first we need to prepare a variable to accept the input
  // let's say we want a number, a double
  double a;

  // prompt the user to enter data
  cout << "Please enter a number: " <<endl; 


  // then fill the variable with value from STDIN
  cin >> a;

  // echo it back to test
  cout << "The number you entered was " << a << endl;
 
}
