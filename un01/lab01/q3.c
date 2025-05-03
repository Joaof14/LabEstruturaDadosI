#include <stdio.h>

/* Qual é a maneira correta de referenciar ch, assumindo que o endereço de ch
foi atribuído ao ponteiro indica? */

int main(){

    char nome[10] = "ch";
    char *indica = nome; // maneira de armazenar o endereço

    printf("Endereço: %p\n", indica); // maneira de mostrar o endereço
    printf("Conteúdo no endereço: %s\n", indica); // maneira de mostrar o conteúdo no endereço.
    return 0;
}