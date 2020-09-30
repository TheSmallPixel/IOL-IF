// Programma che calcola la media di n numeri reali.
// Il numero n è inserito dall'utente

//inizializzazioni
#include <iostream>
using namespace std;

int main(){

    // dichiarazione delle variabili
    float numero,   // numero letto
          somma,    // somma dei numeri
          media;    // media dei numeri
    int n,          // totale numeri da leggere
        i;          // variabile per contare quante volte
                    // occorre leggere un numero

    // stampa del titolo    
    cout << endl;
    cout << "Calcolo della media" << endl << endl;

    // Leggi il valore di n
    cout << "Inserisci il valore di n: ";
    cin >> n;
    cout << endl;

    // Se n == 0 il valore della media non può essere calcolato
	if (n == 0){
		cout << "La media non e' definita" << endl;
	}
	else{   // n!=0

    	// inizializzazione della variabile somma
		somma = 0;

        // lettura degli n numeri e calcolo della loro somma

        // finchè non vengono letti n numeri
		for(i=1; i<=n; i++){

             // lettura dell'i-esimo numero
             cout << "Inserisci il dato numero " << i << ": ";
             cin >> numero;

             // somma il numero al valore di somma corrente
             somma = somma + numero;  // oppure: somma+=numero

         }  // fine while 

    	 // calcolo della media
         media=somma/n;

		 // Stampa il valore della media
         cout << endl << "Media: " << media << endl << endl;
    
	}  // fine else

    return 0;
}
