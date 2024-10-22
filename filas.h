#include <stdio.h>

#define QTDMINBAN 1
#define QTDMAXBAN 10

#define QTDMINSERVBAN 3
#define QTDMAXSERVBAN 6

int qtdbanatv = 0;

typedef struct{
    Vasilha vasilha[6];
    int identificador;
}Bancada;

void iniciarBancada(Bancada *bancada);

void desativarBancada(Bancada *bancada);
