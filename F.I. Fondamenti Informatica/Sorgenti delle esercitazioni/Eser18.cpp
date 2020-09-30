#include <iostream>
#include <iomanip>
using namespace std;

//Tipo nodo della lista
struct nodo {
	int info;
	nodo* next;
};

//Prototipi delle funzioni
//Funzioni di utilità

void inserimentoInCoda(int valore, nodo* &testa);

//Funzioni da sviluppare

void stampaIterativa(nodo* testa);
void stampaRicorsiva(nodo* testa);
void distruggiIterativa(nodo* testa);
void distruggiRicorsiva(nodo* testa);


//Sviluppo delle funzioni

void inserimentoInCoda(int valore, nodo* &tLista)
{
	nodo* ptr;     //cursore utilizzato per identificare l'ultimo nodo
	nodo* temp=new nodo;    //creazione del nuovo nodo da inserire
	temp->info=valore;
	temp->next=0;          //comunque il nuovo nodo sarà l'ultimo

	if(tLista==0) 
		tLista=temp;           //lista vuota
	else 
	{                               //almeno un nodo
		for (ptr=tLista; ptr->next!=0; ptr=ptr->next); //scorri la lista per
										//posizionare ptr sull'ultimo nodo
		ptr->next=temp;                    //aggancia il nuovo nodo in coda
	}
}


void stampaIterativa(nodo* testa)
{
	int numElementi=0;

	for (nodo* ptr=testa; ptr!=0; ptr=ptr->next)    //conto il numero di elementi
		numElementi++;

	if (numElementi==0) 
	{                           //tratto il caso particolare di lista vuota
		cout<<endl<<"Lista Vuota";
		return;
	}

	int numDiscese=numElementi-1;   //numero di volte che devo scendere nella lista
									//per arrivare all'elemento da stampare corrente
	do 
	{
		nodo* daStampare = testa;            //parto dalla testa
		for (int i=0;i<numDiscese;i++)     //discendo a recuperare il prossimo nodo da
												//stampare
			daStampare=daStampare->next;
		cout << setw(4) << daStampare->info;   //stampo il valore del nodo corrente
		numDiscese--;                      //decremento il prossimo numero di discese
	} while (numDiscese>=0);        //finché ci sono nodi da raggiungere e stampare
}


void stampaRicorsiva(nodo* testa)
{
	if (testa==0)                  //lista vuota
		cout << endl << "Lista Vuota";
	else 
	{                              //lista piena
		if (testa->next!=0)  
			stampaRicorsiva(testa->next); //se esiste un successore->passo
											//ricorsivo
		cout << setw(4) << testa->info;    //stampo nodo corrente
	}
}


/* Funzioni di disallocazione dei nodi di una lista                                    *
* Attenzione: non si può partire a deallocare dal primo nodo della lista senza salvare *
* il successivo                                                                        */

void distruggiIterativa(nodo* testa)
{
	nodo* cur=testa, *temp;   //Attenzione * si ripete davanti ad ogni variabile puntatore
	while(cur!=0)
	{
		temp=cur;                          //salvo l'indirizzo del nodo corrente
		cur=cur->next;                     //avanzo lungo la lista
		cout << endl << "Ora distruggo il nodo con valore:" << setw(4) << temp->info;
		delete temp;                       //distruggo il nodo precedente a quello corrente
	}
}


void distruggiRicorsiva(nodo* testa)
{
	if (testa==0) 
		cout << endl << "Lista Vuota";     //base della ricorsione
	else 
	{
		distruggiRicorsiva(testa->next);   //passo ricorsivo (effettuato anche su lista 
											//vuota!)
		cout << endl << "Ora distruggo il nodo con valore:" << setw(4) << testa->info;
		delete testa;
	}
}


void main(void)
{
	//Programma di test
	nodo* listaDiProva=0;                //Testa va inizializzata a 0
	int valore;                          //Valore da inserire in lista

	//Ciclo di interazione con l'utente per creare una lista di prova
	cout << endl << endl << "Programma di stampa a ritroso di una lista";
	do
	{
		cout << endl << "Inserisci il valore di un elemento (0 per terminare): ";
		cin >> valore;
		if(valore!=0) 
			inserimentoInCoda(valore,listaDiProva);
	}
	while (valore!=0);     //Il valore 0 funge da comando di uscita dal ciclo

	//Verifica delle funzioni
	cout << endl << "Prova della funzione di stampa iterativa" << endl;
	stampaIterativa(listaDiProva);
	cout << endl << "Prova della funzione di stampa ricorsiva" << endl;
	stampaRicorsiva(listaDiProva);
	cout << endl << endl << "verifica della funzione distruggi" << endl;
	cout << endl << "Usare la funzione di distruzione iterativa (1) o ricorsiva (2)?";
	cin >> valore;
	if (valore == 1)
		distruggiIterativa(listaDiProva);
	else
		distruggiRicorsiva(listaDiProva);
}
