#include <stdio.h>
#include <time.h>
#include "sort.h"
#include <stdlib.h>
#include "vetor.h"
#include "search.h"


/*
Implemente os dois algoritmos de busca vistos em sala(Sequencial e Binária)
e em seguida compare seus tempos de busca nos seguintes cenários:
a) Array com 1000 elementos
b) Array com 100000
c) Array com 1000000
d) Buscando uma palavra em um texto
*/

int abc(){
     ///letras a, b e c
    int tamanhos[3] = {1000, 100000, 1000000};
    clock_t inicio, fim;
    double tempo_gasto;

    int valor;

    printf("Digite um valor de 0 a 1000 para procurar nos vetores: ");
    scanf("%d", &valor);

    for (int n = 0; n < 3; n++) {
        int tamanho = tamanhos[n];


        printf("\nArray de %d elementos\n\n", tamanho);

        int * vetor = (int *)malloc(tamanho*sizeof(int));

        if(vetor == NULL) {
            printf("Erro ao alocar memória!\n");
            return 1;
        }

        preencherVetor(vetor, tamanho);
        quickSort(vetor, 0, tamanho);
        int posicao;
        
        //Busca binaria
        inicio = clock();
        posicao = BinarySearch(vetor, tamanho, valor);
        fim = clock();
        tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        printf("Binary search: %f segundos; ", tempo_gasto);

        if (posicao == -1) {
            printf("Valor não encontrado\n");
        } else {
            printf("Valor encontrado na posição %d\n", posicao);
        }

        //Busca binaria
        inicio = clock();
        posicao = LinearSearch(vetor, tamanho, valor);
        fim = clock();
        tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        printf("Linear search: %f segundos; ", tempo_gasto);

        if (posicao == -1) {
            printf("Valor não encontrado\n");
        } else {
            printf("Valor encontrado na posição %d\n", posicao);
        }


        
        
        free(vetor);
        
    }
    
    return 0;
}

int d(){
    clock_t inicio, fim;
    double tempo_gasto;
    int tamanho;
    //d) Buscando uma palavra em um texto

    printf("Digite o tamanho do array de strings: ");
    scanf("%d", &tamanho); 
    printf("\n\nArray de %d strings\n\n", tamanho);
    // Alocar memória para as strings
    char **strings_original = (char **)malloc(tamanho * sizeof(char *));
    char **strings = (char **)malloc(tamanho * sizeof(char *));

    if(strings_original == NULL || strings == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    preencherStrings(strings_original, tamanho, 20);

    // Copiar as strings para o vetor de strings
    copiarStrings(strings_original, strings, tamanho);
    // Ordenação das strings
    inicio = clock();
    quickSortChar(strings, 0, tamanho - 1);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Quick sort: %f segundos\n", tempo_gasto);

    // Busca binária
    char valor[20];
    printf("Digite uma palavra para procurar no array: ");
    scanf("%s", valor);
    inicio = clock();
    int posicao = BinarySearchChar(strings, tamanho, valor);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Binary search: %f segundos; ", tempo_gasto);
    if (posicao == -1) {
        printf("Palavra não encontrada\n");
    } else {
        printf("Palavra encontrada na posição %d\n", posicao);
    }
    // Busca linear
    inicio = clock();
    posicao =  LinearSearchChar(strings, tamanho, valor);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Linear search: %f segundos; ", tempo_gasto);
    if (posicao == -1) {
        printf("Palavra não encontrada\n");
    } else {
        printf("Palavra encontrada na posição %d\n", posicao);
    }
    // Liberar memória
    liberarStrings(strings_original, tamanho);
    free(strings_original);
    liberarStrings(strings, tamanho);
    free(strings);      

    return 0;
}


int main(){
    int n;
    do {
        printf("Digite a função que deseja executar:\n");
        printf("1 - Ordenação e busca de números\n");
        printf("2 - Ordenação e busca de strings\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &n);
        switch (n)
        {
         
        case 1:
            abc();
            break;

        case 2:
            d();
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    }
    while(n != 0);
    printf("Programa encerrado.\n");

   


    return 0;
}

/* Digite um valor de 0 a 1000 para procurar nos vetores: 2

Array de 1000 elementos

Binary search: 0.000003 segundos; Valor encontrado na posição 2
Linear search: 0.000001 segundos; Valor encontrado na posição 1

Array de 100000 elementos

Binary search: 0.000003 segundos; Valor encontrado na posição 291
Linear search: 0.000002 segundos; Valor encontrado na posição 200

Array de 1000000 elementos

Binary search: 0.000002 segundos; Valor encontrado na posição 2928
Linear search: 0.000012 segundos; Valor encontrado na posição 1992
*/