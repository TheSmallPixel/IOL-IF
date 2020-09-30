/* Programma che indica se l'anno fornito in ingresso � bisestile.
   
   Un anno � bisestile se � divisibile per 4 ma non per 100, oppure se,
   essendo divisibile per 100, � divisibile anche per 400.
   
   Esempi:
   1996 � bisestile
   1900 non � bisestile
   2000 � bisestile

   Singola esecuzione
*/

// #include <iostream.h> notazione obsoleta

#include <iostream>
using namespace std;

int main()
{
    int anno;

	cout << "Digitare l'anno di interesse: ";
	cin >> anno;

	if ( (anno % 4 == 0) && (anno % 100 != 0) || (anno % 400 == 0) )
		cout << "L'anno " << anno << " e' bisestile." << endl;
	else 
		cout << "L'anno " << anno << " NON e' bisestile." << endl;

	return 0;
}
