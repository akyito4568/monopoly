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
    int prixMaison;
    int nbProp;
    int loyerMaison1;
    int loyerMaison2;
    int loyerMaison3;
    int loyerMaison4;
    int loyerHotel;
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


///fichier Analyse case
void affichage_bien_joueurs(t_propriete* prop, joueur* a);
void analyse_case_joueur(t_propriete* prop, joueur* a, t_propriete plateau[32], joueur tab[4], int nbjoueurs);
void loyer(t_propriete tab[32], joueur*a, joueur tab2[4], t_propriete* prop);
int position_actuel(joueur * a);
int loyer_vente(joueur* a,t_propriete tab[32]);
int prix_vente(t_propriete* a);
void remplissagetableau2(t_propriete tab[32]);
void index_l(joueur tab[4],int nbJoueurs);
void index_propriete(t_propriete tab[32]);
void achat_location (t_propriete* prop, joueur* a, t_propriete plateau[32], joueur tab[4]);
void groupeChek(t_propriete plateau[32]);
void acheterMaison(t_propriete* prop,joueur* a);
void conditionAcheterMaison(t_propriete* prop,t_propriete plateau[32], joueur* a);

///fichier Cartes
void colonneCarteC(int positionX,int positionY);
void HautCarteC();
void BasCarteC();
void ligne();
void carteChance(t_propriete* prop, joueur* a, t_propriete plateau[32], joueur tab[4]);
void carteCommunaute(t_propriete* prop, joueur* a, t_propriete plateau[32], joueur tab[4],int nbjoueurs);

///fichier Des
void deplacement_pion(t_propriete tab_p[32],joueur* tab, int i);
void LanceDe(int * de1,int * de2);
int doubles(int * a);
void lancedefinal(joueur* a, t_propriete tab[32]);

///fichier Fonctions
void consoleencouleur(int couleurtexte, int couleurfond);
void Color(int couleurDuTexte,int couleurDeFond) ;
void gotoligcol( int lig, int col);
void clearScreen();

///fichier Joueur
void config_joueur(joueur a[4],int nbJoueurs);
void afficher_donnee_joueur_encours(joueur* tab);
void ordrepassagejoueurs(int nbjoueurs, joueur tab[4], joueur tabapres[4]);

///fichier Menu
void optionsauvegarde(joueur tab[4], t_propriete Plateau[32], int* nbjoueurs, int* numsauv);
void affichage_regles_jeu();
void afficher_createurs();
void chargement_partie(joueur tab[4], t_propriete Plateau[32], int* numsauv, int* nbjoueurs);
void menu(joueur tab[4], t_propriete Plateau[32], int *nbjoueurs, int* choix, joueur tabordre[4], int* numsauv, joueur tabcharg[4], t_propriete plateaucharg[32]);

///fichier Plateau
void couleurPlateau();
void remplir_prop(t_propriete* pro, int i);
void affichagepropriete(t_propriete Plateau[32], joueur* tab);
void affichageplateau(t_propriete Plateau[32]);
void bandecouleur(int couleurtexte, int couleurfond,int positionX,int positionY );
void colonneCarteProp(int positionX,int positionY);
void colonneCarte(int positionX,int positionY);
void colonnecouleur(int couleurtexte, int couleurfond,int positionX,int positionY);
void rectangleCouleur(int couleurtexte, int couleurfond,int positionX,int positionY);

///fichier Prison
int doubles_prison(joueur * a);
void prison_basic(t_propriete tab[32],joueur *a,joueur tab2[4]);
void prison_final(t_propriete tab[32],joueur *a,joueur tab2[4]);

#endif // FONCTIONS_H_INCLUDED
