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

int inserir_inicio(Lista* li, struct aluno al);

int inserir_final(Lista* li, struct aluno al);

int inserir_ordenado(Lista* li, struct aluno al);

int remover_inicio(Lista* li);

int remover_final(Lista* li);

int remover_meio(Lista* li, int valor);

int consulta_pos(Lista* li, int pos, struct aluno *al);

int consulta_valor(Lista* li, int valor, struct aluno *al);

void imprime_lista(Lista* li);



