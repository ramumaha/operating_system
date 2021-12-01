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
    int is_completed[n];
    memset(is_completed,0,sizeof(is_completed));
    for(int i=0;i<n;i++){
        cout<<"Enter the arrival time of the process"<<i+1<<":";
        cin>>p[i].arrival_time;
        cout<<"Enter the burst time of the process"<<i+1<<": ";
        cin>>p[i].burst_time;
        p[i].pid=i+1;
        cout<<"\n";
    }
    int current_time=0;
    int completed=0;
    while(completed!=n){
        int idx=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(p[i].arrival_time<=current_time&&is_completed[i]==0){
                if(p[i].burst_time<mini){
                    mini=p[i].burst_time;
                    idx=i;
                }
                if(p[i].burst_time==mini){
                    if(p[i].arrival_time<p[idx].arrival_time){
                        idx=i;
                    }

                }

            }
        }
        if(idx!=-1){
            p[idx].start_time=current_time;
            p[idx].completion_time=p[idx].start_time+p[idx].burst_time;
            p[idx].turnaround_time=p[idx].completion_time-p[idx].arrival_time;
            p[idx].waiting_time=p[idx].turnaround_time-p[idx].burst_time;
            total_waiting_time+=p[idx].waiting_time;
            total_turnaround_time+=p[idx].turnaround_time;
            is_completed[idx]=1;
            completed++;
            current_time=p[idx].completion_time;
        }else{
            current_time++;
        }
    }
    avg_waiting_time=(float)total_waiting_time/n;
    avg_turn_around=(float)total_turnaround_time/n;
     cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].pid<<"\t"<<p[i].arrival_time<<"\t"<<p[i].burst_time<<"\t"<<p[i].start_time<<"\t"<<p[i].completion_time<<"\t"<<p[i].turnaround_time<<"\t"<<p[i].waiting_time<<"\t"<<"\n";
    }
    return 0;
}