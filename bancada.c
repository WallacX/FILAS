#include "bancada.h"

void iniciaBancada(Bancada *bancada, Ingrediente cardapio[]){
    bancada->qtdUsuariosAtendidos = 0;
    bancada->qtdServentesBancada = 0;
    bancada->usuario = NULL;
    bancada->tempoTotalServentes = 0;

    for(int i = 0; i < TAMCARDAPIO; i++){
        bancada->idServentes[i] = -1;
    }
    
    for(int i = 0; i < TAMCARDAPIO; i++)
        iniciaVasilha(&bancada->vasilhas[i], cardapio[i]);

}

