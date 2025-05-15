#include <stdio.h> 
#include <string.h>

/*  Declare um registro "Tigela" com os campos estado (cheia ou vazia) e tipo de 
alimento (sopa ou canja). Crie uma função "Fome" que recebe um ponteiro para 
uma Tigela e altera o seu estado para "vazia". Na função principal crie uma 
tigela cheia, crie um ponteiro que aponta para essa tigela e então mostre como a 
tigela estava antes da janta. Depois chame a função Fome com o ponteiro que 
aponta para a tigela e ao fim mostre a tigela depois da janta.*/



typedef struct {
    char estado[20];
    char tipo_de_alimento[20];

} Tigela;

void Fome(Tigela * ptr) {
    //ptr->estado = "vazia";
    strcpy(ptr->estado, "vazia");

}

int main() {
    Tigela bowl = {"cheia", "sopa"};
    Tigela * p = &bowl;

    printf("A Tigela antes da janta estava %s de %s\n", p->estado, p->tipo_de_alimento);
    Fome(p);
    printf("A Tigela depois da janta estava %s\n", p->estado);

    return 0;
}