#include <stdio.h> 

/*  Descubra o que acontece ao tentarmos acessar um ponteiro que contém um 
endereço inválido. Para isso tente mostrar o conteúdo apontado por um ponteiro 
recém-criado:*/

int main() {
    int * ptr;
    printf("%d", *ptr);
    return 0;
}

/* O resultado foi: Falha de segmentação (imagem do núcleo gravada) 
Provavelmente o ponteiro está apontando para lixo da memória.
*/