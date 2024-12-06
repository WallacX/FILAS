// gcc main.c bancada.c vasilha.c ingrediente.c usuario.c fila.c servente.c -o programa
// ./programa

#include "fila.h"

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
    #ifdef OS_Windows
        Sleep(10000);
        system("cls");
    #else
        sleep(1);
        system("clear");
    #endif
    
    funcionamentoRU(cardapio, bancadas, filas, serventes);

    imprimeRelatorio(cardapio, bancadas, filas, serventes);

   

    return 0;
}
