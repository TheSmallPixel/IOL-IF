#include <iostream>
using namespace std;

const int FALSO = 0;
const int VERO = 1;
const int RIGHE = 4;
const int COLONNE = 3;

void puntoDiSella(const int mat[RIGHE][COLONNE],int &rigamax, int &colmin, int &esiste)
{
	int riga = 0;
	esiste = FALSO;           // suppongo che la sella non esista
	do
	{
		// cerco colonna del minimo su riga
		colmin = 0;           // ipotizzo il min in colonna 0
		for(int colCorr=1; colCorr<COLONNE; colCorr++)
		{  
			if(mat[riga][colCorr] < mat[riga][colmin])
				colmin=colCorr;        // aggiorno colonna minimo
		}
		// cerco riga del massimo su colmin
		rigamax = 0;            // ipotizzo il max in riga 0
		for (int rigaCorr=1; rigaCorr<RIGHE; rigaCorr++)
		{
			if (mat[rigaCorr][colmin] > mat[rigamax][colmin])
				rigamax = rigaCorr;
		}
		if(rigamax == riga)
			esiste = VERO;      // termino
		riga++;
	} while((!esiste) && (riga < RIGHE));
}

void main ()
{
	int ch;
	int matinput[RIGHE][COLONNE];
	int i=0,j=0;
	int rigaSella;
	int colonnaSella;
	int esiste;

	for (j=0;j<RIGHE;j++)
		for (i=0;i<COLONNE;i++) 
			matinput[j][i]=0;
	
	cout << "Inserire riga per riga i dati delle matrici" << endl;
	cout << "inserisce le cifre separate da spazi" << endl;
	cout << "per inserire una nuova colonna premere enter" << endl;
	for (j=0;j<RIGHE;j++)
    {
		cout<<"inserire "<<COLONNE<<" valori per la "<<j+1<<" riga"<<endl;
		i=0;
		while (i<COLONNE)
		{
			cin >> ch;
			matinput[j][i] = ch;
			i++;
		}
	}

	puntoDiSella(matinput,rigaSella,colonnaSella,esiste);
	if (esiste==VERO)
	{
		cout<<"il punto di sella esiste ed e' " << 
			matinput[rigaSella][colonnaSella] << endl;
	}
	else
		cout <<"il punto di sella non esiste"<<endl;
}
