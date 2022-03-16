typedef struct grafo
{
    int size;//Número de vértices que o grafo contém
    int grau_max;//O grau máximo permitido para cada vértice
    int** arestas;//A matriz de Adjacência
    int* grau;//Contém o grau de cada nó 
    int* dist;//Contém a menor distância de cada nó em relação ao nó inicial
    int* pred;//Contém o predecessor de cada nó em relação à distância citada acima ^^^
    int* info;/*Contém o conteúdo de cada nó, ou seja, de cada sala da nave
				(0 -> ninguém / 1 -> Ripley / 2 -> Alien / 3 -> Ambos = Ripley morta)*/
    char* cor;//Contém o estado (cor) de cada nó (branco 'w' / cinza 'g' / preto 'b')
}Grafo;

typedef struct fila
{
	int size;//Tamanho máximo da fila, ou seja, o número de vértices do grafo
	int* fila;//A fila em si
	int ini;//Variável de referência do nó inicial da fila
	int fim;//Variável de referência do nó final da fila
}QUEUE;

Grafo *cria_Grafo(int nro_vertices, int grau_max);
void insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo);
void printMatriz(Grafo *G);
void spawnRipley(Grafo *G,int v);
QUEUE *criaFila(int size);
void enqueue(QUEUE *F, int s);
int dequeue(QUEUE *F);
int filaCheck(QUEUE *F);
void BFS(Grafo *G, int s);
Grafo* resetGrafo(Grafo *G);
int turnoRipley(Grafo *G, int ripley, QUEUE *caminho);
int turnoAlien(Grafo *G, int alien, int hard);
void spawn(Grafo *G, int ripley, int alien);
void mostraGrafoM(Grafo *gr);