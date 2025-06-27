#include <stdio.h>
#include <pthread.h>
#include "matriz.h"

void *worker(void *arg) {
    int idx = (int)(long)arg;
    long s = 0;
    for (int j = 0; j < DIMFILA; j++)
        s += matriz[idx].vector[j];
    matriz[idx].suma = s;
    return NULL;
}

int main(void) {
    inicializar_matriz();

    pthread_t threads[NUMFILAS];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    // Prueba con PTHREAD_SCOPE_SYSTEM
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
    for (long i = 0; i < NUMFILAS; i++)
        pthread_create(&threads[i], &attr, worker, (void*)i);
    for (int i = 0; i < NUMFILAS; i++)
        pthread_join(threads[i], NULL);
    printf("== PTHREAD_SCOPE_SYSTEM ==\n");
    imprimir_sumas();

    // Reinicializa y prueba PTHREAD_SCOPE_PROCESS
    inicializar_matriz();
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);
    for (long i = 0; i < NUMFILAS; i++)
        pthread_create(&threads[i], &attr, worker, (void*)i);
    for (int i = 0; i < NUMFILAS; i++)
        pthread_join(threads[i], NULL);
    printf("== PTHREAD_SCOPE_PROCESS ==\n");
    imprimir_sumas();

    pthread_attr_destroy(&attr);
    return 0;
}

