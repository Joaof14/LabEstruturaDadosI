#include <stdio.h>

int main() {
	FILE *arquivo;
	arquivo = fopen("arquivo_texto.txt", "a");

	fprintf(arquivo, "Esta é uma linha de exemplo. \n");
	fprintf(arquivo, "esta eh outra linha de exemplo\n");
	fclose(arquivo);
}