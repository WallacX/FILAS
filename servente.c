#include "servente.h"

void iniciaServente(Servente *servente, int id){
    servente->id = id;
    servente->qtdUsuariosAtendidos = 0;
    servente->bancada = NULL;
    servente->tempoAtendimento = rand()%4+3;
    servente->tempoTrabalhado = 0;
    servente->tempoDescansado = 30;
}


void posicionaServente(Bancada *bancada, Servente serventes[]){ //Posiciona um servente na bancada respeitando a seguinte estrutura (112233) -> (142536)

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
    }else
        printf("Nao foi possivel posicionar o servente na bancada!\n");
}


int retornaIdServenteDescansado(Servente serventes[]){//Retorna aleatoriamente o id de algum servente descansado
    int cont = 0;
    int idDescansados[QTDSERVENTES] = {-1}; //Cria um vetor que vai armazenar os indices dos serventes descansados

    for(int i = 0; i < QTDSERVENTES; i++){
        if(serventes[i].tempoDescansado >= TEMPOMINDESCANSOSERVENTE && serventes[i].bancada == NULL){
            idDescansados[cont] = i; //Armazena o indice do servente descansado no vetor
            cont++;
        } 
    }
    return serventes[idDescansados[rand()%cont]].id; 
}


void checaServentes(Bancada bancadas[], Servente serventes[]){//Checa se os serventes estão dentro do limite de tempo máximo trabalhado e troca os serventes caso seja nescessário
    for(int i = 0; i < QTDSERVENTES; i++){//Aumenta os contadores de trabalho/descanso dos serventes
        if(serventes[i].bancada == NULL){
            serventes[i].tempoDescansado++;
        }  
        else{
            serventes[i].tempoTrabalhado++;
        } 
    }


    for(int i = 0; i < QTDBANCADAS; i++){//Analisa cada bancada, e, caso o servente tenha chegado ao tempo limite de trabalho, substitui o servente
        for(int j = 0; j < QTDMAXSERVENTEBANCADA; j++){
            if(serventes[bancadas[i].idServentes[j]].tempoTrabalhado >= TEMPOMAXTRABALHOSERVENTE){
                trocaServente(&bancadas[i], serventes, j);
            }
        }
    }
}

void trocaServente(Bancada *bancada, Servente serventes[], int posServBanc){//Troca o servente que atingiu o tempo máximo de trabalho de acordo com a posição dele na bancada e da quantidade de serventes na bancada
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


void serveUsuarios(Bancada bancadas[], Servente serventes[]){//Aumenta o contador dos usuarios e caso tenha atingido a quantidade correta, serve o usuario

    for(int i = 0; i < QTDBANCADAS; i++){ //Passa por todas as bancadas
        if(bancadas[i].usuario != NULL){ //Apenas as bancadas que estão com algum usuario

            int tempoUsuarioAtendido = 0; //Variavel que armazena o tempo pro usuario ser atendido
            for(int j = 0; j < TAMCARDAPIO; j++){
                if(bancadas[i].usuario->aceitacao[j] == true){
                    tempoUsuarioAtendido += serventes[bancadas[i].idServentes[j]].tempoAtendimento; //Varre o vetor adicionando o tempo do servente quando o usuario aceita o alimento
                }
            }

            bancadas[i].usuario->tempo++; //Aumenta o tempo que o usuario está na bancada

            if(bancadas[i].usuario->tempo >= tempoUsuarioAtendido){ //Se o tempo de espera do usuario já é suficiente, então serve a comida
                int qtdComidaServida;

                for(int k = 0; k < TAMCARDAPIO; k++){
                    if(bancadas[i].usuario->aceitacao[k] == true){
                        qtdComidaServida = QTDMININGREDIENTES[k] + (rand() % (QTDMAXINGREDIENTES[k] - QTDMININGREDIENTES[k]) + 1);
                        bancadas[i].vasilhas[k].qtdRestante -= qtdComidaServida;
                        totalIngredientesConsumidos[k] += qtdComidaServida;
                    }
                }

                free(bancadas[i].usuario); //Libera a memória que o usuario estava armazenando
                bancadas[i].usuario = NULL; //Aponta o ponteiro da bancada para nulo
                bancadas[i].qtdUsuariosAtendidos++; //Aumenta a quantidade de usuarios atendidos pela bancada
                bancadas[i].tempoTotalServindo += tempoUsuarioAtendido; //Adiciona o tempo que o usuario demorou para ser servido ao tempo total que a bancada serviu


                atualizaContadorServentes(&bancadas[i], serventes);

            }
        }
    }
}



void atualizaContadorServentes(Bancada *bancada, Servente serventes[]){//Atualiza o contador de usuarios atendidos de cada servente de acordo com a quantidade de serventes na bancada
    if(bancada->qtdServentesBancada == 3){
        serventes[bancada->idServentes[0]].qtdUsuariosAtendidos++;
        serventes[bancada->idServentes[2]].qtdUsuariosAtendidos++;
        serventes[bancada->idServentes[4]].qtdUsuariosAtendidos++;

    }else if(bancada->qtdServentesBancada == 4){
        serventes[bancada->idServentes[0]].qtdUsuariosAtendidos++;
        serventes[bancada->idServentes[1]].qtdUsuariosAtendidos++;
        serventes[bancada->idServentes[2]].qtdUsuariosAtendidos++;
        serventes[bancada->idServentes[4]].qtdUsuariosAtendidos++;

    }else if(bancada->qtdServentesBancada == 5){
        serventes[bancada->idServentes[0]].qtdUsuariosAtendidos++;
        serventes[bancada->idServentes[1]].qtdUsuariosAtendidos++;
        serventes[bancada->idServentes[2]].qtdUsuariosAtendidos++;
        serventes[bancada->idServentes[3]].qtdUsuariosAtendidos++;
        serventes[bancada->idServentes[4]].qtdUsuariosAtendidos++;

    }else if(bancada->qtdServentesBancada == 6){
        for(int i = 0; i < TAMCARDAPIO; i++){
            serventes[bancada->idServentes[i]].qtdUsuariosAtendidos++;
        }   
    }
}
