#include <stdio.h> 
#include <stdint.h> // https://www.ibm.com/docs/pt-br/i/7.5.0?topic=files-stdinth

/* Uma cor pode ser representada pela combinação de 4 valores de intensidade 
para R (Red), G (Green), B (Blue) e A (Alpha). Esses valores podem ser 
guardados em um registro com 4 inteiros de 8 bits (0-255) ou por um valor 
inteiro de 32 bits codificado com os 4 valores. Construa uma união para 
armazenar uma cor. Em seguida construa uma função para ler do usuário uma 
cor no formato RGBA e outra para ler uma cor no formato inteiro de 32 bits. 
Ambas as funções devem receber o endereço de uma variável do tipo cor e 
modificar a variável recebida, sem retornar valor.*/


typedef struct {
    int8_t R;
    int8_t G;
    int8_t B;
    int8_t A;
} rgba;

union Cor {
    rgba corRGBA;
    int32_t cor32;

};

void RGBA() {

}

void Int32(){

}

int main() {
    return 0;
}