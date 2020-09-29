#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    scanf("%d", &N);
    int *arr = malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        *(arr+i)=i;
        printf("%d ", *(arr+i));
    }
    printf("\n");
    free(arr);
}