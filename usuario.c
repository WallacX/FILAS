#include "usuario.h"

int qtdTotalUsuarios = 0;
int qtdUsuariosNasFilas = 0;


Usuario *geraUsuario(Ingrediente cardapio[]){
    Usuario *usuario = (Usuario *)malloc(sizeof(Usuario));
    
    int veg = rand()%101; //define se o usuario será vegetariano ou não.
    if(veg > 80)
        usuario->vegetariano = true;
    else
        usuario->vegetariano = false;

    //define os graus de aceitação do usuario para cada ingrediente.
    int aceita;
    for(int i = 0; i < 6; i++){
        aceita = rand() %81 + 20; // Garante que a aceitação do usuario é pelo menos 20 
        if(aceita <= cardapio[i].grauAceitacao)
            usuario->aceitacao[i] = true;
        else
            usuario->aceitacao[i] = false;
    }

    usuario->tempo = 0;

    qtdTotalUsuarios++;
    return usuario;
}
