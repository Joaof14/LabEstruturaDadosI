#include <stdio.h>
#include <time.h>
#include "sort.h"
#include <stdlib.h>
#include "vetor.h"
#include "search.h"


/*
Implemente os algoritmos de ordenação vistos na disciplina(bubble,insertion, merge, quick)
e compare seus tempos de execução

a) Array com 1000 elementos
b) Array com 100000 elementos
c) Array com 1000000 elementos
*/

int main(){


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
