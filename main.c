#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>



int main()
{

    int nbJoueurs;
    joueur tab[4];
    t_propriete tab2[32];
    printf("Combien de joueurs etes vous ? :");
    do{
        scanf("%i",&nbJoueurs);
        if ((nbJoueurs>=2) && (nbJoueurs<=4))
            break;
        printf("Entrez un nombre entre 2 et 4 :");
        }
    while ((nbJoueurs<2) || (nbJoueurs>4));
    config_joueur(tab,nbJoueurs);
    system("cls");
    remplissagetableau(tab2);
    InitilisationPlateau(tab2);
    lance_de_final(&tab[0],tab2);
    deplacement_pion(nbJoueurs,tab2,tab);
    gotoligcol(100,0);


    return 0;








}
