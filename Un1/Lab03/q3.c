#include <stdio.h> 

/*  Construa um registro para guardar informações sobre um carro. Um carro 
deve ter um modelo, ano de fabricação e preço. Em seguida construa um vetor 
estático de 10 carros inicializando os dois primeiros carros respectivamente para 
"Vectra", 2009, R$58.000,00 e "Polo", 2008, R$45.000,00. Use um ponteiro 
para apontar para o segundo carro e exibir seus dados.*/

typedef struct {
    char modelo[30];
    int ano;
    float valor;
} carro;

int main() {
    //Criação do vetor
    carro carros[10] = {
        {"Vectra", 2009, 58000},
        {"Polo", 2008, 45000}
    };

    //ponteiro
    carro *c = &carros[1];

    printf("Carro2\nModelo: %s, ano: %d: , valor: R$%.2f\n", c->modelo,c->ano, c->valor);
 
    free(c);
    return 0;

}