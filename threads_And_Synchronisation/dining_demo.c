#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t room,chopstick[5];


void eat(int phil){
    for(int i=0;i<5;i++){
        if(i!=phil){
             printf("\n Philosopher %d is thinking",i);
        }else{
             printf("\n Philosopher %d is eating",phil);
        }
    }
    printf("\n");
   
}
void*philosopher(void *num){
    int phil=*(int*)num;
    sem_wait(&room);
    printf("\n Philosopher %d has entered room",phil);
    sem_wait(&chopstick[phil]);
    sem_wait(&chopstick[(phil+1)%5]);
    eat(phil);
    sleep(2);
    sem_post(&chopstick[(phil+1)%5]);
    sem_post(&chopstick[phil]);
    sem_post(&room);
}







int main(){
    int i,phil[5];
    pthread_t tid[5];
    sem_init(&room,0,4);
    for(int i=0;i<5;i++){
        sem_init(&chopstick[i],0,1);
    }
    for(int i=0;i<5;i++){
        phil[i]=i;
        pthread_create(&tid[i],NULL,philosopher,(void*)&phil[i]);
    }
    for(int i=0;i<5;i++){
        pthread_join(tid[i],NULL);
    }
}