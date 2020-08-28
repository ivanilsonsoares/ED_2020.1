#define MAX 100
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct pilha Pilha;

Pilha* criar_pilha();

void Liberar_pilha(Pilha* pi);

int tamanho_pilha(Pilha* pi);

int pilha_cheia(Pilha* pi);

int pilha_vazia(Pilha* pi);

int inserir_pilha(Pilha* pi, struct aluno al);

int remover_pilha(Pilha* pi);

int consulta_pilha(Pilha* pi, struct aluno *al);

void imprimir(Pilha* pi);