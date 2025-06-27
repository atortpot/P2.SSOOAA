#include <stdio.h>
#include "matriz.h"

int main(void) {
    inicializar_matriz();
    for (int i = 0; i < NUMFILAS; i++) {
        long s = 0;
        for (int j = 0; j < DIMFILA; j++)
            s += matriz[i].vector[j];
        matriz[i].suma = s;
    }
    imprimir_sumas();
    return 0;
}

