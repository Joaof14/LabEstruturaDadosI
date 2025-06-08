/*Escreva um programa para ler todos os números do texto e gravá-los em outro
arquivo.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivoEntrada = fopen("arquivos/q2_in.txt", "r");
    FILE *arquivoSaida = fopen("arquivos/q2_out.txt", "w");

    if (arquivoEntrada == NULL || arquivoSaida == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    char palavra[100];
    char *endptr;
    long numero;

    while (fscanf(arquivoEntrada, "%s", palavra) == 1) {
        numero = strtol(palavra, &endptr, 10);

        if (endptr != palavra) {
            fprintf(arquivoSaida, "%ld\n", numero);
        }
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    return 0;
}
