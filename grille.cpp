//c++ file to create the grid.
#include "game.h"

void renderGrid(Jeu *jeu, int m, int n){
    cout << "   " << "  A   B   C   D   E   F   G   H  " << endl;
    cout << "   " << "+---+---+---+---+---+---+---+---+" << endl;
    for(int i=0; i < m;i++){
            cout <<" "<< i+1 << " |";
            for(int j=0; j < n;j++){
                
                if(jeu->grille[i][j] != NULL){
                    cout <<" "<< jeu->grille[i][j]->color;
                    
                } else {
                    cout << "  ";
                }
                
                
                cout << " |";
                
            }  

            cout << endl;
            cout << "   " << "+---+---+---+---+---+---+---+---+" << endl;
    }

}