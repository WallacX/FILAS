#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#include "ingrediente.h"


#define MAXUSUARIOSGERADOSPORSEGUNDO 2


extern int qtdTotalUsuarios;
extern int qtdUsuariosNasFilas;

typedef struct{
    int id;
    bool vegetariano;
    bool aceitacao[TAMCARDAPIO];
    int tempo;
}Usuario;


Usuario *geraUsuario(Ingrediente cardapio[]);


#endif // USUARIO_H
