#include "fila.h"

void iniciaFila(Fila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

int retornaIndiceMenorFila(Fila filas[]){
    int menorTamanho = 999;
    int indiceMenorTamanho = -1;

    for(int i = 0; i< MAXIMODEFILAS; i++){
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
    return indiceMenorTamanho;
}

void enfileiraUsuario(Usuario *usuario, Fila *fila){
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
    qtdUsuariosNasFilas++;
}

bool filaVazia(Fila *fila){
    if(fila->tamanho == 0)
        return true;
    else
        return false;
}



void serveUsuario(Bancada *bancada, Servente serventes[]){
    int qtdComidaServida;
    for(int i = 0; i < TAMCARDAPIO; i++){
        if(bancada->usuario->aceitacao[i] == true){
            //trecho q vai 'travar' o usuario pelo tempo do servente em vasilha[i]
            qtdComidaServida = QTDMININGREDIENTES[i] + (rand() % (QTDMAXINGREDIENTES[i] - QTDMININGREDIENTES[i]) + 1);
            bancada->vasilhas[i].qtdRestante -= qtdComidaServida;
            totalIngredientesConsumidos[i] += qtdComidaServida;

            /*printf("\nO usuario %d serviu-se de %d gramas de %s Restam %d gramas na vasilha.", 
        bancada->usuario->id, qtdComidaServida, bancada->vasilhas[i].ingrediente.nome,
        bancada->vasilhas[i].qtdRestante);*/
        }
    }
    free(bancada->usuario);
    bancada->usuario = NULL;
    bancada->qtdUsuariosAtendidos++;
    //acrescentar o tempo de cada servente nessa função
    checaServentes(bancada, serventes);
    checaVasilhas(bancada);
}

void checaVasilhas(Bancada *bancada){
    for(int i = 0; i < TAMCARDAPIO; i++){
        if(bancada->vasilhas[i].qtdRestante < QTDMAXINGREDIENTES[i]){
            //trecho que vai 'travar' o codigo durante o tempo da troca
            bancada->vasilhas[i].qtdRestante = CAPACIDADE_INGREDIENTE;
        }
    }

}


void checaServentes(Bancada *bancada, Servente serventes[]){
    for(int i = 0; i < TAMCARDAPIO; i++){
        if(serventes[bancada->idServentes[i]].tempoTrabalhado >= 60){
            trocaServente(bancada, serventes, i);
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
    for(int i = 0; i < TAMCARDAPIO; i++){
        if(bancada->idServentes[i] == -1){
            bancada->idServentes[i] = aux;
        }
    }
}


Fila *sorteiaFila(Fila filas[]){
    Fila *filaSorteada;
    do{
        filaSorteada = &filas[rand() % MAXIMODEFILAS];

    }while(filaVazia(filaSorteada));
    return filaSorteada;
}

Bancada *selecionaBancadaVazia(Bancada bancadas[]){
    int aux;
    do{
        aux = rand() % qtdBancadasAtivas + 1;
        if(bancadas[aux].usuario == NULL)
            return &bancadas[aux];

        /*
        for(int i = 2; i<qtdBancadasAtivas; i++){
            if(bancadas[i].usuario == NULL)
                return &bancadas[i];
        }
        */
        
    }while(1);

}


void posicionaUsuarioNaBancada(Usuario *usuario, Bancada bancadas[], Servente serventes[]){
    bool vazia = false;
    if(usuario->vegetariano == true){

        do{
            if(bancadas[0].usuario == NULL){
                vazia = true;
            }
        }while(!(vazia));


        //printf("O usuario %d foi inserido na bancada 0\n", usuario->id);
        bancadas[0].usuario = usuario;
        serveUsuario(&bancadas[0], serventes); 

    }else{
        Bancada *bancadaSelecionada = selecionaBancadaVazia(bancadas);
        
        bancadaSelecionada->usuario = usuario;
        printf("O usuario %d foi inserido na bancada %d\n", usuario->id, bancadaSelecionada->identificador);
        serveUsuario(bancadaSelecionada, serventes);
    }
}


//Mover essa função pro arquivo de bancadas caso possivel

void desenfileiraUsuario(Fila filas[], Bancada bancadas[], Servente serventes[]){
    //printf("Entrou em desenfileira\n");
    Fila *filaSorteada = sorteiaFila(filas);
    //printf("Tamanho da fila sorteada: %d\n", filaSorteada->tamanho);
    No *noAux = filaSorteada->primeiro;
    Usuario *usuario = noAux->usuario;
    filaSorteada->primeiro = noAux->proximo;
    filaSorteada->tamanho--;
    qtdUsuariosNasFilas--;

    if(filaSorteada->primeiro == NULL || filaSorteada->tamanho == 0){
        filaSorteada->ultimo = NULL;
    }

    free(noAux);

    posicionaUsuarioNaBancada(usuario, bancadas, serventes);

}
