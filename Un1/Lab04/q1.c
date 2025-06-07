#include <stdio.h>
#include <stdlib.h>
/* 
Considerando o arquivo texto apresentado, o que o trecho de código abaixo
faz?

#include <stdio.h>
#include <stdlib.h>
int main()
{
FILE *fin;
fin = fopen("arquivos/intro.txt", "r");
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






void a(){
    printf("\n\nLetra a) O oitavo caractere \n");

    FILE *fin;
    fin = fopen("arquivos/intro.txt", "r");
    char ch;

    //posiciionar cursos no caractere 8
    fseek(fin, 7, SEEK_SET);
    fscanf(fin, "%c", &ch);
    fclose(fin);
    printf("%c\n", ch);
}

void b(){
    printf("\n\nb) Uma palavra \n");

    FILE *fin;
    fin = fopen("arquivos/intro.txt", "r");

    //ler palavra formatada
    char s[100];
    fscanf(fin, "%s", s);
    fclose(fin);
    printf("%s\n", s);
}

void c(){
    printf("\n\nc) A quinta palavra \n");

    FILE *fin;
    fin = fopen("arquivos/intro.txt", "r");
    int contador = 0;
    char s[100];
    
    //iterarpara ler quatro palavras
    while(contador < 4){
        if (fscanf(fin, "%99s",s) == 1){
            contador +=1;
        }
    }

    //ler e mostrar a quinta palavra
    fscanf(fin, "%s", s);
    fclose(fin);
    printf("%s\n", s);
}

void d(){
    printf("\n\nd) Uma linha \n");

    FILE *fin;
    fin = fopen("arquivos/intro.txt", "r");
    char linha[200];

    fgets(linha,sizeof(linha),fin);
    printf("%s",linha);
    fclose(fin);
}

int main(){
    printf("Considerando o arquivo texto apresentado, o que o trecho de código abaixo faz?\nesse trecho lê o arquivo e exibe o primeiro código de linha");
    a(); //Letra a
    b(); //Letra b
    c(); //Letra c
    d(); //Letra d
}