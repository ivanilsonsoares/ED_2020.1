#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

struct elemento
{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista *criar_lista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if (li != NULL)
    {
        *li = NULL;
    }
    return li;
}

void liberar_lista(Lista *li)
{
    if (li == NULL && (*li) != NULL)
    {
        Elem *aux, *no = *li;
        while ((*li) != no->prox)
        {
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }
}

int tamanho_lista(Lista *li)
{
    if (li == NULL || (*li) == NULL)
    {
        return 0;
    }
    int cont = 0;
    Elem *no = *li;
    do
    {
        cont++;
        no = no->prox;
    } while (no != (*li));
    return cont;
}

int lista_cheia(Lista *li)
{
    return 0;
}

int lista_vazia(Lista *li)
{
    if (li == NULL && (*li) == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_inicio(Lista *li, struct aluno al)
{
    if (li == NULL)
    {
        return 0;
    }
    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
    {
        return 0;
    }
    no->dados = al;
    if ((*li) == NULL)
    {
        *li = no;
        no->prox = no;
    }
    else
    {
        Elem *aux = *li;
        while (aux->prox != (*li)){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
        *li = no;
    }
    return 1;
}

int inserir_final(Lista *li, struct aluno al)
{
    if (li == NULL)
    {
        return 0;
    }
    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
    {
        return 0;
    }
    no->dados = al;
    if (no == NULL)
    {
        *li = no;
        no->prox = no;
    }
    else
    {
        Elem *aux = *li;
        while (aux->prox != (*li))
        {
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
    }
    return 1;
}

int inserir_ordenado(Lista *li, struct aluno al)
{
    if (li == NULL)
    {
        return 0;
    }
    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
    {
        return 0;
    }
    no->dados = al;
    if ((*li) == NULL)
    {
        *li = no;
        no->prox = no;
        return 1;
    }else{
        if ((*li)->dados.matricula > al.matricula){
            Elem *aux = *li;
            while (aux->prox != (*li)){
                aux = aux->prox;
            }
            aux->prox = no;
            no->prox = *li;
            *li = no;
        }
        Elem *ant = *li, *atual = (*li)->prox;
        while(atual != (*li) && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = no;
        no->prox = atual;
        return 1;
    }
}

int remover_inicio(Lista *li)
{
    if (li == NULL)
    {
        return 0;
    }
    if ((*li) == NULL)
    {
        return 0;
    }
    if ((*li) == (*li)->prox)
    {
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *atual = *li;
    while (atual->prox != (*li))
    {
        atual = atual->prox;
    }
    Elem *no = *li;
    atual->prox = no->prox;
    *li = no->prox;
    free(no);
    return 1;
}

int remover_final(Lista *li)
{
    if (li == NULL)
    {
        return 0;
    }
    if ((*li) == NULL)
    {
        return 0;
    }
    if ((*li) == (*li)->prox)
    {
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *ant, *no = *li;
    while (no->prox != (*li))
    {
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox;
    free(no);
    return 1;
}

int remover_meio(Lista *li, int valor)
{
    if (li == NULL)
    {
        return 0;
    }
    if ((*li) == NULL)
    {
        return 0;
    }

    Elem *no = *li;
    if (no->dados.matricula == valor)
    {
        if (no == no->prox)
        {
            free(no);
            *li = NULL;
            return 1;
        }
        else
        {
            Elem *ult = *li;
            while (ult->prox != (*li))
            {
                ult = ult->prox;
            }
            ult->prox = (*li)->prox;
            *li = (*li)->prox;
            free(no);
            return 1;
        }
    }
    Elem *ult = no;
    no = no->prox;
    while (no != (*li) && no->dados.matricula != valor)
    {
        ult = no;
        no = no->prox;
    }
    if (no == *li && no->dados.matricula != valor)
    {
        ult = no;
        no = no->prox;
    }
    if (no == *li)
    {
        return 0;
    }
    ult->prox = no->prox;
    free(no);
    return 1;
}

int consulta_pos(Lista *li, int pos, struct aluno *al)
{
    if (li == NULL || (*li) == NULL || pos <= 0)
    {
        return 0;
    }
    Elem *no = *li;
    int i = 1;
    while (no->prox != (*li) && i < pos)
    {
        no = no->prox;
        i++;
    }
    if (i != pos)
    {
        return 0;
    }
    else
    {
        *al = no->dados;
    }
    return 1;
}

int consulta_valor(Lista *li, int valor, struct aluno *al)
{
    if (li == NULL || (*li) == NULL)
    {
        return 0;
    }
    Elem *no = *li;
    while (no->prox != (*li) && no->dados.matricula != valor)
    {
        no = no->prox;
    }
    if (no->dados.matricula != valor)
    {
        return 0;
    }
    else
    {
        *al = no->dados;
    }
    return 1;
}

void imprime_lista(Lista *li)
{
    Elem *no = *li;
    printf("{ ");
    do
    {
        printf("Nome: %s | Matricula: %d | Nota: %f \n", no->dados.nome, no->dados.matricula, no->dados.n1);
        no = no->prox;
    } while (no != *li);
    printf("}");
    printf("\n");
}
