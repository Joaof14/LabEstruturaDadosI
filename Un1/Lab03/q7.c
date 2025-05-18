#include <stdio.h> 
#include <stdlib.h>

/* Declare um ponteiro para inteiro, aloque memória dinamicamente para ele e 
armazene o número 100 nessa memória. Mostre o conteúdo apontado. Peça que 
o usuário digite um novo número inteiro e armazene-o na memória previamente 
alocada. Libere o espaço alocado dinamicamente ao final do programa. 
*/

int main() {
    //Declarar ponteiro
    int * ptr = malloc(sizeof(int));

    //Verificar se alocação da memória foi bem sucedida
    if (ptr == NULL) 
    {
        printf("Erro na alocação de memória!");
        return 1;
    }
    //Atribuir valor a ponteiro
    * ptr = 100;

    printf("Conteúdo armazenado: %d ", *ptr);
    printf("\nDigite o novo valor para esse bloco de memória: ");
    scanf("%d", ptr);

    //Liberar espaço
    free(ptr);

    return 0;
}