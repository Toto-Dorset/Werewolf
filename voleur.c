#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"
//#include "role_printf.h"


void Voleur(int carteVoleur[],joueur playerList[],int voleur){
    int i;
    int choix;

    printf("Voici les cartes disponibles :\n");

    for (i = 0; i < 2; i++)
    {   printf("Carte %d : ", i+1);
        
        switch (carteVoleur[i])
    {
    case 1 :
        printf("Loup-Garou\n");
        break;
    case 2 :
        printf("Voyante\n");
        break;
    case 3 :
        printf("Cupidon\n");
        break;
    case 4 :
        printf("Sorciere\n");
        break;
    case 5 :
        printf("Chasseur\n");
        break;
    case 6 :
        printf("Petite fille\n");
        break;
    case 7 :
        printf("Voleur\n");
        break;
    
    default:
        printf("Villageois\n");
        break;
    }

        if (carteVoleur[i] == 1)
        {
            printf("Une carte de loup-garou est disponible. Elle vous est attribué.\n");
            playerList[voleur].role == voleur;
            exit(0);
        }
    }
    printf("Quelle carte choississez vous ?\n");
    scanf("%d", &choix);
    playerList[voleur].role = carteVoleur[choix-1];
    printf("Vous etes maintenant :\n");
    role_printf(playerList, voleur);


}