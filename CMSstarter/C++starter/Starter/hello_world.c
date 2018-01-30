// A first program in C++

// This will print the phrase "Hello world!" to the screen
// We will use this to introduce the basic elements of a C++ program

// I recommend to also refer to the tutorials available at:
// http://www.cplusplus.com/doc/tutorial/



//***************************************************
// Conor Henderson, Univ of Alabama, August 2011
//***************************************************


// First of all, note that every line which starts with //
// (like this one) 
// is a 'comment' in C++
// This will not appear in the final program
// but it is a very useful way to add comments to explain what
// your program is trying to do

// In order to print things to the terminal screen
// we need to include the following 'header' file
// we'll explain this in more detail later
// for now, just note that we must include this 'header' file

#include <iostream>

// likewise, we will explain the following line later too...
using namespace std;




// all C++ executable programs need to have a 'main' function,
// and it needs to be called 'main'
// this is the function which starts the program execution

// all C++ functions must have a 'return type'
// for the main function, we will make this be an int (more on ints 
// later in the tutorial)

// finally, what distinguishes a function is that it can take a list 
// of arguments to process, given in parentheses
// for our main function in this example, we dont need any arguments
// so we just give an empty set of parentheses  -> ()

// all of the above leads to the follwing line:

int main() 
{

  // this { opens up the set of instructions belonging to the main function
  // everything from here to the closing } will be part of 'main'

  cout << "Hello world!" <<endl;

  // that was our first C++ statement of code
  // note that it ends with a semi-colon
  // all valid c++ statements must end with a ;
  // otherwise funny things will happen...

  // the word 'cout' is used to indicate that we want to print something 
  // to the terminal screen

  // the << symbol directs the following items to cout, which then directs
  // them to the screen

  // "Hello world!" is the 'string' that we want to print
  // In C++ (and most programming languages), a 'string' is what we call the
  // collection of characters that make up literal words and phrases in
  // our physical language

  // the 'endl' indicates the 'end of the line' which we want to print


  return 0;

  // all functions should have a return statement, which indicates when 
  // the function terminates

  // a return statement can also have a return value
  // this can indicate how the function terminated
  // for example, you can have different return values to indicate
  // the different ways that a function can terminate

  // in the case above, the return value is '0'

  // the 'type' of the return value must match the one 
  // declared for the function
  // for us, that was the 'int' in the 'int main()' line at the 
  // start of the function

  // in practice, 0 is a common return value to indicate that the function
  // ended normally



}

// and here we close the main function with this }

// now see the file named README.how_to_compile_and_run
// for instructions on how to compile and run this program

