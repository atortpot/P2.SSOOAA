#ifndef MATRIZ_H
#define MATRIZ_H

#define DIMFILA 300000
#define NUMFILAS 20

typedef struct {
    int vector[DIMFILA];
    long suma;
} fila_t;

extern fila_t matriz[NUMFILAS];

void inicializar_matriz(void);
void imprimir_sumas(void);

#endif // MATRIZ_H

