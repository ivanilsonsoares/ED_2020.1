#include <stdio.h>
#include <stdlib.h>
#include "ListaEncad.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;


void liberar_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while ((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL){
        return 0;
    }
    int cont = 0;
    Elem *no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}

int inserir_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int inserir_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no ==NULL){
        return 0;
    }
    no->dados = al;
    if(lista_vazia(li)){
        no->prox =(*li);
        *li = no;
        return 1;
    }else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no ->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}

int inserir_lista_final(Lista* li, struct aluno al){
     if(li == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no->prox == NULL){
        no->dados = al;
        no->prox = (*li);
        *li = no;
        return 1;
    }
}

int remover_lista_inicio(Lista* li){
    if(lista_vazia(li)){
        return 0;
    }
    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remover_lista_final(Lista* li){
    if(lista_vazia(li)){
        return 0;
    }
    Elem *ant, *no = *li;
    while (no->prox != NULL){
        ant = no; 
        no = no->prox;
    }
    if(no == (*li)){
        *li =no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int remover_lista_meio(Lista* li,int mat, struct aluno al){
    if(lista_vazia(li)){
        return 0;
    }
    int tam = tamanho_lista(li);
    Elem  *ant, *no = *li;

      if(mat == 1){
        remover_lista_inicio(li);
        return 1;
    }else if(mat == tam){
        remover_lista_final(li);
        return 1;
    }else{
       while(no != NULL && no->dados.matricula != mat){
           no= no->prox;
       }
       if(no == NULL){
           return 0;
       }else{
           ant->prox = no->prox;
           free(no);
           return 1;
       }
    }
    return 0;
}

int consulta_list_mat(Lista* li, int matricula, struct aluno *al){
    if(li==NULL){
        return 0;
    }
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != matricula){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *al = no->dados;
        return 1;
    }
}

int consulta_list_pos(Lista* li, int posicao, struct aluno *al){
    int tam = tamanho_lista(li);
    if(lista_vazia(li)){
        return 0;
    }
    if(tam < posicao){
        return 0;
    }
    
    for(int i = 0; i <=tam; i++){
        if(i == posicao){
            return 1;
        }
    }
}
void imprimir(Lista* li){
    Elem *aux;
    aux = *li;
   while (aux!=NULL){
     printf ("%d \n",aux->dados.matricula);
     aux=aux->prox;
   }
}
