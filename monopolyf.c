#include <stdio.h>
#include <stdlib.h>
#define MAX_LIMIT 20

typedef struct coord{
    int x,y;
    }coord;

typedef struct joueur{
    char nom[MAX_LIMIT];
    int argent;
    char signe;
    int nombre_propri;
    int position;
    coord pos_cord;
    }joueur;


void config_joueur(joueur a[],int nbJoueurs){




    int i=0,choix=0;
    char tab[]={0x03,0x04,0x05,0x06};
    for(i;i<nbJoueurs;i++){
        a[i].argent=1500;
        a[i].position=0;
        a[i].nombre_propri=0;

        printf("\n41Choisir signe \n1.%c \n2.%c \n3.%c \n4.%c  ",0x03,0x04,0x05,0x06);
        
        do {
                scanf("%i",&choix);
                a[i].signe=tab[choix];
                if (tab[])
                
                
        while (a[i].signe==0)
        
        
        
       
        
        printf("%c",a[i].signe);


        printf("\n Choisir un nom (20 char max :)");
        fgets(a[i].nom,MAX_LIMIT,stdin);




    }










    }
