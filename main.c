#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"
#include "windows.h"
//test2

 //nous permettra de mettre en place une interface graphique si on a le temps

joueur* playerList = NULL;

const int role_count = voleur - villageois;


void print_player(joueur player){
    printf("%d \n",player.role);
    printf("%d \n",player.pouv);
    printf("%d\n",player.status);
}

int randomize(int randRange){
    return (int)rand()%randRange;
}

int *distribution_role(joueur* pList, int pNum, int maxLoup){
    //SI IL Y'A MOINS DE 12 JOUEURS, AJOUTER 2 LOUP GAROUS SINON 3 LOUP GAROUS

    int deck[] = {villageois,villageois,villageois,villageois,villageois,villageois,villageois,villageois,villageois,villageois,villageois,villageois,villageois
    ,cupidon, sorciere,chasseur,fille,voleur};
    int checkTab[] = {0,0,0,0,0,0,0,0};
    static int carteVoleur[2];

    srand(time(NULL));

    do{
        int joueurAlea = randomize(pNum);
        if(pList[joueurAlea].role != loup && pList[joueurAlea].role != voyante){
            pList[joueurAlea].role = loup;
            checkTab[1] = checkTab[1]+1;
        }
        /*On va générer aléatoirement un nombre qui correspondera a l'index d'un joueur de la liste
        Et on attribue le role VOYANTE uniquement si ce joueur n'est pas loup  et si il n'est pas voyante(par mesure de securite)*/
    }while(checkTab[1] < maxLoup);
    
    do{
        int joueurAlea = randomize(pNum);
        if(pList[joueurAlea].role != loup && pList[joueurAlea].role != voyante){
            pList[joueurAlea].role = voyante;
            checkTab[2] = checkTab[2]+1;
        }
        /*On va générer aléatoirement un nombre qui correspondera a  l'index d'un joueur de la liste
        Et on attribue le role VOYANTE uniquement si ce joueur n'est pas loup  et si il n'est pas voyante(par mesure de securite)*/
    }while(checkTab[2] < 1);

    
    int k = 0;

    if(checkTab[2]>=1 && checkTab[1]>= maxLoup){
        for(int i=0; i<pNum +2;i++){
            if(pList[i].role !=loup && pList[i].role != voyante && i < pNum){
                int roleAlea = randomize(17-k);
                pList[i].role = deck[roleAlea];
                deck[roleAlea] = deck[17-k];
                k++;
            }
            else if (i >= pNum)
            {
                
                int roleAlea = randomize(17-k);
                carteVoleur[i] = deck[roleAlea];
                deck[roleAlea] = deck[17-k];
                k++;
            }
        }
    }


    return carteVoleur;//Retourne un tableau contenant les cartes pour le voleur
////////////AJOUT DE 2 CARTE ALEA QUE LE VOLEUR POURRA VOLER
}  

int main(int argc, char **argv){

    int nombreJoueur=0, maxLoup = 0, premierTour = 0, tour1 = 1, resultat = 0;
    int *carteVoleur;
 //   joueur* playerList = NULL;

    
 //////////////////////////INITIALISATION DE LA PARTIE/////////////////////////////

    do{
        printf("Veuillez entrer le nombre de joueurs : ");
        scanf("%d", &nombreJoueur);
    }while(nombreJoueur< 8 || nombreJoueur > 18);

    //CHAQUE JOUEUR ENTRE SON NOM
    system("cls");

    

    //Le nombre max de loup par partie
    
    if(nombreJoueur < 12){
        maxLoup = 2; 
    }else{
        maxLoup = 3; 
    }

    playerList = malloc(nombreJoueur * sizeof(joueur));    
    
    for(int i=0; i<nombreJoueur;i++){
        playerList[i].status = alive;
    }

    carteVoleur = malloc(2 * sizeof(int));    
    
    carteVoleur = distribution_role(playerList, nombreJoueur, maxLoup);

    for(int i=0; i<nombreJoueur;i++){
        
        printf("Joueur %d, voici votre role : ", i);
        role_printf(playerList, i);
        printf("Rentrez votre pseudo : ");
        scanf("%s", playerList[i].pseudo);
        system("cls");
    }

/*    printf("Carte voleur : \n");

    for(int i=0;i<2;i++){
        printf("%d \n", carteVoleur[i]);
    }

    printf("Joueurs :\n");

    for(int i=0; i<nombreJoueur;i++){
        print_player(playerList[i]);
        printf("Suivant :\n");
    }*/
    initialisation(playerList, nombreJoueur);

    

    printf("LA PARTIE PEUT ALORS COMMENCER ! LE VILLAGE S'ENDORT.....\n");

    Sleep(3);
    system("cls");



/////////////////////////////PARTIE//////////////////////////////////
    if(premierTour == 0){
        
        for (int i = 0; i < nombreJoueur; ++i)
        {
            if (playerList[i].role == voleur)
            {
                printf("Le voleur se reveille.....\n");
                Voleur(carteVoleur, playerList, i);
                printf("Le voleur peut se rendormir.....\n");
                Sleep(3);
                system("cls");
            }
        }

        for (int i = 0; i < nombreJoueur; ++i)
        {
            if (playerList[i].role == cupidon)
            {
                printf("Cupidon se reveille.....\n");
                Cupidon(playerList, nombreJoueur);
                //AFFICHE LES AMOUREUX
                Sleep(3);
                system("cls");
            }
        }
        premierTour = 1;
    }

    do{

        for (int i = 0; i < nombreJoueur; ++i)
        {
            if (playerList[i].role == voyante && playerList[i].status == 0) 
            {
                printf("La voyante se reveille et souhaite prendre connaissance du role d'un joueur.....\n");
                Voyant(playerList, nombreJoueur);
                printf("La voyante peut se rendormir.....\n");
                Sleep(3);
                system("cls");
            }
        }

        for (int i = 0; i < nombreJoueur; ++i)
        {
            if (playerList[i].role == loup && playerList[i].status == 0) 
            {
                printf("Les loups garous se reveillent. Rassemblez vous et tuez quelqu'un\n");
                Loupgarou(playerList, nombreJoueur, 0);
                printf("Les loups garous peuvent se rendormir.....\n");
                Sleep(3);
                system("cls");
                break;
            }
        }

        for (int i = 0; i < nombreJoueur; ++i)
        {
            if (playerList[i].role == sorciere && playerList[i].status == 0) 
            {
                printf("La sorciere se reveille.\n");
                Sorciere(playerList, nombreJoueur, tour1);
                Sleep(3);
                system("cls");
            }
        }
        printf("Le village se reveille.\n");
        Tour(playerList, nombreJoueur, tour1);
        resultat = fin(playerList, nombreJoueur);
        if (resultat != 0)
        {
            break;
        }
        if (tour1 == 1)
        {
            Capitaine(playerList, nombreJoueur, 0);
        }
        printf("Nous allons proceder aux votes afin d'eliminer un potentiel loup-garou; \n");
        Vote(playerList, nombreJoueur, 0);
        //VERIFIER SI IL Y A UNE VICTOIRE (LOUP OU VILLAGEOIS), SI C'EST LE CAS , QUITTER LA BOUCLE
        printf("Le village peut se rendormir.....\n");
        Sleep(3);
        system("cls");
        tour1++;

    }while(resultat == 0);//AUCUN CAMP N'A GAGNE   

    switch(resultat){
        case 1 :
            printf("Les loup-garous remportent la partie !!\n");
            break;
        default :
            printf("Felicitation, les villageois remportent la partie !!\n");
            break;
    }
    


    free(playerList);
    

    return 0;
}


