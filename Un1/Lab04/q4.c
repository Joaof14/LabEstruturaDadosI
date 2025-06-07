/*Construa um programa que leia um arquivo texto contendo o nome e as três
notas de vários alunos (uma quantidade indefinida de alunos). Escreva em outro
arquivo texto o nome e a situação do aluno (aprovado, quarta prova ou
reprovado).*/

#include <stdio.h>
#include <stdlib.h>


float calcularMedia(float n1, float n2, float n3){
    float media;
    media = (n1 + n2 + n3)/3;
    return media;
}

int main(){
    FILE * arquivoEntrada = fopen("arquivos/notasAlunos.txt", "r");
    FILE * arquivoSaida = fopen("arquivos/notasAlunosSituacao.txt", "w");


    char nome[100];
    float n1, n2, n3, media;

    while(fscanf(arquivoEntrada, "%99s %f %f %f", nome, &n1, &n2, &n3) == 4){
        media = calcularMedia(n1, n2, n3);

        if (media < 3.5) {
            fprintf(arquivoSaida, "%s: Reprovado\n", nome);
        }
        else if (media < 7){
            fprintf(arquivoSaida, "%s: Quarta prova\n", nome);
        }
        else{fprintf(arquivoSaida, "%s: Aprovado\n", nome);}
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    return 1;
}