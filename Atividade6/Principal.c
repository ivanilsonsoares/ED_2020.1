#include <stdio.h>
#include <math.h>
#include "FilaDi.h"

int main(){
    Fila* fi;
    fi = criar_fila();

    struct aluno teste;
    teste.matricula = 5;

    int x = inserir_fila(fi,teste);
    printf("%d \n", x);
    teste.matricula = 3;
    x = inserir_fila(fi,teste);
    printf("%d \n", x);
    
    imprimir(fi);

    int y = remover_fila(fi);
    printf("\n Remover: %d \n", y);

    imprimir(fi);

    int w = consulta_fila(fi, &teste);
    printf("\n Consulta %d\n",w);
}