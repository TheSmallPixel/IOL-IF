/*Prima PI del 25 ottobre 2019 - Array

Data una matrice quadrata di interi e due array pure di interi si vogliono
cercare nella matrice le sequenze di valori che costituiscono la differenza
fra i numeri presenti nei due array. La differenza dovrà essere calcolata in
due modi:
- sottraendo dal valore di ogni cella del primo array il valore della
corripondente cella del secondo array (la chiameremo differenza di tipo 1);
- sottraendo dal valore della prima cella del primo array il valore dell’ultima
cella del secondo array, dal valore dalla seconda cella del primo array il 
valore della penultima cella del secondo array e così via (la chiameremo 
differenza di tipo 2).
Si scriva, in linguaggio C++, la funzione individuaDifferenze che, ricevuta in
ingresso una matrice quadrata di interi di dimensione N e due array di interi
di dimensione M (con M<=N), stampi a video le coordinate delle celle della
matrice a partire dalle quali, scandendo la matrice da sinistra a destra e
dall’alto in basso, compare una sequenza di valori che costituisce la differenza
fra i valori dei due array, calcolata come indicato in precedenza, e restituisca,
come valore di ritorno, il numero di sequenze trovate.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int N=5; //Dimensione matrice
const int M=3; //Dimensione array

//Funzione richiesta dalle specifiche del problema
int individuaDifferenze(int mat[][N], int dimM, int vett1[], int vett2[], int dimV);

//Individua la sequenza vett[] in mat[][] a partire dalla posizione n,m
//Restituisce il valore 1 se viene individuata la sequenza, altrimenti 0
int cercaSequenza(int mat[][N], int dimM, int vett[], int dimV, int n, int m);

void stampaVett(int vett[], int dimV);
void stampaMat(int mat[][N], int dimM);



int main()
{
	
	int mat[][N]={{17,-8,9,1,6},
				{8,6,19,-5,12},
				{1,3,5,3,7},
				{-6,16,12,1,3},
				{11,42,9,1,6}};

	/*int mat[][N]={{17,-8,9,1,6},
				{8,6,19,-5,12},
				{1,3,5,3,7},
				{-6,16,12,1,3},
				{11,42,23,-5,14}};*/

	int vett1[]={17,3,11};
	int vett2[]={5,2,8};
	int numSeq; //sequenze individuate

	//Stampa i dati del problema
	cout<<"array1"<<endl;
	stampaVett(vett1,M);
	cout<<endl;

	cout<<"array2"<<endl;
	stampaVett(vett2,M);
	cout<<endl;

	cout<<"matrice"<<endl;
	stampaMat(mat,N);
	cout<<endl;

	//esecuzione della funzione richiesta dalle specifiche del problema
	numSeq=individuaDifferenze(mat, N, vett1, vett2, M);
	
	cout<<endl;
	cout<<"Sono state individuate "<<numSeq<<" sequenze"<<endl<<endl;

	return 0;
}

int individuaDifferenze(int mat[][N],int dimM, int vett1[], int vett2[], int dimV)
{
	int seq=0;

	int diff1[M], diff2[M]; //archiviano le differenze tra vett1 e vett2 come 
							//da specifiche


	//calcola il vettore diff1[]
	for(int i=0; i<M; i++)
		diff1[i]=vett1[i]-vett2[i];

	cout<<"Sequenza 1 da individuare: "; stampaVett(diff1,M); cout<<endl;

	//calcola il vettore diff2[]
	for(int i=0; i<M; i++)
		diff2[i]=vett1[i]-vett2[M-1-i];

	cout<<"Sequenza 2 da individuare: "; stampaVett(diff2,M); cout<<endl;

	//A partire da ogni elemento della matrice si cercano le sequenze indicate
	for(int i=0; i<dimM; i++)
		for(int j=0; j<dimM; j++)
		{
			//...si interrompe se la sequenza da individuare e' piu lunga degli elementi
			//rimanenti nella matrice
			if(i==dimM-1 && j>dimM-dimV)
				return seq;
			if(cercaSequenza(mat, dimM, diff1, dimV, i, j))
			{
					cout<<"("<<i<<","<<j<<") "<< "differenza di tipo 1"<<endl;
					seq++;
			}
			if(cercaSequenza(mat, dimM, diff2, dimV, i, j))
			{
					cout<<"("<<i<<","<<j<<") "<< "differenza di tipo 2"<<endl;
					seq++;
			}
		}
	return seq;
}

int cercaSequenza(int mat[][N], int dimM, int vett[], int dimV, int n, int m)
{
	for(int i=0; i<dimV;i++)
	{
		//se si giunge a fine riga si incrementa la riga e si ultima il conteggio
		if(m+i==dimM)
		{
			n++;
			m=-i;
		}
		//alla prima discrepanza si esce con valore 0
		if(mat[n][m+i]!=vett[i])
			return 0;
	}
	return 1;
}

void stampaVett(int vett[], int dimV)
{
	for(int i=0; i<dimV; i++)
		cout<<setw(4)<<vett[i];
	cout<<endl;
	return;
}

void stampaMat(int mat[][N], int dimM)
{
	for(int i=0; i<dimM; i++)
	{
		for(int j=0;j<N;j++)
			cout<<setw(4)<<mat[i][j];
		cout<<endl;
	}
	return;
}