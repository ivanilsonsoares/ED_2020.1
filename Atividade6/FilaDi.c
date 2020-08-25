#include <stdio.h>
#include <stdlib.h>
#include "FilaDi.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};

Fila* criar_fila(){
    Fila* fi =(Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void Liberar_fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_fila(Fila* fi){
    if(fi == NULL){
        return 0;
    }
    int cont = 0;
    Elem* no = fi->inicio;
    while(no!=NULL){
        cont++;
        no=no->prox;
    }
    return cont;
}

int fila_cheia(Fila* fi){
    return 0;
}

int fila_vazia(Fila* fi){
    if(fi==NULL){
        return 1;
    }
    if(fi->inicio == NULL){
        return 1;
    }
    return 0;
}

int inserir_fila(Fila* fi, struct aluno al){
    if(fi==NULL){
        return 0;
    }
    Elem *no =(Elem*)malloc(sizeof(Elem));
    if(no==NULL){
        return 0;
    }
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL){
        fi->inicio = no;
    }else{
        fi->final->prox = no;
    }
    fi->final = no; // realizar movimentação(caso não o valor é subescrito)
    return 1;
}

int remover_fila(Fila* fi){
    if(fi == NULL){
        return 0;
    }
    if(fi->inicio == NULL){
        return 0;
    }
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL){
        fi->final = NULL;
    }
    free(no);
    return 1;
}

int consulta_fila(Fila* fi, struct aluno *al){
    if(fi == NULL){
        return 0;
    }
    if(fi->inicio == NULL){
        return 0;
    }
    *al = fi->inicio->dados;
    return 1;
}

void imprimir(Fila* fi) {
    Elem *no;
    if(fila_vazia(fi)){
        printf("Lista vazia\n");
    }
    no = fi->inicio;

    while(no !=NULL){
        printf("%d ,", no->dados.matricula);
        no = no->prox;
    }
}