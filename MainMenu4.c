#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Fonctions.h"
#include <time.h>

int main()
{
    int nbjoueurs=0, choix=0, continuer=0, compteur=0, compteursortie=0, validationprison=0;
    char continuer2 =0;
    joueur tableau[4]; //ce tableau est rempli dans le menu si on selectionne la nouvelle partie
    joueur tableauordre[4];
    t_propriete Plateau[32]; //déclaration du plateau

    //affichage du menu principal
    menu(tableau, Plateau, &nbjoueurs, &choix, tableauordre);
    //si le choix était d'afficher les joueurs ou les regles le menu se réaffiche juste après l'avoir quitté
    while (choix==4 || choix==5){
       menu(tableau, Plateau, &nbjoueurs, &choix, tableauordre);
    }

    if (choix ==1){
        clearScreen();
        gotoligcol(0,0); // remise à 0 du curseur

        remplissagetableau(Plateau); //initialisation et affichage du plateau
        InitilisationPlateau(Plateau);

        gotoligcol(0,0); //remise à 0 du curseur
        deplacement_pion(nbjoueurs, Plateau, tableauordre);
        affichagepropriete(Plateau, tableauordre, compteur);
        gotoligcol(0,85);
        printf("Appuyer sur entree pour lancer la partie !");
        gotoligcol(1, 85);
        printf("On commence avec %s", tableauordre[0].nom);
        fflush(stdin);
        scanf("%c", &continuer2);

        do{
            clearScreen();
            gotoligcol(0,0);
            InitilisationPlateau(Plateau);

            lancedefinal(tableauordre,Plateau, compteur, &compteursortie, &validationprison);
            afficher_donnee_joueur_encours(tableauordre, compteur);
            deplacement_pion(nbjoueurs, Plateau, tableauordre);
            affichagepropriete(Plateau, tableauordre, compteur);



            gotoligcol(0,85);
            printf("Si vous avez termine votre tour selectionner 1 : ");
            gotoligcol(1, 85);
            printf("Si vous voulez retourner au menu principal selectionnez 0 : ");
            fflush(stdin);
            scanf("%d", &continuer);

            if(continuer==1)
                compteur=(compteur+1)%nbjoueurs;
                continue;
            if(continuer==0)
                break;
        }while(1);

        clearScreen();
        menu(tableau, Plateau, &nbjoueurs, &choix, tableauordre);


        gotoligcol(50, 0); //affichage du process return en dehors du plateau
    }




    gotoligcol(50, 0); //affichage du process return en dehors du plateau
    return 0;
}
