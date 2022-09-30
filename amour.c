#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"


void Amour(joueur listejoueur[], int nbjoueur)
{
    int i;
    int j;
        for (i = 0; i < nbjoueur ; i++)
        {
            if (listejoueur[i].status == 1 && listejoueur[i].Amour == 1) //cherche un joueur mort ET faisant partie du couple
            {
                for (j = 0; j < nbjoueur ; j++)
                {
                    if (listejoueur[j].status == 0 && listejoueur[j].Amour == 1)
                    {
                        listejoueur[j].status = 1;
                    }
					//si un joueur faisant partie du couple est mort, on cherche le 2eme et on le tue
                }
            }
        }
}