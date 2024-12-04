#include "ingrediente.h"

int totalIngredientesConsumidos[6] = {0};  
const int QTDMAXINGREDIENTES[6] = {200, 220, 300, 150, 250, 280}; 
const int QTDMININGREDIENTES[6] = {30, 20, 50, 10, 40, 60};

const char *todosIngredientes[] = {
    "Arroz", "Feijao", "Carne", "Salada", "Macarrao", "Frango",
    "Peixe", "Legumes", "Batata", "Ovo", "Sopa", "Fruta"
};

void criaCardapio(Ingrediente cardapio[]){
    int indicesUsados[TOTALINGREDIENTES] = {0};

    for(int i = 0; i < TAMCARDAPIO; i++){
        int indiceAleatorio;

        do{
            indiceAleatorio = rand() % TOTALINGREDIENTES;
        }while(indicesUsados[indiceAleatorio] != 0);

        indicesUsados[indiceAleatorio] = 1;

        int grauAceitacao = rand() % 61 + 40; //Define como 40 o minimo de aceitação para cada ingrediente

        cardapio[i] = criaIngrediente(grauAceitacao, todosIngredientes[indiceAleatorio]); //Cria e adiciona o ingrediente ao cardapio
    }
}

Ingrediente criaIngrediente(int grauAceit, const char nome[]){
    Ingrediente novoIngrediente;
    novoIngrediente.grauAceitacao = grauAceit;
    strncpy(novoIngrediente.nome, nome, TAMMAXNOMEINGREDIENTE - 1);
    novoIngrediente.nome[TAMMAXNOMEINGREDIENTE - 1] = '\0';

    return novoIngrediente;
}

void imprimeCardapio(Ingrediente cardapio[]){
    printf("Cardapio do dia:\n");
    for(int i = 0; i < TAMCARDAPIO; i++){
        printf("Ingrediente: %s, Grau de Aceitacao: %d%%\n", cardapio[i].nome, cardapio[i].grauAceitacao);
    }
}
