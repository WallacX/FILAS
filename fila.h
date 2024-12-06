#ifndef FILA_H
#define FILA_H

#include <stdbool.h>
#include "usuario.h"
#include "servente.h"
#include "bancada.h"


//Checa se o sistema é linux ou windows e inclui a biblioteca correspondente
#ifdef __unix__         
    #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32) 
   #define OS_Windows
   #include <windows.h>
#endif


#define QTDFILAS 5

typedef struct No{
    Usuario *usuario;
    struct No *proximo;
}No;

typedef struct{
    No *primeiro;
    No *ultimo;
    int tamanho; //Tamanho atual da fila
    int qtdTotalDeUsuarios; //Quantidade total de usuarios que entrou na respectiva fila
    int tempoDeEsperaTotal; //Tempo de espera total dos usuarios que entraram na respectiva fila
}Fila;


void iniciaFila(Fila *fila);
bool filaVazia(Fila *fila);

void enfileiraUsuarios(Ingrediente cardapio[], Fila filas[]);
void controlaTempoUsuariosNasFilas(Fila filas[]);
Fila *retornaMenorFila(Fila filas[]);

void desenfileiraUsuarios(Fila filas[], Bancada bancadas[]);
Fila *sorteiaFila(Fila filas[]);

void iniciaRU(Ingrediente cardapio[], Bancada bancadas[], Fila filas[], Servente serventes[]);

void funcionamentoRU(Ingrediente cardapio[], Bancada bancadas[], Fila filas[], Servente serventes[]);
bool checaUsuariosNoRU(Bancada bancadas[]);

void imprimeRelatorio(Ingrediente cardapio[], Bancada bancadas[], Fila filas[], Servente serventes[]);


#endif // FILA_H
