#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_LIMIT 20


void menu(){
        int choix;
        char action = 0;
        //affichage de la console en couleurs et des instructions
        consoleencouleur(0, 15);
        Color(0, 15);
        gotoligcol(8, 50);
        printf("BIENVENU(E) !\n");
        gotoligcol(9, 43);
        printf("%c Dans Monopoly Monument %c", 0xC8, 0xBC);
        gotoligcol(10, 35);
        printf("Veuillez selectionner votre choix (1 a 6):\n");
        gotoligcol(14, 0);
        printf("          1-%c Nouvelle Partie---------------%c\n          2-%c Sauvergarder la partie--------%c\n          3-%c Charger une ancienne partie---%c\n          4-%c Afficher les regles-----------%c\n          5-%c Afficher les createurs du jeu-%c\n          6-%c Quitter-----------------------%c\n", 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11);
        printf("\nChoix-%c ", 0x10);
        scanf("%d", &choix);

        while (choix>6 || choix<1){
            printf("Votre choix n est pas valide, veuillez selectionner de nouveau votre choix :\n   %c Nouvelle Partie\n   %c Sauvergarder la partie\n   %c Charger autre partie\n   %c Afficher les regles\n   %c Afficher les createurs du jeu\n   %c Quitter\n", 0x10, 0x10, 0x10, 0x10, 0x10, 0x10);
            fflush(stdin);
            scanf("%d", &choix);
        }

        switch (choix){
            case 1:
                printf("La nouvelle partie va commencer...\n");
                printf("Appuyer sur une touche et valider pour continuer : ");
                fflush(stdin);
                scanf("%c", &action);
                consoleencouleur(15, 0);
                gotoligcol(0,0);
               /*
                printf("Selectionner le nombre de joueurs (compris entre 2 et 4) : ");
                fflush(stdin);
                scanf("%d", &nbjoueurs);
                while (nbjoueurs<2 || nbjoueurs>4){
                    printf("Selectionner le nombre de joueurs (compris entre 2 et 4) : ");
                    fflush(stdin);
                    scanf("%d", &nbjoueurs);
                }
                */


                break;
            case 2:
                printf("Votre partie a ete sauvegardee\n");
                break;
            case 3:
                printf("Une autre partie est en cours de telechargement\n");
                break;
            case 4:
                printf("Afficher les regles du jeu\n");
                break;
            case 5:
                printf("Les createurs du jeu sont :\n  %c Robin \n  %c Vinciane\n  %c Julie\n  %c Sixtine\n", 0x1A, 0x1A, 0x1A, 0x1A);
                break;
            case 6:
                break;
        }
}

void consoleencouleur(int couleurtexte, int couleurfond){
    int i=0, j=0;
    //le fond de la console en blanc
    for (j=0; j<120; j++){
        for (i=0; i<50; i++){
            Color(couleurtexte, couleurfond);
            gotoligcol(i, j);
            printf(" ");
        }
    }
}
