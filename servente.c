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
    servente->id = ++qtdserventes;
    servente->qtdSsuarioAtendidos = 0;
    servente->bancada = NULL;
    servente->tempoAtendimento = 0;
    servente->tempoTrabalhado = 0;
    servente->tempoDescanso = 0;
}Servente;