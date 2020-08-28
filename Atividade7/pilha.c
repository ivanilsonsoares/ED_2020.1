#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha{
    int qtd;
    struct aluno dados[MAX];
};
typedef struct pilha Pilha;

Pilha* criar_pilha(){
    Pilha *pi;
    pi = (Pilha*) malloc(sizeof(struct pilha));
    if(pi != NULL){
        pi->qtd = 0;
    }
    return pi;
}

void Liberar_pilha(Pilha* pi){
    free(pi);
}

int tamanho_pilha(Pilha* pi){
    if(pi == NULL){
        return -1;
    }else{
        return pi->qtd;
    }
}

int pilha_cheia(Pilha* pi){
    if(pi == NULL){
        return -1;
    }
    return(pi->qtd == MAX);
}

int pilha_vazia(Pilha* pi){
    if(pi == NULL){
        return -1;
    }
    return(pi->qtd == 0);
}

int inserir_pilha(Pilha* pi, struct aluno al){
    if(pi == NULL){
        return 0;
    }
    if(pilha_cheia(pi)){
        return 0;
    }
    pi->dados[pi->qtd] = al;
    pi->qtd++;
    return 1;
}

int remover_pilha(Pilha* pi){
    if(pi == NULL || pi->qtd == 0){
        return 0;
    }
    pi->qtd--;
    return 1;
}

int consulta_pilha(Pilha* pi, struct aluno *al){
    if(pilha_vazia(pi)){
        return 0;
    }
    *al = pi->dados[pi->qtd-1];
    return 1;


}

void imprimir(Pilha* pi){
    for(int i = 0; i <= pi->qtd; i++){
        printf("%d, ", pi->dados[i].matricula);
    }

}
