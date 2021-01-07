//C++ file about the player.
#include "game.h"

void createPlayer(Joueur *joueur, int n){

    char name[20]; 
    Jeton *jetonJoueur = new Jeton;
    int nbJetons = 2;  

    if(n == 1){
        joueur->color = 'x';
        int array[2] = {4,4};
        int array2[2] = {5,5};
        jetonJoueur->color = 'x';
        jetonJoueur->coordonate[0] = array[0];
        jetonJoueur->coordonate[1] = array[1];
        jetonJoueur->next = NULL;

        addCoordonate(&jetonJoueur, array2, 'x');
    }else{
        joueur->color = 'o';
        int array[2] = {4,5};
        int array2[2] = {5,4};
        jetonJoueur->color = 'o';
        jetonJoueur->coordonate[0] = array[0];
        jetonJoueur->coordonate[1] = array[1];
        jetonJoueur->next = NULL;
        
        addCoordonate(&jetonJoueur, array2, 'o');
    }

    cout << "Creation du joueur " << n << endl;
    cout << "Quel est votre nom ? " << endl;
    

    do{ //on recupere le nom du joueur.
        cout << "Mon nom est : ";
        cin >> name;
    }while((unsigned)strlen(name) > 20);

    strcpy(joueur->name, name);
    joueur->nbJetons = nbJetons;
    joueur->jetonJoueur = *jetonJoueur;



    if(n == 1){
        cout << "Ma couleur est 'x'" <<endl;
        cout << "\n" <<endl;
    }else{
        cout << "Ma couleur est 'o'" << endl;
        cout << "\n\n\n" << endl;
        cout << "Le jeu va commencer preparez vous !" <<endl;
    }

}