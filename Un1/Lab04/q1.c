/* 
Considerando o arquivo texto apresentado, o que o trecho de código abaixo
faz?

#include <stdio.h>
#include <stdlib.h>
int main()
{
FILE *fin;
fin = fopen("intro.txt", "r");
char ch;
fscanf(fin, "%c", &ch);
fclose(fin);
printf("%c\n", ch);
return 0;
}

Modifique o programa para ler do arquivo texto:
a) O oitavo caractere
b) Uma palavra
c) A quinta palavra
d) Uma linha
*/