#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct file{
    char n[10];
    int b,s;
    int i;
}File;

typedef struct indexblock{
    int blockid;
    int blocks[100];
}IndexBlock;
IndexBlock Index[100];
File file[100];
int freeb[100],n,nf,mem,f,c,r,bsize;

void print(int i){
    printf("Index block : %d\n Blocktable\n",Index[i].blockid);
    for(int j=0;j<file[i].b;j++){
        printf("%d ",Index[i].blocks[j]);

    }
}

int main(){
    printf("Enter size of memory :\n");
    scanf("%d",&mem);
    printf("Enter the blocksize\n");
    scanf("%d",&bsize);
    n=mem/bsize;
    printf("No of blocks %d\n",n);
    nf=n;
    for(int i=0;i<n/3;i++){
        r=random()%n;
        if(freeb[r]==0){
            nf--;
            freeb[r]=1;
        }else{
            i--;
        }
    }
    printf("free blocks\n");
    for(int i=0;i<n;i++){
        if(freeb[i]==0){
            printf("%d ",i);
        }
    }
    printf("Enter the number of files\n");
    scanf("%d",&f);
    for(int i=0;i<f;i++){
        printf("Enter the name of file\n");
        scanf("%s",file[c].n);
        printf("Enter the size of file\n");
        scanf("%d",&file[c].s);
        file[c].b=ceil((float)file[c].s/bsize);
        if((file[c].b*1.0)/bsize>file[c].b){
            (file[c].b)++;
        
                }
        if(file[c].b>nf){
            printf("Cannot Allocate\n");
            i--;
        }else{
            do{
                r=random()%n;

            }while(freeb[r]==1);
            Index[c].blockid=r;
            file[c].i=r;
            freeb[r]=1;
            nf--;
            for(int j=0;j<file[c].b;j++){
                r=random()%n;
                if(freeb[r]==0){
                    nf--;
                    freeb[r]=1;
                    Index[c].blocks[j]=r;
                }else{
                    j--;
                }
            }
            c++;
        }
        if(nf==0){
            printf("Memory over\n");
            f=c;
            break;
        }
    }
    printf("File allocation\n");
    for(int i=0;i<f;i++){
        printf("File is %s\n",file[i].n);
        print(i);
        printf("\n");
    }

   return 0;
}
