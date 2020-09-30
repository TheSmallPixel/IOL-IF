/* Programma che calcola la mediana di n numeri interi distinti, con n dispari */

#include <iostream>
using namespace std;

const int DIM = 11;   //dimensione del vettore

int main()
{
	int insieme[DIM];  // insieme dei numeri: vettore di DIM elementi
	int i,j;	     // variabili per la scansione del vettore
	int contatore;     // variabile per il conteggio di quanti numeri sono minori
  
	// dialogo con l'utente
	cout << endl << "Programma che calcola la mediana di " << DIM
		<< " numeri distinti." << endl << endl;

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
		/* Conteggio di quanti elementi dell'insieme sono minori di 
		insieme[i] */

		/* con l'indice i si indica il numero per il quale si
		verifica se le condizioni affinchè sia la mediana sono
		soddisfatte; per il conteggio viene utilizzata un'altra
		variabile (la variabile j) */

		contatore = 0;

		/* prima alternativa per il conteggio: ciclo FOR */

		/* for (j = 0; j < DIM; j++)
		{
			if (insieme[i] > insieme[j])
			{
				contatore++;
			}
		} */


		/* Seconda alternativa: utilizzo del ciclo while - soluzione 
		piu' efficiente */

		j = 0;
		while ((j<DIM) && (contatore <= (DIM - 1)/2))
		{
			if (insieme[i] > insieme[j])
			{
				contatore++;
			}
			j++;
		}

		i++;  /* incremento dell'indice per passare al numero
				successivo */

	} while ((contatore != ((DIM - 1)/2)) && (i<DIM));
	/*quando questa condizione e' soddisfatta significa che il
	numero in posizione i-1 e' la mediana */

	//Stampa del risultato
	cout << endl << "La mediana dell'insieme di " << DIM
       << " numeri e' " << insieme[i-1] << endl << endl;

	return 0;
}
