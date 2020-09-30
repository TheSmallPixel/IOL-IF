#include <iostream>
using namespace std;

//Programma di test

struct Nodo {
   int valore;
   Nodo *nextPtr;
} ;

// Sviluppo delle funzioni 
/*
Nodo *ricerca(Nodo *testa, int numero)
{
	Nodo *ptr = testa;

	while ((ptr != 0) && (numero != ptr->valore))
		ptr = ptr->nextPtr;

	return ptr;
}
*/

void inserimento(Nodo * &testa, int numero)
{
	// if (ricerca(testa, numero) == 0)
	// {
		Nodo *temp = new Nodo;
		temp->valore = numero;
		temp->nextPtr = 0;

		if (testa==0) 
			testa = temp;
		else
		{
			Nodo *curr=testa;
			while (curr->nextPtr!=0) 
				curr = curr->nextPtr;
			curr->nextPtr = temp;
		}
	// }
}

 
void stampa(Nodo *testa)
{
	cout << endl << endl;
	for(Nodo *ptr = testa; ptr != 0; ptr = ptr->nextPtr)
		cout << "    " << ptr->valore << endl;
}

  
/*
void invertiLista(Nodo *testa, Nodo * &testaInv)
{
	testaInv = 0;

	for(Nodo* ptr1 = testa; ptr1 != 0;  ptr1 = ptr1->nextPtr)
		inserimento(testaInv,ptr1->valore);
}
*/

//ATTENZIONE: Questa funzione distrugge la lista originaria.
/*
void invertiLista(Nodo *&testa, Nodo * &testaInv)
{
	Nodo* prec,* cur, * temp;

	if ((testa==0) || (testa->nextPtr==0)) 
		testaInv=testa;
	else
	{
		prec=testa;
		cur=testa->nextPtr;

		while(cur!=0)
		{
			temp=cur->nextPtr;
			cur->nextPtr=prec;
			prec=cur;
			cur=temp;
		}

		testaInv=prec;
		testa->nextPtr=0;
	}

	testa=0;
}
*/


// VERSIONE MIGLIORE
void invertiLista(Nodo *&testa, Nodo * &testaInv)
{
	Nodo* prec,* cur, * temp;

	if (testa==0) 
		testaInv=testa;
	else
	{
		prec=0;
		cur=testa;

		while(cur!=0)
		{       
			temp=cur->nextPtr;
			cur->nextPtr=prec;
			prec=cur;
			cur=temp;
		}
		
		testaInv=prec;
	}

	testa=0;
}


void main()
{       
	int numero;
	Nodo *lista1 = 0;
	Nodo *lista2 = 0;
	Nodo *lista3 = 0;
	int n;

	cout << endl << "Quanti numeri si vogliono " <<
             "inserire in lista1? ";
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cout << "lista1[" << i << "] = ";
		cin >> numero;
		inserimento(lista1, numero);
	}

	stampa(lista1);

	//Test di invertiLista

	invertiLista(lista1, lista3);

	cout << endl << "Stampa di lista1 al contrario" << endl;

	stampa(lista3);
}


