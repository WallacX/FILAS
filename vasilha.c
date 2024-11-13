#include "vasilha.h"


void iniciarVasilha(Vasilha *vasilha, Ingrediente ingrediente){
    vasilha->ingrediente = ingrediente; 
    vasilha->qtdRestante = CAPACIDADE_INGREDIENTE;
    printf("\nvasilha iniciada");
}

