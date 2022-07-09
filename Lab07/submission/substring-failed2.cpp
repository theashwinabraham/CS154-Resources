/*
* AUTHOR: ASHWIN ABRAHAM
* SUBSTRING: INCORRECT VERSION
*/
#include <iostream>
#include <string>
#include <cassert>

int find(const std::string& str, const std::string& sub)
{
    //precondition assertions
    assert(str.length() >= sub.length()); //ensures substring length is always less than or equal to string length
    assert(str.length() > 0); //ensuring that str is not empty 
    //note that since null set is a subset of every set, if sub is empty, then it is present in str at 0th position
    for(int i = 0; i<str.length(); ++i)
    {
        int j = 0;
        for(; j<sub.length() && i+j < str.length(); ++j)
        {
            if(str[i+j] != sub[j]) break;
            assert(i>=0);
            assert(i<str.length());
            assert(j>=0);
            assert(j<sub.length());
        }
        if(j == sub.length()){
            i-=20; //buggy logic
            assert(i>=0); //postconditions
            assert(i<str.length()); //postconditions
            return i;
        }
    }
    assert(false); //ensures substring is actually present in the string (postcondition)
}

int main()
{
    std::cout << find("Hello", "hello") << '\n';
    std::cout << find("hello", "elo") << '\n';
    std::cout << find("World", "Woor") << '\n';
    std::cout << find("Hello World", "lloWor") << '\n';
    return 0;
}