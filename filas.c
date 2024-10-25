#include "filas.h"


void gera_servente(Servente *servente){
    servente->id = ++qtdserventes;
    servente->qtdSsuarioAtendidos = 0;
    servente->bancada = NULL;
    servente->tempoAtendimento = 0;
    servente->tempoTrabalhado = 0;
    servente->tempoDescanso = 0;
}Servente;


/* FUNÇÃO NÃO FINALIZADA
void insere_servente(Servente *servente,  Bancada *bancada, int ingrediente){
    servente->bcd = bancada->identificador;
    servente->igd = bancada->vasilha[igrediente];//vai receber o igrediente
}
*/
