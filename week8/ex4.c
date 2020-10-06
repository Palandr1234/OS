#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
#include<sys/time.h>

int main(){
    struct rusage usage;
    for(int i = 0; i< 10; i++){
        int *ptr = malloc(10485760);
        memset(ptr, 0, 10485760);
        getrusage(RUSAGE_SELF, &usage);
        printf("%d\n", usage.ru_maxrss);
        sleep(1);
    }
}