// example of creating a vector and sorting it
// using the sort algorithm provided by C++ standard library

//***************************************************
// Conor Henderson, Univ of Alabama, February 2013
//***************************************************


#include <iostream>
#include <vector>

// the C++ standard library provides many useful algorithms:
#include <algorithm>
// note, by the way, that when you #include a standard C++ header,
// the name is enclosed in <>
// but when you include one of your own classes, it should be in ""
// the compiler uses the difference to know where to search for the header file

using namespace std;


// to use sort algorithm, you need a function which compares the two elements
// this function should return true if the first argument to the function
// is considered to *go before* the second argument
// this defines the ordering that you are using to sort the list

// for numbers this is straightforward
// but you can also define a comparison function for any class you want
// you just have to tell the function how it should compare its arguments

bool compare(double a, double b) {
  if(a<b)
    return true;
  else
    return false;
}


// now here's the main function of the program

int main() 
{

  vector<double> my_vector;

  // now let us add elements to this vector, 
  // in some random order of size
  my_vector.push_back(1.0);
  my_vector.push_back(4.0);
  my_vector.push_back(7.7);
  my_vector.push_back(2.1);
  my_vector.push_back(12.3);
  my_vector.push_back(0.001);

  cout << "Size of vector = " << my_vector.size() <<endl;

  // display the contents of the original vector
  cout << "Original vector contains:" <<endl;
  for(vector<double>::iterator iter= my_vector.begin(); iter!=my_vector.end(); ++iter) {

    cout << *iter <<endl;
    // here, after dereferencing the iterator, you are left with the vector element
    // which is a double
    // so you can send it directly to cout, which knows how to print a double
    // because it is a built-in type

  }


  // now to sort this vector
  // the sort function is defined in the algorithm header
  // you need to pass it the start and end of the list you want to sort

  // we will use the compare function defined earlier
  // but actually note that if you do not pass any function
  // then sort by default uses the 'less than' operator
  // which, actually, is all our function does too ...
  sort(my_vector.begin(),my_vector.end(),compare);
  
  // now display the sorted vector:
  cout <<endl; 
  cout << "Sorted vector is:" <<endl;
  for(vector<double>::iterator iter= my_vector.begin(); iter!=my_vector.end(); ++iter) {
    
    cout << *iter <<endl;

  }


  return 0;
}




