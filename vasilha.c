#include "vasilha.h"

void iniciarVasilha(Vasilha *vasilha){
    vasilha->qtdRestante = CAPACIDADE_INGREDIENTE;
    printf("\nvasilha iniciada");
}

void iniciarBancada(Bancada *bancada){
    bancada->identificador = ++qtdBancadasAtv;
    for(int i=0; i<QTD_MAX_SERVENTES; i++){
        bancada->vasilhas[i] = NULL;
    }
}

void colocarVasilhaNaBancada(Vasilha *vasilha, Bancada *bancada, int pos){
    bancada->vasilhas[pos] = vasilha;
    printf("\nvasilha colocada.");
}