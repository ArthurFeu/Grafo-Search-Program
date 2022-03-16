#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "trab.h"
 
int main(){
    int ripley, alien;
    QUEUE* caminho = criaFila(100);
    Grafo* G = cria_Grafo(18,6);
    insereAresta(G, 0, 1, 0);
    insereAresta(G, 1, 2, 0);
    insereAresta(G, 2, 3, 0);
    insereAresta(G, 2, 4, 0);
    insereAresta(G, 2, 5, 0);
    insereAresta(G, 2, 7, 0);
    insereAresta(G, 5, 6, 0);
    insereAresta(G, 7, 8, 0);
    insereAresta(G, 8, 9, 0);
    insereAresta(G, 9, 10, 0);
    insereAresta(G, 10, 11, 0);
    insereAresta(G, 10, 12, 0);
    insereAresta(G, 12, 13, 0);
    insereAresta(G, 13, 2, 0);
    insereAresta(G, 13, 14, 0);
    insereAresta(G, 13, 15, 0);
    insereAresta(G, 14, 15, 0);
    insereAresta(G, 14, 17, 0);
    insereAresta(G, 15, 16, 0);
 
    do{//Define os nodes de spawn da Ripley e do Alien
        ripley = rand() % 17;
        alien = rand() % 17;
    }while((ripley == 6 || ripley == 5 || ripley == 2) && alien != ripley)
    spawn(G,ripley,alien);
    enqueue(caminho,ripley);

    while(G->info[ripley] != 3 || G->info[6] != 1){
        BFS(G,ripley);
        ripley = turnoRipley(G,ripley,caminho);
        if(G->info[ripley] == 3)
            break;
        alien = turnoAlien(G,alien);
        G = resetGrafo(G);
    }
    if(G->info[ripley] == 3){//O Alien entrou no node que a Ripley estava
        printf("O Alien encontrou a Ripley!!\n");//TEM Q CUSTOMIZAR DAORA
        printf("O caminho feito por ela até o momento de sua morte foi:\n");
        while(caminho->fila[i] != -1){
            printf("(%i) -> ",caminho->fila[i]);
            i++;
            if(caminho->fila[i] == -1)
                printf("(%i - ALIEN)\n",caminho->fila[i]);//TEM Q CUSTOMIZAR DAORA
        }
    }else{//G->info[6] == 1 ---->>>>> significa que a Ripley chegou na saida
        printf("A Ripley encontrou a saída da nave!!\n\n");//TEM Q CUSTOMIZAR DAORA
        printf("O caminho total feito por ela foi:\n\n");
        for(int i = 0; caminho->fila[i] != -1; i++)
            printf("(%i) -> ",caminho->fila[i]);
        printf("EXTERIOR\n");//TEM Q CUSTOMIZAR DAORA
    }

return 0;
}