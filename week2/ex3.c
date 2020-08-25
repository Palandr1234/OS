#include <stdio.h>

int triangle(int n){
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

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    triangle(n);
    return 0;
}