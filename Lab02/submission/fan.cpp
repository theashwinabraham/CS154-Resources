/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <iostream>

class Fan{
    private:
        int on_rpm; //rpm if fan were on, can be 0, 1, 2, 3, 4, 5
        bool status; //whether fan is on or off
    public:
        Fan(): status(false), on_rpm(0){} //initially Fan is off with speed on turning knob 0
        void switchOn(){
        //switches fan on
        //note if Fan speed is set to 0, turning it on will not make the fan rotate
            status = true;
            return;
        }
        void switchOff(){
            //switches fan off
            status = false;
            return;
        }
        void rotateCW(){
            //increases fan speed unless it is already max
            if(on_rpm==5) std::cout << "Fan is already at maximum speed\n";
            else ++on_rpm;
        }
        void rotateCCW(){
            //decreases fan speed unless it is already 0
            if(on_rpm==0) std::cout << "Fan is already at 0 speed\n";
            else --on_rpm;
        }
        bool isOn() const{
            //returns whether fan is on or off
            //note: fan can be on even when it is not moving
            return status;
        }
        int rpm() const{
            //returns actual speed of the fan in rpm
            if(status){
                return on_rpm;
            }
            return 0;
        }
};

int main(int argc, char* argv[]){
    //example demonstrating usage of the class
    Fan f;
    f.switchOn();
    std::cout << f.isOn() << ' ' << f.rpm() << '\n';
    f.rotateCCW();
    f.rotateCW();
    f.rotateCW();
    f.rotateCW();
    std::cout << f.rpm() << '\n';
    f.rotateCCW();
    std::cout << f.rpm() << '\n';
    f.rotateCW();
    f.rotateCW();
    f.rotateCW();
    f.rotateCW();
    f.switchOff();
    std::cout << f.isOn() << ' ' << f.rpm() << '\n';
    return 0;
}
