#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"


void role_printf(joueur listejoueur[], int x){

    switch (listejoueur[x].role)
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
}