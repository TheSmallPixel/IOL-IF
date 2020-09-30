//
//  main.cpp
//  ordina vettore caratteri
//
//  Created by Andrea on 08/08/18.
//  Copyright © 2018 Andrea. All rights reserved.
//

#include <iostream>

//#define dim1 10
//const int dim2 = 60;
int  dim = 60;

using namespace std;

void carica(char stringa[]);
void ordina (char stringa[]);
void stampa (char stringa[]);

int main(int argc, const char * argv[]) {
    cout << "lunghezza stringa = " ;
    cin >> dim;
    char stringa[dim];
    carica(stringa);
    stampa(stringa);
    ordina(stringa);
    stampa(stringa);
    return 0;
}

void carica(char stringa[]){
    int num, i;
    srand((int)time(NULL));
    for (i=0; i<dim; i++){
        num = rand()%26+65;  /* trova un numero tra 65 e 90. I numeri tra 65 e 90                                    rappresentano le 26 lettere maiuscole dell'alfabeto inglese */
        stringa[i] = (char)num;  // converte il numero in lettera: forzo il casting
    }
    return;
}

/* Ordiniamo utilizzando bubble sort   */
void ordina (char stringa[]){
    int i, j, post_it;
    for(i=0; i<dim; i++){
        for(j=0; j<(dim-(i+1)); j++){
            if (stringa[j+1] < stringa[j]){
                post_it = stringa[j];
                stringa[j] = stringa[j+1];
                stringa[j+1] = post_it;
            }
        }
    }
    return;
}
void stampa (char stringa[]){
    int i;
    for (i=0; i<dim; i++){
        cout << stringa[i];
    }
    cout << endl;
    return;
}
