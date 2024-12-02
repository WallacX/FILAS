#ifndef BANCADA_H
#define BANCADA_H

#include <stdio.h>
#include "vasilha.h"
#include "usuario.h"

#define QTDMINBANCADAS 2
#define QTDMAXBANCADAS 4
#define QTDMINSERVENTEBANCADA 3       
#define QTDMAXSERVENTEBANCADA 6


typedef struct Bancada{
    int qtdUsuariosAtendidos;
    int qtdServentesBancada;
    int idServentes[TAMCARDAPIO];
    Vasilha vasilhas[TAMCARDAPIO];
    Usuario *usuario;
    int tempoTotalServentes;
}Bancada;


void iniciaBancada(Bancada *bancada, Ingrediente cardapio[]);


#endif // BANCADA_H
