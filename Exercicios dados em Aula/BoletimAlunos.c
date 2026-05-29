#include <stdio.h>

typedef struct {
char nome[50];
char curso[50];
float notas[3];
float media;
} Aluno;

int main(){

  Aluno aluno[5];
  
  int n = sizeof(aluno) / sizeof(aluno[0]);
  
  for(int i = 0; i < n; i++){
    
  }

  return 0;
}

//nao terminei
