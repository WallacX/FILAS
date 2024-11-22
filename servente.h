#ifndef SERVENTE_H
#define SERVENTE_H

#include "bancada.h"
#include <stdbool.h>

#define QTDMINSERVERNTES 3
#define QTDMAXSERVENTES 36
#define TEMPSERVMAX 60 


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

bool serventeTempoTrabalhoMax(Servente *servente);

#endif // SERVENTE_H
