#ifndef GAME
#define GAME

#include <iostream>
#include "cstring"
using namespace std;

//ABOUT THE GRID
void renderGrid(char grid[][9], int m, int n);

//ABOUT THE JETON
struct Jeton{
    char color;
    int coordonate[2];
    Jeton *next;
};
void addCoordonate(Jeton **jeton, int coordonate[2], char color);
Jeton *find_last(Jeton *jeton);
void afficheJeton(Jeton jeton);
void initAllJeton(Jeton *AllJeton);
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
    Jeton allJeton;
};

void poseUnJeton(int coordonate[2], char grille[][9], Joueur *joueur);
int *demandeUnePosition();







#endif