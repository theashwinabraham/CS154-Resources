/*
* AUTHOR: ASHWIN ABRAHAM
* STRING TO INT: INCORRECT VERSION
*/
#include <iostream>
#include <string>
#include <cassert>

#ifndef INT32_MAX
#define INT32_MAX 2147483647
#endif

int str2int(const std::string& s)
{
    assert(s.length() > 0); //prevents "" from being passed
    int num = 0, sign = 1;
    if(s[0] == '-'){
        assert(s.length() > 1); //prevents "-" from being passed
        sign = -1;
    }
    for(unsigned int i = 0; i<s.length(); ++i)
    {
        if(i == 0 && s[i] == '-') continue; //allows for first element of string to be '-'
        assert('0' <= s[i] && s[i] <= '9'); //forces string to containg only numbers
        assert(num <= (INT32_MAX - (s[i]-'0'))/10); //prevents overflow
        num*=10;
        num+=(s[i]-'0');
    }
    num = -num; //incorrect logic
    assert(num >= 0); //postcondition (another check on overflow)
	return sign*num;
}

int main()
{
    std::cout << str2int("7b6c7") << '\n';
    std::cout << str2int("10000000000") << '\n';
    std::cout << str2int("-") << '\n';
    return 0;
}