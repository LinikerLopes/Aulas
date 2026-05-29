#include <stdio.h>

int main(){
    int l, c, area, p;

    printf("Digite a largura do retangulo: ");
    scanf("%d", &l);
    printf("Digite a altura do retangulo: ");
    scanf("%d", &c);
    area = l * c;
    p = 2 * (l + c);

    printf("a area e de: %d\n", area);
    printf("o perimetro e de: %d\n", p);

    return 0;
}