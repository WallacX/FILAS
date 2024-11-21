#include "bancada.h"
#include "usuario.h"

int qtdBancadasAtivas = 0;

void iniciaBancada(Bancada *bancada, Ingrediente cardapio[]){
    bancada->identificador = ++qtdBancadasAtivas;
    bancada->qtdUsuariosAtendidos = 0;
    bancada->usuario = NULL;
    bancada->qtdServenteNaBancada = 0;
    
    for(int i = 0; i< TAMCARDAPIO; i++){
        bancada->idServentes[i] = 0;
    }
    
    for(int i = 0; i < TAMCARDAPIO; i++)
        iniciaVasilha(&bancada->vasilhas[i], cardapio[i]);

}
