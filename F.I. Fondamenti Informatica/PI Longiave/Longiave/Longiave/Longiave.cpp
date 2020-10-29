//Cognome:	Longiave
//Nome:		Lorenzo
//Matricola: 959336
//Classe Virtuale: CV2
//Note: Versione Semplice
#include "pch.h"
#include <iostream>
using namespace std;

const int W = 5; //Larghezza
const int H = 6; //Altezza
const int TEMPO_MINIMO_CASO = 3 * 60; // 3 min
const int TEMPO_MINIMO_CASO_CRITICO = 15 * 60;// 15 m

struct cella {
	int matricola = 0;
	int secondi = 0;
	cella() {}
	cella(int matr, int sec) : matricola(matr), secondi(sec) {}
	//verifica le condizioni per essre una persona
	bool isPerson() {
		return !((matricola == -1) && (secondi == -1)) && !((matricola == 0) && (secondi == 0));
	}
	bool checkTime(int time) {
		return secondi >= time && secondi >= time;
	}
};

void verificaVicinanza(cella matricole[H][W]);
void valutaCaso(cella matricola1, cella matricola2);

int main()
{
	cella Pianta[H][W] = {
		{{},{},{},{},{}},
		{{27,235},{},{83,105},{},{}},
		{{},{48,190},{},{},{}},
		{{},{},{},{},{}},
		{{-1,-1},{-1,-1},{},{},{12,935}},
		{{-1,-1},{-1,-1},{},{94,1045},{}}
	};
	verificaVicinanza(Pianta);
	return 0;
}

void valutaCaso(cella matricola1, cella matricola2) {
	//Verifica permanenza minima
	if (matricola1.checkTime(TEMPO_MINIMO_CASO) && matricola2.checkTime(TEMPO_MINIMO_CASO)) {
		//verifica che non sia una persona
		if (matricola1.isPerson() && matricola2.isPerson()) {
			//Verifica caso critico
			bool checkCriticTime = matricola1.checkTime(TEMPO_MINIMO_CASO_CRITICO) && matricola2.checkTime(TEMPO_MINIMO_CASO_CRITICO);
			cout << "Vicinanza " << ((checkCriticTime) ? "CRITICA " : "fra ");
			cout << matricola1.matricola << " e " << matricola2.matricola << endl;
		}
	}
}

//Verificando la vicinanza da sopra possiamo ridurrei casi a 4 e renderli parametrici
void verificaVicinanza(cella matricole[H][W]) {
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (x + 1 < W)
				valutaCaso(matricole[y][x], matricole[y][x + 1]);
			if (y + 1 < H && x + 1 < W)
				valutaCaso(matricole[y][x], matricole[y + 1][x + 1]);
			if (y + 1 < H)
				valutaCaso(matricole[y][x], matricole[y + 1][x]);
			if (y + 1 < H && x - 1 >= 0)
				valutaCaso(matricole[y][x], matricole[y + 1][x - 1]);
		}
	}
}