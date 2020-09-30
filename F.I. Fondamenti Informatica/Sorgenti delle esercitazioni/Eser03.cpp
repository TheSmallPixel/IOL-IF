// Programma che calcola il massimo di una sequenza di numeri interi positivi

//inizializzazioni
#include <iostream>
using namespace std;

int main(){

    // dichiarazione delle variabili
    const int TAPPO = 0;
    int  num, max;

    // stampa del titolo    
    cout << endl;
    cout << "Calcolo del massimo" << endl << endl;

    cout << "Inserisci una sequenza di numeri interi positivi "
         << "terminata da 0" << endl;
    
    // Leggi il primo numero
    cin >> num;
    cout << endl;
    
    max = 0;

    // finch� (la sequenza non � finita)
    while(num != TAPPO){

		// Se (l'ultimo numero letto � > del massimo tra i 
        // numeri gi� letti)
		if (num > max){		

            // Massimo tra i numeri letti = ultimo numero 
            // letto;
	        max = num;
		}

		// Leggi un altro numero
		cin >> num;

    }  // fine while 


	// Se (� stato letto almeno un numero)
	if (max != TAPPO){    

		// Stampa il massimo tra i numeri letti
		cout << endl << "Il massimo e': " << max << endl << endl;
	}

	else{

		// Stampa il messaggio "Non sono stati introdotti numeri"
		cout << endl << "Non sono stati introdotti numeri" << endl << endl;
	}

	return 0;
}
