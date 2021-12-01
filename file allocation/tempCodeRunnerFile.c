#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(){

    int directory[1000],c,len,count=0,x,address;
    memset(directory,0,sizeof(directory));
    printf("Sequential file allocation\n");
    x:count=0;
    printf("Enter the starting address and sizeof file :\n");
    scanf("%d %d",&address,&len);
    for(int i=address;i<(address+len);i++){
        if(directory[i]==0){
            count++;
        }
    }
    if(count==len){
        printf("File allocated\n");
        for(int i=address;i<(address+len);i++){
            if(directory[i]==0){
                directory[i]=1;
            }
            printf("%d\t %d\n",i,1);
        }
        
    }else{
        printf("File not allocated\n");}
        printf("Do you want to enter more files(Yes-1/No-0)\n");
        scanf("%d",&c);
        if(c==1){
            goto x;
        }else{
            exit(0);
        }
   

}