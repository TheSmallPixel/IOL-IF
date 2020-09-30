#include <iostream>
#include <iomanip>
using namespace std;

void main(void)
{                                               
	int numRighe, numColonne, i, j;
	int** mat; // puntatore a puntatore = array di array
	
	// acquisisco le dimensioni
	cout << "Inserisci il numero di righe e di colonne" << endl;
	cin >> numRighe;
	cin >> numColonne;
	// creo dinamicamente una matrice delle dimensioni volute 
	if (numRighe>0 && numColonne>0)
	{
		mat = new int*[numRighe]; // creo l'array esterno di puntatori (int*)
		for (i=0; i<numRighe; i++) // creo le righe
			mat[i] = new int[numColonne];
		for (i=0; i<numRighe; i++) //riempio la matrice di 0
			for (int j=0; j<numColonne; j++) // usando l'operatore di selezione
				mat[i][j]=0;  // come per matrici statiche
		cout << endl;
		//visualizzo la matrice
		for (i=0; i<numRighe; i++)
		{
			for (j=0; j<numColonne; j++)
				cout << setw(4) << mat[i][j];
			cout << endl;
		}
		// distruggo esplicitamente la matrice
		for (i=0; i<numRighe; i++) // distruggo riga per riga
			delete[] mat[i];
		delete[] mat; // distruggo l'array di puntatori
	}
	else 
	{
		cout << "Non ha senso una matrice con 0 righe ";
		cout << " e 0 colonne " << endl;
	}
}

