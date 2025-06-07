/*Uma palavra é um palíndromo se a sequência de letras que a forma é a
mesma quando lida da esquerda para a direita ou da direita para a esquerda (ex:
raiar). Escreva uma função que seja capaz de descobrir se uma palavra é um
palíndromo. Nesta verificação desconsidere maiúsculas e minúsculas (i.e. Ana é
um palíndromo).
O programa deve ler um número indefinido de palavras de um arquivo texto e,
para cada palavra, verificar se ela é ou não um palíndromo. Exiba a quantidade
de palíndromos encontrados no texto, bem como as palavras que são
palíndromos, como mostrado abaixo:*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int verificaPalindromo(const char *palavra){
    int inicio = 0;
    int fim = strlen(palavra) - 1;
    while (fim > inicio)
    {
        if (tolower(palavra[inicio]) != tolower(palavra[fim])) {
            return 0;
        }
        inicio += 1;
        fim -= 1;
    }
    return 1;
}

int main(){
    FILE * arquivo = fopen("arquivos/palindromos.txt", "r");
     if (arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo\n");
        return 0;
    }
    int contador = 0;
    char palavra[100];
    while (fscanf(arquivo, "%s", palavra)!= EOF){
        if(verificaPalindromo(palavra)){
            printf("%s\n", palavra);
            contador ++;
        }
    }
    printf("Foram encontradas %d palavras palíndromos nesse arquivo\n", contador);
    fclose(arquivo);
}