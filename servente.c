#include "servente.h"

#define QTDMINSERVERNTES 3
#define QTDMAXSERVENTES 36


void iniciaServente(Servente *servente, int id){
    servente->id = id;
    servente->qtdUsuariosAtendidos = 0;
    servente->bancada = NULL;
    servente->tempoAtendimento = rand()%4+3;
    servente->tempoTrabalhado = 0;
    servente->tempoDescansado = 30;
}


void posicionaServente(Bancada *bancada, Servente serventes[]){
    int idServente = retornaIdServenteDescansado(serventes);

    if(idServente!= -1 && !(bancada->qtdServentesBancada >= 6)){
        if(bancada->qtdServentesBancada < 3){
            if(bancada->qtdServentesBancada == 0){
                bancada->idServentes[0] = idServente;
                bancada->idServentes[1] = idServente;

            }else if(bancada->qtdServentesBancada == 1){
                bancada->idServentes[2] = idServente;
                bancada->idServentes[3] = idServente;

            }else{
                bancada->idServentes[4] = idServente;
                bancada->idServentes[5] = idServente;
            }

        }else{
            if(bancada->qtdServentesBancada == 3){
                bancada->idServentes[1] = idServente;

            }else if(bancada->qtdServentesBancada == 4){
                bancada->idServentes[3] = idServente;

            }else{
                bancada->idServentes[5] = idServente;
            }
        }

        
        bancada->qtdServentesBancada++;
        serventes[idServente].bancada = bancada;
        serventes[idServente].tempoDescansado = 0;
        //printf("QTD serventes na bancada: %d\n", bancada->qtdServentesBancada);

    }else
        printf("Nao foi possivel posicionar o servente na bancada!\n");

    bancada->tempoTotalServentes = 0;
    if(bancada->qtdServentesBancada >= 3){
        for(int i = 0; i < QTDMAXBANCADAS; i++){
        bancada->tempoTotalServentes += serventes[bancada->idServentes[i]].tempoAtendimento;
        }
    }
    
}


int retornaIdServenteDescansado(Servente serventes[]){
    for(int i = 0; i <QTDMAXSERVENTES; i++){
        if(serventes[i].tempoDescansado >= 30 && serventes[i].bancada == NULL && serventes[i].tempoTrabalhado < 60)
            return serventes[i].id;    
    }
    printf("Todos os serventes estao cansados\n");
    return -1;
}
