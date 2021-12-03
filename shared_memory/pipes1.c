#include<stdio.h>
#include<unistd.h>
#define MEGSIZE 16

int main(){
    int p[2];
    int x=pipe(p);
    int pid=getpid();
    if(pid!=0){
        write(p[1],"Hello Child!",MEGSIZE);
    }
    pid=fork();
    if(pid==0){
        char kol[MEGSIZE];
        close(p[1]);
        read(p[0],kol,MEGSIZE);
        printf("%s",kol);
    }




    return 0;
}