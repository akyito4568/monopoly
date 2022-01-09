#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "Biblio.h"

#define MAX_LIMIT 50

//affichage des carrés de la couleur du joueurs sur ses propriétés
void affichage_bien_joueurs(t_propriete* prop, joueur* a){
    gotoligcol(0,0);

    //si la propriété appartient au joueur
    if((prop->proprietaire) == (a->indice)){
        gotoligcol(prop->y-1, prop->x);//place du curseur aux coordonnées de la case
        Color(a->couleur, 0);
        printf("%c", 0xDB);
    }

}

//analyse la position du joueur, achat, location, chance et communauté, impot, début, police, parking
void analyse_case_joueur(t_propriete* prop, joueur* a, t_propriete plateau[32], joueur tab[4], int nbjoueurs){

    ///le joueur tombe sur une case particulière
    if (a->position==0 || a->position==3 || a->position==8 || a->position==11 || a->position==16 || a->position==18 || a->position==24 || a->position==25 || a->position==29){
        //case impot
        if(a->position==29){
            gotoligcol(21,85);
            printf("Mince, vous devez payer vos impots. Payez 200 euros");
            a->argent = (a->argent)-200;
        }
        //case chance
        if((a->position==3) || (a->position==18)){
            carteChance(prop, a, plateau, tab);
            printf(" ");
        }
        //case communauté
        if((a->position==11) || (a->position==25)){
            carteCommunaute(prop, a, plateau, tab, nbjoueurs);
            printf(" ");
        }
        //case police
        if((a->position==24)){
            a->position = 8; //joueur déplacé à la case prison
            prison_final(plateau, a, tab);
        }
        if (a->position==8){
            gotoligcol(23,85);
            printf(" ");
        }
    }


    ///le joueur tombe sur une case achetable (cas location aussi)
    else{
        achat_location(prop, a, plateau, tab);
    }


}

//débite le joueur, et envoi l'argent au propriétaire
void loyer(t_propriete tab[32],joueur*a, joueur tab2[4], t_propriete* prop){
    int s,s2;
    int compteur=0;
    int tab_int[32];
    int tab_int2[32];
    groupeChek(tab);
    if (prop->loyer <= (a->argent)){
        tab2[prop->proprietaire].argent= (tab2[prop->proprietaire].argent) + (prop->loyer);
        a->argent = a->argent - prop->loyer;
    }
    else if(prop->nbProp>0 && prop->maison==0)
        {
        tab2[prop->proprietaire].argent= (tab2[prop->proprietaire].argent) + (prop->loyer)*2;
        a->argent = a->argent - (prop->loyer)*2;
    }

    else if(prop->maison==1)
        {
        tab2[prop->proprietaire].argent= (tab2[prop->proprietaire].argent) + (prop->loyerMaison1);
        a->argent = a->argent - (prop->loyerMaison1);
    }
    else if(prop->maison==2)
        {
        tab2[prop->proprietaire].argent= (tab2[prop->proprietaire].argent) + (prop->loyerMaison2);
        a->argent = a->argent - (prop->loyerMaison2);
        }
    else if(prop->maison==3)
        {
        tab2[prop->proprietaire].argent= (tab2[prop->proprietaire].argent) + (prop->loyerMaison3);
        a->argent = a->argent - (prop->loyerMaison3);
        }
    else if(prop->maison==4 && prop->hotel==0)
        {
        tab2[prop->proprietaire].argent= (tab2[prop->proprietaire].argent) + (prop->loyerMaison4);
        a->argent = a->argent - (prop->loyerMaison4);
        }
    else if(prop->hotel==1)
        {
        tab2[prop->proprietaire].argent= (tab2[prop->proprietaire].argent) + (prop->loyerHotel);
        a->argent = a->argent - (prop->loyerHotel);
        }
    else if (loyer_vente(a,tab) >= prop->loyer){
            for(int i=0;i<32;i++){
                if(tab[i].proprietaire==a->indice){
                    tab_int[compteur]=prix_vente(&tab[i]);
                    tab_int2[compteur]=tab[i].place-1;
                    compteur++;

                }
            }
        while(s < prop->loyer){
                printf("\nVous devez vendre pour: %i$",tab[a->position].loyer-a->argent-s);
                for(int k=0;k<=compteur;k++){
                    if (tab_int[k]!=0)
                        printf("\n%i.%s %i$",k,tab[tab_int2[k]].nom,tab_int[k]);
                    }
                scanf("%i",&s2);
                s=s+tab_int[s2];
                tab_int[s2]=0;
                tab[tab_int2[s2]].proprietaire=4;
                if (s- prop->loyer>0)
                    a->argent=a->argent + s-tab[a->position].loyer;

        }
    }
}

//détermine la position du joueur
int position_actuel(joueur * a){
    return (a->position);
}

//Joueur pas assez d'argent pour payer un loyer
int loyer_vente(joueur* a,t_propriete tab[32]){
    int somme=0;
    for (int i=0;i<32;i++){
        if (tab[i].proprietaire==a->indice){
            somme= somme + prix_vente(&tab[i]);
        }

    }
     return somme;
}

//rempli la variable prix actuel
void remplissagetableau2(t_propriete tab[32]){
    for (int i=0;i<32;i++)
        tab[i].prix_actuel=tab[i].prix;
    }

//rempli la variable indice du joueur
void index_l(joueur tab[4],int nbJoueurs){
    for(int i=0;i<nbJoueurs;i++){
        tab[i].indice=i;}
}

//met la variable propriétaire d'une case quand elle est vendu (plus de propriétaire)
void index_propriete(t_propriete tab[32]){
    for(int i=0;i<32;i++){
        tab[i].proprietaire=4;
        }
    }

//détermine le prix de vente d'une propriété
int prix_vente(t_propriete* a){
    int b=(a->prix_actuel)/2;
    return b;
      }

//détermine si la propriété est déjà achetée ou non, agit en fonction
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
            do {
            gotoligcol(21,85);
            printf("Voulez vous acheter ce monument, il coute %d euros? (1. Oui 2. Non)", prop->prix);
            fflush(stdin);
            scanf("%d", &choix);
            }while((!(choix==1)) && (!(choix==2)));
            //blindage de la saisie

            //si le joueur valide l'achat et qu'il a assez d'argent
            if((choix == 1) && (a->argent >= prop->prix)){
                gotoligcol(22, 85);
                a->argent = (a->argent) - (prop->prix); //débit de l'argent par la banque
                strcpy(prop->nomproprietaire, a->nom); // le nom du joueur est entré dans les données de la case propriété
                a->nombre_propri = (a->nombre_propri)+1; //le nombre de propriété du joueur augmente de 1
                prop->proprietaire = a->indice;
                printf("Vous avez achete ce monument. Felicitation !");
            }
            if((choix==1) && (a->argent < prop->prix)){
                gotoligcol(22,85);
                printf("Vous n avez pas assez d argent, vous ne pouvez pas acheter cette propriete.");
            }
            // si le joueur ne veut pas acheter
            if(choix == 2){
                gotoligcol(22, 85);
                printf("Vous avez decide de ne pas acheter ce monument.");
            }
    }
    ///si la propriété est déjà a quelqu'un
    if(!(test==0)){
        //si le joueur est le propriétaire
        if(testbis==0){
            gotoligcol(22,85);
            printf("Bienvenue chez vous %s !", a->nom);
            conditionAcheterMaison(prop,plateau,a);
        }
        // si le joueur n'est pas propriétaire
        if(!(testbis==0)){
            gotoligcol(22, 85);
            printf("Vous voulez visiter ce monument. Vous payez votre visite guidee (%d euros)", prop->loyer);
            loyer(plateau, a, tab, prop);
        }
    }
}

//vérifie que le joueur possède toutes les propriéts d'un groupe, si oui achat de maison possible
void conditionAcheterMaison(t_propriete* prop,t_propriete plateau[32], joueur* a)
{
    groupeChek(plateau);
    if((prop->groupe==13) || (prop->groupe==1)){//France et Russie
        if(prop->nbProp==2)//    On les separe car ils n'ont que deux proprietes
        {
            acheterMaison(prop,a);
        }
    }
    else{
        if(prop->nbProp==3)
        {
            acheterMaison(prop,a);
        }
    }

}

//achat de maison
void acheterMaison(t_propriete* prop,joueur* a)
{
    int compteurM=0;//Le max est 32
    int compteurH=0;//Le max est 12
    int choix;


            if(compteurM==32 && compteurH==12)//Ici on imagine qu'il n'y a plus de maison n'y d hotel
            {
                gotoligcol(23,85);
                printf("Nous n avons plus de restaurant ni d'hotel a vendre!Desole");
            }
            else{
                if(prop->maison<4)//On est dans le cas ou toutes les maisons ne sont pas encore achete et que le joueur n'ai pas encore achete toute les maisons poue avoir un hotel
                {
                    do {
                    gotoligcol(23,85);
                    printf("Voulez vous acheter un restaurants, il coute %d euros?(1. Oui 2. Non)",prop->prixMaison);
                    fflush(stdin);
                    scanf("%d", &choix);
                    }while((!(choix==1)) && (!(choix==2)));
                    if(choix == 1){
                        gotoligcol(24, 85);
                        a->argent = (a->argent) - (prop->prixMaison); //d�bit de l'argent par la banque
                        prop->maison=prop->maison+1;//ajoute +1 au nombre de restaurant dans la propriete
                        printf("Vous avez achete un restaurant. Tres bon choix !");
                        compteurM=compteurM+1;
                    }
                    // si le joueur ne veut pas acheter
                    if(choix == 2){
                    gotoligcol(24, 85);
                    printf("Vous avez decide de ne pas acheter ce restaurant.");}
                }
                else if(prop->maison==4&&prop->hotel==0){
                    do {
                    gotoligcol(23,85);
                    printf("Voulez vous acheter un hotel, il coute %d euros?(1. Oui 2. Non)",prop->prixMaison);
                    fflush(stdin);
                    scanf("%d", &choix);
                    }while((!(choix==1)) && (!(choix==2)));
                    if(choix == 1)
                    {
                        a->argent = (a->argent) - (prop->prixMaison); //d�bit de l'argent par la banque
                        prop->hotel=prop->hotel+1;//ajoute +1 au nombre d hotel dans la propriete
                        printf("Vous avez achete un hotel. Excellent investissement !");
                        compteurM=compteurM-4;
                        compteurH=compteurH+1;
                    }
                    if(choix == 2){
                    gotoligcol(24, 85);
                    printf("Vous avez decide de ne pas acheter cet hotel.");
                    }

                }
            }

}

//vérifie que le joueur possède toutes les propriétés d'un groupe
void groupeChek(t_propriete plateau[32])
{
    if( strcmp(plateau[1].nomproprietaire, plateau[2].nomproprietaire)==0)
    {
        plateau[1].nbProp=2;
        plateau[2].nbProp=2;
    }
    else if( strcmp(plateau[30].nomproprietaire, plateau[31].nomproprietaire)==0)
    {
        plateau[30].nbProp=2;
        plateau[31].nbProp=2;
    }
    else if( strcmp(plateau[5].nomproprietaire, plateau[6].nomproprietaire)==0 && strcmp(plateau[6].nomproprietaire, plateau[7].nomproprietaire)==0)
    {
        plateau[5].nbProp=3;
        plateau[6].nbProp=3;
        plateau[7].nbProp=3;
    }
    else if( strcmp(plateau[9].nomproprietaire, plateau[10].nomproprietaire)==0 && strcmp(plateau[10].nomproprietaire, plateau[13].nomproprietaire)==0)
    {
        plateau[9].nbProp=3;
        plateau[10].nbProp=3;
        plateau[13].nbProp=3;
    }
    else if( strcmp(plateau[14].nomproprietaire,plateau[15].nomproprietaire)==0 && strcmp(plateau[15].nomproprietaire,plateau[17].nomproprietaire)==0)
    {
        plateau[14].nbProp=3;
        plateau[15].nbProp=3;
        plateau[17].nbProp=3;
    }
    else if( strcmp(plateau[19].nomproprietaire, plateau[21].nomproprietaire)==0 && strcmp(plateau[21].nomproprietaire, plateau[22].nomproprietaire)==0)
    {
        plateau[19].nbProp=3;
        plateau[21].nbProp=3;
        plateau[22].nbProp=3;
    }
    else if( strcmp(plateau[23].nomproprietaire, plateau[26].nomproprietaire)==0 && strcmp(plateau[26].nomproprietaire, plateau[27].nomproprietaire)==0)
    {
        plateau[23].nbProp=3;
        plateau[26].nbProp=3;
        plateau[27].nbProp=3;
    }
}
