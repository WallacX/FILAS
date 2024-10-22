#include "filas.h"


void gera_servente(Servente *servente){
    
    servente->bcd = NULL;
    servente->igd = NULL;    
    servente->identificacao = qtdserventes;
    servente->tservir = TEMPO_SERVIR;
    servente->ttrabalhado = 0;
    servente->tdescanso = 0;
    qtdserventes++;
}


/* FUNÇÃO NÃO FINALIZADA
void insere_servente(Servente *servente,  Bancada *bancada, int ingrediente){
    servente->bcd = bancada->identificador;
    servente->igd = bancada->vasilha[igrediente];//vai receber o igrediente
}
*/
