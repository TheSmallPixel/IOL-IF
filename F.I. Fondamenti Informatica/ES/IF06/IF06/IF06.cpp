// IF06.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>
using namespace std;
#define DIM 11
int main()
{
	cout << "Dammi " << DIM << "numeri!" << endl;
	int array[DIM];
	for (int i = 0; i < DIM; i++) {
		cin >> array[i];
	}
	int min = 0, max = 0,i = 0;
	for (i = 0; i < DIM; i++) {
		min = 0, max = 0;
		for (int ii = 0; ii < DIM; ii++) {
			if (ii != i) {
				if (array[ii] < array[i]) {
					min++;
				}
				else {
					max++;
				}
			}
		}
		if (min == max)
			break;
	}
	cout << endl << "La mediana dell'insieme di " << DIM
		<< " numeri e' " << array[i] << endl << endl;
}

// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln
