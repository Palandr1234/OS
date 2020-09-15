#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>

#define N 8
char buffer[N];
int counter = 0;

int producer_sleep;
int consumer_sleep;
int t = 0;

void* producer(void* value){
    while(1){
        if(producer_sleep){
            continue;
        }
        if(counter == N){
            producer_sleep = 1;
            consumer_sleep = 0;
            printf("Finsih producing on %d\n", t++);
            continue;
        }
        buffer[counter] = 0 + counter;
        counter++;
    }
    pthread_exit(NULL);
    return NULL;
}

void* consumer(void* value){
    while(1){
        if(consumer_sleep){
            continue;
        }
        if(counter == 0){
            consumer_sleep = 1;
            producer_sleep = 0;
            continue;
        }
        int value = buffer[counter];
        printf("Value: %d\n", value);
        counter--;
    }
    pthread_exit(NULL);
    return NULL;
}

int main(){
    consumer_sleep = 1;
    producer_sleep = 0;
    pthread_t producer_t;
    pthread_t consumer_t;
    pthread_create(&producer_t, NULL, producer, 0);
    pthread_create(&consumer_t, NULL, consumer, 0);
    while(1);
    return 0;
}
//it stopped at t = 213356