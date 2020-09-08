#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){
    int n = 10;
    int process = fork();
    if (process > 0){
        printf("Hello from parent [%d - %d]\n", getpid(), n);
    }
    else if(process == 0){
        printf("Hello from child [%d - %d]\n", getpid(), n);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
    //Since allocation of concurrent execution of child processes is unknown, sometimes the oder may be broken
}