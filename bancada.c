#include "bancada.h"


int qtdBancadasAtivas = 0;


void iniciaBancada(Bancada *bancada, Ingrediente cardapio[]){
    bancada->identificador = ++qtdBancadasAtivas;
    bancada->qtdUsuariosAtendidos = 0;
    bancada->usuario = NULL;
    
    for(int i = 0; i < TAMCARDAPIO; i++)
        iniciaVasilha(&bancada->vasilhas[i], cardapio[i]);

}
