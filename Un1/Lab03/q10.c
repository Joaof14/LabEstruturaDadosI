#include <stdio.h> 
#include <stdlib.h>

/* Defina um registro ASCII que armazena um caractere e um valor inteiro 
associado. Crie uma função que recebe um valor inteiro e um caractere, e 
retorna o endereço de um elemento do tipo ASCII, alocado dinamicamente na 
memória. O programa principal deve chamar a função passando valores lidos do 
usuário, receber o retorno em um ponteiro, exibir os valores de retorno e deletar 
a memória que foi alocada dentro da função.  */

typedef struct{
    char c;
    int n;

} ASCII;

//função que retorna ponteiro criado
ASCII* criarAscii(char ch, int i)
{   
    //Alocação dinâmica do valor
    ASCII* valor = malloc(sizeof(ASCII));

    if (valor != NULL){
        valor->c = ch;
        valor->n = i;
    }

    return valor;

}

int main() {

    //Criação e recebimento das variáveis
    int num;
    char car;
    ASCII * ptr = NULL;
    printf("Digite um caractere: ");
    scanf(" %c", &car);
    printf("Digite um valor inteiro: ");
    scanf("%d", &num );
    

    //Criar ascii
    ptr = criarAscii(car, num);

    //Verificação se alocação a partir de função foi bem sucedida
    if (ptr == NULL)
    {
        printf("Erro na alocação de memória");
        return 1;
    }

    printf("Caractere: %c", ptr->c);
    printf("\nnúmero: %d\n", ptr->n);

    free(ptr);



    return 0;
}