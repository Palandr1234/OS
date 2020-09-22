#include<stdio.h>  
#include<stdlib.h>

void CompletionTime(int n, int at[], int wt[], int bt[], int ct[]){
    for(int i = 0; i < n; i++){
        ct[i] = at[i]+wt[i]+bt[i];
    }
}

void WaitingTime(int n, int at[], int bt[], int wt[]){    
    wt[0] = 0;     
    int service[n];
    service[0] = 0;
    for (int  i = 1; i < n ; i++ )  {
        service[i] = service[i-1]+bt[i-1];
        wt[i] = service[i] - at[i];
        if(wt[i] < 0){
            wt[i] = 0;
        } 
    } 
}  

void TurnAroundTime( int n, int bt[], int wt[], int tat[])  
{    
    for (int  i = 0; i < n ; i++){ 
        tat[i] = bt[i] + wt[i];  
    }
}  
    
int main()  
{  
    int n;
    scanf("%d", &n);
    int  burst_time[n];
    int arrival_time[n];
    int process[n];
    for(int i = 0; i<n; i++){
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        process[i] = i+1;
    }  
    
    for(int i =0; i<n-1;i++){
        for(int j = 0; j < n-i-1;j++){
            if(arrival_time[j]>arrival_time[j+1]){
                int temp_arrival = arrival_time[j];
                arrival_time[j]=arrival_time[j+1];
                arrival_time[j+1]=temp_arrival;
                int temp_burst = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1]=temp_burst;
                int temp_process = process[j];
                process[j]=process[j+1];
                process[j+1]=temp_process;
            }
        }
    }
    int ct[n], wt[n], tat[n], total_wt = 0, total_tat = 0;  
    WaitingTime(n, arrival_time, burst_time, wt);  
    CompletionTime(n,arrival_time,wt,burst_time,ct);
    TurnAroundTime(n, burst_time, wt, tat);  
    printf("Process   Burst time   Completion time   Waiting time   Turn around time\n");   
    for (int  i=0; i<n; i++)  
    {  
        total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
        printf("   %d ",process[i]); 
        printf("       %d ", burst_time[i] ); 
        printf("          %d",ct[i]);
        printf("                %d",wt[i] ); 
        printf("                %d\n",tat[i] );  
    }  
    float w=(float)total_wt / (float)n; 
    float t=(float)total_tat / (float)n; 
    printf("Average waiting time = %f",w); 
    printf("\n"); 
    printf("Average turn around time = %f ",t);  
    return 0;  
}