#include <iostream>
using namespace std;
#include "similarity.h"  // contains declaration


int main (int argc, char *argv[]) {

  int score;

     score = checksimilarity(argv[1], argv[2]);

     cout << score << endl;

}
