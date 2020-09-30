/* Programma che gestisce una tabella organizzata ad albero,
 * con l'uso della classe Tree per rappresentare la tabella
 * e di una classe TreeNode per rappresentare il singolo nodo.
 * Le operazioni ammesse sono:
 * Inserimento di un nuovo elemento, se non esiste ancora;
 * Varie modalità di attraversamento dell'albero, con stampa
 * delle informazioni in tabella, limitate al solo campo chiave.
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

const int MAXIDENT =10;
struct Studente
{
	int matricola;
	char cognome[MAXIDENT],
		nome[MAXIDENT],
		sesso;  // M,F
	Data dataNascita;
};

// Definizione della classe TreeNode

class TreeNode 
{
	friend class Tree;
public:
	TreeNode (Studente);               // costruttore
	Studente getData( );          // ritorna l'informazione contenuta
private:
	TreeNode *leftPtr;            // puntatore al sottoalbero sinistro
	Studente datiStud;
	TreeNode *rightPtr;           // puntatore al sottoalbero destro
};

// Costruttore
TreeNode:: TreeNode (Studente nuovoStudente)
{
	datiStud = nuovoStudente;
	leftPtr = rightPtr = 0;
}

// Ritorna una copia del dato contenuto
Studente TreeNode :: getData ( )  
{ 
	return datiStud; 
}


//Definizione della classe Tree
#include <iostream>
#include <iomanip>
using namespace std;

class Tree 
{
public:
	Tree ( );
	void inserisciSeNonEsiste (Studente);
	void preOrderTraversal ( );
	void inOrderTraversal ( );
	void postOrderTraversal ( );
	void stampaAlberoRovesciato( );
private:
	TreeNode*rootPtr;
	// funzioni di servizio
	void inserisciConRicorsione (TreeNode*&, Studente);
	void recursivePreOrder (TreeNode*);
	void recursiveInOrder (TreeNode*);
	void recursivePostOrder (TreeNode*);
	void stampaRovesciatoRicorsiva (TreeNode*, int);
	int  altezzaRicorsiva (TreeNode* );
	void stampaRigaAlbero (TreeNode*, int, float, int);
};

Tree::Tree ( )  
{
	rootPtr = 0;
}

void Tree::inserisciSeNonEsiste (Studente nuovoStudente)
{ 
	inserisciConRicorsione (rootPtr, nuovoStudente); 
}

void Tree::inserisciConRicorsione (TreeNode*& ptr, Studente nuovoStudente)
{
	if (ptr == 0)                                                // albero vuoto
		ptr = new TreeNode (nuovoStudente);
	else if (nuovoStudente.matricola < ptr->datiStud.matricola)  // albero 
		inserisciConRicorsione (ptr->leftPtr, nuovoStudente);       // non vuoto
	else if (nuovoStudente.matricola > ptr->datiStud.matricola)
		inserisciConRicorsione (ptr->rightPtr, nuovoStudente);
	else
		cout << "studente di matricola "  << nuovoStudente.matricola 
				<< " già presente" << endl;
}

void Tree::preOrderTraversal () 
{
	recursivePreOrder (rootPtr); 
}

void Tree::recursivePreOrder (TreeNode*ptr)
{
	if (ptr != 0)  
	{
		cout << ptr->datiStud.matricola << ' ';
		recursivePreOrder (ptr->leftPtr);
		recursivePreOrder (ptr->rightPtr);
	}
}

void Tree::inOrderTraversal ( ) 
{ 
	recursiveInOrder (rootPtr); 
}

void Tree::recursiveInOrder (TreeNode*ptr)
{
	if (ptr != 0)  
	{
		recursiveInOrder (ptr->leftPtr);
		cout << ptr->datiStud.matricola << ' ';
		recursiveInOrder (ptr->rightPtr);
	}
}

void Tree::postOrderTraversal ( ) 
{ 
	recursivePostOrder(rootPtr); 
}

void Tree::recursivePostOrder (TreeNode*ptr)
{
	if (ptr != 0)  
	{
		recursivePostOrder (ptr->leftPtr);
		recursivePostOrder (ptr->rightPtr);
		cout << ptr->datiStud.matricola << ' ';
	}
}

void Tree::stampaAlberoRovesciato ( )
{
	const int initIndent = 10;
	cout << "stato dell'albero ruotato di 90° in senso antiorario" << endl;
	stampaRovesciatoRicorsiva (rootPtr, initIndent);
}

void Tree::stampaRovesciatoRicorsiva (TreeNode*ptr, int indent)
{
	const int dataDim = 3;
	const int incrIndent = 3;
	if (ptr != 0)  
	{
		stampaRovesciatoRicorsiva (ptr->rightPtr, indent + incrIndent);
		cout << setw(indent) << "-" << setw(dataDim) 
							<< ptr->datiStud.matricola << endl;
		stampaRovesciatoRicorsiva (ptr->leftPtr, indent + incrIndent);
	}
}

// Programma di prova della classe Tree

void main()
{ 
	const char INSERISCI = 'i';
	const char FINE = 'f';
	char operazione ;       // operazione da effettuare sulla tabella
	Studente nuovoStudente; // dati dello studente da inserire
	Tree classe;
	//inizializzazione della tabella: non serve più
	classe.stampaAlberoRovesciato();
	//acquisizione e gestione delle operazioni sulla tabella
	//intestazione in uscita
	cout << setw(50) << "acquisizione operazioni" << endl << endl;
	//acquisizione di operazione per prima rilevazione
	cout << "operazione? ( i per inserimento,"
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
			classe.inserisciSeNonEsiste(nuovoStudente);
			classe.stampaAlberoRovesciato();
		}
		//acquisizione di prossima operazione
		cout << "operazione? ( i per inserimento,"
				<<                      " f per fine"        << " ): ";
		cin >> operazione;
	};
}


