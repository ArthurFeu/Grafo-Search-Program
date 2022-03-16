#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo* cria_Grafo(int nro_vertices, int grau_max){
    Grafo *gr=(Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;//nro total de vértices no grafo
        gr->grau_max = grau_max;//quantidade máxima de ligações por vértice
        gr->grau=(int*) calloc(nro_vertices,sizeof(int));//alocando * grau dos vértices em 0
        gr->dist=(int*) malloc(nro_vertices*sizeof(int));
        gr->pred=(int*) malloc(nro_vertices*sizeof(int));
        gr->arestas=(int**) calloc(nro_vertices,sizeof(int*));//alocando ** arestas
        for(i=0; i<nro_vertices; i++){//alocando * arestas
            gr->arestas[i] = (int*) calloc(grau_max,sizeof(int));
            gr->dist[i] = 1000;//valor absurdo
            gr->pred[i] = -1;//vertice inexistente
        }
    }
return gr;
}
void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0;i<gr->nro_vertices;i++)
            free(gr->arestas[i]);//libera as colunas da matriz aresta
        free(gr->arestas);//libera a linha da matriz arestas
        free(gr->grau);//libera o valor de grau
        free(gr);//libera grafo
    }
}
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)//verifica se vértice de origem existe
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)//verifica se vértice de destino existe
        return 0;

    setbuf(stdin, NULL);
    gr->arestas[orig][dest] = 1;//insere aresta ligando ao destino
    gr->grau[orig]++;//aumenta o valor do grau do vértice de origem

    if(eh_digrafo == 0)
        insereAresta(gr, dest, orig, 1, peso);//insere outra aresta se não for digrafo
return 1;
}

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)//verifica se vértice de origem existe
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)//verifica se vértice de destino existe
        return 0;

    gr->grau[orig]--;//diminui o grau do vértice origem
    gr->arestas[orig][dest] = 0;//substitui o elemento a ser removido por 0
    if(eh_digrafo == 0)
        removeAresta(gr, dest, orig, 1);//remove outra aresta se não for digrafo
return 1;
}



void mostraGrafoM(Grafo *gr) {
    printf("Grafo:\n");
    for (int i = 0; i < gr->nro_vertices; i++) {
        for (int j = 0; j < gr->nro_vertices; j++) {
            printf("%i-", gr->arestas[i][j]);
        }
        printf("\n");
    }
}                                                                                                                                                                             
