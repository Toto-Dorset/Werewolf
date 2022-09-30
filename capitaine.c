#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"


// !! IL FAUT AJOUTER UN ENTIER "ValeurVote" DANS LA STRUCTURE DES JOUEURS, ET L'INITIALISER A 1 POUR TOUS LES JOUEURS (au moment du vote du captaine, ValeurVote deviendra 2 pour le joueur élu) !!

//quand on appelle la fonction "capitaine" dans le main, il faudra donner la valeur 0 à l'entier "nbvote" à renseigner en 3eme position dans l'appel de la fonction
void Capitaine (joueur listejoueur[], int nbjoueur, int nbvote) //meme fonctionnement que la focntion vote, sauf qu'elle sert à élire le capitaine au lieu d'une personne à tuer
{
	int j;
	int i; 
	int vote;
	int maxVote = 0;
	int JoueurVote = 0;
	int nbMax = 0;
	
	nbvote++;
	printf("Vous devez elire un capitaine. \nReflechissez bien, le joueur que vous elirez verra son vote etre compte double lors des phases de vote. \nVoici la liste des joueurs encore en vie : \n");
	for (j = 0; j < nbjoueur ; j++)
    {
            if (listejoueur[j].status == 0)
            {
                printf("Joueur %d; ", j);
            }
    }
    printf("\n");
	for ( i = 0; i < nbjoueur; i++)
    {
        if (listejoueur[i].status == 0)
		{
            printf("A toi joueur %d, pour qui votes-tu ?\n", i);
            scanf("%d", &vote);
            listejoueur[vote].NombreVote++;
        }
    }

	for (i = 0; i < nbjoueur; i++)
	{
	    if (listejoueur[i].status == 0 && listejoueur[i].NombreVote == maxVote)
		{  
            nbMax++;
        }

        else if (listejoueur[i].status == 0 && listejoueur[i].NombreVote > maxVote)
		{
            maxVote = listejoueur[i].NombreVote;
            JoueurVote = i;
            nbMax = 0;
        }
    }

    if (nbMax != 0) //si il y a une egalite, les joueurs revotent une fois
	{
        for (int i = 0; i < nbjoueur; i++)
        {
            listejoueur[i].NombreVote = 0;
        }
        Capitaine(listejoueur, nbjoueur, nbvote);
    }
    else 
	{
        printf("Le joueur %d a recu %d vote(s). Il devient donc le nouveau capitaine. \n", JoueurVote, maxVote);
        listejoueur[JoueurVote].ValeurVote = 2;
    }
    for (int i = 0; i < nbjoueur; i++)
    {
            listejoueur[i].NombreVote = 0;
    }
}