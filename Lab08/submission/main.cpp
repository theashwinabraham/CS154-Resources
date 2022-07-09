/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include "reusable.h"
#include <iostream>


int main(int argc, char** argv)
{
    try
    {
        File f1(argv[1]), f2(argv[2]);
        std::cout << checksimilarity(f1, f2) << '\n';
    }
    catch(...)
    {
        std::cout << "The file names/paths must be given as command line arguments\n";
        std::cout << "If there is still an error ensure that the files given exist\n";
        std::cout << "And ensure that the files are C++ files\n";
        std::cout << "(Some assert statements may throw errors if you submit non C++ files)\n";
    }
    return 0;
}