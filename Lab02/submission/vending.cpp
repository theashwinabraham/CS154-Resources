/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <iostream>
#include <vector>
#include <string>

class Drink{
    //class describing name, stock, and number of drinks in the vending machine
    private:
        std::string drink_name;
        int drink_num;
        int drink_price;
    public:
        Drink(std::string name = "", int num = 0, int price = 0): drink_name(name), drink_num(num), drink_price(price){}
        std::string name(){
            return drink_name;
        }
        int& stock(){
            return drink_num;
        }
        int price(){
            return drink_price;
        }
};

class DrinksVendingMachine{
    private:
        std::vector<Drink> drinks; //dynamic array of drinks in the vending machine
        int money; //Total number of coins entered into the machine
    public:
        DrinksVendingMachine(): drinks(0), money(0){} //initially machine has no drinks in it and no coins have been entered in it
        void addDrink(const std::string& drink_name, int drink_price){
            //adds Drink to the machine
            //if the Drink is already there but the price is given incorrectly, then it doesn't allow new drink to be added
            //but instead gives an error message
            for(int i = 0; i<drinks.size(); ++i){
                if(drinks[i].name() == drink_name){
                    if(drinks[i].price() == drink_price){
                        ++drinks[i].stock();
                        return;
                    }
                    else{
                        std::cout << "You have entered the incorrect price for this drink\n";
                        return;
                    }
                }
            }
            drinks.push_back(Drink(drink_name, 1, drink_price));
            return;
        }
        void getDrink(const std::string& drink){
            //models purchase of a drink from the machine
            //if the drink exists in the machine and the customer enters the correct number of coins it increases the money of the machine
            //and decreases the number of that type of drink
            //otherwise it just gives an error message
            for(int i = 0; i<drinks.size(); ++i){
                if(drinks[i].name()==drink){
                    std::cout << "Enter " << drinks[i].price() << " coins (in the terminal type the number of coins you are entering): ";
                    int x;
                    std::cin >> x;
                    if(x!=drinks[i].price()){
                        std::cout << "You have not entered the correct amount\n";
                        return;
                    }
                    std::cout << "You have successfully purchased " << drinks[i].name() << '\n';
                    money+=x;
                    --drinks[i].stock();
                    if(drinks[i].stock()==0){
                        drinks.erase(drinks.begin()+i);
                    }
                    return;
                }
            }
            std::cout << "Sorry, " << drink << " is not available at the moment\n";
            return;
        }
        void print(){
            //prints the drinks available along with their quantities and prices
            for(int i = 0; i<drinks.size(); ++i) std::cout << "Name: " << drinks[i].name() << ", Stock: " << drinks[i].stock() << ", Price: " << drinks[i].price() << '\n';
            return;
        }
};

int main(int argc, char* argv[]){
    //example demonstrating usage of the class
    DrinksVendingMachine dvm;
    dvm.addDrink("coke", 200);
    dvm.addDrink("coke", 200);
    dvm.addDrink("pepsi", 300);
    dvm.addDrink("sprite", 100);
    dvm.getDrink("soda");
    dvm.getDrink("pepsi");
    dvm.print();
    return 0;
}
