#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"

void Cupidon(joueur listejoueur[], int nbjoueur)
{
    int i;
    int amoureux1;
    int amoureux2;

    printf("\nVoici la liste des joueurs : \n");
        for (i = 0; i < nbjoueur ; i++)
        {
            if (listejoueur[i].status == 0 && listejoueur[i].role != 3)
            {
                printf("%s(%d); ",listejoueur[i].pseudo, i);
            }
        }
    printf("\nIndiquez le numero du 1er joueur qui composera le couple :\n");
    scanf("%d", &amoureux1);
    listejoueur[amoureux1].Amour = 1;
    printf("Indiquez le numero du 2eme joueur qui composera le couple :\n");
    scanf("%d", &amoureux2);
    listejoueur[amoureux2].Amour = 1;
	//cupidon doit rentrer les numeros des 2 joueurs qu'il met en couple et on inidque donc au programme qu'ils le sont
    printf("Cupidon peut se rendormir.....\n");
    printf("Les amoureux se reveillent, se reconnaissent et s'endorment.\n");
}