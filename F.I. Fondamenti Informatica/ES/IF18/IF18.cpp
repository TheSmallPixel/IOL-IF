// IF17.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>



struct Nodo {
public:
	int Valore;
	Nodo *nextPtr;
	Nodo() : Valore(0), nextPtr(NULL) {}

	Nodo(int i) {
		Valore = i;
		nextPtr = NULL;
	}

	Nodo* AddValue(int i) {
		nextPtr = new Nodo(i);
		return nextPtr;
	}

	Nodo* AddValueOnTop(int i) {
		Nodo* newNode = new Nodo(i);
		newNode->nextPtr = this;
		return newNode;
	}

	bool HasNext(Nodo **next) {
		if ((*next)->nextPtr != NULL) {
			*next = (**next).nextPtr;
			return true;
		}
		else {
			return false;
		}
		return false;
	}
	bool HasNext() {
		if (nextPtr != NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void GetNext(Nodo * next) {
		if (nextPtr != NULL) {
			*next = *nextPtr;
		}
	}
	Nodo* GetNext() {
		if (nextPtr != NULL) {
			return nextPtr;
		}
		return NULL;
	}

	int Count() {
		int DIM = 1;
		Nodo* i = this;
		for (Nodo** p = &i; (*p)->HasNext(p); DIM++) {}
		return DIM;
	}

	Nodo* GetItemAt(Nodo* head,int pos) {
		int locPos = 0;
		Nodo** it = &head;
		do {
			if (locPos == pos) return *it;
			locPos++;
		} while (HasNext(it));
		return NULL;
	}

	Nodo* GetLast() {
		Nodo* ip = this;
		Nodo** i = &ip;
		for (; (*i)->HasNext(i);) {}
		return *i;
	}
	Nodo* Print() {
		Nodo* it = this;
		Nodo** i = &it;
		do {
			(*i)->PrintThis();
		} while (HasNext(i));
		return this;
	}
	void PrintThis() {
		cout << "|" << Valore;
	}
	Nodo* InverseRecursive() { //this will not work as aspected!
		if (nextPtr != NULL)
			return nextPtr->InverseRecursive();
		return this;
	}
	Nodo* FindPrev(Nodo* head, Nodo* node) {
	
		Nodo** i = &head;
		do {
			if ((*i)->nextPtr == node) {
				return (*i);
			}
		} while (HasNext(i));
		return NULL;
	}
	void InversePrint() {
		if (nextPtr != NULL)
			nextPtr->InversePrint();
		PrintThis();
	}
	Nodo* InverseV2() {
		Nodo* it = this;
		Nodo** i = &it;
		//Nodo current = *this;
		Nodo *inverseList = NULL;
		do {
			if (inverseList == NULL) {
				inverseList = new Nodo((*i)->Valore);
			}
			else {
				inverseList = inverseList->AddValueOnTop((*i)->Valore);
			}
		} while (HasNext(i));
		return inverseList;
	}
	Nodo* Inverse() {
		Nodo *testa = NULL;
		Nodo *nodoInv = NULL;
		Nodo* nod = this;
		Nodo** nodo = &nod;
		int nodeCount = Count();
		int* arr = new int[nodeCount];
		int i = 0;
		do {
			arr[i] = (*nodo)->Valore;
			i++;
		} while (HasNext(nodo));
		for (int i = nodeCount - 1; i >= 0; i--) {
			if (testa == NULL) {
				nodoInv = testa = new Nodo(arr[i]);
			}
			else {
				nodoInv = nodoInv->AddValue(arr[i]);
			}
		}
		delete[] arr;
		return testa;
	}
	Nodo* RemoveNodeAt(Nodo* head, int ti) {
		if (ti == 0)
			return this->DeleteThis();
		Nodo* nodo = GetItemAt(head,ti);
		Nodo* precedente = FindPrev(head, nodo);
		if (nodo != NULL && precedente != NULL) {
			Nodo** delThis = &nodo;
			Nodo** next = &(nodo->nextPtr);
			precedente->nextPtr = *next;
			delete *delThis;
			
			return head;
		}
		else if (nodo != NULL) {
			head = nodo->DeleteThis();
		}
		return head;
	}
	Nodo* DeleteThis() {
		Nodo* returnData = nextPtr;
		delete this;
		if (returnData != NULL)
			return returnData;
		return NULL;
	}
	Nodo* DeleteAll() {
		if (nextPtr != NULL)
			nextPtr->DeleteThis();
		return DeleteThis();
	}
};

int main()
{
	cout << "Inserire 0 per terminare il programma:" << endl;
	int pos = -1;
	Nodo *testa = NULL;
	Nodo *p = NULL;

	while (cin >> pos) {
		if (pos == 0) break;
		if (testa == NULL) {
			p = testa = new Nodo(pos);
		}
		else {
			p = p->AddValue(pos);
		}
	}
	cout << endl << "Normal->";
	testa->FindPrev(testa, testa->nextPtr)->PrintThis();
	cout << endl << "InverseNormalv2->";
	testa->InverseV2()->DeleteThis()->Print()->FindPrev(testa, testa->nextPtr)->PrintThis();
	cout << endl << "InverseNormal->";
	testa->Inverse()->Print()->DeleteAll();
	cout << endl << "InversePrint->";
	testa->InverseRecursive();
	cout << endl << "Cancella";
	testa->Print()->RemoveNodeAt(testa, 2)->Print();
}
