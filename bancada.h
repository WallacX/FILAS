#include <stdio.h>
#include "vasilha.h"
#include "usuario.h"

#define QTDMINBANCADA 2
#define QTDMAXBANCADA 4

#define QTDMINSERVENTEBANCADA 3         
#define QTDMAXSERVENTEBANCADA 6

int qtdbancadasattvas = 0;

typedef struct{
    Vasilha *vasilha[6];
    int identificador; 
    //int tempoAtendimento; no relatorio precisamos imprimir o tempo medio de atendimento das bancadas
    //podemos fazer dentro da struct ou ent um vetor global contando que vai somar o tempo dos atendentes
    Usuario *usuario;
    int qtdUsuariosAtendidos;
}Bancada;

void iniciarBancadas(Bancada *bancada);

void ativarBancada(Bancada *bancada, int identificador);

void desativarBancada(Bancada *bancada, int identificador);