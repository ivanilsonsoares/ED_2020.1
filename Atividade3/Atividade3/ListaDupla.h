struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct elemento* Lista;

Lista* criar_lista();

void liberar_lista(Lista* li);

int tamanho_lista(Lista* li);

int lista_cheia(Lista* li);

int lista_vazia(Lista* li);

int inserir_lista_inicio(Lista* li, struct aluno al);

int inserir_lista_final(Lista* li, struct aluno al);

int inserir_lista_ordenada(Lista* li, struct aluno al);

int remover_lista_inicio(Lista* li);

int remover_lista_final(Lista* li);

int remover_lista_meio(Lista* li, int pos);

int consulta_lista_pos(Lista* li, int pos, struct aluno *al);

int consulta_lista_valor(Lista* li, int valor, struct aluno *al);

void imprimir(Lista* li);