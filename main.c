#include <stdio.h>

int main() {
	FILE *arquivo = fopen("arquivo_texto.txt", "r");
	char linha[100];

	printf("Contéudo do arquivo:\n");

	
	while(fgets(linha, sizeof(linha), arquivo) != NULL)
	{
		printf("%s", linha);
	}

	printf("\n");

	fclose(arquivo);
	return 0;
}