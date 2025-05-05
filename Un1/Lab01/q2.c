#include <stdio.h>

// Declare uma variável e “printe” o valor dela e o seu endereço.


int main(){
    //Declaração de variável
    int numero = 0;

    // Printar
    printf("número: %d\n", numero);
    printf("endereço: %p\n", &numero);

    return 0;
}