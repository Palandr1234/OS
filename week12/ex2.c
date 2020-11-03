#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int append = 0;
	
	if(argc > 1 && strcmp(argv[1], "-a") == 0)
		append = 1;
	int count = argc - append - 1;
	FILE** files = malloc(count * sizeof(FILE*));
    char* mode;
    if(append == 0){
        mode = "w";
    }
    else{
        mode = "a";
    }
        printf("%d\n", append);
	for(int i=0; i<count; i++){
		files[i] = fopen(argv[i+append+1], mode);
    }
    
	char output;
	while(read(0, &output, 1) != 0){
        //printf("%d\n", append);
		printf("%c", output);
		for(int i=0; i<count; i++){
            fprintf(files[i], "%c", output);
        }
	}
	for(int i=0; i<count; i++){
		fclose(files[i]);
	}
	
	return 0;
}