// PI2_Longiave.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
//Cognome: Longiave
//Nome: Lorenzo
//Matricola: 959336
//Classe Virtuale: CV2
//Nota:		Visto che mi trovo bene con c++ ho iniziato a provare cose più avanzate
//			In questo caso ho cercato si separare la logica delle lista dalla logica 
//			del programma, spero non sia un problema.

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Lista riusabile con un paio di metodi riusabili
template<class TData>
struct Node {
public:
	TData *nextPtr;
	Node() : nextPtr(NULL) {}

	int Count(TData *list) {
		int DIM = 1;
		for (TData** p = &list; (*p)->HasNext(p); DIM++) {}
		return DIM;
	}

	bool HasNext(TData **next) {
		if ((*next)->nextPtr != NULL) {
			*next = (**next).nextPtr;
			return true;
		}
		return false;
	}

	virtual bool Compare(TData *item) = 0;


	//Aggiunge in maniera ricorsiva usando il metodo Compare
	void Add(TData *prev, TData *item) {
		if (!Compare(item)) {
			//se è non è maggiore allora effettuo lo swap
			item->nextPtr = (TData*)this;
			prev->nextPtr = item;
		}
		else {
			if (nextPtr != NULL) {
				//prendo l'elemento successivo
				nextPtr->Add((TData*)this, item);
			}
			else {
				//se non ho altri elementi lo inserisco infondo
				nextPtr = item;
			}
		}
	}
};

struct Contravvenzione : Node<Contravvenzione> {
public:
	int IdVigile;
	int Data;
	int Ora;
	string Targa;
	int CodInfrazione;

	Contravvenzione(int idVigile, int data, int ora, string targa, int codInfrazione) :
		IdVigile(idVigile), Data(data), Ora(ora), Targa(targa), CodInfrazione(codInfrazione) {}
	
	//Verifico l'ordinamento nel momento dell'inserimento, tendo conto della sostituzione della testa della lista
	//In questo caso mi serve il pointer per poterlo sostituire con un'altra testa
	void accodaMulta(Contravvenzione **head, int idVigile, int data, int ora, string targa, int codInfrazione) {
		Contravvenzione *item = new Contravvenzione(idVigile, data, ora, targa, codInfrazione);
		if (!Compare(item)) {
			//caso speciale per il primo elemento
			item->nextPtr = this;
			*head = item;
		}
		else {
			Add(this, item);
		}
	}

	//Comparazione tra due oggetti tramite date
	virtual bool Compare(Contravvenzione *item) {
		if (this->Data > item->Data) {
			return true;
		}
		else if (this->Data == item->Data) {
			return (this->Ora > item->Ora);
		}
		return false;
	}
	
	//estrazione del mese
	int GetMonth() {
		return (Data / 100) % 100;
	}

	//prende il numero di contravvezioni indicando il mese e l'id
	int GetNumberOfFines(int id, int mese) {
		Contravvenzione* it = this;
		int contravenzioni = 0;
		do {
			if (id == it->IdVigile && it->GetMonth() == mese) {
				contravenzioni++;
			}
		} while (HasNext(&it));
		return contravenzioni;
	}

	//Verifico ogni vigile e sommo le contravenzioni, se è già stata fatta viene salvata in id
	void creaReport(int mese) {
		int count = Count(this);
		Contravvenzione* it = this;
		int* id = new int[count] {0};

		cout << "Mese " << mese << endl;
		do {
			if (!ContainsAnyOf(id, it)) {	
				id[GetFreeIndex(id)] = it->IdVigile;
				it->Print(GetNumberOfFines(it->IdVigile, mese));
			}
		} while (HasNext(&it));
	}

	//cerca un index libero nella lista
	int GetFreeIndex(int * &id)
	{
		for (int i = 0; i < sizeof(id); i++) {
			if (0 == id[i]) {
				return i;
			}
		}
		return -1;
	}

	//verifica se è già presente nella lista un determinata contravvenzione
	bool ContainsAnyOf(int *id, Contravvenzione *it)
	{
		for (int i = 0; i < sizeof(id); i++) {
			if (it->IdVigile == id[i])
				return true;
		}
		return false;
	}

	void Print(int numCont) {
		cout << setw(4) << right << IdVigile << " contravvenzioni " << setw(4) << left << numCont << endl;
	}

	void PrintAll() {
		cout << IdVigile << " data " << Data << " ora " << Ora << endl;
		if (nextPtr != NULL) {
			nextPtr->PrintAll();
		}
	}
};


int main()
{
	Contravvenzione *con = new Contravvenzione(10275, 20200912, 1730, "CA061ZW", 158);
	con->accodaMulta(&con, 10115, 20200812, 2115, "CB101ZA", 158);
	con->accodaMulta(&con, 10275, 20200812, 1923, "AA101ZA", 143);

	con->accodaMulta(&con, 10115, 20200812, 1912, "CB101CA", 154);
	con->accodaMulta(&con, 10115, 20200812, 1856, "CB181ZB", 158);
	con->accodaMulta(&con, 10275, 20200812, 1130, "CB251SP", 142);

	con->accodaMulta(&con, 10115, 20200812, 1058, "FB109ZA", 154);
	con->accodaMulta(&con, 10275, 20200812, 912, "BB375ZA", 158);
	con->PrintAll();
	con->creaReport(8);
	  
}