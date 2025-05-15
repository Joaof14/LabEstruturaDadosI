#include <stdio.h> 

/* Defina um registro que descreve um peixe. O registro deve incluir o tipo 
(string), o peso (ponto-flutuante) e o comprimento (inteiro) do peixe. Em 
seguida mostre: 
a) Como criar uma variável de tipo peixe 
b) Como criar um ponteiro para uma variável de tipo peixe. */

typedef struct  {
    char tipo[50];
    float peso;
    int comprimento;
} peixe ;

int main() {
    //a) 
    peixe p1;

    //b)
    peixe * ptr = &p1;


    return 0;
}