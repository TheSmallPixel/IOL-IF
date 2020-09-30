/* Tentativo senza speranza di dimostrare la falsità dell'ultimo 
 * teorema di Fermat.
 * Versione con funzione ricorsiva.
 */
#include <iostream>
using namespace std;

int elevaAPotenza (int base, int esponente)     // versione ricorsiva
{ // versione per esponente positivo 
	if (esponente == 1)
		return base;                                                           
	if (esponente > 1)
		return base * elevaAPotenza(base, esponente - 1); 
}

void main() 
{ 
	int x, y, z, n;               // valori su cui operare

	// Presenta le funzionalita' del programma 
	cout << "Semplice verifica dell'ultimo teorema di Fermat." << endl 
		<< "Se x, y, z sono interi positivi e n intero > 2" << endl
		<< "(x elevato a n)+(y elevato a n)diverso da(z elevato a n)."
		<< endl; 
                                                                        
	// Leggi i dati e verifica che rispondano alle specifiche 
	cout << "Inserisci x,y,z e n, separati da almeno uno spazio: " << endl;                                                 
	cin >> x >> y >> z >> n;
	if (x <= 0 || y <= 0 || z <= 0 || n < 3) return; 

	// verifica se xAllaN + yAllaN è uguale a zAllaN
	// e stampa il risultato
	if (elevaAPotenza(x,n) + elevaAPotenza(y,n) == elevaAPotenza(z,n))
		cout << "Risultato impossibile: Andrew Wiles ha dimostrato la"
			<< " validità dell'ultimo teorema di Fermat nel 1994" << endl;
	else 
		cout << "L'ultimo teorema di Fermat risulta confermato" << endl;
} 

