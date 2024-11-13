// gcc main.c bancada.c vasilha.c ingrediente.c -o programa
// ./programa

#include <stdio.h>
#include "bancada.h"
#include "ingrediente.h"

int main(){

    Ingrediente cardapio[TAMCARDAPIO];
    criaCardapio(cardapio);
    imprimeCardapio(cardapio);
    Bancada b1;
    iniciarBancada(&b1, cardapio);
    
    printf("B1 %d/%d\n", b1.vasilhas->qtdRestante, b1.vasilhas->ingrediente.grauAceitacao);
    printf("QTD: %d\n", QTDMAXBANCADA);
    return 0;
}
