#include<stdio.h>  
#include<stdlib.h>

void findTime(int n, int at[], int wt[], int bt[], int ct[], int rbt[], int tat[], int q){
    int t = 0;
    int flag = 1;
    int flag_arrival;
    while(flag != 0){
        flag_arrival = 0;
        flag = 0;
        for(int i = 0; i < n; i++){
            if((rbt[i] > 0) && (at[i] <= t)){
                flag_arrival = 1;
                if(rbt[i] > q){
                    t = t + q;
                    rbt[i] -= q;
                }
                else{
                    t = t + rbt[i];
                    rbt[i] = 0;
                    wt[i] = t-at[i]-bt[i];
                    ct[i] = t;
                    tat[i] = bt[i]+wt[i];
                }
                flag = 1;
            }
        }
        if(flag_arrival == 0){
            for(int i = 0; i < n; i++){
                if(rbt[i] > 0){
                    if(t < at[i]){
                        t = at[i];
                    }
                    if(rbt[i] > q){
                        t = t + q;
                        rbt[i] -= q;
                    }
                    else{
                        t = t + rbt[i];
                        rbt[i] = 0;
                        wt[i] = t-at[i]-bt[i];
                        ct[i] = t;
                        tat[i] = bt[i]+wt[i];
                    }
                    flag = 1;
                }
            } 
        }
    }
}
 
int main()  
{  
    int n, quantum;
    scanf("%d", &n);
    scanf("%d", &quantum);
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
    int remaining_burst[n];
    for(int i = 0; i < n; i++){
        remaining_burst[i] = burst_time[i];
    }
    int ct[n], wt[n], tat[n], total_wt = 0, total_tat = 0;  
    findTime(n, arrival_time, wt, burst_time, ct, remaining_burst, tat, quantum);  
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
    
/* Input:
4
2 3
0 4
4 2
5 4

Round robin (quantum = 1):
Process   Burst time   Completion time   Waiting time   Turn around time
   2        4           8                4                8
   1        3           9                4                7
   3        2           10                4                6
   4        4           13                4                8
Average waiting time = 4.000000
Average turn around time = 7.250000

Round robin (quantum = 2):
4 2
2 3    
0 4 
4 2
5 4
Process   Burst time   Completion time   Waiting time   Turn around time
   2        4           10                6                10
   1        3           11                6                9
   3        2           6                0                2
   4        4           13                4                8
Average waiting time = 4.000000
Average turn around time = 7.250000 

Round robin (quantum = 3):
Process   Burst time   Completion time   Waiting time   Turn around time
   2        4           12                8                12
   1        3           6                1                4
   3        2           8                2                4
   4        4           13                4                8
Average waiting time = 3.750000
Average turn around time = 7.000000

Round robin (quantum = 4):
Process   Burst time   Completion time   Waiting time   Turn around time
   2        4           4                0                4
   1        3           7                2                5
   3        2           9                3                5
   4        4           13                4                8
Average waiting time = 2.250000
Average turn around time = 5.500000

First come, first served:
Process   Burst time   Completion time   Waiting time   Turn around time
   2        4           4                0                4
   1        3           7                2                5
   3        2           9                3                5
   4        4           13                4                8
Average waiting time = 2.250000
Average turn around time = 5.500000 

Shortest job next:
Process   Burst time   Completion time   Waiting time   Turn around time
   2        4           4                0                4
   3        2           6                0                2
   1        3           9                4                7
   4        4           13                4                8
Average waiting time = 2.000000
Average turn around time = 5.250000

As we can see, in terms of average TAT and average WT, SJF has the best performance since it allows to the shortest jobs run 
first, so their TAT and WT becomes low. Round robin with quantum = 4 has absolutely the same results as FCFS since with 
quantum = 4 and max(burst_time) = 4 every job can succefully finishes in the first time slot given to it. However, all approaches
finishes all processes at the same time, so overall performance is the same for all approaches.
*/