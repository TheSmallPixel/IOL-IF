/* Scrivere un programma che legge una matrice bidimensionale di caratteri e
ricerchi al suo interno un valore passato in ingresso dall’utente. Il programma
restituisce quindi il numero di linea e di colonna relativo all’elemento cercato
se questo è presente nella matrice, altrimenti il messaggio 
"Elemento non presente".

Esempio: fornita in ingresso la matrice
A  V  R
B  G  L
L  A  K
e indicato come carattere da ricercare  A  fornisce il seguente output:
A in linea 1 colonna 1
A in linea 3 colonna 2
*/

#include <iostream>
using namespace std;

int const DIM=3

void popolaMatrice (char [][DIM], int);
void stampaMatrice (char [][DIM], int);
void cercaCarattere (char [][DIM], int, char);

int main()
{
   	char mat[DIM][DIM];
   	char car;

   	// Presenta all'utente le funzionalita' del programma 
   	cout << "\nProgramma che legge una matrice bidimensionale di caratteri ed\n";
   	cout << "un carattere da ricercare e fornisce in output le coordinate delle\n";
   	cout << "posizioni in cui compare il carattere\n\n";

   	// Lettura della matrice bidimensionale
	popolaMatrice(mat, DIM);

   	// Lettura del carattere da ricercare
   	cout << "Digitare il carattere da ricercare: ";
   	cin >> car;

   	// Stampa della matrice
   	stampaMatrice (mat, DIM);

   	// Ricerca del carattere nella matrice e stampa delle coordinate
   	cercaCarattere (mat, DIM, car);

   	return 0;
}


void popolaMatrice(char matrice[][DIM], int dim)
{
	int i, j;

	cout << "Inserire la matrice di caratteri\n\n";
	for (i=0; i<dim; i++)
	  	for (j=0; j<DIM; j++)
		{
			cout << "Inserire l'elemento " << i << j << ": ";
			cin >> matrice[i][j];
		}
	return;

}

void stampaMatrice (char matrice[][DIM], int dim)
{
	int i, j;

	cout << "\nMatrice:\n\n";
   	for (i=0; i<dim; i++)
   	{
	  	for (j=0; j<DIM; j++)
		 	cout << matrice[i][j] << " ";
      cout << endl;
   	}
   	cout << endl;

	return;
}


void cercaCarattere (char matrice[][DIM], int dim, char carattere)
{

   	int i, j, cont = 0;

   	for (i=0; i<dim; i++)
	  	for (j=0; j<DIM; j++)
			 if (matrice[i][j] == carattere)
			 {
				cout << carattere << " - in riga " << i+1 << " colonna " << j+1;
				cout << endl;
				cont++;
		 	}
   	if (cont == 0)
	  	cout << carattere <<" - Elemento non presente\n";

	return;
}

