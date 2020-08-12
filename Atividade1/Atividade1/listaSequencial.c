#include <stdio.h>
#include <stdlib.h>
#include "listaSequencial.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};
typedef struct lista Lista;

Lista* criar_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li !=NULL){
        li->qtd = 0;
    }
    return li;
}

void Liberar_lista(Lista* li){
    free(li);
}

int Tamanho_lista(Lista* li){
    if(li == NULL){
        return -1;
    }else{
        return li->qtd;
    }
}

int Lista_cheia(Lista* li){
    if(li == NULL){
        return -1;
    }
    return(li->qtd==MAX);
}

int Lista_vazia(Lista* li){
    if(li == NULL){
        return -1;
    }
    return(li->qtd = 0);
}

int Inserir_lista_inicio(Lista* li, struct aluno al){
    int i;
    if(li==NULL){
        return 0;
    }
    if(Lista_cheia(li)){
        return 0;
    }
    for(i =li->qtd-1;i>=0;i--){
        li->dados[i+1] = li->dados[i];
    }
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int Inserir_lista_meio(Lista* li, struct aluno al, int posicao){
    if(li==NULL){
        return 0;
    }
    if(Lista_cheia(li)){
        return 0;
    }
    if(posicao>0 && posicao <= Tamanho_lista(li)){
        for (int k =li->qtd-1;k >=posicao;k--){
        li->dados[k+1] = li->dados[k];
    }
    li->dados[posicao] = al;
    li->qtd++;
    return 1;
    }
}

int Inserir_lista_fim(Lista* li, struct aluno al){
    if(li==NULL){
        return 0;
    }
    if(Lista_cheia(li)){
        return 0;
    }
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int remover_lista_inicio(Lista* li){
    if(li== NULL){
        return 0;
    }
    if(li->qtd ==0){
        return 0;
    }
    int k;
    for (k = 0;k < li->qtd-1;k++){
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
}

int remover_lista_meio(Lista* li, int posicao){
    if(li== NULL){
        return 0;
    }
    if(li->qtd ==0){
        return 0;
    }
    if(posicao>0 && posicao <= Tamanho_lista(li)){
        for (int k =li->qtd-1;k >=posicao;k--){
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
    }

}

int remover_lista_fim(Lista* li){
    if(li == NULL){
        return 0;
    }
    if(li->qtd == 0){
        return 0;
    }
    li->qtd--;
    return 1;
}

int consultar_lista_pos(Lista* li, int posicao, struct aluno *al){
    if(li==NULL || posicao <=0|| posicao > li->qtd){
        return 0;
    }
    *al = li->dados[posicao-1];
    return 1;
}

int consultar_lista_conteudo(Lista* li, int conteudo, struct aluno *al){
    int i =0;
    while(i <=Tamanho_lista(li)){
        if(conteudo == li->dados[i].matricula){
            return 1;
        }else{
            i++;
        }
    }
    return 0;
}

void imprimir(Lista* li){
    for(int i = 0; i<=Tamanho_lista(li); i++){
        printf(" %d, ", li->dados[i].matricula);
    }
}


