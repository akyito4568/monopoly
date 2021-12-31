#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"




void config_joueur(joueur a[4],int nbJoueurs)
{




    int i=0,choix=0;
    char tab[]= {0x03,0x04,0x05,0x06};
    for(i; i<nbJoueurs; i++)
    {
        a[i].argent=1500;
        a[i].position=0;
        a[i].nombre_propri=0;

        printf("\nChoisir signe \n1.%c \n2.%c \n3.%c \n4.%c  ",0x03,0x04,0x05,0x06);

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





        printf("\nVotre signe est le : %c",a[i].signe);
        fflush(stdin);


        printf("\nChoisir un nom (20 char max ) :");
        fgets(a[i].nom,MAX_LIMIT,stdin);















    }
}

void InitilisationPlateau(t_propriete Plateau[32])

{



    int j=0;

    int a=24;

    int z=32;

    int espace=0;

    int propriete=0;

    int taille=9;



    /********************Mise en forme plateau***********************/





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

        printf("\nPays: %s\nMonument: %s\nPrix: %d\nProprietere: %c\nLoyer: %d\nMaison: %d\n Hotel: %d\nHypotheque: %d",Plateau[choixcase].nomgroupe,Plateau[choixcase].nom,Plateau[choixcase].prix,Plateau[choixcase].biens,Plateau[choixcase].loyer,Plateau[choixcase].maison,Plateau[choixcase].hotel,Plateau[choixcase].hypotheque);

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



    /*******************Remplisage plateau***************/









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

void gotoligcol( int lig, int col ) {

// ressources

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

void lance_de_final(joueur * a, t_propriete tab[32]){
    int somme=0;
    int compteur=0;
    int test;
    srand(time(NULL));
    do{
        test=doubles(&somme);
        printf("\ntest :%i",test);
        printf("\nsomme:%i",somme);
        compteur++;
        if (compteur==3 && test==1){
            a->position=8;
            break;}
        a->position= (a->position+somme)%32;
        somme=0;
            }



    while(test);

    printf("\n nouvelle pos :%i",a->position);
    }



