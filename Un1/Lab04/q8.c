/*Uma escola deseja fazer uma competição intercalasses com seus alunos. A
secretaria da escola montou um arquivo texto com a lista dos alunos
interessados em participar da competição. A listagem contém o nome do aluno e
um código que indica o turno (manhã ou tarde) e a série (6ª, 7ª ou 8ª), como no
exemplo abaixo:


Crie um registro para representar um aluno, leia as informações do arquivo e
guarde em um vetor de alunos. Em seguida use laços e testes condicionais para
separar e exibir os alunos agrupados por turno e série, como no exemplo abaixo.




Sugestão: tente também listar os alunos separados apenas por turno.
a) Seria possível separar os alunos por sexo usando os dados fornecidos no
programa? Descreva sua solução.
b) Se fosse possível adicionar novas informações aos dados, qual seria a
forma mais fácil de conseguir fazer essa separação por sexo?
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    char sobrenome[50];
    char turno;
    int serie;
} alunos;

void titulo(char c, int n)
{

    switch (c)
    {
    case 'M':
        printf("\nMatutino ");
        break;
    case 'T':
        printf("\nVespertino ");
        break;

    default:
        break;
    }

    switch (n)
    {
    case 6:
        printf("6a série\n");
        break;
    case 7:
        printf("7a série\n");
        break;
    case 8:
        printf("8a série\n");
        break;
    default:
        break;
    }
    printf("-------------\n");
}

int main()
{
    FILE *arquivo = fopen("arquivos/alunosInterclasse.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro abrindo o arquivo");
        return 0;
    }

    alunos *vetorAlunos = malloc(sizeof(alunos));
    if (vetorAlunos == NULL)
    {
        printf("Erro locando memória");
        return 0;
    }

    int i = 0;
    while (fscanf(arquivo, "%49s %49s %c%d", vetorAlunos[i].nome, vetorAlunos[i].sobrenome, &vetorAlunos[i].turno, &vetorAlunos[i].serie) == 4)
    {
        i++;
        vetorAlunos = realloc(vetorAlunos, (1 + i) * sizeof(alunos));
    }

    char turnos[] = {'M', 'T'};

    int series[] = {6, 7, 8};

    for (int t = 0; t < 2; t++)
    {
        char turno = turnos[t];

        for (int s = 0; s < 3; s++)
        {
            int serie = series[s];

            titulo(turno, serie);
            for (int j = 0; j < i; j++)
            {
                if (vetorAlunos[j].turno == turno && vetorAlunos[j].serie == serie)
                {
                    printf("%s %s\n", vetorAlunos[j].nome, vetorAlunos[j].sobrenome);
                }
            }
        }   
    }

    free(vetorAlunos);
    fclose(arquivo);
    return 1;
}
