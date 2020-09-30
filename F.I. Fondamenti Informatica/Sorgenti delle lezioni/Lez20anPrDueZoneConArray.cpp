// Analisi del prezzo di un prodotto in una città divisa in due zone.
// Versione con uso di sottoprogrammi.
// Versione con uso di array di zone
#include <iostream>
#include <iomanip>
using namespace std;

void visualizzaDeviazioni
			(const char nomeZona[], int somma, int num, const int  prezzi[])
{ 
	float media, deviazione;
	int i;
	if (num != 0)                   // se c'è almeno una rilevazione 
	{ 
		cout << endl << setw(20) 
			<< "rilevazioni    zona "// crea intestazione 
			<< setw(10) << nomeZona << endl << endl // tabella per zona
			<< setw(20) << "prezzi rilevati"        // di nome nomeZona
			<< setw(40) << "deviazione rispetto al prezzo medio" << endl;
		media = (float)somma / num;     // ne calcola il prezzo medio
		for (i = 0; i < num; i++)       // per ogni rilevazione, stampa: 
        { 
			deviazione = prezzi[i] - media;   
			cout <<setw(20)<< prezzi[i] // una riga contenente il prezzo
				<< setw(40) << setprecision(2)// rilevato e la deviazione 
				<< setiosflags (ios::fixed | ios::showpoint) // rispetto 
				<< deviazione    // alla media, in formato fisso, con il
				<< endl;         // punto decimale e due cifre decimali
		}
	}
}


void main()
{ 
	// const char CENTRO = 'c', PERIFERIA = 'p';
	const int MAXNOME = 10;
	const char nomeZone[2][MAXNOME] = {"centro", "periferia"};
	const int MAXDIM = 100;
	// char zona;                  // zona della rilevazione corrent
	int zona;
	int prezzo,                     // prezzo della rilevazione corrente
	// prezziC[MAXDIM],prezziP[MAXDIM],// prezzi rilevati nelle due zone
	prezzi[2][MAXDIM],
	//numC,numP,sommaC,sommaP;//numero e somma dei prezzi delle due zone
	num[2], somma[2];

	cout << setw(53) << "acquisizione   rilevazioni" << endl;

	// numC = 0; numP = 0; sommaC = 0; sommaP = 0;
	for(zona = 0; zona < 2; zona++)
	{ 
		num[zona] = 0; 
		somma[zona] = 0;
	}

	while(1) // ciclo di acquisizione zona e prezzo per ogni rilevazione 
	{ 
		cout << "zona della nuova rilevazione: "; 
		cin >> zona;
		//if (cin.eof()|| (zona == CENTRO && num[CENTRO] >= MAXDIM)    
		//           || (zona == PERIFERIA && num[PERIFERIA] >= MAXDIM))
		if (cin.eof()|| (zona >= 0 && zona < 2 
						&& num[zona] >= MAXDIM))
			break;
		//if (zona == CENTRO || zona == PERIFERIA)
		if (zona >= 0 && zona < 2)
		{ 
			cout << "prezzo della nuova rilevazione: "; 
			cin >> prezzo;
			//if (zona == CENTRO)
			//  { somma[CENTRO] += prezzo;
			//    prezzi[CENTRO][num[CENTRO]] = prezzo; 
			//    num[CENTRO]++; 
			//  }
			//if (zona == PERIFERIA)
			//  { somma[PERIFERIA] += prezzo; 
			//    prezzi[PERIFERIA][num[PERIFERIA]] = prezzo;
			//    num[PERIFERIA]++; 
			//  }
			somma[zona] += prezzo;
			prezzi[zona][num[zona]] = prezzo;
			num[zona]++;
		}
		else
			cout << "zona non corretta: inserire nuovo valore";
	}

	//visualizzaDeviazioni("centro", sommaC, numC, prezziC);
	//visualizzaDeviazioni("periferia", sommaP, numP, prezziP);
	for (zona = 0; zona < 2; zona++)
		visualizzaDeviazioni(nomeZone[zona], somma[zona],
						num[zona], prezzi[zona]);
}

