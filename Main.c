#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "Biblio.h"

#define MAX_LIMIT 50



int main()
{
    int i=0;
    int nbjoueurs=0, choix=0, continuer=0, compteur=0, compteursortie=0, validationprison=0;
    int Case=0;
    char continuer2 =0;
    joueur tableau[4]; //ce tableau est rempli dans le menu si on selectionne la nouvelle partie
    joueur tableauordre[4];
    t_propriete Plateau[32];


    //affichage du menu principal
    menu(tableau, Plateau, &nbjoueurs, &choix, tableauordre);
    //si le choix était d'afficher les joueurs ou les regles le menu se réaffiche juste après l'avoir quitté
    while (choix==4 || choix==5){
       menu(tableau, Plateau, &nbjoueurs, &choix, tableauordre);
    }

    ///si le joueur sélectionne une nouvelle partie
    if (choix==1){

        // remplissage d'un tableau de structure joueur
        for (i=0; i<nbjoueurs; i++){
            configuration_joueur(&tableau[i]);
            tableau[i].indice=i;
        }
        //mise en ordre du tableau de structure joueur
        ordrepassagejoueurs(nbjoueurs, tableau, tableauordre);
        clearScreen();

        /// remplissage des cases du tableau
        for (i=0; i<32; i++){
            remplir_prop(&Plateau[i], i);
        }

        /// affichage plateau et boucle de parcours pour afficher les pions de chaque joueur
        affichageplateau(Plateau);
        for(i=0; i<nbjoueurs; i++){
            deplacement_pion(Plateau, &tableauordre[i], i);
        }

        affichagepropriete(Plateau, &tableauordre[compteur]);

        ///démarrage de la partie
        Color(15,0);
        gotoligcol(0,85);
        printf("Appuyer sur entree pour lancer la partie !");
        gotoligcol(1, 85);
        printf("On commence avec %s", tableauordre[0].nom);
        fflush(stdin);
        scanf("%c", &continuer2);

        do{
            clearScreen(); //remise à 0 de l'écran à chaque tour
            gotoligcol(0,0);
            affichageplateau(Plateau);

            ///lancé des dés, affichage des données du joueur et de la propriété sur laquelle il tombe
            lancedefinal(&tableauordre[compteur], Plateau, &compteursortie, &validationprison);
            afficher_donnee_joueur_encours(&tableauordre[compteur]);
            affichagepropriete(Plateau, &tableauordre[compteur]);
            //affichage des pions sur le plateau
            for(i=0; i<nbjoueurs; i++){
                deplacement_pion(Plateau, &tableauordre[i], i);
            }

            ///achat potentiel de propriété
            Case = tableauordre[compteur].position;
            achat_location(&Plateau[Case], &tableauordre[compteur]);
            ///case autre que propriété
              
            // réaffichage des données du joueur et de la propriété pour voir les modifications si il y a eu un achat
            afficher_donnee_joueur_encours(&tableauordre[compteur]);
            affichagepropriete(Plateau, &tableauordre[compteur]);
            for(i=0; i<32; i++){
                for(j=0; j<nbjoueurs; j++){
                    gotoligcol(0,0);
                    affichage_bien_joueurs(&Plateau[i], &tableauordre[j]);
                }
            }

            Color(15,0);
            gotoligcol(0,85);
            printf("Si vous avez termine votre tour selectionner 1 : ");
            gotoligcol(1, 85);
            printf("Si vous voulez retourner au menu principal selectionnez 0 : ");
            fflush(stdin);
            scanf("%d", &continuer);

            if(continuer==1)
                compteur=(compteur+1)%nbjoueurs;
            if(continuer==0)
                break;
        }while(continuer == 1);
    }

        clearScreen();
        menu(tableau, Plateau, &nbjoueurs, &choix, tableauordre);


        gotoligcol(50, 0); //affichage du process return en dehors du plateau
}
