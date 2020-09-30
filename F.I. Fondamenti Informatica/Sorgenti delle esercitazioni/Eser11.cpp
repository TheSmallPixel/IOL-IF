#include <iostream>
using namespace std;

const int RANGO=3;

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


int massimoDiagonali(const int mat[][RANGO])
{
	int somma, rigaInizio, colInizio, riga, col, max=0;

	// triangolo superiore
	for (rigaInizio=0; rigaInizio <RANGO; rigaInizio ++)  //per ogni cammino
	{
		//calcola la somma lungo la diagonale
		somma = 0;    
        
		riga = rigaInizio;  //riga e colonna dell'inizio del cammino
		col = 0;

		while(riga>=0 && col<RANGO)  //finche' non esci dai limiti della matrice
		{
			somma += mat[riga][col];   //sommo l'elemento corrente
			riga--; col++;             //passo all'elemento successivo lungo il cammino
		}

		if (somma>max)
			max = somma;
	}

	// triangolo inferiore
	for (colInizio=1; colInizio <RANGO; colInizio ++)  //per ogni cammino
	{
		//calcola la somma lungo la diagonale
		somma = 0;    
        
		riga = RANGO-1;  //riga e colonna dell'inizio del cammino
		col = colInizio;

		while(riga>=0 && col<RANGO)  //finche' non esci dai limiti della matrice
		{
			somma += mat[riga][col];   //sommo l'elemento corrente
			riga--; col++;             //passo all'elemento successivo lungo il cammino
		}

		if (somma>max)
			max = somma;
	}
   
	return max;
}

