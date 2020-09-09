#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include "Ordenacao.h"

int BuscaLinear(int *V, int N, int Elem)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (Elem == V[i])
        {
            return i;
        }
    }
    return -1;
}

int BuscaOrdenada(int *V, int N, int Elem)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (Elem == V[i])
        {
            return i;
        }
        else
        {
            if (Elem < V[i])
            {
                return -1;
            }
        }
    }
    return -1;
}

int BuscaBinaria(int *V, int N, int Elem){
    int i, ini, meio, fim;
    ini = 0;
    fim = N-1;
    while(ini<= fim){
        meio = (ini +fim)/2; // divisão do vetor para encontrar o meio
        if(Elem< V[meio]){
            fim = meio -1; // parte da esquerda 
        }else{
            if(Elem > V[meio]){
                ini = meio+1; // parte da direita 
            }else{
                return meio; 
            }
        }
        return -1;
    }


}

int BuscaLinearMatricula(struct aluno *V, int N, int Elem)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (Elem == V[i].matricula)
        {
            return i;
        }
        return -1;
    }
}

int BuscaLinearNome(struct aluno *V, int N, char* Elem)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (strcmp(Elem,V[i].nome) == 0)
        {
            return 1;
        }
    }
    return -1;
}

void BubbleSort(int *V, int N)
{
    int i, continua, aux, fim = N;
    do
    {
        continua = 0;
        for (i = 0; i < fim - 1; i++)
        {
            if (V[i] > V[i + 1])
            {
                aux = V[i];
                V[i] = V[i + 1];
                V[i + 1] = aux;
                continua = i;
            }
        }
        fim--;
    } while (continua != 0);

    for(i = 0; i<= fim + 1; i++){
        printf("%d, ", V[i]);
    }
}

void InsertSort(int *V, int N)
{
    int i, j, aux;
    for (i = 1; i < N; i++)
    {
        aux = V[i];
        for (j = i; (j > 0) && (aux < V[j - 1]); j--)
        {
            V[j] = V[j - 1];
        }
        V[j] = aux;
    }
}

void SelectionSort(int *V, int N)
{
    int i, j, menor, troca;
    for (i = 0; i < N - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < N; j++)
        {
            if (V[j] < V[menor])
            {
                menor = j;
            }
        }
        if (i != menor)
        {
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}

void MergeSort(int *V, int ini, int fim){
    int meio;
    if(ini<fim){
        meio = (ini + fim)/2; // calcular o meio e arredondar o valor
        MergeSort(V,ini,fim); // recursividade 
        MergeSort(V,ini,fim);
        Merge(V,ini,meio,fim);
    }
}

void Merge(int *V, int ini, int meio, int fim){
    int *aux, parte1, parte2, tam, i , j, k;
    int fim1 = 0, fim2 = 0;
    tam = fim-ini+1;
    parte1 = ini;
    parte2 = meio +1;
    aux = (int *) malloc(tam* sizeof(int));
    if(aux != NULL){
        for(i = 0; i<tam; i++){
            if(!fim1 && fim2){
                if(V[parte1]< V[parte2]){
                    aux[i] = V[parte1++];
                }else{
                    aux[i] = V[parte2++];
                }
                if(parte1>meio){
                    fim1 = 1;
                }
                if(parte2> fim){
                    fim2 =1;
                }
            }else{
                if(!fim1){
                    aux[i] = V[parte1++];
                }else{
                    aux[i] = V[parte2++];
                }
            }
        }
        for(j = 0, k=ini;j<tam;j++, k++){
            V[k] != aux[j];
        }
    }
    free(aux);
}

