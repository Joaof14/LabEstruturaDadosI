#include <stdio.h> 

/* Seja a seguinte seqüência de instruções em um programa C:
int *pti;
int i = 10;
pti = &i;
Qual afirmativa é falsa? Justifique a resposta
I - pti armazena o endereço de i
II - *pti é igual a 10
III - ao se executar *pti = 20; i passará a ter o valor 20
IV - ao se alterar o valor de i, *pti será modificado
V - pti é igual a 10 */



/* Resposta: 
I-Correto, pti armazena o endereço de i, como demonstrado pelo símbolo &. 
II- Correto, ao fazer 8pti, acessamos o valor no endereço armazenado naquele ponteiro, ou seja, acessamo o valor de i.asm
III- Correto, *pti altera o valor no endereço de i, logo i será 20.
IV- Errado, pois *pti é somente o endereço de i, o que muda é o valor armazenado naquele endereço, e não o endereço em si.
V- Falso, pti é igual ao endereço de i, seja la qual ele for.
*/

//Codigo ilustrativo: 
int main(){
    int *pti;
    int i = 10;
    pti = &i;

    printf("i: %d, *pti= %p\n", i, pti);

    *pti = 20;
    printf("i: %d, *pti= %p\n", i, pti);

    i = 30;
    printf("i: %d, *pti= %p\n", i, pti);

    return 0;
}

