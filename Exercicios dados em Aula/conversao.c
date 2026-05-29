#include <stdio.h>

int main() {
    float val_reais, val_dolar;
    float cotacao;

    printf("Digite o valor em dolar guardado: ");
    scanf("%f", &val_dolar);

    printf("Digite a cotacao atual: ");
    scanf("%f", &cotacao);

    val_reais = val_dolar * cotacao;

    printf("Valor em reais no cofre: %.2f\n", val_reais);
    return 0;
}