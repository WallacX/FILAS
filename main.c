#include "filas.h"

int main(){
    Ingrediente cardapio[TAMCARDAPIO];
    srand(time(NULL)); 

    criaCardapio(cardapio);
    imprimeCardapio(cardapio);

    return 0;
}