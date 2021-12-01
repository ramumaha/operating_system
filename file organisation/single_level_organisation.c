#include<stdio.h>
#include<string.h>


int main(){
    char directory_name[100],files[10][1000],name[100];
    int n;
    printf("Enter the directory name\n");
    scanf("%s",directory_name);
    printf("Enter the number of files\n");
    scanf("%d",&n);
    int x=0,j=0,c=0,f=0;
    while(x!=n){
        start:
        f=0;
        printf("Enter the file name\n");
        scanf("%s",name);
        for(int i=0;i<n;i++){
            if(strcmp(name,files[i])==0){
                f=1;
                break;
            }
        }
        if(!f){
            strcpy(files[j++],name);
            x++;
        }else{
            printf("File already exists\n");
        }
        printf("Do you want to enter again 1.yes 2.No\n");
        scanf("%d",&c);
        if(c==1 && x!=n){
            goto start;
        }else{
            printf("Operation terminated\n");
            break;
        }
    }

    printf("The directory name is %s\n",directory_name);
    printf("The files are\n");
    for(int i=0;i<x;i++){
        printf("%s ",files[i]);
    }
    return 0;
}