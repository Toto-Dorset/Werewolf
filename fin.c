#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"

int fin(joueur listejoueur[], int nbjoueur){
	int i, loup, villageois;

	i = loup = villageois = 0;


	for (i = 0; i < nbjoueur; i++)
	{
		if (listejoueur[i].status == 0 && listejoueur[i].role != 1)
		{
			villageois = 1;
		}
	}

	i = 0;
	for (i = 0; i < nbjoueur; i++)
	{
		if (listejoueur[i].status == 0 && listejoueur[i].role == 1)
		{
			loup = 1;
		}
	}

	if (villageois == 1 && loup == 1)
	{
		return 0;
	}
	if (villageois == 1 && loup == 0)
	{
		return 2;
	}
	if (villageois == 0 && loup == 1)
	{
		return 1;
	}
}