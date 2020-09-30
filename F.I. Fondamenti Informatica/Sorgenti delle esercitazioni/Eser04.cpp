#include <iostream>
using namespace std;

int main()
{
	//inizializzazioni
	const char TAPPO = '$';
	char ch;
	int totCaratteri;
	int totMinuscole;
	int totCifre;

	cin.unsetf(ios::skipws);

	totCaratteri = 0;
	totMinuscole = 0;
	totCifre = 0;
   
	//dialogo con l'utente
	cout << endl << "Introdurre un testo terminato da " << TAPPO << endl;

	// leggi carattere corrente
	cin >> ch;

	//while (il testo non è finito)
	while (ch != TAPPO)
	{
		//numero totale di caratteri ++
		totCaratteri++;

		//if (il carattere corrente è minuscolo)
		if(ch>='a' && ch <='z')
		{
			//numero caratteri minuscoli ++
			totMinuscole++;
		}
		//else if (il carattere corrente è una cifra)
		else if (ch>='0' && ch <='9')
		{
			//numero cifre++
			totCifre++;
	    }
	
		// leggi carattere corrente
		cin >> ch; 
	}

	//if (numero totale di caratteri >0)
	if (totCaratteri > 0)
    {
  		//stampa i risultati
		cout << endl << "La percentuale di lettere minuscole e' ";
		cout << 100*totMinuscole/totCaratteri << " %" << endl;
		cout << endl << "La percentuale di cifre e' ";
		cout << 100*totCifre/totCaratteri << " %" << endl;
	}
	else
	{
		//stampa "Non sono stati introdotti caratteri"
		cout << endl << "Non sono stati introdotti caratteri" << endl;
	}

	return  0;
}

