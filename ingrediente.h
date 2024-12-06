#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAMMAXNOMEINGREDIENTE 15
#define TAMCARDAPIO 6
#define TOTALINGREDIENTES 12


extern int totalIngredientesConsumidos[6]; //Vetor que armazena a quantidade total de ingredientes consumidos
extern const int QTDMAXINGREDIENTES[6]; //Vetores para armazenar a quantidade min e max de cada ingrediente que pode ser consumida por cada usuario
extern const int QTDMININGREDIENTES[6];


typedef struct Ingrediente{
    int grauAceitacao; //Armazena a % de aceitação do ingrediente
    char nome[TAMMAXNOMEINGREDIENTE];
}Ingrediente;

void criaCardapio(Ingrediente cardapio[]);

Ingrediente criaIngrediente(int grauAceit, const char nome[]);

void imprimeCardapio(Ingrediente cardapio[]);

#endif // INGREDIENTE_H
