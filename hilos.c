#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
int saldo;

void * holaHilo(){  
    printf("Hola desde hilo \n");
    pthread_exit(NULL);
}

void* Incrementa(){
    printf("Saldo actual es: %d\n", saldo);
    saldo = saldo + 100;
}

int main(){
    saldo=0;
    for(int i = 0; i<=100 ;i++){
        pthread_t t;
        Incrementa();
        pthread_create(&t, NULL, holaHilo, NULL); 
    }
    pthread_exit(NULL);
}