#ifndef BANCADA_H
#define BANCADA_H

#include <stdio.h>
#include "vasilha.h"
#include "usuario.h"

#define QTDMINBANCADAS 2
#define QTDMAXBANCADAS 4
#define QTDMINSERVENTEBANCADA 3       
#define QTDMAXSERVENTEBANCADA 6


extern int qtdBancadasAtivas;


typedef struct Bancada{
    int identificador;
    int qtdUsuariosAtendidos;
    Vasilha vasilhas[TAMCARDAPIO];
    //podemos fazer dentro da struct ou ent um vetor global contando que vai somar o tempo dos atendentes
    Usuario *usuario;
}Bancada;


void iniciaBancada(Bancada *bancada, Ingrediente cardapio[]);


#endif // BANCADA_H
