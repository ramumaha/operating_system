#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

void main(int argc,char*argv[]){
    int f1,f2,c;
    char buf[1024];
    f1=open(argv[1],O_RDONLY);
    f2=open(argv[0],O_WRONLY|O_CREAT,S_IRWXU|S_IRGRP|S_IROTH);
    while((c=read(f1,buf,1024))>0){
        writ(f2,buf,c);
    }
    printf("Copied");
    close(f1);
    close(f2);
}