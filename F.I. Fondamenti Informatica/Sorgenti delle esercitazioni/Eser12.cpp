/* programma che legge un vettore, lo stampa, 
ricerca un numero all'interno del vettore.*/

#include <iostream>
#include <iomanip>
using namespace std;

//prototipi
void leggiVettore(int vett[], int dim);
void stampaVettore(const int vett[], int dim);

int ricercaSeq(const int vett[], int dim, int elem);
int ricercaSeqOrd(const int vett[], int dim, int elem);
int ricercaBinaria(const int vett[], int dim, int elem);

int main()
{
	const int DIM = 10;   //dimensione massima del vettore
	int vettore[DIM];
	int tipo=-1;

	//lettura dei dati del vettore e stampa del vettore letto
	leggiVettore(vettore, DIM);
	stampaVettore(vettore, DIM);

	//ricerca di un elemento
	int elemento, pos;
	while (tipo!=0)
	{
		cout << endl << endl << "Immettere il tipo di ricerca da applicare " << endl;
		cout << "Sequenziale              1 " << endl;
		cout << "Sequenziale con ordine   2 " << endl;
		cout << "Binaria                  3 " << endl;
		cout << "Esci                     0 " << endl << endl;
		cout << "Tipo: ";
		cin >> tipo;
		if (tipo!=0)
		{
			cout << "Immettere l'elemento da cercare " << endl;
			cin >> elemento;
			cout << endl;
			switch (tipo) 
			{
				case 1: /*chiamata della funzione ricerca*/
					pos = ricercaSeq(vettore, DIM, elemento); 
					if (pos >= 0)
						cout << "Il valore "<< elemento <<" e' in posizione " << pos;
					else
						cout << " Il valore " << elemento << 
							" non si trova nel vettore" << endl;
					break;
				case 2: /*chiamata della funzione ricerca*/
					pos = ricercaSeqOrd(vettore, DIM, elemento); 
					if (pos >= 0)
						cout << "Il valore "<< elemento <<" e' in posizione " << pos;
					else
						cout << " Il valore " << elemento << 
							" non si trova nel vettore" << endl;
					break;
				case 3: /*chiamata della funzione ricerca*/
					pos = ricercaBinaria(vettore, DIM, elemento); 
					if (pos >= 0)
						cout << "Il valore "<< elemento <<" e' in posizione " << pos;
					else
						cout << " Il valore " << elemento << 
							" non si trova nel vettore" << endl;
					break;
				default: cout << "Il numero inserito non e' corretto" << endl;
			} //fine switch
		} //fine if
	} //fine while
	return 0;
}

//funzione che legge dim dati e li memorizza nel vettore vett
void leggiVettore(int vett[], int dim)
{
	cout << endl << "Immettere i valori contenuti nell'array" << endl
		<< endl;

	for(int i = 0; i < dim; i++)
	{
		cout << "Immettere il dato in posizione " << i+1 << ": " ;
		cin >> vett[i];
	}
}

//funzione che stampa dim dati del vettore vett
void stampaVettore(const int vett[], int dim)
{
	for(int i = 0; i < dim; i++)
		cout << setw(5) << vett[i];
	cout << endl;
}

// RICERCA IN UN VETTORE NON ORDINATO
int ricercaSeq(const int vett[], int dim, int elem)
{
	if(dim == 0)
		return - 1;
	int i = 0;
	while ((i < dim-1) && (elem != vett[i]))
		i++;
	if (elem == vett[i])
		return i;
	else
		return -1;
}

// RICERCA SEQUENZIALE IN UN VETTORE ORDINATO
int ricercaSeqOrd(const int vett[], int dim, int elem)
{
	if(dim == 0)
		return - 1;
	int i = 0;
	while((i < dim-1) && (elem > vett[i]))
		i++;
	if (elem == vett[i])
		return i;
	else
		return -1;
}

// RICERCA BINARIA IN UN VETTORE ORDINATO
int ricercaBinaria(const int vett[], int dim, int elem)
{
	if(dim == 0)
		return - 1;
	int inf = 0;
	int med;
	int sup = dim - 1;
	while (inf <= sup)
	{
		med = (inf + sup) / 2;
		if (vett[med] < elem)
			inf = med + 1;
		else if (elem < vett[med])
			sup = med - 1;
		else
			return med;
	}
	return -1;
}