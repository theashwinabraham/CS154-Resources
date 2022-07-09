/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <iostream>

class Lift{
    private:
        bool current_floor; //only 2 floors (0(false)-> ground floor, 1(true)-> first floor)
    public:
        Lift(): current_floor(0){} //initializes lift on ground floor
        bool Current_floor() const{ //returns current floor
            return current_floor;
        }
        void go_to_other_floor(){ //moves lift to floor which it is not on
            current_floor = !current_floor;
            return;
        }
        void go_to_floor(bool floor){ //moves lift to a desired floor
            current_floor = floor;
            return;
        }
};

int main(int argc, char* argv[]){
    //example demonstrating usage of the class
    Lift l;
    std::cout << "Current Floor: " << l.Current_floor() << '\n';
    l.go_to_other_floor();
    std::cout << "Current Floor: " << l.Current_floor() << '\n';
    l.go_to_floor(0);
    std::cout << "Current Floor: " << l.Current_floor() << '\n';
    l.go_to_other_floor();
    std::cout << "Current Floor: " << l.Current_floor() << '\n';
    l.go_to_floor(1);
    std::cout << "Current Floor: " << l.Current_floor() << '\n';
    return 0;
}
