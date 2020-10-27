#include <stdio.h>
#include <unistd.h>

int main(){
    char str[5] = "Hello";
    setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
    for(int i =0; i< 5; i++){
        printf("%c", str[i]);
		sleep(1);
    }
}