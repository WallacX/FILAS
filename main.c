#include "filas.c"
#include "ingrediente.c"
#include "usuario.c"
#include "vasilha.c"
#include "servente.c"
#include "bancada.c"

int main(){
    
    return 0;
}

/*
--Abertura do RU--
criaCardapio() -> Mesmo cardapio pro dia todo
inicializaBancada() e encerraBancada() //Essas funções devem ser chamadas por meio do teclado

preencheVasilha(Bancada)
geraServentes()
posicionaServente(Servente, Bancada)


--Etapas do Funcionamento--
criaFila(Bancada)
geraUsuarios()
insereUsuarioFila(Usuario, Fila) --> Caso seja vegetariano inserir ele na fila da bancada vegetariana
//Usuario deve ser inserido na menor fila

insereUsuarioBancada(Usuario, Bancada, Fila) ou removeUsuarioFila()

serveUsusario() em paralelo a esta função deve existir a função trocaVasilha(bancada, igrediente) que 
deve trocar a  vasilha sempre que a quantidade do igrediente seja insuficiente
//Se o usuario estiver na ultima vasilha, após ser servido deve ser liberado usando removeUsuarioBancada() e freeUsuario()

Antes do proximo usuario entrar na bancada, devemos checar o tempo trabalhados dos serventes com 
confereTempoServente() e utilizar liberaServenteDescanso() caso nescessario, e caso seja nescessario 
inserir outro servente usamos a função definida anteriormente

checaServenteDescansado()-> Checa se o tempo de descanso do servente já foi alcançado, caso tenha sido, zera
o tempo de trabalho?*

DescansaServentes() considerando que o RU pare de funcionar pelo menos 30m antes do próximo turno, todos os serventes
iniciarão o proximo turno descansados


--Finalização--
freeServente()
geraRelatorio()

*/