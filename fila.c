#include "fila.h"
#include <string.h>

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

Fila* sorteiaFila(Fila *filas){
    int posicaoFila = rand() % MAXIMODEFILAS;
    if(filas == NULL || filas[posicaoFila].tamanho == 0){
        printf("\nFila %d vazia!\n", posicaoFila+1);
        return NULL;
    }

    //printf("\nA fila %d tem tamanho %d. O primeiro da fila eh %d\n", 
    //posicaoFila+1, filas[posicaoFila].tamanho, filas[posicaoFila].primeiro->usuario->id);
    return &filas[posicaoFila];
}

Usuario desenfileiraUsuario(Fila *fila){
    if(fila == NULL){
        bool aceitacaoVazia[6] = {false, false, false, false, false, false};
        Usuario usuarioVazio = {0, false, aceitacaoVazia};
        return usuarioVazio;
    }

    No *no = fila->primeiro;
    Usuario usuario = *(no->usuario);
    fila->primeiro = no->proximo;

    if(fila->primeiro == NULL){
        fila->ultimo == NULL;
    }

    fila->tamanho--;
    free(no->usuario);
    free(no);
    return usuario;
}

void serveUsuario(Fila *filas, Bancada *bancadas, Servente *serventes){
    Fila *filaSorteada = sorteiaFila(filas);
    if(filaSorteada == NULL || bancadas == NULL){
        return;
    }

    Usuario usuarioServido = desenfileiraUsuario(filaSorteada);
    if(usuarioServido.id == 0){
        return;
    }

    Bancada *bancada = NULL;
    if(usuarioServido.vegetariano){
        bancada = &bancadas[0];
        bancada->usuario = &usuarioServido;
    
    }

    else{
        bancada = &bancadas[1];
        bancada->usuario = &usuarioServido;
        
    }

    //printf("\n\nO usuario %d foi posicionado na bancada %d\n", usuarioServido.id, bancada->identificador);

    int qtdIngredientes[6] = {0, 0, 0, 0, 0, 0};
    for(int i=0; i<TAMCARDAPIO; i++){
        if(i == 0 && usuarioServido.aceitacao[i] == true){
            qtdIngredientes[i] = sorteiaQtdServida(QTD_MAX_INGREDIENTE_1, QTD_MIN_INGREDIENTE_1);
        }
        else if(i == 1 && usuarioServido.aceitacao[i] == true)
            qtdIngredientes[i] = sorteiaQtdServida(QTD_MAX_INGREDIENTE_2, QTD_MIN_INGREDIENTE_2);

        else if(i == 2 && usuarioServido.aceitacao[i] == true)
            qtdIngredientes[i] = sorteiaQtdServida(QTD_MAX_INGREDIENTE_3, QTD_MIN_INGREDIENTE_3);
        
        else if(i == 3  && usuarioServido.aceitacao[i] == true)
            qtdIngredientes[i] = sorteiaQtdServida(QTD_MAX_INGREDIENTE_4, QTD_MIN_INGREDIENTE_4);

        else if(i == 4  && usuarioServido.aceitacao[i] == true)
            qtdIngredientes[i] = sorteiaQtdServida(QTD_MAX_INGREDIENTE_5, QTD_MIN_INGREDIENTE_5);
        
        else if(i == 5  && usuarioServido.aceitacao[i] == true)
            qtdIngredientes[i] = sorteiaQtdServida(QTD_MAX_INGREDIENTE_6, QTD_MIN_INGREDIENTE_6);
    
    }

    printf("\n");
    for(int i=0; i<TAMCARDAPIO; i++){
        bancada->vasilhas[i].qtdRestante = bancada->vasilhas[i].qtdRestante - qtdIngredientes[i];
        printf("\nO usuario %d serviu-se de %d gramas de %s.\nRestam %d gramas de %s na vasilha.", 
        usuarioServido.id, qtdIngredientes[i], bancada->vasilhas[i].ingrediente.nome,
        bancada->vasilhas[i].qtdRestante, bancada->vasilhas[i].ingrediente.nome);
    }
}

int sorteiaQtdServida(int qtdMax, int qtdMin){
    int qtdServida = qtdMin + (rand() % (qtdMax - qtdMin + 1));
    return qtdServida;

}
