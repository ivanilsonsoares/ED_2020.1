#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinariaBusca.h"

struct NO{
    int info;
    struct NO* esq;
    struct NO* dir;
};

int inserirArvore(arvBin* raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL){
        return 0;
    }
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL){
        *raiz == novo;
    }else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual ->info){
                free(novo);
                return 0;
            }
            if(valor > atual->info){
                atual = atual->dir;
            }else{
                atual = atual->esq;
            }
            if(valor > ant->info){
                ant->dir = novo;
            }else{
                ant->esq = novo;
            }
        }
    }
    return 1;
}

int removerArvore(arvBin* raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz){
                *raiz = removeAtual(atual);
            }else{
                if(ant->dir == atual){
                    ant->dir = removeAtual(atual); 
                }else{
                    ant->esq = removeAtual(atual);
                }
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;    
        }
    }
}

struct NO* removeAtual(struct NO* atual){
    struct NO *no1, *no2;
    if(atual->esq = NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2 ->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int consultaArvore(arvBin* raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}
