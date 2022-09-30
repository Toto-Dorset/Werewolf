#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"

void Chasseur(joueur listejoueur[], int nbjoueur)
{
int i;
int joueurChoisi;
int chass;

for (i = 0; i < nbjoueur; i++)
{
	if (listejoueur[i].role == 5)
	{
		chass = i;
	}
}


if (listejoueur[chass].status == 1)
	{
		printf("Cette nuit, vous avez ete designe pour mourir.\nVous allez devoir nous indiquez quel joueur vous souhaitez tuer dans votre dernier souffle.\nVoici la liste des joueurs encore en vie : \n");
		for (i = 0; i < nbjoueur ; i++)
        {
            if (listejoueur[i].status == 0 && listejoueur[i].role != 5)
            {
                printf("Joueur %d; ", i);
            }
		}
		printf("\nIndiquez le numero du joueur que vous souhaitez eliminer : \n");
		scanf("%d", &joueurChoisi);
		listejoueur[joueurChoisi].status = 1;
		printf("Vous bien avez elimine le joueur %d . \n", joueurChoisi);
	}
}
