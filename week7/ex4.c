#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

void *myRealloc(void *ptr, size_t size){
    if(ptr == NULL){
        return malloc(size);
    }
    if(size == 0){
        free(ptr);
        return NULL;
    }
    void *new_arr = malloc(MIN(size, malloc_usable_size(ptr)));
    memcpy(new_arr, ptr, MIN(size, malloc_usable_size(ptr))); 
    free(ptr);
    return new_arr;

}

int main(){
    int* a= malloc(10*sizeof(int));
    printf("Old values of a: ");
    for(int i = 0; i< 10; i++){
        *(a+i)=i;
        printf("%d ", *(a+i));
    }
    printf("\n");
    a = myRealloc(a, 5*sizeof(int));
    printf("New values of a: ");
    for(int i =0; i< 5; i++){
        printf("%d ", *(a+i));
    }
    printf("\n");
    int* b = malloc(5*sizeof(int));
    printf("Old values of b: ");
    for(int i = 0; i< 5; i++){
        *(b+i)=i;
        printf("%d ", *(b+i));
    }
    printf("\n");
    b = myRealloc(b, 10*sizeof(int));
    printf("New values of b: ");
    for(int i =0; i< 10; i++){
        printf("%d ", *(b+i));
    }
    printf("\n");
    int* c = NULL;
    c = myRealloc(c, 10*sizeof(int));
    printf("New values of c: ");
    for(int i =0; i< 10; i++){
        printf("%d ", *(c+i));
    }
    printf("\n");
    int* d = malloc(10*sizeof(int));
    printf("Old values of d: ");
    for(int i = 0; i< 10; i++){
        *(d+i)=i;
        printf("%d ", *(d+i));
    }
    printf("\n");
    d = myRealloc(d, 0);
}