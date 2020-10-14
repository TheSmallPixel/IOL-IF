// IF06.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>
using namespace std;
#define DIM1 3
#define DIM2 5
int getMediana(int *array,int dim) {
	int min = 0, max = 0, i = 0;
	do {
		min = 0, max = 0;
		for (int ii = 0; ii < dim; ii++) {
			if (ii != i) {
				if (array[ii] < array[i]) {
					min++;
				}
				else if (array[ii] > array[i]) {
					max++;
				}
			}
		}
		i++;
	} while ((i < dim) && !((min <= (dim - 1) / 2) && (max <= (dim - 1) / 2)));
	return array[i];
}
int * getData(int dim) {
	cout << "Dammi " << dim << "numeri!" << endl;
	int* array = new int[dim];
	for (int i = 0; i < dim; i++) {
		cin >> array[i];
	}
	return array;
}
int main()
{
	cout << "La prima mediana è: " << getMediana(getData(DIM1),DIM1) << endl;
	cout << "La seconda mediana è: " << getMediana(getData(DIM2), DIM2) << endl;

	return 0;
}