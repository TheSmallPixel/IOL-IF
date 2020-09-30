#include <iostream>
using namespace std;

const int DIM1 = 5;
const int DIM2 = 11;

//prototipi delle funzioni
void leggiVettore (int vettore[], int dimensione);
int mediana (const int vettore[], int dimensione);
int massimo (int numero1, int numero2);

void main()
{
	int insieme1[DIM1], insieme2[DIM2];

	cout << endl << "Programma che calcola il massimo "
		<< "delle mediane di due insiemi di numeri distinti"
		<< endl << endl;

	cout << "Insieme n. 1:" << endl;
	leggiVettore(insieme1, DIM1);
	cout << endl << "Insieme n.2:" << endl;
	leggiVettore(insieme2, DIM2);

	cout << endl << "Il valore massimo delle due mediane e' "
		<< massimo(mediana(insieme1, DIM1),
			mediana(insieme2, DIM2)) << endl;
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
int mediana(const int insieme[], int dimensione)
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
	return insieme[i - 1];
}

//funzione per il calcolo del massimo di due numeri
int massimo(int numero1, int numero2)
{
	if(numero1 > numero2)
		return numero1;
	else
		return numero2;
} 


