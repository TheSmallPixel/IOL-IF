// IF16.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>

using namespace std;

struct Nodo {
	int Valore;
	Nodo *nextPtr;

	Nodo() : Valore(0), nextPtr(NULL) {}

	Nodo(int i) {
		Valore = i;
		nextPtr = NULL;
	}

	Nodo* AddValue(int i) {
		return nextPtr = new Nodo(i);
	}

	bool HasNext(Nodo *next) {
		if (nextPtr != NULL) {
			*next = *nextPtr;
			return true;
		}
		else {
			return false;
		}
	}

	int Count() {
		int DIM = 1;
		Nodo i = *this;
		for (Nodo* p = &i; p->HasNext(p); DIM++) {}
		return DIM;
	}

	Nodo* GetItemAt(int pos) {
		int locPos = 1;
		Nodo i = *this;
		for (Nodo* p = &i; p->HasNext(p); locPos++) {
			if (locPos == pos) return p;
		}
		return NULL;
	}

	int CalcolaMediana() {
		int DIM = Count();
		if (DIM % 2 == 0) {
			int p1 = (DIM - 1) / 2;
			int p2 = (DIM) / 2;
			return (GetItemAt(p1)->Valore + GetItemAt(p2)->Valore)/2;
		}
		else {
			int p2 = (DIM) / 2;
			return GetItemAt(p2)->Valore;
		}
	}
};

int main()
{
	Nodo *testa = new Nodo(0);
	Nodo *p = testa;
	for (int i = 1; i < 7; i++) {
		p = p->AddValue(i);
	}
	cout << testa->CalcolaMediana() << endl;
}
