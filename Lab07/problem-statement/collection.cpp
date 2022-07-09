#include <iostream>
using namespace std;
#include <cassert>
// A program which is not correct
class Collection {
int *S;
int cap, card;
// any additional variables

  public:
	Collection(int sz) {
		S = new int [sz];
		card=0;
  //... add assertion(s)...
	}

	void push_back(int elem) {
  //... add assertion(s)...


  //... add logic

  //... add assertion(s)...

	}

	int pop_back() {
  //... add assertion(s)...

  //... add logic

  //... add assertion(s)...


	}
};
int main () {

   // add testing code that tests the class above and fails it, the failures get caught by assertions

   // make another version with correct implement and that passes all assertions
}
