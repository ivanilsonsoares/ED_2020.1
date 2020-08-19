#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
    int inicio,final,qtd;
    struct aluno dados[MAX];
};
typedef struct fila Fila;

Fila* criar_fila(){
    Fila *fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void Liberar_fila(Fila* fi){
    free(fi);
}

int tamanho_fila(Fila* fi){
    if(fi==NULL){
        return -1;
    }
    return fi->qtd;
}

int fila_cheia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    if(fi->qtd == MAX){
        return 1;
    }else{
        return 0;
    }
}

int fila_vazia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    if(fi->qtd == 0){
        return 1;
    }else{
        return 0;
    }
}

int inserir_fila(Fila* fi, struct aluno al){
    if(fi == NULL){
        return 0;
    }
    if(fila_cheia(fi)){
        return 0;
    }
    fi->dados[fi->final] = al;
    fi->final = (fi->final+1)%MAX;
    fi->qtd++;
    return 1;
}

int remover_fila(Fila* fi){
    if(fila_vazia(fi)){
        return 0;
    }
    fi->inicio = (fi->inicio+1)%MAX;
    fi->qtd--;
    return 1;
}

int consulta_fila(Fila* fi, struct aluno *al){
    if(fila_vazia(fi)){
        return 0;
    }
    *al = fi->dados[fi->inicio];
    return 1;
}

void imprimir(Fila* fi){
    for(int i = 0; i<=tamanho_fila(fi); i++){
        printf(" %d, ", fi->dados[i].matricula);
    }
}
