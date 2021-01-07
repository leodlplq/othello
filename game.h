#ifndef GAME
#define GAME

#include <iostream>
#include "cstring"
using namespace std;

//ABOUT THE GRID
void renderGrid(char *grid, int m, int n);

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

//ABOUT THE PLAYER
struct Joueur{
    char name[20];
    Jeton jetonJoueur;
    int nbJetons;
};
void createPlayer(Joueur *joueur, int n);

//ABOUT THE GAME
struct Jeu{
    Joueur joueur1;
    Joueur joueur2;
    Jeton allJeton;
};







#endif