/*
 
quando o ru abre, qtd min e max de bancadas (min =1), min e max de serventes na 
bancada(3 e 6), qtd min e max de serventes, qtd de ingredientes do cardápio (6), 
capacidade de cada vasilha (em gramas), grau de aceitação decada ingrediente, 
tempo de substituição da vasilha

Caracteristicas:
Servente W: numero de identificação, tempo para servir (3s a 6s definido por 
macro), tempo de trabalho (max 60s); tempo de descanso(pelo menos 30s)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Variavéis globais
#define inicia_srand srand(time(NULL))
#define TEMPO_SERVIR rand()%4+3

#define QTDMINSER 3
#define QTDMAXSER 75

int qtdserventes = 0;


typedef struct{
    int *bcd; //ponteiro pra bancada
    int *igd; //ponteiro pro igrediente que está servindo
    int identificacao;
    int tservir;
    int ttrabalhado;
    int tdescanso;
}Servente;

void gera_servente(Servente *servente);