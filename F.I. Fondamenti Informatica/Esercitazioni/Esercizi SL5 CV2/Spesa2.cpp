/*
Il software incluso nei registratori di cassa prevede anche la struttura per la 
memorizzazione di un singolo scontrino per volta. Uno scontrino è un elenco di 
articoli di dimensione non nota a priori. Per ogni articolo è noto il codice 
numerico (univoco), il prezzo unitario, la quantità acquistata e una breve 
descrizione dell’articolo (max 30 caratteri). L’addetto alla cassa inserisce i 
prodotti acquistati uno alla volta (si supponga che il prodotto venga passato 
sopra un lettore di codice a barre), ma il software deve memorizzare i prodotti 
una sola volta, eventualmente con una quantità diversa da 1.
Si realizzino la funzione AggiungiArticolo e la stampa dello scontrino.
La prima funzione deve inserire un nuovo articolo nello scontrino su cui si
sta operando se il corrispondente codice non è già presente; altrimenti la
funzione deve aumentare la quantità del prodotto considerato.
Si desidera poi la stampa a video di tutto lo scontrino (iniziando dal primo
articolo inserito) ed il totale dello stesso, ottenuto come somma di tutti
gli articoli.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXLUNGDESCR = 30;
const int TRUE = 1;
const int FALSE = 0;


//   -----   Classe ARTICOLO   -----

class Articolo  
{
	friend ostream& operator<<(ostream &out, const Articolo &);

  public:
	Articolo();
	Articolo(int code, float price, float quantity, char description[]);
	Articolo(Articolo &);
	Articolo& operator=(Articolo &);
	Articolo& operator+=(Articolo &); // a parità di Articolo somma le quantità

	int  leggiCodice() const;
	float leggiQuantita() const;
	float leggiPrezzo() const;

  private:
	int copiaStringa(char *destinazione, char *origine);   // o #include <string.h>

	int		codice;		// Valore fra 1 e 30000
	float	prezzo;
	float	quantita;	// Decimale per esprimere il peso degli articoli il cui
						// prezzo è espresso per chilo
	char	descrizione[MAXLUNGDESCR];
};


// Metodi

Articolo::Articolo()
{
	codice = -1;
	prezzo = 0;
	quantita = 0;
	descrizione[0] = '\0';		// terminatore di stringa
}

Articolo::Articolo(int code, float price, float quantity, char description[])
{
	codice = code;
	prezzo = price;
	quantita = quantity;

	// strcpy(descrizione, description);   aggiungendo   #include <string.h>
	copiaStringa(descrizione, description);
}

Articolo::Articolo(Articolo &a)
{
	codice = a.codice;
	prezzo = a.prezzo;
	quantita = a.quantita;

	// strcpy(descrizione, a.descrizione);
	copiaStringa(descrizione, a.descrizione);
}

Articolo& Articolo::operator=(Articolo &a)
{
	codice = a.codice;
	prezzo = a.prezzo;
	quantita = a.quantita;

	// strcpy(descrizione, a.descrizione);
	copiaStringa(descrizione, a.descrizione);

	return *this;
}

Articolo& Articolo::operator+=(Articolo &art)
{
	if (codice == art.codice)
		quantita += art.quantita;
	else
	{
		cout << "ERRORE: è impossibile sommare le quantità di prodotti ";
		cout << "diversi" << endl;
	}
	return *this;
}

int Articolo::leggiCodice() const
{
	return codice;
}

float Articolo::leggiQuantita() const
{
	return quantita;
}

float Articolo::leggiPrezzo() const
{
	return prezzo;
}

int Articolo::copiaStringa(char *destinazione, char *origine)
{
    int i;
	for (i=0; origine[i]!='\0'; i++)
		destinazione[i] = origine[i];
	destinazione[i] = origine[i];			// per copiare '\0'
	return 0;
}


// Funzioni friend

ostream& operator<<(ostream &out, const Articolo &art)
{
	out << setw(6) << art.codice << setw(30) << art.descrizione << setw(10);
	out	<< art.quantita << setw(10) << art.prezzo;
	return out;
}

//   Fine Classe ARTICOLO 



//   -----   Classe NODO-SCONTRINO   -----

class NodoScontrino 
{
	friend class Scontrino;
	friend ostream& operator<<(ostream &out, const Scontrino &scontr);

  public:
	NodoScontrino(Articolo &);

  private:
	Articolo elemento;
	NodoScontrino *next;
};

NodoScontrino::NodoScontrino(Articolo &art)
{
	elemento = art;   // usa overload operator= su articolo
	next = NULL;
}

//   Fine Classe NODO-SCONTRINO



//   -----   Classe SCONTRINO   -----

class Scontrino 
{
	friend ostream& operator<<(ostream &out, const Scontrino &scontr);

  public:
	Scontrino();
	Scontrino(Scontrino &scontr);   // aggiunta a scopo didattico
	~Scontrino();
	Scontrino& operator=(const Scontrino &);   // aggiunta a scopo didattico
	int aggiungiArticolo(Articolo &art);

  private:
	NodoScontrino *testaScontrino;		// Lo scontrino è una lista di articoli
	float totale;
	NodoScontrino *codaScontrino;       // è comodo per aggiungere nuovi articoli
	                                    // mantenendo lo scontrino ordinato

	int cercaArticolo(Articolo &art, NodoScontrino* &punt);
	int inserisciArticolo(Articolo &art);
};


// Metodi

Scontrino::Scontrino()
{
	testaScontrino = codaScontrino = NULL;
	totale = 0;
}

Scontrino::Scontrino(Scontrino &scontr)
{
	// Costruttore per copia - Copiare lo scontrino vuol dire copiare l'intera lista
	NodoScontrino *punt=scontr.testaScontrino;	

	while (punt != NULL)
	{
		inserisciArticolo(punt->elemento);   //inserisce nel nuovo scontrino
		punt = punt->next;
	}

	if (totale != scontr.totale)
		cout << "ERRORE: Totali diversi nella copia degli scontrini" << endl;
}

Scontrino::~Scontrino()
{
	// Distruttore - Elimina tutti gli elementi della lista
	NodoScontrino *temp, *punt;

	temp = punt = testaScontrino;
	testaScontrino = NULL;
	while (punt != NULL)
	{
		punt = punt->next;
		delete temp;
		temp = punt;
	}
}

Scontrino& Scontrino::operator=(const Scontrino &scontr)
{
	NodoScontrino *punt=scontr.testaScontrino;	

	while (punt != NULL)
	{
		inserisciArticolo(punt->elemento);
		punt = punt->next;
	}

	if (totale != scontr.totale)
		cout << "ERRORE: Totali diversi nella copia degli scontrini" << endl;
	return *this;
}

int Scontrino::aggiungiArticolo(Articolo &art)
{
	NodoScontrino *punt;

	if (cercaArticolo(art, punt))
	{
		punt->elemento += art;          // overload operator+= su Articolo
		totale += art.leggiQuantita() * art.leggiPrezzo();   
	}
	else
		inserisciArticolo(art);
	return 0;
 
}

int Scontrino::cercaArticolo(Articolo &art, NodoScontrino* &punt)
{
	punt= testaScontrino;
	while ( (punt!=NULL) && (punt->elemento.leggiCodice() != art.leggiCodice()))
		punt = punt->next;

	if (punt != NULL)
		return TRUE;
	else
		return FALSE;
}

int Scontrino::inserisciArticolo(Articolo &art)
{
	NodoScontrino *temp;

	temp = new NodoScontrino(art);
	if (testaScontrino == NULL)
		testaScontrino = codaScontrino = temp;
	else
	{
		codaScontrino->next = temp;
		codaScontrino = codaScontrino->next;
	}
	totale += art.leggiQuantita() * art.leggiPrezzo();
	return 0;
}


// Funzioni friend

ostream& operator<<(ostream &out, const Scontrino &scontr)
{
	NodoScontrino *punt=scontr.testaScontrino;

	while (punt != NULL)
	{
		out << punt->elemento << endl;     // overload operator<< su Articolo
		punt = punt->next;
	}
	out << endl << "Totale scontrino : " << scontr.totale << endl << endl;

	return out;
}

//   Fine Classe SCONTRINO



int main()
{
	Articolo art1(1, 3.4, 2, "Pane"), art2(art1), art3(2, 5.7, 1, "Salame");

	cout << art1 << endl << art2 << endl << art3 << endl << endl;
	art2 = art3;
	cout << art1 << endl << art2 << endl << art3 << endl << endl;

	Scontrino s2;
	{
		Scontrino s1;
		s1.aggiungiArticolo(art1);
		s1.aggiungiArticolo(art3);
		s1.aggiungiArticolo(art2);
		cout << "Stampa scontrino: " << endl;
		cout << s1 << endl;

		s2 = s1;
	}
	s2.aggiungiArticolo(art1);
	cout << "Stampa secondo scontrino: " << endl;
	cout << s2 << endl;

	return 0;

}
