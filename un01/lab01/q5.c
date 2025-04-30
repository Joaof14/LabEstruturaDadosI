#include <stdio.h>

/* Como seria o output se eu desse “print” nas variáveis x, y e p? */

int main(){

    int x=68, y;
    int *p;
    p = &x;
    y = *p + 200;

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("p = %p\n", p);
    return 0;
}

/* OUTPUT: 
x = 68
y = 268
p = 0x7ffe4e997bd8 */ 
