#include<stdio.h>
#include<unistd.h>

int main(){
    for(int i = 0; i< 10; i++){
        int *ptr = malloc(10485760);
        memset(ptr, 0, 10485760);
        sleep(1);
    }
}
/* In the first output, I have si = 0 and 
so = 14. It means that 14 bytes were allocated 
for swapping. In the all further outputs of 
vmstat 1, I have si = 0 and so = 0 since 
the amount of memory is enough and there is no 
need to swapp any process.*/

/* For exercise 3, for ex2 process %CPU equal to 
0.3% and sometimes increases to 0.7% since it 
allocates memory and fills it with 0s. The %Mem
always increases (1.4%, 2.4% and 3.4%) since we 
don't free the memory and allocates it for ex2 
process.*/