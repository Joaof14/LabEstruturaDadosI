/*Escreva um programa que leia um valor inteiro do usuário e armazene-o em
um arquivo binário chamado “interger.bin”. Ao entrar, o programa deve
verificar se o arquivo “integer.bin” existe, e em caso positivo, deve ler e exibir o
número na tela.*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
        int numero;
        FILE *arquivo;

        arquivo = fopen("arquivos/integer.bin", "rb");
        if (arquivo != NULL)
        {
                fread(&numero, sizeof(int), 1, arquivo);
                printf("O numero armazenado anteriormente foi: %d\n", numero);
                fclose(arquivo);
        }

        printf("Digite um numero inteiro para armazenar: ");
        scanf("%d", &numero);

        arquivo = fopen("integer.bin", "wb");
        if (arquivo == NULL)
        {
                printf("Erro ao criar o arquivo!\n");
                return 1;
        }

        fwrite(&numero, sizeof(int), 1, arquivo);
        fclose(arquivo);

        printf("Numero armazenado com sucesso!\n");

        return 0;
}