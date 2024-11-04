#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "filas.h"

Ingrediente criaIngrediente(int grauAceit, char nome[TAMMAXNOMEINGREDIENTE]){
    Ingrediente novoIngrediente;
    novoIngrediente.grauAceitacao = grauAceit;
    strncpy(novoIngrediente.nome, nome, TAMMAXNOMEINGREDIENTE - 1);
    novoIngrediente.nome[TAMMAXNOMEINGREDIENTE - 1] = '\0';

    return novoIngrediente;
}
void criaCardapio(Ingrediente *cardapio){
int indicesUsados[TOTALINGREDIENTES] = {0};

    for(int i = 0; i < TAMCARDAPIO; i++){
        int indiceAleatorio;

        do {
            indiceAleatorio = rand() % TOTALINGREDIENTES;
        } while (indicesUsados[indiceAleatorio] != 0);

        indicesUsados[indiceAleatorio] = 1;

        int grauAceitacao = rand() % 100 + 1;

        cardapio[i] = criaIngrediente(grauAceitacao, todosIngredientes[indiceAleatorio]); //cria e add ingrediente ao cardapio
    }
}

void imprimeCardapio(Ingrediente *cardapio){
    printf("Cardapio do dia:\n");
    for(int i = 0; i < TAMCARDAPIO; i++){
        printf("Ingrediente: %s, Grau de Aceitacao: %d\n", cardapio[i].nome, cardapio[i].grauAceitacao);
    }
}