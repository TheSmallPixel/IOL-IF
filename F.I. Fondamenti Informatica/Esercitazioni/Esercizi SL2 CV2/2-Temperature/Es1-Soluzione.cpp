/* 
Esercizio

Si scriva un programma che legge da tastiera una successione di lunghezza 
fissata di numeri reali che rappresentano le temperature giornaliere alle 
ore 13 dei giorni di un certo periodo, e
-	stampa a video il numero di giorni di quel periodo nei quali la temperatura
    è stata superiore alla temperatura media del periodo
-	stampa a video anche il massimo scarto in valore assoluto di temperatura
    tra due giorni consecutivi


Esempio (lunghezza del periodo fissata a 10):

-1.2   4.5   6.3   0.1   -3.4   -1.2   2.1   3.2   3.2   4.0

Il numero di giorni in cui la temperatura giornaliera è stata superiore alla 
temperatura media è 6 (la temperatura media è 1.76).

Il massimo scarto di temperatura tra due giorni consecutivi è 6.2 (si verifica 
tra il terzo e il quarto giorno).
*/

/*
- PSEUDOCODICE 1 -

Lettura della sequenza di dati e calcolo della somma

Calcolo della media

Calcolo dei giorni in cui la temperatura è superiore alla media

Calcolo della variazione di temperatura fra due giorni consecutivi e del massimo
   fra di loro

Stampa dei risultati



- PSEUDOCODICE 2 -

Lettura della sequenza di dati e calcolo della somma

Calcolo della media

Inizializzazione del contatore
Per ogni valore di temperatura
	se è superiore alla media
		incremento del contatore 

Calcolo della variazione di temperatura fra i primi due giorni ed utilizzo come 
massimo scarto
Per ogni coppia di valori di temperatura consecutivi escluso il primo
	se lo scarto di temperatura fra i due giorni in esame è maggiore del massimo
    scarto
		assegnamento a massimo scarto del nuovo valore

Stampa dei risultati

*/


#include <iostream>
using namespace std;

float abs(float numero); //Restituisce il valore assoluto del parametro passato

main() 
{
  const int LUNGHEZZA = 10;
  float temperature[LUNGHEZZA];
  float somma = 0;
  float media;
  int maggiori = 0;
  int i; 

  // Lettura della sequenza di dati e calcolo della somma
  for(i = 0; i < LUNGHEZZA; i++) 
    {
      cout << "Inserisci il dato n. " << i + 1<< "  :  "; 
      cin >> temperature[i]; 
      somma += temperature[i]; 
    } 

  // Calcolo della media
  media = somma/LUNGHEZZA;

  // Calcolo dei giorni in cui la temperatura è superiore alla media
  for(i = 0; i < LUNGHEZZA; i++) 
    {
      if(temperature[i] > media)
        {
          maggiori++;
        }
    }

  cout << endl << "Il numero di giorni del periodo "
       << "nei quali la temperatura e' stata superiore " << endl 
       << "alla temperatura media del periodo e' " << maggiori ;
  cout << " (la temperatura media e' " << media << ")." << endl;

  // Calcolo della variazione di temperatura fra due giorni consecutivi e del 
  // massimo fra di loro
  float maxScarto = abs(temperature[1] - temperature[0]);
  for(i = 2; i < LUNGHEZZA; i++) 
    {
      if(abs(temperature[i] - temperature[i-1]) > maxScarto)
        {
          maxScarto = abs(temperature[i] - temperature[i-1]);
        }
    }

  cout << "Il massimo scarto - in valore assoluto - "
       << "di temperatura tra due giorni" << endl
	   << "consecutivi e' " << maxScarto << endl;

  return 0;
}



float abs(float numero)
{
  if(numero < 0)
    {
      return -numero;
    }
  else
    {
      return numero;
    }
}


