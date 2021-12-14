#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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
    int nombre_propri;
    int position;
    coord pos_cord;
} joueur;

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

void deplacement_pion(int nombre_joueur,t_propriete tab_p[32],joueur tab_j[4]){
    InitilisationPlateau(tab_p);
        for (int i=0;i<nombre_joueur;i++){
            gotoligcol((tab_p[tab_j[i].position].y),(tab_p[tab_j[i].position].x-i));
            printf("%c",tab_j[i].signe);
        }
}

void config_joueur(joueur a[4],int nbJoueurs)
{
    int i=0,choix=0;
    char tab[]= {0x03,0x04,0x05,0x06};
    for(i; i<nbJoueurs; i++)
    {
        a[i].argent=1500;
        a[i].position=0;
        a[i].nombre_propri=0;
        printf("\nChoisissez votre signe \n1.%c \n2.%c \n3.%c \n4.%c  \n",0x03,0x04,0x05,0x06);
        do
        {
            scanf("%i",&choix);
            a[i].signe=tab[choix-1];
            if (tab[choix-1]!='b' && (choix>0) &&(choix<5) )
            {
                tab[choix-1]='b';
                break;
            }
            printf("Veuillez saisir un signe valable ou un chiffre entre 1 et 4 : ");
        }
        while ((tab[choix-1]=='b')||(choix<1)||(choix>4));
        printf("\nVotre signe est le : %c\n",a[i].signe);
        printf("Vous etes le joueur numero %d\n", i);
        fflush(stdin);
        printf("\nChoisir un nom (20 caractere max ) :");
        fgets(a[i].nom,MAX_LIMIT,stdin);
    }
}
void InitilisationPlateau(t_propriete Plateau[32])
{   int j=0;
    int a=24;
    int z=32;
    int espace=0;
    int propriete=0;
    int taille=9;
    for(j=0;j<taille;j++)
    {
        ///Disposition des cases horizontales
        if (j==0)
        {
    gotoligcol(1,4);
            printf("%c%c%c%c%c%c%c%c%c",0xDA,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC2);
            for(propriete=0;propriete<taille-2;propriete++)
            {
                printf("%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC2);
            }
            printf("%c%c%c%c%c%c%c%c\n    ",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xBF);
    gotoligcol(2,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c       ",0xB3);
            }
    gotoligcol(2,76);
            printf("%c",0xB3);
    gotoligcol(3,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c   %d   ",0xB3,Plateau[propriete].place); //place la case debut à la case prison
            }
    gotoligcol(3,76);
            printf("%c",0xB3);
            printf("\n\n");
    gotoligcol(4,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c       ",0xB3);
            }
    gotoligcol(4,76);
            printf("%c",0xB3);
    gotoligcol(5,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c       ",0xB3);
            }
    gotoligcol(5,76);
            printf("%c",0xB3);
    gotoligcol(6,4);
            printf("%c%c%c%c%c%c%c%c%c",0xC3,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC5);
            for(propriete=0;propriete<taille-3;propriete++)
            {
                printf("%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC1);
            }
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xB4);
        }
        else if(j==taille-1)
        {
    gotoligcol(41,76);
            printf("%c",0xB3);
    gotoligcol(41,4);
            printf("%c%c%c%c%c%c%c%c%c",0xC3,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC5);
            for(propriete=0;propriete<taille-3;propriete++)
            {
                printf("%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC2);
            }
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xB4);
    gotoligcol(42,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c       ",0xB3);
            }
    gotoligcol(42,76);
            printf("%c",0xB3);
    gotoligcol(43,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c   %d  ",0xB3,Plateau[a-(propriete)].place);// place la Parking à la case Police
            }
    gotoligcol(43,76);
            printf("%c",0xB3);
    gotoligcol(44,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c       ",0xB3);
            }
    gotoligcol(44,76);
            printf("%c",0xB3);
    gotoligcol(45,76);
            printf("%c",0xB3);
    gotoligcol(45,4);
            for(propriete=0;propriete<taille;propriete++)
            {
                printf("%c       ",0xB3);
            }
    gotoligcol(46,4);
            printf("%c%c%c%c%c%c%c%c%c",0xC0,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC1);
            for(propriete=0;propriete<taille-2;propriete++)
            {
                printf("%c%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC1);
            }
            printf("%c%c%c%c%c%c%c%c\n    ",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xD9);
        }
        else
        {
            for(espace=0;espace<taille;espace++)
            {
                ///disposition des cases verticales
                if(espace==0)
                {
                    printf("    %c       %c                                                       %c       %c\n",0xB3,0xB3,0xB3,0xB3);
                    printf("    %c   %d  %c   ",0xB3,Plateau[z-(j)].place,0xB3);//place la case 26 à la case 32
                }
                else if(espace==taille-1)
                {
                    printf("   %c   %d  %c\n",0xB3,Plateau[j+8].place,0xB3);//place la case 10 à la case 16
                    printf("    %c       %c                                                       %c       %c\n",0xB3,0xB3,0xB3,0xB3);
                    printf("    %c       %c                                                       %c       %c\n",0xB3,0xB3,0xB3,0xB3);

                    printf("    %c%c%c%c%c%c%c%c%c   ",0xC3,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xB4);
                    for(espace=0;espace<taille;espace++)
                    {
                        printf("     ");
                    }
                    printf("       %c%c%c%c%c%c%c%c%c",0xC3,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xB4);
                }
                else
                {
                    printf("       ");
                }
            }
        }
    printf("\n");
    }
}

void affichagepropriete(t_propriete Plateau[32])
{
    int choixcase=0;
    do{
        printf("\nQuelle case voulez vous regarder ");
        scanf("%d",&choixcase);
    }while(choixcase<1||choixcase>32);
    choixcase=choixcase-1;
    if(choixcase==0||choixcase==3||choixcase==4||choixcase==8||choixcase==12||choixcase==16||choixcase==20||choixcase==24||choixcase==28||choixcase==29)
    {
        printf("\n%s",Plateau[choixcase].nom);
    }
    else
    {
        printf("\nPays: %s\nMonument: %s\nPrix: %d\nProprietaire: %c\nLoyer: %d\nMaison: %d\nHotel: %d\nHypotheque: %d",Plateau[choixcase].nomgroupe,Plateau[choixcase].nom,Plateau[choixcase].prix,Plateau[choixcase].biens,Plateau[choixcase].loyer,Plateau[choixcase].maison,Plateau[choixcase].hotel,Plateau[choixcase].hypotheque);
    }
}

void remplissagetableau(t_propriete Plateau[32])
{
    /***********Initialisation des cases du plateau***********/
   t_propriete Debut ={1,0,"Evenement","Debut",0,'0',0,0,0,0,8,5};        ///place,groupe,nom,prix,biens(dans le sens qui est le proprietere),loyer,maison,hotel,hypotheque,x,y
    t_propriete PlaceRouge ={2,1,"Russie","Place Rouge",60,'0',0,0,0,30,16,5};
    t_propriete Bolchoi ={3,1,"Russie","Bolchoï",60,'0',0,0,0,30,24,5};
    t_propriete Impot1={4,0,"Evenement","Impot 1",0,'0',0,0,0,0,32,5};
    t_propriete Chance1 ={5,0,"Evenement","Chance 1",0,'0',0,0,0,0,0,5};
    t_propriete OperaSydney ={6,2,"Australie","Opera Sydney",60,'0',0,0,0,30,40,5};
    t_propriete BarrieredeCorail ={7,2,"Australie","Barriere de Corail",60,'0',0,0,0,30,48,5};
    t_propriete PalaisRoyaldesExpositions ={8,2,"Australie","Palais Royal des Expositions",60,'0',0,0,0,30,56,5};
    t_propriete Prison={9,0,"Evenement","Prison",0,'0',0,0,0,0,64,5};
    t_propriete ChristRedempteur ={10,3,"Bresil","Christ Redempteur",60,'0',0,0,0,30,72,10};
    t_propriete CathedraleMetroporitana ={11,3,"Bresil","Cathedrale Metroporitana",60,'0',0,0,0,30,72,15};
    t_propriete TheatreAmazonas ={12,3,"Bresil","Theatre Amazonas",60,'0',0,0,0,30,72,20};
    t_propriete Communaute1={13,0,"Evenement","Communaute 1",0,'0',0,0,0,0,72,25};
    t_propriete LAlhambra ={14,4,"Espagne","LAlhambra",60,'0',0,0,0,30,72,30};
    t_propriete BasiliqueSagradaFamilia ={15,4,"Espagne","Basilique Sagrada Familia",60,'0',0,0,0,30,72,35};
    t_propriete TheatreromaindeLaMerida ={16,4,"Espagne","Theatre romain de la Merida",60,'0',0,0,0,30,72,40};
    t_propriete Parking={17,0,"Evenement","Parking",0,'0',0,0,0,0,72,45};
    t_propriete StatuedeLaLiberte ={18,5,"Etats-Unis","Statue de la Liberte",60,'0',0,0,0,30,64,45};
    t_propriete MontRushmore ={19,5,"Etats-Unis","Mont Rushmore",60,'0',0,0,0,30,56,45};
    t_propriete GrandCanyon ={20,5,"Etats-Unis","Grand Canyon",60,'0',0,0,0,30,48,45};
    t_propriete Chance2 ={21,0,"Evenement","Chance 2",0,'0',0,0,0,0,40,45};
    t_propriete Colisee ={22,6,"Italie","Colisee",60,'0',0,0,0,30,32,45};
    t_propriete TourdePise ={23,6,"Italie","Tour de Pise",60,'0',0,0,0,30,24,45};
    t_propriete CathedraldeMilan ={24,6,"Italie","Cathedrale de Milan",60,'0',0,0,0,30,16,45};
    t_propriete Police ={25,0,"Evenement","Police",0,'0',0,0,0,0,8,45};
    t_propriete Skytree ={26,7,"Japon","Skytree",60,'0',0,0,0,30,8,40};
    t_propriete PalaisimperialdeKyoto ={27,7,"Japon","Palais Imperial de Kyoto",60,'0',0,0,0,30,8,35};
    t_propriete PalaisimperialdeTokyo ={28,7,"Japon","Palais Imperial de Tokyo",60,'0',0,0,0,30,8,30};
    t_propriete Communaute2={29,0,"Evenement","Communaute 2",0,'0',0,0,0,0,8,25};
    t_propriete Impot2={30,0,"Evenement","Impot 2",0,'0',0,0,0,0,8,20};
    t_propriete ArcdeTriomphe ={31,8,"France","Arc de Triomphe",60,'0',0,0,0,30,8,15};
    t_propriete TourEiffel ={32,8,"France","Tour Eiffel",60,'0',0,0,0,30,8,10};

    Plateau[0]=Debut;
    Plateau[1]=PlaceRouge;
    Plateau[2]=Bolchoi;
    Plateau[3]=Impot1;
    Plateau[4]=Chance1;
    Plateau[5]=OperaSydney;
    Plateau[6]=BarrieredeCorail;
    Plateau[7]=PalaisRoyaldesExpositions;
    Plateau[8]=Prison;
    Plateau[9]=ChristRedempteur;
    Plateau[10]=CathedraleMetroporitana;
    Plateau[11]=TheatreAmazonas;
    Plateau[12]=Communaute1;
    Plateau[13]=LAlhambra;
    Plateau[14]=BasiliqueSagradaFamilia;
    Plateau[15]=TheatreromaindeLaMerida;
    Plateau[16]=Parking;
    Plateau[17]=StatuedeLaLiberte;
    Plateau[18]=MontRushmore;
    Plateau[19]=GrandCanyon;
    Plateau[20]=Chance2;
    Plateau[21]=Colisee;
    Plateau[22]=TourdePise;
    Plateau[23]=CathedraldeMilan;
    Plateau[24]=Police;
    Plateau[25]=Skytree;
    Plateau[26]=PalaisimperialdeKyoto;
    Plateau[27]=PalaisimperialdeTokyo;
    Plateau[28]=Communaute2;
    Plateau[29]=Impot2;
    Plateau[30]=ArcdeTriomphe;
    Plateau[31]=TourEiffel;
}

int menu(joueur tab[4]){
        int choix, nbjoueurs;
        char action = 0, continuer = 0;
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
        printf("          1-%c Nouvelle Partie---------------%c\n          2-%c Sauvegarder la partie---------%c\n          3-%c Charger une ancienne partie---%c\n          4-%c Afficher les regles-----------%c\n          5-%c Afficher les createurs du jeu-%c\n          6-%c Quitter-----------------------%c\n", 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11);
        printf("\nChoix-%c ", 0x10);
        scanf("%d", &choix);

        while (choix>6 || choix<1){
            printf("Votre choix n est pas valide, veuillez selectionner de nouveau votre choix :\n   %c Nouvelle Partie\n   %c Sauvergarder la partie\n   %c Charger autre partie\n   %c Afficher les regles\n   %c Afficher les createurs du jeu\n   %c Quitter\n", 0x10, 0x10, 0x10, 0x10, 0x10, 0x10);
            fflush(stdin);
            scanf("%d", &choix);
        }

        switch (choix){
            case 1: //cas de nouvelle partie ou on demande le nombre de joueurs et on rempli le tableau de joueurs
                printf("La nouvelle partie va commencer...\n");
                printf("Appuyer sur entree pour continuer : ");
                fflush(stdin);
                scanf("%c", &action);
                consoleencouleur(15, 0);
                gotoligcol(0,0);
                printf("Selectionner le nombre de joueurs (compris entre 2 et 4) : ");
                fflush(stdin);
                scanf("%d", &nbjoueurs);
                while (nbjoueurs<2 || nbjoueurs>4){
                    printf("Selectionner le nombre de joueurs (compris entre 2 et 4) : ");
                    fflush(stdin);
                    scanf("%d", &nbjoueurs);
                }
                config_joueur(tab, nbjoueurs);
                printf("Vos informations ont etes enregistrees, vous avez ete place sur la case depart. Appuyer sur entree pour continuer\n");
                fflush(stdin);
                scanf("%c", &continuer);
                return nbjoueurs;
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
                consoleencouleur(15,8);
                gotoligcol(5,0);
                printf("Les createurs du jeu sont :\n  %c Robin Balosso\n  %c Vinciane De Parcevaux\n  %c Julie Allier\n  %c Sixtine Gouesse\n", 0x1A, 0x1A, 0x1A, 0x1A);
                break;
            case 6:
                printf("Au revoir");
                break;
        }
}

void consoleencouleur(int couleurtexte, int couleurfond){
    int i=0, j=0;
    for (j=0; j<150; j++){
        for (i=0; i<70; i++){
            Color(couleurtexte, couleurfond);
            gotoligcol(i, j);
            printf(" ");
        }
    }
}
