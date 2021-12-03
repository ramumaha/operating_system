#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/resource.h>
#define SIZER 80

void main(){
    int p1=-1,p2=-1,p3=-1,p[2],pa[2];
    pipe(p);
    setpriority(PRIO_PROCESS,getpid(),10);
    p1=fork();
    if(p1==0){
        write(p[1],"hello",SIZER);
        exit(0);
    }
    if(p1!=0){
        char inbuf[SIZER];
        read(p[0],inbuf,SIZER);
        pipe(pa);
        write(pa[1],inbuf,SIZER);
        setpriority(PRIO_PROCESS,getpid(),10);
        p2=fork();
    }
    if(p2==0){
        char inbuf[SIZER];
        read(pa[0],inbuf,SIZER);
        printf("%s",inbuf);
        close(pa[1]);
        close(pa[0]);
    }
}