// IF01.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>

using namespace std;
int gtc(int m, int n) {
	if (n == 0)
		return m;
	return gtc(n, m%n);
}

int main()
{

	int a = 0, b = 0;

	cout << "Inserisci due numeri:" << endl;
	cin >> a >> b;
	cout << "Numeri inseriti: " << a << " - " << b << endl << "MCD: " << gtc(a, b);
}
