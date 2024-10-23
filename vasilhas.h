#define CAPACIDADE_INGREDIENTE 10000 //em gramas
#define TEMPO_SUBSTITUICAO 3//em minutos

typedef struct{
    ingrediente *ingrediente;
    servente *servente;
    int quantidade_restante;
}Vasilha;

