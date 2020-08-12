#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCircular.h"

int main(){
    Lista* li;
    li = criar_lista();
    struct aluno teste;
    struct aluno teste1;
    struct aluno teste2;
    struct aluno teste3;

    int w = tamanho_lista(li);
    printf("tamanho: %d\n",w);
    teste.matricula = 1;
    strcpy(teste.nome, "Teste");
    teste.n1 = 10;
    int y = inserir_inicio(li,teste);
    printf("Inicio: %d\n", y);
    teste1.matricula =10;
    y = inserir_inicio(li,teste1);
    printf("Inicio: %d\n", y);
    teste2.matricula = 12;
    y = inserir_final(li,teste2);
    printf("Final: %d\n", y);

    int z = tamanho_lista(li);
    printf("tamanho: %d\n",z);

    imprime_lista(li);

    int r = consulta_valor(li,12,&teste);
    printf("Consulta valor: %d\n", r);

    // int t = remover_meio(li,1);
    // printf("final: %d\n", t);
    teste3.matricula =0;
    int g = inserir_ordenado(li, teste3);
    printf("ordem: %d\n", g);

    z = tamanho_lista(li);
    printf("tamanho: %d\n",z);

    imprime_lista(li);


}