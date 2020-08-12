#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ListaEncad.h"

int main(){
    Lista* li = (Lista*) malloc(sizeof(Lista));

    struct aluno teste;
    
    teste.matricula = 1;
    int x = inserir_lista_inicio(li, teste);
    printf("Inicio: %d\n", x);
    teste.matricula = 3;
    x = inserir_lista_inicio(li, teste);
    printf("inicio: %d\n", x);
    teste.matricula = 2;
    x = inserir_lista_ordenada(li, teste);
    printf("ordenado: %d\n", x);

    teste.matricula = 4;
    x = inserir_lista_final(li, teste);
    printf("Final: %d\n", x);

    int q = tamanho_lista(li);
    printf("Tamanho: %d\n", q);
    // int y = remover_lista_inicio(li);
    // printf("Remover inicio: %d\n", y);

    int z = consulta_list_pos(li, 1, &teste);
    printf("Consulta posicao: %d\n", z);
    imprimir(li);
    int w = remover_lista_meio(li, 3, teste);
    printf("Remover meio: %d\n", w);
    imprimir(li);

}