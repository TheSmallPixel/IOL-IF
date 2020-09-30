#include <iostream>
using namespace std;

const int RANGO = 3;

int massimoDiagonali (const int mat[][RANGO]);

int main (void)
{
	int matrice[RANGO][RANGO];

	//inserimento dei dati nella matrice
	for (int i=0; i<RANGO; i++)
		for (int j=0; j<RANGO; j++)
		{
			cout << endl << "Inserisci l'elemento ["<<i<<"]["<<j<<"]: ";
			cin >> matrice[i][j]; 
		}
     
	//calcolo del massimo lungo le diagonali
	cout << endl << "Il massimo delle diagonali e': " << 
		massimoDiagonali(matrice) << endl;
 
	return 0;
}


int massimoDiagonali (const int mat[][RANGO])
{
	int somma, rigaInizio, colInizio, k, max=0;

	// triangolo superiore
	for (rigaInizio=0; rigaInizio <RANGO; rigaInizio ++)  //per ogni cammino
	{
		//calcola la somma lungo la diagonale
		somma=0;

		for(k=0; k<(rigaInizio+1); k++)  //per tutta la lunghezza del cammino
			somma += mat[rigaInizio-k][k];

		if (somma>max)
			max = somma;
	}

	// triangolo inferiore
	for (colInizio=1; colInizio <RANGO; colInizio ++)  //per ogni cammino
	{
		//calcola la somma lungo la diagonale
		somma = 0;

		for (k=0; k<(RANGO-colInizio); k++)  //per tutta la lunghezza del cammino
			somma += mat[RANGO-1-k][colInizio+k];

		if (somma > max)
			max = somma;   
	}

	return max;
}