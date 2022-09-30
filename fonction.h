#ifndef FONCTION_H
#define FONCTION_H

enum role {
    villageois,
    loup,
    voyante,
    cupidon,
    sorciere,
    chasseur,
    fille,
    voleur
};


enum status{
    alive,
    dead
};

//On représente les joueurs par leur role, entier de 0 à 7 grace au enum, idem pour le status : en vie=0 mort = 1, pouv est le nombre de pouvoir qu'il 
//reste, à voir pour améliorer
struct joueur
{
    int role;
    int pouv;
    int status;
    int numero;
    int NombreVote; // comme on ne peut pas initialiser dans une structure, j'ai creer la fonction initialiser qui s'en chargera au début de l'éxecution
    int Amour; //prend la valeur 1 quand le joueur est amoureux
    int ValeurVote; // 2 pour le capitaine, 1 pour les autres
    int tour;
    char pseudo[20]; //pseudo de 20 caracteres max
};
typedef struct joueur joueur;

void Voleur(int carteVoleur[],joueur playerList[],int voleur);
int fin(joueur listejoueur[], int nbjoueur);
void Voyant(joueur listejoueur[], int nbjoueur);
void Vote(joueur listejoueur[], int nbjoueur, int nbvote);
void Tour(joueur listejoueur[], int nbjoueur, int tour1);
void Sorciere(joueur listejoueur[], int nbjoueur, int tour1);
void role_printf(joueur listejoueur[], int x);
void Loupgarou(joueur listejoueur[], int nbjoueur, int nbvote);
void Cupidon(joueur listejoueur[], int nbjoueur);
void Chasseur(joueur listejoueur[], int nbjoueur);
void Capitaine (joueur listejoueur[], int nbjoueur, int nbvote);
void Amour(joueur listejoueur[], int nbjoueur);
void initialisation(joueur listejoueur[], int nbjoueur);


#endif