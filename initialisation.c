#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"
//#include "role_printf.h"


void initialisation(joueur listejoueur[], int nbjoueur){
    int i;

    for (i = 0; i < nbjoueur; i++)
    {
        listejoueur[i].Amour = 0;
        listejoueur[i].NombreVote = 0;
        listejoueur[i].tour = 1;
        listejoueur[i].ValeurVote = 1;
    }
    
}