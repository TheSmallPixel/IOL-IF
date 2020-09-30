/* Programma che calcola il MCD tra due numeri interi positivi

Algoritmo di Euclide
MCD(x,x) = x
se x>y MCD(x,y) = MCD(x-y,y)
se x<y MCD(x,y) = MCD(x,y-x)
*/


#include <iostream>
using namespace std;

int main()
{

	int x, y;	// dichiarazione delle variabili intere x e y

	cout << endl;
	cout << "Calcolo del MCD";
	cout << endl;
	cout << endl;


	// Leggi il valore di x
	cout << "Inserisci il primo numero: ";
	cin >> x;
	cout << endl;

	// Leggi il valore di y
	cout << "Inserisci il secondo numero: ";
	cin >> y;
	cout << endl;

	// Finchè (x!=y) aggiorna x e y
	while (x!=y){
			if (x>y){
				x=x-y;
			}
			else{
				y=y-x;
			}
	}

	// Stampa il valore di x
	cout << "Massimo Comune Divisore: " << x << endl << endl;

	return 0;
}

