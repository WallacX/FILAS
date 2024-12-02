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
        for(int i = 0; i < QTDBANCADAS; i++){
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


void iniciaRU(Ingrediente cardapio[], Bancada bancadas[], Fila filas[], Servente serventes[]){
    for(int i = 0; i < QTDMAXSERVENTES; i++){
        iniciaServente(&serventes[i], i);
        //***printf("Servente: %d T: %d\n", serventes[i].id, serventes[i].tempoAtendimento);
    }

    for(int i = 0; i < QTDBANCADAS; i++){ //Inicia as bancadas e posiciona os serventes
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


void imprimeRelatorio(Ingrediente cardapio[], Bancada bancadas[], Fila filas[], Servente serventes[]){
    FILE *arquivo = fopen("Relatorio_RU.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao escrever relatorio.\n");
        return;
    }

    //qtdTotalUsuarios
    //filas[i].tempoDeEsperaTotal / filas[i].qtdTotalDeUsuarios  ->tempo de espera medio de cada fila
    //bancadas[i].qtdUsuariosAtendidos
    //bancadas[i].qtdUsuariosAtendidos / (bancadadas[i].tempoAtendimentoTotal) -> criar essa variavel;


    //fprintf(arquivo, "Quai")

    fclose(arquivo);
}
