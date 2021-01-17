#include "game.h"
#include <cctype>


int *demandeUnePosition(){
    
    char coord[2];
    char coordBuffer[100];
    bool verif = true;
    int *coordInt = new int[2];

    
    do{

        cout << "Ou voulez vous jouer ? exemple d'écriture : A1"<< endl;
        cin >> coordBuffer;
        if((unsigned)strlen(coordBuffer) == 2 && (((int)coordBuffer[0] >= 65 && (int)coordBuffer[0]<=71) || ((int)coordBuffer[0] >= 97 && (int)coordBuffer[0] <=104)) && ((int)coordBuffer[1] >= 49 && (int)coordBuffer[1] <= 57)) { 
                verif = false;
        }
            
    
    }while(verif);

    memcpy(coord, coordBuffer, 2);
    
   
    switch(toupper(coord[0])){
        case 'A' :
            coordInt[1] = 0;
            break;
        case 'B' : 
            coordInt[1] = 1;
            break;
        case 'C' : 
            coordInt[1] = 2;
            break;
        case 'D' : 
            coordInt[1] = 3;
            break;
        case 'E' : 
            coordInt[1] = 4;
            break;
        case 'F' : 
            coordInt[1] = 5;
            break;
        case 'G' : 
            coordInt[1] = 6;
            break;
        case 'H' : 
            coordInt[1] = 7;
            break;

    }

    coordInt[0] = (int) coord[1] - 49;

    return coordInt;
    
}

void poseUnJetonInit(int coordonate[2], Jeu *jeu, Joueur *joueur){
    if(jeu->grille[coordonate[0]][coordonate[1]] == NULL){
        //c'est ok la case est libre
        Jeton *jetonToAdd = new Jeton;
        jetonToAdd->color = joueur->color;
        jetonToAdd->coordonate[0] = coordonate[0];
        jetonToAdd->coordonate[1] = coordonate[1];
        jeu->grille[coordonate[0]][coordonate[1]] = jetonToAdd;
        
    }
} 

void poseUnJeton(int coordonate[2], Jeu *jeu, Joueur *joueur){
    if(jeu->grille[coordonate[0]][coordonate[1]] == 0){ // ajouter les autres conditions
        //c'est ok la case est libre
        Jeton *jetonToAdd = new Jeton;
        jetonToAdd->color = joueur->color;
        jetonToAdd->coordonate[0] = coordonate[0];
        jetonToAdd->coordonate[1] = coordonate[1];
        jeu->grille[coordonate[0]][coordonate[1]] = jetonToAdd;
        
    }
}  

bool estCoupValide(int coord[2], Jeu* jeu, Joueur* joueur){
    return jeu->grille[coord[0]][coord[1]] == 0 && isItCorrect(coord, jeu, joueur);
}

void tourDunJoueur(Jeu* jeu, Joueur* joueur){
    int* coords = 0;
    do{
        if(coords){
            delete[] coords;
        }
        coords = demandeUnePosition();
    } while(!estCoupValide(coords, jeu, joueur));
    poseUnJeton(coords, jeu, joueur);
    delete[] coords;
}

//VERIFICATION OF THE PLACEMENT

//is there an enemy on a close case ? 
//x x x if o = [x.y] others will be : 
//x o x [x-1.y-1], [x-1.y], [x-1.y+1]  
//x x x [x,y-1],   [x.y],   [x.y+1]
//      [x+1,y-1], [x+1.y],   [x+1,y+1] 


bool isItCorrect(int coordonate[2], Jeu *jeu, Joueur *joueur){
    bool correct = false;
    char toDetect;
    int toLookTo[8][2] = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},      {0,1}, 
        {1,-1},{1,0},{1,1} 
    };
    int x,y;

    if(joueur->color == 'x'){
        toDetect = 'o';
    } else {
        toDetect = 'x';
    }

    for( int *ch : toLookTo){
        x = coordonate[0] + ch[0]; 
        y = coordonate[1] + ch[1];

        if((x>=0 && x<=7) && (y>=0 && y<=7)){
            

            if(jeu->grille[x][y] != 0){ // 0 == NULL
                if(jeu->grille[x][y]->color == toDetect){
                    correct = true;
                }
            }
        }
        
        
    }

    return correct;
}