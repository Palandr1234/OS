#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    for(int i = 0; i < 5; i++){
        fork();
    }
    sleep(5);
    return 0;
}

/*for fork 3 pstree is:
ex2-+-ex2-+-ex2---ex2
    |     `-ex2
    |-ex2---ex2
    `-ex2
The explanation of the results is that in every fork() call
the process creates a copy of itself and the new 
process is a child of old one. Therefore, the total 
number of processes is 2^3=8.
for 5 fork() calls results will be the following:
ex2-+-ex2-+-ex2-+-ex2-+-ex2---ex2
    |     |     |     `-ex2
    |     |     |-ex2---ex2
    |     |     `-ex2
    |     |-ex2-+-ex2---ex2
    |     |     `-ex2
    |     |-ex2---ex2
    |     `-ex2
    |-ex2-+-ex2-+-ex2---ex2
    |     |     `-ex2
    |     |-ex2---ex2
    |     `-ex2
    |-ex2-+-ex2---ex2
    |     `-ex2
    |-ex2---ex2
    `-ex2
We can notice that now we have 2^5 = 32 processes in 
total.
*/