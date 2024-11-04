#define inicia_srand srand(time(NULL))
#define ACEITACAOINGREDIENTE1 rand()%51+50 
#define TAMMAXNOMEINGREDIENTE 15
#define TAMCARDAPIO 6
#define TOTALINGREDIENTES 12

const char *todosIngredientes[] = {
    "Arroz", "Feijao", "Carne", "Salada", "Macarrao", "Frango",
    "Peixe", "Legumes", "Batata", "Ovo", "Sopa", "Fruta"
};

typedef struct{
    int grauAceitacao ;
    char nome[TAMMAXNOMEINGREDIENTE];
}Ingrediente;

Ingrediente criaIngrediente(int grauAceit, char nome[TAMMAXNOMEINGREDIENTE]);
void criaCardapio(Ingrediente *cardapio);
void imprimeCardapio(Ingrediente *cardapio);