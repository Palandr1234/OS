#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#define N 100

int main()
{
	DIR *dir = opendir("./tmp");
	if(dir == NULL)
	{
		return -1;
	}
	int inum[N];
	char* file[N];
	int ind = 0;
	int checked[N];
	for(int i=0; i<N; i++){
		checked[i]=0;
	}
	struct dirent *dp;
	while((dp = readdir(dir)) != NULL)
	{
		inum[ind] = dp->d_ino;
		file[ind] = dp->d_name;
		ind++;
	}
	for(int i = 0; i < ind; i++){
		int count = 1;
		int isPrinted = 0;
		if(checked[i] == 0){
			for(int j = i+1; j<ind; j++){
				if(inum[i] == inum[j]){
					checked[j]=1;
					count++;
					if(isPrinted == 0){
						printf("files with the same i-node number: %s %s" ,file[i], file[j]);
						isPrinted = 1;
					}
					else{
						printf(" s", file[j]);
					}	
				}
			}
			checked[i]=1;
		}
		if(count> 1){
			printf("\n");
		}
	}
	closedir(dir);
	return 0;
}