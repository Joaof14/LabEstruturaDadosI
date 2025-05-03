#include <stdio.h>

/* Qual é a maneira correta de referenciar ch, assumindo que o endereço de ch
foi atribuído ao ponteiro indica? */

int main(){

    char nome[10] = "ch";
    char *indica = nome;

    printf("Endereço: %p\n", indica);
    printf("Conteeúdo no endereço: %s\n", indica);
    return 0;
}