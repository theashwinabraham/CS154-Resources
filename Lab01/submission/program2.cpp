/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <iostream>
#include <fstream>

class possiblechars{
    private:
        int arr[128];
    public:
        possiblechars(){
            for(int i = 0; i<128; ++i) arr[i] = 0;
        }
        void addchar(char c){
            if(c>32 && c<127) ++arr[c];
            return;
        }
        void print(){
            for(int i = 0; i<128; ++i){
                if(arr[i]>0) std::cout << char(i) << " : " << arr[i] << '\n';
            }
            return;
        }
};

int main(int argc, char* argv[]){
    std::ifstream infile;
    infile.open(argv[1]);
    char c;
    possiblechars pc;
    while(infile.get(c)){
        pc.addchar(c);
    }
    pc.print();
    infile.close();
    return 0;
}