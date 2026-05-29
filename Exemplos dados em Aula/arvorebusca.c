//copiei algo errado e tive de consultar gpt para terminar a compilação

#include <stdio.h>
#include <stdlib.h>

//no binaria de arvore de busca

typedef struct No {
int chave;
struct No *filho_esquerdo;
struct No *filho_direito;
} No;


int busca_arvore (int chave, const No *ptr){
while (ptr != NULL) {
if (ptr->chave == chave)
return 1;
else if(chave < ptr-> chave)
ptr = ptr->filho_esquerdo;
else
ptr = ptr->filho_direito;
}
return 0;
}
static No *novo_no (int chave){
No *n = (No *)malloc (sizeof *n);
if (!n)
return NULL;
n->chave = chave;
n->filho_esquerdo = n->filho_direito = NULL;
return n;
}

int busca_arvore_rec(int chave, const No *ptr) {
if (!ptr)
return 0;
if (chave == ptr->chave)
return 1;
return (chave < ptr-> chave) ? busca_arvore_rec (chave, ptr->filho_esquerdo)
                             : busca_arvore_rec (chave,ptr->filho_direito);
}

void liberar_arvore(No *ptr) {
if (ptr == NULL) return;
liberar_arvore(ptr->filho_esquerdo);
liberar_arvore(ptr->filho_direito);
free(ptr);
}

int main(void) {
/*
        8
       / \
      3   10
     / \    \
    1   6    14
*/

No *raiz = novo_no(8);
raiz->filho_esquerdo = novo_no(3);
raiz->filho_direito = topo = novo_no(10);
raiz->filho_esquerdo->filho_esquerdo = novo_no(1);
raiz->filho_esquerdo->filho_direito = novo_no(6);
raiz->filho_direito->filho_direito = novo_no(14);

printf("Busca 6: %s\n", busca_arvore(6, raiz) ? "encontrou" : "nao encntrou");
printf("Busca 13: %s\n", busca_arvore(13, raiz) ? "encontrou" : "nao encntrou");

liberar_arvore(raiz);
return 0;
}
