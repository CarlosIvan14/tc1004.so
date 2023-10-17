#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
int saldo;

void * holaHilo(void *thid){  
    printf("Hola desde hilo %d\n",*((int*)thid));
    pthread_exit(NULL);
}

int main(){
    saldo=0;
    pthread_t t;
    int thid=1;
    for(int i = 1; i<=100 ;i++){
         pthread_create(&t, NULL, holaHilo, &thid); 
         thid=i;
    }
    pthread_exit(NULL);
}