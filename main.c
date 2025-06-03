#include <stdio.h>

typedef struct {
	char nome[50];
	int idade;
	float altura;
} Pessoa;


int main() {

	FILE * arquivo = fopen("f.txt", "r+");

	fprintf(arquivo, "Joao Pedro");

	while (fscanf(arquivo, "%s  %d") != EOF) {
		printf("Nome: %s, Idade: %d\n");
	}

	fclose(arquivo);
	return 0;


}