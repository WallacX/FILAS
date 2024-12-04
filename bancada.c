#include "bancada.h"

void iniciaBancada(Bancada *bancada, Ingrediente cardapio[]){//Inicia as variaveis
    bancada->qtdUsuariosAtendidos = 0;
    bancada->qtdServentesBancada = 0;
    bancada->usuario = NULL;
    bancada->tempoTotalServindo = 0;

    for(int i = 0; i < TAMCARDAPIO; i++){
        bancada->idServentes[i] = -1;
    }
    
    for(int i = 0; i < TAMCARDAPIO; i++)
        iniciaVasilha(&bancada->vasilhas[i], cardapio[i]);

}

void checaVasilhas(Bancada bancadas[]){//Checa se a quantidade dos ingredientes é suficiente para servir o usuario, caso não seja, preenche a vasilha
    for(int i = 0; i < QTDBANCADAS; i++){
        for(int j = 0; j < TAMCARDAPIO; j++){
            if(bancadas[i].vasilhas[j].qtdRestante < QTDMAXINGREDIENTES[j])
                bancadas[i].vasilhas[j].qtdRestante = CAPACIDADE_INGREDIENTE;
        }
    }
}
