/* Programma che calcola la somma di una successione di 
 * interi la cui cardinalit� non � nota a priori.
 * La successione viene terminata da uno speciale carattere che 
 * segnala la fine dei dati(Ctrl-z per Windows).
 */ 
#include <iostream>
using namespace std;

void main()
{
	int somma, addendo;

	//Acquisisci i dati, mantenendo con continuit� la somma di quelli   
	//gi� acquisiti
	somma = 0;
	while (1)
	{ //acquisisci il prossimo addendo
		cout << "addendo da sommare (Ctrl-z per terminare): ";
		cin >> addendo;
		if (cin.eof())
			break;
		//aggiorna somma
		somma += addendo;
	}
	cout << endl;
	//stampa il risultato
	cout << endl << "La somma della successione di interi vale: "
		<< somma << endl;
}

