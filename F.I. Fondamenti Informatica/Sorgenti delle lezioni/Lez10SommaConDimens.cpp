/* Programma che calcola la somma di una successione di
 * interi di cui si conosce la cardinalità.
 */
#include <iostream>
using namespace std;

void main()
{  
	int quanti, dimensione;		 	  //Positive o nulle
	int somma, addendo;

	//Acquisisci la dimensione dei dati
	cout << "dimensione della successione di interi da sommare: ";
	cin >> dimensione;
	//Acquisisci i dati, mantenendo con continuità la somma di
	//tutti quelli già acquisiti
	somma = 0;
	quanti = 0;
	while (quanti < dimensione)
	{ //acquisisci il prossimo addendo
		cout << "addendo: ";
		cin >> addendo;
		//aggiorna somma
		somma += addendo;
		quanti++;
	}
	//Stampa il risultato
	cout << "La somma dei " << quanti << " interi letti "
		<< "vale " << somma << endl;
}

