/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

class ATM{
    //each object of type ATM represents an account accessed by an ATM
    private:
        unsigned int PIN; //PIN must be a 4 digit number
        int balance;
    public:
        ATM(): balance(0){
            //initially PIN is a random number, and balance is 0
            srand(time(NULL));
            PIN = 1000 + rand()%9000;
        }
        void setPIN(int num){
            //sets PIN to num
            PIN = num;
            return;
        }
        int getPIN() const{
            //returns PIN
            return PIN;
        }
        bool enterPIN() const{
            //Asks user to enter PIN,
            //returns true if entered PIN matches actual PIN, else returns false
            std::cout << "Enter your PIN: ";
            int x;
            std::cin >> x;
            if(x==PIN) std::cout << "You have entered your PIN correctly\n";
            else std::cout << "You have entered your PIN incorrectly\n";
            return x==PIN;
        }
        bool checkBalance(int& num) const{
            //sets num to balance and returns true if PIN has been entered correctly
            //else returns false
            if(enterPIN()){
                num = balance;
                return true;
            }
            return false;
        }
        bool deposit(int amount){
            //returns true for successful deposit, else returns false
            if(enterPIN()){
                balance+=amount;
                std::cout << "Deposit Successful\n";
                return true;
            }
            std::cout << "Deposit unsuccessful\n";
            return false;
        }
        bool withdraw(int amount){
            //returns true for successful withdrawal, else returns false
            if(enterPIN()){
                if(balance>=amount){
                    balance-=amount;
                    std::cout << "Withdrawal Successful\n";
                    return true;
                }
            }
            std::cout << "Withdrawal unsuccessful\n";
            return false;
        }
        bool transfer(ATM& other, int amount){
            //returns true for successful transfer, else returns false
            if(enterPIN()){
                if(balance>=amount){
                    balance-=amount;
                    other.balance+=amount;
                    std::cout << "Transfer Successful\n";
                    return true;
                }
            }
            std::cout << "Transfer unsuccessful\n";
            return false;
        }
};

int main(int argc, char* argv[]){
    //example demonstrating usage of the class
    ATM atm;
    std::cout << "PIN: " << atm.getPIN() << '\n';
    atm.enterPIN();
    int num;
    if(atm.checkBalance(num)){std::cout << "Balance: " << num << '\n';}
    atm.deposit(1000);
    if(atm.checkBalance(num)){std::cout << "Balance: " << num << '\n';}
    atm.withdraw(500);
    if(atm.checkBalance(num)){std::cout << "Balance: " << num << '\n';}
    ATM atm2;
    atm.transfer(atm2, 250);
    if(atm.checkBalance(num)){std::cout << "Balance in ATM1: " << num << '\n';}
    atm2.setPIN(1234);
    std::cout << "ATM2 PIN (enter this PIN now): " << atm2.getPIN() << '\n';
    if(atm2.checkBalance(num)){std::cout << "Balance in ATM2: " << num << '\n';}
    return 0;
}
