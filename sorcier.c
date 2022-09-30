#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"

int rea = 1;
int tuer = 1;

void Sorciere(joueur listejoueur[], int nbjoueur, int tour1){
    int i;
    int joueuraelim;
    int res;
    int JoueurMort;
    int kill;
    int pouv = 0;


    if (rea == 1)
    { //signigie qu'il lui reste son pouvoir de réanimation
        for (i = 0; i < nbjoueur; i++)
        {
            if (listejoueur[i].status == 1 && listejoueur[i].tour == tour1)
            {
                JoueurMort = i;
                printf("Le joueur %d vient d'etre elimine. Voulez-vous le sauver ? \n",JoueurMort);
                printf("1.Oui  2.Non \n");
                scanf("%d", &res);
            }
        }

            if (res == 1)
            {
                printf("Reanimation en cours...\n");
                listejoueur[JoueurMort].status = 0; //repasse le status du JoueurMort à 0 (en vie)
                rea--; //indique que son pouvoir de réanimation a été utilisé
                pouv++;
            }
            
    }
    if (tuer == 1 && pouv == 0)
    {
        printf("Voici la liste des joueurs encore en vie : \n");
        for (i = 0; i < nbjoueur ; i++)
        {
            if (listejoueur[i].status == 0 && listejoueur[i].role != 4)
            {
                printf("Joueur %d;  ", i);
            }
        }
            if (tuer == 1)
            { //signifie qu'il lui reste son pouvoir d'élimination
                printf("\nSouhaitez vous elimine un joueur ?\n");
                printf("1. Oui   2. Non\n");
                scanf("%d", &kill);
                if (kill == 1)
                {
                    printf("Rentrer le numero du joueur que vous souhaitez eliminer :\n");
                    scanf("%d", &joueuraelim);
                    listejoueur[joueuraelim].status = 1; //ou fonction tuer
                    tuer--; //indique que son pouvoir de kill a été utilisé
                }

            }

    
            
    }
}