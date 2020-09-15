#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define N 5
pthread_t thread_id[N];

void* PrintHello(int i) {
    printf("Hello from thread %d\n", i);    
    pthread_exit(&i);
}

int main() {
    for (int i = 0; i < N; i++) {
        pthread_create(&thread_id[i], NULL, PrintHello, i); 
        /*without pthread_join it first prints "write in main" becuase of high priority of main, and then prints threads in almost
         random order. With pthread_join we allows for thread to finish its work, so the correct order is preserved*/
        pthread_join(thread_id[i], NULL);
        printf("Write in C\n");
    }
    pthread_exit(NULL);
}