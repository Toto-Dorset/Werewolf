#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"



//quand on appelle la fonction "vote" dans le main, il faudra donner la valeur 0 à l'entier "nbvote" à renseigner en 3eme position dans l'appel de la fonction
void Vote(joueur listejoueur[], int nbjoueur, int nbvote)
{
    int i; 
    int vote;
    int maxVote = 0;
    int JoueurVote = 0; //correspond au joueur le plus voté
    int nbMax = 0; //si différent de max, il y a une égalité
	
	nbvote++;
    printf("Voici la liste des joueurs restants :\n");
    for (i = 0; i < nbjoueur; i++)
    {
        if (listejoueur[i].status == 0)
        {
            printf("Joueur %d; ", i);
        }
    }
    for ( i = 0; i < nbjoueur; i++)
    {
        if (listejoueur[i].status == 0)
		{
            printf("\nA toi joueur %d, contre qui votes-tu ?\n", i);
            scanf("%d", &vote);
            listejoueur[vote].NombreVote += listejoueur[i].ValeurVote;
        }
    }

    for (i = 0; i < nbjoueur; i++)
	{ 
        if (listejoueur[i].status == 0 && listejoueur[i].NombreVote == maxVote)
		{ // on vérifie encore si le joueur est bien vivant pour ne pas comptabiliser les votes des joueurs morts
		//(la valeur des votes des joueurs morts date en plus d'une ancienne phase de vote)
            nbMax++;
        }

        else if (listejoueur[i].status == 0 && listejoueur[i].NombreVote > maxVote)
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
        Vote(listejoueur, nbjoueur, nbvote);
    }
	else if (nbMax != 0 && nbvote >= 2) //apres la 2eme egalite, les joueurs ne revotent plus et aucun joueur n'est elimine.
	{
		printf("Vous n'avez pas reussi a vous decider, il y a une deuxieme egalite, aucun joueur ne sera donc tue. \n ");
        for (int i = 0; i < nbjoueur; i++)
        {
            listejoueur[i].NombreVote = 0;
        }
	}
    else
	{
        printf("Le joueur %d a recu %d vote(s). Il est donc elimine.", JoueurVote, maxVote);
        listejoueur[JoueurVote].status = 1;
        listejoueur[JoueurVote].tour-- ;
        printf("Son role etait :\n");
        role_printf(listejoueur, JoueurVote);
        for (int i = 0; i < nbjoueur; i++)
        {
            listejoueur[i].NombreVote = 0;
        }
    }
    
}