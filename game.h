#ifndef GAME
#define GAME

#include <iostream>
#include "cstring"
using namespace std;



//ABOUT THE JETON
struct Jeton{
    char color;
    int *coordonate[2];
    Jeton *next;
};
void addCoordonate(Jeton **jeton, int coordonate[2], char color);
Jeton *find_last(Jeton *jeton);
void afficheJeton(Jeton jeton);
int countJeton(Jeton *jeton);

//ABOUT THE PLAYER
struct Joueur{
    char name[20];
    Jeton jetonJoueur;
    int nbJetons;
    char color;
};
void createPlayer(Joueur *joueur, int n);

//ABOUT THE GAME
struct Jeu{
    Joueur joueur1;
    Joueur joueur2;
    Jeton* grille[8][8] = {
        {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}
    };
};

void poseUnJeton(int coordonate[2], Jeu *jeu, Joueur *joueur);
int *demandeUnePosition();

//ABOUT THE GRID
void renderGrid(Jeu *jeu, int m, int n);







#endif