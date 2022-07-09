/*
* AUTHOR: ASHWIN ABRAHAM
* COLLECTION: INCORRECT VERSION
*/
#include <iostream>
#include <cassert>

class Collection{
    private:
        int* arr;
        const unsigned int capacity;
        int num;

    public:
        Collection(int size): capacity(size)
        {
            assert(size >= 0); //prevents stack size from being negative
            arr = new int [size];
            num = 0;
        }

        void push_back(const int& el)
        {
            assert(num<capacity); //prevents filling more elements than stack can handle
            arr[num] = el;
            --num; //incorrect logic
            assert(num >=0 && num<=capacity); //postcondition
        }

        int pop_back()
        {
            assert(num>0); //prevents removing from empty stack
            ++num; //incorrect logic
            assert(num >=0 && num<=capacity); //postcondition
            return arr[num];
        }

        int peek()
        {
            assert(num>0); //prevents peeking an empty stack
            assert(num >=0 && num<=capacity); //postcondition
            return arr[num-1];
        }

        ~Collection()
        {
            delete [] arr;
        }
};


int main()
{
    Collection a(-2);
    Collection c(4);
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    c.push_back(4);
    std::cout << c.peek() << ' ' << c.pop_back() << '\n';
    std::cout << c.peek() << ' ' << c.pop_back() << '\n';
    std::cout << c.peek() << ' ' << c.pop_back() << '\n';
    std::cout << c.peek() << ' ' << c.pop_back() << '\n';
    std::cout << c.pop_back() << '\n';
    return 0;
}