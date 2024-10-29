#include <stdio.h>
#include <stdbool.h>


#define QTD_MAX_USUARIOS 5   //Quantidade máxima de usuários que chegam por segundo.

typedef struct Usuario{
    int id;
    bool eVegetariano;
    int tempoEsperaFila;
}Usuario;

void iniciaUsuario (Usuario *usuario, int id);