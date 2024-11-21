#ifndef FILA_H
#define FILA_H

#include "usuario.h"
#include "bancada.h"
#include "servente.h"

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

Fila* sorteiaFila(Fila *filas);

Usuario desenfileiraUsuario(Fila *fila);

void serveUsuario(Fila *filas, Bancada *bancadas, Servente *serventes);

int sorteiaQtdServida(int qtdMax, int qtdMin); 

#endif // FILA_H
