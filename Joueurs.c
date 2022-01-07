#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "Biblio.h"

#define MAX_LIMIT 50

void config_joueur(joueur a[4],int nbJoueurs)
{
    int i=0,choix=0, choix2=0;
    char tab[]= {0x03,0x04,0x05,0x06};
    int couleurjoueur[4]={1,2,3,4};
    for(i=0; i<nbJoueurs; i++)
    {
        a[i].argent=1500;
        a[i].position=0;
        a[i].nombre_propri=0;
        a[i].indice=i;
        a[i].tour_prison=-1;
        a[i].carte_prison=0;
        a[i].mort=0;

        printf("\nChoisir signe \n1.%c \n2.%c \n3.%c \n4.%c  \n",0x03,0x04,0x05,0x06);

        do
        {
            scanf("%i",&choix);
            a[i].signe=tab[choix-1];
            if (tab[choix-1]!='b' && (choix>0) &&(choix<5) )
            {
                tab[choix-1]='b';
                break;
            }
            printf("Veuillez saisir un signe valable ou un chiffre entre 1 et 4 : ");

        }while ((tab[choix-1]=='b')||(choix<1)||(choix>4));
        printf("\nVotre signe est le : %c",a[i].signe);
        fflush(stdin);

        printf("\nChoisissez votre couleur \n1.Bleu \n2.Vert \n3.Turquoise \n4.Rouge  \n");
        do
        {
            scanf("%d",&choix2);
            (a[i].couleur)=couleurjoueur[choix2-1];

            if (couleurjoueur[choix2-1]!='b' && (choix2>0) &&(choix2<5) )
            {
                couleurjoueur[choix2-1]='b';
                break;
            }
            printf("Veuillez saisir une couleur valable, soit un chiffre entre 1 et 4 : ");
        }while ((couleurjoueur[choix2-1]=='b')||(choix2<1)||(choix2>4));
        printf("\nVotre couleur est la numero %d", a[i].couleur);

        printf("\nChoisir un nom :");
        fflush(stdin);
        gets((a[i].nom));
    }
}

//remplissage de la structure pour un joueur avec passage par adresse
void configuration_joueur(joueur* a){
    int choix=0, choix2=0;
    char tab[]={0x03, 0x04, 0x05,0x06}; //tableau contenant les signes
    int couleurjoueur[]={1,2,3,4};

    (a->argent)=1500;
    (a->nombre_propri)=0;
    (a->position)=0;

    printf("\nChoisissez votre signe \n1.%c \n2.%c \n3.%c \n4.%c  \n",0x03,0x04,0x05,0x06);
        do
        {
            scanf("%i",&choix);
            (a->signe)=tab[choix-1];

            if (tab[choix-1]!='b' && (choix>0) &&(choix<5) )
            {
                tab[choix-1]='b';
                break;
            }
            printf("Veuillez saisir un signe valable, soit un chiffre entre 1 et 4 : ");
        }while ((tab[choix-1]=='b')||(choix<1)||(choix>4));
        printf("\nVotre signe est le : %c\n", a->signe);

        fflush(stdin);
        printf("\nChoisissez votre couleur \n1.Bleu \n2.Vert \n3.Turquoise \n4.Rouge  \n");
        do
        {
            scanf("%d",&choix2);
            (a->couleur)=couleurjoueur[choix2-1];

            if (couleurjoueur[choix2-1]!='b' && (choix2>0) &&(choix2<5) )
            {
                couleurjoueur[choix2-1]='b';
                break;
            }
            printf("Veuillez saisir une couleur valable, soit un chiffre entre 1 et 4 : ");
        }while ((couleurjoueur[choix2-1]=='b')||(choix2<1)||(choix2>4));
        printf("\nVotre couleur est la numero %d", a->couleur);

        printf("\nChoisir un nom :");
        fflush(stdin);
        gets((a->nom));

}


void afficher_donnee_joueur_encours(joueur* tab){
    Color(15,0);
    gotoligcol(15, 85);
    printf("Le joueur qui joue est %s", tab->nom);
    gotoligcol(16, 85);
    printf("Vos informations :");
    gotoligcol(17, 87);
    printf("Couleur : numero %d (1.Bleu 2.Vert 3.Turquoise 4.Rouge)", tab->couleur);
    gotoligcol(18, 87);
    printf("Symbole : %c", tab->signe);
    gotoligcol(19,87);
    printf("Argent : %d", tab->argent);
    gotoligcol(20,87);
    printf("Case : %d", (tab->position)+1);
}

void ordrepassagejoueurs(int nbjoueurs, joueur tab[4], joueur tabapres[4]){
    srand(time(NULL));
    int tirage=0, i=0;
    char action=0;
    Color(15,0);
    tirage = rand()%((nbjoueurs-1) - 0 + 1)+0;
    if(nbjoueurs==2){ //cas avec deux joueurs
        if(tirage==0){ //ordre inchangé
            tabapres[0]=tab[0];
            tabapres[1]=tab[1];
            printf("\nL ordre des tours est le suivant : %s, %s", tabapres[0].nom, tabapres[1].nom);
        }
        if(tirage==1){ //le deuxième joueur commence
            tabapres[0]=tab[1];
            tabapres[1]=tab[0];
            printf("\nL ordre des tours est le suivant : %s, %s", tabapres[0].nom, tabapres[1].nom);
        }
    }
    if(nbjoueurs==3){ //cas avec trois joueurs
        if(tirage==0){ //ordre inchangé
            for(i=0; i<3; i++){
                tabapres[i]=tab[i];
            }
            printf("\nL ordre des tours est le suivant : %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom);
        }
        if(tirage==1){ // le deuxième joueur commence, l'ordre suit
            tabapres[0]=tab[1];
            tabapres[1]=tab[2];
            tabapres[2]=tab[0];
            printf("\nL ordre des tours est le suivant : %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom);
        }
        if(tirage==2){ //le troisième joueur commence, l'ordre suit
            tabapres[0]=tab[2];
            tabapres[1]=tab[0];
            tabapres[2]=tab[1];
            printf("\nL ordre des tours est le suivant : %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom);
        }
    }
    if(nbjoueurs==4){//cas avec quatre joueurs
        if(tirage==0){//ordre inchangé
            for(i=0; i<4; i++){
                tabapres[i]=tab[i];
            }
            printf("\nL ordre des tours est le suivant : %s, %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom, tabapres[3].nom);
        }
        if(tirage==1){ //le deuxième joueur commence
            tabapres[0]=tab[1];
            tabapres[1]=tab[2];
            tabapres[2]=tab[3];
            tabapres[3]=tab[0];
            printf("\nL ordre des tours est le suivant : %s, %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom, tabapres[3].nom);
        }
        if(tirage==2){
            tabapres[0]=tab[2];
            tabapres[1]=tab[3];
            tabapres[2]=tab[0];
            tabapres[3]=tab[1];
            printf("\nL ordre des tours est le suivant : %s, %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom, tabapres[3].nom);
        }
        if(tirage==3){
            tabapres[0]=tab[3];
            tabapres[1]=tab[0];
            tabapres[2]=tab[1];
            tabapres[3]=tab[2];
            printf("\nL ordre des tours est le suivant : %s, %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom, tabapres[3].nom);
        }
    }
    printf("\nVous avez ete place sur la case depart.");
    printf("\nAppuyer sur entree pour continuer");
    fflush(stdin);
    scanf("%c", &action);
    consoleencouleur(15,0);
}




