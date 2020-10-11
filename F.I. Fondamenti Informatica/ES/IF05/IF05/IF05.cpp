// IF05.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h";
#include <iostream>;
using namespace std;

void main() {
	cout << "inserisci una frase con più periodi e ti dico  il numero piu' grande di caratteri in un periodo e quante parole contine il periodo piu'lungo";
	char ch = ' ';
	const char tappo = '$';

	cout << "inserisci una frase terminata da " << tappo << "ogni periodo deve essere suddiviso da ; : .";

	int totalCaratteri, caratteriParola, paroleParagrafo, maxParole, maxCaratteri;
	totalCaratteri = caratteriParola = paroleParagrafo = maxParole = maxCaratteri = 0;

	cin.unsetf(ios::skipws);
	while (ch != tappo) {
		cin >> ch;
		if (ch == ' ' | ch == '.' | ch == ';' | ch == ':' | ch == '$') {
			if (caratteriParola > 0) {
				totalCaratteri += caratteriParola;
				caratteriParola = 0;
				paroleParagrafo++;
			}
			if (ch != ' ') {
				if (totalCaratteri > maxCaratteri) {
					maxCaratteri = totalCaratteri;
				}
				if (paroleParagrafo > maxParole) {
					maxParole = paroleParagrafo;
				}
				totalCaratteri = paroleParagrafo = caratteriParola = 0;
			}
		}
		if ((ch >= 65 && ch <= 90) | (ch >= 97 && ch <= 122) | (ch >= 48 && ch <= 57)) caratteriParola++;
	}

	cout << "Il periodo maggiore contiene " << maxParole << "parole." << endl;
	cout << "Il periodo con il maggior numero di caratteri contiene " << maxCaratteri << "caratteri." << endl;
}

