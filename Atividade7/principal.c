#include <stdio.h>
#include <math.h>
#include "pilha.h"

int main(){
    Pilha *pi = criar_pilha();
    struct aluno teste;
    teste.matricula = 5;
    
    
    int x = inserir_pilha(pi,teste);
    printf("|%d|\n", x);
    

    x = inserir_pilha(pi,teste);
    teste.matricula = 3;
    printf("{%d}\n", x);

    x = inserir_pilha(pi,teste);
    teste.matricula = 6;
    printf("[%d]\n", x);

    imprimir(pi);

    int y = remover_pilha(pi);
    printf("(%d)\n", y);

    imprimir(pi);

    x = inserir_pilha(pi,teste);
    teste.matricula = 8;
    printf("[%d]\n", x);

    imprimir(pi);

    int w = consulta_pilha(pi, &teste);
    printf("\n %d\n",w);

}