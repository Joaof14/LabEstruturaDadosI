#include <stdio.h>
#include <time.h>
#include "sort.h"
#include <stdlib.h>
#include "vetor.h"
#include "search.h"


/*
2º Implemente os dois algoritmos de busca vistos em sala(Sequencial e Binária)
e em seguida compare seus tempos de busca nos seguintes cenários:
a) Array com 1000 elementos
b) Array com 100000
c) Array com 1000000
d) Buscando uma palavra em um texto
*/




int main(){
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


/* Os numeros para análise falam por si só sobre quem é melhor: 

Array de 1000 elementos

Quick sort: 0.000269 segundos
Merge sort: 0.000342 segundos
Insertion sort: 0.002069 segundos
Buble sort: 0.005431 segundos


Array de 100000 elementos

Quick sort: 0.029203 segundos
Merge sort: 0.047954 segundos
Insertion sort: 15.905101 segundos
Buble sort: 66.871464 segundos


Array de 1000000 elementos

Quick sort: 0.221404 segundos
Merge sort: 0.391771 segundos
Insertion sort: Excesso de tempo
Buble sort: Excesso de tempo

*/