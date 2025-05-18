#include <stdio.h> 
#include <stdlib.h>

/*  Inicie o programa perguntando ao usuário quantos inteiros ele deseja 
armazenar em um vetor. Use a informação digitada para criar um vetor 
dinâmico com o espaço necessário para armazenar a quantidade de inteiros 
desejada. Depois disso, deixe que o próprio usuário preencha o vetor, utilizando 
o tamanho do vetor como condição de parada de um laço for. Mostre o vetor 
que foi preenchido através de outro laço e libere o espaço alocado 
dinamicamente ao final do programa.*/

int main() {
    //Receber numero
    int n;
    printf("Quantos inteiros você deseja armazenar em um vetor? ");
    scanf("%d", &n);

    //Alocação dinâmica do vetor
    int * vetor = malloc(n * sizeof(int));

    if (vetor == NULL) 
    {
        printf("Erro na alocação de memória");
        return 1;
    }

    //Laço de recebimento
    for (int i = 0; i < n; i++)
    {
        printf("Posição %d: ", i);
        scanf("%d", &vetor[i]);
    }
    
    //Mostrar valores
    for (int i = 0; i < n; i++)
    {
        printf("vetor[%d]:%d\n", i, vetor[i]);     
    }
    
    //Liberar espaço
    free(vetor);

    return 0;
}