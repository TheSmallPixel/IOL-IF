/Fondamenti di Informatica - Seconda prova in itinere
//Nell'esecuzione ho omesso diversi controlli sull'input da tastiera per mancanza di tempo (rispetto al tempo previsto per il completamento)
//per cui il programma non ha una risposta adeguata a fronte di un input scorretto da parte dell'utente

#include <iostream>
#include <iomanip>

using namespace std;

//costanti utilizzate nel programma
const int MAXSTRING = 25; //lunghezza massima di un campo stringa generico

//tipi enumerativi utilizzati
enum TipoBicicletta {UOMO, DONNA, BAMBINO};
enum Menu {INSERISCIBICI, STAMPALISTA, INSERISCIPRENOTAZIONE, STAMPAPRENOTAZIONI, ESCI};

//struttura Data
struct Data{
    int giorno; //rappresenta un giorno dell'anno (1-366)
    int anno;
};

//struttura nodo Prenotazione
struct Prenotazione{
    char nome[MAXSTRING];
    char cognome[MAXSTRING];
    Data inizio;
    Data fine;
    Prenotazione *nextPtr;
};

//struttura nodo Bicicletta
struct Bicicletta{
    int codice;
    char marca[MAXSTRING];
    int tipo;
    Bicicletta *nextPtr;
    Prenotazione *listaPrenotazioni; //puntatore al primo nodo della lista di prenotazioni relative alla bicicletta
};

//header delle funzioni
void acquisisciDatiNuovaBicicletta(Bicicletta *&nuovaBicicletta);
void inserisciNuovaBicicletta(Bicicletta *&listaBiciclette, Bicicletta *nuovaBicicletta);
void acquisisciDatiNuovaPrenotazione(Prenotazione *&nuovaPrenotazione, Bicicletta *&biciclettaSelezionata, Bicicletta *listaBiciclette);
void inserisciNuovaPrenotazione(Prenotazione *prenotazione, Bicicletta *bicicletta);
void stampaListaBiciclette(Bicicletta *listaBiciclette, bool prenotazioni);
void stampaPrenotazioniBicicletta(Bicicletta *bicicletta);

int main(){
    
    Bicicletta *listaBiciclette = 0; //puntatore al nodo di testa della lista di biciclette
    Bicicletta *bicicletta; //puntatore per l'inserimento/ selezione di una bicicletta
    Prenotazione *prenotazione; //puntatore per l'inserimento di una prenotazione
    
    int scelta;
    
    do{
        //stampa del menu
        cout << endl << endl << "*** Gestione noleggio biciclette ***" << endl << endl;
        cout << "Selezione l'operazione che si desidera effettuare:" << endl;
        cout << INSERISCIBICI << " - Inserisci una nuova bicicletta" << endl;
        cout << STAMPALISTA << " - Stampa la lista delle biciclette" << endl;
        cout << INSERISCIPRENOTAZIONE << " - Inserisci una nuova prenotazione" << endl;
        cout << STAMPAPRENOTAZIONI << " - Stampa le prenotazioni raggruppate per bicicletta" << endl;
        cout << ESCI << " - Esci dal programma" << endl << endl;
        cin >> scelta;
        
        switch(scelta){
            case INSERISCIBICI:
            acquisisciDatiNuovaBicicletta(bicicletta);
            inserisciNuovaBicicletta(listaBiciclette, bicicletta);
            break;
            case STAMPALISTA:
            stampaListaBiciclette(listaBiciclette, false);
            break;
            case INSERISCIPRENOTAZIONE:
            //stampo a video la lista delle biciclette con le prenotazioni per dare all'utente una panoramica
            //per la scelta della bicicletta da prenotare
            stampaListaBiciclette(listaBiciclette, true);
            acquisisciDatiNuovaPrenotazione(prenotazione, bicicletta, listaBiciclette);
            inserisciNuovaPrenotazione(prenotazione, bicicletta);
            break;
            case STAMPAPRENOTAZIONI:
            stampaListaBiciclette(listaBiciclette, true);
            break;
            case ESCI:
            break;
        }//switch
        
    }while(scelta != ESCI);
    
}//main

/* Funzione richiesta dall'esercizio per l'inserimento di una bicicletta all'interno della lista.
 Ho predisposto la funzione in modo che la lista venga mantenuta in ordine di codice e che non sia
 possibile inserire due biciclette con lo stesso codice.
 listBiciclette -> parametro in ingresso/uscita Ë il puntatore al nodo di testa della lista passato per indirizzo
 nuovaBicicletta -> parametro in ingresso: Ë il puntatore alla nuova bicicletta da inserire nella lista
 */
void inserisciNuovaBicicletta(Bicicletta *&listaBiciclette, Bicicletta *nuovaBicicletta){
    
    //caso lista vuota
    if(listaBiciclette == 0){
        listaBiciclette = nuovaBicicletta;
        listaBiciclette->nextPtr = 0;
        cout << "*** Bicicletta inserita! ***" << endl;
        return;
    }//if
    
    //controllo se il codice del nuovo elemento Ë minore del codice del primo elemento della lista
    if(nuovaBicicletta->codice < listaBiciclette->codice){
        Bicicletta *appoggio = listaBiciclette;
        listaBiciclette = nuovaBicicletta;
        nuovaBicicletta->nextPtr = appoggio;
        cout << "*** Bicicletta inserita! ***" << endl;
        return;
    }//if
    
    Bicicletta *tempPtr = listaBiciclette;
    
    //ricerca della posizione in cui inserire l'elemento
    do{
        
        if(nuovaBicicletta->codice == tempPtr->codice){
            cout << "Esiste gi‡ una bicicletta con questo codice!" << endl;
            return;
        }//if
        else if(tempPtr->nextPtr != 0){
            if(nuovaBicicletta->codice > tempPtr->codice && nuovaBicicletta->codice < tempPtr->nextPtr->codice){
                Bicicletta *appoggio = tempPtr->nextPtr;
                nuovaBicicletta->nextPtr = appoggio;
                tempPtr->nextPtr = nuovaBicicletta;
                cout << "*** Bicicletta inserita! ***" << endl;
                return;
            }//if
        }//else
        else{
            tempPtr->nextPtr = nuovaBicicletta;
            nuovaBicicletta->nextPtr = 0;
            cout << "*** Bicicletta inserita! ***" << endl;
            return;
        }//else
        
        tempPtr = tempPtr->nextPtr;
        
    }while(tempPtr != 0);
    
}//inserisciNuovaBicicletta

/* Funzione richiesta dall'esercizio per l'inserimento di una nuova prenotazione per una data bicicletta.
 Agendo secondo logica ho predisposto che non le prenotazioni non possano essere sovrapposte (se la bicicletta
 Ë occupata in un dato giorno non sar‡ possibile prenotarla nuovamente per lo stesso giorno).
 prenotazione -> parametro in ingresso Ë il puntatore al nodo alla prenotazione di inserire nella lista
 bicicletta -> parametro in ingresso: Ë il puntatore alla bicicletta su cui si vuole inserire la prenotazione
 */
void inserisciNuovaPrenotazione(Prenotazione *prenotazione, Bicicletta *bicicletta){
    
    //caso lista prenotazioni vuota
    if(bicicletta->listaPrenotazioni == 0){
        prenotazione->nextPtr = 0;
        bicicletta->listaPrenotazioni = prenotazione;
        cout << endl << "*** Prenotazione inserita! ***" << endl;
        return;
    }//if
    
    //puntatore di appoggio per scorrere la lista
    Prenotazione *temp = bicicletta->listaPrenotazioni;
    
    //controllo se la prenotazione Ë precedente al primo elemento della lista prenotazioni
    if(prenotazione->fine.anno < temp->inizio.anno || (prenotazione->fine.anno == temp->inizio.anno && prenotazione->fine.giorno < temp->inizio.giorno)){
        
        prenotazione->nextPtr = temp;
        bicicletta->listaPrenotazioni = prenotazione;
        cout << endl << "*** Prenotazione inserita! ***" << endl;
        return;
        
    }//if
    
    //ricerca della posizione in cui inserire l'elemento
    do{
        
        //verifica coerenza della prontazione (eventuali sovrapposizioni di date con l'elemento puntato da temp)
        if(prenotazione->inizio.anno > temp->fine.anno || (prenotazione->inizio.anno == temp->fine.anno  && prenotazione->inizio.giorno > temp->fine.giorno)){
            
            //se siamo alla fine della lista inserisce la prenotazione
            if(temp->nextPtr == 0){
                prenotazione->nextPtr = 0;
                temp->nextPtr = prenotazione;
                cout << endl << "*** Prenotazione inserita! ***" << endl;
                return;
            }//if
            
            //se il nuovo elemento Ë compreso tra l'elemento puntato da temp e l'elemento puntato da temp->nextPtr inserisce l'elemento
            if(prenotazione->fine.anno < temp->nextPtr->inizio.anno || (prenotazione->fine.anno == temp->nextPtr->inizio.anno  && prenotazione->fine.giorno < temp->nextPtr->inizio.giorno)){
                Prenotazione *appoggio = temp->nextPtr;
                prenotazione->nextPtr = appoggio;
                temp->nextPtr = prenotazione;
                cout << endl << "*** Prenotazione inserita! ***" << endl;
                return;
            }//if
            
        }//if
        else{
            cout << endl << "*** Errore: bicicletta non disponibili nei giorni scelti ***" << endl;
            return;
        }//else
        
        temp = temp->nextPtr;
        
    }while(temp != 0);
    
}//inserisciNuovaPrenotazione

//Funzione per l'acquisizione dei dati di una nuova bicicletta
//Non ho eseguito molti controlli sull'input per mancanza di tempo
void acquisisciDatiNuovaBicicletta(Bicicletta *&nuovaBicicletta){
    
    cout << endl << endl << "*** Inserimento nuova bicicletta ***" << endl << endl;
    nuovaBicicletta = new Bicicletta;
    cout << "Inserisci codice: \n";
    cin >> nuovaBicicletta->codice;
    cout << "Inserisci marca: \n";
    cin >> nuovaBicicletta->marca;
    do{
        cout << "Tipo bicicletta (0 - UOMO, 1 - DONNA, 2 - BAMBINO):\n";
        cin >> nuovaBicicletta->tipo;
    }while(nuovaBicicletta->tipo < UOMO || nuovaBicicletta->tipo> BAMBINO);
    
    nuovaBicicletta->listaPrenotazioni = 0;
    
}//acquisisciDatiNuovaBicicletta

//Funzione che acquisisce le informazioni sulla prenotazione prima di effettuarne l'inserimento
void acquisisciDatiNuovaPrenotazione(Prenotazione *&nuovaPrenotazione, Bicicletta *&biciclettaSelezionata, Bicicletta *listaBiciclette){
    
    //caso lista vuota
    if(listaBiciclette == 0){
        cout << endl << "*** Operazione impossibile: nessuna bicicletta presente in archivio ***" << endl;
        return;
    }//if
    
    int codiceSelezionato;
    biciclettaSelezionata = 0;
    
    //selezione della bicicletta su cui inserire la prenotazione
    do{
        cout << "Inserire il codice della bicicletta da prenotare: ";
        cin >> codiceSelezionato;
        
        Bicicletta *temp = listaBiciclette;
        while(temp != 0){
            if(temp->codice == codiceSelezionato){
                biciclettaSelezionata = temp;
                break;
            }//if
            temp = temp->nextPtr;
        }//while
        if(biciclettaSelezionata == 0)
        cout << "*** Errore! il codice selezionato non Ë presente in archivio, ritentare. ***" << endl;
        
    }while(biciclettaSelezionata == 0);
    
    nuovaPrenotazione = new Prenotazione;
    
    //richiesta delle informazioni di prenotazione
    cout << endl << "Informazioni sulla prenotazione" << endl;
    cout << endl << "Cognome: ";
    cin >> nuovaPrenotazione->cognome;
    cout << "Nome: ";
    cin >> nuovaPrenotazione->nome;
    
    //Per mancanza di tempo non ho effettuato controlli sull'input quali inserimento di numero
    //intero positivo nel range designato
    cout << "Giorno inizio (1-365): ";
    cin >> nuovaPrenotazione->inizio.giorno;
    cout << "Anno inizio (4 cifre): ";
    cin >> nuovaPrenotazione->inizio.anno;
    bool inserimentoOk = false;
    do{
        cout << "Giorno fine (1-365): ";
        cin >> nuovaPrenotazione->fine.giorno;
        cout << "Anno fine (4 cifre): ";
        cin >> nuovaPrenotazione->fine.anno;
        
        if(nuovaPrenotazione->fine.anno > nuovaPrenotazione->inizio.anno ||
           (nuovaPrenotazione->fine.anno == nuovaPrenotazione->inizio.anno && nuovaPrenotazione->fine.giorno >= nuovaPrenotazione->inizio.giorno))
        inserimentoOk = true;
        else
        cout << "La data di fine deve essere superiore alla data inizio!" << endl;
        
    }while(!inserimentoOk);
    
    
}//acquisisciDatiNuovaPrenotazione

//Funzione che effettua una stampa della lista di biciclette
//Il parametro prenotazioni indica se vanno stampate a video anche le prenotazioni di ogni bicicletta
void stampaListaBiciclette(Bicicletta *listaBiciclette, bool prenotazioni){
    
    if(prenotazioni)
    cout << endl << endl << "*** Lista biciclette e relative prenotazioni: ***"<< endl;
    else
    cout << endl << endl << "*** Lista biciclette: ***"<< endl;
    //stampa lista bici
    Bicicletta *temp = listaBiciclette;
    while(temp != 0){
        cout << endl << "Codice: " << setw(5) << temp->codice << " - Marca: " << setw(25) << temp->marca << " - Tipo: ";
        switch(temp->tipo){
            case UOMO:
            cout << "Uomo";
            break;
            case DONNA:
            cout << "Donna";
            break;
            case BAMBINO:
            cout << "Bambino";
            break;
        }//switch
        if(prenotazioni && temp->listaPrenotazioni != 0)
        stampaPrenotazioniBicicletta(temp);
        temp = temp->nextPtr;
    }//while
    cout << endl << endl;
    
}//stampaListaBiciclette

//funzione che stampa tutte le prenotazioni di una bicicletta
void stampaPrenotazioniBicicletta(Bicicletta *bicicletta){
    
    Prenotazione *temp = bicicletta->listaPrenotazioni;
    
    while(temp != 0){
        cout << endl;
        cout << "---- Prenotata dal: " << setw(3) << temp->inizio.giorno << "/" << setw(4) << temp->inizio.anno << " al ";
        cout << setw(3) << temp->fine.giorno << "/" << setw(4) << temp->fine.anno << " - " << temp->cognome << " " << temp->nome;
        temp = temp->nextPtr;
    }//while
    cout << endl;
    
}//stampaPrenotazioniBicicletta

