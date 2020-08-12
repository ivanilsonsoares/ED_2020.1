#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDupla.h"

int main(){
    Lista* li;
    li = criar_lista();
    struct aluno teste;
    struct aluno teste1;
    struct aluno teste2;
    teste.matricula = 1;
    strcpy(teste.nome, "Teste");
    teste.n1 = 10;
    int y = inserir_lista_inicio(li,teste);
    printf("Inicio: %d\n", y);
    teste1.matricula = 3;
    int w = inserir_lista_final(li,teste1);
    printf("Final: %d\n", w);
    teste2.matricula = 4;
    int r = inserir_lista_final(li,teste2);
    printf("Final: %d\n", r);
    int x = tamanho_lista(li);
    printf("Tamanho: %d\n", x);

    imprimir(li);
    int q = remover_lista_meio(li,2);
    printf("Remove: %d \n", q);

    int h = tamanho_lista(li);
    printf("Tamanho: %d\n", h);

    int z = consulta_lista_valor(li, 4, &teste);
    printf("Consulta valor: %d\n", z);

    imprimir(li);
    

}