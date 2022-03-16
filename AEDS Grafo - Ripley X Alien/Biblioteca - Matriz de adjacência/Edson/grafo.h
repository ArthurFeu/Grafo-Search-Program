struct grafo{
    int nro_vertices;
    int grau_max;
    int** arestas;
    int* grau;
    int* dist;
    int* pred;
    int* info;
    char* cor;
};
typedef struct grafo Grafo;

typedef struct fila{
	int size;//Tamanho máximo da fila, ou seja, o número de vértices do grafo
	int fila[size];
	int ini;//Variável de referência do nó inicial da fila
	int fim;//Variável de referência do nó final da fila
	int d[size];//(Menor)Distância em relação ao nó raiz
	int pred[size];//Predecessor do nó em questão
}QUEUE;

Grafo *cria_Grafo(int nro_vertices, int grau_max);
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo);
int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);
QUEUE *criaFila(int size);
void enqueue(QUEUE *F, int s);
int dequeue(QUEUE *F);
int filaCheck(QUEUE *F)
void buscaLargura_Grafo(Grafo *gr, int ini);
void mostraGrafoM(Grafo *gr);

