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
    Jeton *AllJeton = new Jeton;

    //bool gamePlaying = true; //defini si le jeu est toujours en cours ou non. 
    
    

    createPlayer(&joueur1 ,1);
    createPlayer(&joueur2, 2);
    initAllJeton(AllJeton);
    int nbJetons1 = countJeton(&joueur1.jetonJoueur);
    int nbJetons2 = countJeton(&joueur2.jetonJoueur);
    cout << joueur1.name << " a : " << nbJetons1 <<endl;
    cout << joueur2.name << " a : " << nbJetons2 << endl;

    

    afficheJeton(*AllJeton);
    renderGrid(grid, rows, cols);

    int *coordGet = demandeUnePosition();
    poseUnJeton(coordGet, grid, &joueur1);
    renderGrid(grid, rows, cols);
    delete coordGet;

    int *coordGet2 = demandeUnePosition();
    poseUnJeton(coordGet2, grid, &joueur2);
    renderGrid(grid, rows, cols);
    delete coordGet2;

    int *coordGet3 = demandeUnePosition();
    poseUnJeton(coordGet3, grid, &joueur1);
    renderGrid(grid, rows, cols);
    delete coordGet3;

    
    
    
    


    
    
    


    
    return 0;
}
