#include <stdio.h>

int main(){
    int numero, i;
    int fatorial = 1;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    for(i = numero; i > 0; i--){
        fatorial = fatorial * i;
        printf("%d\n ", fatorial);
    }
    return 0;
}