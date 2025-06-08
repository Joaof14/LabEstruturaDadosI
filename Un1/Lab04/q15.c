/*Crie um programa que grave os 100 primeiros números naturais ao mesmo
tempo em um arquivo texto e em um arquivo binário. Compare os tamanhos
dos arquivos e explique como os tipos escolhidos para guardar os números
podem tornar o arquivo binário menor ou maior que o arquivo texto.*/

#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo_txt = fopen("arquivos/numeros.txt", "w");
    FILE *arquivo_bin = fopen("arquivos/numeros.bin", "wb");
    
    if (arquivo_txt == NULL || arquivo_bin == NULL) {
        printf("Erro ao criar os arquivos!\n");
        return 1;
    }
    
    for (int i = 1; i <= 100; i++) {
        // Arquivo texto: grava como string
        fprintf(arquivo_txt, "%d\n", i);
        
        fwrite(&i, sizeof(int), 1, arquivo_bin);
    }
    

    fclose(arquivo_txt);
    fclose(arquivo_bin);
    
    FILE *txt = fopen("arquivos/numeros.txt", "r");
    FILE *bin = fopen("arquivos/numeros.bin", "rb");
    
    fseek(txt, 0, SEEK_END);
    fseek(bin, 0, SEEK_END);
    
    long tamanho_txt = ftell(txt);
    long tamanho_bin = ftell(bin);
    
    fclose(txt);
    fclose(bin);
    
   
    printf("Tamanho do arquivo texto: %ld bytes\n", tamanho_txt);
    printf("Tamanho do arquivo binario: %ld bytes\n", tamanho_bin);
    
    if (tamanho_bin < tamanho_txt) {
        printf("O arquivo binario e %.2fx menor que o texto.\n", 
              (float)tamanho_txt/tamanho_bin);
    } else {
        printf("O arquivo binario e %.2fx maior que o texto.\n", 
              (float)tamanho_bin/tamanho_txt);
    }
    
    return 0;
}

/*O arquivo binário salvo foi maior.
Isso acontece pq o tamanho da variável é salvo como um todo no arquivo binário,
 mesmo para numeros que não precisem. 
 Já no tipo texto as variáveis são salvas somente com o tamanho "necessário"*/