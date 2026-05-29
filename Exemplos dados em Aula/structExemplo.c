#include <stdio.h>

typedef  struct {
    int dia;
    int mes;
    int ano;
} Data;

int main(){

printf("sizeof(Data) = %zu bytes \n", sizeof(Data));

return 0;
}