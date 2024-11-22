#include "bancada.h"

int qtdBancadasAtivas = 0;

// Podemos trocar o nome da função para ativa bancada, e ao inves de um 
//identificador(dentro da struct) podemos deixar um bool pra saber se a bancada está ativa ou não

void iniciaBancada(Bancada *bancada, Ingrediente cardapio[]){
    bancada->identificador = qtdBancadasAtivas++;  
    bancada->qtdUsuariosAtendidos = 0;
    bancada->qtdServentesBancada = 0;
    bancada->usuario = NULL;

    for(int i = 0; i < TAMCARDAPIO; i++){
        bancada->idServentes[i] = -1;
    }
    
    for(int i = 0; i < TAMCARDAPIO; i++)
        iniciaVasilha(&bancada->vasilhas[i], cardapio[i]);

}
