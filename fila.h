#ifndef FILA_H
#define FILA_H

#include "usuario.h"

#define MAXIMODEFILAS 5

typedef struct No{
    Usuario *usuario;
    struct No *proximo;
}No;

typedef struct{
    No *primeiro;
    No *ultimo;
    int tamanho;
}Fila;



int retornaIndiceMenorFila(Fila filas[]);

void enfileiraUsuario(Usuario *usuario, Fila *fila);

void iniciaFila(Fila *fila);

bool filaVazia(Fila *fila);


#endif // FILA_H
