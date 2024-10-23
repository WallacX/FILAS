#include "vasilhas.h"
#include <stdio.h>

int main(){
    Vasilha vasilha;
    Bancada bancada;
    iniciarVasilha(&vasilha);
    iniciarBancada(&bancada);
    colocarVasilhaNaBancada(&vasilha, &bancada, 0);
    printf("\n\nNa bancada %d, tem %d gramas na vasilha", bancada.identificador, bancada.vasilhas[0]->qtdRestante);
    return 0;
}
