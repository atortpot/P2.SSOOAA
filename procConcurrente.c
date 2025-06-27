#include <stdio.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include "matriz.h"

int main(void) {
    fila_t *shared = mmap(NULL, sizeof(matriz),
                         PROT_READ|PROT_WRITE,
                         MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    if (shared == MAP_FAILED) { perror("mmap"); return 1; }

    inicializar_matriz();  // inicializa en la región compartida

    for (int i = 0; i < NUMFILAS; i++) {
        if (fork() == 0) {
            long s = 0;
            for (int j = 0; j < DIMFILA; j++)
                s += shared[i].vector[j];
            shared[i].suma = s;
            _exit(0);
        }
    }
    for (int i = 0; i < NUMFILAS; i++) wait(NULL);

    for (int i = 0; i < NUMFILAS; i++)
        printf("Fila %2d: suma = %ld\n", i, shared[i].suma);

    return 0;
}


