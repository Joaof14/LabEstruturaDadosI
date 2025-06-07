/*Construa um programa que leia um número desconhecido de peixes de um
arquivo texto, chamado “pescado.txt”, e exiba a quantidade total de quilos de
peixe pescado. O arquivo é formatado como no exemplo abaixo: o nome do
peixe, o peso em gramas e o comprimento em centímetros.*/
#include <stdio.h>
#include <stdlib.h>



int main(){
    FILE * arquivo = fopen("arquivos/pescados.txt", "r");
    
    float soma = 0;
    char nome[100];
    int peso, tamanho;
    if (arquivo == NULL )
        {printf("Erro ao abrir arquivo");}

    while (fscanf(arquivo, "%99s %d %d", nome, &peso, &tamanho) == 3)
    {soma += (peso / 1000.0f);}
    
    printf("\n%.3f kg de peixe pescados!\n", soma);
    fclose(arquivo);
    return 1;
}