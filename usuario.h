#include <stdbool.h>
#define QUANT_USU_MAX 5                   //Quantidade máxima de usuários que chegam por segundo.

typedef struct Usuario{
    int id;
    bo eVegetariano;
    Bancada *bancada;
    struct usuario *prox;
    //int tempoDeEspera; //Ainda não sei se vai ser necessario.
}Usuario;

void iniciaUsuario (Usuario *usuario, int id);
