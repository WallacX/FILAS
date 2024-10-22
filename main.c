#include "filas.c"

int main(){
    inicia_srand;

    Servente aux[8+2];

    gera_servente(&aux[0]);
    gera_servente(&aux[1]);
    gera_servente(&aux[2]);
    gera_servente(&aux[3]);
    gera_servente(&aux[4]);
    gera_servente(&aux[5]);
    gera_servente(&aux[6]);
    gera_servente(&aux[7]);
    gera_servente(&aux[8]);
    gera_servente(&aux[8+1]);


    printf("Tempos de servir: %d %d %d %d %d %d %d %d %d %d", aux[0].tservir, aux[1].tservir, aux[2].tservir, aux[3].tservir, aux[4].tservir, aux[5].tservir, aux[6].tservir, aux[7].tservir, aux[8].tservir, aux[8+1].tservir);
    return 0;
}



/*
Definir macros para: os horários de funcionamento, qtd maxima de usuarios
que chegam no RU por segundo o tempo que cada servente vai servir, qtd de filas 
quando o ru abre, qtd min e max de bancadas (min = 1), min e max de serventes na 
bancada(3 e 6), qtd min e max de serventes, qtd de ingredientes do cardápio (6), 
capacidade de cada vasilha (em gramas), grau de aceitação decada ingrediente, 
tempo de substituição da vasilha 


Caracteristicas:
Servente W: numero de identificação, tempo para servir (3s a 6s definido por 
macro), tempo de trabalho (max 60s); tempo de descanso(pelo menos 30s)

Usuario A: numero de matricula, vegetariano(bool - definido aleatoriamente)

Vasilha I: Capacidade

Bancadas P:

Ingredientes C: "Grau de aceitação" (definido por macro)

*/
