
/* Programma che gestisce una tabella sequenziale ordinata con:
 * Inizializzazione;
 * Inserimento di un nuovo elemento, se non esiste ancora;
 * Eliminazione di un elemento, se esiste;
 * Stampa della tabella, con il solo campo chiave;
 */
#include <iostream>
#include <iomanip>
using namespace std;

const int FALSO = 0;
const int VERO = 1;
struct Data
{
	int giorno,   // 1-31
	    mese,     // 1-12
	    anno;     // 00-99
};
const int MAXIDENT = 10;
struct Studente 
{ 
	int matricola;
	char cognome[MAXIDENT],
	     nome[MAXIDENT],
	     sesso;  // M,F
	Data dataNascita;
};
const int DIM = 8;
struct InsStudenti 
{
	int num;                  // numero di righe significative
	Studente elenco[DIM];
};

InsStudenti inizializzaTabella();
void inserisciSeNonEsiste(Studente, InsStudenti &);
void eliminaSeEsiste(int,InsStudenti &);
void cercaSeEsisteEPosizione(int, InsStudenti &,int &, int &);
void stampaTabella(InsStudenti &);

void main()
{ 
	const char INSERISCI = 'i';
	const char ELIMINA = 'e';
	const char FINE = 'f';
	char operazione ;       // operazione da effettuare sulla tabella
	Studente nuovoStudente; // dati dello studente da inserire
	int matricola;          // matricola dello studente da eliminare
	InsStudenti classe;
	//inizializzazione della tabella
	classe = inizializzaTabella();
	stampaTabella(classe);
	//acquisizione e gestione delle operazioni sulla tabella
	//intestazione in uscita
	cout << setw(50) << "acquisizione operazioni" << endl << endl;
	//acquisizione di operazione per prima rilevazione
	cout << "operazione? ( i per inserimento,"
		 <<              " e per eliminazione,"
		 <<              " f per fine"        << " ): ";
	cin >> operazione;
	while (operazione != FINE)
    {
		if (operazione == INSERISCI) 
		{ //lettura dei dati del nuovo studente
			cout << " dati del nuovo studente" << endl;
			cout << " matricola: "; cin >> nuovoStudente.matricola;
			cout << " cognome: "; cin >> nuovoStudente.cognome;
			cout << " nome: "; cin >> nuovoStudente.nome;
			cout << " sesso( M/F ): "; cin >> nuovoStudente.sesso;
			cout << " giorno di nascita (1-31): ";
			cin >> nuovoStudente.dataNascita.giorno;
			cout << " mese di nascita (1-12): ";
			cin >> nuovoStudente.dataNascita.mese;
			cout << " anno di nascita (0-99): ";
			cin >> nuovoStudente.dataNascita.anno;
            inserisciSeNonEsiste(nuovoStudente,classe);
            stampaTabella(classe);
        }
        else if (operazione == ELIMINA)
        { //lettura matricola studente da eliminare
			cout << " matricola studente da eliminare: ";
			cin >> matricola; 
			eliminaSeEsiste(matricola,classe);
			stampaTabella(classe);
        }

		//acquisizione di prossima operazione
        cout << "operazione? ( i per inserimento,"
				<< " e per eliminazione,"
				<< " f per fine" << " ): ";
		cin >> operazione;
	};
}

InsStudenti inizializzaTabella()
{ 
	InsStudenti tab = 
	{
		4,
		{
			{7, "rossi", "marco",'M',{5,10,76}},
			{48,"verdi", "anna", 'F',{4, 7,75}},
			{63,"neri",  "remo", 'M',{5, 8,76}},
			{84,"gialli","carla",'F',{5,11,75}}
		}
	};
	return tab;
}

void cercaSeEsisteEPosizione(int dato, InsStudenti &tab,
								int &esiste, int &pos)
/* cerca in tab se esiste uno studente con matricola uguale a dato:
 * - se SI (caso utile in eliminazione)
 *   esiste assume valore VERO,
 *   pos individua lo studente precedente.
 *   Se lo studente con matricola uguale a dato e' in prima posizione,
 *   pos assume convenzionalmente il valore -1.
 * - se NO (caso utile in inserimento)
 *   esiste assume valore FALSO,
 *   pos individua lo studente dopo il quale deve essere inserito
 *   il nuovo studente per mantenere l'ordinamento.
 *   Se il nuovo studente deve essere inserito in prima posizione
 *   pos assume convenzionalmente il valore -1.
 */
{
	esiste = FALSO;// fino a prova contraria si suppone che in tab non
			// esista uno studente con matricola uguale a dato.
	//gestione dei casi speciali
	//caso speciale di studente non esistente 
	//da inserire in prima posizione
	if ((tab.num == 0) ||		               // tabella vuota
		(tab.elenco[0].matricola > dato)) 
		pos = -1;
	//caso speciale di studente esistente in prima posizione
	else if (tab.elenco[0].matricola == dato) 
	{ 
		esiste = VERO;
		pos = -1;
	}
	//caso generale: pos individua un elemento della lista 
    else                                        
	{ 
		pos = 0; // si parte dal primo elemento
		int finito = FALSO;   // finché non è finita la ricerca
		while (finito == FALSO) // si esamina il successore di pos: 
		{
			if (pos == tab.num -1) // non esiste successore
				finito = VERO;
			else if (tab.elenco[pos+1].matricola == dato) 
			{
				finito = VERO;     // l'elemento cercato
				esiste = VERO;     // è quello successivo a pos
			}
			else if (tab.elenco[pos+1].matricola > dato)
				finito = VERO;       // l'elemento cercato non esiste
			else
				pos++; //la decisione se l'elemento cercato esiste
						//richiede la continuazione del ciclo a partire
						//dall'elemento successivo a pos
		}
	}
}

void inserisciSeNonEsiste(Studente nuovoStudente, InsStudenti &tab)
{ 
	int esiste, posizione;
	cercaSeEsisteEPosizione(nuovoStudente.matricola, tab, esiste, posizione);
	if ((esiste == FALSO) && (tab.num <= DIM))
	{
		cout << "inserimento di studente con matricola"
			<< setw(5) << nuovoStudente.matricola << endl;
		int temp = posizione + 1;
		for (int i = tab.num - 1; i >= temp; i--)
			tab.elenco[i + 1] = tab.elenco[i];
		tab.elenco[temp] = nuovoStudente;
		tab.num++;
	}
}

void eliminaSeEsiste(int matricola, InsStudenti &tab)
{ 
	int esiste, posizione;
	cercaSeEsisteEPosizione(matricola, tab, esiste, posizione);
	if (esiste == VERO) 
	{
		cout << "eliminazione di studente con matricola"
			<< setw(5) << matricola << endl;
		int temp = posizione + 1; //posizione dell'elemento da eliminare
		for (int i = temp + 1; i < tab.num; i++)
			tab.elenco[i - 1] = tab.elenco[i];
		tab.num--;
	}
}

void stampaTabella(InsStudenti &tab)
{ 
	int i;
	cout << " tabella con il solo campo chiave " << endl;
	for(i = 0; i< tab.num; i++)
		cout << setw(5) << tab.elenco[i].matricola;
	cout << endl << endl;
}


