#include<stdio.h>

void sort_greater(int m,int memory[][2]){
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(memory[j][0]>memory[i][0]){
                int temp=memory[i][0];
                memory[i][0]=memory[j][0];
                memory[j][0]=temp;
                  temp=memory[i][1];
                memory[i][1]=memory[j][1];
                memory[j][1]=temp;
            }
        }
    }

}

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
    int memory[m][2];
    for(int i=0;i<m;i++){
        scanf("%d",&memory[i][0]);
        memory[i][1]=i;
    }
    sort_greater(m,memory);
    int i=0,j=0,x=-1;
    while(j<n){
        sort_greater(m,memory);

        if(x==j && i%m==0){
            printf("External fragmentation\n");
            break;
        }else if(i%m==0){
            x=j;
        }
        if(memory[i%m][0]>=process[j]){
            printf("Allocated!");
            memory[i%m][0]-=process[j];
            printf("%d is left.%d process is allocated %d segment\n",memory[i%m][0],j,memory[i%m][1]);
        j++;
        sort_greater(m,memory);

        }
        i++;
    }


}