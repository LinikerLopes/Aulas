#include <stdio.h>
#include <string.h>

enum { MAX_NOME = 60, MAX_DATA = 12, MAX_CURSO = 40 };

typedef struct {
    int matricula;
    char nome[MAX_NOME];
    char dataNasc[MAX_DATA];
    char curso[MAX_CURSO];
    float cr;
} Aluno;


static void limpa_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

static void le_linha(char *buf, size_t tam) {
    if (fgets(buf, (int)tam, stdin) != NULL) {
        size_t n = strlen(buf);
        if (n > 0 && buf[n - 1] == '\n') {
            buf[n - 1] = '\0';
        } else {
            limpa_buffer();
        }
    }
}

int main(void) {
    Aluno a = {0};

    printf("Matricula: ");
    while (scanf("%d", &a.matricula) != 1) {
        printf("Valor invalido. Tente novamente: ");
        limpa_buffer();
    }
    limpa_buffer(); // consume '\n'
    
    
    printf("Nome: ");
    le_linha(a.nome, sizeof(a.nome));

    printf("Nota (CR): ");
    while (scanf("%f", &a.cr) != 1) {
        printf("Valor invalido. Tente novamente: ");
        limpa_buffer();
    }
    limpa_buffer();

    char *nome = a.nome;
    float nota = a.cr;

    FILE *arquivo = fopen("notas.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo para escrita");
        return 1;
    }

    fprintf(arquivo, "Nome: %s Nota: %.1f\n", nome, nota);
    fclose(arquivo);
    printf("\nDados gravados em 'notas.txt'\n");


    arquivo = fopen("notas.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo para leitura");
        return 1;
    }

    char linha[100];
    printf("\n--- Conteudo do arquivo ---\n");
    while (fgets(linha, sizeof linha, arquivo)) {
        printf("%s", linha);
    }
    fclose(arquivo); // nao deixar de fechar

    return 0;
}
