#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

void main(){
    int pid=fork();
    if(pid==0){
        printf("Child process\n");
        printf("pid of child process=%d\n",getpid());
        printf("pid of parent in child=%d\n",getppid());
    }else{
        printf("Parent process\n");
        printf("pid of child in parent=%d\n",getpid());
        printf("pid of parent in parent=%d\n",getppid());
        exit(0);
    }
}