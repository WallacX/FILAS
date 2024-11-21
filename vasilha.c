#include "vasilha.h"


void iniciaVasilha(Vasilha *vasilha, Ingrediente ingrediente){
    vasilha->ingrediente = ingrediente; 
    vasilha->qtdRestante = CAPACIDADE_INGREDIENTE;
    printf("Vasilha iniciada\n");
}