#include <stdio.h>

#define TAM 5

void preencherValor(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Digite um numero: ");
        scanf("%d", &vetor[i]);
    }
}
void mostraVetor(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int numeros[TAM];
    preencherValor(numeros, TAM);
    mostraVetor(numeros, TAM);

    return 0;
}