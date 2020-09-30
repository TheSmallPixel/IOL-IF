//
//  main.cpp
//  puntatori
//
// 
//  Copyright © 2018 Andrea. All rights reserved.
//

#include <iostream>

struct Data
{ int giorno,
    mese,
    anno;
};
const int MAXIDENT = 10;
const int DIM = 10;

struct Studente
{ int matricola;
    char cognome[MAXIDENT],
    nome[MAXIDENT],
    sesso;
    Data dataNascita;
};

struct Nodo
{ Studente datiStud;
    Nodo *nextPtr;
};

struct InsStudente
{ int num;
    Studente elenco[DIM];
};
Nodo *inizializzaTabella();
void inserisciSeNonEsiste(Studente, InsStudente &);
void eliminaSeEsiste(int, InsStudente &);
void cercaSeEsisteEPosizione(int, InsStudente &,
                             int &, int &);
void provaParametri(int &a, int *b, int *&c);
void stampaTabella(InsStudente &);

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Nodo *classe = NULL;
 //   Nodo classe2 = NULL;
    Nodo classe3;
    Studente Andrea;
    
    int a = 1;
    int *p = &a;  // si legge: "assegna a p l'indirizzo di a"
    int b = *p;   // si legge: "assegna a b il valore puntato da p"
    
    cout << "a: " << a << endl;         // 1
    cout << "b: " << b << endl;         // 1
    cout << "*p: " << *p << endl;       // 1
    cout << "a: " << &a << endl;        // indirizzo di a es: 0x7ffeefbff4b4
    
    cout << "p = " << p << endl;        // indirizzo di a es: 0x7ffeefbff4b4
    cout << "*p = " << *p << endl;      // 1 il contenuto puntato da p
    cout << "*&p = " << *&p << endl;    // indirizzo di p es: 0x7ffeefbff4b4
    cout << "&*p = " << &*p << endl;    // indirizzo di p es: 0x7ffeefbff4b4
    cout << "__________________________________________" << endl;
    cout << "__________________________________________" << endl;
    
    
    provaParametri(*p, &*p, *&p);     // la prima variabile (puntatore p) è passata per indirizzo, le                        altre per valore; si noti che la seconda contiene l'indirizzo del puntatore
    
    cout << "p after provaParametri ="  << p << endl;
    
    
    return 0;
}

void provaParametri(int &a, int *b, int *&c ){
    cout << "a = " << a << endl;             // 1 contenuto do p
    cout << "&a = " << &a << endl;
    cout << "*&a = " << *&a << endl;
    cout << "__________________________________________" << endl;
    
    cout << "b = " << b << endl;
    cout << "&b = " << &b << endl;
    cout << "*&b = " << *&b << endl;
    cout << "&*b = " << &*b << endl;
    cout << "__________________________________________" << endl;
    
    cout << "c = " << c << endl;
    cout << "&c = " << &c << endl;
    cout << "*&c = " << *&c << endl;
    cout << "&*c = " << &*c << endl;
    cout << "__________________________________________" << endl;
    cout << "__________________________________________" << endl;
    cout << "__________________________________________" << endl;
    
    int *z=NULL;
    a++;
   // a = *z;
    cout << "a ="  << a << endl;
    
}

