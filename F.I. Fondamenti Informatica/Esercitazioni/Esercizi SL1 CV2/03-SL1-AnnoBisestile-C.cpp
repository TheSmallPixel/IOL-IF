/* Programma che indica se l'anno fornito in ingresso è bisestile.
   
   Un anno è bisestile se è divisibile per 4 ma non per 100, oppure se,
   essendo divisibile per 100, è divisibile anche per 400.
   
   Esempi:
   1996 è bisestile
   1900 non è bisestile
   2000 è bisestile


   Versione ciclica: il ciclo termina con il valore convenzionale CTRL+z.
*/


#include <iostream>
using namespace std;

int main()
{
    const int FALSE = 0;
    int anno;

	cout << "Digitare l'anno di interesse (CTRL+z per terminare): ";
	cin >> anno;

	while (cin.eof() == FALSE)
	{
		if ( (anno % 4 == 0) && (anno % 100 != 0) || (anno % 400 == 0) )
			cout << "L'anno " << anno << " e' bisestile." << endl;
		else 
			cout << "L'anno " << anno << " NON e' bisestile." << endl;

		cout << "Digitare l'anno di interesse (CTRL+z per terminare): ";
		cin >> anno;
	}

	return 0;
}
