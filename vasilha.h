#ifndef VASILHA_H
#define VASILHA_H

#include <stdio.h>
#include "ingrediente.h"

#define CAPACIDADE_INGREDIENTE 10000
#define TEMPO_SUBSTITUICAO 3


typedef struct Vasilha{
    Ingrediente ingrediente;
    int qtdRestante;
}Vasilha;

void iniciarVasilha(Vasilha *vasilha, Ingrediente ingrediente);


#endif // VASILHA_H
