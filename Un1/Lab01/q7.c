#include <stdio.h> 

/*
Desenvolva uma função que receba como parâmetro os ponteiros de
dois vetores de 5 posições. O procedimento deverá imprimir na tela os
valores contidos nos dois vetores de forma crescente (Utilize ponteiros).
Exemplo:
Vetor 1 = 2, 5, 9, 8, 3
Vetor 2 = 7, 4, 1, 10, 6
Saída: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 
*/



void ordenar(int*v1, int*v2) {

    int i, j, aux;
    int v3[10];

    //concatenar vetores no v3
    for (i = 0; i < 5; i++)
    {
        v3[i] = v1[i];
        v3[i + 5] = v2[i];
    }

    //Ordenar vetores concatenados. Tomei como exemplo o vídeo de uma dança mostrado pelo professor em sala de aula para ajudar a resolver.
    for (i = 0; i<10; i++)
    {
        for (j = 0; j < 9; j++){

            if (v3[j] > v3[j+1])
            {
                aux = v3[j];
                v3[j] = v3[j+1];
                v3[j+1] = aux;
            }


        }
    }
    
    printf("Lista ordenada\n");
    for (i = 0; i < 10; i++){
        printf("%d\n", v3[i]);

    }

    //Usei loops com os tamanhos já pré definidos mas para outros valores que tornassem meu código mais flexível os tamanhos virariam parâmetros da função ordenar.
    

}

int main(){

    int Vetor1[5] = {2, 5, 9, 8, 3};
    int Vetor2[5] = {7, 4, 1, 10, 6};

    ordenar(Vetor1, Vetor2);
    
    return 0;
}

