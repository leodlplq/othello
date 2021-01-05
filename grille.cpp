//c++ file to create the grid.
#include "grille.h"

void renderGrid(char *grid, int m, int n){

    for(int i=0; i < m;i++){
            
            for(int j=0; j < n;j++){
                cout <<" "<<*((grid+i*n) + j) ;
                if(i == 0){
                    cout << "  ";
                }
                else{
                    cout << " |";
                }
            }  

            cout << endl;
            cout << "   " << "+---+---+---+---+---+---+---+---+" << endl;
        }

}