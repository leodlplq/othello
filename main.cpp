#include "game.h"




int main(){
    Joueur joueur1, joueur2;
    char vainqueur[20];
    Jeu *jeu = new Jeu;
    bool running = true;
    int i = 0;
    bool player = false; //false is player1 & true is player2
    int** coordsDispo1 = 0;
    int** coordsDispo2 = 0;
    

    //bool gamePlaying = true; //defini si le jeu est toujours en cours ou non. 
    
    initPlateau(jeu);

    createPlayer(&joueur1 ,1);
    jeu->joueur1 = joueur1;
    createPlayer(&joueur2, 2);
    jeu->joueur2 = joueur2;
    
    

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
        coordsDispo1 = giveCoordDispo(jeu, &joueur2);
        coordsDispo2 = giveCoordDispo(jeu, &joueur1);
        
        if(player && coordsDispo1[0][0] != -1){
            cout << "\nC'est au tour de "<< joueur2.name << ":" << joueur2.color <<endl;
            
            tourDunJoueur(jeu, &joueur2, &joueur1);
            renderGrid(jeu, rows, cols);

            
            player = !player;
        } else if(!player && coordsDispo2[0][0] != -1) {
            cout << "\nC'est au tour de "<< joueur1.name << ":" << joueur1.color <<endl;
            tourDunJoueur(jeu, &joueur1, &joueur2);
            renderGrid(jeu, rows, cols);
            player = !player;
        }else{
            player = !player;
        }
        

        i++;
        if(gameFinished(jeu, &joueur1, &joueur2) || (coordsDispo1[0][0] == -1 && coordsDispo2[0][0] == -1)){
            cout << "C'est la fin de la partie !" <<endl;
            if(joueur1.nbJetons > joueur2.nbJetons){
                memcpy(vainqueur, joueur1.name, strlen(joueur1.name));
                cout << "Félicitation " << vainqueur << "vous avez gagné le partie " << joueur1.nbJetons << " jetons contre " << joueur2.nbJetons << " jetons." << endl;
            }else if(joueur1.nbJetons == joueur2.nbJetons){
                cout << "Il n'y a pas de vainqueur ! Egalité." << endl;
            }else{
                memcpy(vainqueur, joueur2.name, strlen(joueur2.name));
                cout << "Félicitation " << vainqueur << "vous avez gagné le partie " << joueur2.nbJetons << " jetons contre " << joueur1.nbJetons << " jetons." << endl;
            }
             
            
            running=false;
        }

        
    }
    for (int j = 0; j < 64; j++){
                delete[] coordsDispo1[j];  
                delete[] coordsDispo2[j]; 
        }
        delete[] coordsDispo1;
        delete[] coordsDispo2;



    
    
    
    


    
    
    


    
    return 0;
}
