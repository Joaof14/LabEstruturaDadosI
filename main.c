#include <stdio.h>

typedef struct {
	char nome[50];
	int idade;
	float altura;
} Pessoa;


int main() {

	Pessoa p1 = {"Carlos", 30, 1.75};

	FILE *arquivo = fopen("pessoa.bin", "wb");

	fwrite(&p1, sizeof(Pessoa), 1, arquivo);
	fclose(arquivo);

	//size_t_fwrite(const void *ptr, size_t_size, size_t_count, FILE * stream);

	Pessoa p2;

	arquivo = fopen("pessoa.bin", "rb");

	fread(&p2, sizeof(Pessoa), 1, arquivo);
	fclose(arquivo);

	printf("Nome: %s\nIdade: %d\nAltura: %.2f\n", p2.nome, p2.idade, p2.altura);

	return 0;



	return 0;
}