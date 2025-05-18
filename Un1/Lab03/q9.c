#include <stdio.h> 
#include <stdlib.h>

/* Crie um registro "Local" com os campos nome, país e continente. Pergunte 
ao usuário quantos locais ele quer visitar nas próximas férias e crie um vetor de 
locais alocando dinamicamente o espaço de acordo com quantos locais ele quer 
visitar. Use um laço for para armazenar as informações dos locais que o usuário 
deseja visitar, e depois do armazenamento mostre os locais que ele escolheu. 
Libere o espaço alocado dinamicamente ao final do programa. */

typedef struct {
    char nome[50];
    char país[50];
    char continente[50];
} Local;

void ReceberLocal(Local * l, int n){
    

    for (int i = 0; i < n; i++){
        printf("Digite  o nome do local que você quer visitar: ");
        scanf("%s", l[i].nome);
        printf("Digite o país do local que você quer visitar: ");
        scanf("%s",l[i].país);
        printf("Digite o nome do continente do local que você quer visitar: ");
        scanf("%s",  l[i].continente);
    }

}

void MostrarLocal(Local * l, int n)
{
    printf("Nome|País|Continente\n");
    for (int i = 0; i < n; i++){
        printf("%s|%s|%s\n", l[i].nome, l[i].país, l[i].continente);
    }

}

int main() {
    //Receber numero
    int n;
    printf("Quantos locais você deseja armazenar nessas férias? ");
    scanf("%d", &n);

    //Alocação dinâmica do vetor
    Local * vetor = malloc(n * sizeof(Local));

    if (vetor == NULL) 
    {
        printf("Erro na alocação de memória");
        return 1;
    }

    ReceberLocal(vetor, n);
    MostrarLocal(vetor, n);

    free(vetor);

    return 0;
}