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
    int R;
    int G;
    int B;
    int A;
} rgba;

union Cor {
    rgba corRGBA;
    unsigned long int cor32;

};

//Função para receber RGBA
void ReceberRGBA(union Cor *cor) {
    while (1) {
        printf("Insira valores de cores RGBA (0-255) separados por espaço\n");
        scanf("%d %d %d %d", &cor->corRGBA.R, &cor->corRGBA.G, &cor->corRGBA.B, &cor->corRGBA.A);
        if ( (cor->corRGBA.R <= 255 && cor->corRGBA.R >= 0 ) && (cor->corRGBA.G <= 255 && cor->corRGBA.G >= 0 ) && (cor->corRGBA.B <= 255 && cor->corRGBA.B >= 0 ) && (cor->corRGBA.A <= 255 && cor->corRGBA.A >= 0 )  )
        {break;}
    }


}

//Função para receber int32
void ReceberInt32(union Cor *cor){
    //int max = 4294967295;
    while (1) {
        printf("Digite um valor de 0 a 4294967295\n");
        scanf("%lu", &cor->cor32);

        if(cor->cor32 <= 4294967295 && cor->cor32 >= 0) {
            break;
        }
    }

}

int main() {
    union Cor cor;

    ReceberRGBA(&cor);
    printf("\n");
    ReceberInt32(&cor);
    
    return 0;
}