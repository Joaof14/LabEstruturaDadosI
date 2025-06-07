/*Escreva um programa para ler todos os números do texto e gravá-los em outro
arquivo.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main() {
    FILE *arquivoEntrada = fopen("arquivos/q2_in.txt", "r");
    FILE *arquivoSaida = fopen("arquivos/q2_out.txt", "w");

    if (arquivoEntrada == NULL || arquivoSaida == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    char palavra[100];
    int numero;

    //le todos os inteiros do arquivo e escreve no arquivo de saída
    while (fscanf(arquivoEntrada, "%s", palavra) == 1)
    {   
        if _
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    return 0;
}
