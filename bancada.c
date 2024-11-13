#include "bancada.h"


int qtdBancadasAtivas = 0;


void iniciarBancada(Bancada *bancada, Ingrediente cardapio[]){
    bancada->identificador = ++qtdBancadasAtivas;
    bancada->qtdUsuariosAtendidos = 0;

    //bancada->usuario = NULL;
    
    
    for(int i = 0; i < TAMCARDAPIO; i++){ //trocar pelo tam cardapio
        iniciarVasilha(&bancada->vasilhas[i], cardapio[i]);
    }
}
