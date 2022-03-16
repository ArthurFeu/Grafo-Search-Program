#include <stdio.h>
#include <stdlib.h>

int main(){
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
     printf("Código\n");
      // código 

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