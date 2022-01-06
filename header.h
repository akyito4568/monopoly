#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define MAX_LIMIT 20
typedef struct coord
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
    int index;
    int tour_prison;
    int carte_prison;


} joueur;


typedef struct Propriete
{

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

    int proprietaire;

    int prix_actuel;





} t_propriete;
void InitilisationPlateau(t_propriete Plateau[32]);

void affichagepropriete(t_propriete Plateau[32]);

void remplissagetableau(t_propriete Plateau[32]);
void config_joueur(joueur a[4],int nbJoueurs);
void gotoligcol( int lig, int col );
void deplacement_pion(int numero_joueur,t_propriete tab_p[32],joueur tab_j[4]);
int prison_final(t_propriete tab[32],joueur *a,joueur tab2[4]);

int prison_basic(t_propriete tab[32],joueur * a,joueur tab2[4]);
void lance_de_final(joueur * a, t_propriete tab[32]);



#endif // HEADER_H_INCLUDED
