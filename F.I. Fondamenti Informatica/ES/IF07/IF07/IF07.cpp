// IF07.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>
using namespace std;
#define DIM 9
int main()
{
	cout << "Dammi " << DIM << "numeri!" << endl;
	int array[DIM];
	for (int i = 0; i < DIM; i++) {
		cin >> array[i];
	}
	int min = 0, max = 0, i = 0;
	do {
		min = 0, max = 0;
		for (int ii = 0; ii < DIM; ii++) {
			if (ii != i) {
				if (array[ii] < array[i]) {
					min++;
				}
				else if(array[ii] > array[i]){
					max++;
				}
			}
		}
		cout << endl << i << endl;

		i++;
	} while ((i < DIM) && !((min <= (DIM-1)/2) && (max <= (DIM-1)/2)));
	cout << "La mediana dell'insieme di " << DIM << " numeri e' " << array[i] << " - " << i << endl;
}