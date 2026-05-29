#include <stdio.h>

int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;
    int(*ptr)[5] = &arr;
    printf("=== Estado inicial ===\n");
    printf("arr        = %p\n", (void *)arr);
    printf("&arr[0]    = %p\n", (void *)&arr[0]);
    printf("&arr       = %p\n", (void *)&arr);
    printf("\n");
    printf("p          = %p -> valor = %d\n", (void *)p, *p);
    printf("ptr        = %p -> primeiro valor do bloco = %d\n", (void *)ptr, (*ptr)[0]);
    printf("\n=== Apos incremento ===\n");
    p++;
    ptr++;
    printf("p apos p++    = %p\n", (void *)p);
    printf("ptr apos ptr++ = %p\n", (void *)ptr);
    printf("\n=== Interpretacao ===\n");
    printf("p avancou para o proximo int: &arr[1] = %p\n", (void *)&arr[1]);
    printf("ptr avancou para o proximo bloco de 5 ints: &arr + 1 = %p\n", (void *)(&arr + 1));
    return 0;
}