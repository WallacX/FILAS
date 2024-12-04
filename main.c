// gcc main.c bancada.c vasilha.c ingrediente.c usuario.c fila.c servente.c -o programa
// ./programa

#include <stdio.h>
//#include <windows.h>//Ativar quando for no windows para usar a função sleep 
#include <unistd.h> //Linux
#include "fila.h"

//importar stdlib na servente.h e tentar retornar um id aleatorio em retorna id servente

#define TEMPOFUNCIONAMENTOCAFE 150
#define TEMPOFUNCIONAMENTOALMOCO 210
#define TEMPOFUNCIONAMENTOJANTAR 150

int main(){
    srand(time(NULL));

    //Declaração dos vetores com seus respectivos tamanhos
    Ingrediente cardapio[TAMCARDAPIO];
    Bancada bancadas[QTDBANCADAS];
    Fila filas[QTDFILAS];
    Servente serventes[QTDSERVENTES];

    criaCardapio(cardapio); // Criacao do cardapio

    iniciaRU(cardapio, bancadas, filas, serventes); //Inicialização dos vetores/posicionamento dos serventes na bancada


    imprimeCardapio(cardapio);
    sleep(2);
    
    funcionamentoRU(cardapio, bancadas, filas, serventes, TEMPOFUNCIONAMENTOCAFE, 1); //Café da manhã
    funcionamentoRU(cardapio, bancadas, filas, serventes, TEMPOFUNCIONAMENTOALMOCO, 2); //Almoço
    funcionamentoRU(cardapio, bancadas, filas, serventes, TEMPOFUNCIONAMENTOJANTAR, 3); //Jantar

    imprimeRelatorio(cardapio, bancadas, filas, serventes);

   

    return 0;
}
