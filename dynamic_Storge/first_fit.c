#include<stdio.h>

int main(){
    int n,m;
    printf("Enter the number of process :\n");
    scanf("%d",&n);
    int process[n];
    for(int i=0;i<n;i++){
        printf("Enter mem need for %d :\n",i);
        scanf("%d",&process[i]);
    }
    printf("Enter the number of holes :\n");
    scanf("%d",&m);
    int memory[m];
    for(int i=0;i<m;i++){
        scanf("%d",&memory[i]);
    }
int i=0,j=0,x=-1;
    while(j<n){
        if(i%m==0 && x==j){
            printf("External fragmentation\n");
            break;
        }else if(i%m==0){
            x=j;
        }
        if(memory[i%m]>=process[j] && j<n){
            memory[i%m]-=process[j];
          printf("%d left.%d segment allocated to process %d \n",memory[i%m],i%m,j);
            j++;
        }
        i++;
    }

}