#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#define TAMMAXNOMEINGREDIENTE 15
#define TAMCARDAPIO 6
#define TOTALINGREDIENTES 12


extern int totalIngredientesConsumidos[6];
extern const int QTDMAXINGREDIENTES[6];
extern const int QTDMININGREDIENTES[6];


typedef struct Ingrediente{
    int grauAceitacao ;
    char nome[TAMMAXNOMEINGREDIENTE];
}Ingrediente;

Ingrediente criaIngrediente(int grauAceit, const char nome[]);

void criaCardapio(Ingrediente cardapio[]);

void imprimeCardapio(Ingrediente cardapio[]);

#endif // INGREDIENTE_H
