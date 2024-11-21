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
    for(int i = 0; i < QTDMAXSERVENTES; i++){
        if(serventes[i].bancada == NULL && serventes[i].tempoDescansado >= 30){
            serventes[i].bancada = bancada;


            /*int aux = 0;
            for(int j = 0; j < TAMCARDAPIO; j++){
                
                if(bancada->vasilhas[j].idServente == -1){
                    bancada->vasilhas[j].idServente = serventes[i].id;
                    
                }
                    
            }*/
            
            break;
        }
    }
}
