#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int DIM1 = 6;  //Dimensione della matrice
const int DIM2 = 3;  //Dimensione della sottomatrice

int confrontaSottomatrici(int mat1[DIM1][DIM1], int mat2[DIM1][DIM1], int dim1, int dim2);

//x, y: coordinate del primo elemento, in alto a sinistra, della sottomatrice da valutare
int valutaSottomatrice(int mat1[DIM1][DIM1], int mat2[DIM1][DIM1], int x, int y, int dim);
void stampaMatrice(int[DIM1][DIM1], int);

int main()
{
	int m1[DIM1][DIM1] = { {8,26,15,8,9,4},
					{1,5,-4,3,5,17},
					{5,3,2,5,-8,6},
					{3,14,5,4,2,-18},
					{9,1,8,6,5,8},
					{3,4,12,7,3,6} };
	int m2[DIM1][DIM1] = { {7,6,8,4,7,11},
					{26,9,-5,12,6,5},
					{17,-8,19,14,9,8},
					{1,10,-2,3,1,6},
					{4,6,23,15,11,6},
					{2,13,7,7,-4,5} };

	stampaMatrice(m1, DIM1);
	stampaMatrice(m2, DIM1);

	cout << "Valore restituito dalla funzione: " << confrontaSottomatrici(m1, m2, DIM1, DIM2) << endl;
	int i = 0;
	cin >> i;
	return 0;
}


int confrontaSottomatrici(int mat1[DIM1][DIM1], int mat2[DIM1][DIM1], int dim1, int dim2)
{
	int cont = 0; //Conta quante sottomatrici verificano le condizioni poste

	for (int i = 0; i < dim1 - dim2 + 1; i++)
		for (int j = 0; j < dim1 - dim2 + 1; j++)
			if (valutaSottomatrice(mat1, mat2, i, j, dim2)) //Se restituito 1 e'stata verificata la condizione richiesta
			{
				cout << "La sottomatrice trovata e' individuata dalle seguenti celle: (" << i + 1 << "," << j + 1 << ")" << " e (" << i + dim2 << "," << j + dim2 << ")" << endl;
				cont++;
			}

	return cont;
}

int valutaSottomatrice(int mat1[DIM1][DIM1], int mat2[DIM1][DIM1], int x, int y, int dim)
{
	int i, j;
	int somma1 = 0, somma2 = 0;
	int h = 0, k = 0;
	/*
	//Verifica dell'esistenza della sottomatrice (ovvero che non si esca dai limiti di ammissibilita')
	if((x+dim-1>=DIM1) || (y+dim-1>=DIM1) || x<0 || y<0)
	{
		cout<<"Errore nella sottomatrice individuata!"<< endl;
		return 0;
	} */

	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			if (i == j)
			{
				somma1 += mat1[x + i][y + j];
				somma2 += mat2[x + i][y + j];
			}
			else
				if (i < j)
					somma1 += mat1[x + i][y + j];
				else
					somma2 += mat2[x + i][y + j];
		}

	}

	if (somma1 > somma2)
		return 1;
	else
		return 0;
}

void stampaMatrice(int matrice[][DIM1], int dim)
{
	int i, j;

	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
			cout << setw(4) << matrice[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	return;
}