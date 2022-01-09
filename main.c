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
    int nbjoueurs=0, choix=0, continuer=0, compteur=0, numsauv=0, nombre_mort=0;
    int Case=0, regarderCase=0, caseChoisi=0, couleur=0;
    char continuer2 =0;
    joueur tableau[4]; //ce tableau est rempli dans le menu si on selectionne la nouvelle partie
    joueur tableauordre[4];
    t_propriete Plateau[32];
    t_propriete plateauchargement[32];
    joueur tabchargement[4];


    //affichage du menu principal
    menu(tableau, Plateau, &nbjoueurs, &choix, tableauordre, &numsauv, tabchargement, plateauchargement);

    ///entrée dans le jeu
    do{
        ///le joueur a affiché les règles ou les créateurs du jeu
        while (choix==4 || choix==5){
        menu(tableau, Plateau, &nbjoueurs, &choix, tableauordre, &numsauv, tabchargement, plateauchargement);
        }

        ///le joueur a choisi la sauvegarde
        while(choix==2){
            menu(tableau, Plateau, &nbjoueurs, &choix, tableauordre, &numsauv, tabchargement, plateauchargement);
        }

        ///le joueur a chargé une partie précédente
        if(choix==3){
            Color(15,0);
            gotoligcol(0,85);
            printf("Appuyer sur entree pour reprendre la partie !");
            do{
                clearScreen(); //remise à 0 de l'écran à chaque tour
                gotoligcol(0,0);
                affichageplateau(plateauchargement);
                for(i=0; i<32; i++){
                    for(j=0; j<nbjoueurs; j++){
                        gotoligcol(0,0);
                        affichage_bien_joueurs(&plateauchargement[i], &tabchargement[j]);
                    }
                }

                /// tri pour si le joueur est en prison, ou joueur sur autre case (même prison, simple visite)
                //joueur en prison
                if ((tabchargement[compteur].position==8) &&(tabchargement[compteur].tour_prison>=0)){
                    prison_final(plateauchargement,&tabchargement[compteur],tabchargement);
                }
                //joueur position autre que prison (+simple visite)
                if(tabchargement[compteur].tour_prison==-1){
                    lancedefinal(&tabchargement[compteur], plateauchargement);

                }

                ///lancé des dés, affichage des données du joueur et de la propriété sur laquelle il tombe

                afficher_donnee_joueur_encours(&tabchargement[compteur]);
                affichagepropriete(plateauchargement, &tabchargement[compteur]);
                //affichage des pions sur le plateau
                for(i=0; i<nbjoueurs; i++){
                    deplacement_pion(plateauchargement, &tabchargement[i], i);
                }

                ///traitement de la case en cours
                Case = tabchargement[compteur].position;
                analyse_case_joueur(&plateauchargement[Case], &tabchargement[compteur], plateauchargement, tabchargement, nbjoueurs);


                /// réaffichage des données du joueur et de la propriété pour voir les modifications si il y a eu un achat
                afficher_donnee_joueur_encours(&tabchargement[compteur]);
                affichagepropriete(plateauchargement, &tabchargement[compteur]);
                for(i=0; i<32; i++){
                    for(j=0; j<nbjoueurs; j++){
                        gotoligcol(0,0);
                        affichage_bien_joueurs(&plateauchargement[i], &tabchargement[j]);
                    }
                }

                if(tabchargement[compteur].tour_prison == -2){
                    tabchargement[compteur].tour_prison = -1;
                }

                Color(15,0);
                do{

                    gotoligcol(0,85);
                    printf("Si vous avez termine votre tour selectionner 1 : ");
                    gotoligcol(1, 85);
                    printf("Si vous voulez retourner au menu principal selectionnez 0 : ");
                    fflush(stdin);
                    scanf("%d", &continuer);
                }while(!(continuer==0) && !(continuer==1));

                nombre_mort=0;
                for (int i=0;i<nbjoueurs;i++){
                    if(tabchargement[i].mort==1){
                        nombre_mort++;
                    }
                }


                if(continuer==1){
                    do {
                        compteur=(compteur+1)%nbjoueurs;
                    }
                    while(tabchargement[compteur].mort==1);
                }
                if(continuer==0)
                    break;

            }while(continuer == 1 && nombre_mort!=nbjoueurs-1);
        }

        ///si le joueur sélectionne une nouvelle partie
        if (choix==1){

            // remplissage d'un tableau de structure joueur
            config_joueur(tableau, nbjoueurs);

            //mise en ordre du tableau de structure joueur
            ordrepassagejoueurs(nbjoueurs, tableau, tableauordre);
            index_l(tableauordre, nbjoueurs);
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
                 do{
                        Color(15,0);
                        gotoligcol(10,85);
                        printf("Si vous voulez regarder une propriete selectionner 1 sinon selectionner 0 : ");
                        fflush(stdin);
                        scanf("%d", &regarderCase);
                        if(regarderCase==1)
                        {
                        do{
                            gotoligcol(11,85);
                            printf("Quelle propriete voulez vous voir : (choisissez entre 1 et 32) ");
                            fflush(stdin);
                            scanf("%d",&caseChoisi);
                            caseChoisi=caseChoisi-1;
                            }while(caseChoisi<0&&caseChoisi>31);
                            if(caseChoisi==0||caseChoisi==3||caseChoisi==4||caseChoisi==8||caseChoisi==11||caseChoisi==12||caseChoisi==16||caseChoisi==18||caseChoisi==20||caseChoisi==24||caseChoisi==25||caseChoisi==28||caseChoisi==29)
                            {
                                gotoligcol(26,88);
                                printf("                                      ");
                                gotoligcol(26,88);
                                printf("%s",Plateau[caseChoisi].nom);
                            }
                            else{
                            gotoligcol(23,85);
                            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xDA,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xBF);
                            gotoligcol(41,85);
                            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC0,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xD9);

                            gotoligcol(35,89);
                            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4);
                            colonneCarte(24,85);
                            colonneCarte(24,113);

                            couleur=Plateau[caseChoisi].groupe;

                            rectangleCouleur(0,couleur,86,24);

                            gotoligcol(24,90);
                            printf("Titre de Propriete");
                            gotoligcol(26,88);
                            printf("%s",Plateau[caseChoisi].nom);
                            Color(15,0);
                            gotoligcol(28,108);
                            printf("euros");
                            gotoligcol(29,87);
                            printf("LOYER");
                            gotoligcol(29,94);
                            printf("Terrain nu      %d",Plateau[caseChoisi].loyer);
                            gotoligcol(30,94);
                            printf("Avec 1 Maison   %d",Plateau[caseChoisi].loyerMaison1);
                            gotoligcol(31,99);
                            printf("2 Maisons  %d",Plateau[caseChoisi].loyerMaison2);
                            gotoligcol(32,99);
                            printf("3 Maisons %d",Plateau[caseChoisi].loyerMaison3);
                            gotoligcol(33,99);
                            printf("4 Maisons %d",Plateau[caseChoisi].loyerMaison4);
                            gotoligcol(34,99);
                            printf("HOTEL     %d",Plateau[caseChoisi].loyerHotel);
                            gotoligcol(36,86);
                            printf("Prix maisons : %d chacune",Plateau[caseChoisi].prixMaison);
                            gotoligcol(37,86);
                            printf("Prix d un Hotel %d plus 4",Plateau[caseChoisi].prixMaison);
                            gotoligcol(38,105);
                            printf("maisons");
                            gotoligcol(39,93);
                            printf("Hypothequee :");
                            gotoligcol(40,95);
                            printf("%d   euros",Plateau[caseChoisi].hypotheque);

                        }
                        }

                    }while(regarderCase==1);

                /// tri pour si le joueur est en prison, ou joueur sur autre case (même prison, simple visite)
                //joueur en prison
                if ((tableauordre[compteur].position==8) &&(tableauordre[compteur].tour_prison>=0)){
                    prison_final(Plateau,&tableauordre[compteur],tableauordre);
                }
                //joueur position autre que prison (+simple visite)
                if(tableauordre[compteur].tour_prison==-1){
                    lancedefinal(&tableauordre[compteur],Plateau);

                }

                ///lancé des dés, affichage des données du joueur et de la propriété sur laquelle il tombe

                afficher_donnee_joueur_encours(&tableauordre[compteur]);
                affichagepropriete(Plateau, &tableauordre[compteur]);
                //affichage des pions sur le plateau
                for(i=0; i<nbjoueurs; i++){
                    deplacement_pion(Plateau, &tableauordre[i], i);
                }

                ///traitement de la case en cours
                Case = tableauordre[compteur].position;
                analyse_case_joueur(&Plateau[Case], &tableauordre[compteur], Plateau, tableauordre, nbjoueurs);


                /// réaffichage des données du joueur et de la propriété pour voir les modifications si il y a eu un achat
                afficher_donnee_joueur_encours(&tableauordre[compteur]);
                affichagepropriete(Plateau, &tableauordre[compteur]);
                for(i=0; i<32; i++){
                    for(j=0; j<nbjoueurs; j++){
                        gotoligcol(0,0);
                        affichage_bien_joueurs(&Plateau[i], &tableauordre[j]);
                    }
                }


                Color(15,0);
                do{

                    gotoligcol(0,85);
                    printf("Si vous avez termine votre tour selectionner 1 : ");
                    gotoligcol(1, 85);
                    printf("Si vous voulez retourner au menu principal selectionnez 0 : ");
                    fflush(stdin);
                    scanf("%d", &continuer);
                }while(!(continuer==0) && !(continuer==1));

                nombre_mort=0;
                for (int i=0;i<nbjoueurs;i++){
                    if(tableauordre[i].mort==1){
                        nombre_mort++;
                    }
                }
                 if(tableauordre[compteur].tour_prison == -2){
                    tableauordre[compteur].tour_prison = -1;
                 }


                if(continuer==1){
                    do {
                        compteur=(compteur+1)%nbjoueurs;
                    }
                    while(tableauordre[compteur].mort==1);
                }
                if(continuer==0)
                    break;

            }while(continuer == 1 && nombre_mort!=nbjoueurs-1);
        }

        if (nombre_mort==nbjoueurs-1){
            clearScreen();
            gotoligcol(0,0);
            printf("Vous avez gagne");
        }
        else {
        clearScreen();
        menu(tableau, Plateau, &nbjoueurs, &choix, tableauordre, &numsauv, tabchargement, plateauchargement);
        gotoligcol(50, 0);
        }



    }while(!(choix==6));
    gotoligcol(50, 0); //affichage du process return en dehors du plateau
}

