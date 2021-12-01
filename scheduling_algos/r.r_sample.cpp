#include<bits/stdc++.h>
using namespace std;

struct process{
    int pid;
    int s_time;
    int c_time;
    int t_time;
    int w_time;
    int b_time;
    int a_time;
};

bool compare(process a,process b){
    return a.a_time<b.a_time;
}

bool compare2(process a,process b){
    return a.pid<b.pid;
}

int main(){

    int n,tq,count=0,current_time=0;
    float averge_turnaround_time;
    float average_waiting_time;
    int total_waiting_time=0;
    int total_turnaround_time=0;
    cout<<"Enter the number of process\n";
    cin>>n;
    cout<<"Enter the time quanta\n";
    cin>>tq;
    process p[n];
    int burst_time[n+1];
    memset(burst_time,0,sizeof(burst_time));
     for (int i = 0; i < n; i++)
    {
        cout << "\nProcess " << i + 1 << "\n";
        cout << "\nArrival Time: ";
        cin >> p[i].a_time;
        cout << "\nBurst Time: ";
        cin >> p[i].b_time;
        p[i].pid = i + 1;
        burst_time[p[i].pid] = p[i].b_time;
        
    }
    sort(p,p+n,compare);
    queue<int>q;
    vector<int>mark(n,false);
    q.push(0);
    mark[0]=true;
    while(count!=n){
        int idx=q.front();
        q.pop();
        if(burst_time[p[idx].pid]==p[idx].b_time){
            p[idx].s_time=current_time;

        }
        if(burst_time[p[idx].pid]-tq>0){
            current_time+=tq;
            burst_time[p[idx].pid]-=tq;
        }else{
            current_time+=burst_time[p[idx].pid];
            burst_time[p[idx].pid]=0;
            count++;
            p[idx].c_time=current_time;
            p[idx].t_time=p[idx].c_time-p[idx].a_time;
            p[idx].w_time=p[idx].t_time-p[idx].b_time;
            total_waiting_time+=p[idx].w_time;
            //    p[idx].r_time = p[idx].s_time + p[ind].a_time;

            total_turnaround_time+=p[idx].t_time;
        }
        for(int i=1;i<n;i++){
            int id=p[i].pid;
            if(p[i].a_time<=current_time&&!mark[i]&&burst_time[id]>0){
                mark[i]=true;
                q.push(i);
            }
        }
        if(burst_time[p[idx].pid]>0){
            q.push(idx);
        }
        if(q.empty()){
            for(int i=0;i<n;i++){
                int id=p[i].pid;
                if(burst_time[id]>0){
                    mark[i]=true;
                    q.push(i);

                }
            }
        }
    }
//  sort(p, p + n, compare2);
    cout << "\nPID\t\tAT\t\tBT\t\tST\t\tCT\t\tTAT\t\tWT";
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << p[i].pid << "\t\t" << p[i].a_time << "\t\t" << p[i].b_time << "\t\t" << p[i].s_time << "\t\t" << p[i].c_time << "\t\t" << p[i].t_time << "\t\t" << p[i].w_time;
    }

}