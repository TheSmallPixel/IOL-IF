// Analisi del prezzo di un prodotto in una città divisa in due zone.

#include <iostream>
#include <iomanip>
using namespace std;

void main()
{ 
	const char CENTRO = 'c', PERIFERIA = 'p';
	const int MAXDIM = 100;
	char zona;                          // zona della rilevazione corrente
	int prezzo,                         // prezzo della rilevazione corrente
		prezziC[MAXDIM], prezziP[MAXDIM],  // prezzi rilevati nelle due zone
		numC,numP, sommaC,sommaP,  // numero e somma dei prezzi delle due zone
		i;
	float media, deviazione;

	cout << setw(53) << "acquisizione   rilevazioni" << endl;
	numC = 0; numP = 0; sommaC = 0; sommaP = 0;
	while(1)         // ciclo di acquisizione zona e prezzo per ogni rilevazione 
	{ 
		cout << "zona della nuova rilevazione: "; 
		cin >> zona;
		if (cin.eof() || (zona == CENTRO && numC >= MAXDIM)    
						|| (zona == PERIFERIA && numP >= MAXDIM))
			break;
		if (zona == CENTRO || zona == PERIFERIA)
		{ 
			cout << "prezzo della nuova rilevazione: "; 
			cin >> prezzo;
			if (zona == CENTRO)
			{ 
				sommaC += prezzo; 
				prezziC[numC] = prezzo; 
				numC++; 
			}
			if (zona == PERIFERIA)
			{ 
				sommaP += prezzo; 
				prezziP[numP] = prezzo; 
				numP++; 
			}
		}
		else
			cout << "zona non corretta: inserire nuovo valore";
	}
	
	if (numC != 0)           // se c'è almeno una rilevazione della zona centro
	{ 
		cout << endl << setw(20) << "rilevazioni    zona "// crea intestazione 
				<< setw(10) << "centro" << endl << endl     // tabella
				<< setw(20) << "prezzi rilevati"            // per zona centro
				<< setw(40) << "deviazione rispetto al prezzo medio" << endl;
		media = (float)sommaC / numC;           // ne calcola il prezzo medio
		for (i = 0; i < numC; i++)   // per ogni rilevazione del centro, stampa: 
		{ 
			deviazione = prezziC[i] - media;   
			cout << setw(20) << prezziC[i]  // una riga contenente il prezzo 
				<< setw(40) << setprecision(2)// rilevato e la deviazione rispetto 
				<< setiosflags (ios::fixed | ios::showpoint) // alla media, in
				<< deviazione                 // formato fisso,sempre con il punto
				<< endl;                      // decimale e due cifre decimali
		}
	}

	if (numP != 0)                          // idem per la  periferia
	{ 
		cout << endl << setw(20) << "rilevazioni    zona " 
			<< setw(10) << "periferia" << endl << endl
			<< setw(20) << "prezzi rilevati"         
			<< setw(40) << "deviazione rispetto al prezzo medio" << endl;
		media = (float)sommaP / numP;
		for (i = 0; i < numP; i++) 
		{ 
			deviazione = prezziP[i] - media;
			cout << setw(20) << prezziP[i]
				<< setw(40) << setprecision(2)
				<< setiosflags (ios::fixed | ios::showpoint)
				<< deviazione << endl;
		}
	}
}

