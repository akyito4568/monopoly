#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Fonctions.h"

int main()
{

    joueur tableau[4];
    t_propriete Plateau[32]; //déclaration du plateau
    remplissagetableau(Plateau);

    menu(); //affichage du menu principal



    return 0;
}
