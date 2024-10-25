#include "bancada.h"

void iniciarBancadas(Bancada *bancada){
    for(int i = 0; i <= QTDMAXSERVENTEBANCADA; i++){
        bancada->vasilha[i] = NULL;
    }

void ativarBancada(Bancada *bancada, int identificador);

void desativarBancada(Bancada *bancada, int identificador);