/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include "reusable.h"
#include <cmath>


int checksimilarity(const File& file1, const File& file2)
{
    int diff = 0, sum = 0;
    for(int i = 0; i<num_keywords; ++i)
    {
        diff += abs(file1[i] - file2[i]);
        sum += file1[i] + file2[i];
    }

    double keyword_diff = 1 - static_cast<double>(diff)/sum; //relative difference in the key words
    double length_diff = 1 - (static_cast<double>(abs(file1.length() - file2.length()))/(file1.length() + file2.length())); //relative length difference
    
    return keyword_diff*sqrt(length_diff)*100;
}