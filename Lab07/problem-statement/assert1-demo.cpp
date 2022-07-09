#include <cassert>

#include <iostream>
using namespace std;


int main () {

  cout << "I'm here 1 \n";

  assert (1<0);

  cout << "I'm here 2 \n";
}

// assert statement checks for the given condition
// if the condition fails, the program terminates
// if the condition passes, the program continues