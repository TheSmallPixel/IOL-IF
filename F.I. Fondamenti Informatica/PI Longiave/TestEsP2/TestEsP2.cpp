#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

//Cognome: Di Conza
//Nome: Elisa
//Matricola: 962815
//Classe Virtuale: cv1



//!!!NON SO COME EFFETTUARE STACK DICE CON LE MATRICI E C'E' ANCHE IL PROBLEMA DELLA TARGA CHE NON E' INT.
//PER CUI HO PROVATO UNO STACK DICE DIVERSO

//STACK DICE 2

struct elemento {
	int ID_Vigile, Data, Ora, CodInfrazione;
	string Targa;
	elemento * next;

	elemento(int idVigile, int data, int ora, string targa, int codInfrazione) :
		ID_Vigile(idVigile), Data(data), Ora(ora), Targa(targa), CodInfrazione(codInfrazione)
	{
		next = NULL;
	}

	void accodaMulta(elemento **head, int idVigile, int data, int ora, string targa, int codInfrazione)
	{
		elemento*  newData = new elemento(idVigile, data, ora, targa, codInfrazione);
		if (IsSmallerThan(newData)) {
			newData->next = this;
			*head = newData;
		}
		else {
			if (next != NULL) {
				next->inserimentoRecursivo(this, newData);
			}
			else {
				next = newData;
			}
		}
	}

	void inserimentoRecursivo(elemento* prec, elemento* data) {
		//Swap
		if (IsSmallerThan(data)) {
			data->next = this;
			prec->next = data;
			//prec |data| this | 
		}
		else {
			if (next != NULL) {
				next->inserimentoRecursivo(this, data);
			}
			else {
				next = data;
			}
		}
	}

	bool IsSmallerThan(elemento* newData) {
		if (Data < newData->Data) {
			return true;
		}
		else if (Data == newData->Data) {
			return (Ora < newData->Ora);
		}
		return false;
	}
	//20200812/100 = 202008 % 100 = 08
	bool IsThisMonth(int mese) {
		return ((Data / 100) % 100) == mese;
	}

	void creaReport(int mese) {
		elemento* ptr = this;
		int dim = 1;
		for (; ptr->next != NULL; ptr = ptr->next, dim++);
		int* arrId = new int[dim] {0};
		ptr = this;
		cout << "Mese" << mese << endl;
		for (; ptr->next != NULL; ptr = ptr->next) {
			bool alreadyDone = false;
			for (int i = 0; i < dim; i++) {
				if (arrId[i] == ptr->ID_Vigile) {
					alreadyDone = true;
				}
			}
			if (!alreadyDone) {
				for (int i = 0; i < dim; i++) {
					if (arrId[i] == 0) {
						arrId[i] = ptr->ID_Vigile;
						break;
					}
				}
				int contravvenzioni = 0;
				elemento* ptr2 = this;
				for (; ptr2 != NULL; ) {
					if (ptr2->IsThisMonth(mese) && ptr2->ID_Vigile == ptr->ID_Vigile) {
						contravvenzioni++;
					}
					ptr2 = ptr2->next;
				}
				cout << "Vigile " << ptr->ID_Vigile << " contravvenzioni: " << contravvenzioni << endl;
			}
		}
	}
};

int main() {
	elemento* head = new elemento(10275, 20200812, 912, "BB375ZA", 158);
	head->accodaMulta(&head, 10275, 20200812, 1012, "BB375ZA", 158);
	head->accodaMulta(&head, 10275, 20200812, 912, "BB375ZA", 158);
	head->accodaMulta(&head, 10275, 20200912, 912, "BB375ZA", 158);
	head->accodaMulta(&head, 10275, 20200912, 1012, "BB375ZA", 158);
	head->accodaMulta(&head, 10274, 20200812, 1012, "BB375ZA", 158);
	head->accodaMulta(&head, 10274, 20200812, 912, "BB375ZA", 158);
	head->accodaMulta(&head, 10274, 20200912, 912, "BB375ZA", 158);
	head->accodaMulta(&head, 10273, 20200912, 1012, "BB375ZA", 158);
	head->creaReport(8);

}




//LISTA MULTE

/*MULTA 1
10275
20200812
0912
BB375ZA
158

//MULTA 2
10115
20200812
1058
FB109ZA
154

//MULTA 3
10275
20200812
1130
CB251SP
142

//MULTA 4
10115
20200812
1856
CB181ZB
158

//MULTA 5
10115
20200812
1912
CB101CA
154

//MULTA 6
10275
20200812
1923
AA101ZA
143

//MULTA 7
10115
20200812
2115
CB101ZA
158

//MULTA 8
10275
20200912
1730
CA061ZW
158
*/
