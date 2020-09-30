/* Analisi del prezzo di un prodotto in una città divisa in più zone.
 * L'utente può scegliere numero e nome delle zone.
 */
#include <iostream>
#include <iomanip>
using namespace std;

void visualizzaDeviazioni(char nomeZona[], int somma, int num, int prezzi[]) 
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
			cout << setw(20)<< prezzi[i] // una riga contenente il prezzo 
					<< setw(40) << setprecision(2)// rilevato e la deviazione 
					<< setiosflags (ios::fixed | ios::showpoint) // rispetto 
					<< deviazione    // alla media, in formato fisso, con il
					<< endl;         // punto decimale e due cifre decimali
		}
	}
}

void main()
{ 
	const int MAXDIM = 100,    // massimo numero di rilevazioni per zona
			MAXZONE = 15,    // massimo numero delle zone
			MAXNOME = 10;    // massima lunghezza dei nomi delle zone
	int numZone;                            // numero delle zone
	char nomeZone[MAXZONE][MAXNOME];        // nomi delle zone
	int prezzi[MAXZONE][MAXDIM],            // prezzi rilevati per zona
		num[MAXZONE], somma[MAXZONE];         // loro numero e somma
	int zona,      // codifica dell'utente per la zona della rilevazione
					// corrente e indice che identifica il componente 
					// di ogni zona negli array somma, num, prezzi 
		prezzo;                    // prezzo della rilevazione corrente

	// acquisizione di numero e nome delle zone
	cout << "numero di zone presenti (massimo " << MAXZONE << "):";
	cin >> numZone;
	for (zona = 0; zona < numZone; zona++)
	{ 
		cout << "nome della zona denotata nel seguito"
			<< " con il numero progressivo " << zona << ": ";
		cin >> nomeZone[zona];
	}  
  
	// ciclo di acquisizione di zona e prezzo per ogni rilevazione
	for(zona = 0; zona < numZone; zona++)
	{ 
		num[zona] = 0; 
		somma[zona] = 0;
	}
	cout << setw(53) << "acquisizione   rilevazioni" << endl;
	while(1)  //ciclo di acquisizione zona e prezzo per ogni rilevazione 
	{ 
		cout << "zona della nuova rilevazione, eof se fine: ";
		cin >> zona;
		if (cin.eof())                    // se segnale di fine
			break;                            // chiudi il ciclo
		if (zona >= 0 && zona < numZone) // se la zona e' corretta
		{ 
			if (num[zona] >= MAXDIM)        // se non c'è posto
				break;                           // chiudi il ciclo
			cout << "prezzo della nuova rilevazione: "; 
			cin >> prezzo;
			somma[zona] += prezzo; 
			prezzi[zona][num[zona]] = prezzo;
			num[zona]++;
		}                   // gestisci la rilevazione
		else                             // altrimenti segnala zona
			cout << "zona non corretta: inserire nuovo valore"; // errata
	}
 
	// stampa di una tabella separata per ogni zona, con prezzo e 
	// deviazione di ogni rilevazione rispetto alla media della zona
	for (zona = 0; zona < numZone; zona++)
		visualizzaDeviazioni(nomeZone[zona], somma[zona],
								num[zona], prezzi[zona]);
}

