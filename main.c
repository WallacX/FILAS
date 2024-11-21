// gcc main.c bancada.c vasilha.c ingrediente.c usuario.c fila.c servente.c -o programa
// ./programa

#include <stdio.h>
#include "servente.h" 
#include "fila.h"



int main(){
    srand(time(NULL));
    Ingrediente cardapio[TAMCARDAPIO];
    criaCardapio(cardapio);
    imprimeCardapio(cardapio);
    Bancada bancadas[QTDMAXBANCADAS];

    Fila filas[MAXIMODEFILAS];
    Servente serventes[QTDMAXSERVENTES];


    for(int i = 0; i < QTDMAXSERVENTES; i++){
        iniciaServente(&serventes[i], i+1);
        printf("Servente: %d T: %d\n", serventes[i].id, serventes[i].tempoAtendimento);
    }

    for(int i = 0; i < QTDMAXBANCADAS; i++){
        iniciaBancada(&bancadas[i], cardapio);
    }
    
    for(int i = 0; i < MAXIMODEFILAS; i++){
        iniciaFila(&filas[i]);
    }

    
    for(int i = 1; i <= 13; i++){
        Usuario *user = (Usuario *)malloc(sizeof(Usuario));
        iniciaUsuario(user, cardapio);
        printf("Id: %d ~ igd1: %d  igd2: %d igd3: %d igd4: %d igd5: %d igd6: %dVeg: %s\n", user->id, user->aceitacao[0], user->aceitacao[1], user->aceitacao[2], user->aceitacao[3],user->aceitacao[4], user->aceitacao[5], user->vegetariano ? "true" : "false");
        enfileiraUsuario(user, &filas[retornaIndiceMenorFila(filas)]);
    }

    for(int i = 0; i < 5; i++){
        printf("Tamanho da Fila %d : %d\n", i+1, filas[i].tamanho);
    }
    

    return 0;
}
