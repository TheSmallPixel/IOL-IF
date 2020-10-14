// IF03.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	cout << "Inserisci quanti numeri vuoi, per terminare digiti 0:" << endl;
	int temp = -1;
	int max = 0;
	do {
		
		cin >> temp;
		if (temp != 0 && temp > max)
			max = temp;
	} while (temp != 0);
	cout << "Max: " << max << endl;
}