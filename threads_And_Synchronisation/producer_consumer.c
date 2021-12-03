#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int S=1,in=0,n=8,out=0;
char buffer[8];
char item='A';

void init_buff()
{
    memset(buffer + 0,'*', sizeof(char)*8);
}


char display(){
    for(int i=0;i<8;i++){
        printf("%c ",buffer[i]);
    }
    printf("\n");
}

char produce_item(){
    return item++;
}

void wait(int x)
{
    while(x <= 0);
    x--;
}
void signal(int x)
{
    x++;
}

void producer()  
{   
    wait(S);  
    char ip = produce_item();  
    printf("item produced-> %c\n",ip);
    buffer[in] = ip;  
    printf("\nCurrent status of buffer -> ");
    display();
    in = (in + 1) % n;
    signal(S);     
    
} 

void consumer(void)  
{    
    wait(S); 
    char ic = buffer[out]; 
    buffer[out] = '*';
    printf("\nItem consumed -> %c",ic);  
    out = (out + 1) % n;  
    printf("\nCurrent status of buffer -> ");
    display();
    signal(S);  
}  



int main(){
    init_buff();
int choice;
    printf("Initial state of buffer ( '*' denotes empty cell) : \n ");
    display();
    while(1)
    {
        printf("\n 1. Producer \n 2. Consumer \n 0.Exit \n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: if(buffer[in] != '*')
                    {
                        printf("\nBuffer full..");
                    }
                    else
                    {
                        producer();
                    }
                    break;
            case 2: if(buffer[out] == '*')
                    {
                        printf("\nBuffer empty..");
                    }
                    else
                    {
                        consumer();
                    }
                    break;
            default: exit(0);
        }
    }
    return 0;
}