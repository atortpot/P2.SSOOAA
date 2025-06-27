#include "matriz.h"
#include <stdio.h>

fila_t matriz[NUMFILAS];

void inicializar_matriz(void) {
    for (int i = 0; i < NUMFILAS; i++) {
        matriz[i].suma = 0;
        for (int j = 0; j < DIMFILA; j++)
            matriz[i].vector[j] = 10;
    }
}

void imprimir_sumas(void) {
    for (int i = 0; i < NUMFILAS; i++)
        printf("Fila %2d: suma = %ld\n", i, matriz[i].suma);
}

