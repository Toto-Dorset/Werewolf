#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"


//quand on appelle la fonction "loupgarou" dans le main, il faudra donner la valeur 0 à l'entier "nbvote" à renseigner en 3eme position dans l'appel de la fonction

void Loupgarou(joueur listejoueur[], int nbjoueur, int nbvote)
{
	int i;
	int vote;
	int maxVote = 0;
	int JoueurVote = 0;
	int nbMax = 0;

	nbvote++;
	printf("Vous allez devoir voter pour le joueur que vous souhaitez eliminer. \nVoici la liste des joueurs encore en vie : \n");
	for (i = 0; i < nbjoueur ; i++)
    {
        if (listejoueur[i].status == 0 && listejoueur[i].role != 1)
        {
            printf("Joueur %d; ", i);
			
        }
	}
	printf("\n");
	for ( i = 0; i < nbjoueur; i++)
    {
        if (listejoueur[i].status == 0 && listejoueur[i].role == 1)
		{
            printf("A toi joueur %d, contre qui votes-tu ?\n", i);
            scanf("%d", &vote);
            listejoueur[vote].NombreVote++;
        }
    }

    for (i = 0; i < nbjoueur; i++)
	{ 
        if (listejoueur[i].status == 0 && listejoueur[i].NombreVote == maxVote && listejoueur[i].role != 1)
		{
            nbMax++;
        }

        else if (listejoueur[i].status == 0 && listejoueur[i].NombreVote > maxVote && listejoueur[i].role != 1)
		{
            maxVote = listejoueur[i].NombreVote;
            JoueurVote = i;
            nbMax = 0;
        }
    }

    if (nbMax != 0 && nbvote <2) //si il y a une egalite, les joueurs revotent une fois
	{
        printf("Attention, veuillez-vous mettre d'accord. A la prochaine egalite, aucun joueur ne sera elimine.\n");
        for (int i = 0; i < nbjoueur; i++)
        {
            listejoueur[i].NombreVote = 0;
        }
        Loupgarou(listejoueur, nbjoueur, nbvote);
    }
	else if (nbMax != 0 && nbvote >= 2) //apres la 2eme egalite, les joueurs ne revotent plus et aucun joueur n'est elimine.
	{
		printf("Vous n'avez pas reussi a vous decider, il y a une deuxieme egalite, aucun joueur ne sera donc tue. \n");
        for (int i = 0; i < nbjoueur; i++)
        {
            listejoueur[i].NombreVote = 0;
        }
	}
    else
	{
        printf("Le joueur %d a recu %d vote(s). Il est donc elimine. \n", JoueurVote, maxVote);
        listejoueur[JoueurVote].status = 1;
    }
    for (int i = 0; i < nbjoueur; i++)
    {
            listejoueur[i].NombreVote = 0;
    }
	
}