#include <stdio.h>
#include <math.h>
#include "pilhaDi.h"

int main(){
    Pilha *pi = criar_pilha();
    struct aluno teste;
    struct aluno teste2;
    struct aluno teste3;
    struct aluno teste4;
    teste.matricula = 5;
    
    
    int x = inserir_pilha(pi,teste);
    printf("inserir 1|%d|\n", x);
    imprimir(pi);    

    teste2.matricula = 3;
    int y = inserir_pilha(pi,teste2);
    printf("inserir 2 {%d}\n", y);

    imprimir(pi);

    teste3.matricula = 6;
    x = inserir_pilha(pi,teste3);
    
    printf("inserir 3 [%d]\n", x);

    imprimir(pi);

    int z = remover_pilha(pi);
    printf("Remover (%d)\n", z);

    imprimir(pi);
    
    teste4.matricula = 8;
    x = inserir_pilha(pi,teste4);
    
    printf("inserir 4 [%d]\n", x);

    imprimir(pi);

    int w = consulta_pilha(pi, &teste);
    printf("\n consulta  %d\n",w);

    int f = tamanho_pilha(pi);
    printf("\n tamanho  %d\n",f);

}