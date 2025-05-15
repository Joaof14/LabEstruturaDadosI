#include <stdio.h> 

/* Descubra qual é a saída do seguinte trecho de código, sem auxílio do 
computador. Depois rode o programa passo a passo com o depurador para 
verificar se conseguiu chegar na resposta certa. 

#include <stdio.h> 
int main() { 
    int valor = 10, *temp, soma = 0; 
    temp = &valor; 
    *temp = 20;  
    temp = &soma; 
    *temp = valor; 
    printf("valor: %d\nsoma: %d\n", valor, soma); 
    return 0; 
}

*/

/* Resposta:
    temp = &valor; -> temp recebe endereço de valor
    *temp = 20;  -> variável Valor é alterada para 20
    temp = &soma; -> Temp recebe endereço de soma
    *temp = valor; -> altera soma para receber o mesmo conteúdo de valor.
*/

int main() {
    int valor = 10, *temp, soma = 0; 
    temp = &valor; 
    *temp = 20;  
    temp = &soma; 
    *temp = valor; 
    printf("valor: %d\nsoma: %d\n", valor, soma); 
    return 0;
}