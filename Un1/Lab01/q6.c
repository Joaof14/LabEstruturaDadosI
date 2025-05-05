#include <stdio.h>

/* Assumindo que queremos ler o valor de x, e o endereço de x foi atribuído a
px, a instrução seguinte é correta? Por que?
scanf ( “%d”, *px ); */

int main(){
    int x;
    int * px = &x;
    scanf( "%d", *px );

    return 0;
}

/* Resposta: Não, pois *px é o ponteiro em si, ele armazena o endereço da memória de x, gerando um erro ao tentar ler nele. 
Para ler usando o ponteiro, o correto seria utilizar somente px,  pois o armazenamento estaria sendo feito naquele endereço armazenado, e não onde o ponteiro está*/