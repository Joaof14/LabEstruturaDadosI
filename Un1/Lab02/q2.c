#include <stdio.h> 

/* Construa uma função que receba um peixe e exiba o seu conteúdo. 
a) Faça uma versão utilizando um parâmetro tipo peixe 
b) Faça uma versão utilizando um parâmetro tipo ponteiro para peixe */
typedef struct  {
    char tipo[50];
    float peso;
    int comprimento;
} peixe ;


//a)
void mostrarPeixe1(peixe p){
    printf("Tipo de peixe: %s \n", p.tipo);
    printf("Peso (kg): %.3f \n", p.peso);
    printf("comprimento (cm): %d \n", p.comprimento);

}

//b)
void MostrarPeixe2 (peixe * p){
    printf("Tipo de peixe: %s \n", p->tipo);
    printf("Peso (kg): %.3f \n", p->peso);
    printf("comprimento (cm): %d \n", p->comprimento);


}

int main() {
    peixe p1 = {"Bacalhau", 5.7, 42};
    mostrarPeixe1(p1);
    
    MostrarPeixe2(&p1);
    return 0;
}