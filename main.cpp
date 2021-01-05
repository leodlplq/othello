#include "grille.h"

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
    // renderGrid(*grid, rows, cols);
    renderGrid((char *)grid, rows, cols);
    return 0;
}
