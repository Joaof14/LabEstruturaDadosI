/*
Use o registro peixe definido abaixo.

a) Construa um programa que leia do usuário os dados de um único peixe e
salve-os em um arquivo binário. Cada execução do programa deve acrescentar
um peixe ao arquivo.
b) Modifique o programa obtido no item anterior para ler e exibir os peixes
cadastrados no arquivo binário antes de permitir que o usuário faça um
novo cadastro.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    unsigned peso;
    float comp;
} peixe;

void cadastrarPeixe(FILE *arquivo) {
    peixe novo;
    
    printf("\n--- Cadastro de Peixe ---\n");
    printf("Nome: ");
    scanf("%19s", novo.nome);
    printf("Peso (gramas): ");
    scanf("%u", &novo.peso);
    printf("Comprimento (cm): ");
    scanf("%f", &novo.comp);
    
    fwrite(&novo, sizeof(peixe), 1, arquivo);
    printf("Peixe cadastrado com sucesso!\n");
}

void listarPeixes(FILE *arquivo) {
    peixe p;
    int i = 0;
    
    fseek(arquivo, 0, SEEK_SET);
    
    printf("\n--- Peixes Cadastrados ---\n");
    while(fread(&p, sizeof(peixe), 1, arquivo) == 1) {
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
    
    arquivo = fopen("arquivos/peixes.bin", "ab+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    
    listarPeixes(arquivo);
    cadastrarPeixe(arquivo);
    
    fclose(arquivo);
    return 0;
}