#include <stdio.h>
#include <stdlib.h>

void preencherVetor(int * vetor, int tamanho) {
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 1000;
    }
}

void copiarVetor(int *origem, int * destino, int tamanho){
    for (int i = 0; i< tamanho; i++){
        destino[i] = origem[i];
    }
}

void imprimirVetor(int * vetor, int tamanho) {
    for (int i = 0; i< tamanho; i++) {
        printf("%d", vetor[i]);
    }
    printf("\n");
}