/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

class Dice{
    private:
        int number; //number at the top of the die (can be 1, 2, 3, 4, 5 or 6)
    public:
        Dice(){
            number = 1 + rand()%6; //randomly initializes number at the top
        }
        void toss(){
            number = 1 + rand()%6; //randomly assigns number at the top
        }
        int top() const{
            return number; //returns number at the top
        }
};

int main(int argc, char* argv[]){
    //example demonstrating usage of the class
    srand(time(NULL));
    Dice d;
    for(int i = 0; i<10; ++i){
        std::cout << d.top() << '\n';
        d.toss();
    }
    return 0;
}
