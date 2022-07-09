/*
* AUTHOR: ASHWIN ABRAHAM
*/

//solution for Problem based on text given in Moodle
#include <iostream>

//ProductC, containing only feature1
class ProductC{
    public:
        void feature1() const{
            std::cout << "Feature 1 has been called\n";
            return;
        }
};

//ProductB containing feature3 and feature1 (inherited from ProductC)
class ProductB: public ProductC{
    public:
        void feature3() const{
            std::cout << "Feature 3 has been called\n";
            return;
        }
};

//ProductA containing feature2 and feature3 (inherited from ProductB) and feature1 (inherited from ProductC via ProductB)
class ProductA: public ProductB{
    public:
        void feature2() const{
            std::cout << "Feature 2 has been called\n";
            return;
        }
};

int main(){
    ProductC c;
    c.feature1();

    ProductB b;
    b.feature1();
    b.feature3();

    ProductA a;
    a.feature1();
    a.feature2();
    a.feature3();
    return 0;
}
