//
//  main.cpp
//  FattorialeRicorsivo
//
//  Created by Andrea on 25/10/2018.
//  Copyright © 2018 Andrea. All rights reserved.
//

#include <iostream>

/* File: fattoriale.c */
/* Funzione ricorsiva che calcola il fattoriale di un numero >= 0
 Si ricorda che il fattoriale n! e' definito come:
 
 n! = 1         se n = 0
 n! = n*(n-1)!  se n > 0
 
 */
/* Esempio di funzione ricorsiva */

#include <stdio.h>

using namespace std;

int fattoriale(int n)
{
    if (n < 0) return -1; /* Fattoriale non e' definito per interi negativi! */
    
    if (n == 0) return 1;
    else return n*fattoriale(n-1);
}

int main(void)
{
    long long int n;
    cout << ("Inserire un intero >= 0 : ");
    cin >>  n;
    cout << "Il fattoriale di " << n << " è: " << fattoriale(n) << endl;
    return 0;
}

/*
 Nota: il fattoriale di un numero cresce molto velocemente. Per calcolare il
 fattoriale di numeri grandi, abbiamo usato long long che ci dovrebbe garatire almeno 8 bytes (64 bit)
 */
