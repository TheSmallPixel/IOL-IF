//
//  main.cpp
//  vettoreAndreColo
//
//  Created by Maristella on 27/07/17.
//  Copyright © 2017 Andrea. All rights reserved.
//

#include <iostream>
#include <time.h>

const int dim = 5;

using namespace std;

int popola (int [] [dim]);
int stampa (int [] [dim]);
int minmax (int [] [dim]);

int main(int argc, const char * argv[]) {
    // insert code here...
    int vet [dim] [dim];
    cout << "Array\n";
    srand (time(NULL));  // Innesca la sequenza di numeri casuali
    popola (vet );
    stampa (vet );
    minmax (vet );       // Trovo il valore minimo ed il massimo all'interno del vettore
    return 0;
}


int popola (int a [] [dim]){
    int i, j;
    for (i = 0; i < dim ; i++) {
        for (j = 0; j < dim ; j++)
            a[i] [j] = rand()%20;  // mi da il resto della divisione: solo valori positivi
        
    }
    return 0;
}

int stampa (int a[] [dim]){
    int i, j, segno;
    for (i = 0; i < dim ; i++) {
        for (j = 0; j < dim ; j++) {
            segno = rand()%2;
            if (segno == 1) a[i] [j] = a[i] [j];       //rand()%20;
            if (segno == 0) a[i] [j] = (-1)*a[i] [j];  //rand()%20;
            cout << a[i] [j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int minmax (int a[] [dim]) {
    int i, j, min, max;
    min = a[0] [0];
    max = a[0] [0];
    for (i = 0; i < dim ; i++) {
        for (j = 0; j < dim ; j++) {
            if (a[i] [j] < min  ) min = a[i] [j];
            if (a[i] [j] > max  ) max = a[i] [j];
        }
  //      cout << endl;
    }
    cout << " minimo = "  << min << endl;
    cout << " massimo = " << max << endl;
    return 0;
}
