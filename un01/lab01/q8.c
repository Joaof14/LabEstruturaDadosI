#include <stdio.h>

/* Assumindo que o endereço da variável x foi atribuído a um ponteiro px,
escreva uma expressão que não usa x e divida x por 3. */

int main(){

    int x = 3;
    int * px = &x;

    int resultado = (*px)/3 ; // expressão

    printf("Resultado: %d\n", resultado);

    return 0;
}