//  Copyright © 2018 Andrea. All rights reserved.
//

// #include <stdio.h>
#include <iostream>
#include <iomanip>

int const dim = 20;

using namespace std;

void inizializza(int A[][dim]);
void disponi(int A[][dim]);          /* non utilizzata */
void CorniceO(int i, int A[][dim]);  /* cornice Orizzontale  */
void CorniceV(int j, int A[][dim]);  /* cornice Verticale    */
void visualizza(int A[][dim]);

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << ("Stampa Cornice\n");
    int Cornice[dim][dim];
    inizializza(Cornice);
    visualizza(Cornice);
    disponi(Cornice);
    visualizza(Cornice);
    return 0;
}

void inizializza(int A[][dim]){
    int i, j;
    for (i =0; i<dim; i++) {
        for (j =0; j<dim; j++) {
            A[i][j] = 0;
        }
    }
    return;
}

void disponi(int A[][dim]){
    int i, j;
    for (i =0; i<dim; i++) {
        CorniceO(i, A);
    }
    for (j =0; j<dim; j++) {
        CorniceV(j, A);
    }
    return;
}
void visualizza(int A[][dim]){
    int i, j;
    for (i =0; i<dim; i++) {
        for (j =0; j<dim; j++) {
            
            cout << setw(3) <<  A[i][j];
        }
        printf("\n");
    }
    return;
}
void CorniceO(int i, int A[][dim]){
    int k, ma;
    ma = (int)(dim/2);
    if (i< ma){
        for (k=i; k <(dim-i); k++){
            A[i][k] = i+1;
        }
    }
    if (i >= ma){
        for(k = (dim-i-1); k<=i; k++){
            A[i][k] = dim-i;
        }
    }
    return;
}

void CorniceV(int j, int A[][dim]){
    int k, ma;
    ma = (int)(dim/2);
    if (j<ma){
        for (k=j; k <(dim-j); k++){
            A[k][j] = j+1;
        }
    } else {
        for(k=  dim-j-1; k<=j; k++){
            A[k][j] = dim-j;
        }
    }
    
    return;
}