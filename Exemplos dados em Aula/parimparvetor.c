#include <stdio.h>

int parImpar (int num){
    if(num % 2 == 0) {
    return 1;
        
    } else {
     return 0; 
    }
}

int main(){
    int numeros[10];
    int i;
    int n = sizeof(numeros) / sizeof(numeros[0]);
    int par = 0, impar = 0;

    for (int i = 0; i < n; i++){
        printf("Digite um numero: ");
        scanf("%d", &numeros[i]);

        if(parImpar(numeros[i]) == 1){
            par++;
        } else {
            impar++;
        }
    }

    printf("Quantidade de numeros pares: %d\n", par);
    printf("Quantidade de numeros impares: %d\n", impar);

    return 0;
}