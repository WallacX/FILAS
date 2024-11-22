#include <stdio.h>
#include "vasilha.h"
#include <stdbool.h>


void iniciaVasilha(Vasilha *vasilha, Ingrediente ingrediente){
    vasilha->ingrediente = ingrediente; 
    vasilha->qtdRestante = CAPACIDADE_INGREDIENTE;
    printf("Vasilha iniciada\n");
}

//Checar se a qtd de ingrediente em cada vasilha é suficiente.
bool qtdIngredienteSuficiente(Vasilha *vasilha){
    //Caso a quantidade restante seja igual ou menor a 50 gramas retorna falso.
    if (vasilha -> qtdRestante <= 50){
        return false;
    }
    else{
        return true;
    }
}
