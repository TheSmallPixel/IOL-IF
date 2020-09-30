#include <iostream>
using namespace std;

const int DIM1 = 5;
const int DIM2 = 11;

//prototipi delle funzioni
void leggiVettore (int vettore[], int dimensione);
void calcolaMediana (const int vettore[], int dimensione, int &mediana);
int massimo (int numero1, int numero2);

void main()
{
	int insieme1[DIM1], insieme2[DIM2]; /* vettori per memorizzare
								i due insiemi di numeri */
	int mediana1, mediana2; /* variabili per memorizzare i valori 
								delle mediane dei due insiemi */

	//visualizzazione di un messaggio iniziale
	cout << endl << "Programma che calcola il massimo "
		<< "delle mediane di due insiemi di numeri distinti"
		<< endl << endl;

	//lettura dei due insiemi di numeri

	cout << "Insieme n. 1:" << endl;
	leggiVettore(insieme1, DIM1);

	cout << endl << "Insieme n.2:" << endl;
	leggiVettore(insieme2, DIM2);

	// calcolo delle due mediane
	calcolaMediana(insieme1, DIM1, mediana1);
	calcolaMediana(insieme2, DIM2, mediana2);

	// calcolo del massimo delle due mediane
	cout << endl << "Il valore massimo delle due mediane e' "
		<< massimo(mediana1, mediana2) << endl;
}


//funzione per la lettura di un vettore lungo dimensione
void leggiVettore (int vettore[], int dimensione)
{
	for (int i = 0; i < dimensione; i++)
	{
		cout << "Inserisci il dato n. " << i + 1 << " ";
		cin >> vettore[i];
	}
}

//funzione per il calcolo della mediana di un insieme di numeri
void calcolaMediana (const int insieme[], int dimensione, int &mediana)
{
	int contatore;
	int i = 0;

	do
	{
		contatore = 0;
		int j = 0;
		while ((j < dimensione) && (contatore <= (dimensione - 1)/2))
		{
			if (insieme[i] > insieme[j])
				contatore++;
			j++;
		}
		i++;
	} while ((i < dimensione) && (contatore != (dimensione - 1)/2));
	mediana = insieme[i - 1];
}

//funzione per il calcolo del massimo di due numeri
int massimo (int numero1, int numero2)
{
	if(numero1 > numero2)
		return numero1;
	else
		return numero2;
}