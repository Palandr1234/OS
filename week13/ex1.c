#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_OF_PROC 3
#define NUM_OF_RES 1

int main(int argc, char *argv[])
{

	FILE *input = fopen("input.txt", "r");

    int E[NUM_OF_RES], A[NUM_OF_RES], C[NUM_OF_PROC][NUM_OF_RES], R[NUM_OF_PROC][NUM_OF_RES];
    int proc_deadlocked[NUM_OF_PROC];
    for (int i = 0; i < NUM_OF_RES; i++){
        fscanf(input, "%d", &E[i]);
    }
    for (int i = 0; i < NUM_OF_RES; i++){
        fscanf(input, "%d", &A[i]);
    }
    for(int i = 0; i < NUM_OF_PROC; i++){
        proc_deadlocked[i] = 1;
        for (int j = 0; j < NUM_OF_RES; j++){
            fscanf(input, "%d", &C[i][j]);
        }
    }
    for(int i = 0; i < NUM_OF_PROC; i++){
        for (int j = 0; j < NUM_OF_RES; j++){
            fscanf(input, "%d", &R[i][j]);
        }
    }
    fclose(input);
    for(int i = 0; i < NUM_OF_PROC; i++){
        for (int j = 0; j < NUM_OF_PROC; j++){
            int is_ok = 1;
            for(int k = 0; k < NUM_OF_RES; k++){
                if(A[k] < R[j][k]){
                    is_ok = 0;
                    break;
                }
            }
            if((is_ok == 1)&&(proc_deadlocked[j] == 1)){
                proc_deadlocked[j] = 0;
                for(int k = 0; k < NUM_OF_RES; k++){
                    A[k] += C[j][k]; 
                }
            }
        }
    }
    FILE* output = fopen("output.txt", "w");
    int is_deadlock = 0;
    for(int i = 0; i < NUM_OF_PROC; i++){
        if(proc_deadlocked[i] == 1){
            is_deadlock = 1;
            break;
        }
    }
    if(is_deadlock == 1){
        fprintf(output, "There is a deadlock between these processes:\n");
        for(int i = 0; i < NUM_OF_PROC; i++){
            if(proc_deadlocked[i] == 1){
                fprintf(output, "%d ", i);
            }
        }
        fprintf(output, "\n");
    }
    else{
        fprintf(output, "There is no a deadlock\n");
    }
    fclose(output);
	return 0;
}