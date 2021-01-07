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
            coordInt[1] = 1;
            break;
        case 'B' : 
            coordInt[1] = 2;
            break;
        case 'C' : 
            coordInt[1] = 3;
            break;
        case 'D' : 
            coordInt[1] = 4;
            break;
        case 'E' : 
            coordInt[1] = 5;
            break;
        case 'F' : 
            coordInt[1] = 6;
            break;
        case 'G' : 
            coordInt[1] = 7;
            break;
        case 'H' : 
            coordInt[1] = 8;
            break;

    }

    coordInt[0] = (int) coord[1] - 48;

    return coordInt;
    
}
void poseUnJeton(int coordonate[2], char grille[][9], Joueur *joueur){
    if(grille[coordonate[0]][coordonate[1]] == ' '){
        //c'est ok la case est libre
        grille[coordonate[0]][coordonate[1]] = joueur->color;
    } else {
        //va falloir redemander de jouer.
    }
}  