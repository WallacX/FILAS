/*
 
quando o ru abre, qtd min e max de bancadas (min =1), min e max de serventes na 
bancada(3 e 6), qtd min e max de serventes, qtd de ingredientes do cardápio (6), 
capacidade de cada vasilha (em gramas), grau de aceitação decada ingrediente, 
tempo de substituição da vasilha

Caracteristicas:
Servente W: numero de identificação, tempo para servir (3s a 6s definido por 
macro), tempo de trabalho (max 60s); tempo de descanso(pelo menos 30s)
*/


//Variavéis globais
#include "servente.h"


void gera_servente(Servente *servente){
    
    servente->id = ++qtdServentes;
    servente->qtdSsuarioAtendidos = 0;
    servente->bancada = NULL;
    servente->tempoAtendimento = TEMPO_SERVIR;
    servente->tempoTrabalhado = 0;
    servente->tempoDescanso = 0;
}Servente;


Servente *geraServente(){

    if(qtdServentes < QTDMAXSERVENTES){
        srand(time(NULL));
        Servente *aux = (Servente *)malloc(sizeof(Servente));
        aux->id = ++qtdServentes;
        aux->qtdSsuarioAtendidos = 0;
        aux->bancada = NULL;
        aux->tempoAtendimento = TEMPO_SERVIR;
        aux->tempoTrabalhado = 0;
        aux->tempoDescanso = 0;
        return aux;
    }
    else{
        printf("Qtd maxima de serventes criada\n");
        return NULL;
    }
    
}

int main(){
    Servente s1;

    gera_servente(&s1);
    printf("Tempo s1: %d", s1.tempoAtendimento);
    
    return 0;
}
