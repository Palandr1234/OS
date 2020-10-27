#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

#define STR_SIZE 19

int main()
{
    int file = open("ex1.txt", O_RDWR);
    char str[19] = "This is a nice day";
    char *map = mmap(NULL, STR_SIZE - 1, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
    ftruncate(file, STR_SIZE-1);
    memcpy(map, str, STR_SIZE - 1);
    close(file);
}