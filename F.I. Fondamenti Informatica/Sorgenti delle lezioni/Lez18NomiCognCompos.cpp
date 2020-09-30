// Programma che pospone
// il nome composto di una o piu' parti
// al cognome composto di una o piu' parti.

#include <iostream>
#include <iomanip>
using namespace std;

char carattere;                      // variabile globale
const char spazio = ' ';

void saltaspazi()                    // dichiarazione di funzione
{
	do
	{
		cin >> carattere;
	} while (carattere == spazio);
}

void main()
{
	const char tappo = '.';
	int i, j;
	const int lung_max = 20;
	char nome[lung_max];
  
	cin.unsetf(ios::skipws); // evita in lettura il salto degli spazi
	// inserimento di nome e cognome
	cout << "Inserisci nome e cognome in successione, " << endl
		<< "ognuno immediatamente seguito da " << tappo << ";"
		<< endl << "nome e cognome possono essere composti." << endl
		<< "Le parti sono separate da uno o piu' spazi." << endl;

	// conserva il nome composto
	i = 0;
	do
	{	// salta spazi iniziali
		saltaspazi();
		// conserva una parte del nome
		do
		{
			nome[i] = carattere;
			i++;
			cin >> carattere;
		} while (carattere != tappo && carattere != spazio);
		// metti spazio in nome, se non e' l'ultima parte
		if (carattere == spazio)
		{ 
			nome[i] = spazio;
			i++;
		}
	} while (carattere != tappo);

	// leggi e scrivi cognome composto di una o piu' parti
	do
	{	// salta spazi prima di parte del cognome
		saltaspazi();
		// leggi e scrivi parte del cognome
		do 
		{
			cout << carattere;
			cin >> carattere;
		} while (carattere != tappo && carattere != spazio);
		// scrivi spazio
		cout << spazio;
	} while (carattere != tappo);

	// scrivi i caratteri del nome
	for (j = 0;j <= i-1;j++)
		cout << nome[j];
	cout << endl;
}

