#include "fila.h"

void iniciaFila(Fila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
    fila->qtdTotalDeUsuarios = 0;
    fila->tempoDeEsperaTotal = 0;
}

bool filaVazia(Fila *fila){
    if(fila->tamanho == 0)
        return true;
    else
        return false;
}





void enfileiraUsuarios(Ingrediente cardapio[], Fila filas[]){
    controlaTempoUsuariosNasFilas(filas); // os usuarios que estão nas filas

    int qtd = rand() % MAXUSUARIOSGERADOSPORSEGUNDO;
    //printf("Qtd usuarios gerados %d\n", qtd);
    int cont = 0;
    while(cont < qtd){
        Usuario *usuario = geraUsuario(cardapio);
        Fila *fila = retornaMenorFila(filas);

        No *aux = (No*)malloc(sizeof(No));
        if(aux == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
        }

        aux->usuario = usuario;
        aux->proximo = NULL;

        if(filaVazia(fila)){
            fila->primeiro = aux;
            fila->ultimo = aux;
        }
        else{
            fila->ultimo->proximo = aux;
            fila->ultimo = aux;
        }
        
        fila->tamanho++;
        fila->qtdTotalDeUsuarios++;
        qtdUsuariosNasFilas++;

        cont++;
    }
}

void controlaTempoUsuariosNasFilas(Fila filas[]){//Adiciona o tam da fila a quantidade de espera total, variável que será utilizada no relatório
    for(int i = 0; i<QTDMAXDEFILAS; i++){
        filas[i].tempoDeEsperaTotal += filas[i].tamanho;
    }
}

Fila *retornaMenorFila(Fila filas[]){
    int menorTamanho = 999;
    int indiceMenorTamanho = -1;

    for(int i = 0; i< QTDMAXDEFILAS; i++){
        if(filas[i].tamanho == 0){
            indiceMenorTamanho = i;
            break;
        }
        else{
            if(filas[i].tamanho < menorTamanho){
                menorTamanho = filas[i].tamanho;
                indiceMenorTamanho = i;
            }
        }
    }
    return &filas[indiceMenorTamanho];
}


void desenfileiraUsuarios(Fila filas[], Bancada bancadas[]){
        for(int i = 0; i < QTDMAXBANCADAS; i++){
            if(qtdUsuariosNasFilas > 0){
                if(bancadas[i].usuario == NULL){
                    Fila *filaSorteada = sorteiaFila(filas);
                    No *noAux = filaSorteada->primeiro;
                    Usuario *usuario = noAux->usuario;
                    filaSorteada->primeiro = noAux->proximo;
                    filaSorteada->tamanho--;
                    qtdUsuariosNasFilas--;
                    free(noAux);
                    bancadas[i].usuario = usuario;
            }
        }
    }
}

Fila *sorteiaFila(Fila filas[]){
    Fila *filaSorteada;
    do{
        filaSorteada = &filas[rand() % QTDMAXDEFILAS];
    }while(filaVazia(filaSorteada));
    return filaSorteada;
}


void serveUsuarios(Bancada bancadas[]){
    for(int i = 0; i < QTDMAXBANCADAS; i++){
        if(bancadas[i].usuario != NULL){
            bancadas[i].usuario->tempo++;

            if(bancadas[i].usuario->tempo >= bancadas[i].tempoTotalServentes){
                int qtdComidaServida;

                for(int j = 0; j < TAMCARDAPIO; j++){
                    if(bancadas[i].usuario->aceitacao[j] == true){
                        qtdComidaServida = QTDMININGREDIENTES[i] + (rand() % (QTDMAXINGREDIENTES[i] - QTDMININGREDIENTES[i]) + 1);
                        bancadas[i].vasilhas[j].qtdRestante -= qtdComidaServida;
                        totalIngredientesConsumidos[j] += qtdComidaServida;
                    }
                }

                free(bancadas[i].usuario);
                bancadas[i].usuario = NULL;
                bancadas[i].qtdUsuariosAtendidos++;

            }
        }
    }
}



void checaServentes(Bancada bancadas[], Servente serventes[]){
    for(int i = 0; i < QTDMAXSERVENTES; i++){
        if(serventes->bancada != NULL)
            serventes[i].tempoTrabalhado++;
        else
            serventes[i].tempoDescansado++;
    }


    for(int i = 0; i < QTDMAXBANCADAS; i++){
        for(int j = 0; j < QTDMAXSERVENTEBANCADA; j++){
            if(serventes[bancadas[i].idServentes[j]].tempoTrabalhado >= 60){
                trocaServente(&bancadas[i], serventes, j);
            }
        }
    }
}

void trocaServente(Bancada *bancada, Servente serventes[], int posServBanc){//Posição do servente na bancada
    printf("Entrou em troca servente\n");
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
                printf("Entrou qtd 5, else\n");
            }
        }
        else{
            serventes[bancada->idServentes[posServBanc]].bancada = NULL;
            bancada->idServentes[posServBanc] = -1;
            printf("Entrou no ultimo else e definiu %d como -1\n", posServBanc);
        }
    }
    
    int aux = retornaIdServenteDescansado(serventes);
    serventes[aux].bancada = bancada;
    serventes[aux].tempoDescansado = 0;
    serventes[aux].tempoTrabalhado = 0;
    for(int i = 0; i < TAMCARDAPIO; i++){
        if(bancada->idServentes[i] == -1){
            bancada->idServentes[i] = aux;
        }
    }
}

void checaVasilhas(Bancada bancadas[]){
    for(int i = 0; i < QTDMAXBANCADAS; i++){
        for(int j = 0; j < TAMCARDAPIO; j++){
            if(bancadas[i].vasilhas[j].qtdRestante < QTDMAXINGREDIENTES[j])
                bancadas[i].vasilhas[j].qtdRestante = CAPACIDADE_INGREDIENTE;
        }
    }
}




void iniciaRU(Ingrediente cardapio[], Bancada bancadas[], Fila filas[], Servente serventes[]){
    for(int i = 0; i < QTDMAXSERVENTES; i++){
        iniciaServente(&serventes[i], i);
        //***printf("Servente: %d T: %d\n", serventes[i].id, serventes[i].tempoAtendimento);
    }

    for(int i = 0; i < QTDMAXBANCADAS; i++){ //Inicia as bancadas e posiciona os serventes
        iniciaBancada(&bancadas[i], cardapio);

        int cont = 0, total;
        total = rand() % 4 + 3;
        
        while(cont != total){
            posicionaServente(&bancadas[i], serventes);
            cont++;
            //***printf("Rand: %d Contador: %d\n", total, cont);
        }
        
    }

    for(int i = 0; i < QTDMAXDEFILAS; i++){
            iniciaFila(&filas[i]);
        }

}