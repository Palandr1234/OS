#include<stdio.h>  
#include<stdlib.h>

void findTime(int n, int time[][6]){
    time[0][3] = time[0][1] + time[0][2];
    time[0][5] = time[0][3] - time[0][1];
    time[0][4] = time[0][5] - time[0][2];
    for(int i = 1; i < n; i++){
        int curr_time = time[i-1][3];
        int mn = time[i][2];
        int ind = i;
        for(int j = i; j < n; j++){
            if((time[j][2] < mn) && (time[j][1] <= curr_time)){
                mn = time[j][2];
                ind = j;
            }
        }
        if(time[ind][1] > curr_time){
            curr_time = time[ind][1];
        }
        time[ind][3] = curr_time + time[ind][2];
        time[ind][4] = curr_time - time[ind][1];
        time[ind][5] = time[ind][4] + time[ind][2];
        for(int j = 0; j < 6; j++){
            int temp = time[i][j];
            time[i][j] = time[ind][j];
            time[ind][j] = temp;
        }
    }
}
    
// Driver code  
int main()  
{  
    int n;
    scanf("%d", &n);
    int  time[n][6];
    for(int i = 0; i<n; i++){
        scanf("%d %d", &time[i][1], &time[i][2]);
        time[i][0] = i+1;
    }  
    
    for(int i =0; i<n-1;i++){
        for(int j = 0; j < n-i-1;j++){
            if((time[j][1] > time[j+1][1]) || ((time[j][1] == time[j+1][1]) && (time[j][2] > time[j+1][2]))){
                for(int k = 0; k < 3; k++){
                    int temp = time[j][k];
                    time[j][k] = time[j + 1][k];
                    time[j + 1][k] = temp;
                }
            }
        }
    }
    int total_wt = 0, total_tat = 0;  
    findTime(n, time); 
    printf("Process   Burst time   Completion time   Waiting time   Turn around time\n");   
    for (int  i=0; i<n; i++)  
    {  
        total_wt = total_wt + time[i][4];  
        total_tat = total_tat + time[i][5];  
        printf("   %d ",time[i][0]); 
        printf("       %d ", time[i][2] ); 
        printf("          %d",time[i][3]);
        printf("                %d",time[i][4] ); 
        printf("                %d\n",time[i][5] );  
    }  
    float w=(float)total_wt / (float)n; 
    float t=(float)total_tat / (float)n; 
    printf("Average waiting time = %f",w); 
    printf("\n"); 
    printf("Average turn around time = %f ",t);  
    return 0;  
}