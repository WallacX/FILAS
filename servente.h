#ifndef SERVENTE_H
#define SERVENTE_H

#include "bancada.h"

#define QTDSERVENTES 6 * QTDBANCADAS * 2 //Garante que a quantidade de serventes vai ser suficiente para todas as bancadas mesmo com as trocas
#define TEMPOMAXTRABALHOSERVENTE 60
#define TEMPOMINDESCANSOSERVENTE 30

typedef struct{
    int id; //Id do servente é semelhante ao seu indice no vetor
    int qtdUsuariosAtendidos; //Armazena a quantidade total de usuarios atendidos pelo respectivo servente
    Bancada *bancada; //Aponta para a bancada em que o respectivo servente está posicionado
    int tempoAtendimento; //Tempo que o usuario demora para servir
    int tempoTrabalhado;
    int tempoDescansado;
}Servente;

void iniciaServente(Servente *servente, int id);

void posicionaServente(Bancada *bancada, Servente serventes[]);

void checaServentes(Bancada *bancada, Servente serventes[]);
void trocaServente(Bancada *bancada, Servente serventes[], int posServBanc);//Posição do servente na bancada

void serveUsuarios(Bancada bancadas[], Servente serventes[]);



int retornaIdServenteDescansado(Servente serventes[]);

void atualizaContadorServentes(Bancada *bancada, Servente serventes[]);


#endif // SERVENTE_H
