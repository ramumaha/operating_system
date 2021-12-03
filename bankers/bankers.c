#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int avg(int process,int finish[]){
    int sum=0;
    for(int i=0;i<process;i++){
        sum+=finish[i];
    }
    return sum/process;
}





int main(){
    int process,resource;
    printf("Enter the number of process\n");
    scanf("%d",&process);
    printf("Enter the number of resources: \n");
    scanf("%d",&resource);
    printf("\n");
    int alloc[process][resource],max[process][resource],avail[process],need[process][resource];

    for(int i=0;i<process;i++){
        printf("Allocation value for process %d:\n",i);
        for(int j=0;j<resource;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("\n");

    for(int i=0;i<process;i++){
        printf("Enter the max for the process %d",i);
        for(int j=0;j<resource;j++){
            scanf("%d",&max[i][j]);
        }
    }

    printf("\n");
    for(int i=0;i<resource;i++){
        printf("Enter avail for %d",i);
        scanf("%d",&avail[i]);
    }
    for(int i=0;i<process;i++){
        for(int j=0;j<resource;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    printf("\n");

    int finish[process];
    memset(finish,0,sizeof(finish));
int loop_counter=0,counter;
    while(avg(process,finish)!=1){
        counter=0;
        for(int i=0;i<process;i++){
            if(finish[i]==1){
                continue;
            }else{
                for(int j=0;j<resource;j++){
                    if(need[i][j]<=avail[j]){
                        counter++;
                    }
                }
                if(counter==resource){
                    finish[i]=1;
                    printf("process %d ->",i);
                    for(int j=0;j<resource;j++){
                        avail[j]+=alloc[i][j];
                    }
                }
                counter=0;
            }
        }
        loop_counter++;
        if(loop_counter>process+1){
            if(avg(process,finish)!=1){
            printf("\nDeadlock occured\n");}
            break;
        }
    }
    return 0;
}