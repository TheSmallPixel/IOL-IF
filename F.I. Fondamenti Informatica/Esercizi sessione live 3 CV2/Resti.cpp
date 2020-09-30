/*  Prima prova in itinere di Informatica.
 *  Nome: Luca
 *  Cognome: Resti
 *  Matricola 811816
 *  Classe virtuale: 2
 *
 *  Note aggiuntive:
    Alla riga 11 ho scelto di riproporre la matrice data nel testo della prova, per semplicita' di correzione.
*/


#include <iostream>

using namespace std;

const int colonne = 5;
const int righe = 4;
char cruciverba[righe][colonne] = {
    {'A','B','I','*','I'},
    {'T','O','*','E','R'},
    {'O','B','A','M','A'},
    {'S','*','*','I','Q'}
};


//Funzione per appurare che il carattere in questione sia una lettera maiuscola o minuscola
bool controlloCarattere (char carattere) {
    if ((carattere >= 'a' && carattere <= 'z') || (carattere >= 'A' && carattere <= 'Z')) {
        return true;
    }
    else {
        return false;
    }
}


void stampaRisultato(char tabella[righe][colonne]) {
    int posizione = 0;

    // Doppio ciclo for per iterare lungo righe e colonne nel seguente modo: [0][0], [0][1], [0][2] ecc. Contatore colonne: i. Contatore righe: j.
    for (int j=0; j <= righe-1; j++) {
        for (int i=0; i<=colonne-1; i++) {
            bool orizzontaleVero = false, verticaleVero = false;

            if (controlloCarattere(tabella[j][i]) == true) {
                //Determinazione delle iniziali di parole nelle righe
                if ((i < colonne-1 && controlloCarattere(cruciverba[j][i+1]) == true) && !(i > 0 && controlloCarattere(cruciverba[j][i-1]) == true)) {
                    orizzontaleVero = true;
                }
                //Determinazione delle iniziali di parole nelle colonne
                if ((j < righe-1 && controlloCarattere(cruciverba[j+1][i]) == true) && !(j > 0 && controlloCarattere(cruciverba[j-1][i]) == true)) {
                    verticaleVero = true;
                }
             }
            //Stampa dei risultati soltanto se vi e' una parola in orizzontale o in verticale
            if (orizzontaleVero == true || verticaleVero == true) {
                posizione ++;
                cout << "Posizione " << posizione <<  ": riga " << j << ", colonna " << i;
                if (verticaleVero == true) {
                    cout << " verticale ";
                    for (int c=j; c < righe; c++){
                        //Chiamata della funzione controlloCarattere(), per stampare solo fintantoche' si trovano lettere dell'alfabeto
                        if (controlloCarattere(cruciverba[c][i])==true){
                            cout << cruciverba[c][i];
                        } else break;
                    }
                }
                if (orizzontaleVero == true) {
                    cout << " orizzontale ";
                    for (int d=i; d < colonne; d++){
                        //Chiamata della funzione controlloCarattere(), per stampare solo fintantoche' si trovano lettere dell'alfabeto
                        if (controlloCarattere(cruciverba[j][d])==true){
                            cout << cruciverba[j][d];
                        } else break;
                    }
                }
                cout << endl;
            }
        }
    }
}


int main()
{
    stampaRisultato(cruciverba);
    return 0;
}


