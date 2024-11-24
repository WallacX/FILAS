#ifndef BANCADA_H
#define BANCADA_H

#include <stdio.h>
//#include <stdbool.h>
#include "vasilha.h"
#include "usuario.h"

#define QTDMINBANCADAS 2
#define QTDMAXBANCADAS 5
#define QTDMINSERVENTEBANCADA 3       
#define QTDMAXSERVENTEBANCADA 6


extern int qtdBancadasAtivas;


typedef struct Bancada{
    int identificador;
    int qtdUsuariosAtendidos;
    int qtdServentesBancada;
    //bool ativa;
    int idServentes[TAMCARDAPIO];
    Vasilha vasilhas[TAMCARDAPIO];
    Usuario *usuario;
}Bancada;


void iniciaBancada(Bancada *bancada, Ingrediente cardapio[]);


#endif // BANCADA_H
