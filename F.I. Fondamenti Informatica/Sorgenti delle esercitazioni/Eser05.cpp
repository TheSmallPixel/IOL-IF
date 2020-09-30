#include <iostream>
using namespace std;

int main()
{
	//inizializzazioni
	const char TAPPO ='$';
	int lungChar, lungMaxChar, lungPar, lungMaxPar;
	char ch, chPrec;

	cin.unsetf(ios::skipws);

	lungMaxChar = 0;
	lungChar = 0;
	lungMaxPar = 0;
	lungPar = 0;
	chPrec = ' '; 

	// dialogo con l'utente
	cout << endl << "Introdurre un testo terminato da " << TAPPO << endl;

	//leggi carattere corrente
	cin >> ch;

	//while(il testo non è finito)
	while (ch!=TAPPO)
	{
		//lunghezza corrente in caratteri++
		lungChar++;

		//if ((il carattere corrente è una lettera o un numero) and (il 
		//carattere  precedente non è una lettera o un numero))
		if ((((ch>='a') && (ch<='z')) || 
			((ch>='A') && (ch <= 'Z'))  ||
			((ch>='0') &&   (ch<='9')) ) &&  
			! (((chPrec>='a') && (chPrec<='z')) || 
			((chPrec>='A') && (chPrec <= 'Z'))  ||  
			((chPrec>='0') && (chPrec<='9'))) )
		{
			//lunghezza corrente in parole++
			lungPar++;
 	    }
		//else if (carattere corrente termina il periodo)
		else if ((ch=='.') || (ch==';') || (ch==':')) 
		{
			//if (lunghezza corrente in parole > lunghezza corrente 
			//massima in parole)
			if (lungPar > lungMaxPar)
			{
				//lunghezza corrente massima in parole
				// =lunghezza corrente in parole;
				lungMaxPar=lungPar;
			}
			
			//lunghezza corrente in parole =0;
			lungPar=0;

			//if (lunghezza corrente in caratteri)>(lunghezza  corrente 
			//massima in caratteri)
			if (lungChar > lungMaxChar)
			{
				//lunghezza corrente massima in caratteri = lunghezza 
				//corrente in caratteri
				lungMaxChar = lungChar;
			}
			
			//lunghezza corrente in caratteri=0
			lungChar=0;
		}

		//carattere precedente = carattere corrente 
		chPrec=ch;
		//leggi carattere corrente
		cin >> ch;
	}
   
	//stampa risultati
	cout << endl << "il numero di caratteri del periodo con piu' caratteri = ";
	cout << lungMaxChar << endl;
	cout << endl << "Il numero di parole del periodo" << " con piu' parole = ";
	cout << lungMaxPar << endl;

	return 0;
}

