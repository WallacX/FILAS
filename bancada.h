#ifndef BANCADA_H
#define BANCADA_H

#include <stdio.h>
#include "vasilha.h"
#include "usuario.h"


#define QTDBANCADAS 6
#define QTDMINSERVENTEBANCADA 3
#define QTDMAXSERVENTEBANCADA 6


typedef struct Bancada{
    int qtdUsuariosAtendidos;
    int qtdServentesBancada;
    int idServentes[TAMCARDAPIO]; //Armazena o id dos serventes em cada posição da bancada
    Vasilha vasilhas[TAMCARDAPIO];
    Usuario *usuario; //Aponta pra o usuario que está na bancada naquele momento
    int tempoTotalServindo; //Armazena o tempo total (do dia inteiro) que a bancada serviu
}Bancada;


void iniciaBancada(Bancada *bancada, Ingrediente cardapio[]);

void checaVasilhas(Bancada bancadas[]);

#endif // BANCADA_H
