/* Tentativo senza speranza di dimostrare la falsità dell'ultimo 
 * teorema di Fermat.
 * Versione senza funzioni.
 */
#include <iostream>
using namespace std;
                                                                           
void main() 
{ 
	int x, y, z, n,               // valori su cui operare 
	xAllaN, yAllaN, zAllaN;     // contengono x,y,z elevati a n           
	int base, esponente, potenza, // variabili per utilizzo codice già
	prodMancanti;                 // esistente

	// Presenta le funzionalita' del programma 
	cout << "Semplice verifica dell'ultimo teorema di Fermat." << endl 
		<< "Se x, y, z sono interi positivi e n intero > 2" << endl
		<< "(x elevato a n)+(y elevato a n) e' diverso da (z elevato a n)" 
		<< endl; 
                                                                        
	// Leggi i dati e verifica che rispondano alle specifiche 
	cout << "Inserisci x,y,z e n, separati da almeno uno spazio: " 
		<< endl;                                                 
	cin >> x >> y >> z >> n;
	if (x <= 0 || y <= 0 || z <= 0 || n < 3) return; 

	// calcola x elevato a n, con risultato in xAllaN
	base = x; esponente = n;                                              
	// calcola base elevato a esponente, con risultato in potenza 
	potenza = 1;                 
	for (prodMancanti = esponente; prodMancanti > 0; prodMancanti--)
		potenza *= base;                                                       
	xAllaN = potenza;                                                     

	// calcola y elevato a n, con risultato in yAllaN
	base = y; esponente = n;
	// calcola base elevato a esponente, con risultato in potenza 
	potenza = 1;                 
	for (prodMancanti = esponente; prodMancanti > 0; prodMancanti--)
		potenza *= base;                                                       
	yAllaN = potenza;

	// calcola z elevato a n, con risultato in zAllaN
	base = z; esponente = n;
	// calcola base elevato a esponente, con risultato in potenza 
	potenza = 1;                 
	for (prodMancanti = esponente; prodMancanti > 0; prodMancanti--) 
		potenza *= base;                                                       
	zAllaN = potenza;

	// verifica se xAllaN + yAllaN è uguale a zAllaN
	// e stampa il risultato
	if (xAllaN + yAllaN == zAllaN)
		cout << "Risultato impossibile: Andrew Wiles ha dimostrato la"
		<< " validità dell'ultimo teorema di Fermat nel 1994" << endl;
	else 
		cout << "L'ultimo teorema di Fermat e' confermato" << endl;
} 

