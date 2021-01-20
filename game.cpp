#include "game.h"
#include <cctype>

bool gameFinished(Jeu* jeu, Joueur* joueur1, Joueur* joueur2 ){
    int totalPoint  = joueur1->nbJetons + joueur2->nbJetons;
    int finished = false;

    if(totalPoint == 64){
        finished =  true;
    }

    return finished;

}
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
    
    jeu->grille[coordonate[0]][coordonate[1]]->color = joueur->color;  
    
} 

void poseUnJeton(int coordonate[2], Jeu *jeu, Joueur *joueurPoseur, Joueur* joueurPris){

        jeu->grille[coordonate[0]][coordonate[1]]->color = joueurPoseur->color;        
        joueurPoseur->nbJetons += 1;
        captureJeton(coordonate, jeu, joueurPoseur, joueurPris);
        cout << "Bravo, " << joueurPoseur->name << " a maintenant " << joueurPoseur->nbJetons << "jetons !\n\n"<<endl;
    
}  

bool estCoupValide(int coord[2], Jeu* jeu, Joueur* joueur){
    return jeu->grille[coord[0]][coord[1]]->color == ' ' && isItCorrect(coord, jeu, joueur) && detecteCaptureJeton(coord, jeu, joueur);
}

void tourDunJoueur(Jeu* jeu, Joueur* joueurPoseur, Joueur* joueurPris){
    int* coords = 0;
    do{
        if(coords){
            delete[] coords;
        }
        coords = demandeUnePosition();
    } while(!estCoupValide(coords, jeu, joueurPoseur));
    poseUnJeton(coords, jeu, joueurPoseur, joueurPris);
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


void captureJeton(int coordonate[2], Jeu *jeu, Joueur *joueurPoseur, Joueur* joueurPris){
    char toDetect;
    int toMoveTo[8][2] = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},      {0,1}, 
        {1,-1},{1,0},{1,1} 
    };
    int allTakenPion[64][2];
    int takenPion[8][2];

    for(int i=0;i<64;i++){
        allTakenPion[i][0] = -1;
        allTakenPion[i][1] = -1;
    }
    int x,y;
    // int nbPrise = 0;
    int nbPriseTotal = 0;
    int count;
    int countAll=0;

    if(joueurPoseur->color == 'x'){
        toDetect = 'o';
    } else {
        toDetect = 'x';
    }

    for( int *ch : toMoveTo){
        
        for(int i=0;i<8;i++){
            takenPion[i][0] = -1;
            takenPion[i][1] = -1;
        }
        count = 0;
        x = coordonate[0] + ch[0]; 
        y = coordonate[1] + ch[1];
        

        if((x>=0 && x<=7) && (y>=0 && y<=7)){
            
            if(jeu->grille[x][y] != 0){
                while(jeu->grille[x][y]->color == toDetect && ((x>0 && x<7) && (y>0 && y<7))){
                    takenPion[count][0]=x;
                    takenPion[count][1]=y;
                    x = x + ch[0]; 
                    y = y + ch[1];
                    count +=1;
                };
            count = 0;
            //normalement x,y sont sur la case d'apres, donc 
            //je verifie si c'est 0/7/ou mon pion afin de valider la prise.
                if(x<0 || x>7 || y<0 || y>7){
                    //c'est sur les bords du tableau donc x/y n'existe pas dans le tableau.
                    //on valide la prise. pour faire ca, on push dans le allTaken et on push dans le nbPriseTotal.
                    
                    while(takenPion[count][0] != -1 && takenPion[count][1] != -1){
                        allTakenPion[nbPriseTotal][0] = takenPion[count][0];
                        allTakenPion[nbPriseTotal][1] = takenPion[count][1];
                        nbPriseTotal++;
                        count++;
                    }
                }else if(jeu->grille[x][y]->color == joueurPoseur->color){
                    //les jetons sont entre deux de mes jetons, donc ils sont mtn à moi. On peut valider.
                    while(takenPion[count][0] != -1 && takenPion[count][1] != -1){
                        allTakenPion[nbPriseTotal][0] = takenPion[count][0];
                        allTakenPion[nbPriseTotal][1] = takenPion[count][1];
                        nbPriseTotal++;
                        count++;
                    }
                }
            }
              
        }  
    }
    while(allTakenPion[countAll][0] != -1 && allTakenPion[countAll][1]){
        jeu->grille[allTakenPion[countAll][0]][allTakenPion[countAll][1]]->color = joueurPoseur->color;
        countAll++;
    }
    joueurPoseur->nbJetons += nbPriseTotal;
    joueurPris->nbJetons -= nbPriseTotal;
}

bool detecteCaptureJeton(int coordonate[2], Jeu *jeu, Joueur *joueur){
    char toDetect;
    int toMoveTo[8][2] = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},      {0,1}, 
        {1,-1},{1,0},{1,1} 
    };
    int takenPion[8][2];    
    int x,y;
    // int nbPrise = 0;
    int nbPriseTotal = 0;
    int count;
    if(joueur->color == 'x'){
        toDetect = 'o';
    } else {
        toDetect = 'x';
    }

    for( int *ch : toMoveTo){
        
        for(int i=0;i<8;i++){
            takenPion[i][0] = -1;
            takenPion[i][1] = -1;
        }
        count = 0;
        x = coordonate[0] + ch[0]; 
        y = coordonate[1] + ch[1];
        if((x>=0 && x<=7) && (y>=0 && y<=7)){
            
            if(jeu->grille[x][y] != 0){
                while(jeu->grille[x][y]->color == toDetect && ((x>0 && x<7) && (y>0 && y<7))){
                    takenPion[count][0]=x;
                    takenPion[count][1]=y;

                    x = x + ch[0]; 
                    y = y + ch[1];
                    count +=1;
                };

            count = 0;
            //normalement x,y sont sur la case d'apres, donc 
            //je verifie si c'est 0/7/ou mon pion afin de valider la prise.
                if(x<0 || x>7 || y<0 || y>7){
                    //c'est sur les bords du tableau donc x/y n'existe pas dans le tableau.
                    //on valide la prise. pour faire ca, on push dans le allTaken et on push dans le nbPriseTotal.
                    while(takenPion[count][0] != -1 && takenPion[count][1] != -1){
                        nbPriseTotal++;
                        count++;
                    }
                }else if(jeu->grille[x][y]->color == joueur->color){
                    //les jetons sont entre deux de mes jetons, donc ils sont mtn à moi. On peut valider.
                    while(takenPion[count][0] != -1 && takenPion[count][1] != -1){
                        nbPriseTotal++;
                        count++;
                    }
                }
         
            }
              
        }
        
        
    }
    
    if(nbPriseTotal != 0){
        return true;
    } else {
        return false;
    }
}