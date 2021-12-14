#include "mabiblio.h"
///sous programme permettant de choisir l'ordre de passage
void debutejoueur(int*j1,int*j2,int*j3, int*j4)///passage par adresse avec des pointeurs
{
    srand(time(NULL));///on initialise le générateur aléatoire
    int i,j;
    do{
    printf("Saisissez le nombre de joueurs entre 2 et 4\n"); ///on saisie le nombre de joueur
    scanf("%d",&i);
    }while(i>4 || i<2); ///on blinde pour avoir entre 2 à 4 joueurs
    j=rand()%(i-1+1)+1; ///nombre aléatoire entre le nbr de joueurs à 1
    if (i==2)           ///si le nbre de joueurs est 2
    {
        if (j==1)       ///si nombre aléatoire est 1,j1 commence
        {
            printf("Joueur 1 commence\n");
            printf("Joueur 2 joue en deuxieme\n");
            *j1=1,*j2=2,*j3=0,*j4=0;
        }
        else        ///sinon j2 commence
        {
            printf("Joueur 2 commence\n");
            printf("Joueur 1 joue en deuxieme\n");
            *j2=1,*j1=2,*j3=0,*j4=0;
        }
    }
    else if (i==3)      /// sinon si le nbre de joueurs est 3
    {
        if (j==1)       ///si j1 commence,j2 joue en 2eme,j3 en dernier
        {
            printf("Joueur 1 commence\n");
            printf("Joueur 2 joue en deuxième\n");
            printf("Joueur 3 joue en dernier\n");
             *j1=1,*j2=2,*j3=3,*j4=0;
        }
        else if (j==2) ///si j2 commence,j3 après,puis j1
        {
            printf("Joueur 2 commence\n");
            printf("Joueur 3 joue en deuxième\n");
            printf("Joueur 1 joue en dernier\n");
            *j1=3,*j2=1,*j3=2,*j4=0;
        }
        else       ///sinon j3 commence,j1 suit,puis j2
        {
            printf("Joueur 3 commence\n");
            printf("Joueur 1 joue en deuxième\n");
            printf("Joueur 2 joue en dernier\n");
            *j1=2,*j2=3,*j3=1,*j4=0;
           }
        }
    else ///sinon le nbr de joueur est 4
    {
        if (j==1)   ///si j1 commence,j2 suit,j3 après,puis j4
        {
            printf("Joueur 1 commence\n");
            printf("Joueur 2 joue en deuxième\n");
            printf("Joueur 3 joue en troisième\n");
            printf("Joueur 4 joue en dernier\n");
            *j1=1,*j2=2,*j3=3,*j4=4;
        }
        else if (j==2)  ///sinon si j2 commence,j3 suit,j4 puis j1
        {
            printf("Joueur 2 commence\n");
            printf("Joueur 3 joue en deuxième\n");
            printf("Joueur 4 joue en troisième\n");
            printf("Joueur 1 joue en dernier\n");
            *j1=4,*j2=1,*j3=2,*j4=3;
        }
        else if (j==3)  ///sinon si j3 commence,j4 suit,j1 puis j2
        {
            printf("Joueur 3 commence\n");
            printf("Joueur 4 joue en deuxième\n");
            printf("Joueur 1 joue en troisième\n");
            printf("Joueur 2 joue en dernier\n");
            *j1=3,*j2=4,*j3=1,*j4=2;
        }
        else    ///sinon j4 commence,j1 suit,j2 puis j3
        {
            printf("Joueur 4 commence\n");
            printf("Joueur 1 joue en deuxième\n");
            printf("Joueur 2 joue en troisième\n");
            printf("Joueur 3 joue en dernier\n");
            *j1=2,*j2=3,*j3=4,*j4=1;
        }

    }
}
