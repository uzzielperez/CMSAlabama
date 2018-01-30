// simple example program to illustrate the use of C++ vector class

//***************************************************
// Conor Henderson, Univ of Alabama, February 2013
//***************************************************

// to make use of vector, we just need to include its header
#include <vector>

#include <iostream>

using namespace std;
// now we will explain this line. 
// all these standard C++ classes live in the namespace 'std'
// this is to distinguish the standard vector class from a class
// that you may write yourself and call it 'vector'
// (After all, if you didnt know that 'vector' already existed, 
// it would seem pretty weird if you couldnt make your own class called 'vector')
// using namespaces is how C++ prevents this kind of conflict
// officially then we should write 'std::vector' and 'std::cout' etc
// to make it clear the namespace is 'std'
// but to save typing, we can declare the 'default' namespace to be 'std'
// so that if its not specified, the compiler will assume we are using the std namespace
// that's the purpose of the 'using namespace std' line



// rememeber, all executable programs must have a main() function
// this is where program execution starts
int main() 
{
  // let's say a group of numbers is related in some way
  // in C, we might put them in an array
  // in C++, we can use the much better vector instead

  // we need to declare what our vector will be a vector of:
  vector<double> my_vector;
  // here every element of the vector will be a double
  
  // now we can add elements to this vector
  my_vector.push_back(1.0);
  my_vector.push_back(2.0);
  my_vector.push_back(3.0);
  // note that we didnt have to declare the size of the vector ahead of time
  // every time we call push_back(), it increases the size by 1 
  // and adds the new element to the end
  // much better than an array, where  the size must be declared at the start
  
  // if we want to know the current size of our vector, we can do:
  cout << "Size of vector = " << my_vector.size() <<endl;

  // normally the whole point of collecting these related numbers is that
  // you will want to process them together
  // vector class provides an 'iterator' to loop over all its elements
  // this syntax for this is a little more complicated though
  // but it is the recommended way to do it

  cout << "This vector contains:" <<endl;
  for(vector<double>::iterator iter= my_vector.begin(); iter!=my_vector.end(); ++iter) {

    cout << *iter <<endl;
    // here you are dereferencing the iterator (*iter instead of iter)
    // if youre new to C++ and pointers, you probably dont know what this is
    // or why you are doing it
    // sorry
    // you'll have to learn why later, once you know more
    // for now, just make sure you include the *, or it wont work
  }




  // note that we can still use array indexing to return elements of the vector if we so wish:
  //  cout << "First element is: "<< my_vector[0] << endl;
  // but better to use the new vector functions instead, when applicable.




  return 0;
}
