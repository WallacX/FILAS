#include <stdbool.h>
#include "bancada.h"
#define QUANT_USU_MAX 5                   //Quantidade máxima de usuários que chegam por segundo.

typedef struct Usuario{
    int id;
    bool eVegetariano;
    int grauAceitacao[6];
    Bancada *bancada;
}Usuario;

void iniciaUsuario (Usuario *usuario, int id);
