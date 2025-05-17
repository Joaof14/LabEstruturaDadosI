#include <stdio.h> 
#include <stdlib.h>

/*  Repita o exercício anterior criando um vetor dinâmico de carros. Ao invés de 
inicializar o vetor com valores predefinidos, peça ao usuário para digitar os 
dados de dois carros. Use uma função para receber o vetor de carros e exibir o 
valor total dos carros.*/

typedef struct {
    char modelo[30];
    int ano;
    float valor;
} carro;


void valorCarros(carro *vetorC){
    float total = 0;
    for(int i = 0; i < 2; i++) {
        total += vetorC[i].valor;
    }

    printf("O valor total é: R$%.2f\n", total);

}

int main() {
    carro *c = malloc(2*sizeof(carro));
    
    printf("Entre com dados de dois carros\n");
    scanf("%s %d %f", c[0].modelo, &c[0].ano, &c[0].valor);
    scanf("%s %d %f", c[1].modelo, &c[1].ano, &c[1].valor);

    valorCarros(c);

    free(c);
    return 0;
}