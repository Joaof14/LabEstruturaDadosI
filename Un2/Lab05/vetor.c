#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Funções auxiliares para strings
void preencherStrings(char **strings, int tamanho, int max_len) {
    const char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int num_caracteres = strlen(caracteres);
    
    for(int i = 0; i < tamanho; i++) {
        strings[i] = (char *)malloc((max_len + 1) * sizeof(char));
        int comprimento = 5 + rand() % (max_len - 5);  // Strings de 5 a max_len caracteres
        
        for(int j = 0; j < comprimento; j++) {
            strings[i][j] = caracteres[rand() % num_caracteres];
        }
        strings[i][comprimento] = '\0';
    }
}

void copiarStrings(char **origem, char **destino, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = strdup(origem[i]);
    }
}

void liberarStrings(char **strings, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        free(strings[i]);
    }
}