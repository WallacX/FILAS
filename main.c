// gcc main.c bancada.c vasilha.c ingrediente.c usuario.c fila.c servente.c -o programa
// ./programa

#include <stdio.h>
//#include <windows.h>//Ativar quando for no windows para usar a função sleep 
#include <unistd.h> //Linux
#include "fila.h"

int main(){
    srand(time(NULL));

    
    Ingrediente cardapio[TAMCARDAPIO];
    criaCardapio(cardapio); 
    Bancada bancadas[QTDBANCADAS];
    Fila filas[QTDMAXDEFILAS];
    Servente serventes[QTDMAXSERVENTES];

    iniciaRU(cardapio, bancadas, filas, serventes); //Inicialização dos vetores/posicionamento dos serventes na bancada


    //**verificar se na hora da troca do servente 
    //as variavéis de trabalho/descanso estão sendo atualizadas corretamente
    //Transformar retornaIdserventeDescansado em retornaServenteDescansado?**


    //cafeDaManha();
    int tempo = 0;
    while(tempo <= 150){
        
        system("clear");//Linux
        //system("cls"); Windows
        
        
        printf("Tempo: %d\n", tempo);
        printf("Qtd usuarios nas filas: %d\n", qtdUsuariosNasFilas);
        for(int i = 0; i < QTDMAXDEFILAS; i++){
            if(filas[i].tamanho != 0)
                printf("Fila: %d Tam: %d\n", i, filas[i].tamanho);
        }
        printf("Tempo Trab/Desc servente 0: %d %d\n", serventes[0].tempoTrabalhado, serventes[0].tempoDescansado);
        printf("Tempo Trab/Desc servente 18: %d %d\n", serventes[18].tempoTrabalhado, serventes[18].tempoDescansado);
        printf("Tempo Trab/Desc servente %d: %d %d\n",QTDMAXSERVENTES-1, serventes[QTDMAXSERVENTES-1].tempoTrabalhado, serventes[QTDMAXSERVENTES-1].tempoDescansado);
        printf("Qtd usuarios atendidos pela b0: %d\n", bancadas[0].qtdUsuariosAtendidos);

        enfileiraUsuarios(cardapio, filas); //Gera os usuarios e os enfileira
        desenfileiraUsuarios(filas, bancadas);
        serveUsuarios(bancadas);
        checaServentes(bancadas, serventes);
        checaVasilhas(bancadas);
        printf("Total consumido de cada igrediente: %d %d %d %d %d %d\n", totalIngredientesConsumidos[0], totalIngredientesConsumidos[1], totalIngredientesConsumidos[2], totalIngredientesConsumidos[3], totalIngredientesConsumidos[4], totalIngredientesConsumidos[5]);
        tempo++;
        

        for(int i = 0; i < QTDBANCADAS; i++){
            printf("Bancada %d: ", i);
            for(int j = 0; j < QTDMAXSERVENTEBANCADA; j++){
                printf("%d ", bancadas[i].idServentes[j]);
            }
            printf("\n");
        }
        //Sleep(2000); Windows
        if(tempo == 59|| tempo == 60|| tempo == 120 || tempo == 180 || tempo == 240)
            sleep(5); //Linux
    }
    //while(qtdusuariosnafila > 0);    
    //Função para deixar os serventes descansados antes de abrir pro almoço



   

    return 0;
}
