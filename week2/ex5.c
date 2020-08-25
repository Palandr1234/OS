#include <stdio.h>

void mode1(int n){
    for(int i = 0; i< n;i++){
        for(int j = 0; j < n - i - 1; j++){
            printf(" ");
        }
        for(int j = n - i -1; j <= n + i - 1; j++){
            printf("*");
        }
        printf("\n");
    }
}

void mode2(int n){
    for(int i = 0; i< n;i++){
        for(int j = 0; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
}

void mode3(int n){
    for(int i = 0; i< n;i++){
        for(int j = 0; j < n; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    int mode = atoi(argv[2]);
    switch(mode){
        case 1:
            mode1(n);
            break;
        case 2:
            mode2(n);
            break;
        case 3:
            mode3(n);
            break;
    }
    return 0;
}