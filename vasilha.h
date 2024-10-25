#include "globais.h"

#define CAPACIDADE_INGREDIENTE 10000 //em gramas
#define TEMPO_SUBSTITUICAO 3 //em minutos

typedef struct{
    //Ingrediente *ingrediente;
    int qtdRestante;
}Vasilha;

#define QTD_MIN_BANCADAS 1
#define QTD_MAX_BANCADAS 10
#define QTD_MIN_SERVENTES 3
#define QTD_MAX_SERVENTES 6

static int qtdBancadasAtv = 0; //quantidade de bancadas ativas


typedef struct{
    Vasilha *vasilhas[QTD_MAX_SERVENTES];
    int identificador;
}Bancada;


void iniciarBancada(Bancada *bancada);

void desativarBancada(Bancada *bancada);

void iniciarVasilha(Vasilha *vasilha);

void colocarVasilhaNaBancada(Vasilha *vasilha, Bancada *bancada, int pos);