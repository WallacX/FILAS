#ifndef SERVENTE_H
#define SERVENTE_H

#include "bancada.h"

#define QTDMAXSERVENTES 6 * QTDBANCADAS * 2
#define TEMPOMAXTRABALHOSERV 60
#define TEMPOMINDESCANSOSERV 30

typedef struct{
    int id;
    int qtdUsuariosAtendidos;
    Bancada *bancada;
    int tempoAtendimento;
    int tempoTrabalhado;
    int tempoDescansado;
}Servente;

void iniciaServente(Servente *servente, int id);

void posicionaServente(Bancada *bancada, Servente serventes[]);

void checaServentes(Bancada *bancada, Servente serventes[]);
void trocaServente(Bancada *bancada, Servente serventes[], int posServBanc);//Posição do servente na bancada

void serveUsuarios(Bancada bancadas[], Servente serventes[]);



int retornaIdServenteDescansado(Servente serventes[]);

#endif // SERVENTE_H
