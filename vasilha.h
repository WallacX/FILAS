#ifndef VASILHA_H
#define VASILHA_H

#include <stdbool.h>
#include "ingrediente.h"

#define CAPACIDADE_INGREDIENTE 10000
#define TEMPO_SUBSTITUICAO 3

typedef struct Vasilha{
    Ingrediente ingrediente;
    int qtdRestante;
}Vasilha;

void iniciaVasilha(Vasilha *vasilha, Ingrediente ingrediente);

bool qtdIngredienteSuficiente(Vasilha *vasilha);

#endif // VASILHA_H
