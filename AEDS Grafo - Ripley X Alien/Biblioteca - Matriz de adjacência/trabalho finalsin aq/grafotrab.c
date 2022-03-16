#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "trab.h"
 
int trabalho(){
    srand(time(NULL));
    int ripley, alien, hard, i = 0, teste = 0, viva = 0, morta = 0;
    Grafo* G = cria_Grafo(18,6);
    QUEUE* caminho = criaFila(100);
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

    printf("Você deseja realizar a simulação no modo HARDCORE (Alien) ou no modo Normal?\n");
    printf("1 - HARDCORE\n2 - Normal\n");
    scanf("%i",&hard);

    do{//Define os nodes de spawn da Ripley e do Alien
        ripley = rand() % 17;
        alien = rand() % 17;
    }while((ripley == 6 || ripley == 5 || ripley == 2) || ripley == alien);
    spawn(G,ripley,alien);
    enqueue(caminho,ripley);
    
    while(ripley != alien && ripley != 6){
        system("sleep 1.5");
        system("clear");
        printf("Localização da Ripley: %i\n",ripley);
        printf("Localização do Alien: %i\n",alien);
        BFS(G,ripley);
        ripley = turnoRipley(G,ripley,caminho);
        if(G->info[ripley] == 3)
            break;
        
        if(hard == 1)
            G = resetGrafo(G);
            BFS(G,alien);
        alien = turnoAlien(G,alien,hard);
        G = resetGrafo(G);
    }
    if(G->info[ripley] == 3){//O Alien entrou no node que a Ripley estava
        printf("\033[31m O Alien encontrou a Ripley e a matou!!\033[0m\n\n");
        morta++;
        printf("\033[35m O caminho feito por ela até o momento de sua morte foi:\033[0m\n\n");
        while(caminho->fila[i] != -1){
            printf("(%i) -> ",caminho->fila[i]);
            i++;
            if(caminho->fila[i] == -1)
                printf("\033[33mRipley Morta\033[0m <- ALIEN\n");
        }
    }else{//ripley = 6 ---->>>>> significa que a Ripley chegou na saida
        printf("\n \033[32m A Ripley encontrou a saída da nave e fugiu!!\033[0m\n\n");
        viva++;
        printf("\033[35m O caminho total feito por ela foi:\033[0m\n\n");
        for(int i = 0; caminho->fila[i] != -1; i++)
            printf("(%i) -> ",caminho->fila[i]);
        printf("\033[28mEXTERIOR\033[0m\n");
    }

return 0;
}

int menu(){
system("sleep 0.5");
system("clear");
printf("\033[31m\n");
printf("     /\\     | | (_)               \n");
system("sleep 0.15");
printf("    /  \\    | |  _    ___   _ __  \n");
system("sleep 0.15");
printf("   / /\\ \\   | | | |  / __ \\ | '_  \\ \n");
system("sleep 0.15");
printf("  / /  \\ \\  | | | | |   __/ | | | |\n");
system("sleep 0.15");
printf(" /_/    \\_\\ |_| |_|  \\ ___| |_| |_|\n");
system("sleep 0.15");
printf("\033[0m\n");

system("sleep 0.15");
printf("\033[35m\n");
printf("\t|\\     /|(  ____ \\ \n");
system("sleep 0.15");
printf("\t| )   ( || (    \\/\n");
system("sleep 0.15");
printf("\t| |   | || (_____ \n");
system("sleep 0.15");
printf("\t( (   ) )(_____  )\n");
system("sleep 0.15");
printf("\t \\ \\_/ /       ) |\n");
system("sleep 0.15");
printf("\t  \\   /  /\\____) |\n");
system("sleep 0.15");
printf("\t   \\_/   \\_______)\n");
printf("\033[0m\n");

system("sleep 0.15");
printf("\033[32m\n");
printf("  _____    _           _                \n");
system("sleep 0.15");
printf(" |  __ \\  (_)         | |               \n");
system("sleep 0.15");
printf(" | |__) |  _   _ __   | |   ___   _   _ \n");
system("sleep 0.15");
printf(" |  _  /  | | | '_ \\  | |  / _ \\ | | | |\n");
system("sleep 0.15");
printf(" | | \\ \\  | | | |_) | | | |  __/ | |_| |\n");
system("sleep 0.15");
printf(" |_|  \\_\\ |_| | .__/  |_|  \\___|  \\__, |\n");
system("sleep 0.15");
printf("              | |                  __/ |\n");
system("sleep 0.15");
printf("              |_|                 |___/ \n");
printf("\033[0m\n\n\n");

selecao:
system("sleep 0.5");
printf("\033[33m\n");
printf("\t|\\  /||~~ |\\  ||   |\n");
printf("\t| \\/ ||-- | \\ ||   |\n");
printf("\t|    ||__ |  \\| \\_/ \n");
printf("\033[37m\n\n");

printf("\t1. Iniciar simulação\n");
printf("\t2. Créditos\n");
printf("\t3. Sair\n");
printf("\033[0m\n");

for(int i = 0; i < 48; ++i){
    system("sleep 0.1");
    printf("\n");
}

int op;
printf("--> ");
scanf("%d", &op);
if(op > 3){
    printf("\n\033[31m OPÇÃO INVÁLIDA\n\n\033[0m");
    goto selecao;
}
//menu
char resp;
switch (op){

case 1:
     trabalho(); 

break;

case 2:
system("clear");
    printf("\n\t\tCréditos\n\n Este é um trabalho realizado pelos seguintes alunos do 2o ano do Colégio Técnico da UFMG:\n");
    printf("\n-Arthur Feu \n-Edson Paschoal \n-João Pedro Camargo\n");
    printf("\nO trabalho foi feito nos meses de julho e agosto (2019), na disciplina de AEDS, ministrada \npela prof. Virgínia.\n\n");


break;

case 3:
     return 0;
break;
}

return 0;
}

int main(){
    menu();
return 0;
}