#include <stdio.h>

int media (int nota1, int nota2, int nota3){
        return (nota1 + nota2 + nota3) / 3;
    }

int main(){
    printf("%d", media(10, 20, 30));
    return 0;
}

