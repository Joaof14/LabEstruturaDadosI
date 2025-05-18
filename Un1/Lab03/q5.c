#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/*  Construa um vetor dinâmico de alunos. O registro aluno deve ser composto 
por nome (ou matrícula), código da disciplina (número inteiro sem sinal), e 
situação da disciplina. A situação da disciplina deve ser uma enumeração com 
os valores: Aprovado, Trancado, Reprovado. Peça ao usuário para digitar o 
número de alunos do vetor e em seguida leia os dados do primeiro aluno. Para 
finalizar mostre os dados do primeiro aluno usando uma função que recebe um 
ponteiro para aluno. */

enum situDisciplina {Aprovado, Trancado, Reprovado};

typedef struct {
    char nome[30];
    unsigned int codigoDisciplina;
    enum situDisciplina situacao;

} aluno;

void exibirAluno(aluno * a){
    char sit[20];
    switch (a->situacao)
    {
    case 0:
        strcpy(sit, "Aprovado");
        break;

    case 1:
        strcpy(sit, "Trancado");
        break;

    case 2:
        strcpy(sit, "Reprovado");
        break;
    default:
        break;
    }
    printf("Aluno: %s | Disciplina: %u | Situação: %s\n", a->nome, a->codigoDisciplina, sit);
    
}

void lerAluno(aluno * a){
    printf("Digite o nome do aluno\n");
    scanf("%s", a->nome);
    printf("Digite o código da discplina\n");
    scanf("%u", &a->codigoDisciplina);
    while (1) 
    {
        printf("Digite o número que corresponde à situação da discplina\n 0-Aprovado, 1-Trancado, 2-Reprovado\n");
        scanf("%u", &a->situacao);

        if (a->situacao <= 2 && a->situacao>= 0){
            break;
        }
    }


}

int main() {
    int numAlunos;
    printf("Digite o número de alunos: ");
    scanf("%d", &numAlunos);
    aluno *alunos = malloc(numAlunos*sizeof(aluno));

    if (alunos == NULL)
    {
        printf("Erro na alocação de memória!\n");
        return 1;
    }
    lerAluno(&alunos[0]);

    exibirAluno(&alunos[0]);

    free(alunos);

    return 0;
}