typedef struct NO* arvBin;

arvBin* criar_bin();

int inserir(int valor, arvBin* raiz, arvBin esq, arvBin dir);

void liberarNo(struct NO* no);

void liberar_bin(arvBin* raiz);

int vazia_bin(arvBin* raiz);

int altura_bin(arvBin* raiz);

int total_bin(arvBin* raiz);

void preOrdem_bin(arvBin* raiz);

void emOrdem_bin(arvBin* raiz);

void posOrdem(arvBin* raiz);


