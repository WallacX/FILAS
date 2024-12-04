#include "fila.h"


void iniciaRU(Ingrediente cardapio[], Bancada bancadas[], Fila filas[], Servente serventes[]){
    for(int i = 0; i < QTDSERVENTES; i++){
        iniciaServente(&serventes[i], i);
    }

    for(int i = 0; i < QTDBANCADAS; i++){ //Inicializa as bancadas
        iniciaBancada(&bancadas[i], cardapio);

        int cont = 0, total;
        total = rand() % 4 + 3; //Gera de forma aleatoria a quantidade de serventes que estarão na posicionados na bancada
        
        while(cont != total){
            posicionaServente(&bancadas[i], serventes);
            cont++;
        }
        
    }

    for(int i = 0; i < QTDFILAS; i++){
            iniciaFila(&filas[i]);
        }
}


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





void enfileiraUsuarios(Ingrediente cardapio[], Fila filas[]){//Gera e enfileira os usuários
    controlaTempoUsuariosNasFilas(filas);

    int qtd = rand() % MAXUSUARIOSGERADOSPORSEGUNDO; //Gera aleatoriamente a quantidade de usuarios
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

void controlaTempoUsuariosNasFilas(Fila filas[]){//Adiciona o tamanho da fila a quantidade de espera total, variável que será utilizada no relatório
    for(int i = 0; i<QTDFILAS; i++){
        filas[i].tempoDeEsperaTotal += filas[i].tamanho;
    }
}

Fila *retornaMenorFila(Fila filas[]){//Retorna um ponteiro para a menor fila
    int menorTamanho = 999;
    int indiceMenorTamanho = -1;

    for(int i = 0; i< QTDFILAS; i++){
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


void desenfileiraUsuarios(Fila filas[], Bancada bancadas[]){//Desenfileira um usuario e posiciona em uma bancada vazia
        for(int i = 0; i < QTDBANCADAS; i++){
            if(qtdUsuariosNasFilas > 0){
                if(bancadas[i].usuario == NULL){
                    Fila *filaSorteada = sorteiaFila(filas);
                    No *noAux = filaSorteada->primeiro;
                    Usuario *usuario = noAux->usuario;
                    filaSorteada->primeiro = noAux->proximo;
                    filaSorteada->tamanho--;
                    qtdUsuariosNasFilas--;
                    free(noAux); //Libera o nó que armazenava o usuário na fila
                    bancadas[i].usuario = usuario;
            }
        }
    }
}





Fila *sorteiaFila(Fila filas[]){//Retorna uma fila aleatória
    Fila *filaSorteada;
    do{
        filaSorteada = &filas[rand() % QTDFILAS];
    }while(filaVazia(filaSorteada));
    return filaSorteada;
}



void funcionamentoRU(Ingrediente cardapio[], Bancada bancadas[], Fila filas[], Servente serventes[], int duracao, int turno){
    int tempo = 0;
    int h = -1, m = -1;

    if(turno == 1){
        h = 6;
        m = 30;
    }else if(turno == 2){
        h = 11;
        m = 0;
    }else{
        h = 17;
        m = 0;
    }
    

    while(tempo <= duracao){
        enfileiraUsuarios(cardapio, filas);
        desenfileiraUsuarios(filas, bancadas);
        serveUsuarios(bancadas, serventes);
        checaServentes(bancadas, serventes);
        checaVasilhas(bancadas);


        if(tempo != 0 && m % 60 == 0){
            h++;
            m%=60;
        }
        printf("Tempo: %02d:%02d\n", h, m);
        m++;
        tempo++;


        printf("Qtd usuarios nas filas: %d\n", qtdUsuariosNasFilas);
                for(int i = 0; i < QTDFILAS; i++){
                    if(filas[i].tamanho != 0){
                        printf("Fila: %d Tam: %d\n", i, filas[i].tamanho);
                    }
                }
                    

        printf("Total consumido de cada igrediente: ");
        for(int i = 0; i < TAMCARDAPIO; i++){
            printf("%dg ", totalIngredientesConsumidos[i]);
        }
        printf("\n");

        
        sleep(1);
        system("clear");//Linux
        //system("cls"); Windows
        
        
        
        
    
        
        
        //Sleep(2000); Windows
        //sleep(1); Linux
    }

    
    //Fazer uma checagem para caso o usuario esteja sendo servido
    while(qtdUsuariosNasFilas > 0){
        desenfileiraUsuarios(filas, bancadas);
        serveUsuarios(bancadas, serventes);
        checaServentes(bancadas, serventes);
        checaVasilhas(bancadas);


        if(tempo != 0 && m % 60 == 0){
            h++;
            m%=60;
        }
        printf("Tempo: %02d:%02d\n", h, m);
        m++;
        tempo++;


        printf("Qtd usuarios nas filas: %d\n", qtdUsuariosNasFilas);
                for(int i = 0; i < QTDFILAS; i++){
                    if(filas[i].tamanho != 0){
                        printf("Fila: %d Tam: %d\n", i, filas[i].tamanho);
                    }
                }

        printf("Total consumido de cada igrediente: ");
        for(int i = 0; i < TAMCARDAPIO; i++){
            printf("%dg ", totalIngredientesConsumidos[i]);
        }
        printf("\n");

        
        sleep(1);
        system("clear");//Linux
        //system("cls"); Windows
        
        
        //Sleep(1000); Windows
        //sleep(1); //Linux
    }    



}


void imprimeRelatorio(Ingrediente cardapio[], Bancada bancadas[], Fila filas[], Servente serventes[]){
    FILE *arquivo = fopen("Relatorio_RU.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao escrever relatorio.\n");
        return;
    }

    fprintf(arquivo, "Quantidade Total de Usuarios: %d\n", qtdTotalUsuarios);

    for(int i = 0; i < QTDFILAS; i++){
        fprintf(arquivo, "Tempo médio de espera na fila %d: %ds\n", i, filas[i].tempoDeEsperaTotal / filas[i].qtdTotalDeUsuarios); 
    }
    fprintf(arquivo, "\n");
    
    for(int i = 0; i < QTDBANCADAS; i++){
        fprintf(arquivo, "Tempo médio de espera na bancada %d: %ds\n", i, bancadas[i].tempoTotalServindo / bancadas[i].qtdUsuariosAtendidos);
        fprintf(arquivo, "Quantidade de usuarios atendidos pela bancada %d: %d\n", i, bancadas[i].qtdUsuariosAtendidos);
    }
    fprintf(arquivo, "\n");

    for(int i = 0; i < TAMCARDAPIO; i++){
        fprintf(arquivo, "Quantidade de %s consumida: %dg\n", cardapio[i].nome, totalIngredientesConsumidos[i]);
    }
    fprintf(arquivo, "\n");

    for(int i = 0; i < QTDSERVENTES; i++){
        fprintf(arquivo, "Quantidade de usuarios atendidos pelo servente %d: %d\n", serventes[i].id, serventes[i].qtdUsuariosAtendidos);
    }

    fclose(arquivo);
}
