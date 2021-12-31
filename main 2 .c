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
    do{
    clearScreen();
    gotoligcol(0,0);

    InitilisationPlateau(tab2);
    lance_de_final(&tab[compteur],tab2);
    deplacement_pion(nbJoueurs,tab2,tab);
    compteur=(compteur+1)%nbJoueurs;
    gotoligcol(0,85);
    printf("Avez vous fini votre tour ? :");
    scanf("%i",&continuer);




    if (continuer==1)
        continue;
    }
    while (1);


    return 0;








}
