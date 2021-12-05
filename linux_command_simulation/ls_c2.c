#include<stdio.h>
#include<stdbool.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

void ls(char*dir,int depth,char*option){
    DIR *dp,*temp;
    struct dirent *sd;
    int i;
    dp=opendir(dir);
    for(int i=0;i<depth;i++){
        printf("\t");
    }
    printf("%s :\n",dir);
    while((sd=readdir(dp))!=NULL){
        for(int i=0;i<=depth;i++){
            printf("\t");
        }
        printf("%s\n",sd->d_name);
        if(strcmp(option,"-R")==0){
            if((temp=opendir(sd->d_name))!=NULL){
                if(strcmp(sd->d_name,".")!=0 && strcmp(sd->d_name,"..")!=0){
                    ls(sd->d_name,depth+1,option);

                }
                closedir(temp);
            }
        }
    }
    closedir(dp);
}














int main(int argc,char *argv[]){
    if(argc<3){
        ls(argv[1],0," ");
    }else{
        ls(argv[1],0,argv[2]);
    }
}