#include <stdio.h>
#include <stdlib.h>
#include "arvBin.h"

int main(){
    arvBin* raiz = criar_bin();

    int r = inserir(50,raiz,NULL,NULL);
    printf("%d\n", r);

    int y = altura_bin(raiz);
    printf("altura: %d\n", y);

    int x = total_bin(raiz);
    printf("total: %d\n", x);

    printf("pre\n");
    preOrdem_bin(raiz);
    printf("em\n");
    emOrdem_bin(raiz);
    printf("pos\n");
    posOrdem(raiz);

    liberar_bin(raiz);



}