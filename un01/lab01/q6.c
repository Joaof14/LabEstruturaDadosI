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

/* Resposta: */