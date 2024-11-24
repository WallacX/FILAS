#ifndef FILA_H
#define FILA_H

#include "usuario.h"
#include "servente.h"
#include "bancada.h"

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

void checaVasilhas(Bancada *bancada);

int retornaIndiceMenorFila(Fila filas[]);

void enfileiraUsuario(Usuario *usuario, Fila *fila);

void iniciaFila(Fila *fila);

bool filaVazia(Fila *fila);



void desenfileiraUsuario(Fila filas[], Bancada bancadas[], Servente serventes[]);

void posicionaUsuarioNaBancada(Usuario *usuario, Bancada bancadas[], Servente serventes[]);

void serveUsuario(Bancada *bancada, Servente serventes[]);

//Mover essa função pro arquivo de bancadas caso possivel
Bancada *selecionaBancadaVazia(Bancada bancadas[]);

Fila *sorteiaFila(Fila filas[]);



void checaServentes(Bancada *bancada, Servente serventes[]);

void trocaServente(Bancada *bancada, Servente serventes[], int posServBanc);//Posição do servente na bancada



#endif // FILA_H
