#include <stdio.h>

int main(void){
    int a = 3, b = 2, c;

    int *p, *q;

    p = &a;
    q = &b;
    c = *p + *q;
    printf("c = %d\n", c);
}