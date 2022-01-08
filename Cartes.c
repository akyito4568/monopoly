#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "Biblio.h"

#define MAX_LIMIT 50

void colonneCarteC(int positionX,int positionY)
{
    int i=0, j=0;
    for (j=positionY; j<positionY+1; j++){
        for (i=positionX; i<positionX+10; i++){
            gotoligcol(i, j);
            printf("%c",0xBA);
        }
    }

}
void HautCarteC()
{
    gotoligcol(15,17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB);

}
void BasCarteC()
{
    gotoligcol(26,17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBC);

}
void ligne()
{
    gotoligcol(24,32);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4);

}
//Fonction

void carteChance(t_propriete* prop, joueur* a, t_propriete plateau[32], joueur tab[4])
{
    srand(time(NULL));
    int i;
    Color(15, 0);

            gotoligcol(21, 85);
            printf("C'est votre jour de CHANCE");
            i=rand()%(15-0+1)+0;
        switch (i){
    case 0:


        a->argent = (a->argent) - 20;   //Amende pour location illegale : payez 20 euros

        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,20);
        colonneCarteC(16,68);
        ligne();
        Color(15,0);
        gotoligcol(20,23);
        printf("     Amende pour location illegale : ");
        gotoligcol(22,23);
        printf("               payez 20 euros ");


        break;

    case 1:
        a->position=28;                 //Il fait froid et la neige paralyse le trafic aerien :allez a l aeroport 4

        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,20);
        printf("Il fait froid et la neige paralyse le trafic");
        gotoligcol(22,20);
        printf("       aerien : allez a l aeroport 4");

        break;

    case 2:
        a->argent = (a->argent) + 50;   //Vous recevez le prix du plus beau monument :touchez 50 euro
        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,20);
        printf("Vous recevez le prix du plus beau ");
        gotoligcol(22,20);
        printf("   monument : touchez 50 euros");

        break;

    case 3:
        a->argent = (a->argent) - 70;   //Votre monument a besoin de reparations :payez 70 euros
        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,20);
        printf("   Votre monument a besoin de reparations :");
        gotoligcol(22,20);
        printf("               payez 70 euros");

        break;

    case 4:
        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
            gotoligcol(20,20);
            printf("Rendez vous aux Etats-Unis pour admirer le ");
            gotoligcol(21,20);
            printf("     Mont Rushmore:si vous passez par ");
            gotoligcol(22,20);
            printf("    la case depart, recevez 200 euros");

        if(a->position=18)
        {
            a->position=15;                 //Rendez vous aux Etats-Unis pour admirer le Mont Rushmore: si vous passez par la case depart,recevez 200 euros.
            a->argent = (a->argent) + 200;
        }
        else{
            a->position=15;                 //Rendez vous aux Etats-Unis pour admirer le Mont Rushmore: si vous passez par la case depart,recevez 200 euros.

        }

        break;

    case 5:
        a->position=a->position-2;          //Reculez de deux cases

        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
            gotoligcol(20,20);
            printf("            Reculez de deux cases");

        break;

    case 6:
        a->argent = (a->argent) - 50;       //Un seisme a endommage vos proprietes : payez les renovations 50 euros
        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
            gotoligcol(20,20);
            printf("    Un seisme a endommage vos proprietes : ");
            gotoligcol(22,20);
            printf("      payez les renovations 50 euros");

        break;
    case 7:
        a->argent = (a->argent) + 50;       //Vous recevez le prix du plus beau monument :touchez 50 euros

        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
            gotoligcol(20,20);
            printf("    Vous recevez le prix du plus beau");
            gotoligcol(22,20);
            printf("       monument : touchez 50 euros");
        break;

    case 8:
        a->argent = (a->argent) - 70;       //Votre monument a besoin de reparations :payez 70 euro

        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
            gotoligcol(20,20);
            printf("    Votre monument a besoin de reparations :");
            gotoligcol(22,20);
            printf("             payez 70 euros");
        break;

    case 9:
        a->argent = (a->argent) - 50;       //Un degat des eau a eu lieu : payez les reparations 50 euros
        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
            gotoligcol(20,20);
            printf("        Un degat des eau a eu lieu :");
            gotoligcol(22,20);
            printf("       payez les reparations 50 euros");

        break;

    case 10:
        a->argent = (a->argent) + 100;      //Votre monument a recu des dons : touchez 100 euros

        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
            gotoligcol(20,20);
            printf("        Votre monument a recu des dons :");
            gotoligcol(22,20);
            printf("                touchez 100 euros");

        break;

    case 11:
        a->position=8;
        a->tour_prison=0;                     //Vous avez ete arrete sans votre passeport : allez directement en prison,ne passez pas par la casedepart
        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
            gotoligcol(20,20);
            printf("Vous avez ete arrete sans votre passeport :");
            gotoligcol(21,20);
            printf("      allez directement en prison,");
            gotoligcol(22,20);
            printf("    ne passez pas par la case depart");
        break;

    case 12:
        a->position=0;                      //Avancez jusqu a la case depart
        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
            gotoligcol(20,20);
            printf("     Avancez jusqu a la case depart");

        break;

    case 13:
        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        a->carte_prison=1;
        Color(15,0);
            gotoligcol(20,20);
            printf("  Sortie de prison : vous etes libere de prison ");


        break;

    case 14:
        a->position=12;                     //Votre passeport a ete vole : allez a l aeroport 2sans passer par la case depart, payez 50 euros pour faire refaire votre passepor
        a->argent = (a->argent) - 50;
        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
            gotoligcol(20,20);
            printf("    Votre passeport a ete vole : allez a ");
            gotoligcol(21,20);
            printf("   l aeroport 2 sans par la case depart,");
            gotoligcol(22,20);
            printf("payez 50 euros pour faire refaire votre passeport");

        break;

    case 15:
        a->argent = (a->argent) + 100;      //Votre monument a recu des dons : touchez 100 euros
        Color(12,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
            gotoligcol(20,20);
            printf("      Votre monument a recu des dons :");
            gotoligcol(22,20);
            printf("                touchez 100 euros");

        break;


    }

}
void carteCommunaute(t_propriete* prop, joueur* a, t_propriete plateau[32], joueur tab[4],int nbjoueurs)
{
    srand(time(NULL));
    int i;
    Color(15, 0);

            gotoligcol(21, 85);
            printf("Bienvenue au centre de Communautes");
            i=rand()%(15-0+1)+0;
        switch (i){
    case 0:
        a->position=0;
        a->argent = (a->argent) + 400;   //Alors que vous ne pensiez pas pouvoir faire un metre de plus, vous franchissez la ligne d arrivee du marathon, vous recevez des fond pour l hopital local : avancez a la case depart, touchez 400 euro

        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(19,20);
        printf("Alors que vous ne pensiez pas pouvoir faire");
        gotoligcol(20,20);
        printf("un metre de plus, vous franchissez la ligne");
        gotoligcol(21,20);
        printf("d arrivee du marathon, vous recevez des fond");
        gotoligcol(22,20);
        printf("  pour l hopital local : avancez a la case ");
        gotoligcol(23,20);
        printf("        depart, touchez 400 euros");

        break;

    case 1:
        a->argent = (a->argent) + 50;    //Vous avez achete des patisserie pour une oeuvre de charite : recevez 50 euros

        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,20);
        printf("     Vous avez achete des patisserie pour");
        gotoligcol(22,20);
        printf("    une oeuvre de charite : recevez 50 euros");


        break;

    case 2:
        a->argent = (a->argent) + 100;   //Vous avez aide a construire une aire de jeu dans une ecole : recevez 100 euros

        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,20);
        printf(" Vous avez aide a construire une aire de jeu");
        gotoligcol(22,20);
        printf("      dans une ecole : recevez 100 euros");
        break;

    case 3:
        a->argent = (a->argent) + 100;   //Vous prenez le temps de bavarder avec d autres touristes : recevez 100 euros
        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,20);
        printf("     Vous prenez le temps de bavarder avec");
        gotoligcol(22,20);
        printf("     d autres touristes : recevez 100 euros");

        break;

    case 4:
        a->position=8;                  //Vous ecoutez de la musique trop fort tard le soir : allez en prison
        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,20);
        colonneCarteC(16,68);
        ligne();
        Color(15,0);
        gotoligcol(20,20);
        printf("  Vous ecoutez de la musique trop fort tard ");
        gotoligcol(22,20);
        printf("          le soir : allez en prison");
        break;

    case 5:
        a->argent = (a->argent) + 200;  //Vous aidez des locaux a nettoyer leurs jardins apres une grosse tempete : recevez 200 euro
        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(19,20);
        printf("          Vous aidez des locaux  ");
        gotoligcol(20,20);
        printf("a nettoyer leurs jardins apres une grosse ");
        gotoligcol(21,20);
        printf("        tempete : recevez 200 euros");

        break;

    case 6:
        a->argent = (a->argent) + 10*nbjoueurs;       //Vous distribuez des parapluies pour chaque personne attendant la visite de votre monument sous la pluie : chaque joueur vous doit 10 euros
        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(19,20);
        printf(" Vous distribuez des parapluies pour chaque ");
        gotoligcol(20,19);
        printf("personne attendant la visite de votre monument");
        gotoligcol(21,20);
        printf("      sous la pluie : chaque joueur vous ");
        gotoligcol(22,20);
        printf("             doit 10 euros");

        break;
    case 7:
        a->argent = (a->argent) + 50;       //Vous recevez le prix du plus beau monument :touchez 50 euros
        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,20);
        printf("Vous recevez le prix du plus beau monument :");
        gotoligcol(22,20);
        printf("              touchez 50 euros");



        break;

    case 8:
        a->argent = (a->argent) - 50;       //Votre ami a oublie son portefeuille : vous payez volontiers le diner, 50 euros
        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,20);
        printf("   Votre ami a oublie son portefeuille : ");
        gotoligcol(22,20);
        printf(" vous payez volontiers le diner, 50 euros");
        break;

    case 9:
        a->argent = (a->argent) - 100;       //Vous allez au lave-auto caritatif de l'�cole du quartier, mais vous oubliez de fermer vos fen�tres ! Payez 100 euros
        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,20);
        printf("Vous allez au lave-auto caritatif de l'ecole ");
        gotoligcol(21,19);
        printf("   du quartier, mais vous oubliez de fermer ");
        gotoligcol(22,20);
        printf("       vos fenetres !Payez 100 euros");

        break;

    case 10:
        a->argent = (a->argent) + 10;      //Vous donnez votre sang. Il y avait des g�teaux gratuits. Recevez 10 euros
        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,20);
        printf("            Vous donnez votre sang. ");
        gotoligcol(21,19);
        printf("        Il y avait des gateaux gratuits. ");
        gotoligcol(22,20);
        printf("                Recevez 10 euros");
        break;

    case 11:
        a->argent = (a->argent) + 20;      //Miaou ! Vous tricotez des pulls douillets pour les chats sans fourrure du refuge animalier . Recevez 20 euros.
        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,20);
        printf("Miaou ! Vous tricotez des pulls douillets pour");
        gotoligcol(21,19);
        printf(" les chats sans fourrure du refuge animalier.");
        gotoligcol(22,20);
        printf("                Recevez 20 euros");
        break;

    case 12:
        a->argent = (a->argent) + 10;      //Vous faites don de l'argent re�u pour votre anniversaire � un centre social. Gardez-en un peu pour vous. Recevez 10 euros
        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,19);
        printf("Vous faites don de l'argent recu pour votre");
        gotoligcol(21,19);
        printf("      anniversaire a un centre social.");
        gotoligcol(22,20);
        printf("Gardez-en un peu pour vous. Recevez 10 euros");
        break;

    case 13:
        a->argent = (a->argent) + 10*nbjoueurs;//Vous organisez une visite gratuite de votre monument : chaque joueur vous doit 10 euros
        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,19);
        printf("     Vous organisez une visite gratuite");
        gotoligcol(21,19);
        printf("de votre monument : chaque joueur vous doit");
        gotoligcol(22,20);
        printf("                  10 euros");
        break;

    case 14:
        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(21,19);
        a->carte_prison=1;
        printf(" Sortie de prison vous etes libere de prison");

        break;

    case 15:
        a->position=14;                      //Vous avez oubliez de prendre de belles photos lors d�une de vos visites : Retournez � la Statue de la libert� aux Etats-Unis.
        Color(9,0);
        BasCarteC();
        HautCarteC();
        colonneCarteC(16,17);
        colonneCarteC(16,65);
        ligne();
        Color(15,0);
        gotoligcol(20,19);
        printf("Vous avez oubliez de prendre de belles photos");
        gotoligcol(21,19);
        printf("   lors d une de vos visites : Retournez a ");
        gotoligcol(22,20);
        printf("    la Statue de la liberte aux Etats-Unis");
        break;

        }
}
