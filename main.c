#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>



int main()
{

    int nbJoueurs=2;
    joueur tab[4];
    t_propriete tab2[32];
    config_joueur(tab,nbJoueurs);
    system("cls");
    remplissagetableau(tab2);
    InitilisationPlateau(tab2);
    deplacement_pion(1,tab2,tab);





}
