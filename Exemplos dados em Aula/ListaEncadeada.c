#include <stdio.h>
#include <stdlib.h>

typedef struct {
int valor;
}Elemento;

typedef struct no{
int chave;
Elemento elemento;
struct no *prox;
} No;

void inicializar (No *no_cabeca){
no_cabeca -> prox = NULL;
}

/* Busca em lista encadeada ordenada.
retorna:
ponteiro para o no encontrado
NULL, caso a chave nao exista */

No *buscar ( No *no_cabeca, No **anterior, int chave){
No *atual = no_cabeca-> prox;

*anterior = no_cabeca;

while (atual != NULL){
if (atual-> chave < chave){
*anterior = atual;
atual = atual->prox;
}else if(atual ->chave ==chave){
return atual; // elemento encontrado;
}else{
break; //elemento nao encontrado}
}
}
return NULL; //chegou ao finm da lista
}

/* insere um novo elemento na lista, mantendo a ordem crescent das chaves.
retorna: 1 -> insercao bem sucedida
0 - chave ja existente
-1 - falha de memoria */

int inserir (No *no_cabeca, Elemento novo_elemento, int chave){
No *anterior;
No *encontrado = buscar (no_cabeca, &anterior, chave);
if (encontrado != NULL){
return 0; // chave existente
}
No *novo_no = calloc (1, sizeof(No));
if (novo_no == NULL){
return -1; // falha de memoria
}
novo_no -> chave =  chave;
novo_no -> elemento = novo_elemento;

novo_no -> prox = anterior -> prox;
anterior -> prox = novo_no;
return 1; // insercao feita
}

void imprimir(const No *no_cabeca){
const No *atual = no_cabeca->prox;

printf("Lista: ");

while (atual != NULL){
printf("[chave= %d, valor =%d] ", atual->chave, atual -> elemento.valor);
atual = atual->prox;
}
printf("\n");
}

void liberar (No *no_cabeca){
No *atual = no_cabeca -> prox;
while(atual != NULL){
No *proximo = atual->prox;
free(atual);
atual = proximo;
}
no_cabeca -> prox = NULL;
}

int main(void){

No cabeca;
inicializar(&cabeca);
inserir(&cabeca, (Elemento){100}, 10);
inserir(&cabeca, (Elemento){300}, 30);
inserir(&cabeca, (Elemento){200}, 30);
inserir(&cabeca, (Elemento){500}, 50);
inserir(&cabeca, (Elemento){400}, 40);
imprimir(&cabeca);
No *anterior;
No *resultado = buscar(&cabeca, &anterior, 30);
if (resultado != NULL){
printf("Chave %d encontrada. Valor: %d \n", resultado -> chave, resultado -> elemento.valor);
} else{
printf("Chave %d nao encontrada. \n", 30);
}
resultado = buscar (&cabeca, &anterior, 25);
if(resultado != NULL){
printf("Chave %d encontrada. Valor: %d \n", resultado -> chave, resultado -> elemento.valor);
} else{
printf("Chave %d nao encontrada. \n", 25);
printf("Ela deveria ser inserida depois da chave %d \n", anterior -> chave);
}
liberar(&cabeca);
return 0;
}
