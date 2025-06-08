/* Construa um programa que leia um número desconhecido de peixes de um
arquivo texto (semelhante ao arquivo utilizado na primeira questão) e grave
estas informações em um arquivo binário que possa ser lido pelo programa da
segunda questão. Compare o tamanho dos arquivos texto e binário.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    unsigned peso;
    float comp;
} peixe;

void cadastrarPeixe(FILE *arquivo) {
    peixe novo;
    
    printf("\nCadastro de Peixe\n");
    printf("Nome: ");
    scanf("%19s", novo.nome);
    printf("Peso (gramas): ");
    scanf("%u", &novo.peso);
    printf("Comprimento (cm): ");
    scanf("%f", &novo.comp);
    
    fprintf(arquivo, "%s %u %.1f\n", novo.nome, novo.peso, novo.comp);
    printf("Peixe cadastrado com sucesso!\n");
}

void listarPeixes(FILE *arquivo) {
    peixe p;
    int i = 0;
    
    rewind(arquivo);
    
    printf("\nPeixes Cadastrados\n");
    while(fscanf(arquivo, "%19s %u %f", p.nome, &p.peso, &p.comp) == 3) {
        printf("\nPeixe %d:\n", ++i);
        printf("Nome: %s\n", p.nome);
        printf("Peso: %u g\n", p.peso);
        printf("Comprimento: %.1f cm\n", p.comp);
    }
    
    if (i == 0) {
        printf("Nenhum peixe cadastrado ainda.\n");
    }
}

int main() {
    FILE *arquivo;
    
    arquivo = fopen("arquivos/peixes.txt", "a+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    
    listarPeixes(arquivo);
    cadastrarPeixe(arquivo);
    
    fclose(arquivo);
    return 0;
}