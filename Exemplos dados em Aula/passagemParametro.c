#include <stdio.h>

void por_valor (int x) {
x = x + 10;
}
void por_referencia (int *x) {
*x = *x + 10;
}

int main (void){
int a =5, b= 5;

por_valor(a);
por_referencia(&b);

printf("a (por valor) = %d \n", a);
printf("b (por referencia) = %d \n", b);

return 0;
}
