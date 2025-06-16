/*Crie um registro Soldado com os campos nome, eliminações, mortes, taxa
de eliminação por morte (eliminações/mortes) e número de partidas jogadas. Na
função principal leia um soldado de um arquivo binário. Se o arquivo não
Para existir, você deve direcionar o usuário para a criação de um novo soldado.
Quando o soldado for lido (seja pelo arquivo ou pelo teclado), você deve dar as
seguintes opções ao usuário:
[N]ovo soldado (sobrescrever o anterior)
[A]ualiza o soldado (com os dados da última partida)
[E]xibe o soldado (atual)
[S]air */

#include <stdlib.h>
#include <stdio.h>

typedef struct {
        char nome[100];
        int elim;
        int mortes;
        float taxaDeElimin;
        int partidas;
} Soldado;

void RegistrarSoldado(){}

void AtualizarSoldado(){}

void ExibirSoldado(){}


int main(){
        return 0;
}