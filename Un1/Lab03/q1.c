#include <stdio.h> 
#include <stdlib.h>

/* Crie um programa que peça ao usuário para digitar o número de alunos em 
uma turma. O programa deve usar essa informação para criar um vetor dinâmico 
que armazene as notas finais desses alunos. Peça ao usuário para entrar com a 
nota de dois alunos e em seguida mostre essas notas usando cout.*/

int main() {
    //Recebendo número de alunos
    int numDeAlunos = 0;

    // Garantir q sejam no mínimo 2 alunos
    while (numDeAlunos < 2) {
        printf("Digite o número de alunos da turma (mínimo 2)\n");
        scanf("%d", &numDeAlunos);
    }
    
    //Criar vetor de notas
    float *notas = malloc(numDeAlunos*sizeof(float));

    printf("Perfeito! Agora digite a nota de dois alunos\n");
    scanf("%f %f", &notas[0], &notas[1]);


    printf("As notas digitadas foram %.2f e %.2f\n", notas[0], notas[1] );

    free(notas);

    return 0;
}