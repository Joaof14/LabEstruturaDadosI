/*Construa um programa que leia do usuário uma sequência de números
inteiros, até que o número zero seja lido. Os números devem ser armazenados
em um arquivo binário chamado “vet.dat”. O primeiro número do arquivo deve
ser a quantidade de números digitados. Na entrada do programa verifique se o
arquivo existe e, caso positivo, exiba os valores do vetor.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
        FILE *arquivo;
        int numero, quantidade = 0;
        int *vetor = NULL;
        int i;

        arquivo = fopen("arquivos/vet.dat", "rb");
        if (arquivo != NULL)
        {
                fread(&quantidade, sizeof(int), 1, arquivo);
                vetor = (int *)malloc(quantidade * sizeof(int));
                fread(vetor, sizeof(int), quantidade, arquivo);

                printf("Vetor armazenado anteriormente:\n");
                for (i = 0; i < quantidade; i++)
                {
                        printf("%d ", vetor[i]);
                }
                printf("\n");

                fclose(arquivo);
                free(vetor);
        }

        printf("\nDigite uma sequencia de numeros inteiros (0 para terminar):\n");
        vetor = NULL;
        quantidade = 0;

        while (1)
        {
                scanf("%d", &numero);
                if (numero == 0)
                        break;

                quantidade++;
                vetor = (int *)realloc(vetor, quantidade * sizeof(int));
                vetor[quantidade - 1] = numero;
        }

        arquivo = fopen("arquivos/vet.dat", "wb");
        if (arquivo == NULL)
        {
                printf("Erro ao criar o arquivo!\n");
                free(vetor);
                return 1;
        }

        fwrite(&quantidade, sizeof(int), 1, arquivo);
        fwrite(vetor, sizeof(int), quantidade, arquivo);
        fclose(arquivo);
        free(vetor);
        printf("Sequencia armazenada com sucesso!\n");

        return 0;
}