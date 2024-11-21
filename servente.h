#ifndef SERVENTE_H
#define SERVENTE_H

#include "bancada.h"

#define QTDMINSERVERNTES 3
#define QTDMAXSERVENTES 36


typedef struct{
    int id;
    int qtdUsuariosAtendidos;
    Bancada *bancada;
    int tempoAtendimento;
    int tempoTrabalhado;
    int tempoDescansado;
}Servente;

void iniciaServente(Servente *servente, int id);

void posicionaServente(Bancada *bancada, Servente *servente);

#endif // SERVENTE_H
