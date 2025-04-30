#include <stdio.h>

/* Qual é a maneira correta de referenciar ch, assumindo que o endereço de ch
foi atribuído ao ponteiro indica? */

int main(){

    char nome[2] = "ch";
    char *indica = &nome;

    printf("%p", *indica);
    return 0;
}