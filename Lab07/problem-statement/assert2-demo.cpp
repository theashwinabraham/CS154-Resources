#include <cassert>

#include <iostream>
using namespace std;

bool isprime (int x){
 
assert(....); // precodions on the input

 ..... // these two assertions will be written before you
   // start developing the code..
 // so that they act as defense against errors that you
// may make during development of the body

assert (....); //postcondition on the output result

}

int *sort (int * a, int n) {
//.... preconditions

 // body  ... which can use assertions for internal code structure

//... postconditions 

//return results... 
};

int main () {

  cout << "I'm here 1 \n";

  assert (1<0);

  cout << "I'm here 2 \n";
}

// assert statement checks for the given condition
// if the condition fails, the program terminates
// if the condition passes, the program continues