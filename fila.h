#ifndef FILA_H
#define FILA_H

#include "usuario.h"
#include "servente.h"
#include "bancada.h"

#define QTDMAXDEFILAS 5

typedef struct No{
    Usuario *usuario;
    struct No *proximo;
}No;

typedef struct{
    No *primeiro;
    No *ultimo;
    int tamanho;
    int qtdTotalDeUsuarios;
    int tempoDeEsperaTotal;
}Fila;


void iniciaFila(Fila *fila);
bool filaVazia(Fila *fila);

void enfileiraUsuarios(Ingrediente cardapio[], Fila filas[]);
void controlaTempoUsuariosNasFilas(Fila filas[]);
Fila *retornaMenorFila(Fila filas[]);

void desenfileiraUsuarios(Fila filas[], Bancada bancadas[]);
Fila *sorteiaFila(Fila filas[]);

void serveUsuarios(Bancada bancadas[]);

void checaServentes(Bancada *bancada, Servente serventes[]);
void trocaServente(Bancada *bancada, Servente serventes[], int posServBanc);//Posição do servente na bancada

void checaVasilhas(Bancada *bancada);




void iniciaRU(Ingrediente cardapio[], Bancada bancadas[], Fila filas[], Servente serventes[]);

#endif // FILA_H
