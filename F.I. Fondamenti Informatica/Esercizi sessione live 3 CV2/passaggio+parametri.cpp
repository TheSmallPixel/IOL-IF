//
//  main.cpp
//  passaggioParametri
//
//  Created by Maristella on 26/10/17.
//  Copyright © 2017 Andrea. All rights reserved.

// PASSAGGIO PER INDIRIZZO
//

/*
#include <iostream>
using namespace std;

// Definizione del prototipo
int moltiplica(int* x, int* y);

int main()
{
    int a = 5;
    int b = 6;
    int risultato;
    cout <<"Benvenuti" << endl;
    
    cout << "Il risultato contiene: "<< risultato <<endl;
    cout << "PUNTATORE a = "<< &a <<endl;
    
    risultato = moltiplica(&a, &b);
    cout << "Il risultato della moltiplicazione è: "<< risultato <<endl;
    cout << "PUNTATORE = "<< &a <<endl;
    
    
    return 0;
}

// Dichiarazione della funzione
int moltiplica(int *x, int *y)
{
    int ris;
    
    cout << "PUNTATORE &x = "<< &x <<endl;
    cout << "contenuto *x = "<< *x <<endl;
    // effettua la moltiplicazione tra i valori che si
    // trovano leggendo il contenuto della memoria
    // agli indirizzi x e y, tramite il prefisso '*'
    // (da non confondere con l'operatore di moltiplicazione)
    ris = *x * *y;
    
    // Valore restituito dalla funzione.
    return ris;
}
*/
 #include <iostream>
 using namespace std;
 // PASSAGGIO PER REFERENZA
 // Definizione del prototipo
 int moltiplica(int &x, int &y);
 
 
 int main()
 {
 int a = 5;
 int b = 6;
 int risultato;
 
 risultato = moltiplica(a, b);
 cout << "Il risultato della moltiplicazione è:" << risultato <<endl;
 
 cout << "PUNTATORE = "<< &a <<endl;
 return 0;
 }
 
 
 // Dichiarazione della funzione
 int moltiplica(int &x, int &y)
 {
 int ris;
 
 // moltiplica ciò che trova presso gli indirizzi di memoria di x e y
 // ma non c'è bisogno di esplicitarlo
 ris = x * y;
     
 cout << "PUNTATORE nella funzione = "<< &x <<endl;
 
 // Valore restituito dalla funzione
 return ris;
 }
