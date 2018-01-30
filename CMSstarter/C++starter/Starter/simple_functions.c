// Here we will illustrate how to make use of functions in C++

//***************************************************
// Conor Henderson, Univ of Alabama, August 2011
//***************************************************


#include <iostream>
using namespace std;


// suppose there is some complicated operation that we might like to do
// fairly often 
// in this case, its a good way to make this operation into a 'function' 
// like this:

double simple_function(double inputVariable)
{

  // this function is named simple_function()

  // like all functions, it has a return value
  // in this case, the return value is of type double

  // a function can also take a list of arguments, inside the ()
  // in this case, the argument is the variable inputVariable
  // and it is of type double
  // these arguments are things that the function can process

  // for this simple function example, we will just double the value of the input argument

  // so we create a new variable 'result'
  // and assign it the value we want, based on the input:

  double result = inputVariable*2.0;

  // and then we 'return' this result
  // the return value is the *output* of this function

  return result;


}

// lets write another function
// functions can take more than one input
// so we will write a function that adds two numbers together

double add_two_numbers(double A, double B) 
{
  double result = A+B;
  return result;

}

// now we will use the functions above inside our 'main' program

int main() 
{

  double A = 3.0;

  double B = 10.0;

  // we use the functions above by 'calling them'
  // then we specify what inputs to the function are:

  double first_result = simple_function(A);

  cout << "First result = "<< first_result <<endl;

  // now we will do the same function operation on a different input

  double second_result = simple_function(B);

  cout << "Second result = " << second_result<<endl;

  // and now we use the 'add' function:

  double third_result = add_two_numbers(first_result,second_result);

  cout << "Third result = " <<third_result<<endl;



  return 0;
}
