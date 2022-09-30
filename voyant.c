#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"
//#include "role_printf.h"


void Voyant(joueur listejoueur[], int nbjoueur){
    int JoueurObserv;
    int i;

    printf("Voici la liste des joueurs encore en vie : \n");
        for (i = 0; i < nbjoueur ; i++)
        {
            if (listejoueur[i].status == 0 && listejoueur[i].role != 2)
            {
                printf("%s(%d); ",listejoueur[i].pseudo, i);
            }
        }
    printf("\n");
    printf("Indiquer le numero du joueur dont vous souhaitez voir la carte : \n");
    scanf("%d", &JoueurObserv);
    printf("Voici le role du joueur selectionne : \n");
    role_printf(listejoueur, JoueurObserv);


}