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
