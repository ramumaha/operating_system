#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void main(){

    int shmid=shmget(IPC_PRIVATE,4,0666|IPC_CREAT);
    int *shared=(int*)shmat(shmid,(void*)0,0);
    int pr=fork();
    if(pr==0){
        *shared=1000;
        shmdt(shared);
        printf("Data is added to the common buffer\n");
        exit(0);
    }else{
        printf("The data shared is :");
        printf("%d",*shared);
        shmdt(shared);
        shmctl(shmid,IPC_RMID,NULL);
    }
}