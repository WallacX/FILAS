#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#define TAMMAXNOMEINGREDIENTE 15
#define TAMCARDAPIO 6
#define TOTALINGREDIENTES 12

#define QTD_MIN_INGREDIENTE_1 20
#define QTD_MAX_INGREDIENTE_1 200
#define QTD_MIN_INGREDIENTE_2 20
#define QTD_MAX_INGREDIENTE_2 200
#define QTD_MIN_INGREDIENTE_3 20
#define QTD_MAX_INGREDIENTE_3 150
#define QTD_MIN_INGREDIENTE_4 100
#define QTD_MAX_INGREDIENTE_4 200
#define QTD_MIN_INGREDIENTE_5 10
#define QTD_MAX_INGREDIENTE_5 100
#define QTD_MIN_INGREDIENTE_6 50
#define QTD_MAX_INGREDIENTE_6 250


typedef struct Ingrediente{
    int grauAceitacao ;
    char nome[TAMMAXNOMEINGREDIENTE];
}Ingrediente;

Ingrediente criaIngrediente(int grauAceit, const char nome[]);

void criaCardapio(Ingrediente cardapio[]);

void imprimeCardapio(Ingrediente cardapio[]);

#endif // INGREDIENTE_H
