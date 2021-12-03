#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(NULL));

   long long int page_no,page_size,frame_no,frame_size,start_addr;
    cout<<"enter the number of frames\n";
    cin>>frame_no;
    cout<<"enter the frame size\n";
    cin>>frame_size;
    cout<<"enter the number of pages\n";
    cin>>page_no;
    cout<<"Enter the starting address\n";
    cin>>start_addr;
    vector<vector<int>>page_table(page_no,vector<int>(2));
    vector<int>visited(frame_no,0);
    for(int i=0;i<page_no;i++){
        page_table[i][0]=-1;
        page_table[i][1]=start_addr;
        start_addr+=frame_size;  
    }
    cout<<"Table before allocation\n";
    for(int i=0;i<page_no;i++){
        cout<<page_table[i][0]<<" "<<page_table[i][1]<<"\n";
    }
    
    for(int i=0;i<page_no;i++){
        int r=rand()%frame_no;
        do{
            r=rand()%frame_no;
        }while(visited[r]==1);
        visited[r]=1;
        page_table[i][0]=r;
    }

     cout<<"Table after allocation\n";
    for(int i=0;i<page_no;i++){
        cout<<page_table[i][0]<<" "<<page_table[i][1]<<"\n";
    }
    long long int offset,pg;
     cout<<"Enter page no between 0 and "<<page_no-1<<":";
    cin>>pg;
    while(pg<0 || pg>page_no-1){
        cout<<"Illegal value\n";
        cout<<"Enter page no between 0 and "<<page_no-1<<":";
        cin>>pg;}


     cout<<"Enter the offset";
    cin>>offset;
    while(offset>page_no-1 || offset<0){
        cout<<"Illegal value\n";
          cout<<"Enter the offset :";
    cin>>offset;}

    cout<<"The physical address is "<<page_table[pg][1]+offset;



    return 0;
}