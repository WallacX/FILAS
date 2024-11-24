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

            printf("\nO usuario %d serviu-se de %d gramas de %s Restam %d gramas na vasilha.", 
        bancada->usuario->id, qtdComidaServida, bancada->vasilhas[i].ingrediente.nome,
        bancada->vasilhas[i].qtdRestante);
        }
    }
    free(bancada->usuario);
    bancada->usuario = NULL;
}

Fila *sorteiaFila(Fila filas[]){
    Fila *filaSorteada;
    do{
        filaSorteada = &filas[rand() % MAXIMODEFILAS];

    }while(filaVazia(filaSorteada));
    return filaSorteada;
}

Bancada *selecionaBancadaVazia(Bancada bancadas[]){
    
    do{
        for(int i = 1; i<qtdBancadasAtivas; i++){
            if(bancadas[i].usuario == NULL)
                return &bancadas[i];
        }
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


        printf("O usuario %d foi inserido na bancada 0\n", usuario->id);
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
    printf("Entrou em desenfileira\n");
    Fila *filaSorteada = sorteiaFila(filas);
    printf("Tamanho da fila sorteada: %d\n", filaSorteada->tamanho);
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
