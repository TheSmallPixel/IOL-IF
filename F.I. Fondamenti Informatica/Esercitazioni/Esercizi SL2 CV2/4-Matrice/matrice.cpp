/* Scrivere un programma che legge una matrice bidimensionale di caratteri e
ricerchi al suo interno un valore passato in ingresso dall’utente. Il programma
restituisce quindi il numero di linea e di colonna relativo all’elemento cercato
se questo è presente nella matrice, altrimenti il messaggio "Elemento non 
presente".

Esempio: fornita in ingresso la matrice
A  V  R
B  G  L
L  A  K
e indicato come carattere da ricercare  A  fornisce il seguente output:
A in linea 1 colonna 1
A in linea 3 colonna 2
*/



/*
    PSEUDOCODICE 1

    Presenta all'utente le funzionalita' del programma
    Lettura della matrice bidimensionale 
    Lettura del carattere da ricercare 
    Stampa della matrice 
    Ricerca del carattere nella matrice e stampa delle coordinate 
*/



/*
    PSEUDOCODICE 2

    Presenta all'utente le funzionalita' del programma
    
	per ogni riga della matrice
	    per ogni cella 
		    lettura del rispettivo valore
			
    Lettura del carattere da ricercare 
    
	per ogni riga della matrice
	    per ogni cella 
		    stampa del rispettivo valore
    
	per ogni riga della matrice
	    per ogni cella 
		    se il valore della cella coincide con il carattere cercato
			    stampa delle coordinate della cella
*/



#include <iostream>
using namespace std;

int main()
{
   const int DIM=3;
   char mat[DIM][DIM];
   char car;
   int i, j;
   int cont;

   /* Presenta all'utente le funzionalita' del programma */
   cout << "Programma che legge una matrice bidimensionale di caratteri ed "
        << "un carattere da" << endl << "ricercare e fornisce in output le "
		<< "coordinate delle posizioni in cui compare il" << endl 
		<< "carattere" << endl << endl;

   /* Lettura della matrice bidimensionale */
   cout << "Inserire la matrice di caratteri" << endl;
   for (i=0; i<DIM; i++)
	  for (j=0; j<DIM; j++)
		 cin >> mat[i][j];

   /* Lettura del carattere da ricercare */
   cout << "Digitare il carattere da ricercare" << endl;
   cin >> car;

   /* Stampa della matrice */
   cout << endl << "Matrice:" << endl;
   for (i=0; i<DIM; i++)
   {
	  for (j=0; j<DIM; j++)
		 cout << mat[i][j];
      cout << endl;
   }
   cout << endl;

   /* Ricerca del carattere nella matrice e stampa delle coordinate */
   cont = 0;
   for (i=0; i<DIM; i++)
	  for (j=0; j<DIM; j++)
		 if (mat[i][j] == car)
		 {
			cout << car << " - in linea " << i+1 << " colonna " << j+1 << endl;
			cont++;
		 }
   if (cont == 0)
	  cout << car << " - Elemento non presente" << endl;

   return 0;
}
