// gcc main.c bancada.c vasilha.c ingrediente.c usuario.c fila.c servente.c -o programa
// ./programa

#include <stdio.h>
#include <windows.h>
#include "fila.h"

int main(){
    srand(time(NULL));

    //
    Ingrediente cardapio[TAMCARDAPIO];
    criaCardapio(cardapio); 
    Bancada bancadas[QTDMAXBANCADAS];
    Fila filas[QTDMAXDEFILAS];
    Servente serventes[QTDMAXSERVENTES];

    iniciaRU(cardapio, bancadas, filas, serventes); //Inicialização dos vetores/posicionamento dos serventes na bancada


    //**verificar se na hora da troca do servente 
    //as variavéis de trabalho/descanso estão sendo atualizadas corretamente
    //Transformar retornaIdserventeDescansado em retornaServenteDescansado?**


    //cafeDaManha();
    int tempo = 0;
    while(tempo < 150){
        
        system("cls");
        
        printf("Tempo: %d\n", tempo);
        printf("Qtd usuarios nas filas: %d\n", qtdUsuariosNasFilas);
        for(int i = 0; i < QTDMAXDEFILAS; i++){
            if(filas[i].tamanho != 0)
                printf("Fila: %d Tam: %d\n", i, filas[i].tamanho);
        }
        printf("Tempo trabalhado servente B0V0: %d\n", serventes[bancadas[0].idServentes[0]].tempoTrabalhado);
        printf("Tempo descanso servente 35: %d\n", serventes[35].tempoDescansado);

        
        enfileiraUsuarios(cardapio, filas); //Gera os usuarios e os enfileira
        desenfileiraUsuarios(filas, bancadas);
        serveUsuarios(bancadas);
        checaServentes(bancadas, serventes);
        checaVasilhas(bancadas);
        printf("Total consumido de cada igrediente: %d %d %d %d %d %d\n", totalIngredientesConsumidos[0], totalIngredientesConsumidos[1], totalIngredientesConsumidos[2], totalIngredientesConsumidos[3], totalIngredientesConsumidos[4], totalIngredientesConsumidos[5]);
        tempo++;
        Sleep(2000);
    }
    //while(qtdusuariosnafila > 0);    
    //Função para deixar os serventes descansados antes de abrir pro almoço
    return 0;
}