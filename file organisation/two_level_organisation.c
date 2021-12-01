#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct{
    char dname[10],fname[10][10];
    int fcnt;
}dir[10];


int main(){
    int i,ch,dcnt=0,k;
    char f[30],d[30];
    while(1){
        printf("\n1.Create Directory\t2.Create file\t3.Display\t4.Exit\nEnter the choice :");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the name of the directory\n");
            scanf("%s",dir[dcnt].dname);
            dir[dcnt].fcnt=0;
            dcnt++;
            printf("Directory created\n");
            break;

            case 2:
            printf("Enter the name of the directory\n");
            scanf("%s",d);
            for(i=0;i<dcnt;i++){
                if(strcmp(d,dir[i].dname)==0){
                    printf("Enter the file name\n");
                    scanf("%s",dir[i].fname[dir[i].fcnt]);
                    dir[i].fcnt++;
                    printf("File created\n");
                    break;
                }
            }
            if(i==dcnt){
                printf("Directory not found\n");
                break;
            }
            break;

            case 3:
            if(dcnt==0){
                printf("No directory created\n");}

                for(int i=0;i<dcnt;i++){
                    printf("\n %s\t\t",dir[i].dname);
                    for(int j=0;j<dir[i].fcnt;j++){
                        printf("%s ",dir[i].fname[j]);
                    }
                }
           
            break;

            case 4:
            exit(0);
            default:
            exit(0);
        }
    }









    return 0;
}