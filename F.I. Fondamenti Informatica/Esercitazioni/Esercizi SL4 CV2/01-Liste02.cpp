/*
Si scriva un programma per gestire una lista ordinata di numeri interi.
Il programma deve chiedere ciclicamente l'operazione da effettuare:
inserimento di un nuovo elemento, cancellazione di un dato elemento ed
uscita dal programma.
Possono  essere inseriti più valori uguali. 
In caso di cancellazione, se il valore fornito non è presente, il programma
deve stampare un messaggio d'errore.
All'uscita dal ciclo si stampi a video il contenuto della lista prodotta.
*/

#include <iostream>
#include <iomanip>
using namespace std;

struct elemento{
   int dato;
   elemento *next;
};


elemento* cercaPrecedente(elemento*, int);
/* 
Forniti come parametri la testa della lista ed un valore, restituisce il
puntatore all'elemento il cui valore e' immediatamente minore di quello
fornito o NULL se tale elemento non esiste 
*/

int inserisciElemento(elemento* &, int);
/* 
Forniti come parametri la testa della lista, passata per riferimento, ed
il valore dell'elemento da aggiungere esegue l'inserimento del nuovo valore
nella lista mantenendo l'ordinamento
*/

elemento* puntaElemento(elemento*, int);
/* 
Forniti come parametri la testa della lista ed un valore, restituisce il
puntatore all'elemento avente tale valore o NULL se l'elemento non esiste 
*/

int cancellaElemento(elemento* &, int);
/* 
Forniti come parametri la testa della lista, passata per riferimento, ed
il valore dell'elemento da eliminare, toglie dalla lista l'elemento indicato
o stampa un messaggio d'errore se non è presente 
*/

int stampaLista(elemento *);


int main ()
{
	char risp;
	int val;
	elemento *testa=NULL;

	cout << "Programma per la gestione di una lista di interi" << endl << endl;

	do
	{
		cout << "Indicare che operazione si vuole eseguire:" << endl;
		cout << "Inserimento (i), Eliminazione (e), Uscita (u)" << endl;
		cin >> risp;
		if (risp=='i')
		{
			/* Inserimento di un nuovo elemento nella lista */
			stampaLista(testa);
			cout << "Introduci il valore dell'elemento della lista:" << endl;
			cin >> val;
			inserisciElemento(testa, val);

			stampaLista(testa);
		}
		else if (risp=='e')
		{
			/* Cancellazione di un elemento dalla lista */
			stampaLista(testa);
			cout << "Indicare il valore dell'elemento da cancellare" << endl;
			cin >> val;
			cancellaElemento(testa, val);

			stampaLista(testa);
		} 
		else if(risp!='u')
			cout << endl << "Scelta non valida!" << endl;
   }while (risp != 'u');

   stampaLista(testa);

   return 0;
}



/* 
Forniti come parametri la testa della lista ed un valore, restituisce il
puntatore all'elemento il cui valore e' immediatamente minore di quello
fornito o NULL se tale elemento non esiste 
*/
elemento* cercaPrecedente(elemento *lista, int valore)
{
	elemento *prec, *punt;

	prec=NULL;
	for (punt=lista; punt!=NULL; punt=punt->next)
	{
		if (punt->dato < valore)	 //  equivale a: (*punt).dato < valore;
			prec=punt;
		else
	        return prec;
	}
	return prec;
}



/* 
Forniti come parametri la testa della lista, passata per riferimento, ed
il valore dell'elemento da aggiungere esegue l'inserimento del nuovo valore
nella lista mantenendo l'ordinamento
*/
int inserisciElemento(elemento* &testa, int valore)
{
	elemento *nuovo, *prec;

	nuovo = new elemento;
	nuovo->dato = valore;
	
	prec = cercaPrecedente(testa, valore);
	if (prec == NULL)
	{
		nuovo->next = testa;
		testa = nuovo;
	}
	else
	{
		nuovo->next = prec->next;
		prec->next = nuovo;
	}

	return 0;
}



/* 
Forniti come parametri la testa della lista ed un valore, restituisce il
puntatore all'elemento avente tale valore o NULL se l'elemento non esiste 
*/
elemento* puntaElemento(elemento* lista, int valore)
{
	while (lista != NULL)
		if (lista->dato < valore)
			lista=lista->next;
		else
			if (lista->dato == valore)
				return lista;
			else
				return NULL;
	
    return lista;
}



/* 
Forniti come parametri la testa della lista, passata per riferimento, ed
il valore dell'elemento da eliminare, toglie dalla lista l'elemento indicato
o stampa un messaggio d'errore se non è presente 
*/
int cancellaElemento(elemento* &testa, int valore)
{
	elemento *bersaglio, *prec;


	if (testa != NULL)
	{
		bersaglio = puntaElemento(testa, valore);
		if (bersaglio != NULL)
		{
			prec = cercaPrecedente(testa, valore);
			if (prec == NULL)
				testa = bersaglio->next;
			else
				prec->next = bersaglio->next;
			delete bersaglio;
		}
		else
			cout << endl << "Errore: l'elemento non e' presente" << endl;
	}
	else
		cout << endl << "Errore: la lista e' vuota" << endl;
	return 0;
}



int stampaLista(elemento *punt)
{
	cout << "La lista e' cosi' costituita:" << endl;
	if (punt==NULL)
		cout << "-- Lista vuota --" << endl;
	else
	while (punt!=NULL)
	{
		cout << setw(5) << punt->dato;
		punt=punt->next;
	}
	cout << endl << endl;
	
	return 0;
}
