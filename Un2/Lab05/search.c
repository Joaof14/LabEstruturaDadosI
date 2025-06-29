# include <stdio.h>
#include <string.h>


int BinarySearch(int * vetor, int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho -1;
    int meio;

    while (inicio <= fim) 
    {
        meio = (inicio + fim)/ 2;
        if (vetor[meio] == valor) {
        return meio;
        }
        else if (vetor[meio] > valor) {
            fim = meio -1;
            
        }
        else{
            inicio = meio + 1;
        }
    }
    return -1;
}

int LinearSearch(int * vetor, int tamanho, int valor) {
    for (int i =0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}

int LinearSearchChar(char **vetor, int tamanho, char *valor) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(vetor[i], valor) == 0) {
            return i;
        }
    }
    return -1;
}

int BinarySearchChar(char **vetor, int tamanho, char *valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (strcmp(vetor[meio], valor) == 0) {
            return meio;
        } else if (strcmp(vetor[meio], valor) > 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return -1;
}