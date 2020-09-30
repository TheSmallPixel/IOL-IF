/* Programma che gestisce una tabella non sequenziale ordinata
 * creata con l'utilizzo dei puntatori mediante:
 * Inizializzazione;
 * Inserimento di un nuovo elemento, se non esiste ancora;
 * Eliminazione di un elemento, se esiste;
 * Stampa della tabella, con il solo campo chiave;
 * Viene evidenziata la differenza rispetto alla gestione sequenziale
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

/* const int DIM = 8;
 * struct InsStudenti 
 * { 
 *	int num;                  // numero di righe significative
 *	Studente elenco[DIM];
 * };
 */
struct Nodo
{ 
	Studente datiStud;
    Nodo* nextPtr;
};

 /* InsStudenti */ Nodo* inizializzaTabella();
void inserisciSeNonEsiste(Studente, Nodo* &);
void eliminaSeEsiste(int, Nodo* &);
void cercaSeEsisteEPosizione(int, Nodo* &,int &, /* int */ Nodo* &);
void stampaTabella(Nodo* &);

void main()
{
	const char INSERISCI = 'i';
	const char ELIMINA = 'e';
	const char FINE = 'f';
	char operazione ;       // operazione da effettuare sulla tabella
	Studente nuovoStudente; // dati dello studente da inserire
	int matricola;          // matricola dello studente da eliminare
	/* InsStudenti */ Nodo* classe;// Tabella organizzata a lista non 
				// sequenziale definita dal puntatore al primo studente
	//inizializzazione della tabella
	classe = inizializzaTabella();
	stampaTabella(classe);
	//acquisizione e gestione delle operazioni sulla tabella
	//intestazione in uscita
	cout << setw(50) << "acquisizione operazioni" << endl << endl;
	//acquisizione di operazione per prima rilevazione
	cout << "operazione? ( i per inserimento,"
		<<                " e per eliminazione,"
		<<                " f per fine"        << " ): ";
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

/* InsStudenti */ Nodo* inizializzaTabella()
{ 
/* InsStudenti tab = 
			{
				4,
				{
					{7, "rossi", "marco",'M',{5,10,76}},
					{48,"verdi", "anna", 'F',{4, 7,75}},
					{63,"neri",  "remo", 'M',{5, 8,76}},
					{84,"gialli","carla",'F',{5,11,75}}
				}
			};
*/ 
	return /* tab */ 0;
}

void cercaSeEsisteEPosizione(int dato, Nodo* &tab,
								int &esiste, /* int */ Nodo* &pos)
/* cerca in tab se esiste uno studente con matricola uguale a dato:
 * - se SI (caso utile in eliminazione)
 *   esiste assume valore VERO,
 *   pos individua lo studente precedente.
 *   Se lo studente con matricola uguale a dato e' in prima posizione,
 *   pos assume convenzionalmente il valore 0 (NULL).
 * - se NO (caso utile in inserimento)
 *   esiste assume valore FALSO,
 *   pos individua lo studente dopo il quale deve essere inserito
 *   il nuovo studente per mantenere l'ordinamento.
 *   Se il nuovo studente deve essere inserito in prima posizione
 *   pos assume convenzionalmente il valore 0 (NULL).
 */
{
	esiste = FALSO;// fino a prova contraria si suppone che in tab non
					// esista uno studente con matricola uguale a dato.
	//gestione dei casi speciali

	//caso speciale di studente non esistente 
	//da inserire in prima posizione
	if ((/* tab.num */ tab == 0) ||		      //tabella vuota
		(/* tab.elenco[0] */ tab->datiStud.matricola > dato)) 
		pos = /* -1 */ 0;
	//caso speciale di studente esistente in prima posizione
	else if (/* tab.elenco[0] */ tab->datiStud.matricola == dato)
	{
		esiste = VERO;
		pos = /* -1 */ 0;
	}
	//caso generale: pos individua un elemento della lista
	else
	{
		pos = /* 0 */ tab;       //si parte dal primo elemento
		int finito = FALSO;      //finché non è finita la ricerca
		while (finito == FALSO)  //si esamina il successore di pos:
		{
			if (/* pos == tab.num -1 */ pos->nextPtr == 0)
				finito = VERO;       //non esiste successore
			else if ( /* tab.elenco[pos+1] */
						(pos->nextPtr)->datiStud.matricola == dato) 
			{
				finito = VERO;     //l'elemento cercato
				esiste = VERO;     //è quello successivo a pos
			}
			else if ( /* tab.elenco[pos+1] */
                        (pos->nextPtr)->datiStud.matricola > dato)
				finito = VERO;       //l'elemento cercato non esiste
			else
				/* pos++ */ pos = pos->nextPtr; //la decisione se 
				//l'elemento cercato esiste richiede la continuazione 
				//del ciclo a partire dall'elemento successivo a pos
		}
	}
}

void inserisciSeNonEsiste(Studente nuovoStudente, Nodo* &tab)
{ 
	int esiste /* , posizione */;
	Nodo*posizione;
	cercaSeEsisteEPosizione(nuovoStudente.matricola, tab, esiste, posizione);
	if ((esiste == FALSO) /* && (tab.num <= dim) */)
	{
		cout << "inserimento di studente con matricola"
				<< setw(5) << nuovoStudente.matricola << endl;
		/* int */ Nodo* temp;     // posizione dell'elemento da inserire
		temp = /* posizione + 1 */ new Nodo;   //creazione dell'elemento
		/* for (int i = tab.num - 1; i >= temp; i--)
			tab.elenco[i + 1] = tab.elenco[i]; 
		tab.elenco[temp] = nuovoStudente;
		tab.num++; */
		if (posizione == 0) // l'elemento da inserire va in testa
		{
			temp->nextPtr = tab;
			tab = temp;
		}
		else                // l'elemento da inserire non va in testa
		{
			temp->nextPtr = posizione->nextPtr;
			posizione->nextPtr = temp;
		}
		temp->datiStud = nuovoStudente;
	}
}

void eliminaSeEsiste(int matricola, Nodo* &tab)
{ 
	int esiste /*, posizione*/;
	Nodo* posizione;
	cercaSeEsisteEPosizione(matricola, tab, esiste, posizione);
	if (esiste == VERO) 
	{
		cout << "eliminazione di studente con matricola"
				<< setw(5) << matricola << endl;
		/* int temp = posizione + 1;
		for (int i = temp + 1; i < tab.num; i++)
			tab.elenco[i - 1] = tab.elenco[i];
		tab.num--; */
		Nodo* temp;         // posizione dell'elemento da eliminare
		if (posizione == 0) // l'elemento da eliminare è il primo 
		{
			temp = tab;
			tab = tab->nextPtr;
		}
		else	           // l'elemento da eliminare non è il primo 
		{
			temp = posizione->nextPtr;
			posizione->nextPtr = temp->nextPtr;
        }
		delete temp;
	}
}

void stampaTabella( Nodo*  &tab)
{
	/* int i */ Nodo* studPtr;
	cout << " tabella con il solo campo chiave " << endl;
	for (studPtr = /* 0 */ tab; /* i< tab.num */ studPtr != 0 ; 
						/* i++ */ studPtr = studPtr->nextPtr)
		cout << setw(5) << /* tab.elenco[i].matricola */ 
							studPtr->datiStud.matricola ;
	cout << endl << endl;
}

