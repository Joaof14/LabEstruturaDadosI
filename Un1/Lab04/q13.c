/*O Exercício de Revisão 1 do Laboratório 6 (Tipos Inteiros) mostra como
usar códigos de Escape para mudar a cor do texto exibido em um terminal. A
sequência de caracteres "\033[38;5;000;48;5;154m" define a cor 000 para o
texto e 154 para o fundo. Considerando que as cores são valores de 3 dígitos de
000 a 255, construa um programa para ler do usuário um texto com no máximo
80 caracteres, um código para a cor do texto e um código para a cor do fundo.
Guarde essas informações em um arquivo binário. O usuário deve ter a opção de
guardar uma nova frase ou exibir a frase já armazenada através de um menu,
como mostrado no exemplo abaixo.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
        char texto[80 + 1];
        int cor_texto;
        int cor_fundo;
} TextoColorido;

void salvarTexto(FILE *arquivo)
{
        TextoColorido tc;

        printf("\nDigite o texto (max %d caracteres): ", 80);
        scanf(" %80[^\n]", tc.texto);

        do
        {
                printf("Digite o código da cor do texto (000-255): ");
                scanf("%d", &tc.cor_texto);
                if (tc.cor_texto < 0 || tc.cor_texto > 255)
                {
                        printf("Valor inválido! Digite um número entre 0 e 255.\n");
                }
        } while (tc.cor_texto < 0 || tc.cor_texto > 255);

        do
        {
                printf("Digite o código da cor do fundo (000-255): ");
                scanf("%d", &tc.cor_fundo);
                if (tc.cor_fundo < 0 || tc.cor_fundo > 255)
                {
                        printf("Valor inválido! Digite um número entre 0 e 255.\n");
                }
        } while (tc.cor_fundo < 0 || tc.cor_fundo > 255);

        fseek(arquivo, 0, SEEK_SET);
        fwrite(&tc, sizeof(TextoColorido), 1, arquivo);
        printf("\nTexto salvo com sucesso!\n");
}

void exibirTexto(FILE *arquivo)
{
        TextoColorido tc;

        fseek(arquivo, 0, SEEK_SET);
        if (fread(&tc, sizeof(TextoColorido), 1, arquivo) != 1)
        {
                printf("\nNenhum texto armazenado ainda.\n");
                return;
        }

        printf("\n\033[38;5;%d;48;5;%dm", tc.cor_texto, tc.cor_fundo);
        printf("%s", tc.texto);
        printf("\033[0m\n");
}

int main()
{
        FILE *arquivo;
        int opcao;

        arquivo = fopen("arquivos/texto_colorido.bin", "rb+");
        if (arquivo == NULL)
        {
                arquivo = fopen("arquivos/texto_colorido.bin", "wb+");
                if (arquivo == NULL)
                {
                        printf("Erro ao criar o arquivo!\n");
                        return 1;
                }
        }

        do
        {
                printf("\nMenu:\n");
                printf("1. Salvar novo texto colorido\n");
                printf("2. Exibir texto armazenado\n");
                printf("0. Sair\n");
                printf("Opção: ");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                        salvarTexto(arquivo);
                        break;
                case 2:
                        exibirTexto(arquivo);
                        break;
                case 0:
                        printf("Encerrando programa...\n");
                        break;
                default:
                        printf("Opção inválida!\n");
                }
        } while (opcao != 0);

        fclose(arquivo);
        return 0;
}