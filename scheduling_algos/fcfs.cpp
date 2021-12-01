#include<bits/stdc++.h>
using namespace std;


struct process{
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int turnaround_time;
    int waiting_time;
    int completion_time;
};

bool compareArrival(process p1,process p2){
    return p1.arrival_time<p2.arrival_time;
}

bool compareId(process p1,process p2){
    return p1.pid<p2.pid;
}

void print_table(process p[100],int n){
    puts("+----+------------+----------+----------");
    puts("| PID| Burst time + TurnAroud Time      |");
    puts("+----+------------+----------+----------");
    for(int i=0;i<n;i++){
        printf("| %2d  |     %2d     |      %2d      |        %2d       |\n"
               , p[i].pid, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time );
        puts("+-----+------------+--------------+-----------------+");
    }
}

void gantt_chart(process p[100],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<p[i].burst_time;j++){
            printf("--");
        }
        cout<<" ";
    }
    printf("\n|");

    for(int i=0;i<n;i++){
        for(int j=0;j<p[i].burst_time-1;j++){
            cout<<" ";
          
        }
          cout<<p[i].pid;
        for(int j=0;j<p[i].burst_time-1;j++){
            cout<<" ";
            cout<<"|";
        }
    }
      for(int i=0;i<n;i++){
        for(int j=0;j<p[i].burst_time;j++){
            printf("--");
        }
        cout<<" ";
    }

    cout<<"0";
    for(int i=0;i<n;i++){
        for(int j=0;j<p[i].burst_time;j++){
            cout<<" ";
            if(p[i].turnaround_time>9){
                cout<<"\b";
            }
            cout<<p[i].turnaround_time;
        }
    }


}
int main(){

    int n;
    struct process p[100];
    float avg_turn_around;
    float avg_waiting_time;
    int total_turnaround_time=0;
    int total_waiting_time=0;
    float throughput;

    cout<<setprecision(2)<<fixed;
    cout<<"Enter the number of prcess\n";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the arrival time of the process"<<i+1<<":";
        cin>>p[i].arrival_time;
        cout<<"Enter the burst time of the process"<<i+1<<": ";
        cin>>p[i].burst_time;
        p[i].pid=i+1;
        cout<<"\n";
    }
    sort(p,p+n,compareArrival);

    for(int i=0;i<n;i++){
        p[i].start_time=(i==0)?p[i].arrival_time:max(p[i-1].completion_time,p[i].arrival_time);
        p[i].completion_time=p[i].start_time+p[i].burst_time;
        p[i].turnaround_time=p[i].completion_time-p[i].arrival_time;
        p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;

        total_turnaround_time+=p[i].turnaround_time;
        total_waiting_time+=p[i].waiting_time;
    }

    avg_turn_around=(float)total_waiting_time/n;
    avg_waiting_time=(float)total_waiting_time/n;
    throughput=(float)n/(p[n-1].completion_time-p[0].arrival_time);
    //printing table
    print_table(p,n);
    // gantt_chart(p,n);


}