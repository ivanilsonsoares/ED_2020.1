#define MAX 100
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct lista Lista;

Lista* criar_lista();

void Liberar_lista(Lista* li);

int Tamanho_lista(Lista* li);

int Lista_cheia(Lista* li);

int Lista_vazia(Lista* li);

int Inserir_lista_inicio(Lista* li, struct aluno al);

int Inserir_lista_meio(Lista* li, struct aluno al, int posicao);

int Inserir_lista_fim(Lista* li, struct aluno al);

int remover_lista_inicio(Lista* li);

int remover_lista_meio(Lista* li, int posicao);

int remover_lista_fim(Lista* li);

int consultar_lista_pos(Lista* li, int posicao, struct aluno *al);

int consultar_lista_conteudo(Lista* li, int conteudo, struct aluno *al);

void imprimir(Lista* li);