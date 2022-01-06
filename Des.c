#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "Biblio.h"

#define MAX_LIMIT 50

//on place le pion du joueur aux coordonées de la case sur laquelle il se trouve
void deplacement_pion(t_propriete tab_p[32],joueur* tab, int i){
    Color(15,0);
    gotoligcol(tab_p[tab->position].y, tab_p[tab->position].x-i);
    printf("%c",tab->signe);
}

void LanceDe(int * de1,int * de2){
        int BorneInf = 1;
        int BorneSup = 6;
        *de1 = rand()%(BorneSup - BorneInf + 1) + BorneInf;
        *de2 = rand()%(BorneSup - BorneInf + 1) + BorneInf;
}

int doubles(int * a){
    int de1,de2;
    LanceDe(&de1,&de2);
    if (de1==de2){
        *a=*a+de1+de2;
        return 1;}

    else{
        *a=*a+de1+de2;
        return 0;}
}

void lancedefinal(joueur* a, t_propriete tab[32]){ //lancer des dés
    int somme=0, sommeaffichee=0;
    int compteur=0;
    int test;
    srand(time(NULL));
    Color(15,0);
        do{
            test=doubles(&somme);
            gotoligcol(47, 0);
            printf("test :%i",test);
            printf("\nsomme:%i",somme);
            compteur++;
            // si le joueur fait trois doubles
            if (compteur==3){
                a->position=8;
                gotoligcol(7, 85);
                printf("Mince ! Vous avez fait trois doubles, vous allez en prison...");
                break;
            }

            a->position= (a->position+somme)%32;

            gotoligcol(4, 85);
            printf("Vous avez lance les des %d fois.", compteur);
            gotoligcol(5, 85);
            printf("Vous avez fait %d doubles.", compteur-1);
            gotoligcol(6, 85);
            sommeaffichee = sommeaffichee + somme;
            printf("Vous avancez de %d cases.", sommeaffichee);
            somme=0;
            compteur=0;
            }
        while(test);
}

