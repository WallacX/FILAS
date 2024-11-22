#include "servente.h"
#include <stdbool.h>

#define QTDMINSERVERNTES 3
#define QTDMAXSERVENTES 36


void iniciaServente(Servente *servente, int id){
    servente->id = id;
    servente->qtdUsuariosAtendidos = 0;
    servente->bancada = NULL;
    servente->tempoAtendimento = rand()%4+3;
    servente->tempoTrabalhado = 0;
    servente->tempoDescansado = 30;
}

void posicionaServente(Bancada *bancada, Servente *servente){
    servente->bancada = bancada;
}

//Checar se o servente atingiu o tempo máximo de trabalho.
bool serventeTempoTrabalhoMax(Servente *servente){
    //Caso o tempo trabalhado seja menor que o maximo retorna falso.
    if (servente -> tempoTrabalhado < TEMPSERVMAX){
        return false;
    }
    else {
        return true;
    }
}
