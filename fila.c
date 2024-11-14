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
}

bool filaVazia(Fila *fila){
    if(fila->tamanho == 0)
        return true;
    else
        return false;
}
