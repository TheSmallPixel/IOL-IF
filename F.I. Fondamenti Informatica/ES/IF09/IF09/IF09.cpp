// IF06.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
#include "pch.h"
#include <iostream>
using namespace std;
#define DIM1 3
#define DIM2 8
float getMediana(int *array, int dim) {
	return (dim % 2 != 0) ? (array[dim / 2]) : (array[dim / 2] + array[(dim / 2) - 1]) / (float)2;
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
	cout << "La prima mediana è: " << getMediana(getData(DIM1), DIM1) << endl;
	cout << "La seconda mediana è: " << getMediana(getData(DIM2), DIM2) << endl;
	return 0;
}