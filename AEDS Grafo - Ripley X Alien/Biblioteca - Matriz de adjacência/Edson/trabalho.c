#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
int main(){
    Grafo* gr = cria_Grafo(18, 7, 0);
    insereAresta(gr, 0, 1, 0, 0);
    insereAresta(gr, 1, 2, 0, 0);
    insereAresta(gr, 2, 3, 0, 0);
    insereAresta(gr, 2, 4, 0, 0);
    insereAresta(gr, 2, 5, 0, 0);
    insereAresta(gr, 2, 7, 0, 0);
    insereAresta(gr, 5, 6, 0, 0);
    insereAresta(gr, 7, 8, 0, 0);
    insereAresta(gr, 8, 9, 0, 0);
    insereAresta(gr, 9, 10, 0, 0);
    insereAresta(gr, 10, 11, 0, 0);
    insereAresta(gr, 10, 12, 0, 0);
    insereAresta(gr, 12, 13, 0, 0);
    insereAresta(gr, 13, 2, 0, 0);
    insereAresta(gr, 13, 14, 0, 0);
    insereAresta(gr, 13, 15, 0, 0);
    insereAresta(gr, 14, 15, 0, 0);
    insereAresta(gr, 14, 17, 0, 0);
    insereAresta(gr, 15, 16, 0, 0);
    mostraGrafoM(gr);
    //int vis[18];

    //buscaLargura_Grafo(gr, 0, vis);
return 0;
}