/*Escreva um programa para ler todos os números do texto e gravá-los em outro
arquivo.*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * arquivo = fopen("arquivos/q2_ex.txt", "r");
     if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    int n;

    while (fscanf(arquivo, "%d", &n) == 1){
        printf("%d\n", n);
    }
    printf("%d", n);

    fclose(arquivo);
    return 1;

}