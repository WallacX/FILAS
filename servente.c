#include "servente.h"

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

}


int retornaIdServenteDescansado(Servente serventes[]){
    for(int i = 0; i < QTDMAXSERVENTES; i++){
        if(serventes[i].tempoDescansado >= TEMPOMINDESCANSOSERV && serventes[i].bancada == NULL){
            //serventes[i].tempoTrabalhado = 0;
            return serventes[i].id;  
        }
    }
    printf("Todos os serventes estao cansados\n");
    return -1;
}


void checaServentes(Bancada bancadas[], Servente serventes[]){
    for(int i = 0; i < QTDMAXSERVENTES; i++){
        if(serventes[i].bancada == NULL){
            serventes[i].tempoDescansado++;
        }  
        else{
            serventes[i].tempoTrabalhado++;
        } 
    }


    for(int i = 0; i < QTDBANCADAS; i++){
        for(int j = 0; j < QTDMAXSERVENTEBANCADA; j++){
            if(serventes[bancadas[i].idServentes[j]].tempoTrabalhado >= TEMPOMAXTRABALHOSERV){
                trocaServente(&bancadas[i], serventes, j);
            }
        }
    }
}

void trocaServente(Bancada *bancada, Servente serventes[], int posServBanc){//Posição do servente na bancada
    serventes[bancada->idServentes[posServBanc]].tempoTrabalhado = 0;
    if(bancada->qtdServentesBancada == 3){
        serventes[bancada->idServentes[posServBanc]].bancada = NULL;
        bancada->idServentes[posServBanc] = -1;
        bancada->idServentes[posServBanc+1] = -1;     
    }
    else{
        if(bancada->qtdServentesBancada == 4){
            if(posServBanc >= 2){
                serventes[bancada->idServentes[posServBanc]].bancada = NULL;
                bancada->idServentes[posServBanc] = -1;
                bancada->idServentes[posServBanc+1] = -1;   
            }
            else{
                serventes[bancada->idServentes[posServBanc]].bancada = NULL;
                bancada->idServentes[posServBanc] = -1;
            }
        }
        else if(bancada->qtdServentesBancada == 5){
            if(posServBanc >= 4){
                serventes[bancada->idServentes[posServBanc]].bancada = NULL;
                bancada->idServentes[posServBanc] = -1;
                bancada->idServentes[posServBanc+1] = -1;   
            }
            else{
                serventes[bancada->idServentes[posServBanc]].bancada = NULL;
                bancada->idServentes[posServBanc] = -1;
            }
        }
        else{
            serventes[bancada->idServentes[posServBanc]].bancada = NULL;
            bancada->idServentes[posServBanc] = -1;
        }
    }
    
    int id = retornaIdServenteDescansado(serventes);
    serventes[id].bancada = bancada;
    serventes[id].tempoDescansado = 0;
    serventes[id].tempoTrabalhado = 0;
    for(int i = 0; i < TAMCARDAPIO; i++){
        if(bancada->idServentes[i] == -1){
            bancada->idServentes[i] = id;
        }
    }
}


void serveUsuarios(Bancada bancadas[], Servente serventes[]){

    for(int i = 0; i < QTDBANCADAS; i++){
        

        if(bancadas[i].usuario != NULL){

            int tempoUsuarioAtendido = 0; // tempo pro usuario ser atendido
            for(int j = 0; j < TAMCARDAPIO; j++){
                if(bancadas[i].usuario->aceitacao[j] == true){
                    tempoUsuarioAtendido += serventes[bancadas[i].idServentes[j]].tempoAtendimento; //Varre o vetor adicionando o tempo do servente quando o usuario aceita o alimento
                }
            }


            bancadas[i].usuario->tempo++;

            if(bancadas[i].usuario->tempo >= tempoUsuarioAtendido){
                int qtdComidaServida;

                for(int k = 0; k < TAMCARDAPIO; k++){
                    if(bancadas[i].usuario->aceitacao[k] == true){
                        qtdComidaServida = QTDMININGREDIENTES[i] + (rand() % (QTDMAXINGREDIENTES[i] - QTDMININGREDIENTES[i]) + 1);
                        bancadas[i].vasilhas[k].qtdRestante -= qtdComidaServida;
                        totalIngredientesConsumidos[k] += qtdComidaServida;
                    }
                }

                free(bancadas[i].usuario);
                bancadas[i].usuario = NULL;
                bancadas[i].qtdUsuariosAtendidos++;
                bancadas[i].tempoTotalServindo += tempoUsuarioAtendido;
                


            }
        }
    }
}
