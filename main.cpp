#include "game.h"

const int rows = 9, cols = 9;
char grid[rows][cols] = {
    {' ','A','B','C','D','E','F','G','H'},
    {'1',' ',' ',' ',' ',' ',' ',' ',' '},
    {'2',' ',' ',' ',' ',' ',' ',' ',' '},
    {'3',' ',' ',' ',' ',' ',' ',' ',' '},
    {'4',' ',' ',' ','x','o',' ',' ',' '},
    {'5',' ',' ',' ','o','x',' ',' ',' '},
    {'6',' ',' ',' ',' ',' ',' ',' ',' '},
    {'7',' ',' ',' ',' ',' ',' ',' ',' '},
    {'8',' ',' ',' ',' ',' ',' ',' ',' '}   
};


int main(){
    Joueur joueur1, joueur2;

    createPlayer(&joueur1 ,1);
    createPlayer(&joueur2, 2);

    cout << joueur1.name <<endl;
    cout << joueur2.name << endl;

    afficheJeton(joueur1.jetonJoueur);
    afficheJeton(joueur2.jetonJoueur);
    


    renderGrid((char *)grid, rows, cols);
    return 0;
}
