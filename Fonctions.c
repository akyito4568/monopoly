#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "Biblio.h"

#define MAX_LIMIT 50

//effet de glissement de l'écran
void consoleencouleur(int couleurtexte, int couleurfond){
    int i=0, j=0;
    for (j=0; j<119; j++){
        for (i=0; i<60; i++){
            Color(couleurtexte, couleurfond);
            gotoligcol(i, j);
            printf(" ");
        }
    }
}

//affichage des couleurs
void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

//curseur
void gotoligcol( int lig, int col)
{
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

//remise a zéro de l'écran
void clearScreen(){
    system("cls");
    }
