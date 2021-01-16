#include "game.h"




int main(){
    Joueur joueur1, joueur2;
    Jeu *jeu = new Jeu;
    bool running = true;
    int i = 0;
    bool player = false; //false is player1 & true is player2
    

    //bool gamePlaying = true; //defini si le jeu est toujours en cours ou non. 
    
    

    createPlayer(&joueur1 ,1);
    jeu->joueur1 = joueur1;
    createPlayer(&joueur2, 2);
    jeu->joueur2 = joueur2;
    
    int nbJetons1 = countJeton(&joueur1.jetonJoueur);
    int nbJetons2 = countJeton(&joueur2.jetonJoueur);
    cout << joueur1.name << " a : " << nbJetons1 <<endl;
    cout << joueur2.name << " a : " << nbJetons2 << endl;

    int init[2] = {3,3};
    int init2[2] = {3,4};
    int init3[2] = {4,3};
    int init4[2] = {4,4};
    poseUnJetonInit(init, jeu, &joueur1);
    poseUnJetonInit(init4, jeu, &joueur1);
    poseUnJetonInit(init2, jeu, &joueur2);
    poseUnJetonInit(init3, jeu, &joueur2);

    
    renderGrid(jeu, rows, cols);

    while(running){
        if(player){
            cout << "\nC'est au tour de "<< joueur2.name <<endl;
            int *coordGet = demandeUnePosition();
            poseUnJeton(coordGet, jeu, &joueur2);
            renderGrid(jeu, rows, cols);
            delete coordGet;
            player = !player;
        } else {
            cout << "\nC'est au tour de "<< joueur1.name <<endl;
            int *coordGet = demandeUnePosition();
            poseUnJeton(coordGet, jeu, &joueur1);
            renderGrid(jeu, rows, cols);
            delete coordGet;
            player = !player;
        }
        

        i++;
        if(i==5){
            running=false;
        }
    }
    

    int *coordGet2 = demandeUnePosition();
    poseUnJeton(coordGet2,jeu, &joueur2);
    renderGrid(jeu, rows, cols);
    delete coordGet2;

    int *coordGet3 = demandeUnePosition();
    poseUnJeton(coordGet3, jeu, &joueur1);
    renderGrid(jeu, rows, cols);
    delete coordGet3;
    delete jeu;

    
    
    
    


    
    
    


    
    return 0;
}
