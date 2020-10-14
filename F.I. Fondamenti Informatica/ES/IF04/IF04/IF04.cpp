// IF04.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	char temp = ' ';
	int numCount = 0,minCharsCount = 0,total = 0;
	while (temp != '$') {
		cin >> temp;
		if (temp != '$') {
			if (temp >= 48 && temp <= 57)
				numCount++;
			if (temp >= 97 && temp <= 122)
				minCharsCount++;

			total++;
		}
	} ;

	cout << "Caratteri minuscoli: " << (minCharsCount/(float) total) << "% Cifre: "<<(numCount/ (float)total)<<"%" << endl;
}