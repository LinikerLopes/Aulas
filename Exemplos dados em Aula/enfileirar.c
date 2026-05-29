//Complementado com chatgpt pq esqueci de copiar algo do codigo

#include <stdio.h>

#define MAX_FILA 5

typedef int Elemento;

typedef struct{
    Elemento v[MAX_FILA];
    int inicio;
    int fim;
} Fila;

void fila_init (Fila *f) { f->inicio = f->fim = -1; }

int enfileirar(Fila *f, Elemento e){
    if((f->inicio == 0 && f->fim == MAX_FILA -1) || (f->fim + 1 == f->inicio)){
        return 0;
    }

    if(f->inicio == -1){  // Corrigido 'f->) inicio'
        f->inicio = f->fim = 0;
    }else if(f->fim==MAX_FILA -1){
        f->fim = 0;
    }else{
        f->fim++;
    }
    f->v[f->fim] = e;
    return 1;
}

void fila_dump(const Fila *f){
    if (f->inicio == -1){
        puts("[]");
        return;
    }
    printf("[");
    int i = f->inicio;
    while (1){
        printf("%d", f->v[i]);
        if(i == f->fim)
            break;
        i = (i+1) % MAX_FILA;
        printf(" ");
    }
    puts("]");
}

int main(void){
    Fila F;
    fila_init(&F);  // Corrigido 'file_init' para 'fila_init'

    for(int i = 0; i < 5; i++) {  // Corrigido 'for(int x : ...)' para sintaxe C padrão
        int x = (int[]){10,20,30,40,50}[i];  // Mantendo a ideia do original
        if (enfileirar(&F, x)){  // Corrigido 'inf' para 'if'
            printf("enfileirar(%d) OK\n", x);
        }else{
            printf("enfileirar(%d) OVERFLOW\n", x);
            fila_dump(&F);
        }
    }

    if(!enfileirar(&F, 60))  // Corrigido a string e parênteses
        puts("overflow detectado ao tentar 60");

    return 0;
}
