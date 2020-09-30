/* Programma che indica se l'anno fornito in ingresso � bisestile.
   
   Un anno � bisestile se � divisibile per 4 ma non per 100, oppure se,
   essendo divisibile per 100, � divisibile anche per 400.
   
   Esempi:
   1996 � bisestile
   1900 non � bisestile
   2000 � bisestile


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
