#include <stdio.h> 
#include <stdlib.h>

/* Defina o registro balao como mostrado abaixo. Construa um programa para 
alocar dinamicamente uma variável do tipo balao. Peça ao usuário para entrar 
com valores para cada um dos membros e em seguida exiba o conteúdo do 
registro. 

Em seguida mostre:  
a) Como criar uma variável de tipo balão 
b) Como alocar dinamicamente um registro de tipo balão. 

*/

typedef struct {
    float diametro; //diametro em metros
    char marca[20]; //nome da marca
    int modelo; //numero do modelo
} balao;

int main() {
    //a)Criando variavel do tipo balão
    balao b1;

    printf("Digite o diâmetro do balão: ");
    scanf("%f", &b1.diametro);
    printf("Digite a marca do balão: ");
    scanf("%s", b1.marca);
    printf("Digite o número do modelo do balão: ");
    scanf("%d", &b1.modelo);

    printf("Balão da letra A):\nDiâmetro: %f\nMarca:%s\nModelo:%d\n", b1.diametro, b1.marca, b1.modelo);

    //b) Alocando dinamicamente um registro do tipo balao
    balao *b2 = malloc(sizeof(balao));

    if (b2 == NULL) {
        printf("Falha na alocação de memória");
        return 1;
    }
    printf("Digite o diâmetro do balão: ");
    scanf("%f", &b2->diametro);
    printf("Digite a marca do balão: ");
    scanf("%s", b2->marca);
    printf("Digite o número do modelo do balão: ");
    scanf("%d", &b2->modelo);

    printf("Balão da letra B):\nDiâmetro: %f\nMarca:%s\nModelo:%d\n", b2->diametro, b2->marca, b2->modelo);

    free(b2);

    return 0;
}