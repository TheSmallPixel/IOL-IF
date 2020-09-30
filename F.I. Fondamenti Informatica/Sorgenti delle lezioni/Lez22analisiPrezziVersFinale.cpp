/* Analisi del prezzo di un prodotto in una città divisa in più zone.
 * L'utente può scegliere numero e nome delle zone.
 * Versione con utilizzo massiccio delle funzioni
 */
#include <iostream>
#include <iomanip>
using namespace std;

const int MAXDIM = 100,            // massimo numero di rilevazioni per zona
			MAXZONE = 15,            // massimo numero delle zone
			MAXNOME = 10;            // massima lunghezza dei nomi delle zone
  
void scegliZone(int & numZone, char nomeZone[][MAXNOME]);
void acquisisciRilevazioni(int numZone, 
				int num[], int somma[], int prezzi[][MAXDIM]);
void stampaIntestazione(const char nomeZona[]);
void calcolaDeviazioni(int somma, int num, const int prezzi[],
				float deviazioni[]);
void stampaDeviazioni(int num, const int prezzi[], const float deviazioni[]);

int main()
{
	int numZone;                          // numero delle zone
	char nomeZone[MAXZONE][MAXNOME];      // nomi delle zone
	int prezzi[MAXZONE][MAXDIM],          // prezzi rilevati per zona
		num[MAXZONE], somma[MAXZONE];       // loro numero e somma
	float deviazioni[MAXZONE][MAXDIM];
	int zona;                         // codifica dell'utente per la zona
	scegliZone(numZone, nomeZone);
	acquisisciRilevazioni(numZone, num, somma, prezzi);
	for (zona = 0; zona < numZone; zona++)// per ogni zona
		if(num[zona] != 0)                // se c'è almeno una rilevazione 
		{
			stampaIntestazione(nomeZone[zona]); // calcola e stampa la tabella
			calcolaDeviazioni(somma[zona], num[zona], prezzi[zona], 
								deviazioni[zona]);   // della zona
			stampaDeviazioni(num[zona], prezzi[zona], deviazioni[zona]);
		}
	return 0;
}

void scegliZone(int & numZone, char nomeZone[][MAXNOME])
{
	int zona;
	cout << "numero di zone presenti (massimo " << MAXZONE << "):";
	cin >> numZone;
	for (zona = 0; zona < numZone; zona++)
	{ 
		cout << "nome della zona denotata nel seguito con il numero progressivo "
			<< zona << ": ";
		cin >> nomeZone[zona];
	}  
}

void acquisisciRilevazioni(int numZone, 
                           int num[], int somma[], int prezzi[][MAXDIM])
{ 
	int zona;
	for(zona = 0; zona < numZone; zona++)
    {
		num[zona] = 0; somma[zona] = 0;
    }
	cout << setw(53) << "acquisizione   rilevazioni" << endl;
	while(1)         // ciclo di acquisizione zona e prezzo per ogni rilevazione 
    {
		cout << "zona della rilevazione, eof se fine: ";
		cin >> zona;
		if (cin.eof())  // se incontri il segnale di fine
			break;       	// o superi la capienza dell'array, interrompi il ciclo
		if (zona >= 0 && zona < numZone)       // se la zona e' corretta
		{
			if (num[zona] >= MAXDIM) break;
			cout << "prezzo della nuova rilevazione: ";
			cin >> prezzi[zona][num[zona]];      // gestisci la rilevazione
			somma[zona] += prezzi[zona][num[zona]]; num[zona]++;
		}                    
		else                                   // altrimenti segnala un errore
			cout << "zona non corretta: inserire nuovo valore" << endl;
    }
}

void stampaIntestazione(const char nomeZona[])
{
	cout << endl << setw(20) << "rilevazioni    zona "// crea intestazione 
		<< setw(10) << nomeZona << endl << endl        // tabella per zona
		<< setw(20) << "prezzi rilevati"               // di nome nomeZona
		<< setw(40) << "deviazione rispetto al prezzo medio" << endl;
}

void calcolaDeviazioni(int somma, int num, const int prezzi[],
                       float deviazioni[])
{ 
	float media;
	int i;
	media = (float)somma / num;             // calcola il prezzo medio
	for (i = 0; i < num; i++)               // per ogni rilevazione 
		deviazioni[i] = prezzi[i] - media;       //calcola lo scarto
}

void stampaDeviazioni(int num, const int prezzi[], const float deviazioni[])
{
	int i;
	for (i = 0; i < num; i++)       // per ogni rilevazione:  
    {
		cout << setw(20) << prezzi[i]    // stampa una riga contenente il prezzo 
			<< setw(40) << setprecision(2)// rilevato e la deviazione rispetto 
			<< setiosflags (ios::fixed | ios::showpoint)      // alla media, in
			<< deviazioni[i]              // formato fisso, sempre con il punto
			<< endl;                      // decimale e due cifre decimali
	}
}
