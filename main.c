#include <stdio.h>
#include <stdlib.h>


int main()
{

    int nbJoueurs,joueurs[nbJoueurs];
    printf("Combien de joueurs etes vous ? :");
    do{
        scanf("%i",&nbJoueurs);
        if ((nbJoueurs>=1) && (nbJoueurs<=4))
            break;
        printf("Entrez un nombre entre 1 et 4 :");
        }
    while ((nbJoueurs<1) || (nbJoueurs>4));



}
