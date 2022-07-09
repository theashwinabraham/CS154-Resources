/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <stdio.h>

int main(int argc, char* argv[]){
    FILE* fp = fopen(argv[1], "r");
    int arr[128] = {};
    for(char c = fgetc(fp); c!=EOF; c = fgetc(fp)){
        if(c>32 && c<127) ++arr[c];
    }
    for(int i = 0; i<128; ++i){
        if(arr[i]>0) printf("%c : %d\n", char(i), arr[i]);
    }
    fclose(fp);
    return 0;
}