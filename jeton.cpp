#include "game.h"

void addCoordonate(Jeton **jeton, int coordonate[2], char color){
    Jeton *newJeton = new Jeton;
    if(newJeton==0){
        cout << "memory run out" << endl;
        exit(1);
    }
    newJeton->color = color;
    newJeton->coordonate[0] = coordonate[0];
    newJeton->coordonate[1] = coordonate[1];

    newJeton->next = NULL;
    
    find_last(*jeton)->next = newJeton;
}

Jeton *find_last(Jeton *jeton){
    while(jeton->next != NULL){
        jeton=jeton->next;
    }

    return jeton;
}

void afficheJeton(Jeton jeton){
    Jeton *current;
    current = &jeton;

    while(current != NULL){
        cout << current->color << " les coordonnées sont " << current->coordonate[0] <<":"<< current->coordonate[1]<<endl;
        current = current->next;
    }

}


void initAllJeton(Jeton *AllJeton){
    int array[2] = {5,5};
    int array2[2] = {4,5};
    int array3[2] = {5,4};

    AllJeton->color = 'x';
    AllJeton->coordonate[0] = 4;
    AllJeton->coordonate[1] = 4;
    AllJeton->next = NULL;

    addCoordonate(&AllJeton, array, 'x');
    addCoordonate(&AllJeton, array2, 'o');
    addCoordonate(&AllJeton, array3, 'o');
}