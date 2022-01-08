#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define MAX_LIMIT 50

typedef struct Propriete
{
    int place;
    int groupe;
    char nomgroupe[MAX_LIMIT];
    char nom[MAX_LIMIT];
    int prix;
    char nomproprietaire[MAX_LIMIT];
    int loyer;
    int maison;
    int hotel;
    int hypotheque;
    int x;
    int y;
    int proprietaire;
    int prix_actuel;
} t_propriete;

typedef struct coord //structure pour coordonnées des joueurs
{
    int x,y;
} coord;


typedef struct joueur
{
    char nom[MAX_LIMIT];
    int argent;
    char signe;
    int nombre_propri;
    int position;
    coord pos_cord;
    int indice;
    int couleur;
    int tour_prison;
    int carte_prison;
    int mort;
}joueur;

//fichier Menu
void menu(joueur tab[4], t_propriete Plateau[32], int *nbjoueurs, int* choix, joueur tabordre[4], int* numsauv, joueur tabcharg[4], t_propriete plateaucharg[32]);
void optionsauvegarde(joueur tab[4], t_propriete Plateau[32], int* nbjoueurs, int* numsauv);
void affichage_regles_jeu();
void afficher_createurs();
void chargement_partie(joueur tab[4], t_propriete Plateau[32], int* numsauv, int* nbjoueurs);

//fichier Plateau
void remplir_prop(t_propriete* pro, int i);
void couleurPlateau();
void colonnecouleur(int couleurtexte, int couleurfond,int positionX,int positionY);
void bandecouleur(int couleurtexte, int couleurfond,int positionX,int positionY );
void affichageplateau(t_propriete Plateau[32]);
void affichagepropriete(t_propriete Plateau[32], joueur* tab);
void rectangleCouleur(int couleurtexte, int couleurfond,int positionX,int positionY);
void colonneCarteProp(int positionX,int positionY);
void colonneCarte(int positionX,int positionY);


//fichier Fonctions
void consoleencouleur(int couleurtexte, int couleurfond);
void Color(int couleurDuTexte,int couleurDeFond);
void gotoligcol( int lig, int col);
void clearScreen();

//fichier Joueurs
void config_joueur(joueur a[4],int nbJoueurs);
void configuration_joueur(joueur* a);
void afficher_donnee_joueur_encours(joueur* tab);
void ordrepassagejoueurs(int nbjoueurs, joueur tab[4], joueur tabapres[4]);

//fichier Dés
void deplacement_pion(t_propriete tab_p[32],joueur* tab, int i);
void LanceDe(int * de1,int * de2);
int doubles(int * a);
void lancedefinal(joueur* tableau, t_propriete tab[32]);
void lance_de_final(joueur * a, t_propriete tab[32]);

//fichier AchatVente etc
void achat_location (t_propriete* prop, joueur* a, t_propriete plateau[32], joueur tab[4]);
void loyer(t_propriete tab[32],joueur*a,joueur tab2[4], t_propriete* prop);
int prix_vente(t_propriete* a);
int loyer_vente(joueur* a,t_propriete tab[32]);

void affichage_bien_joueurs(t_propriete* prop, joueur* a);

int prison_basic(t_propriete tab[32],joueur *a,joueur tab2[4]);
int doubles_prison(joueur * a);
int prison_final(t_propriete tab[32],joueur *a,joueur tab2[4]);

void analyse_case_joueur(t_propriete* prop, joueur* a, t_propriete plateau[32], joueur tab[4], int nbjoueurs);

void index_propriete(t_propriete tab[32]);
void index_l(joueur tab[4],int nbJoueurs);

void remplissagetableau2(t_propriete tab[32]);

int position_actuel(joueur * a);


///Cartes
void carteChance(t_propriete* prop, joueur* a, t_propriete plateau[32], joueur tab[4]);
void colonneCarteC(int positionX,int positionY);
void HautCarteC();
void BasCarteC();
void ligne();
void carteCommunaute(t_propriete* prop, joueur* a, t_propriete plateau[32], joueur tab[4],int nbjoueurs);
