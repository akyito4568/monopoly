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
    int couleur;
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

void config_joueur(joueur a[4],int nbJoueurs)
{
    int i=0,choix=0, choix2=0;
    char tab[]= {0x03,0x04,0x05,0x06};
    int couleurjoueur[]= {1, 2, 3, 4};
    for(i=0; i<nbJoueurs; i++)
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
        }while ((tab[choix-1]=='b')||(choix<1)||(choix>4));
        printf("\nVotre signe est le : %c\n",a[i].signe);
        a[i].indice = i;
        printf("Vous etes le joueur numero %d\n", i);
        fflush(stdin);
        printf("\nChoisissez votre couleur \n1.Bleu \n2.Vert \n3.Turquoise \n4.Rouge  \n");
        do
        {
            scanf("%d",&choix2);
            a[i].couleur=couleurjoueur[choix2-1];
            if (couleurjoueur[choix2-1]!='b' && (choix2>0) &&(choix2<5) )
            {
                couleurjoueur[choix2-1]='b';
                break;
            }
            printf("Veuillez saisir une couleur valable, soit un chiffre entre 1 et 4 : ");
        }while ((couleurjoueur[choix2-1]=='b')||(choix2<1)||(choix2>4));
        printf("\nVotre couleur est la numero %d", a[i].couleur);
        fflush(stdin);
        printf("\nChoisir un nom (20 caractere max ) :");
        fflush(stdin);
        gets(a[i].nom);
    }
}

void ordrepassagejoueurs(int nbjoueurs, joueur tab[4], joueur tabapres[4]){
    srand(time(NULL));
    int tirage=0, i=0;
    char action=0;
    tirage = rand()%((nbjoueurs-1) - 0 + 1)+0;
    if(nbjoueurs==2){ //cas avec deux joueurs
        if(tirage==0){ //ordre inchangé
            tabapres[0]=tab[0];
            tabapres[1]=tab[1];
            printf("L ordre est le suivant : %s, %s", tabapres[0].nom, tabapres[1].nom);
        }
        if(tirage==1){ //le deuxième joueur commence
            tabapres[0]=tab[1];
            tabapres[1]=tab[0];
            printf("L ordre est le suivant : %s, %s", tabapres[0].nom, tabapres[1].nom);
        }
    }
    if(nbjoueurs==3){ //cas avec trois joueurs
        if(tirage==0){ //ordre inchangé
            for(i=0; i<3; i++){
                tabapres[i]=tab[i];
            }
            printf("L ordre est le suivant : %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom);
        }
        if(tirage==1){ // le deuxième joueur commence, l'ordre suit
            tabapres[0]=tab[1];
            tabapres[1]=tab[2];
            tabapres[2]=tab[0];
            printf("L ordre est le suivant : %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom);
        }
        if(tirage==2){ //le troisième joueur commence, l'ordre suit
            tabapres[0]=tab[2];
            tabapres[1]=tab[0];
            tabapres[2]=tab[1];
            printf("L ordre est le suivant : %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom);
        }
    }
    if(nbjoueurs==4){//cas avec quatre joueurs
        if(tirage==0){//ordre inchangé
            for(i=0; i<4; i++){
                tabapres[i]=tab[i];
            }
            printf("L ordre est le suivant : %s, %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom, tabapres[3].nom);
        }
        if(tirage==1){ //le deuxième joueur commence
            tabapres[0]=tab[1];
            tabapres[1]=tab[2];
            tabapres[2]=tab[3];
            tabapres[3]=tab[0];
            printf("L ordre est le suivant : %s, %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom, tabapres[3].nom);
        }
        if(tirage==2){
            tabapres[0]=tab[2];
            tabapres[1]=tab[3];
            tabapres[2]=tab[0];
            tabapres[3]=tab[1];
            printf("L ordre est le suivant : %s, %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom, tabapres[3].nom);
        }
        if(tirage==3){
            tabapres[0]=tab[3];
            tabapres[1]=tab[0];
            tabapres[2]=tab[1];
            tabapres[3]=tab[2];
            printf("L ordre est le suivant : %s, %s, %s, %s", tabapres[0].nom, tabapres[1].nom, tabapres[2].nom, tabapres[3].nom);
        }
    }
    printf("\nAppuyer sur entree pour continuer");
    fflush(stdin);
    scanf("%c", &action);
    consoleencouleur(15,0);
}



void deplacement_pion(int nombre_joueur,t_propriete tab_p[32],joueur tab_j[4]){
        for (int i=0;i<nombre_joueur;i++){
            gotoligcol((tab_p[tab_j[i].position].y),(tab_p[tab_j[i].position].x-i));
            printf("%c",tab_j[i].signe);
        }
}
void clearScreen(){
    system("cls");
    }

void LanceDe(int * de1,int * de2){
        int BorneInf = 1;
        int BorneSup = 6;
        *de1 = rand()%(BorneSup - BorneInf + 1) + BorneInf;
        *de2 = rand()%(BorneSup - BorneInf + 1) + BorneInf;
}

int doubles(int * a){
    int de1,de2;
    LanceDe(&de1,&de2);
    if (de1==de2){
        *a=*a+de1+de2;
        return 1;}

    else{
        *a=*a+de1+de2;
        return 0;}
}

void afficher_donnee_joueur_encours(joueur tab[4], int indice){
    gotoligcol(15, 85);
    printf("Le joueur qui joue est %s", tab[indice].nom);
    gotoligcol(16, 85);
    printf("Vos informations :");
    gotoligcol(17, 87);
    printf("Couleur : numero %d (1.Bleu 2.Vert 3.Turquoise 4.Rouge)", tab[indice].couleur);
    gotoligcol(18, 87);
    printf("Symbole : %c", tab[indice].signe);
    gotoligcol(19,87);
    printf("Argent : %d", tab[indice].argent);
    gotoligcol(20,87);
    printf("Case : %d", (tab[indice].position)+1);
}

void lancedefinal(joueur tableau[4], t_propriete tab[32], int indice, int* compteursortie, int* validationprison){
    int somme=0, sommeaffichee=0;
    int compteur=0;
    int test;
    srand(time(NULL));
    if (tableau[indice].position==8 && *compteursortie<3 && *validationprison==1){
        test=doubles(&somme);
        if(test==1){
            gotoligcol(10, 85);
            printf("Vous etes libere de prison, vous avez fait un double");
            tableau[indice].position = ((tableau[indice].position)+somme)%32;
            *compteursortie=0;
            *validationprison=0;
        }
        if (test==0 && *compteursortie<3){
            gotoligcol(10, 85);
            printf("Dommage, vous restez en prison, reessayer de sortir au prochain tour !");
            compteursortie++;
        }
        if(test==0 && *compteursortie==3){
            gotoligcol(10, 85);
            printf("Vous etes en prison depuis trois tours, vous etes libere");
            tableau[indice].position = ((tableau[indice].position)+somme)%32;
            *compteursortie = 0;
            *validationprison=0;
        }
    }
    else{
        do{
            test=doubles(&somme);
            gotoligcol(47, 0);
            printf("test :%i",test);
            printf("\nsomme:%i",somme);
            compteur++;
            if (compteur==3){
                tableau[indice].position=8;
                gotoligcol(7, 85);
                printf("Mince ! Vous avez fait trois doubles, vous allez en prison...");
                *validationprison=1;
                break;}

            tableau[indice].position= ((tableau[indice].position)+somme)%32;

            if(tableau[indice].position == 24){
                gotoligcol(7, 85);
                printf("Mince ! Vous avez ete arrete par un agent de police... Direction la prison.");
                tableau[indice].position = 8;
                *validationprison = 1;
                break;
            }

            gotoligcol(4, 85);
            printf("Vous avez lance les des %d fois.", compteur);
            gotoligcol(5, 85);
            printf("Vous avez fait %d doubles.", compteur-1);
            gotoligcol(6, 85);
            sommeaffichee = sommeaffichee + somme;
            printf("Vous avancez de %d cases.", sommeaffichee);
            somme=0;
            }
        while(test);
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

void affichagepropriete(t_propriete Plateau[32], joueur tab[4], int indice)
{
    int choixcase=tab[indice].position;
    gotoligcol(8, 15);
    //case qui ne sont pas des monuments
    if(choixcase==0||choixcase==3||choixcase==4||choixcase==8||choixcase==12||choixcase==16||choixcase==20||choixcase==24||choixcase==28||choixcase==29)
    {
        gotoligcol(9,15);
        printf("%s",Plateau[choixcase].nom);
    }
    else
    {
        gotoligcol(10,15);
        printf("Pays: %s", Plateau[choixcase].nomgroupe);
        gotoligcol(11,15);
        printf("Monument: %s", Plateau[choixcase].nom);
        gotoligcol(12,15);
        printf("Prix: %d", Plateau[choixcase].prix);
        gotoligcol(13,15);
        printf("Proprietaire: %c", Plateau[choixcase].biens);
        gotoligcol(14,15);
        printf("Loyer: %d", Plateau[choixcase].loyer);
        gotoligcol(15,15);
        printf("Maison: %d", Plateau[choixcase].maison);
        gotoligcol(16,15);
        printf("Hotel: %d", Plateau[choixcase].hotel);
        gotoligcol(17,15);
        printf("Hypotheque: %d", Plateau[choixcase].hypotheque);
    }
}

void remplissagetableau(t_propriete Plateau[32])
{
    /***********Initialisation des cases du plateau***********/
    t_propriete Debut ={1,0,"Evenement","Debut",0,'0',0,0,0,0,8,5};        ///place,groupe,nom,prix,biens(dans le sens qui est le proprietere),loyer,maison,hotel,hypotheque,x,y
    t_propriete PlaceRouge ={2,1,"Russie","Place Rouge",60,'0',0,0,0,30,16,5};
    t_propriete Bolchoi ={3,1,"Russie","Bolchoï",60,'0',0,0,0,30,24,5};
    t_propriete Impot1={4,0,"Evenement","Impot 1",0,'0',0,0,0,0,32,5};
    t_propriete Chance1 ={5,0,"Evenement","Chance 1",0,'0',0,0,0,0,40,5};
    t_propriete OperaSydney ={6,2,"Australie","Opera Sydney",60,'0',0,0,0,30,48,5};
    t_propriete BarrieredeCorail ={7,2,"Australie","Barriere de Corail",60,'0',0,0,0,30,56,5};
    t_propriete PalaisRoyaldesExpositions ={8,2,"Australie","Palais Royal des Expositions",60,'0',0,0,0,30,64,5};
    t_propriete Prison={9,0,"Evenement","Prison",0,'0',0,0,0,0,72,5};
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

void menu(joueur tab[4], t_propriete Plateau[32], int *nbjoueurs, int* choix, joueur tabordre[4]){
        int n=0, m=0;
        char action = 0, continuer = 0, action2 = 0, action3=0;
        char nomsauv[10];
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
            case 1: //cas de nouvelle partie ou on demande le nombre de joueurs et on rempli le tableau de joueurs
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
                config_joueur(tab, *nbjoueurs);
                printf("Vos informations ont etes enregistrees, vous avez ete place sur la case depart. Appuyer sur entree pour continuer\n");
                fflush(stdin);
                scanf("%c", &continuer);
                consoleencouleur(15,0);
                gotoligcol(0,0);
                printf("L ordre de passage a ete determiner, il restera le meme tout au long de la partie !\n");
                ordrepassagejoueurs(*nbjoueurs, tab, tabordre);
                break;
            case 2:
                printf("Saisir un nom a donner a cette sauvegarde (10 caracteres maximum): ");
                fflush(stdin);
                gets(nomsauv);
                optionsauvegarde(tab, Plateau, &nbjoueurs, nomsauv);
                printf("Votre partie a ete sauvegardee, appuyer sur entree pour continuer\n");
                break;
            case 3:
                printf("Une autre partie est en cours de telechargement\n");
                break;
            case 4:
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


                fflush(stdin);
                gotoligcol(38, 0);
                printf("Appuyer sur entree pour revenir au menu...");
                scanf("%c", &action2);
                break;
            case 5:
                consoleencouleur(15,8);
                gotoligcol(5,0);
                printf("Les createurs du jeu sont :\n  %c Robin Balosso\n  %c Vinciane De Parcevaux\n  %c Julie Allier\n  %c Sixtine Gouesse\n", 0x1A, 0x1A, 0x1A, 0x1A);
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
void optionsauvegarde(joueur tab[4], t_propriete Plateau[32], int nbjoueurs, char nomsauvegarde[10]){
    int i=0, j=0;
    FILE* sauvegarde=NULL;
    sauvegarde = fopen("sauvegarde.txt", "w");
    if (sauvegarde == NULL){
        printf("Le fichier est introuvable, la suavegarde ne peut pas etre effectuee");
    }
    fprintf(sauvegarde, "%s\n", nomsauvegarde);
    for (i=0; i<nbjoueurs; i++){
        fprintf(sauvegarde, "%s", tab[i].nom);
        fprintf(sauvegarde, "%d", tab[i].argent);
        fprintf(sauvegarde, "%c", tab[i].signe);
        fprintf(sauvegarde, "%d", tab[i].nombre_propri);
        fprintf(sauvegarde, "%d", tab[i].position);
        fprintf(sauvegarde, "%d", tab[i].pos_cord.x);
        fprintf(sauvegarde, "%d\n\n", tab[i].pos_cord.y);
    }
    for (j=0; j<32; j++){
        fprintf(sauvegarde,"\n\n\n%d", Plateau[j].place);
        fprintf(sauvegarde,"%d", Plateau[j].groupe);
        fprintf(sauvegarde,"%c", Plateau[j].nomgroupe[30]);
        fprintf(sauvegarde,"%c", Plateau[j].nom[30]);
        fprintf(sauvegarde,"%d", Plateau[j].prix);
        fprintf(sauvegarde,"%d", Plateau[j].biens);
        fprintf(sauvegarde,"%d", Plateau[j].loyer);
        fprintf(sauvegarde,"%d", Plateau[j].maison);
        fprintf(sauvegarde,"%d", Plateau[j].hotel);
        fprintf(sauvegarde,"%d", Plateau[j].hypotheque);
        fprintf(sauvegarde,"%d", Plateau[j].x);
        fprintf(sauvegarde,"%d\n\n", Plateau[j].y);
    }
    fclose(sauvegarde);
}
