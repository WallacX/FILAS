// gcc main.c bancada.c vasilha.c ingrediente.c usuario.c -o programa
// ./programa

#include <stdio.h>
#include "bancada.h"
#include "ingrediente.h"

int main(){

    Ingrediente cardapio[TAMCARDAPIO];
    criaCardapio(cardapio);
    imprimeCardapio(cardapio);
    Bancada bancadas[QTDMAXBANCADAS];

    for(int i = 0; i < QTDMAXBANCADAS; i++){
        iniciaBancada(&bancadas[i], cardapio);
        
    }
    
    Usuario u1;
    iniciaUsuario(&u1, cardapio);
    printf("\n Usuario ~ id: %d  aceitigd1: %d  aceitigd2: %d  Veg: %s\n", u1.id, u1.aceitacao[0], u1.aceitacao[5], u1.vegetariano ? "true" : "false");
    
    printf("\nB1 %d/%d\n", bancadas[0].vasilhas->qtdRestante, bancadas[0].vasilhas[0].ingrediente.grauAceitacao);
    printf("\nB2 %d/%d\n", bancadas[1].vasilhas->qtdRestante, bancadas[1].vasilhas[1].ingrediente.grauAceitacao);
    printf("\nB3 %d/%d\n", bancadas[2].vasilhas->qtdRestante, bancadas[2].vasilhas[2].ingrediente.grauAceitacao);
    printf("\nB4 %d/%d\n", bancadas[3].vasilhas->qtdRestante, bancadas[3].vasilhas[3].ingrediente.grauAceitacao);
    
    return 0;
}
