/*
Costruire una funzione che ordini in modo crescente la lista di numeri interi
ricevuta come parametro d'ingresso.
Costruire poi una seconda funzione che, ricevendo in ingresso due liste di 
numeri interi ordinate in modo crescente, costruisca una nuova lista ordinata 
in cui compaiono tutti gli elementi delle liste iniziali, evitando la 
ripetizione dei dati.
Es.: date   4 76 234 300 456
  		    5 27 56 300 500
si ottenga  4 5 27 56 76 234 300 456 500
*/


#include <iostream>
#include <iomanip>
using namespace std;

struct elemento {
	int dato;
	elemento *next;
	};



//Elimina un elemento dalla lista di origine e restituisce il
//puntatore all'elemento stesso
elemento *togliElemento(elemento *&testa);

//Restituisce il puntatore all'elemento precedente il punto di inserimento
//del valore indicato (secondo il criterio di ordinamento crescente)
elemento *cercaPrecedente(elemento *testa, int valore);

//Passati il blocco contenente il dato e il puntatore dell'elemento precedente
//il punto di inserimento, effettua inserimento dell'elemento
int aggiungiInLista(elemento *&testa, elemento *blocco, elemento *prec);


//Elimina uno ad uno gli elementi dalla lista di origine, cerca la posizione
//nella nuova lista (ordinata), inserisce l'elemento nella nuova lista ordinata
int ordinaLista(elemento *&testa);


//Fornite come parametri le teste di due liste, crea una nuova lista che e'
//l'unione delle due e ne restituisce il puntatore alla testa 
elemento *unione(elemento *testa1, elemento *testa2);

//Fornito come parametro un valore, crea un nuovo elemento avente tale valore
//e restituisce un puntatore a tale elemento
elemento *creaBlocco(int dato);


/* FUNZIONI AUSILIARIE */

//Forniti come parametri la testa della lista ed un valore, aggiunge alla
//lista un nuovo elemento avente il valore passato e restituisce il puntatore
//alla testa della lista
int aggiungiInTesta(elemento *&, int);

//Stampa gli elementi della lista a cui punta il puntatore passato
int stampa(elemento *, char []);


int main (void)
{
   elemento *lista1=NULL, *lista2=NULL, *testa;

   /* costruzione della prima lista */
   aggiungiInTesta(lista1, 4);
   aggiungiInTesta(lista1, 300);
   aggiungiInTesta(lista1, 76);
   aggiungiInTesta(lista1, 234);
   aggiungiInTesta(lista1, 456);
   stampa(lista1, "lista1 d'origine");
   ordinaLista(lista1);
   stampa(lista1, "lista1 ordinata");

   /* costruzione della seconda lista */
   aggiungiInTesta(lista2, 5);
   aggiungiInTesta(lista2, 56);
   aggiungiInTesta(lista2, 300);
   aggiungiInTesta(lista2, 27);
   aggiungiInTesta(lista2, 500);
   stampa(lista2, "lista2 d'origine");
   ordinaLista(lista2);
   stampa(lista2, "lista2 ordinata");

   testa = unione(lista1, lista2);
   stampa(testa, "lista unione delle due");
   
   return 0;
}



elemento *togliElemento(elemento *&testa)
{
	elemento *temp;

	temp = testa;
	testa = testa->next;
	return temp;
}


elemento *cercaPrecedente(elemento *testa, int valore)
{
	elemento *prec=NULL;
	elemento *temp=testa;
	bool minore=true;

	while ((temp != NULL) && minore)
	{
		if (temp->dato >= valore)
			minore = false;
		else
		{
			prec = temp;
			temp = temp->next;
		}
	}
	return prec;
}


int aggiungiInLista(elemento *&testa, elemento *blocco, elemento *prec)
{
	if (prec == NULL)
	{
		blocco->next = testa;
		testa = blocco;
	}
	else
	{
		blocco->next = prec->next;
		prec->next = blocco;
	}
	return 0;
}


/*
ordinaLista(elemento *&)
{
	while lista non è finita
	{
		togli un elemento dalla lista in ingresso
		individua l'elemento precedente nella nuova lista ordinata
		aggiungi tale elemento nella nuova lista ordinata
	}
}
*/

int ordinaLista(elemento *&testa)
{
	elemento *nuova=NULL, *temp, *prec;

	while (testa != NULL)
	{
		temp = togliElemento(testa);
		prec = cercaPrecedente(nuova, temp->dato);
		aggiungiInLista(nuova, temp, prec);
	}
	testa = nuova;

	return 0;
}

elemento *creaBlocco(int dato)
{
   elemento *punt;

   punt = new (elemento);
   punt->dato = dato;
   punt->next = NULL;
   return punt;
}


/*
elemento * unione(elemento * testa1, elemento * testa2)
{
    while ci sono elementi nelle due liste
    {
        considera il valore minore
        crea un nuovo elemento avente tale valore
		individua l'elemento precedente nella nuova lista ordinata
		aggiungi tale elemento nella nuova lista ordinata
    }
}
*/

elemento *unione(elemento *testa1, elemento *testa2)
{
	elemento *punt1, *punt2;
	elemento *testa3 = NULL;
	elemento *temp, *coda=NULL;
	int dato;

	punt1 = testa1;
	punt2 = testa2;

	while(punt1!=NULL && punt2 != NULL)
	{
		if (punt1->dato < punt2->dato)
		{
			dato = punt1->dato;
			punt1 = punt1->next;
		}
		else
		{
			dato = punt2->dato;
			if (punt1->dato == punt2->dato)
				punt1 = punt1->next;
			punt2 = punt2->next;
		}
		temp = creaBlocco(dato);

		if (coda==NULL)
			testa3 = coda= temp;
		else
		{
			coda->next = temp;
			coda = coda->next;
		}
	}

	while (punt1 != NULL)
	{
		temp = creaBlocco(punt1->dato);
		coda->next = temp;
		coda = coda->next;
		punt1 = punt1->next;
	}

	while (punt2 != NULL)
	{
		temp = creaBlocco(punt2->dato);
		coda->next = temp;
		coda = coda->next;
		punt2 = punt2->next;
	}

   return testa3;
}


int aggiungiInTesta(elemento *&lista, int dato)
{
   elemento *punt;

   punt = new(elemento);
   punt->dato = dato;
   punt->next = lista;
   lista = punt;
   return 0;
}


int stampa(elemento *inizio, char testo[])
{
   elemento *punt;

   cout << "Stampa dei dati presenti nella "<< testo <<":" << endl;
   for(punt=inizio; punt!=NULL; punt=punt->next)
      cout << punt->dato << setw(5);
   cout << endl << endl;
   return 0;
}
