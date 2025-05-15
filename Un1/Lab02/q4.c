#include <stdio.h> 

/* Construa duas funções que realizem o incremento de um número em uma 
unidade. A função Mais deve receber um número inteiro através de um 
ponteiro. A função Incrementa deve receber um valor inteiro, sem usar 
ponteiros, e retornar o valor incrementado em uma unidade. */

void Mais(int * n1){
    *n1 = *n1 + 1;
}


int Incrementa(int n1){
    n1 = n1 + 1;
    return n1;
}

int main() {
    int n;
    printf("Digite um valor:\n");
    scanf(" %d", &n);

    Mais(&n);
    printf("Resultado após Mais: %d \n", n);

    n = Incrementa(n);
    printf("Resultado após Incrementa: %d \n", n);

    return 0;
}