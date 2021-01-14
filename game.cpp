#include "game.h"
#include <cctype>


int *demandeUnePosition(){
    char coord[2];
    int *coordInt = new int[2];

    cout << "Ou voulez vous jouer ? exemple d'écriture : A1"<< endl;
    cin >> coord;
    cout << "-----------" << endl;
    cout << coord[0] << coord[1] << endl;
    cout << "to upper return " <<(char)toupper(coord[0]) << endl;
    switch(toupper(coord[0])){
        case 'A' :
            coordInt[1] = 0;
            break;
        case 'B' : 
            coordInt[1] = 1;
            break;
        case 'C' : 
            coordInt[1] = 2;
            break;
        case 'D' : 
            coordInt[1] = 3;
            break;
        case 'E' : 
            coordInt[1] = 4;
            break;
        case 'F' : 
            coordInt[1] = 5;
            break;
        case 'G' : 
            coordInt[1] = 6;
            break;
        case 'H' : 
            coordInt[1] = 7;
            break;

    }

    coordInt[0] = (int) coord[1] - 49;

    return coordInt;
    
}
void poseUnJeton(int coordonate[2], Jeu *jeu, Joueur *joueur){
    if(jeu->grille[coordonate[0]][coordonate[1]] == NULL){ // ajouter les autres conditions
        //c'est ok la case est libre
        Jeton *jetonToAdd = new Jeton;
        jetonToAdd->color = joueur->color;
        jetonToAdd->coordonate[2] = coordonate;
        jeu->grille[coordonate[0]][coordonate[1]] = jetonToAdd;
        
    } else {
        //va falloir redemander de jouer.
    }
}  