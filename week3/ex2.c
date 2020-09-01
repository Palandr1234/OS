#include <stdio.h>

void bubble_sort(int input[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i; j++){
            if(input[j] > input[j + 1]){
                int temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }
}

int main(){
    int a[10] = {98, 58, 82, 59, 100, 69, 52, 58, 75, 56};
    int size = sizeof(a)/sizeof(*a);
    bubble_sort(a, size);
    for(int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
}