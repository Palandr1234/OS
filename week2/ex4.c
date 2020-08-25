#include <stdio.h>

void swap(int *a, int *b){
    *a = *b - *a;
    *b = *b - *a;
    *a = *b + *a;


}

int main(){
    int i, j;
    scanf("%d %d", &i, &j);
    swap(&i, &j);
    printf("%d %d", i, j);
}