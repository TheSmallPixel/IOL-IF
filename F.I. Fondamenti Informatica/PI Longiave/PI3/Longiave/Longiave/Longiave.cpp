//
//Cognome: Longiave
//Nome: Lorenzo
//Matricola: 959336
//Classe Virtuale: CV2
//Nota:


#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#define NumeroAtleti 9
using namespace std;

enum Ruolo { Timoniere, Canottiere };

class Atleta {
public:
	string Nome, Cognome, Universita;
	Ruolo RuoloAtleta;

	Atleta(string nome, string cognome, string universita, Ruolo ruoloAtleta) {
		Nome = nome;
		Cognome = cognome;
		Universita = universita;
		RuoloAtleta = ruoloAtleta;
	}

	void ModificaUniversita(string universita) {
		Universita = universita;
	}

	string GetRuolo() {
		return ((RuoloAtleta == Timoniere) ? "Timoniere" : "Canottiere");
	}

	friend ostream& operator<<(ostream &out, Atleta *a) {
		out << "[Atleta]" << a->Nome << " - " << a->Cognome << " - " << a->Universita << " - " << a->GetRuolo() << endl;
		return out;
	}

	~Atleta() {
		cout << "Atleta " << Nome << " " << Cognome << " e stato rimosso!" << endl;
	}
};
class Imbarcazione {
public:
	string Universita;
	Atleta *Atleti[NumeroAtleti]{ 0 };

	Imbarcazione(string universita) {
		Universita = universita;
	}

	bool AggiungiAtleta(Atleta* a) {
		//verifica se l'atleta è già presente
		if (Exist(a)) return false;
		//verifica università
		if (a->Universita != Universita) return false;
		//verifica se è un timoniere e se il posto libero
		if (TrovaIndexTimoniere() != -1) {
			if (a->RuoloAtleta == Timoniere) return false;
		}
		else {
			if (PostiDisponibili() < 2 && a->RuoloAtleta != Timoniere) return false;
		}

		//trova uno slot libero per l'atleta
		for (int i = 0; i < NumeroAtleti; i++) {
			if (Atleti[i] == 0) {
				Atleti[i] = a;
				return true;
			}
		}
		return false;
	}

	bool Exist(Atleta* a) {
		for (int i = 0; i < NumeroAtleti; i++) {
			if (Atleti[i] == a) return true;
		}
		return false;
	}

	void RimuoviAtleta(Atleta* a) {
		for (int i = 0; i < NumeroAtleti; i++) {
			if (Atleti[i] == a) {
				Atleta* temp = Atleti[i];
				Atleti[i] = 0;
				delete temp;
				return;
			}
		}
	}

	bool ModificaTimoniere(Atleta* a) {
		if (a->RuoloAtleta != Timoniere) return false;

		int TimIndex = TrovaIndexTimoniere();
		if (TimIndex != -1) {
			Atleta* temp = Atleti[TimIndex];
			Atleti[TimIndex] = a;
			delete temp;
			return true;
		}
		else {
			return AggiungiAtleta(a);
		}
	}

	int TrovaIndexTimoniere() {
		for (int i = 0; i < NumeroAtleti; i++) {
			if (Atleti[i] && Atleti[i]->RuoloAtleta == Timoniere)
				return i;
		}
		return -1;
	}

	int PostiDisponibili() {
		int disp = 0;
		for (int i = 0; i < NumeroAtleti; i++) {
			if (Atleti[i] == 0)
				disp++;
		}
		return disp;
	}

	void Stampa(string fileName) {
		ofstream out;
		out.open(fileName);
		out << this;
		out.close();
	}

	friend ostream& operator<<(ostream &out, Imbarcazione *a) {
		out << "[Imbarcazione] " << a->Universita << " " << (NumeroAtleti - a->PostiDisponibili()) << "/" << NumeroAtleti << " Posti Occupati" << endl;
		for (int i = 0; i < NumeroAtleti; i++) {
			if (a->Atleti[i])
				out << (a->Atleti[i]);
		}
		out << "=========================" << endl;
		return out;
	}

	~Imbarcazione() {
		cout << "Imbarcazione " << Universita << " rimossa!" << endl;
		for (int i = 0; i < NumeroAtleti; i++) {
			if (Atleti[i])
				delete Atleti[i];
		}
	}
};

int main()
{
	Imbarcazione* i = new Imbarcazione("Poli");
	i->AggiungiAtleta(new Atleta("Lorenzo", "Piero", "Poli", Timoniere));
	i->AggiungiAtleta(new Atleta("Rossi", "Piero", "Poli", Canottiere));
	i->AggiungiAtleta(new Atleta("Mario", "Piero", "Poli", Canottiere));
	i->AggiungiAtleta(new Atleta("Giacomo", "Piero", "Poli", Canottiere));
	i->AggiungiAtleta(new Atleta("Lorneza", "Piero", "Poli", Canottiere));

	cout << "Caso Standard: " << endl << i << endl;
	i->Stampa("Atleta.txt");

	cout << "Verifica delle altre funzioni:" << endl;

	i->RimuoviAtleta(i->Atleti[2]);
	cout << "Rimozione del 3 Atleta: " << endl << i << endl;

	i->Atleti[3]->ModificaUniversita("Universita di Pavia");
	cout << "Cambio Universita: " << endl << i << endl;

	//provo a scambiare un'atleta non timoniere per verificare che non sia approvato come timoniere
	bool cambio = i->ModificaTimoniere(new Atleta("Giammarco", "Fiorini", "Poli", Canottiere));
	cout << "Cambio Timoniere Fasullo: " << (cambio ? "Rimosso" : "Non rimosso") << endl;

	//scambio un timoniere valido
	bool cambio1 = i->ModificaTimoniere(new Atleta("Giammarco", "Fiorini", "Poli", Timoniere));
	cout << "Cambio Timoniere: " << (cambio1 ? "Rimosso" : "Non rimosso") << endl;

	//Verifico che il programma lasci sempre uno spazio per il timoniere
	Imbarcazione* b = new Imbarcazione("Poli");
	b->AggiungiAtleta(new Atleta("Rossi", "Piero", "Poli", Canottiere));
	b->AggiungiAtleta(new Atleta("Mario", "Piero", "Poli", Canottiere));
	b->AggiungiAtleta(new Atleta("Giacomo", "Piero", "Poli", Canottiere));
	b->AggiungiAtleta(new Atleta("Lorneza", "Piero", "Poli", Canottiere));
	b->AggiungiAtleta(new Atleta("Rossi2", "Piero", "Poli", Canottiere));
	b->AggiungiAtleta(new Atleta("Mario2", "Piero", "Poli", Canottiere));
	b->AggiungiAtleta(new Atleta("Giacomo2", "Piero", "Poli", Canottiere));
	b->AggiungiAtleta(new Atleta("Lorneza2", "Piero", "Poli", Canottiere));
	b->AggiungiAtleta(new Atleta("Orlando", "Piero", "Poli", Canottiere));
	b->AggiungiAtleta(new Atleta("Lorenzo", "Piero", "Poli", Timoniere));
	cout << "Verifica spazio per il Timoniere: " << endl << b << endl;


	//cancello tutto
	delete i;
	delete b;
}
