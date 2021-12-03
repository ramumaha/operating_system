#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    srand(time(NULL));
    int page_size,page_no,frame_no,frame_size,start_addr;
    printf("Enter the number of frames :\n");
    scanf("%d",&frame_no);
    printf("Enter the frame size :\n");
    scanf("%d",&frame_size);
    printf("Enter the number of pages :\n");
    scanf("%d",&page_no);
    printf("Enter the starting address\n");
    scanf("%d",&start_addr);
    int page_table[page_no][2];
    int visited[frame_no];
    for(int i=0;i<page_no;i++){
        page_table[i][0]=-1;
        page_table[i][1]=start_addr;
        start_addr+=frame_size;
    }
    printf("Table before allocation\n");
    for(int i=0;i<page_no;i++){
        printf(" %d %d %d\n",i,page_table[i][0],page_table[i][1]);
    }
    
    for(int i=0;i<page_no;i++){
        int r=random()%frame_no;
        do{
            r=random()%frame_no;
        }while(visited[r]==1);
        visited[r]=1;
        page_table[i][0]=r;
    }
     printf("Table after allocation\n");
    for(int i=0;i<page_no;i++){
        printf(" %d %d %d\n",i,page_table[i][0],page_table[i][1]);
    }
    int test_page,offset;
    printf("Enter the page from %d to %d",0,page_no-1);
    scanf("%d",&test_page);
    while(test_page<0 || test_page>page_no-1){
        printf("Invalid\n");
        printf("Enter the page from %d to %d",0,page_no-1);
        scanf("%d",&test_page);
    }
    printf("Enter the offset from %d to %d",0,page_no-1);
    scanf("%d",&offset);
    while(offset<0 || offset>page_no-1){
        printf("Invalid\n");
        printf("Enter the page from %d to %d",0,page_no-1);
        scanf("%d",&offset);
    }
    printf("physical address is  %d",page_table[test_page][1]+offset);







    return 0;
}