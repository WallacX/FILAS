#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"



void iniciaUsuario (Usuario *usuario, int id){
    usuario -> id = id;
    //define se o usuario será vegetariano ou não.
    int vegetariano = rand() % 101;            
    if (vegetariano > 80){
        usuario -> eVegetariano = true;
    }
    else {
        usuario -> eVegetariano = false;
    }
    //define os graus de aceitação do usuario para cada ingrediente.
    for (int i = 0; i < 6; j++){
        usuario -> grauAceitacao[i] = rand() % 101;
    }
    
    usuario -> bancada = NULL;                    

    return;
}
