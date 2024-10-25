#include "usuario.h"


void iniciaUsuario (Usuario *usuario, int id){
    usuario -> id = id;

    int vegetariano = rand() % 101;
    if (vegetariano > 80){
        usuario -> eVegetariano = true;
    }
    else {
        usuario -> eVegetariano = false;
    }
    
    usuario -> bancada = NULL;
    usuario -> prox = NULL;

    return;
}