#include <stdio.h>

static int a = 0;

void incrementa(void){
    int b = 0;
    static int c = 0;
    printf("a = %d, b = %d, c = %d\n", a, b, c);
}

int main(void){
    for (int i = 0; i < 5; i++){
        incrementa();
    }

    return 0;
}