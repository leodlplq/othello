//c++ file to create the grid.
#include "game.h"

void initPlateau(Jeu* jeu){
    for(int i=0; i < 8;i++){
        for(int j=0; j < 8;j++){
            Jeton* jeton = new Jeton;
            jeton->color = ' ';
            jeton->coordonate[0] = i;
            jeton->coordonate[1] = j;
            jeu->grille[i][j] = jeton;

        }
    }
}

void renderGrid(Jeu *jeu, int m, int n){
    cout << "   " << "  A   B   C   D   E   F   G   H  " << endl;
    cout << "   " << "+---+---+---+---+---+---+---+---+" << endl;
    for(int i=0; i < m;i++){
            cout <<" "<< i+1 << " |";
            for(int j=0; j < n;j++){
                cout <<" "<< jeu->grille[i][j]->color << " |";
                
            }  

            cout << endl;
            cout << "   " << "+---+---+---+---+---+---+---+---+" << endl;
    }

}