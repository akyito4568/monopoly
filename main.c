#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>



int main()
{

    int nbJoueurs;
    joueur tab[4];
    t_propriete tab2[32];
    int compteur=0;
    int continuer=0;

    printf("Combien de joueurs etes vous ? :");
    do{
        scanf("%i",&nbJoueurs);
        if ((nbJoueurs>=2) && (nbJoueurs<=4))
            break;
        printf("Entrez un nombre entre 2 et 4 :");
        }
    while ((nbJoueurs<2) || (nbJoueurs>4));
    config_joueur(tab,nbJoueurs);
    remplissagetableau(tab2);
    clearScreen();



    do{

    clearScreen();

    gotoligcol(0,0);





    //InitilisationPlateau(tab2);





    //lance_de_final(&tab[compteur],tab2);
    InitilisationPlateau(tab2);
    if ((tab[compteur].position==8) &&(tab[compteur].tour_prison>=0)){
        prison_final(tab2,&tab[compteur],tab);
        }

    if(tab[compteur].tour_prison==-1){
        lance_de_final(&tab[compteur],tab2);

        }
     if (tab[compteur].position==24){
            printf("Vous etes en prison");
            tab[compteur].position=8;
            tab[compteur].tour_prison++;}

    deplacement_pion(nbJoueurs,tab2,tab);

     if (tab[compteur].tour_prison==-2){
        tab[compteur].tour_prison=-1;
        }
    ;
    compteur=(compteur+1)%nbJoueurs;

    gotoligcol(0,85);
    printf("Avez vous fini votre tour ? :");

    scanf("%i",&continuer);





    if (continuer==1)
        continue;


    //if (tab[i].position==8 && tab[i].tour_prison>=0)
       // prison_final();
    //if(tab[i].tour_prison!==-1)
        //lance_de_final();

    }
    while (1);






}
