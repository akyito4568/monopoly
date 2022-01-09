#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "Biblio.h"

#define MAX_LIMIT 50

//traitement de tous les cas de prison
void prison_final(t_propriete tab[32],joueur *a,joueur tab2[4]){
    int choix;
    gotoligcol(21, 85);
    Color(15, 0);
    printf("Vous etes en prison");
    if (a->carte_prison==1){
        gotoligcol(22,85);
        printf("Vous avez une carte prison voulez vous l'utiliser (1=Oui 0=Non)? :");
        scanf("%i",&choix);//a blinder
        if (choix==1){
            a->tour_prison=-2;
            a->carte_prison--;
            lancedefinal(a, tab);
        }


        else{
                prison_basic(tab,a,tab2);
        }
}

    prison_basic(tab,a,tab2);
}

//traitement des cas de prison sans carte chance
void prison_basic(t_propriete tab[32],joueur *a,joueur tab2[4]){
    int choix=1;
    srand(time(NULL));
    if(!(a->tour_prison==2)){
           do{
            gotoligcol(22,85);
            printf("1.Lancer les des 2.Payer amende  ");
            fflush(stdin);
            scanf("%i",&choix);
           }while(!(choix==1) && !(choix==2));
    }
        ///le joueur choisi de lancer les des
        if(choix==1)
        {   //il fait un double
            if(doubles_prison(a)==1)
            {
                gotoligcol(23,85);
                printf("Vous avez fait un double vous sortez de prison");
                a->tour_prison=-1;
            }
            // il est en prison depuis 3 tours
            else if (a->tour_prison==2){
                    a->argent=a->argent-50;
                    a->tour_prison=-1;
                    gotoligcol(23,85);
                    printf("Vous etes en prison depuis 3 tours, vous payez votre caution et lancez les des.");
                    lancedefinal(a,tab);

            }
            else // pas de double et en prison depuis moins de trois tours
            {
                gotoligcol(23,85);
                printf("Vous n'avez pas fait un double vous restez en prison");
                a->tour_prison = a->tour_prison +1;
            }
        }
        ///le joueur choisi de payer sa caution
        //il a assez d'argent
        if ((choix==2) && (a->argent >= 50))
        {
            a->argent=a->argent-50;
            a->tour_prison=-1;
            gotoligcol(23, 85);
            printf("Vous avez paye votre caution, vous sortez de prison");
        }
        // pas assez d'argent, lance les des par défaut
        if((choix==2) && (a->argent <50)){
            gotoligcol(23,85);
            printf("Vous n avez pas assez d argent pour payer votre caution, vous lancez les dés par défaut.");
            if(doubles_prison(a)==1)
            {
                gotoligcol(23,85);
                printf("\nVous avez fait un double vous sortez de prison"); // si double sort de prison
                a->tour_prison=-1;
            }
            else if (a->tour_prison==2){
                    a->argent=a->argent-50;
                    a->tour_prison=-1;
                    lancedefinal(a,tab);
        }
    }
}

//traitement des doubles pour la libération de prison
int doubles_prison(joueur * a){
    int de1,de2;
    LanceDe(&de1,&de2);
    printf("\n%i %i",de1,de2);
    if (de1==de2){
        a->position=a->position + de2 + de1;
        return 1;
    }

    return 0;
}

