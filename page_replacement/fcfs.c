#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int find(int val,int frame[],int n){
for(int i=0;i<n;i++){
if(frame[i]==val){
return 1;
}
}
return -1;

}

int find_index(int x,int nf,int lru[][nf]){
for(int i=0;i<nf;i++){
if(lru[i][0]==x && lru[i][1]>0){
return i;
break;
}
}
return -1;
}

int least_used(int nf,int lru[nf][nf],int recently_used[]){
int min_index=0;
for(int i=0;i<nf;i++){
if(recently_used[min_index]>recently_used[i] && recently_used[i]!=-1){
min_index=i;}
}return min_index;

}

void LRU(int request[],int n,int nf){

int lru [nf][nf];
int recently_used[nf];
memset(lru,0,sizeof(lru));
memset(recently_used,-1,sizeof(recently_used));
int k=0;
for(int i=0;i<n;i++){
int x=find_index(request[i],nf,lru);
if(x!=-1){
printf("Page hit\n");
lru[x][1]++;
recently_used[x]=i;
}else{
printf("Page miss\n");
if(k<nf){
lru[k][0]=request[i];
lru[k][1]++;
recently_used[k]=i;
k++;
}else{
int y=least_used(nf,lru,recently_used);
lru[y][0]=request[i];
lru[y][1]=1;
recently_used[y]=i;
}
}
printf("Page no\t\t Occurance\t\t Last_used_index\t\n");
for(int i=0;i<nf;i++){
printf("%d\t\t %d\t t\t\t%d\n",lru[i][0],lru[i][1],recently_used[i]);
 printf("\n");
 }
}
}

int main(){
int nf,n;
printf("Enter the number of frames\n");
scanf("%d",&nf);
printf("Enter the size of request\n");
scanf("%d",&n);
int request[n];
for(int i=0;i<n;i++){
scanf("%d",&request[i]);
}
int frame[nf];
memset(frame,-1,sizeof(frame));

 //FIFO
printf("\n\n");
printf("FIFO\n");
printf("\n\n");
int page_hit=0;
int j=0;
for(int i=0;i<n;i++){
int x=find(request[i],frame,nf);
if(x==1){
printf("Page Hit\n");
page_hit++;
}else{
printf("Page miss\n");
if(j<nf){
frame[j]=request[i];
j++;
} else{
j=0;
frame[j]=request[i];
j++;
}
}
printf("Current contents in table\n");
for(int i=0;i<nf;i++){
printf("%d ",frame[i]);
}
printf("\n");
}
printf("The number of page fault is %d ",n-page_hit);

//LRU
printf("\n\n");
printf("LRU\n");
printf("\n\n");
LRU(request,n,nf);
return 0;
}