#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
    int file = open("ex1.txt", O_RDWR);
    struct stat buff;
    fstat (file, &buff);
    char *map = mmap(NULL, buff.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
    int file_write = open("ex1.memcpy.txt", O_RDWR | O_CREAT);
    char *map_write = mmap(NULL, buff.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file_write, 0);
    ftruncate(file_write, buff.st_size);
    memcpy(map_write, map, buff.st_size);
    close(file);
    close(file_write);
}