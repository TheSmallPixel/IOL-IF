// IF17.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
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
		int DIM = 0;
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

	void Inverse() {
		Nodo i = *this;
		int DIM = Count();
		int* arr = new int[DIM] {0};
		int invIte = DIM-1;
		for (Nodo* p = &i; p->HasNext(p); invIte--) {
			arr[invIte] = p->Valore;
		}
		for (int i = 0; i < DIM; i++) {
			cout << arr[i] << "\t";
		}
		delete[] arr;
	}
	
};

int main()
{
	Nodo *testa = new Nodo(0);
	Nodo *p = testa;
	int pos = -1;
	while (cin >> pos) {
		if (pos == 0) break;
		p = p->AddValue(pos);
	}
	cout << endl;
	testa->Inverse();
}
