#include <stdlib.h>
#include <stdio.h>
#include "trab.h"

Grafo* cria_Grafo(int size, int grau_max){//Cria e inicializa o grafo
    int i;
    Grafo *gr = (Grafo*) malloc(sizeof(Grafo));

    gr->size = size;//Número total de vértices no grafo
    gr->grau_max = grau_max;//Quantidade máxima de ligações por vértice
    gr->grau = (int*) calloc(size,sizeof(int));//Alocando * grau dos vértices em 0
    gr->dist = (int*) malloc(size*sizeof(int));
    gr->pred = (int*) malloc(size*sizeof(int));
    gr->info = (int*) malloc(size*sizeof(int));
    gr->cor = (char*) malloc(size*sizeof(char));
    gr->arestas = (int**) calloc(size,sizeof(int*));//Alocando ** arestas
    for(i = 0; i < size; i++){
        gr->arestas[i] = (int*) calloc(size,sizeof(int));//Alocando * arestas
        gr->dist[i] = 1000;//Valor absurdo (infinito)
        gr->pred[i] = -1;//Vértice inexistente (inválido)
        gr->cor[i] = 'w';
    }

return gr;
}

void insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return;
    if(orig < 0 || orig >= gr->size)//Verifica se vértice de origem existe
        return;
    if(dest < 0 || dest >= gr->size)//Verifica se vértice de destino existe
        return;

    gr->arestas[orig][dest] = 1;//Insere aresta na matriz
    gr->grau[orig]++;//Atualiza o grau do vértice de origem

    if(eh_digrafo == 0)//Insere outra aresta se o grafo for não-direcionado
        insereAresta(gr, dest, orig, 1);
}

void printMatriz(Grafo *G){
	int k, i;

	for(k = 0;k < G->size;k++)
		printf("\t%i",k);
	for(i = 0;i < G->size;i++){
		printf("\n%i: ",i);
		for (int j = 0;j < G->size;j++)
			printf("%i\t",G->arestas[i][j]);
	}
}

void mostraGrafoM(Grafo *gr){
    printf("Grafo:\n");
    for (int i = 0; i < gr->size; i++) {
        for (int j = 0; j < gr->size; j++) {
            printf("%i-", gr->arestas[i][j]);
        }
        printf("\n");
    }
}   

QUEUE *criaFila(int size){
	int i;
	QUEUE *F = (QUEUE*) malloc(sizeof(QUEUE));
	F->fila = (int*) malloc(size * sizeof(int));

	F->size = size;
	F->ini = F->fim = -1;
	for(i = 0; i < size; i++)
		F->fila[i] = -1;//A fila é inicializada como "vazia"

	return F;
}

void enqueue(QUEUE *F, int s){
	if(F->ini == -1)//Caso se o primeiro item a ser inserido na fila
		F->ini = 0;
	F->fim++;//F->fim = 0, ou seja, F->fim = F->ini
	F->fila[F->fim] = s;//Insere o item no final da fila
}

int dequeue(QUEUE *F){
	int item;

	item = F->fila[F->ini];//Retira o item que está na fila a mais tempo
	F->ini++;//Atualiza a posição da fila

	return item;
}

int filaCheck(QUEUE *F){//Checa se a fila está vazia ou não
	if(F->ini > F->fim)
		return 1;
	else
		return 0;
}

void BFS(Grafo *G, int s){
	QUEUE *F = criaFila(G->size);
	int D = 0;

	enqueue(F,s);//Insere o nó inicial na fila
	G->cor[s] = 'g';//E marca ele como visitado, ou seja, cinza (grey)
	G->dist[s] = D;//D = 0

	while(!filaCheck(F)){//Continua rodando enquanto a fila não estiver vazia
		s = dequeue(F);//Retira o nó mais antigo da fila
		G->cor[s] = 'b';//E o marca como "completo", ou seja, preto (black)
		D++;
		for(int i = 0; i < G->size; i++){//Isso eh bemmm ineficiente me parece...
			if(G->arestas[i][s] == 1 && G->cor[i] == 'w'){//Descobre todos os nós adjacentes
				enqueue(F,i);//Insere cada um deles na fila
				G->cor[i] = 'g';//E os marca como visitados
				G->dist[i] = D;/*Define a distância do nó a partir da camada em que o mesmo
								se encontra em relação ao nó inicial*/
				G->pred[i] = s;//Define o predecessor deste como o último nó retirado da fila
			}
		}
	}
}

Grafo* resetGrafo(Grafo *G){//Reinicializa as variáveis do grafo necessárias à BFS
	for(int i = 0; i < G->size; i++){
		G->dist[i] = 1000;//Distância começa como "infinita"
		G->cor[i] = 'w';//Todos nodes são desconhecidos
		G->pred[i] = -1;//Todos os predecessores são desconhecidos
	}

	return G;
}

int turnoRipley(Grafo *G, int ripley, QUEUE *caminho){/*Move a Ripley de acordo com o
														caminho fornecido pela BFS*/
	int temp = G->pred[6], i = 0, j = 0;
	while(temp != ripley){
		i = temp;
		temp  = G->pred[i];

	}//Ao final do while: "temp" = "ripley" e "i" = próximo node de acordo com o caminho

	if(ripley + 1 == 6){
		G->info[ripley]--;
		G->info[6]++;

		return 6;
	}
	if(G->info[i] == 2){//Caso o próximo node esteja ocupado pelo Alien
		if(G->grau[temp] > 1){//Caso o node que a ripley esteja tenha mais de uma aresta
			while(j < G->size){
				if(G->arestas[temp][j] == 1 && G->info[j] != 2){//Encontra um node adjacente
					i = j;										//que o Alien não esteja
					break;
				}
				j++;
			}
		}
	}

	G->info[ripley]--;//A Ripley sai do nó atual
	G->info[i]++;//A Ripley entra no nó seguinte
	enqueue(caminho,i);//Atualiza o caminho que a Ripley está fazendo

	return i;
}

int turnoAlien(Grafo *G, int alien, int hard){
	int temp = G->pred[6], i = 0;

	if(hard == 1){
		while(temp != alien){
			i = temp;
			temp = G->pred[i];
		}
		G->info[alien] -= 2;
		G->info[i] += 2;
	}else{
		while(1){
			if(G->arestas[alien][i] == 1){
				G->info[alien] -= 2;
				G->info[i] += 2;
				break;
			}
			i++;
		}
	}

	return i;
}

void spawn(Grafo *G, int ripley, int alien){
	G->info[ripley]++;// G->info[ripley] = 1
	G->info[alien] += 2;
}