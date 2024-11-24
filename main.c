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
        iniciaServente(&serventes[i], i);
        //printf("Servente: %d T: %d\n", serventes[i].id, serventes[i].tempoAtendimento);
    }

    for(int i = 0; i < QTDMAXBANCADAS; i++){
        iniciaBancada(&bancadas[i], cardapio);

        int cont = 0, total;
        total = rand() % 4 + 3;
        
        while(cont != total){
            posicionaServente(&bancadas[i], serventes);
            cont++;
            //printf("Rand: %d Contador: %d\n", total, cont);
        }
        
    }
    
    for(int i = 0; i < MAXIMODEFILAS; i++){
        iniciaFila(&filas[i]);
    }

    for(int i = 0; i<15; i++){
        printf("Servente %d: %s\n",i , serventes[i].bancada ? "true" : "false");
    }

    for(int i = 0; i < QTDMAXBANCADAS; i++){
        printf("Bancada %d: ", i);
        for(int j = 0; j < TAMCARDAPIO; j++){
            printf("%d ", bancadas[i].idServentes[j]);
        }
        printf("\n");
    }
    
    for(int i = 1; i <= 13; i++){
        Usuario *user = (Usuario *)malloc(sizeof(Usuario));
        iniciaUsuario(user, cardapio);
        //printf("Id: %d ~ igd1: %d  igd2: %d igd3: %d igd4: %d igd5: %d igd6: %d  Veg: %s\n", user->id, user->aceitacao[0], user->aceitacao[1], user->aceitacao[2], user->aceitacao[3],user->aceitacao[4], user->aceitacao[5], user->vegetariano ? "true" : "false");
        enfileiraUsuario(user, &filas[retornaIndiceMenorFila(filas)]);
    }

    for(int i = 0; i < 5; i++){
        //printf("Tamanho da Fila %d : %d\n", i+1, filas[i].tamanho);
    }
    
    //printf("Qtd bancadas ativas: %d\n", qtdBancadasAtivas);

    int cont = 0;
    while(qtdUsuariosNasFilas > 5){
        //printf("While Cont = %d\n", cont);
        desenfileiraUsuario(filas, bancadas, serventes);
        cont++;        
    }
    
    serventes[0].tempoTrabalhado = 60;
    serventes[6].tempoTrabalhado = 70;
    serventes[8].tempoTrabalhado = 80;
    

    while(qtdUsuariosNasFilas > 0){
        //printf("While Cont = %d\n", cont);
        desenfileiraUsuario(filas, bancadas, serventes);
        cont++;        
    }

    printf("While Cont = %d\n", cont);


    for(int i = 0; i < QTDMAXBANCADAS; i++){
        printf("Bancada %d: ", i);
        for(int j = 0; j < TAMCARDAPIO; j++){
            printf("%d ", bancadas[i].idServentes[j]);
        }
        printf("\n");
    }


    for(int i = 0; i<15; i++){
        printf("Servente %d: %s\n",i , serventes[i].bancada ? "true" : "false");
    }


    printf("\n\n");
    for(int i = 0; i < TAMCARDAPIO; i++){
        //printf("Qtd do igd %d consumida: %d gramas\n", i, totalIngredientesConsumidos[i]);
    }
    

    return 0;
}
