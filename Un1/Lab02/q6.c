#include <stdio.h> 

/* Crie uma variável do tipo char inicializada para o caractere 'A' e um ponteiro 
que aponte para esta variável. Modifique a variável criada usando o ponteiro, de 
forma que seu conteúdo agora seja 'B'. Por fim, mostre o conteúdo da variável e 
o conteúdo apontado pelo ponteiro.  */

int main() {
    char c = 'A';
    char * ptr = &c;
    *ptr = 'B';
    printf("conteúdo da variável: %c\n", c);
    printf("Conteúdo do Ponteiro: %p\n", (void*) ptr);
    return 0;
}