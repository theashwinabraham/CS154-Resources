/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <stdio.h>
#include <stdlib.h>

int to_int(char* c){
    int num = 0;
    for(int i = 0; c[i]!='\0'; ++i) num = 10*num + (c[i]-'0');
    return num;
}

int main(int argc, char* argv[]){
    int num[6] = {};
    for(int i = 0; i<to_int(argv[1]); ++i) ++num[rand()%6];
    for(int i = 0; i<6; ++i) printf("%d: %f\n", 1+i, num[i]*1.0/to_int(argv[1]));
    return 0;
}