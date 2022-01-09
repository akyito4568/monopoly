#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "Biblio.h"

#define MAX_LIMIT 50
#define LIMIT 100

//menu principal
void menu(joueur tab[4], t_propriete Plateau[32], int *nbjoueurs, int* choix, joueur tabordre[4], int* numsauv, joueur tabcharg[4], t_propriete plateaucharg[32]){
        ///variables pour tout le menu
        char action = 0, action2 = 0, action3=0, continuer=0, action4=0;
        //traitement du chargement de la partie
        int i=0, c=0, j=0, d=0;
        //affichage de la console en couleurs et des instructions
        consoleencouleur(0, 15);
        Color(0, 15);
        gotoligcol(0, 50);
        printf("BIENVENU(E) !\n");
        gotoligcol(1, 43);
        printf("%c Dans Monopoly Monument %c", 0xC8, 0xBC);
        gotoligcol(2, 35);
        printf("Veuillez selectionner votre choix (1 a 6):\n");
        gotoligcol(6, 0);
        printf("          1-%c Nouvelle Partie---------------%c\n          2-%c Sauvegarder la partie---------%c\n          3-%c Charger une ancienne partie---%c\n          4-%c Afficher les regles-----------%c\n          5-%c Afficher les createurs du jeu-%c\n          6-%c Quitter-----------------------%c\n", 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11);
        printf("\nChoix-%c ", 0x10);
        scanf("%d", choix);

        while (*choix>6 || *choix<1){
            printf("Votre choix n est pas valide, veuillez selectionner de nouveau votre choix :\n   %c Nouvelle Partie\n   %c Sauvergarder la partie\n   %c Charger autre partie\n   %c Afficher les regles\n   %c Afficher les createurs du jeu\n   %c Quitter\n", 0x10, 0x10, 0x10, 0x10, 0x10, 0x10);
            fflush(stdin);
            scanf("%d", choix);
        }

        switch (*choix){
            case 1:
                //cas de nouvelle partie ou on demande le nombre de joueurs
                printf("La nouvelle partie va commencer...\n");
                printf("Appuyer sur entree pour continuer : ");
                fflush(stdin);
                scanf("%c", &action);
                consoleencouleur(15, 0);
                gotoligcol(0,0);
                printf("Selectionner le nombre de joueurs (compris entre 2 et 4) : ");
                fflush(stdin);
                scanf("%d", nbjoueurs);
                while (*nbjoueurs<2 || *nbjoueurs>4){
                    printf("Selectionner le nombre de joueurs (compris entre 2 et 4) : ");
                    fflush(stdin);
                    scanf("%d", nbjoueurs);
                }

                break;
            case 2:
                do{
                    printf("Saisir le numero de la sauvegarde (1 a 3): ");
                    fflush(stdin);
                    scanf("%d", numsauv);
                }while(!(*numsauv==1) && !(*numsauv==2) && !(*numsauv==3));

                optionsauvegarde(tabordre, Plateau, nbjoueurs, numsauv);

                printf("\nVotre partie a ete sauvegardee, appuyer sur entree pour continuer");
                fflush(stdin);
                scanf("%c", &continuer);

                break;

            case 3:
                do{
                    printf("Saisir le numero de la partie que vous voulez telecharger (1 a 3): ");
                    fflush(stdin);
                    scanf("%d", nbjoueurs);
                    printf("Saisir le nombre de joueur participant a cette ancienne partie (1 a 4): ");
                    fflush(stdin);
                    scanf("%d", numsauv);
                }while( (*nbjoueurs<1 || *nbjoueurs>4) || (*numsauv<1 || *numsauv>3));
                ///vérification que les fichier ne sont pas vides
                if(*numsauv == 1){
                    FILE* sauv1 = NULL;
                    FILE* prop1=NULL;
                    sauv1 = fopen("sauvegarde1.txt", "r");
                    prop1 = fopen("propriete1.txt", "r");

                    rewind(sauv1); //remet au début de chaque fichier leurs curseur respectifs
                    rewind(prop1);
                    do{
                        do
                        {
                            c=fgetc(sauv1);
                            i++;
                        }while(c!=EOF);
                        do
                        {
                            d=fgetc(prop1);
                            j++;
                        }while(d!=EOF);

                        if(j==1 && i==1){
                            printf("Il n existe pas de sauvegarde pour ce numero, veuillez saisir un numero valide");
                            do{
                                printf("Saisir le numero de la partie que vous voulez telecharger (1 a 3): ");
                                fflush(stdin);
                                scanf("%d", nbjoueurs);
                                printf("Saisir le nombre de joueur participant a cette ancienne partie (1 a 4): ");
                                fflush(stdin);
                                scanf("%d", numsauv);
                                }while( (*nbjoueurs<1 || *nbjoueurs>4) || (*numsauv<1 || *numsauv>3));
                        }
                        else{
                            printf("Une autre partie est en cours de telechargement. Veuillez patienter...");
                            chargement_partie(tabcharg, plateaucharg, numsauv, nbjoueurs);

                            for(i=0; i<*nbjoueurs; i++){
                                printf("%s %d %c %d %d %d %d %d %d %d\n", tabcharg[i].nom, tabcharg[i].argent, tabcharg[i].signe, tabcharg[i].nombre_propri, tabcharg[i].position, tabcharg[i].indice, tabcharg[i].couleur, tabcharg[i].tour_prison, tabcharg[i].carte_prison, tabcharg[i].mort);
                            }
                            for(i=0; i<32; i++){
                                    printf("%d %d %s %s %d %s %d %d %d %d %d %d %d %d", Plateau[i].place, Plateau[i].groupe, Plateau[i].nomgroupe, Plateau[i].nom, Plateau[i].prix, Plateau[i].nomproprietaire, Plateau[i].loyer, Plateau[i].maison, Plateau[i].hotel, Plateau[i].hypotheque, Plateau[i].x, Plateau[i].y, Plateau[i].proprietaire, Plateau[i].prix_actuel);
                            }
                            printf("\n La partie a ete chargee, vous allez commencer a jouer. Appuyez sur entree");
                            fflush(stdin);
                            scanf("%c", &action4);
                            clearScreen();
                        }

                    }while(i==1 && j==1);

                break;

            case 4:

                affichage_regles_jeu();

                fflush(stdin);
                gotoligcol(38, 0);
                printf("Appuyer sur entree pour revenir au menu...");
                scanf("%c", &action2);

                break;

            case 5:

                afficher_createurs();

                gotoligcol(15, 0);
                printf("Appuyer sur entree pour revenir au menu");
                fflush(stdin);
                scanf("%c", &action3);

                break;
            case 6:

                printf("Au revoir");

                break;
        }
    }
}

//chargement d'anciennes parties
void chargement_partie(joueur tab[4], t_propriete Plateau[32], int* numsauv, int* nbjoueurs){
    int i=0;
    FILE* sauv1=NULL;
    FILE* sauv2=NULL;
    FILE* sauv3=NULL;

    FILE* prop1=NULL;
    FILE* prop2=NULL;
    FILE* prop3=NULL;


    if(*numsauv==1){
        sauv1 = fopen("sauvegarde1.txt", "r");
        if(sauv1==NULL){
            printf("Erreur");
        }
        prop1 = fopen("propriete1.txt", "r");
        if(prop1==NULL){
            printf("Erreur");
        }
        ///saisie des joueurs dans le fichier
        for(i=0; i<*nbjoueurs; i++){
            fgets(tab[i].nom, LIMIT, sauv1);
            fscanf(sauv1, "\n%d %c %d %d %d %d %d %d %d\n", &tab[i].argent, &tab[i].signe, &tab[i].nombre_propri, &tab[i].position, &tab[i].indice, &tab[i].couleur, &tab[i].tour_prison, &tab[i].carte_prison, &tab[i].mort);
        }

        for(i=0; i<32; i++){

            fscanf(prop1, "%d %d\n", &Plateau[i].place, &Plateau[i].groupe);
            fgets(Plateau[i].nomgroupe, LIMIT, prop1);
            fscanf(prop1,"\n%d\n", &Plateau[i].prix);
            fgets(Plateau[i].nom, LIMIT, prop1);
            fscanf(prop1,"\n%d\n", &Plateau[i].loyer);
            fgets(Plateau[i].nomproprietaire, LIMIT, prop1);
            fscanf(prop1,"\n%d %d %d %d %d %d %d", &Plateau[i].maison, &Plateau[i].hotel, &Plateau[i].hypotheque, &Plateau[i].x, &Plateau[i].y, &Plateau[i].proprietaire, &Plateau[i].prix_actuel);
        }
        fclose(sauv1);
        fclose(prop1);
    }

    if(*numsauv==2){
        sauv2 = fopen("sauvegarde2.txt", "r");
        if(sauv2==NULL){
            printf("Erreur");
        }
        prop2 = fopen("propriete2.txt", "r");
        if(prop2==NULL){
            printf("Erreur");
        }
        ///saisie des joueurs dans le fichier
        for(i=0; i<*nbjoueurs; i++){
            fscanf(sauv2, "%s %d %c %d %d %d %d %d %d %d\n", tab[i].nom, &tab[i].argent, &tab[i].signe, &tab[i].nombre_propri, &tab[i].position, &tab[i].indice, &tab[i].couleur, &tab[i].tour_prison, &tab[i].carte_prison, &tab[i].mort);
        }

        for(i=0; i<32; i++){
            fscanf(prop2, "%d %d %s %s %d %s %d %d %d %d %d %d %d %d\n", &Plateau[i].place, &Plateau[i].groupe, Plateau[i].nomgroupe, Plateau[i].nom, &Plateau[i].prix, Plateau[i].nomproprietaire, &Plateau[i].loyer, &Plateau[i].maison, &Plateau[i].hotel, &Plateau[i].hypotheque, &Plateau[i].x, &Plateau[i].y, &Plateau[i].proprietaire, &Plateau[i].prix_actuel);
        }
        fclose(sauv2);
        fclose(prop2);
    }

    if(*numsauv==3){
        sauv3 = fopen("sauvegarde3.txt", "r");
        if(sauv3==NULL){
            printf("Erreur");
        }
        prop3 = fopen("propriete3.txt", "r");
        if(prop2==NULL){
            printf("Erreur");
        }
        ///saisie des joueurs dans le fichier
        for(i=0; i<*nbjoueurs; i++){
            fscanf(sauv3, "%s %d %c %d %d %d %d %d %d %d\n", tab[i].nom, &tab[i].argent, &tab[i].signe, &tab[i].nombre_propri, &tab[i].position, &tab[i].indice, &tab[i].couleur, &tab[i].tour_prison, &tab[i].carte_prison, &tab[i].mort);
        }

        for(i=0; i<32; i++){
            fscanf(prop3, "%d %d %s %s %d %s %d %d %d %d %d %d %d %d\n", &Plateau[i].place, &Plateau[i].groupe, Plateau[i].nomgroupe, Plateau[i].nom, &Plateau[i].prix, Plateau[i].nomproprietaire, &Plateau[i].loyer, &Plateau[i].maison, &Plateau[i].hotel, &Plateau[i].hypotheque, &Plateau[i].x, &Plateau[i].y, &Plateau[i].proprietaire, &Plateau[i].prix_actuel);
        }
        fclose(sauv3);
        fclose(prop3);
    }

    for(i=0; i<*nbjoueurs; i++){
        printf("%s %d %c %d %d %d %d %d %d %d\n", tab[i].nom, tab[i].argent, tab[i].signe, tab[i].nombre_propri, tab[i].position, tab[i].indice, tab[i].couleur, tab[i].tour_prison, tab[i].carte_prison, tab[i].mort);
    }
    for(i=0; i<32; i++){
        printf("%d %d %s %s %d %s %d %d %d %d %d %d %d %d", Plateau[i].place, Plateau[i].groupe, Plateau[i].nomgroupe, Plateau[i].nom, Plateau[i].prix, Plateau[i].nomproprietaire, Plateau[i].loyer, Plateau[i].maison, Plateau[i].hotel, Plateau[i].hypotheque, Plateau[i].x, Plateau[i].y, Plateau[i].proprietaire, Plateau[i].prix_actuel);
    }
}

//afficher les créateur du jeu
void afficher_createurs(){
    consoleencouleur(15,8);
    gotoligcol(5,0);
    printf("Les createurs du jeu sont :\n  %c Robin Balosso\n  %c Vinciane De Parcevaux\n  %c Julie Allier\n  %c Sixtine Gouesse\n", 0x1A, 0x1A, 0x1A, 0x1A);

}

//sauvegarde les données d'une partie
void optionsauvegarde(joueur tab[4], t_propriete Plateau[32], int* nbjoueurs, int* numsauv){
    int i=0;
    FILE* sauv1=NULL;
    FILE* sauv2=NULL;
    FILE* sauv3=NULL;

    FILE* prop1=NULL;
    FILE* prop2=NULL;
    FILE* prop3=NULL;


    if(*numsauv==1){
        sauv1 = fopen("sauvegarde1.txt", "w");
        if(sauv1==NULL){
            printf("Erreur");
        }
        prop1 = fopen("propriete1.txt", "w");
        if(prop1==NULL){
            printf("Erreur");
        }
        ///saisie des joueurs dans le fichier
        for(i=0; i<*nbjoueurs; i++){
            fprintf(sauv1, "%s\n%d %c %d %d %d %d %d %d %d\n", tab[i].nom, tab[i].argent, tab[i].signe, tab[i].nombre_propri, tab[i].position, tab[i].indice, tab[i].couleur, tab[i].tour_prison, tab[i].carte_prison, tab[i].mort);
        }

        for(i=0; i<32; i++){
              fprintf(prop1, "%d %d \n%s\n%d \n%s\n%d \n%s\n%d %d %d %d %d %d %d\n", Plateau[i].place, Plateau[i].groupe, Plateau[i].nomgroupe, Plateau[i].prix, Plateau[i].nom,  Plateau[i].loyer, Plateau[i].nomproprietaire, Plateau[i].maison, Plateau[i].hotel, Plateau[i].hypotheque, Plateau[i].x, Plateau[i].y, Plateau[i].proprietaire, Plateau[i].prix_actuel);
        }
        fclose(sauv1);
        fclose(prop1);
    }

    if(*numsauv==2){
        sauv2 = fopen("sauvegarde2.txt", "w");
        if(sauv2==NULL){
            printf("Erreur");
        }
        prop2 = fopen("propriete2.txt", "w");
        if(prop2==NULL){
            printf("Erreur");
        }
        ///saisie des joueurs dans le fichier
        for(i=0; i<*nbjoueurs; i++){
            fprintf(sauv2, "%s %d %c %d %d %d %d %d %d %d\n", tab[i].nom, tab[i].argent, tab[i].signe, tab[i].nombre_propri, tab[i].position, tab[i].indice, tab[i].couleur, tab[i].tour_prison, tab[i].carte_prison, tab[i].mort);
        }
        for(i=0; i<32; i++){
            fprintf(prop2, "%d %d %s %s %d %s %d %d %d %d %d %d %d %d", Plateau[i].place, Plateau[i].groupe, Plateau[i].nomgroupe, Plateau[i].nom, Plateau[i].prix, Plateau[i].nomproprietaire, Plateau[i].loyer, Plateau[i].maison, Plateau[i].hotel, Plateau[i].hypotheque, Plateau[i].x, Plateau[i].y, Plateau[i].proprietaire, Plateau[i].prix_actuel);
        }
        fclose(sauv2);
        fclose(prop2);
    }

    if(*numsauv==3){
        sauv3 = fopen("sauvegarde3.txt", "w");
        if(sauv3==NULL){
            printf("Erreur");
        }
        prop3 = fopen("propriete3.txt", "w");
        if(prop2==NULL){
            printf("Erreur");
        }
        ///saisie des joueurs dans le fichier
        for(i=0; i<*nbjoueurs; i++){
            fprintf(sauv3, "%s %d %c %d %d %d %d %d %d %d\n", tab[i].nom, tab[i].argent, tab[i].signe, tab[i].nombre_propri, tab[i].position, tab[i].indice, tab[i].couleur, tab[i].tour_prison, tab[i].carte_prison, tab[i].mort);
        }
        for(i=0; i<32; i++){
            fprintf(prop3, "%d %d %s %s %d %s %d %d %d %d %d %d %d %d", Plateau[i].place, Plateau[i].groupe, Plateau[i].nomgroupe, Plateau[i].nom, Plateau[i].prix, Plateau[i].nomproprietaire, Plateau[i].loyer, Plateau[i].maison, Plateau[i].hotel, Plateau[i].hypotheque, Plateau[i].x, Plateau[i].y, Plateau[i].proprietaire, Plateau[i].prix_actuel);
        }
        fclose(sauv3);
        fclose(prop3);
    }
}

//affiche les règles du jeu
void affichage_regles_jeu(){
                printf("Afficher les regles du jeu\n");
                consoleencouleur(15, 1);
                gotoligcol(0, 0);
                Color(0,14);
                printf("But du jeu/Objectif :");
                Color(15, 1);
                gotoligcol(1, 0);
                printf("L objectif du monopoly est de devenir le joueur le plus riche, via l'achat, la location et la vente de proprietes.");
                gotoligcol(2, 0);
                printf("Mais attention a la faillite ! Reservez la plutot a vos adversaires. ");

                Color(15, 4);
                gotoligcol(6, 1);
                printf("%c", 0x1D);
                gotoligcol(6, 2);
                printf("Propriete :");
                gotoligcol(7,2);
                Color(15, 1);
                printf("%c", 0x7E);
                gotoligcol(7, 3);
                printf("Le  monument ou l aeroport  n appartient a");
                gotoligcol(8,3);
                printf("personne. Le joueur est libre d acheter ou");
                gotoligcol(9,3);
                printf("non ce bien.");
                gotoligcol(9,2);
                printf("%c", 0x7E);
                gotoligcol(10,3);
                printf("Le  monument ou l aeroport appartient a un");
                gotoligcol(11, 3);
                printf("autre joueur,le joueur qui tombe sur cette");
                gotoligcol(12, 3);
                printf("case sans en etre le proprietaire  paie le");
                gotoligcol(13,3);
                printf("montant,   pour   une   visite  guidee  du");
                gotoligcol(14,3);
                printf("monument, ou de son billet d avion pour un");
                gotoligcol(15,3);
                printf("aeroport.");
                gotoligcol(16,2);
                printf("%c", 0x7E);
                gotoligcol(16,3);
                printf("Si le joueur tombe sur une case qui ne lui");
                gotoligcol(17,3);
                printf("apparient pas, et  qu il ne peut pas payer");
                gotoligcol(18,3);
                printf("sa  visite ou son billet  d avion, il doit");
                gotoligcol(19,3);
                printf("hypothequer   ses   biens   pour   pouvoir");
                gotoligcol(20,3);
                printf("continuer a jouer.Si meme apres hypotheque");
                gotoligcol(21,3);
                printf("le joueur reste endette, son tour du monde");
                gotoligcol(22,3);
                printf("s arrete, c est la faillite !");


                Color(15, 13);
                gotoligcol(6, 47);
                printf("%c", 0x1D);
                gotoligcol(6, 48);
                printf("Chance et Communaute :");
                gotoligcol(7,48);
                Color(15, 1);
                printf("%c", 0x7E);
                gotoligcol(7, 49);
                printf("Le joueur tire la premiere carte du tas de");
                gotoligcol(8, 49);
                printf("carte, et  doit  appliquer  ce qu elle lui");
                gotoligcol(9, 49);
                printf("impose.");
                gotoligcol(10,48);
                printf("%c", 0x7E);
                gotoligcol(10, 49);
                printf("Dans le  cas, ou le joueur  doit  payer un");
                gotoligcol(11, 49);
                printf("montant,si il ne peut pas payer meme apres");
                gotoligcol(12, 49);
                printf("hypotheque, c est la faillite.");
                gotoligcol(13,48);
                printf("%c", 0x7E);
                gotoligcol(13, 49);
                printf("Les carte de sortie de prison sont gardees");
                gotoligcol(14, 49);
                printf("par le joueur jusqu a utilisation.");


                Color(15, 2);
                gotoligcol(16, 47);
                printf("%c", 0x1D);
                gotoligcol(16, 48);
                printf("Impot sur le revenu :");
                Color(15, 1);
                gotoligcol(17,48);
                printf("%c", 0x7E);
                gotoligcol(17, 49);
                printf("Le joueur paie 200 euros d impot.");
                gotoligcol(18,48);
                printf("%c", 0x7E);
                gotoligcol(18, 49);
                printf("Si il ne peut pas payer, il fait faillite.");

                // case départ
                Color(15, 12);
                gotoligcol(20, 47);
                printf("%c", 0x1D);
                gotoligcol(20, 48);
                printf("Case depart :");
                Color(15, 1);
                gotoligcol(21, 48);
                printf("%c", 0x7E);
                printf("Le  joueur   reçoit  200  euros  a  chaque");
                gotoligcol(22, 49);
                printf("passage sur cette case.");
                gotoligcol(23, 48);
                printf("%c", 0x7E);
                gotoligcol(23, 49);
                printf("Si il le joueur passe sur cette case  sous");
                gotoligcol(24, 49);
                printf("effet d une carte chance ou communaute, il");
                gotoligcol(25, 49);
                printf("recoit le double du montant initial,  soit");
                gotoligcol(26, 49);
                printf("400 euros.");

                // case allez en prison
                Color(15, 11);
                gotoligcol(24, 1);
                printf("%c", 0x1D);
                gotoligcol(24, 2);
                printf("Allez en prison :");
                Color(15, 1);
                gotoligcol(25,2);
                printf("%c", 0x7E);
                gotoligcol(25, 3);
                printf("Le joueur est arrete, il part directement en");
                gotoligcol(26, 3);
                printf("prison,  ne  reçoit  pas l argent de la case");
                gotoligcol(27, 3);
                printf("depart.");
                gotoligcol(28,2);
                printf("%c", 0x7E);
                gotoligcol(28, 3);
                printf("Le joueur est libere si il fait un double,");
                gotoligcol(29, 3);
                printf("si il possede la carte sortie de prison,ou");
                gotoligcol(30, 3);
                printf("au bout de trois  tour, en  ayant paye une");
                gotoligcol(31, 3);
                printf("caution de 50 euros.");

                //case parking
                Color(15, 5);
                gotoligcol(28, 47);
                printf("%c", 0x1D);
                gotoligcol(28, 48);
                printf("Parking :");
                Color(15,1);
                gotoligcol(29, 48);
                printf("%c", 0x7E);
                printf("Il ne se  passe rien lorsqu un joueur tombe");
                gotoligcol(30, 48);
                printf("sur cette case.");
}
