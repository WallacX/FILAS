#include <stdio.h>
#include "bancada.h"

#define inicia_srand srand(time(NULL))
#define TEMPO_SERVIR rand()%4+3

#define QTDMINSER 3
#define QTDMAXSERVENTES 30

int qtdserventes = 0;


typedef struct{
    int id;
    int qtdSsuarioAtendidos;
    Bancada *bancada;
    int tempoAtendimento;
    int tempoTrabalhado;
    int tempoDescanso;
}Servente;

void gera_servente(Servente *servente);



/* FUNÇÃO NÃO FINALIZADA
void insere_servente(Servente *servente,  Bancada *bancada, int ingrediente){
    servente->bcd = bancada->identificador;
    servente->igd = bancada->vasilha[igrediente];//vai receber o igrediente
}
*/
