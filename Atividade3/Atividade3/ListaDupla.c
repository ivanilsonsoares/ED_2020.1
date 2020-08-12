#include <stdio.h>
#include <stdlib.h>
#include "ListaDupla.h"

struct elemento
{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* criar_lista(){
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if (li != NULL){
        *li = NULL;
    }
    return li;
}

void liberar_lista(Lista *li)
{
    if(li != NULL){
        Elem *no;
        while((*li) != NULL){
            no = *li;
            (*li) = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista *li){
    if(li == NULL){
        return 0;
    }
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista *li)
{
    return 0;
}

int lista_vazia(Lista *li)
{
    if (li == NULL)
    {
        return 1;
    }
    if (*li == NULL)
    {
        return 1;
    }
    return 0;
}

int inserir_lista_inicio(Lista *li, struct aluno al){
    if (li == NULL){
        return 0;
    }
    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL){
        return 0;
    }
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    if (*li != NULL)
    {
        (*li)->ant = no;
    }
    *li = no;
    return 1;
}

int inserir_lista_final(Lista* li, struct aluno al){
    if (li == NULL){
        return 0;
    }
    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL){
        return 0;
    }
    Elem *aux = *li;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    no->dados = al;
    no->prox = NULL;
    aux->prox = no;
    no->ant = aux;
    return 1;
}

int inserir_lista_ordenada(Lista *li, struct aluno al)
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
    if (lista_vazia(li))
    {
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }
    else
    {
        Elem *ante, *atual = *li;
        while (atual != NULL && atual->dados.matricula < al.matricula)
        {
            ante = atual;
            atual = atual->prox;
        }
        if (atual == *li)
        {
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }
        else
        {
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if (atual != NULL)
            {
                atual->ant = no;
            }
            return 1;
        }
    }
}

int remover_lista_inicio(Lista *li)
{
    if (li == NULL)
    {
        return 0;
    }
    if (lista_vazia(li))
    {
        return 0;
    }
    Elem *no = *li;
    *li = no->prox;
    if (no->prox != NULL)
    {
        no->prox->ant = NULL;
    }
    free(no);
    return 1;
}

int remover_lista_final(Lista *li){
    if (li == NULL){
        return 0;
    }
    if (lista_vazia(li)){
        return 0;
    }
    Elem *no = *li;
    while (no->prox != NULL)
    {
        no = no->prox;
    }
    if (no->ant == NULL){
        *li = no->prox;
    }
    else
    {
        no->ant->prox = NULL;
    }
    free(no);
    return 1;
}

int remover_lista_meio(Lista* li, int pos){
    if (li == NULL){
        return 0;
    }
    if (lista_vazia(li)){
        return 0;
    }
    Elem *aux ,*remove;
    if(pos == 0){
        remover_lista_inicio(li);
    }else if(pos == tamanho_lista(li)){
        remover_lista_final(li);
    }else{
       aux = (*li);
       for(int i = 1; i<pos;i++){
           aux = aux->prox;
           remove = aux;
           aux->ant->prox = aux->prox;
           aux->prox->ant = aux->ant;
        }
        free(remove);
        return 1;
    }
}

int consulta_lista_pos(Lista *li, int pos, struct aluno *al){
    if(li == NULL || pos<=  0){
        return 0;
    }
    Elem* no = *li;
    int i = 1;
    while(no != NULL && i<pos){
        no = no->prox;
        i++;
    }
    if(no==NULL){
        return 0;
    }else{
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_valor(Lista* li, int valor, struct aluno *al){
   if(li==NULL){
        return 0;
    }
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != valor){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *al = no->dados;
        return 1;
    }
}

void imprimir(Lista* li){
    Elem* no = *li;
    printf("[");
    while(no != NULL){
        printf("{Nome: %s | Matricula: %d | Nota: %f}, ",no->dados.nome, no->dados.matricula, no->dados.n1);
        no = no->prox;
    }
    printf("]\n");
}