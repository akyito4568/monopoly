#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "Biblio.h"

#define MAX_LIMIT 50


void achat_location (t_propriete* prop, joueur* a){
    int choix=0;
    int test=0, testbis=0;
    char nomp[50];
    Color(15, 0);
    gotoligcol(21, 85);

    strcpy(nomp, "/");
    test = strcmp(nomp, prop->nomproprietaire);
    testbis = strcmp(prop->nomproprietaire, a->nom);

    /// si la propriété n'a pas encore été acheté
    if (test==0){
        //si pas monument
        if (a->position==0 || a->position==3 || a->position==8 || a->position==11 || a->position==16 || a->position==18 || a->position==24 || a->position==25 || a->position==29){
            printf(" ");
        }
        //si propriété
        else{
            do {
            gotoligcol(21,85);
            printf("Voulez vous acheter ce monument, il coute %d ? (1. Oui 2. Non)", prop->prix);
            fflush(stdin);
            scanf("%d", &choix);
            }while((!(choix==1)) && (!(choix==0)));
            //blindage de la saisie

            //si le joueur valide l'achat
            if(choix == 1){
                gotoligcol(22, 85);
                a->argent = (a->argent) - (prop->prix); //débit de l'argent par la banque
                strcpy(prop->nomproprietaire, a->nom); // le nom du joueur est entré dans les données de la case propriété
                printf("Vous avez acheter ce monument. Felicitation !");
            }
            // si le joueur ne veut pas acheter
            if(choix == 0){
                gotoligcol(22, 85);
                printf("Vous avez decider de ne pas acheter ce monument.");
            }
        }
    }
    ///si la propriété est déjà a quelqu'un
    if (test==1){
        //si le joueur est le propriétaire
        if(testbis==0){
            gotoligcol(22,85);
            printf("Bienvenue chez vous %s !", a->nom);
        }
        // si le joueur n'est pas propriétaire
        if(test==0){
            gotoligcol(22, 85);
            printf("Vous voulez visiter ce monument. Vous payer votre visite guidee (%d euros)", prop->loyer);
            a->argent = (a->argent) - (prop->loyer);
        }
    }
}
