#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#include "ingrediente.h"


#define MAXUSUARIOSGERADOSPORSEGUNDO 2 //Definição da quantidade de usuarios geradas por segundo (-1 por causa do rand)


extern int qtdTotalUsuarios; //Variável global que armazena a quantidade total de usuarios gerados
extern int qtdUsuariosNasFilas; //Variável global que armazena a quantidade atual de usuarios nas filas

typedef struct{
    int id;
    bool vegetariano; //Váriavel que informa se o usuario é vegetariano ou não
    bool aceitacao[TAMCARDAPIO]; //Vetor booleano que informa se o usuario aceita ou não o ingrediente
    int tempo; //Armazena o tempo de espera do usuario na bancada
}Usuario;


Usuario *geraUsuario(Ingrediente cardapio[]);


#endif // USUARIO_H
