#include "usuario.h"

int qtdTotalUsuarios = 0;


void iniciaUsuario(Usuario *usuario, Ingrediente cardapio[]){


    usuario->id = ++qtdTotalUsuarios;
    //define se o usuario será vegetariano ou não.
    int veg = 0;
    veg = rand()%101;
    printf("veg = %d\n", veg);
    if(veg > 80)
        usuario->vegetariano = true;
    else
        usuario->vegetariano = false;

    //define os graus de aceitação do usuario para cada ingrediente.
    int aceita;
    for(int i = 0; i < 6; i++){
        aceita = rand() %81 + 20;
        if(aceita <= cardapio[i].grauAceitacao)
            usuario->aceitacao[i] = true;
        else
            usuario->aceitacao[i] = false;
    }
}
