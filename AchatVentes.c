#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "Biblio.h"

#define MAX_LIMIT 50


void consoleencouleur(int couleurtexte, int couleurfond){
    int i=0, j=0;
    for (j=0; j<119; j++){
        for (i=0; i<60; i++){
            Color(couleurtexte, couleurfond);
            gotoligcol(i, j);
            printf(" ");
        }
    }
}

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void gotoligcol( int lig, int col)
{
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void clearScreen(){
    system("cls");
    }
void affichage_bien_joueurs(t_propriete* prop, joueur* a){
    int test=0;
    gotoligcol(0,0);
    test = strcmp(prop->nomproprietaire, a->nom);
    //si la propriété appartient au joueur
    if(test==0){
        gotoligcol(prop->y-1, prop->x);//place du curseur aux coordonnées de la case
        Color(a->couleur, 0);
        printf("%c", 0xDB);
    }

}


int analyse_case_joueur(t_propriete* prop, joueur* a, t_propriete plateau[32], joueur tab[4]){

    ///le joueur tombe sur une case particulière

        //case impot
        if(a->position==29){
            gotoligcol(21,85);
            printf("Mince, vous devez payer vos impots. Payez 200 euros");
            a->argent = (a->argent)-200;
            return 0;
        }
        //case chance
        if((a->position==3) || (a->position==18)){
            ///appel sous-programme chance sixtine
            return 0;
        }
        //case communauté
        if((a->position==11) || (a->position==25)){
            ///appel sous-programme communauté sixtine
            return 0;
        }
        //case police
        if((a->position==24)){
            a->position = 8; //joueur déplacé à la case prison
            prison_final(plateau, a, tab);
            return 0;
        }
        if (a->position==8){
            return 0;
        }



    ///le joueur tombe sur une case achetable (cas location aussi)
    else{
        achat_location(prop, a, plateau, tab);
        return 0;
    }

}

int prison_final(t_propriete tab[32],joueur *a,joueur tab2[4]){
    int choix;
    gotoligcol(21, 85);
    printf("Vous etes en prison");
    if (a->carte_prison==1){
        gotoligcol(22,85);
        printf("Vous avez une carte prison voulez vous l'utiliser (1=Oui 0=Non)? :");
        scanf("%i",&choix);//a blinder
        if (choix==1){
            a->tour_prison=-2;
            a->carte_prison--;
            return 0;}


        else{
                prison_basic(tab,a,tab2);
                return 0;
                    }
}

    prison_basic(tab,a,tab2);

    return 0;
}

void loyer(t_propriete tab[32],joueur*a, joueur tab2[4]){
    int s,s2;
    int compteur=0;
    int tab_int[32];
    int tab_int2[32];
    if (tab[a->position].loyer <= (a->argent)){
        tab2[tab[a->position].proprietaire].argent= (tab2[tab[a->position].proprietaire].argent) + (tab[a->position].loyer);
        a->argent = a->argent - tab[a->position].loyer;}

    else if (loyer_vente(a,tab)>=tab[a->position].loyer){
            for(int i=0;i<32;i++){
                if(tab[i].proprietaire==a->indice){
                    tab_int[compteur]=prix_vente(&tab[i]);
                    tab_int2[compteur]=tab[i].place-1;
                    compteur++;

                }
            }
        while(s<tab[a->position].loyer){
                printf("\nVous devez vendre pour: %i$",tab[a->position].loyer-a->argent-s);
                for(int k=0;k<=compteur;k++){
                    if (tab_int[k]!=0)
                        printf("\n%i.%s %i$",k,tab[tab_int2[k]].nom,tab_int[k]);
                    }
                scanf("%i",&s2);
                s=s+tab_int[s2];
                tab_int[s2]=0;
                tab[tab_int2[s2]].proprietaire=4;
                if (s-tab[a->position].loyer>0){
                    a->argent=a->argent + s-tab[a->position].loyer;}

        }
        tab2[tab[a->position].proprietaire].argent= (tab2[tab[a->position].proprietaire].argent) + (tab[a->position].loyer);

    }
    else {
            for(int i=0;i<32;i++){
                if(tab[i].proprietaire==a->indice){
                    tab_int[compteur]=prix_vente(&tab[i]);
                    tab_int2[compteur]=tab[i].place-1;
                    compteur++;

                }
            }
                for (int i=0;i<compteur;i++){
                s=s+tab_int[i];
                //tab_int[i]=0;
                tab[tab_int2[i]].proprietaire=4;

                    }

                    a->argent=0;
                    a->mort=1;
                    tab2[tab[a->position].proprietaire].argent= (tab2[tab[a->position].proprietaire].argent) + s;




    }
}

int position_actuel(joueur * a){
    return (a->position);
}


void index(joueur tab[4]){
    for(int i=0;i<4;i++){
        tab[i].indice=i;
    }
}

int loyer_vente(joueur* a,t_propriete tab[32]){
    int somme=0;
    for (int i=0;i<32;i++){
        if (tab[i].proprietaire==a->indice){
            somme= somme + prix_vente(&tab[i]);
        }

    }
     return somme;
}

int prix_vente(t_propriete* a){
    int b=(a->prix_actuel)/2;
    return b;
      }
void remplissagetableau2(t_propriete tab[32]){
    for (int i=0;i<32;i++)
        tab[i].prix_actuel=tab[i].prix;
    }
void index_l(joueur tab[4],int nbJoueurs){
    for(int i=0;i<nbJoueurs;i++){
        tab[i].indice=i;}


    }

void index_propriete(t_propriete tab[32]){
    for(int i=0;i<32;i++){
        tab[i].proprietaire=4;
        }
    }

int prison_basic(t_propriete tab[32],joueur *a,joueur tab2[4]){
    int choix;
    srand(time(NULL));
    gotoligcol(22,85);
        if (a->tour_prison!=2){
            printf("\n1.Lancer les des \n2.Payer amende");
            scanf("%i",&choix);}//a blinder

        else
            choix=1;

        if(choix==1)
        {
            if(doubles_prison(a)==1)
            {
                printf("\nVous avez fait un double vous sortez de prison");
                a->tour_prison=-2;
                return 0;
            }
            else if (a->tour_prison==2){
                    a->argent=a->argent-50;
                    a->tour_prison=-2;
                    lancedefinal(a,tab);
                    return 0;

            }
            else
            {
                printf("\nVous n'avez pas fait un double vous restez en prison");
                a->tour_prison++;
                 return 0;
            }
        }
        if (choix==2)// blinder!!
        {
            a->argent=a->argent-50;
            a->tour_prison=-2;
            lancedefinal(a,tab);
            return 0;
        }
    return 0;
}

int doubles_prison(joueur * a){
    int de1,de2;
    LanceDe(&de1,&de2);
    printf("\n%i %i",de1,de2);
    if (de1==de2){
        a->position=a->position + de2 + de1;
        return 1;
    }

        return 0;
}


void achat_location (t_propriete* prop, joueur* a, t_propriete plateau[32], joueur tab[4]){
    int choix=0;
    int test=0, testbis=0;
    char nomp[50];
    Color(15, 0);
    gotoligcol(21, 85);

    strcpy(nomp, "/");
    test = strcmp(nomp, prop->nomproprietaire);
    testbis = strcmp(prop->nomproprietaire, a->nom);

    /// si la propriété n'a pas encore été acheté
    if (test==0){
        //si pas monument
        if (a->position==0 || a->position==3 || a->position==8 || a->position==11 || a->position==16 || a->position==18 || a->position==24 || a->position==25 || a->position==29){
            printf(" ");
        }
        //si propriété
        else{
            do {
            gotoligcol(21,85);
            printf("Voulez vous acheter ce monument, il coute %d euros? (1. Oui 2. Non)", prop->prix);
            fflush(stdin);
            scanf("%d", &choix);
            }while((!(choix==1)) && (!(choix==2)));
            //blindage de la saisie

            //si le joueur valide l'achat
            if(choix == 1){
                gotoligcol(22, 85);
                a->argent = (a->argent) - (prop->prix); //débit de l'argent par la banque
                strcpy(prop->nomproprietaire, a->nom); // le nom du joueur est entré dans les données de la case propriété
                a->nombre_propri = (a->nombre_propri)+1; //le nombre de propriété du joueur augmente de 1
                prop->proprietaire = a->indice;
                printf("Vous avez achete ce monument. Felicitation !");
            }
            // si le joueur ne veut pas acheter
            if(choix == 2){
                gotoligcol(22, 85);
                printf("Vous avez decide de ne pas acheter ce monument.");
            }
        }
    }
    ///si la propriété est déjà a quelqu'un
    if(!test==0){
        //si le joueur est le propriétaire
        if(testbis==0){
            gotoligcol(22,85);
            printf("Bienvenue chez vous %s !", a->nom);
        }
        // si le joueur n'est pas propriétaire
        if(!testbis==0){
            gotoligcol(22, 85);
            printf("Vous voulez visiter ce monument. Vous payez votre visite guidee (%d euros)", prop->loyer);
            loyer(plateau, a, tab);
        }
    }
}
