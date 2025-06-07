/*Escreva um programa que peça ao usuário para digitar um nome de arquivo
texto e uma palavra que ele deseja procurar neste arquivo. O programa deve
dizer se a palavra está ou não presente no arquivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char arquivoNome[100];
    printf("Digite ao nome do arquivo que você quer procurar (lembre-se de começar com 'arquivos/'): ");
    scanf("%99s", arquivoNome);

    FILE *arquivo = fopen(arquivoNome, "r");
    int encontrada = 0;
    if (arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo\n");
        return 0;
    }
    char palavraAlvo[100], palavra[100];
    printf("Digite a palavra que você quer procurar no arquivo: ");
    scanf("%99s", palavraAlvo);

    while(fscanf(arquivo, "%99s", palavra) != EOF){
        if (strcmp(palavra, palavraAlvo) == 0){
            encontrada++;
        }
    }
    printf("Palavra encontrada %d vezes nesse arquivo\n", encontrada);

    fclose(arquivo);
    return 1;
}