#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"

void Tour(joueur listejoueur[], int nbjoueur, int tour1)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int nvCapitaine;

	for (i = 0; i < nbjoueur ; i++)
	{
		if (listejoueur[i].status == 1 && listejoueur[i].tour == tour1 && listejoueur[i].role != 5)
//cherche les joueurs qui sont morts ET qui sont alle jusqu'au tour de la nuit derniere (pour savoir si ils sont morts la nuit derniere) ET qui ne sont pas chasseurs.
		{
			printf("Le joueur %d est mort cette nuit. Son role etait : \n",i);
			role_printf(listejoueur, i);
		}
		if (listejoueur[i].status == 1 && listejoueur[i].tour == tour1 && listejoueur[i].role == 5)
//cherche si un joueur mort la nuit derniere est le chasseur, si oui on lance la fonction chasseur qui permet au chasseur de tuer une derniere personne de son choix.
		{
			printf("Le joueur %d est mort cette nuit. Son role etait : \n Chasseur \n" , i);
			Chasseur(listejoueur, nbjoueur);
		}
	}
	i = 0;
	for (i = 0; i < nbjoueur ; i++)
	{
		if (listejoueur[i].status == 1 && listejoueur[i].tour == tour1 && listejoueur[i].Amour == 1)
//cherche si un joueur mort la nuit derniere etait en couple. Si oui, il regarde si le 2eme membre du couple est vivant. Si il est vivant, on le tue, si il est mort c'est qu'il a ete tue pendant la nuit aussi donc pas besoin de le tuer.
		{
			for (j = 0; j < nbjoueur ; j++)
			{
				if (listejoueur[j].status == 1 && listejoueur[j].Amour == 1 && j != i)
				{
				printf("Le joueur %d et le joueur %d etaient en couple. \n Cependant ils sont deja tous les deux morts cette nuit. \n", i, j);
				}
				if (listejoueur[j].status == 0 && listejoueur[j].Amour == 1)
				{
				printf("Le joueur %d, qui est mort, etait en couple avec le joueur %d. \nLes deux rejoignent donc le monde des morts ensemble." , i , j);
				Amour(listejoueur, nbjoueur);
				break;
				}
				
			}
		}
	}
	i = 0;
	for (i = 0; i < nbjoueur; i++)
	{
		if (listejoueur[i].ValeurVote == 2 && listejoueur[i].status == 1 && listejoueur[i].tour == tour1)
		{
			printf("Le capitaine est mort cette nuit, il doit designer son successeur :\n");
			printf("Voici la liste des joueurs encore en vie; qui choississez vous en temps que nouveau capitaine ?\n"); 
			for (k = 0; k < nbjoueur; k++)
			{
				if (listejoueur[k].status == 0)
				{
					printf("Joueur %d; ", k);
				}
			}
			scanf("\n%d", &nvCapitaine);
			listejoueur[nvCapitaine].ValeurVote = 2;
			break;
		}
	}

	i = 0;
	for (i = 0; i < nbjoueur ; i++)
// on ajoute 1 a l'entier "tour" dans la structure des joueurs encore en vie pour indiquer qu'ils survivent pendant au moins un tour de plus.
	{
		if (listejoueur[i].status == 0)
		{
			listejoueur[i].tour++ ;
		}
	}
}