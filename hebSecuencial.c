#include <stdio.h>
#include <pthread.h>
#include "matriz.h"

void *worker(void *arg) {
    for (int i = 0; i < NUMFILAS; i++) {
        long s = 0;
        for (int j = 0; j < DIMFILA; j++)
            s += matriz[i].vector[j];
        matriz[i].suma = s;
    }
    return NULL;
}

int main(void) {
    inicializar_matriz();
    pthread_t th;
    pthread_create(&th, NULL, worker, NULL);
    pthread_join(th, NULL);
    imprimir_sumas();
    return 0;
}

