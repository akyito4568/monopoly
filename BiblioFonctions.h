#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define MAX_LIMIT 20

typedef struct Propriete{ // définition structure case
    int place;
    int groupe;
    char nomgroupe[30];
    char nom[30];
    int prix;
    char biens;
    int loyer;
    int maison;
    int hotel;
    int hypotheque;
    int x;
    int y;
}t_propriete;

typedef struct coord //structure pour coordonnées des joueurs
{
    int x,y;
} coord;

typedef struct joueur //structure des joueurs
{
    char nom[MAX_LIMIT];
    int argent;
    char signe;
    int indice;
    int nombre_propri;
    int position;
    coord pos_cord;
} joueur;

void afficher_donnee_joueur_encours(joueur tab[4], int indice);
void deplacement_pion(int nombre_joueur,t_propriete tab_p[32],joueur tab_j[4]);
void menu(joueur tab[4],t_propriete Plateau[32], int* nbjoueurs, int* choix, joueur tabordre[4]);
void Color(int couleurDuTexte,int couleurDeFond);
void gotoligcol( int lig, int col);
void InitilisationPlateau(t_propriete Plateau[32]);
void affichagepropriete(t_propriete Plateau[32], joueur tab[4], int indice);
void remplissagetableau(t_propriete Plateau[32]);
void consoleencouleur();
void config_joueur(joueur a[4],int nbJoueurs);
void optionsauvegarde(joueur tab[4], int nbjoueurs, char nomsauvegarde[10]);
void clearScreen();
void LanceDe(int * de1,int * de2);
int doubles(int * a);
void lancedefinal(joueur tableau[4], t_propriete tab[32], int indice, int* compteursortie, int* validationprison);

#endif // FONCTIONS_H_INCLUDED
