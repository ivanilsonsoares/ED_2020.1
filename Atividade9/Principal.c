#include <stdio.h>
#include <math.h>
#include "Ordenacao.h"

int main(){
    struct aluno V[4] = {(2, "euu",9.5,7.8,8.0),
                        (3, "eu",9.5,7.8,8.0),
                        (4, "eu",9.5,7.8,8.0),
                        (5, "eu",9.5,7.8,8.0)};
    int vet[5] = {-5,-8,1,4,14};

    printf("Qual algoritomo deseja?\n");
    int opc;
    scanf("%d", &opc);

    switch (opc){
    case 1:
        if (BuscaLinear(vet,5,4) == 1){
            printf("Busca linear realizada com sucesso\n");
            
        }else{
            printf("Valor não encontrado");
        }
        break;
    case 2:
         if (BuscaOrdenada(vet,5,0) == 1){
            printf("Busca ordenada realizada com sucesso\n");            
        }else{
            printf("Valor não encontrado");
        }
        
        break;
    case 3:
        if (BuscaBinaria(vet,5,1) != -1){
            printf("Busca binaria realizada com sucesso\n");

        }else{
            printf("Valor não encontrado");
        }
        break;
    case 4:
         if (BuscaLinearMatricula(V,4,5) != -1){
            printf("Busca binaria realizada com sucesso\n");

        }else{
            printf("Valor não encontrado");
        }
        break;
    case 5:
        if (BuscaLinearNome(V,4,"euu") != -1){
            printf("Busca binaria realizada com sucesso\n");

        }else{
            printf("Valor não encontrado");
        }
        break;
    case 6:
        BubbleSort(vet,4);
        printf("Realizado com sucesso\n");
        break;
    case 7:
        InsertSort(vet,4);
        printf("Realizado com sucesso\n");
        break;
    case 8:
        SelectionSort(vet,4);
        printf("Realizado com sucesso\n");
        break;
    case 9:
        MergeSort(vet,-8,14);
        printf("Realizado com sucesso\n");
        break;
    default:
        break;
    }
    
}