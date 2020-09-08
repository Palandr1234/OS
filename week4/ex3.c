#include<stdio.h>

int main(){
    char s[256];
    while(1){
        printf("> ");
        scanf("%s", s);
        system(s);
    }
    return 0;
}