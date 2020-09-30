/* Programma che calcola il MCD tra due numeri interi positivi
   implementando la funzione calcolaMCD()

Algoritmo di Euclide
MCD(x,x) = x
se x>y MCD(x,y) = MCD(x-y,y)
se x<y MCD(x,y) = MCD(x,y-x)
*/

#include <iostream>
using namespace std;

int calcolaMCD(int, int);    // dichiarazione della funzione - prototipo

int main()
{

	int x, y;	

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

	// Chiamata della funzione che restituisce il MCD
	x = calcolaMCD(x, y);
	
	// Stampa il valore di x
	cout << "Massimo Comune Divisore: " << x << endl << endl;

	return 0;
}


int calcolaMCD(int a, int b)		// definizione della funzione
{
	while (a!=b)
		if (a>b)
			a=a-b;
		else
			b=b-a;
	return a;
}

