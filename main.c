#include <stdio.h>

typedef struct {
	char nome[50];
	int idade;
	float altura;
} Pessoa;


int main() {

	FILE * arquivo = fopen("data.txt", "r");

	char nome[50];
	int idade;

	while (fscanf(arquivo, "%s  %d", nome,  &idade) != EOF) {
		printf("Nome: %s, Idade: %d\n", nome, idade);
	}

	fclose(arquivo);
	return 0;

	return 0;

}