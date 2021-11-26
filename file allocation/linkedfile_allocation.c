#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int block;
    struct list*next;
}List;

typedef struct file{
    char n[10];
    int s,b;
    List*head;
}File;

File file[100];
int mem,bsize,n,nf,c,r,f,freeb[100];
List*newnode(int n){
    List*p=(List*)malloc(sizeof(List));
    p->next=NULL;
    p->block=n;
    return p;
}

void print(List*head){
    for(List*t=head;t!=NULL;t=t->next){
        printf("%d ",t->block);
        if(t->next==NULL)printf("\n");
        else{
            printf("->");
        }
    }
}

int main(){
    printf("Enter the size of memory : \n");
    scanf("%d",&mem);
    printf("Enter the size of block :\n");
    scanf("%d",&bsize);
    n=mem/bsize;
    printf("no of block is %d\n",n);
    nf=n;
    for(int i=0;i<n/3;i++){
        int r=random()%n;
        if(freeb[r]==0){
            freeb[r]=1;
            nf--;
        }else{
            i--;
        }
    }
    printf("The blocks that are free \n");
    for(int i=0;i<n;i++){
        if(freeb[i]==0){
            printf("%d ",i);
        }
    }
    printf("\n Enter the number of files\n");
    scanf("%d",&f);
    for(int i=0;i<f;i++){
        printf("Enter the name of the file %d",i+1);
        scanf("%s",file[c].n);
        printf("Enter the size of file \n");
        scanf("%d",&(file[c].s));
        file[c].b=file[c].s/bsize;
        if((file[c].s *1.0)/bsize>file[c].b){
            (file[c].b)++;
        }
         if(file[c].b>nf){
            printf("Cannot allocate\n");
            i--;
        }
        else{
            List *t, *p;
            for(int j = 0; j < file[c].b; j++) {
            r = random()%n;
            if(freeb[r] == 0) {
            freeb[r] = 1;
            nf--;
            t = newnode(r);
            if(j == 0) {
            file[c].head = t;
            p = file[c].head;
            }
            else {
            p->next = t;
            p = t;
            }
            }
            else j--;}
            c++;
            }
            if(nf == 0) {
            printf("Memory over!\n");
            f = c;
            break;
            }
            }
            printf("File allocation\n");
            for(int i=0;i<f;i++){
                printf("File is %s\n",file[i].n);
                print(file[i].head);
                printf("\n");

            }
}













 