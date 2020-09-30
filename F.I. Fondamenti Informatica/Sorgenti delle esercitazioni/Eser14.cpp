#include <iostream>
using namespace std;

/* ---------    Tipi definiti dall'utente   -------- */
typedef enum statoLode {YES, NO} tipoLode;			//enumerativo per la lode
typedef enum statoIscrizione {C, FC} tipoIscriz;	//enumerativo per il tipo
														//di iscrizione  

/* ---------    Dichiarazioni di costanti   -------- */
const int DIM=25;			// dimensione delle stringhe
const int N_STUD=10;		// numero massimo di studenti
								// riduciamo il numero di studenti e di esami  
const int N_ESA=5;			// numero massimo di esami per ogni studente


/* ---------           Strutture            -------- */
struct Data{				// struttura che definisce la data
	int gg, mm, aa;
};

struct recordEsame {		// struttura che definisce il record di un esame
	char nomeEsame[DIM];
	int voto;
	tipoLode lode;
	Data dataEsame;
};

struct recordStudente{		// struttura che definisce il record di uno studente
	char cognome[DIM];
	char nome[DIM];
	int matricola;
	int annoCorso;
	int esamiSostenuti;
	tipoIscriz iscrizione;
	recordEsame esami[N_ESA];
};


/* ---------    Prototipi delle funzioni   -------- */
int inserimentoStudente(recordStudente stud[], recordStudente &s, int &numS);
int ricercaStudente(recordStudente stud[], int numS , int matricola);
int inserimentoEsame(recordStudente stud[], int numS, int matricola,
		recordEsame &esame);
int esamiStudenti(recordStudente stud[], int numS, int matricola,
		int &numEsami, float &media);
float calcoloMedia(recordStudente stud[], int posiz);
void studentiConMedia(recordStudente stud[], int numS, float media);
void stampaMenu();
void leggiStringa(char stringa[]);
Data leggiData(void);
int leggiIntero(void);
float leggiReale(void);
void stampaElencoStudenti(recordStudente stud[], int numS);

/* ----------------------------------------------------------
									  MAIN
	---------------------------------------------------------- */

void main ()
{
	recordStudente studenti[N_STUD];
	int scelta;			// variabile utilizzata per la scelta delle voce del menu'
	int matr;			// matricola dello studente
	int risultato;		// variabile utilizzata per verificare se il risultato
							// delle funzioni va a buon fine o meno
	recordStudente s;	// record studente
	recordEsame e;		// record esame
	int numStudenti=0;	// numero totale di studenti attualmente memorizzati
	float media;		// media dei voti
	int numEsami;		// numero di esami sostenuti
	char str_temp[DIM];	// memorizza temporaneamente una stringa
	int temp;			// variabile utilizzata per memorizzare il valore
							// restituito da alcune funzioni

															//messaggio iniziale
	cout << endl << "Menu' per la gestione di studenti ed esami" << endl;

															//  gestione del menu
	do
	{
		stampaMenu();                           // stampa del menu
		cout << " Inserisci la scelta: ";
		scelta = leggiIntero();                 // lettura della voce scelta
															 
		switch (scelta)
		{
			case 99: break;                       // 99 - fine

			case 1:                               // 1 - inserimento studente

				cout << endl << " Inserisci matricola: ";  // inserimento dati
				s.matricola = leggiIntero();

				if (ricercaStudente(studenti, numStudenti, s.matricola) != -1)
					cout << endl << " Studente già presente" ;
				else 
				{
					cout << " Inserisci cognome: ";
					leggiStringa(s.cognome);        

					cout << " Inserisci nome: ";
					leggiStringa(s.nome);

					cout << " Inserisci anno di corso: ";
					s.annoCorso = leggiIntero();

					cout << " Inserisci iscrizione (c=in corso, f=fuori corso): ";
					do 
					{
						temp = 1;
						leggiStringa(str_temp);
						if ((temp = strcmp(str_temp,"c")) == 0)     
							s.iscrizione = C;
						else if((temp = strcmp(str_temp,"f")) == 0)
							s.iscrizione = FC;
						else
							cout << " Reinserisci valore: ";
					} while (temp != 0);

					// inizializza a 0 gli esami sostenuti
					s.esamiSostenuti = 0;

					// effettua inserimento
					if ((inserimentoStudente(studenti, s, numStudenti))==-1)
						cout << endl << " Inserimento fallito" << endl;
					else 
						cout << endl << " Inserimento effettuato" << endl;
				}

				break;

			case 2:                               // 2 - ricerca studente

				cout << endl << " Inserisci il numero di matricola: ";
				matr = leggiIntero();
				risultato = ricercaStudente(studenti, numStudenti, matr);

				if (risultato == -1)
					cout << endl << " Studente non trovato!" << endl;
				else 
				{                            // stampa dati studente
					cout << endl;
					cout << " Matricola: " << studenti[risultato].matricola << endl;
					cout << " Cognome:   " << studenti[risultato].cognome << endl;
					cout << " Nome:      " << studenti[risultato].nome << endl;
					cout << " Anno:      " << studenti[risultato].annoCorso << endl;
					cout << " C=0/FC=1:  " << studenti[risultato].iscrizione << endl;
				}
				break;

			case 3:                               // 3 - inserimento esame

				cout << endl << " Inserisci il numero di matricola: ";
				matr = leggiIntero();
				if (ricercaStudente(studenti, numStudenti, matr) == -1)
					cout << endl << " Studente non presente" ;
				else 
				{
					cout << " Inserisci il nome dell'esame: ";
					leggiStringa(e.nomeEsame);

					cout << " Inserisci il voto (18-30): ";  // si considerano solo
					do 
					{                                     // voti tra 18 e 30
						e.voto = leggiIntero();
						if ((e.voto > 30) || (e.voto < 18))
							cout << " Voto non valido. Reinserire valore : ";
					} while ((e.voto > 30) || (e.voto < 18));

					if (e.voto==30)
					{
						cout << " Lode (s=SI', n=NO): ";
						do 
						{
							temp = 1;
							leggiStringa(str_temp);
							if ((temp = strcmp(str_temp,"s")) == 0)   
								e.lode = YES;
							else if((temp = strcmp(str_temp,"n")) == 0)
								e.lode = NO;
							else
								cout << " Reinserisci valore: ";
						} while (temp != 0);
					}
					else
						e.lode=NO;

					cout << " Inserisci la data";
					e.dataEsame = leggiData();

					risultato=inserimentoEsame(studenti, numStudenti, matr, e);

					if (risultato == -1)
						cout << endl << " Inserimento fallito" << endl;
					else
						cout << endl << " Inserimento effettuato" << endl;
				}
				break;

			case 4:                               // 4 - calcolo del numero di esami
														// sostenuti e della media
				cout << endl << " Inserisci il numero di matricola: ";
				matr = leggiIntero();

				risultato=esamiStudenti(studenti, numStudenti, matr, numEsami,
												media);

				if (risultato == -1)
					cout << endl << " Lo studente non è presente";
				else 
				{
					cout << endl << " Lo studente ha sostenuto un numero di esami"
						<< " pari a " << numEsami
						<< " con la media del " << media << endl;
				}
				break;

			case 5:                               // 5 - dati degli studenti con una
														// certa media
				cout << endl << " Inserisci il valore della media: ";
				//media = leggiIntero();
				media = leggiReale();             

				studentiConMedia(studenti, numStudenti, media);
				break;

			case 6:
				stampaElencoStudenti(studenti, numStudenti);
				break;

			default:                              // per valori < 0 e > 5
				cout << endl << " Errore nell'inserimento del valore " << endl;
		}

		if (scelta != 99)                       // se non e' 99 (fine)
		{
			cout << endl;
			cout << endl << " --- Premi Invio per tornare al menu ---";
			cin.ignore(30, '\n');	// consuma eventuali caratteri e l'Invio
			cout << endl;
		}

	} while (scelta != 99);                 // ripete la visualizzazione del menu
											// finche' non si inserisce il 99
}

/* ----------------------------------------------------------
				Funzione per la stampa del menu'
	---------------------------------------------------------- */
void stampaMenu()
{
	cout << endl << " -------------------";
	cout << endl << "     Menu " ;
	cout << endl << " -------------------";
	cout << endl;
										// stampa tutte le voci
	cout << " Inserimento studente             1" << endl;
	cout << " Ricerca studente                 2" << endl;
	cout << " Inserimento esame                3" << endl;
	cout << " Media ed esami studente          4" << endl;
	cout << " Studenti con una certa media     5" << endl;
	cout << " Elenco totale studenti           6" << endl;
	cout << " Fine                            99" << endl;
	cout << endl;
}

/* ----------------------------------------------------------
		Funzione per l'inserimento del record di uno studente

	INPUT: insieme di studenti,
			record dello studente da inserire,
			numero totale di studenti presenti nell'insieme
	OUTPUT: restituisce -1 se l'inserimento non è stato effettuato,
			1 se l'inserimento è andato a buon fine
	---------------------------------------------------------- */
int inserimentoStudente(recordStudente stud[], recordStudente &s, int &numS)
{
	if (numS==(N_STUD))                        // verifica se c'e' posto
													// nell'array studenti
		return -1;                              // operazione fallita
	else
	{
		stud[numS]=s;                           // copia il record nel primo
													// posto libero
		numS++;                            // incrementa il numero di studenti
		return 1;                          // operazione con successo
	}
}

/* ----------------------------------------------------------
		Funzione per la ricerca del record di uno studente

	INPUT: insieme di studenti,
			numero totale di studenti presenti nell'insieme
			numero di matricola dello studente da ricercare
	OUTPUT: restituisce -1 se lo studente non è stato trovato,
			la posizione all'interno dell'array altrimenti
	---------------------------------------------------------- */
int ricercaStudente(recordStudente stud[], int numS , int matricola)
{
	int i = 0;
										// scansione dell'intero array fino
										// a quando non si trova la matricola
	while ((i <= numS) && (matricola != stud[i].matricola))
		i++;

	if (matricola == stud[i].matricola)      // se la matricola è stata trovata
		return i;                              //studente trovato in posizione i
	else
		return -1;                             //studente non trovato
}

/* ----------------------------------------------------------
		Funzione per l'inserimento di un esame di uno studente

	INPUT: insieme di studenti,
			numero totale di studenti presenti nell'insieme
			numero di matricola dello studente al quale inserire i
			dati dell'esame,
			record con i dati dell'esame
	OUTPUT: restituisce -1 se lo studente non è stato trovato oppure
			se l'array degli esami è esaurito, 1 altrimenti
	---------------------------------------------------------- */
int inserimentoEsame(recordStudente stud[], int numS, int matricola,
	 recordEsame &esame)
{
	int posiz;
												// ricerca dello studente
	if ((posiz = ricercaStudente(stud,numS,matricola)) == -1)   
		return -1;                               // studente non trovato
	else 
	{                                     // studente trovato
		if (stud[posiz].esamiSostenuti < N_ESA)
		{										// se il record degli esami non
												// e' pieno memorizza i dati
			stud[posiz].esami[stud[posiz].esamiSostenuti] = esame;
			stud[posiz].esamiSostenuti++;          // incrementa il numero di esami
			return 1;                              // operazione con successo
		}
		else
			return -1;                          // array esami esaurito
	}
}

/* ----------------------------------------------------------
		Funzione per il calcolo del numero di esami
		e della media degli esami di uno studente

	INPUT: insieme di studenti,
			numero totale di studenti presenti nell'insieme
			numero di matricola dello studente al quale inserire i
			dati dell'esame,
			numero di esami sostenuti dallo studente (per riferimento),
			media degli esami (per riferimento)
	OUTPUT: restituisce -1 se lo studente non è stato trovato,
			1 altrimenti
	---------------------------------------------------------- */
int esamiStudenti(recordStudente stud[], int numS, int matricola,
	  int &numEsami, float &media)
{
	int posiz;
												// ricerca dello studente
	if ((posiz = ricercaStudente(stud,numS,matricola)) == -1)
		return -1;                               // studente non trovato
	else 
	{
		numEsami=stud[posiz].esamiSostenuti;    // aggiornamento risultati
		media=calcoloMedia(stud,posiz);
		return 1;                               // studente trovato
	}
}

/* ----------------------------------------------------------
		Funzione per il calcolo della media degli esami
		di uno studente

	INPUT: insieme di studenti,
			posizione dello studente del quale calcolare la media
	OUTPUT: restituisce il valore della media degli esami dello
			studente
	---------------------------------------------------------- */
float calcoloMedia(recordStudente stud[], int posiz)
{
	int i=0, somma=0;
	while (i<stud[posiz].esamiSostenuti)
	{       // somma tutti gli esami
		somma += stud[posiz].esami[i].voto;
		i++;
	}                                     // restituisce la media
	return ((float)somma/stud[posiz].esamiSostenuti);
}

/* ----------------------------------------------------------
		Funzione che stampa l'elenco degli studenti che
		hanno una media superiore ad un valore dato

	INPUT: insieme di studenti,
			numero totale di studenti presenti nell'insieme
			valore della media
	OUTPUT: --
	---------------------------------------------------------- */
void studentiConMedia(recordStudente stud[], int numS, float media)
{
	int i;
	float mediaEsami;
	int trovato=0;

	cout << endl << endl << "   Elenco studenti:" << endl;
	for (i=0; i<numS; i++)
	{                    // per tutti gli studenti
							// verifica se la media ha un certo valore
		if ((mediaEsami=(calcoloMedia(stud,i))) > media)
		{	
										// stampa nome e cognome studente
			cout << endl << " " << stud[i].cognome << " " << stud[i].nome
				<< " media=" << mediaEsami;
			trovato=1;
		}
	}
	if (!trovato)                              // nessuno studente ha questa media
		cout << endl << " Non ci sono studenti con media superiore a " << media;
}



/* ----------------------------------------------------------
				Funzione per la lettura di una stringa
	---------------------------------------------------------- */
void leggiStringa(char stringa[])
{
	char c;
	int i = 0;

	while (1) 
	{
		while (((c = cin.peek()) != '\n') && (i < (DIM-1))) 
		{   
			stringa[i++] = cin.get();         // memorizza un carattere alla
		};                                    // volta fino a quando non viene
												// letto il carattere di invio opp.
												// fino a quando termina l'array
		if (i == 0) 
		{                             // se non sono stati inseriti
											// dei caratteri
			cin.get();                    // leggi l'ultimo carattere di
											  // invio
			cout << " Reinserire valore: ";         // rieffettua l'inserimento
		}
		else 
		{                                    // se sono stati inseriti caratteri
			if (( c != '\n') && (i == (DIM-1)))
			{    // se sono stati inseriti più di DIM caratteri
				do 
				{                                  
					cin.get();                      // leggi i caratteri rimanenti
				} while (cin.peek() != '\n');         // finchè non leggi l'invio
			}
			cin.get();                              // leggi l'ultimo carattere di
														// invio
			stringa[i] = '\0';                      // termina la stringa con il
														// terminatore di stringa 
			break;                                  // esci dal ciclo
		}
	}
}


/* ----------------------------------------------------------
				Funzione per la lettura di un intero
	---------------------------------------------------------- */
int leggiIntero(void)
{
	char stringa[DIM];
	int numero;

	do 
	{
		leggiStringa(stringa);              // lettura del numero in una
													// stringa
		numero=atoi(stringa);               // conversione della stringa in
													// numero intero    
		if (numero == 0)                          // errore nella stringa
			cout << endl << " Reinserire valore: "; // richiedi di reinserire
	} while (numero == 0);                      // il dato finchè non è corretto
	return numero;                              // restituisci il numero (corretto)
}

/* ----------------------------------------------------------
				Funzione per la lettura di un numero reale
	---------------------------------------------------------- */
float leggiReale(void)
{
	char stringa[DIM];
	float numero;

	do 
	{
		leggiStringa(stringa);                // lettura del numero in una
													// stringa
		numero=(float)atof(stringa);          // conversione della stringa in
													// numero intero    
		if (numero == 0.0)                        // errore nella stringa
			cout << endl << " Reinserire valore: "; // richiedi di reinserire
	} while (numero == 0.0);                    // il dato finchè non è corretto
	return numero;                              // restituisci il numero (corretto)
}

/* ----------------------------------------------------------
				Funzione per la lettura di una data
	---------------------------------------------------------- */
Data leggiData(void) 
{
	int giorniMese;
	Data d;
	int corretto;

	do {

		do 
		{                                     // leggi giorno
			cout << " Inserisci giorno (gg): ";
			d.gg = leggiIntero();
		} while (d.gg == 0);

		do 
		{                                     // leggi mese
			cout << " Inserisci mese (mm): ";
			d.mm = leggiIntero();
		} while (d.mm == 0);

		do 
		{                                     // leggi anno
			cout << " Inserisci anno (aaaa): ";
			d.aa= leggiIntero();
		} while (d.aa == 0);

											// controllo validità data
	corretto = 1;
	switch (d.mm) 
	{                          // determina il numero di giorni
		case 1:                                // del mese
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			giorniMese = 31;
			break;
		case 4:
		case 9:
		case 6:
		case 11:
			giorniMese = 30;
			break;
		case 2:
			if ((d.aa%4 == 0 && d.aa%100 != 0) || (d.aa % 400 == 0))  
				giorniMese = 29;                   // anno bisestile
			else
				giorniMese = 28;                   // anno non bisestile
			break;
		default:                               // se il mese non è compreso tra
			corretto = 0;                        // 1 e 12 la data non è corretta
	}
	if (corretto && !((d.gg >= 1) && (d.gg <= giorniMese)))
		corretto = 0;                          // verifica correttezza numero
													// del giorno del mese
	if (!corretto)                           // se la data non è valida
		cout << endl << " Data non valida, reinserire i dati: " << endl;
											// reinserire nuovamente i dati
	} while (!corretto);                       // ripeti finchè la data non
															// è valida
	return d;                                  // restituisci la data (corretta)
}

/* ----------------------------------------------------------
	Funzione per la visualizzazione dell'elenco degli studenti
	(non richiesta - inserita per comodità)

	INPUT: insieme di studenti,
			numero totale di studenti presenti nell'insieme
	OUTPUT: --
	---------------------------------------------------------- */
void stampaElencoStudenti(recordStudente stud[], int numS) 
{
	for (int i=0; i < numS; i++)
	{
		cout << " Matricola: " << stud[i].matricola << endl;
		cout << " Cognome:   " << stud[i].cognome << endl;
		cout << " Nome:      " << stud[i].nome << endl;
		cout << " Anno:      " << stud[i].annoCorso << endl;
		cout << " C=0/FC=1:  " << stud[i].iscrizione << endl;
		cout << "============" << endl;
	}
}
