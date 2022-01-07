#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "Biblio.h"

#define MAX_LIMIT 50



int main()
{
    int i=0, j=0;
    int nbjoueurs=0, choix=0, continuer=0, compteur=0, compteursortie=0, validationprison=0,nombre_mort=0;
    int Case=0;
    char continuer2 =0;
    joueur tableau[4]; //ce tableau est rempli dans le menu si on selectionne la nouvelle partie
    joueur tableauordre[4];
    t_propriete Plateau[32];


    //affichage du menu principal
    menu(tableau, Plateau, &nbjoueurs, &choix, tableauordre);
    //si le choix �tait d'afficher les joueurs ou les regles le menu se r�affiche juste apr�s l'avoir quitt�
    while (choix==4 || choix==5){
       menu(tableau, Plateau, &nbjoueurs, &choix, tableauordre);
    }

    ///si le joueur s�lectionne une nouvelle partie
    if (choix==1){

        // remplissage d'un tableau de structure joueur
        config_joueur(tableau, nbjoueurs);

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

        ///d�marrage de la partie
        Color(15,0);
        gotoligcol(0,85);
        printf("Appuyer sur entree pour lancer la partie !");
        gotoligcol(1, 85);
        printf("On commence avec %s", tableauordre[0].nom);
        fflush(stdin);
        scanf("%c", &continuer2);

        do{
            clearScreen(); //remise � 0 de l'�cran � chaque tour
            gotoligcol(0,0);
            affichageplateau(Plateau);

            ///lanc� des d�s, affichage des donn�es du joueur et de la propri�t� sur laquelle il tombe
        if ((tableauordre[compteur].position==8) &&(tableauordre[compteur].tour_prison>=0)){
            prison_final(Plateau,&tableauordre[compteur],tableauordre);
        }

        if(tableauordre[compteur].tour_prison==-1){
            lancedefinal(&tableauordre[compteur],Plateau);

        }
            afficher_donnee_joueur_encours(&tableauordre[compteur]);
            affichagepropriete(Plateau, &tableauordre[compteur]);
            //affichage des pions sur le plateau
            for(i=0; i<nbjoueurs; i++){
                deplacement_pion(Plateau, &tableauordre[i], i);
            }

            ///traitement de la case en cours
            Case = tableauordre[compteur].position;
            analyse_case_joueur(&Plateau[Case], &tableauordre[compteur], Plateau, tableauordre);


            /// r�affichage des donn�es du joueur et de la propri�t� pour voir les modifications si il y a eu un achat
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
            nombre_mort=0;
            for (int i=0;i<nbjoueurs;i++){
                if(tableauordre[i].mort==1){
                    nombre_mort++;
                }
            }


            if(continuer==1){
                do {
                    compteur=(compteur+1)%nbjoueurs;
                }
                while(tableau[compteur].mort==1);

                    }
            if(continuer==0)
                break;

        }while(continuer == 1 && nombre_mort!=nbjoueurs-1);
    }
        if (nombre_mort==nbjoueurs-1){
            clearScreen();
            gotoligcol(0,0);
            printf("Vous avez gagne");}
        else {
        clearScreen();
        menu(tableau, Plateau, &nbjoueurs, &choix, tableauordre);
        gotoligcol(50, 0);
        }

         //affichage du process return en dehors du plateau
}

