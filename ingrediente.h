#include <stdio.h>

#define inicia_srand srand(time(NULL))
#define ACEITACAOINGREDIENTE1 rand()%51+50 


//#define NPROBINGREDIENTE
//#define QTDMININGREDIENTE
//#define QTDMAXINGREDIENTE
#define TAMCARDAPIO 6

typedef struct{
    int grauAceitacao ;
    char nome[15];
}Ingrediente;

//void criaIngrediente(Ingrediente *ingrediente);

//void defineCardapio();