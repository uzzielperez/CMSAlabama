// Assuming you have been able to compile, run and understand the Hello World program
// we will now introduce some of the basic features of the C++ language


//***************************************************
// Conor Henderson, Univ of Alabama, August 2011
//***************************************************

#include <iostream>
using namespace std;


// again we need a 'main' program

int main() 
{

  // the basic data types for numbers in C++ are integers, and doubles (or floats)
  int A = 2;
  // this statement creates a variable A of type integer, and assigns it the value of 2

  // for non-integer numbers, we use the type 'double'
  double B = 3.1415927;
  // you could also use a float, but a double is better and the standard these days
  // (the difference is related to how much internal memory the computer uses to store the number - doubles use twice as much as floats, which is why they're better

  // there are also variables which can be true or false
  // we represent these by 'booleans'
  // true=1 and false=0
  bool C = true;

  // here is a single character  
  char D = 'D'; 

  // we will see how to represent 'strings' of characters later...


  //   let's check these assignments by printing the values of the variables to the screen for display

  cout << "A = " << A <<endl;
  cout << "B = " << B <<endl;
  cout << "C = " << C <<endl;
  cout << "D = " << D <<endl;
  
  
  // now for some operations
  // let's say we want to add 4 to the value of variable A
  // and store it in a new variable
  // then we would do

  int E = A+4;

  //lets check that worked:
  cout << "E = " << E <<endl;


  // we can do other operations as well
  // this time we'll just print them, but not bother to save them
  // to new variables ...

  cout << "A minus 10 = " << A-10 <<endl;
  cout << "A multipled by 10 = " << A*10 <<endl;
  cout << "A divided by 2 = " << A/2 <<endl;

  // note that none of these operations changed the value of A itself
  // if we wanted to do that, we could do:
  A = A+2;
  // now let's see what value A has:

  cout << "Now A = " <<A <<endl;

  // we often find that we want to increase the value of an integer
  // by one unit, eg if we are using it as a counter
  // we could do this by: A=A+1
  // but since we use this often, C++ provides a shortcut:
  A++;
  // this literally means A=A+1, but its shorter
  // let's check the value:
  cout << "After A++, A = " << A <<endl;

  // there is an equivalent if we want to decrease by one: A--;




  // see how we were able to change the value of A?
  // well, now look at variable B above
  // its value is (pretty close to) pi
  // but we could change that value easily, eg by B = B+1
  // but if we were trying to really use it to represent pi
  // then we would not want to be able to change the value at all, in case we sometimes did it by accident ...
  // so instead, we can create a variable with a CONSTANT value
  // we can do this by:

  const double pi = 3.1415927;


  // now we can use this in normal expressions, such as 

  cout << "Pi + 1 =" << pi+1 <<endl;

  // but if we were to try to change the value, the compiler would generate an error
  // you can see that yourself by editing this program and uncommenting the line below
  //  pi = pi+1;

  // you should see the compiler give you an error like:
  //  error: assignment of read-only variable `pi'
  // and the program will fail to compile

  // failing to compile is how the computer tries to help you make sure you dont accidentally run broken programs that might do bad things.
  // if you see errors when you go to compile the program, then you need to fix them
  // an output program will not be generated if the compiler finds errors in the source code
  
  // to correct the above error, just comment out the line again, and recompile


  
  //now that we've seen the basic data types and arithmetical operations, 
  // let's look at the basic control functions: if/else, for, etc...

  // often in a program, we will want to do one thing under some conditions
  // and a different thing under other conditions
  // we can accomplish this by if/else statements

  // an if statement basically works like:
  // if (some condition) { do a bunch of stuff }

  // here's an example
  
  if(A==5) {
    
    cout <<" We have just checked if A equals 5" <<endl;
    cout << "And if it is, we will double it" <<endl;
    A = A*2;
    
  } 

  // note that the condition we check for is inside ()
  // if this is true, we execute all the code that is contained inside the curly brackets {}
  // if the condition is not true, we do not execute that code, and we move on through the program
  
  // also note that we use '=='  to check if A equals 5
  // == is different from just =
  // a single = means an *assignment operation*
  // if we wrote if(A=5) then we would actually *assign* the value 5 to A
  // thats not what we want
  // so to check what the value of A is, we need to use ==
  // (it's a common beginner mistake to write = when you mean == ...)

  // if we want to check for more than one condition at a time, we can use if/else if / else statements
  
  if(A==9) {

    cout << "We have checked that A ==9" <<endl;
    cout << "Now we add 3 to it" <<endl;
    A = A+3;
    
  } 
  else if(A==10) {
    cout << "We have checked that A ==10" <<endl;
    cout << "Now we add 7 to it" <<endl;
    A = A+7;
    
  }
  else {
    // if none of the above are true, then we default to else 
    // i.e. in every other case....
    cout << "We have checked that A is not 9 or 10 ..." <<endl;
    cout << "This time we won't change it" <<endl;
  }


  // depending on what condition was chosen, we can see what the value of A is now

  cout << "After that choice, the value of A is now: A = " << A << endl;
  

  // the other common control structures are loops
  // there are both for-loops and while-loops in C++

  for(int i=0;i<10;i++) {
    // this is a very common loop example
    // we create a counter i
    // each time through the loop, we increment i by one (i++)
    // we continue this loop as long as it is true that i<10
    // i.e. we do the loop ten times, then stop and move on

    //each time through the loop, let's add one to our variable A
    A++;

  }

  // now we can see what the value of A is after this loop:
  cout <<  "After the for loop, A = " << A <<endl;


  //there is also a while loop
  // and sometimes you can use statements like break or continue
  // to modify control flow in programs
  // you can look all these up at
  //  http://www.cplusplus.com/doc/tutorial/control/

  // note that technically C++ has a goto function like in classic BASIC programs
  // but these days, we basically never use goto in real programs...
  



  // and we're done for this exercise, so we return:
  return 0;

}
