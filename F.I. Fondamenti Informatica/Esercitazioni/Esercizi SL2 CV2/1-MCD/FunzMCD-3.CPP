/* Programma che calcola il MCD tra due numeri interi positivi
   implementando la funzione calcolaMCD()

Algoritmo di Euclide
MCD(x,x) = x
se x>y MCD(x,y) = MCD(x-y,y)
se x<y MCD(x,y) = MCD(x,y-x)
*/

#include <iostream>
using namespace std;

int calcolaMCD(int, int, int&);    // dichiarazione della funzione - prototipo

int main()
{

	int x, y, z, err;	

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
	err = calcolaMCD(x, y, z);
	
	// Stampa il valore di z
	if (err != 0)
		cout << "Errore: almeno uno dei valori forniti non e' positivo" << endl;
	else
		cout << "Massimo Comune Divisore: " << z << endl << endl;

	return 0;
}


int calcolaMCD(int a, int b, int& r)		// definizione della funzione
{
	// Verifica che i valori forniti siano interi positivi
	if (a<=0 || b <=0)
		return -1;

	// calcola il Massimo Comune Divisore
	while (a!=b)
		if (a>b)
			a=a-b;
		else
			b=b-a;
	r=a;
	return 0;
}

