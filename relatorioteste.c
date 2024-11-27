#include "relatorioteste.h"

void imprimeRelatorio(Servente *serventes, Bancada *bancadas){
    
    for(int i = 0; i < QTDMAXSERVENTEBANCADA; i++){
        printf("Quantidade de usuarios atendidos pelo servente %d: %d\n", serventes[i].id, serventes[i].qtdUsuariosAtendidos);
    }

    for(int i = 0; i < qtdBancadasAtivas; i++){
        printf("Quantidade de usuarios atendidos na bancada %d: %d\n", bancadas[i].identificador, bancadas[i].qtdUsuariosAtendidos);
    }
}
