#include <stdio.h> 

/*  Modifique o programa abaixo para que ele mostre o número 10 na tela 
usando o ponteiro q: 
#include <stdio.h> 
int main() 
{ 

    int x, *p, **q; 
    p = &x; 
    q = &p; 
    x = 10; 
    printf("%p\n", (void*)q); 
    return 0;
}*/

int main() {
    int x, *p, **q; 
    p = &x; 
    q = &p; 
    x = 10; 
    //Modificações: %d e **q
    printf("%d\n", **q); 
    return 0;
}