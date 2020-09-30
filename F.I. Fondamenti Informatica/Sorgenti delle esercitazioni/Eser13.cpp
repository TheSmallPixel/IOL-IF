#include<iostream>
#include<iomanip>
using namespace std;

void leggiVettore(int vett[], int dim);

void stampaVettore(const int vett[], int dim);

void ordinamentoInserimento(int vett[], int dim);
void ordinamentoSelezione(int vett[], int dim);
void ordinamentoScambio(int vett[], int dim);
/*
	Prototipo della funzione
	Le sue possibili definizioni sono riportate piu` sotto

	vett: vettore da ordinare
	dim: numero di elementi del vettore
*/

const int FALSO = 0;
const int VERO = 1;

int main()
{
	const int DIM = 10;

	int vettore[DIM];

	leggiVettore(vettore, DIM);

	ordinamentoInserimento(vettore, DIM);
	cout<<" stampa del vettore ordinato per Inserimento"<<endl;
	stampaVettore(vettore, DIM);

	ordinamentoSelezione(vettore, DIM);
	cout<<" stampa del vettore ordinato per Selezione"<<endl;
	stampaVettore(vettore, DIM);

	ordinamentoScambio(vettore, DIM);
	cout<<" stampa del vettore ordinato per Scambio"<<endl;
	stampaVettore(vettore, DIM);

	return 0;
}

void leggiVettore(int vett[], int dim)
{
	cout << endl << "Immettere 10 valori contenuti nell`array" << endl ;

	for(int i = 0; i < dim; i++)
	{
		cout << "Immettere il dato in posizione " << i+1 << ": " ;
		cin >> vett[i];
	}
}

void stampaVettore(const int vett[], int dim)
{
	for(int i = 0; i < dim; i++)
	{
		cout << setw(5) << vett[i];
	}
	cout << endl;
}


// ORDINAMENTO PER INSERIMENTO

void ordinamentoInserimento(int vett[], int dim)
{
	int curr;

	for(int i = 1; i < dim; i++)
	{
		curr = vett[i];

		int j = i;
		while ((j > 0) && (curr < vett[j-1]))
		{
			vett[j] = vett[j-1];
			j--;
		}
		vett[j] = curr;
	}
}


// ORDINAMENTO PER SELEZIONE

void ordinamentoSelezione(int vett[], int dim)
{
	int temp, posmin;

	for(int i = 0; i < dim-1; i++)
	{
		posmin = i;

		for(int j = i + 1; j < dim; j++)
		{
			if (vett[j] < vett[posmin])
			{
				posmin = j;
			}
		}
		temp = vett[i];
		vett[i] = vett[posmin];
		vett[posmin] = temp;
	}
}


// ORDINAMENTO PER SCAMBIO

void ordinamentoScambio(int vett[], int dim)
{
	int ordinato;
	int temp;

	ordinato = FALSO;
	while (!ordinato)
	{
		ordinato = VERO;

		for(int j = 0; j < dim-1; j++)
		{
			if (vett[j] > vett[j+1])
			{
				temp = vett[j];
				vett[j] = vett[j+1];
				vett[j+1] = temp;

				ordinato = FALSO;
			}
		}
	}
}
