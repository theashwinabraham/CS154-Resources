/*
* AUTHOR: ASHWIN ABRAHAM
* COLLECTION: CORRECT VERSION
*/
#include <iostream>
#include <cassert>

class Collection{
    private:
        int* arr;
        const unsigned int capacity;
        unsigned int num;

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
            ++num;
            assert(num >=0 && num<=capacity); //postcondition
        }

        int pop_back()
        {
            assert(num>0); //prevents removing from empty stack
            --num;
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
    Collection c1(4);
    c1.push_back(1);
    c1.push_back(2);
    c1.push_back(3);
    c1.push_back(4);
    std::cout << c1.peek() << ' ' << c1.pop_back() << '\n';
    std::cout << c1.peek() << ' ' << c1.pop_back() << '\n';
    std::cout << c1.peek() << ' ' << c1.pop_back() << '\n';
    std::cout << c1.peek() << ' ' << c1.pop_back() << '\n';
    int cap;
    std::cout << "Enter the stack capacity: ";
    std::cin >> cap;
    Collection c2(cap);
    for(int i = 0; i<cap; ++i)
    {
        int x;
        std::cout << "Enter a number: ";
        std::cin >> x;
        c2.push_back(x);
    }
    for(int i = 0; i<cap; ++i)
    {
        std::cout << c2.pop_back() << '\n';
    }
    return 0;
}