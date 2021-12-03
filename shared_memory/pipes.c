#include<stdio.h>
#include<unistd.h>
#define MEGSIZE 16

void main(){
    int p[2];
    int x=pipe(p);
    if(x<0){
        printf("Not successful\n");
    }else{
        printf("successful");
    }
}