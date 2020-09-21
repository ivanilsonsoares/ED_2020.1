#include <stdio.h>
#include <stdlib.h>
#include "arvBin.h"

struct NO{
    int info;
    struct NO* esq;
    struct NO* dir;
};

arvBin* criar_bin(){
    arvBin* raiz = (arvBin*) malloc(sizeof(arvBin));
    if(raiz != NULL){
        *raiz = NULL;
    }
    
    return raiz;
}

int inserir(int valor, arvBin* raiz, arvBin esq, arvBin dir){
    arvBin no = (arvBin) malloc(sizeof(arvBin));
    if(raiz == NULL){
        return 0;
    }
    no->info = valor;
    no->esq = esq;
    no->dir = dir;
    return 1;
}

void liberarNo(struct NO* no){
    if(no == NULL){
        return;
    }
    liberarNo(no->esq);
    liberarNo(no->dir);
    free(no);
    no = NULL;
}

void liberar_bin(arvBin* raiz){
    if(raiz == NULL){
        return;
    }
    liberarNo(*raiz);
    free(raiz);
}

int vazia_bin(arvBin* raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

int altura_bin(arvBin* raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int altEsq = altura_bin(&((*raiz)->esq));
    int altDir = altura_bin(&((*raiz)->dir));
    if(altEsq > altDir){
        return(altEsq + 1);
    }else{
        return(altDir + 1);
    }
}

int total_bin(arvBin* raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int altEsq = total_bin(&((*raiz)->esq));
    int altDir = total_bin(&((*raiz)->dir));
    return(altEsq + altDir + 1);
}

void preOrdem_bin(arvBin* raiz){
    if(raiz ==NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d \n",(*raiz)->info);
        preOrdem_bin(&((*raiz)->esq));
        preOrdem_bin(&((*raiz)->dir));
    }
}

void emOrdem_bin(arvBin* raiz){
     if(raiz ==NULL){
        return;
    }
    if(*raiz != NULL){
        preOrdem_bin(&((*raiz)->esq));
        printf("%d \n",(*raiz)->info);
        preOrdem_bin(&((*raiz)->dir));
    }
}

void posOrdem(arvBin* raiz){
     if(raiz ==NULL){
        return;
    }
    if(*raiz != NULL){
        preOrdem_bin(&((*raiz)->esq));
        preOrdem_bin(&((*raiz)->dir));
        printf("%d \n",(*raiz)->info);
    }
}


