#include <iostream>;
using namespace std;

main() {

	cout << "inserisci una frase con più periodi e ti dico  il numero piu' grande di caratteri in un periodo e quante parole contine il periodo piu'lungo";

	//Il risultato deve mostrare SOLO il numero di
	//parole contenute nella frase con il più alto
	//numero di parole e il numero di caratteri
	//contenuti nella frase con il maggior numero
	//di caratteri.
	char ch;
	const char tappo = '$';

	cout << "inserisci una frase terminata da " << tappo << "ogni periodo deve essere suddiviso da ; : .";


	int totalCaratteri = 0;
	int caratteriParola = 0;
	int paroleParagrafo = 0;

	//win variabili con massimi
	int maxParole = 0;
	int maxCaratteri = 0;
	while (ch != tappo) {
		cin >> ch;
		if (ch == '.' || ch == ';' || ch == ':') {
			if (totalCaratteri > maxCaratteri && paroleParagrafo > maxParole) {
				maxCaratteri = totalCaratteri;
				maxParole = paroleParagrafo;
			}
			totalCaratteri = 0;
			paroleParagrafo = 0;
			caratteriParola = 0;
			continue;				//ritorna all'inizio del ciclo
		}
		//conto quanto è lunga
		if ((ch >= 65 && ch <= 90) ||  //Caratteri A-Z
			(ch >= 97 && ch <= 122) || //a-z
			(ch >= 48 && ch <= 57)) { //0-9
			caratteriParola++;
		}
		if (ch == ' ' && caratteriParola > 0) {
			totalCaratteri += caratteriParola;
			caratteriParola = 0;
			paroleParagrafo++;
		}
	}

	cout << "Il periodo maggiore contiene " << maxParole << "parole." << endl;
	cout << "Il periodo con il maggior numero di caratteri contiene " << maxCaratteri << "caratteri." << endl;

}