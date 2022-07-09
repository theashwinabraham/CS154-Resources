/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <iostream>
#include <cstdlib>

class occurrences{
    private:
        int occ[6];
    public:
        occurrences(){
            for(int i = 0; i<6; ++i) occ[i] = 0;
        }
        void add_occurrence(int i){
            ++occ[i-1];
            return;
        }
        void print_prob(int total){
            for(int i = 0; i<6; ++i) std::cout << 1+i << ": " << occ[i]*1.0/total << '\n';
            return;
        }
};

int to_int(char* c){
    int num = 0;
    for(int i = 0; c[i]!='\0'; ++i) num = 10*num + (c[i]-'0');
    return num;
}

int main(int argc, char* argv[]){
    occurrences Occ;
    for(int i = 0; i<to_int(argv[1]); ++i) Occ.add_occurrence(1 + rand()%6);
    Occ.print_prob(to_int(argv[1]));
    return 0;
}