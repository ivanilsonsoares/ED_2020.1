struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

struct aluno V[6];

int BuscaLinear(int *V,int N, int Elem);

int BuscaOrdenada(int *V, int N, int Elem);

int BuscaBinaria(int *V, int N, int Elem);

int BuscaLinearMatricula(struct aluno *V, int N, int Elem);

int BuscaLinearNome(struct aluno *V, int N, char* Elem);

void BubbleSort(int *V, int N);

void InsertSort(int *V, int N);

void SelectionSort(int *V, int N);

void MergeSort(int *V, int ini, int fim);

void Merge(int *V, int ini, int meio, int fim);