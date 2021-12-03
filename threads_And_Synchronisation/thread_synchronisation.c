#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[12];
int c;
pthread_mutex_t lock;

void*trythis(void*arg){
    pthread_mutex_lock(&lock);
    c++;
    printf("Job %d has started\n",c);
    for(int i=0;i<(0xF);i++){
        printf("%d count of job %d\n",i+1,c);
    }
    printf("%d Job over\n",c);
    pthread_mutex_unlock(&lock);
    return NULL;

}

int main(){
    int i=0;
    int error;
    if(pthread_mutex_init(&lock,NULL)!=0){
        printf("mutex lock init has failed\n");
        return 1;
    }
    while(i<2){
        error=pthread_create(&tid[i],NULL,&trythis,NULL);
        if(error!=0){
            printf("Pthread cant be created");
        }
        i++;

    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_mutex_destroy(&lock);
}