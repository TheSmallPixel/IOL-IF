/* Programma che calcola la mediana di n numeri interi, 
eventualmente non distinti, con n dispari */

#include <iostream>
using namespace std;

const int DIM = 11;   //dimensione del vettore

int main()
{
	int insieme[DIM]; // insieme dei numeri: vettore di DIM elementi
	int i,j;          // variabili per la scansione del vettore
	int minori;       // variabile per il conteggio di quanti numeri
						// sono minori
	int maggiori;     // variabile per il conteggio di quanti numeri
						// sono maggiori

	// dialogo con l'utente
	cout << endl << "Programma che calcola la mediana di " << DIM
		<< " numeri." << endl << endl;

	//Lettura dell'insieme di numeri
	for (i = 0; i < DIM; i++)
	{
		cout << "Inserisci il dato n. " << i + 1 << " ";
		cin >> insieme[i];
	}

	//Elaborazione dell'insieme di numeri
	i = 0;   /* si considera un elemento alla volta a partire dal
				numero contenuto in posizione 0 */
	do
	{
		/* Conteggio di quanti elementi dell'insieme sono minori e
		maggiori di insieme[i] */

		minori = maggiori = 0;

		j = 0;
		while ((j<DIM) && !((minori > (DIM - 1)/2) || (maggiori > (DIM-1)/2)))
		{
			if (insieme[i] > insieme[j])
			{
				minori++;
			}
			else if (insieme[i] < insieme[j])
			{
				maggiori++;
			}
			j++;
		}

		i++;  /* incremento dell'indice per passare al numero
				successivo */

	} while ((i<DIM) && !((minori <= (DIM - 1)/2) && (maggiori <= (DIM-1)/2)));

	//Stampa del risultato
	cout << endl << "La mediana dell'insieme di " << DIM
		<< " numeri e' " << insieme[i-1] << endl << endl;

	return 0;
} 
