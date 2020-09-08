#include<stdio.h>

int main(){
    char s[256];
    while(1){
        printf("> ");
        fgets(s, 20, stdin);
        system(s);
    }
    return 0;
}