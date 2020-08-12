#include <stdio.h>
#include <math.h>
#include "listaSequencial.h"


int main(){
    Lista* li = criar_lista();
    struct aluno teste;
    
    teste.matricula = 1;
    int x = Inserir_lista_inicio(li, teste);
    printf("%d \n", x);
    teste.matricula = 2;
    x = Inserir_lista_fim(li, teste);
    printf("%d \n", x);
    teste.matricula = 3;
    x = Inserir_lista_inicio(li, teste);
    printf("%d \n", x);
    teste.matricula = 4;
    x = Inserir_lista_meio(li, teste, 2);
    printf("%d \n", x);

    x = Tamanho_lista(li);
    printf("Tamannho1 %d \n",x);

    imprimir(li);

   
    int y = consultar_lista_pos(li,2, &teste);
    printf("%d \n", y);

    int z = consultar_lista_conteudo( li, 4, &teste);
    printf("%d \n", z);

    x = remover_lista_meio(li, 4);
    printf("%d \n", x);
    x = Tamanho_lista(li);
    printf("Tamannho2 %d \n",x);
    imprimir(li);
    
    

    Liberar_lista(li);

    printf("Lista liberada com sucesso \n");

    

}