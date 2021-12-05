#include <stdio.h>
#include <stdlib.h>
int round_robin(int proc[], int burst[], int bt[], int arr[], int n, int qm) // bt ->temp burst time
{
    int wt[n], tat[n];
    int waittime = 0, turn_around = 0;
    int num = n;
    int total_time = 0, count = 0;
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for (int i = 0; num != 0;)
    {
        if (bt[i] <= qm && bt[i] > 0)
        {
            total_time += bt[i];
            bt[i] = 0;
            count = 1;
        }
        else if (bt[i] > 0)
        {
            total_time += qm;
            bt[i] -= qm;
        }
        if (bt[i] == 0 && count == 1)
        {
            num--;
            printf("\nProcess No[%d] \t\t %d \t\t\t\t %d\t\t\t %d", i + 1, burst[i], total_time - arr[i],
                   total_time - arr[i] - burst[i]);
            waittime = waittime + total_time - arr[i] - burst[i];
            turn_around = turn_around + total_time - arr[i];
            count = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (arr[i + 1] <= total_time)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    float average_round_robin = (float)waittime / n;
    float average_turnaround_time = (float)turn_around / n;
    printf("\nAverage Waiting Time: %f", average_round_robin);
    printf("\nAvg Turnaround Time: %f", average_turnaround_time);
    return 0;
}
int main()
{
    int n, quantum;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    int process[n], burst_times[n], arrival[n], temp[n];
    printf("Enter burst time and arrival time for processes:\n");
    for (int i = 0; i < n; i++)
    {
        process[i] = i + 1;
        printf("Process %d : ", process[i]);
        printf("Arrival time : ");
        scanf("%d", &arrival[i]);
        printf("Burst time : ");
        scanf("%d", &burst_times[i]);
        temp[i] = burst_times[i];
    }
    printf("\nSet quantum for each process..\n Quantum (in ms) = ");
    scanf("%d", &quantum);
    round_robin(process, burst_times, temp, arrival, n, quantum);
    return 0;
}