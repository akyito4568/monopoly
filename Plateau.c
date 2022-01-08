#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "Biblio.h"

#define MAX_LIMIT 50

void colonnecouleur(int couleurtexte, int couleurfond,int positionX,int positionY)
{
    int i=0, j=0;
    for (j=positionY; j<positionY+2; j++){
        for (i=positionX; i<positionX+2; i++){
            Color(couleurtexte, couleurfond);
            gotoligcol(i, j);
            printf(" ");
        }
    }

}

void bandecouleur(int couleurtexte, int couleurfond,int positionX,int positionY )
{
    int j=0;

    for (j=positionY; j<positionY+7; j++){
        {
            Color(couleurtexte, couleurfond);
            gotoligcol(positionX,j);
            printf(" ");
        }
    }
}

void rectangleCouleur(int couleurtexte, int couleurfond,int positionX,int positionY){
    int i=0, j=0;
    for (j=positionX; j<positionX+27; j++){
        for (i=positionY; i<positionY+4; i++){
            Color(couleurtexte, couleurfond);
            gotoligcol(i, j);
            printf(" ");
        }
    }
}

void colonneCarte(int positionX,int positionY)
{
    int i=0, j=0;
    for (j=positionY; j<positionY+1; j++){
        for (i=positionX; i<positionX+17; i++){
            gotoligcol(i, j);
            printf("%c",0xB3);
        }
    }

}
void colonneCarteProp(int positionX,int positionY)
{
    int i=0, j=0;
    for (j=positionY; j<positionY+1; j++){
        for (i=positionX; i<positionX+12; i++){
            gotoligcol(i, j);
            printf("%c",0xB3);
        }
    }

}


void affichageplateau(t_propriete Plateau[32])
{

    int j=0;
    int a=24;
    int z=32;
    int espace=0;
    int propriete=0;
    int taille=9;

    /********************Mise en forme plateau***********************/

    consoleencouleur(15, 0);


    for(j=0;j<taille;j++)
    {
        ///Disposition des cases horizontales
        if (j==0)
        {
    gotoligcol(1,4);

            printf("%c%c%c%c%c%c%c%c%c",0xDA,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC2);
            for(propriete=0;propriete<taille-2;propriete++)
            {
                printf("%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC2);
            }
            printf("%c%c%c%c%c%c%c%c\n    ",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xBF);
    gotoligcol(2,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c       ",0xB3);
            }
    gotoligcol(2,76);
            printf("%c",0xB3);
    gotoligcol(3,4);

            for(propriete=0;propriete<taille;propriete++)
            {

                printf("%c   %d   ",0xB3,Plateau[propriete].place); //place la case debut � la case prison
            }
    gotoligcol(3,76);
            printf("%c",0xB3);

            printf("\n\n");
    gotoligcol(4,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c       ",0xB3);
            }
    gotoligcol(4,76);
            printf("%c",0xB3);

    gotoligcol(5,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c       ",0xB3);
            }
    gotoligcol(5,76);
            printf("%c",0xB3);

    gotoligcol(6,4);

            printf("%c%c%c%c%c%c%c%c%c",0xC3,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC5);
            for(propriete=0;propriete<taille-3;propriete++)
            {
                printf("%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC1);
            }
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xB4);


        }
        else if(j==taille-1)
        {

    gotoligcol(41,76);
            printf("%c",0xB3);

    gotoligcol(41,4);

            printf("%c%c%c%c%c%c%c%c%c",0xC3,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC5);
            for(propriete=0;propriete<taille-3;propriete++)
            {
                printf("%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC2);
            }
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xB4);

    gotoligcol(42,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c       ",0xB3);
            }
    gotoligcol(42,76);
            printf("%c",0xB3);

    gotoligcol(43,4);
            for(propriete=0;propriete<taille;propriete++)
            {

                printf("%c   %d  ",0xB3,Plateau[a-(propriete)].place);// place la Parking � la case Police
            }
    gotoligcol(43,76);
            printf("%c",0xB3);
    gotoligcol(44,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c       ",0xB3);
            }
    gotoligcol(44,76);
            printf("%c",0xB3);
    gotoligcol(45,76);
            printf("%c",0xB3);
    gotoligcol(45,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c       ",0xB3);
            }
    gotoligcol(46,4);

            printf("%c%c%c%c%c%c%c%c%c",0xC0,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC1);
            for(propriete=0;propriete<taille-2;propriete++)
            {
                printf("%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC1);
            }
            printf("%c%c%c%c%c%c%c%c\n    ",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xD9);

        }
        else
        {
            for(espace=0;espace<taille;espace++)
            {


                ///disposition des cases verticales
                if(espace==0)
                {

                    printf("    %c       %c                                                       %c       %c\n",0xB3,0xB3,0xB3,0xB3);
                    printf("    %c   %d  %c   ",0xB3,Plateau[z-(j)].place,0xB3);//place la case 26 � la case 32

                }

                else if(espace==taille-1)
                {

                    printf("   %c   %d  %c\n",0xB3,Plateau[j+8].place,0xB3);//place la case 10 � la case 16
                    printf("    %c       %c                                                       %c       %c\n",0xB3,0xB3,0xB3,0xB3);
                    printf("    %c       %c                                                       %c       %c\n",0xB3,0xB3,0xB3,0xB3);

                    printf("    %c%c%c%c%c%c%c%c%c   ",0xC3,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xB4);
                    for(espace=0;espace<taille;espace++)
                    {
                        printf("     ");
                    }

                    printf("       %c%c%c%c%c%c%c%c%c",0xC3,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xB4);
                }
                else
                {
                    printf("       ");
                }
            }
        }
    printf("\n");
    }
couleurPlateau();
}


void affichagepropriete(t_propriete Plateau[32], joueur* tab) //afficher les données de la case sur laquelle le joueur tombe pendant son tour
{
    int choixcase=tab->position;
    int couleur;
    gotoligcol(8, 15);
    Color(15,0);
    //case qui ne sont pas des monuments
    if(choixcase==0||choixcase==3||choixcase==11||choixcase==18||choixcase==25||choixcase==29)
    {
        gotoligcol(9,15);
        printf("%s",Plateau[choixcase].nom);
    }
    else if(choixcase==8)
    {
        Color(15,0);
        gotoligcol(9,30);
        printf("%s",Plateau[choixcase].nom);
        gotoligcol(17,25);
        printf("____________________________");
        gotoligcol(18,25);
        printf("     ||   ||     ||   ||");
        gotoligcol(19,25);
        printf("     ||   ||, , ,||   ||");
        gotoligcol(20,25);
        printf("     ||  (||/|/(%c||/  ||",0x5C);
        gotoligcol(21,25);
        printf("     ||  ||| _'_`|||  ||");
        gotoligcol(22,25);
        printf("     ||   || o o ||   ||");
        gotoligcol(23,25);
        printf("     ||  (||  - `||)  ||");
        gotoligcol(24,25);
        printf("     ||   ||  =  ||   ||");
        gotoligcol(25,25);
        printf("     ||   ||%c___/||   ||",0x5C);
        gotoligcol(26,25);
        printf("     ||___||) , (||___||");
        gotoligcol(27,25);
        printf("    /||---||-%c_/-||---||%c ",0x5C,0x5C);
        gotoligcol(28,25);
        printf("   / ||--_||_____||_--|| %c ",0x5C);
        gotoligcol(29,25);
        printf("  (_(||)-| S123-45 |-(||)_)");
    }
    else if(choixcase==24)
    {
        Color(15,0);
        gotoligcol(9,30);
        printf("%s",Plateau[choixcase].nom);
        gotoligcol(19,28);
         printf("     ,   /%c   ,",0x5C);
         gotoligcol(20,28);
         printf("    / '-'  '-' %c ",0x5C);
         gotoligcol(21,28);
         printf("   |   POLICE   |");
         gotoligcol(22,28);
         printf("   %c    .--.    /",0x5C);
         gotoligcol(23,28);
         printf("    |  ( 19 )  |");
         gotoligcol(24,28);
         printf("    %c   '--'   /",0x5C);
         gotoligcol(25,28);
         printf("     '--.  .--'");
         gotoligcol(26,28);
         printf("         %c/",0x5C);

    }
    else if(choixcase==16)
    {
        Color(15,0);
        gotoligcol(9,30);
        printf("%s",Plateau[choixcase].nom);
        gotoligcol(19,25);
        printf("        __-------__");
        gotoligcol(20,25);
        printf("      / _---------_ %c ",0x5C);
        gotoligcol(21,25);
        printf("     / /           %c %c ",0x5C,0x5C);
        gotoligcol(22,25);
        printf("     | |           | |");
        gotoligcol(23,25);
        printf("     |_|___________|_|");
        gotoligcol(24,25);
        printf(" /-%c|                 |/-%c ",0x5C,0x5C);
        gotoligcol(25,25);
        printf("| _ |%c       0       /| _ |",0x5C);
        gotoligcol(26,25);
        printf("|(_)| %c      !      / |(_)|",0x5C);
        gotoligcol(27,25);
        printf("|___|__%c_____!_____/__|___|",0x5C);
        gotoligcol(28,25);
        printf("[_________|ECE22|_________]");
        gotoligcol(29,25);
        printf(" ||||    ~~~~~~~~     ||||");
        gotoligcol(30,25);
        printf(" `--'                 `--'");

    }
    else //case monuments
    {
        gotoligcol(9,26);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xDA,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xBF);
        gotoligcol(22,26);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC0,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xD9);

        colonneCarteProp(10,26);
        colonneCarteProp(10,54);
        couleur=Plateau[choixcase].groupe;
        rectangleCouleur(0,couleur,27,10);

        gotoligcol(10,32);
        printf("%s", Plateau[choixcase].nomgroupe);
        gotoligcol(12,30);
        printf("%s", Plateau[choixcase].nom);

        Color(15,0);

        gotoligcol(14,28);
        printf("Prix d achat:   %d euros", Plateau[choixcase].prix);
        gotoligcol(15,28);
        printf("Proprietaire: %s", Plateau[choixcase].nomproprietaire);
        gotoligcol(16,28);
        printf("Prix visite:     %d euros", Plateau[choixcase].loyer);
        gotoligcol(17,28);
        printf("Maison:                %d", Plateau[choixcase].maison);
        gotoligcol(18,28);
        printf("Hotel:                 %d", Plateau[choixcase].hotel);
        gotoligcol(19,30);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4);
        gotoligcol(20,31);
        printf("Hypotheque :");
        gotoligcol(21,33);
        printf("%d euros", Plateau[choixcase].hypotheque);


    }
}




void remplir_prop(t_propriete* pro, int i){
    switch (i){
    case 0:
        pro->place = 1;
        pro->groupe = 0;
        strcpy(pro->nomgroupe, "Evenement");
        strcpy(pro->nom, "Debut");
        pro->prix=0;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=0;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=0;
        pro->x=8;
        pro->y=5;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;

    case 1:
        pro->place = 2;
        pro->groupe = 13;
        strcpy(pro->nomgroupe, "Russie");
        strcpy(pro->nom, "Place Rouge");
        pro->prix=60;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=2;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=16;
        pro->y=5;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 2:
        pro->place = 3;
        pro->groupe = 13;
        strcpy(pro->nomgroupe, "Russie");
        strcpy(pro->nom, "Bolchoi");
        pro->prix=60;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=4;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=24;
        pro->y=5;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 3:
        pro->place = 4;
        pro->groupe = 0;
        strcpy(pro->nomgroupe, "Evenement");
        strcpy(pro->nom, "Chance 1");
        pro->prix=0;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=0;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=0;
        pro->x=32;
        pro->y=5;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 4:
        pro->place = 5;
        pro->groupe = 9;
        strcpy(pro->nomgroupe, "Aeroport");
        strcpy(pro->nom, "Aeroport 1");
        pro->prix=200;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=25;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=0;
        pro->x=40;
        pro->y=5;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 5:
        pro->place = 6;
        pro->groupe = 2;
        strcpy(pro->nomgroupe, "Angleterre");
        strcpy(pro->nom, "Big Ben");
        pro->prix=100;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=6;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=48;
        pro->y=5;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 6:
        pro->place = 7;
        pro->groupe = 2;
        strcpy(pro->nomgroupe, "Angleterre");
        strcpy(pro->nom, "Tower Bridge");
        pro->prix=100;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=6;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=56;
        pro->y=5;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 7:
        pro->place = 8;
        pro->groupe = 2;
        strcpy(pro->nomgroupe, "Angleterre");
        strcpy(pro->nom, "Buckingham Palace");
        pro->prix=120;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=8;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=64;
        pro->y=5;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 8:
        pro->place = 9;
        pro->groupe = 0;
        strcpy(pro->nomgroupe, "Evenement");
        strcpy(pro->nom, "Prison");
        pro->prix=0;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=0;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=0;
        pro->x=72;
        pro->y=5;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 9:
        pro->place = 10;
        pro->groupe = 14;
        strcpy(pro->nomgroupe, "Bresil");
        strcpy(pro->nom, "Christ Redempteur");
        pro->prix=140;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=10;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=72;
        pro->y=10;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 10:
        pro->place = 11;
        pro->groupe = 14;
        strcpy(pro->nomgroupe, "Bresil");
        strcpy(pro->nom, "Cathedrale Metropolitana");
        pro->prix=140;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=10;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=72;
        pro->y=15;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 11:
        pro->place = 12;
        pro->groupe = 0;
        strcpy(pro->nomgroupe, "Evenement");
        strcpy(pro->nom, "Communaute 1");
        pro->prix=0;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=0;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=0;
        pro->x=72;
        pro->y=20;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 12:
        pro->place = 13;
        pro->groupe = 9;
        strcpy(pro->nomgroupe, "Aeroport");
        strcpy(pro->nom, "Aeroport 2");
        pro->prix=200;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=25;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=0;
        pro->x=72;
        pro->y=25;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 13:
        pro->place = 14;
        pro->groupe = 14;
        strcpy(pro->nomgroupe, "Bresil");
        strcpy(pro->nom,"Theatre Amazonas");
        pro->prix=160;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=12;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=72;
        pro->y=30;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 14:
        pro->place = 15;
        pro->groupe = 8;
        strcpy(pro->nomgroupe, "Etats-Unis");
        strcpy(pro->nom, "Statue de la Liberte");
        pro->prix=180;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=14;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=72;
        pro->y=35;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 15:
        pro->place = 16;
        pro->groupe = 8;
        strcpy(pro->nomgroupe, "Etats-Unis");
        strcpy(pro->nom, "Mont Rushmore");
        pro->prix=180;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=14;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=72;
        pro->y=40;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 16:
        pro->place = 17;
        pro->groupe = 0;
        strcpy(pro->nomgroupe, "Evenement");
        strcpy(pro->nom, "Parking");
        pro->prix=0;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=0;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=0;
        pro->x=72;
        pro->y=45;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 17:
        pro->place = 18;
        pro->groupe = 8;
        strcpy(pro->nomgroupe, "Etats-Unis");
        strcpy(pro->nom, "Grand Canyon");
        pro->prix=200;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=16;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=64  ;
        pro->y=45;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 18:
        pro->place = 19;
        pro->groupe = 0;
        strcpy(pro->nomgroupe, "Evenement");
        strcpy(pro->nom, "Chance 2");
        pro->prix=0;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=0;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=0;
        pro->x=56;
        pro->y=45;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 19:
        pro->place = 20;
        pro->groupe = 5;
        strcpy(pro->nomgroupe, "Italie");
        strcpy(pro->nom, "Colisee");
        pro->prix=220;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=18;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=48;
        pro->y=45;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 20:
        pro->place = 21;
        pro->groupe = 9;
        strcpy(pro->nomgroupe, "Aeroport");
        strcpy(pro->nom, "Aeroport 3");
        pro->prix=200;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=25;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=0;
        pro->x=40;
        pro->y=45;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 21:
        pro->place = 22;
        pro->groupe = 5;
        strcpy(pro->nomgroupe, "Italie");
        strcpy(pro->nom, "Tour de Pise");
        pro->prix=220;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=18;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=32;
        pro->y=45;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 22:
        pro->place = 23;
        pro->groupe = 5;
        strcpy(pro->nomgroupe, "Italie");
        strcpy(pro->nom, "Cathedrale de Milan");
        pro->prix=240;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=20;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=24;
        pro->y=45;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 23:
        pro->place = 24;
        pro->groupe = 6;
        strcpy(pro->nomgroupe, "Japon");
        strcpy(pro->nom, "Skytree");
        pro->prix=260;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=22;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=16;
        pro->y=45;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 24:
        pro->place = 25;
        pro->groupe = 0;
        strcpy(pro->nomgroupe, "Evenement");
        strcpy(pro->nom, "Police");
        pro->prix=0;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=0;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=0;
        pro->x=8;
        pro->y=45;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 25:
        pro->place = 26;
        pro->groupe = 0;
        strcpy(pro->nomgroupe, "Evenement");
        strcpy(pro->nom, "Communaute 2");
        pro->prix=0;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=0;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=8;
        pro->y=40;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 26:
        pro->place = 27;
        pro->groupe = 6;
        strcpy(pro->nomgroupe, "Japon");
        strcpy(pro->nom, "Plais Imperial de Kyoto");
        pro->prix=260;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=22;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=8;
        pro->y=35;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 27:
        pro->place = 28;
        pro->groupe = 6;
        strcpy(pro->nomgroupe, "Japon");
        strcpy(pro->nom, "Palais Imperial de Tokyo");
        pro->prix=280;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=24;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=8;
        pro->y=30;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 28:
        pro->place = 29;
        pro->groupe = 9;
        strcpy(pro->nomgroupe, "Aeroport");
        strcpy(pro->nom, "Aeroport 4");
        pro->prix=200;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=25;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=0;
        pro->x=8;
        pro->y=25;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 29:
        pro->place = 30;
        pro->groupe = 0;
        strcpy(pro->nomgroupe, "Evenement");
        strcpy(pro->nom, "Impot");
        pro->prix=0;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=0;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=0;
        pro->x=8;
        pro->y=20;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 30:
        pro->place = 31;
        pro->groupe = 1;
        strcpy(pro->nomgroupe, "France");
        strcpy(pro->nom, "Arc de Triomphe");
        pro->prix=300;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=35;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=8;
        pro->y=15;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;
    case 31:
        pro->place = 32;
        pro->groupe = 1;
        strcpy(pro->nomgroupe, "France");
        strcpy(pro->nom, "Tour Eiffel");
        pro->prix=320;
        strcpy(pro->nomproprietaire, "/");
        pro->loyer=50;
        pro->maison=0;
        pro->hotel=0;
        pro->hypotheque=30;
        pro->x=8;
        pro->y=10;
        pro->proprietaire=4;
        pro->prix_actuel=0;
        break;

    }
}


void couleurPlateau()
{
    //Debut
    bandecouleur(0,15,2,5);
    //prison
    bandecouleur(0,15,2, 69);
    // Parking
    bandecouleur(0,15,42,69);
    //Police
    bandecouleur(0,15,42,5);

    //Aeroport

    bandecouleur(0,9,2,37);
    bandecouleur(0,9,5,37);
    colonnecouleur(0,9,3,37);
    colonnecouleur(0,9,3,42);

    bandecouleur(0,9,22,69);
    colonnecouleur(0,9,23,69);
    colonnecouleur(0,9,23,74);
    bandecouleur(0,9,25,69);

    bandecouleur(0,9,42,37);
    bandecouleur(0,9,45,37);
    colonnecouleur(0,9,43,37);
    colonnecouleur(0,9,43,42);

    bandecouleur(0,9,22,5);
    bandecouleur(0,9,25,5);
    colonnecouleur(0,9,23,5);
    colonnecouleur(0,9,23,10);



    //Russie

    bandecouleur(0,13,2,13);
    bandecouleur(0,13,2,21);

    //Angleterre
    bandecouleur(0,2,2,45);
    bandecouleur(0,2,2,53);
    bandecouleur(0,2,2,61);

    //Bresil
    bandecouleur(0,14,7,69);
    bandecouleur(0,14,12,69);
    bandecouleur(0,14,27,69);

    //Etats-Unis
    bandecouleur(0,8,32,69);
    bandecouleur(0,8,37,69);
    bandecouleur(0,8,42,61);

    //Italie
    bandecouleur(0,5,42,45);
    bandecouleur(0,5,42,29);
    bandecouleur(0,5,42,21);


    //Japon
    bandecouleur(0,6,42,13);
    bandecouleur(0,6,32,5);
    bandecouleur(0,6,27,5);

    //France

    bandecouleur(0,1,12,5);
    bandecouleur(0,1,7,5);


}
