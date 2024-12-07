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
    if(bancadas[0].usuario == NULL && qtdUsuariosNasFilas > 0){
        for(int i = 0; i < QTDFILAS; i++){//Procura um usuario vegetariano entre as filas
            if(!filaVazia(&filas[i])){
                if(filas[i].primeiro->usuario->vegetariano == true){
                    Fila *fVegetariano = &filas[i];
                    No *noAux = fVegetariano->primeiro;
                    Usuario *usuario = noAux->usuario;
                    fVegetariano->primeiro = noAux->proximo;
                    fVegetariano->tamanho--; //Diminui a quantidade de usuarios na fila
                    qtdUsuariosNasFilas--; //Diminui a quantidade de total de usuarios nas filas
                    free(noAux); //Libera o nó que armazenava o usuário na fila
                    bancadas[0].usuario = usuario; 
                    break;
                }
            }
        }
    }

    for(int i = 1; i < QTDBANCADAS; i++){
        if(bancadas[i].usuario == NULL && qtdUsuariosNasFilas > 0){
            Fila *filaSorteada = sorteiaFila(filas);
            if(filaSorteada != NULL){
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



Fila *sorteiaFila(Fila filas[]){ //Retorna uma fila aleatória com um usuario não vegetariano
    int vNaoVeg[QTDFILAS]; //Vetor que armazena indices das filas em que o primeiro usuario não é vegetariano
    int cont = 0;

    for(int i = 0; i < QTDFILAS; i++){
        if(!filaVazia(&filas[i])){
            if(filas[i].primeiro->usuario->vegetariano == false){//Checa se o primeiro ususario da fila não é vegetariano
                vNaoVeg[cont] = i; //Armazena o indice da fila no vetor
                cont++;
            }
        }
    }

    if(cont == 0) //Se nenhuma fila tiver um usuario não vegetariano na primeira posição retorna nulo
        return NULL;
    else
        return &filas[vNaoVeg[rand()%cont]]; //Sorteia uma das filas cujo primeiro usuario não é vegetariano
}



void funcionamentoRU(Ingrediente cardapio[], Bancada bancadas[], Fila filas[], Servente serventes[]){

    int clocks = 390;// 1 clock equivale a 1 minuto
    int h = 6, m = 30;
    
    while(h<=23){
        printf("Horario: %02d:%02d\n", h, m);
        m++;
        clocks++;

        if((clocks >= 390 && clocks <= 540) || (clocks >= 660 && clocks <= 870) || (clocks >= 1020 && clocks <= 1170)){//Clocks correspondentes a quantidade de minutos do funcionamento do ru
            printf("----- RU ABERTO -----\n");
            enfileiraUsuarios(cardapio, filas);
            desenfileiraUsuarios(filas, bancadas);
            serveUsuarios(bancadas, serventes);
            checaServentes(bancadas, serventes);
            checaVasilhas(bancadas);
        }
        else if(checaUsuariosNoRU(bancadas)){
            printf("----- RU FECHADO -----\n");
            printf("(Servindo os usuarios)\n");
            desenfileiraUsuarios(filas, bancadas);
            serveUsuarios(bancadas, serventes);
            checaServentes(bancadas, serventes);
            checaVasilhas(bancadas);
        }else if(!(checaUsuariosNoRU(bancadas))){
            printf("----- RU FECHADO -----\n");
            if(clocks > 1170){
                #ifdef OS_Windows
                    Sleep(1000);
                    system("cls");
                #else
                    sleep(1);
                    system("clear");
                    #endif
                printf("----- DIA ENCERRADO -----\n");
                printf("  Relatorio Disponivel!\n");
                break;
            }
                
        }
        

        if(clocks != 0 && m % 60 == 0){
            h++;
            m%=60;
        }

        

        printf("\nBancadas atendendo os usuarios: ");
        for(int i = 0; i < QTDBANCADAS; i++){
            if(bancadas[i].usuario != NULL)
                printf("%d ", bancadas[i].usuario->id);
            else
                printf("0 ");
        }

        printf("\n\nQuantidade total de usuarios nas filas: %d\n", qtdUsuariosNasFilas);
        for(int i = 0; i < QTDFILAS; i++){
            printf("Tamanho da fila %d: %d\n", i+1, filas[i].tamanho);
        }


        printf("\nTotal consumido de cada igrediente:\n");
        for(int i = 0; i < TAMCARDAPIO; i++){
            printf("%s: %.3fKg\n", cardapio[i].nome ,(float)totalIngredientesConsumidos[i] / 1000);
        }
        printf("\n");

        #ifdef OS_Windows
            Sleep(1000);
            system("cls");
        #else
            sleep(1);
            system("clear");
        #endif
    }
}

     
 
bool checaUsuariosNoRU(Bancada bancadas[]){//Confere se há usuarios nas filas e se há usuarios sendo servidos
    if(qtdUsuariosNasFilas > 0) //Caso haja algum usuário em alguma fila retorna verdadeiro
        return true;
    else{
        for(int i = 0; i < QTDBANCADAS; i++){
            if(bancadas[i].usuario != NULL) //Caso encontre algum usuario sendo servido retorna verdadeiro
                return true;
        }
    }
    return false;
}

void imprimeRelatorio(Ingrediente cardapio[], Bancada bancadas[], Fila filas[], Servente serventes[]){//Cria um arquivo .txt e imprime nele o relatório
    FILE *arquivo = fopen("Relatorio_RU.txt", "w");
    int aux1 = 0, aux2 = 0;

    if(arquivo == NULL){
        printf("Erro ao gerar relatorio!\n");
        return;
    }


    fprintf(arquivo, "Quantidade total de usuarios atendidos: %d\n\n", qtdTotalUsuarios);



    for(int i = 0; i < QTDFILAS; i++){
        aux1 += filas[i].tempoDeEsperaTotal;
        aux2 += filas[i].qtdTotalDeUsuarios;
    }
    fprintf(arquivo, "Tempo médio de espera nas filas: %ds\n", aux1 / aux2);

    for(int i = 0; i < QTDFILAS; i++){
        fprintf(arquivo, "Tempo médio de espera na fila %d: %ds\n", i+1, filas[i].tempoDeEsperaTotal / filas[i].qtdTotalDeUsuarios); 
    }
    fprintf(arquivo, "\n");

    
    for(int i = 0; i < QTDBANCADAS; i++){
        aux1 += bancadas[i].tempoTotalServindo;
        aux2 += bancadas[i].qtdUsuariosAtendidos;
    }
    fprintf(arquivo, "Tempo médio de atendimento das bancadas: %ds\n", aux1 / aux2);
    aux1 = 0, aux2 = 0;


    for(int i = 0; i < QTDBANCADAS; i++){
        fprintf(arquivo, "Tempo médio de atendimento na bancada %d: %ds\n", i, bancadas[i].tempoTotalServindo / bancadas[i].qtdUsuariosAtendidos);
        fprintf(arquivo, "Quantidade de usuarios atendidos pela bancada %d: %d\n", i, bancadas[i].qtdUsuariosAtendidos);
    }
    fprintf(arquivo, "\n");


    for(int i = 0; i < TAMCARDAPIO; i++){
        fprintf(arquivo, "Quantidade de %s consumida (%d%% de aceitação): %.3fKg\n", cardapio[i].nome, cardapio[i].grauAceitacao,(float)totalIngredientesConsumidos[i]/1000);
    }
    fprintf(arquivo, "\n");



    for(int i = 0; i < QTDSERVENTES; i++){
        aux1 += serventes[i].tempoAtendimento;
    }
    fprintf(arquivo, "Tempo médio de atendimento dos serventes: %d\n", aux1 / QTDSERVENTES) ;
    aux1 = 0;

    for(int i = 0; i < QTDSERVENTES; i++){
        fprintf(arquivo, "Quantidade de usuarios atendidos pelo servente %02d: %02d\n", serventes[i].id+1, serventes[i].qtdUsuariosAtendidos);
        aux1 += serventes[i].qtdUsuariosAtendidos;
    }
    fprintf(arquivo, "Quantidade média de usúarios atendidos pelos serventes: %d\n", aux1/ QTDSERVENTES);


    fclose(arquivo);
}
