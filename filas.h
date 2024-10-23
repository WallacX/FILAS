#include <stdio.h>

#define QTDMINBANCADA 2
#define QTDMAXBANCADA 4

#define QTDMINSERVENTEBANCADA 3         
#define QTDMAXSERVENTEBANCADA 6

int qtdbanatv = 0;

typedef struct{
    Vasilha *vasilha[6];
    int identificador = 0; 
}Bancada;

void iniciarBancadas(Bancada *bancada);

void ativarBancada(Bancada *bancada, int identificador);

void desativarBancada(Bancada *bancada, int identificador);
