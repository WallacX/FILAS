#include <stdio.h>
#include <string.h>

#define NPROBING1
#define QTDMINING1
#define QTDMAXING1

typedef struct{
    int grauAceitacao;
    char nome[15];
}Ingrediente;

void criaIngrediente(Ingrediente *ingrediente, char *nome);

