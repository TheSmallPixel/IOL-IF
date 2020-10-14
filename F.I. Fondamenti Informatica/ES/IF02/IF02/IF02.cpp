// IF02.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	cout << "Quanti numeri vuoi inserire?" << endl;
	cin >> n;
	if (n == 0) {
		cout << "Media non definita." << endl;
		return 0;
	}
	int somma = 0,temp = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		somma += temp;
	}

    cout << "La Media e: " << (somma/n); 
}