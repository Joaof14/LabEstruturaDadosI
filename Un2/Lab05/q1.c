#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include "vetor.h"
#include "search.h"


/*

Implemente os algoritmos de ordenação vistos na disciplina(bubble,insertion, merge, quick)
e compare seus tempos de execução

a) Array com 1000 elementos
b) Array com 100000 elementos
c) Array com 1000000 elementos
d)​ Array de Caracteres


*/

int abc(){
    int tamanhos[3] = {1000, 100000, 1000000};
    clock_t inicio, fim;
    double tempo_gasto;
    for (int n = 0; n < 3; n++) {
        int tamanho = tamanhos[n];
        printf("\n\nArray de %d elementos\n\n", tamanho);

        int * vetor_original = (int *) malloc(tamanho * sizeof(int));
        int * vetor = (int *)malloc(tamanho*sizeof(int));

        if(vetor_original == NULL || vetor == NULL) {
            printf("Erro ao alocar memória!\n");
            return 1;
        }

        preencherVetor(vetor_original, tamanho);
        

        

        //Quick sort
        copiarVetor(vetor_original, vetor, tamanho);
        inicio = clock();
        quickSort(vetor, 0, tamanho);
        fim = clock();
        tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        printf("Quick sort: %f segundos\n", tempo_gasto);

        //

        //Merge sort
        copiarVetor(vetor_original, vetor, tamanho);
        inicio = clock();
        mergeSort(vetor, 0, tamanho-1);
        fim = clock();
        tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        printf("Merge sort: %f segundos\n", tempo_gasto);
  
        //Insertion Sort
        copiarVetor(vetor_original, vetor, tamanho);
        inicio = clock();
        insertionSort(vetor, tamanho);
        fim = clock();
        tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        printf("Insertion sort: %f segundos\n", tempo_gasto);

         // Buble sort
        copiarVetor(vetor_original, vetor, tamanho);
        inicio = clock();
        bubbleSort(vetor, tamanho);
        fim = clock();
        tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        printf("Buble sort: %f segundos\n", tempo_gasto);


        free(vetor);
        free(vetor_original);
    }
    return 0;
}


int d(){
    clock_t inicio, fim;
    double tempo_gasto;
    int tamanho;
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

    // Preencher com strings aleatórias
    preencherStrings(strings_original, tamanho, 10);
    
    // Quick sort
    copiarStrings(strings_original, strings, tamanho);
    inicio = clock();
    quickSortChar(strings, 0, tamanho - 1);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Quick sort: %f segundos\n", tempo_gasto);

    // Merge sort
    copiarStrings(strings_original, strings, tamanho);
    inicio = clock();
    mergeSortChar(strings, 0, tamanho - 1);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Merge sort: %f segundos\n", tempo_gasto);

    // Insertion Sort 
    
    copiarStrings(strings_original, strings, tamanho);
    inicio = clock();
    insertionSortChar(strings, tamanho);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Insertion sort: %f segundos\n", tempo_gasto);


    // Bubble sort 
    
    copiarStrings(strings_original, strings, tamanho);
    inicio = clock();
    bubbleSortChar(strings, tamanho);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Bubble sort: %f segundos\n", tempo_gasto);
    

    // Liberar memória
    liberarStrings(strings_original, tamanho);
    liberarStrings(strings, tamanho);
    free(strings_original);
    free(strings);
    return 0;
}




int main(){
    int n;

   do {
        printf("Digite a função que deseja executar:\n");
        printf("1 - Ordenação de números\n");
        printf("2 - Ordenação de strings\n");
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

   return 0;  
}


/* Os numeros para análise falam por si só sobre quem é melhor: 

Array de 1000 elementos

Quick sort: 0.000328 segundos
Merge sort: 0.000411 segundos
Insertion sort: 0.002267 segundos
Buble sort: 0.005598 segundos


Array de 100000 elementos

Quick sort: 0.029371 segundos
Merge sort: 0.044957 segundos
Insertion sort: 15.284330 segundos
Buble sort: 69.571365 segundos


Array de 1000000 elementos

Quick sort: 0.235621 segundos
Merge sort: 0.395978 segundos
Insertion sort: desisti, tempo demais
Buble sort: desisti, tempo demais.

string de 1000 caracteres

Quick sort: 0.000555 segundos
Merge sort: 0.000611 segundos
Insertion sort: 0.004569 segundos
Bubble sort: 0.015457 segundos

*/