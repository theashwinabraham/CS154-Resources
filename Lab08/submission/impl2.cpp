/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include "reusable.h"
#include <cmath>

int checksimilarity(const File& file1, const File& file2)
{
    int sum_symb = 0, diff_symb = 0;
    for(int i = 0; i<num_symbols; ++i)
    {
        diff_symb+=abs(file1.symbol_occurrence(i) - file2.symbol_occurrence(i));
        sum_symb+=(file1.symbol_occurrence(i) + file2.symbol_occurrence(i));
    }
    if(sum_symb == 0) return 100;


    int sum_bracket = 0, diff_bracket = 0;
    char brackets[3] = {'(', '[', '{'};
    for(int i = 0; i<3; ++i)
    {
        diff_bracket+=abs(file1.bracket_occurrence(brackets[i]) - file2.bracket_occurrence(brackets[i]));
        sum_bracket+=(file1.bracket_occurrence(brackets[i]) + file2.bracket_occurrence(brackets[i]));
    }
    assert(sum_bracket > 0);


    double symbol_diff = 1 - (static_cast<double>(diff_symb)/sum_symb); //relative difference in the symbols
    double bracket_diff = 1 - (static_cast<double>(diff_bracket)/sum_bracket); //relative difference in the brackets
    double length_diff = 1 - (static_cast<double>(abs(file1.length() - file2.length()))/(file1.length() + file2.length())); //relative difference in the lengths

    
    return 100*symbol_diff*bracket_diff*sqrt(length_diff);
}