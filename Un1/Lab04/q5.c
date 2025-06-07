/*Escreva um programa que abra um arquivo texto, leia caractere a caractere
até o fim do arquivo e exiba na tela o número total de caracteres, o número de
vogais, o número de consoantes, e a quantidade de outros caracteres presentes
no texto.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isVogal(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' ||c == 'u' || c == 'A' ||c == 'E' || c == 'I' ||c == 'O' || c == 'U' )
    {
        return 1;
    }
    return 0;
}

int main()
{
    FILE *arquivo = fopen("arquivos/q5_6.txt", "r");

    if (arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo\n");
        return 0;
    }
    int vogais = 0, consoantes = 0, outro = 0;
    char c;
    while ((c = fgetc(arquivo)) != EOF)
    {
        if (!isalpha(c) && !isspace(c))
        {
            outro += 1;
        }
        else if (isVogal(c))
        {
            vogais++;
        }
        else
        {
            consoantes++;
        }
    }
    printf("vogais: %d\nconsoantes: %d\noutros: %d\n", vogais, consoantes, outro);
    fclose(arquivo);
    return 1;
}