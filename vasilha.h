#ifndef VASILHA_H
#define VASILHA_H

#include <stdio.h>
#include "ingrediente.h"

#define CAPACIDADE_INGREDIENTE 5000 //5000 Gramas / 5 Quilos


typedef struct Vasilha{
    Ingrediente ingrediente;
    int qtdRestante; //Quantidade restante na vasilha
}Vasilha;

void iniciaVasilha(Vasilha *vasilha, Ingrediente ingrediente);


#endif // VASILHA_H
