
/* Programma che calcola l'elevamento a potenza di una base
 * intera ad un esponente intero.
 * Viene considerato anche il caso di 0 elevato a 0.
 */
#include <iostream>
using namespace std;

void main()
{
	int esponente;
	int base, potenza;                // potenza rappresenta anche i valori parziali
	int segno = 1;                    // tiene conto del segno dell'esponente
	int prodMancanti;                 // positiva o nulla

	                                  // presenta le funzionalità del programma
	cout << "Calcolo dell'elevamento a potenza di una base intera " << endl
		<< "a un esponente intero " << endl;
	                                  // leggi base ed esponente
	cout << "Inserisci la base e l'esponente: ";
	cin >> base >> esponente;
	if (base == 0 && esponente == 0)  // potenza non definita? Segnala con messaggio
		cout << "L'elevamento a potenza di 0 a 0 non e' definito";
	else                              // potenza definita, calcola
	{
		if (esponente < 0)               // esponente negativo?
		{
			segno = -1;                   // ricordati il segno
			esponente = - esponente;      // rendi positivo esponente
		}
		potenza = 1;                     // = base elevata all'esponente 0
		for (prodMancanti = esponente;   // ciclo a conteggio il cui corpo,
			prodMancanti > 0;           // eseguito esponente volte,
			prodMancanti--)             // aggiorna potenza,
			potenza *= base;                 // moltiplicandola per base
		cout << "L'elevamento a potenza di " << base << " per "
			<< segno * esponente << " vale ";
		if (segno == 1)                  // esponente positivo?
			cout << potenza << endl;         // stampa il valore di potenza
		else                             // esponente negativo?
			cout << 1 / float(potenza) << endl;  // stampa il reciproco di potenza
	}
}


