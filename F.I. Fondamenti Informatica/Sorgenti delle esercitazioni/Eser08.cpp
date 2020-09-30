//inizio intestazione
#include <iostream>
using namespace std;

void main()
{
//fine intestazione
//inizio inizializzazione
	int const maxlungh = 40;
	char const blank = ' ';
	char riga[maxlungh], rigag[maxlungh];
	int i, j, k, p;
	int nparole, nspazi, resto, quoziente;

	for (i=0;i<maxlungh; i=i+1) {
		riga[i]= blank;
		rigag[i]=blank;
	}
// acquisizione
	i = 0;
	cout << "inserire una riga da giustificare" << endl;
	do {			
		riga[i]=cin.get();
		i = i+1;
	} while ((riga[i-1] != '\n') && (i<maxlungh));
	nspazi = maxlungh-i;
	nparole = 0;
	i = 0;	
	//finche' non sei a fine riga
	while ((i<maxlungh) && (riga[i] != '\n')) 
	{
		//conta spazi
		while ((i<maxlungh) && (riga[i] == blank)) 
		{
			nspazi = nspazi+1;
			i = i+1;
		}
		//se inizio parola
		if ((i<maxlungh) && (riga[i] != '\n')) 
		{ 
			//conta parola
			nparole = nparole+1;
		}
		//salta caratteri parola
		while ((i<maxlungh) && (riga[i]!= '\n') && (riga[i] != blank) )
		{
			i = i+1;
		}
	}
	// int = nspazi div nparole-1
	quoziente = nspazi / ( nparole-1);
	//resto = nspazi mod nparole-1
	resto = nspazi % (nparole-1);
	//i, j = 1
	i = 0;
	j = 0;
	//per tutte le parole tranne l'ultima
	for (p=1; p<nparole; p=p+1) 
	{
		//salta spazi in riga
		while ((i<maxlungh) && (riga[i] ==blank)) 
		{
			i = i+1;
		}
		//copia caratteri parola in riga-g
		while ((i<maxlungh) && (riga[i] != blank)) 
		{
			rigag[j] = riga[i];
			i = i+1;
			j = j+1;
		}
		//aggiungi int spazi in riga-g
		for (k=1; k<= quoziente; k=k+1)
		{
			rigag[j] = blank;
			j = j+1;
		}
		//se resto<>0 aggiungi un carattere in riga-g e decrementa resto 
		if (resto > 0)
		{
			rigag[j] = blank;
			j = j+1;
			resto = resto-1;
		}
	}
	//salta spazi in riga i
	while ((i< maxlungh) && (riga[i] == blank)) 
	{
		i = i+1;
	}
	//copia ultima parola in riga g
	while ((i< maxlungh) && (riga[i] != blank)) 
	{
		rigag[j] = riga[i];
		i = i+1;
		j = j+1;
	}
	//stampa risultato
	for (j=0; j<maxlungh; j=j+1) 
	{
		cout << rigag[j];
	}
	cout << endl;
}
