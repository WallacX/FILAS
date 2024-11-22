#include "servente.h"

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
