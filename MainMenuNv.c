#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Fonctions.h"

int main()
{
    int nbjoueurs = 0;
    joueur tableau[4]; //ce tableau est rempli dans le menu si on selectionne la nouvelle partie
    t_propriete Plateau[32]; //déclaration du plateau
    //affichage du menu principal
    nbjoueurs = menu(tableau);

    consoleencouleur(15,0);

    remplissagetableau(Plateau);
    InitilisationPlateau(Plateau);

    deplacement_pion(nbjoueurs, Plateau, tableau);
    gotoligcol(50, 10);
    affichagepropriete(Plateau);





    return 0;
}
