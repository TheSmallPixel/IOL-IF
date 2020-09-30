
// corso : informatica 1
//


//programma per simulare una roulette semplificata 

//#include "stdafx.h"    //qs mi serve per Visual C++
#include <iostream>
#include <time>

//dichiaro tipi e variabili necessarie
using namespace std;

const int PARI=0;        //le due possibili puntati per scommesse di tipo  
const int DISPARI=1;     // pari o dispari
      
enum TipoPuntata {Numero,PariDispari};  //per referenziare il tipo di puntata: 
                                        // singolo numero , pari o dispari
int posta [2] = {36, 2}; //array per memorizzare il "numero di volte la posta"
                         // da pagare per ogni tipo di giocata           

struct Puntata {         //record per memorizzare la singola puntata
  TipoPuntata tipo;      //il tipo di puntata: singolo numero,pari o dispari
  int importo;           //l'importo puntato
  int giocatore;         //il codice del giocatore
  int scelta;            //il numero puntato (se singolo numero ) o una
                         // delle due costanti PARI o DISPARI
};

struct Puntate {   //elemento della lista per memorizzare tutte le puntate
  Puntata puntata; //la singola puntata
  Puntate *succ;   //puntatore alla prossima
};

/*------------------------------------------------/
/     dichiaro la classe principale               /
/------------------------------------------------*/

class Roulette {
  public:
    Roulette(int); //costruttore, in input il capitale iniziale del banco
    ~Roulette();   //distruttore
    int getCapitale();     //ritorna il capitale del banco
    void accettaPuntata(Puntata); //funzione per inserire la singola puntata
    void estrai();         //funzione per "girare la roulette" 
    int getEstratto();     //ritorna il numero estratto
    int getTotPuntate();   //ritorna il totale delle puntate attuali
    int getVincite();      //ritorna il totale delle vincite dei giocatori
    int getVincitaBanco(); //ritorna il totale delle vincite del banco
    void pagaVincite() ;   //paga le vincite ed aggiorna per un nuovo gioco 
  private:
    int capitale;          //capitale corrente di cui dispone il banco
    int estratto;          //numero uscito dopo la girata
    int totPuntate;        //totale delle puntate correnti
    int totVincite;        //totale vinto dai giocatori
    Puntate *puntate ;     //lista contenente le puntate
    void calcolaVincite(); //calcola il totale delle vincite
    void azzeraPuntate();  //dealloca la lista delle puntate
};

/*------------------------------------------------/
/ implemento le funzioni della classe             /
/------------------------------------------------*/ 

Roulette::Roulette(int capIniziale) {
  capitale = capIniziale ;
  puntate=NULL;
  totPuntate=0;
  totVincite=0;
  estratto=-1;  //inizializzo il numero estratto a -1 per essere sicuro
                // che non ci siano vincite senza girare la ruota
}

Roulette::~Roulette() {
  //dealloca le puntate
  azzeraPuntate();
  //saluta
  cout << "Arrivederci alla prossima giocata" << endl << endl;
}

int Roulette::getCapitale() {
  return capitale;
}

void Roulette::accettaPuntata(Puntata nuovaPuntata){
  Puntate *temp;
  //do' per scontato che la puntata sia "valida"
  //creo la nuova puntata
  temp = new Puntate;
  temp->puntata = nuovaPuntata;
  //inserisco il nuovo elemento in testa alla lista
  temp->succ = puntate;
  puntate = temp;
  //confermo l'inserimento
  cout << "Giocatore " << nuovaPuntata.giocatore << " la tua puntata di " ;
  cout << nuovaPuntata.importo ;
  if (nuovaPuntata.tipo == Numero) {
    cout << " sul numero " << nuovaPuntata.scelta ;
  } else {
    cout << " sul " << ( nuovaPuntata.scelta == PARI ? "pari" : "dispari" ) ;
  }  
  cout << " e' stata accettata" << endl;
  // incremento il totale delle puntate correnti
  totPuntate += nuovaPuntata.importo;
}

void Roulette::estrai(){
  //estrazione
  srand(time(0));            //rende la sequenza casuale
  estratto = rand()%(36+1);  //formula per avere un numero casuale tra 0 e 36
  //calcolo del totale vincite dei giocatori
  calcolaVincite();
}


int Roulette::getEstratto() {
  return estratto;
}

int Roulette::getTotPuntate() {
  return totPuntate;
}

int Roulette::getVincite() {
  //ho scelto di richiamare il calcolo del totale delle vincite dalla
  // funzione Roulette::estrai() in modo che il membro totVincite sia
  // valorizzato anche se non lo interrogo con questa funzione
  return totVincite ;
}  

int Roulette::getVincitaBanco() {
  return (totPuntate - totVincite);
}

void Roulette::pagaVincite() {
  //verifico se i soldi sono sufficienti per pagare
  if ( capitale + totPuntate - totVincite >= 0 ) {
    capitale += ( totPuntate - totVincite ) ;
    cout << "Tutte le vincite sono state saldate" << endl;
  } else {
    //la specifica non dice cosa fare del capitale in qs caso;
    // ho deciso di non modificarlo
    cout << "Il banco salta: soldi insufficienti per saldare le vincite!!";
    cout << endl;
  }
  //azzero tutte le giocate e reimposto la roulette
  azzeraPuntate();
}

void Roulette::calcolaVincite() {
  Puntate *temp;
  //scorro la lista delle puntate
  for (temp=puntate;temp!=NULL;temp=temp->succ) {
  //la puntata corrente ha vinto se il tipo e' numero semplice ed il numero
  // e' giusto, oppure se il tipo e' PARI/DISPARI ed ha indovinato
    if ((temp->puntata.tipo == Numero && temp->puntata.scelta == estratto ) ||
        (temp->puntata.tipo == PariDispari &&
          temp->puntata.scelta == estratto % 2 )) {
      //incremento il tot vincite dell'importo scommesso * il moltiplicatore
      // adeguato
      totVincite+= temp->puntata.importo * posta[temp->puntata.tipo] ;
    }
  }
}

void Roulette::azzeraPuntate() {
  Puntate *temp;
  //dealloco la lista delle puntate
  for (temp=puntate; temp != NULL; temp=temp->succ, 
                                   delete puntate, 
                                   puntate = temp);
  //resetto le variabili membro della classe
  estratto= -1;
  totPuntate=0;
  totVincite=0;
}

/*------------------------------------------------------------------/
/ non richiesto dalla prova: funzione main per testare la classe    /
/------------------------------------------------------------------*/ 

int main() {
  Puntata miaPuntata;
  
  cout << endl << "Benvenuti nel programma di simulazione roulette " << endl; 
  //test del costruttore
  Roulette sanRemo(100); //dichiaro la mia roulette col capitale iniziale 1000
  //test di visualizzazione del capitale
  cout << "Il capitale del banco ammonta a " << sanRemo.getCapitale();
  cout << endl;
  //inserisco alcune puntate singole
  miaPuntata.tipo=Numero;
   importo=5;  
  miaPuntata.giocatore=1;
  miaPuntata.scelta=12;
  sanRemo.accettaPuntata(miaPuntata);
  cout << "il totale delle puntate ammonta a " << sanRemo.getTotPuntate() << endl;
  miaPuntata.tipo=Numero;
  miaPuntata.importo=10;  
  miaPuntata.giocatore=2;
  miaPuntata.scelta=25;
  sanRemo.accettaPuntata(miaPuntata);
  cout << "il totale delle puntate ammonta a " << sanRemo.getTotPuntate() << endl;
  miaPuntata.tipo=Numero;
  miaPuntata.importo=2;  
  miaPuntata.giocatore=3;
  miaPuntata.scelta=36;
  sanRemo.accettaPuntata(miaPuntata);
  cout << "il totale delle puntate ammonta a " << sanRemo.getTotPuntate() << endl;
  //inserisco alcune puntate pari/dispari
  miaPuntata.tipo=PariDispari;
  miaPuntata.importo=15;  
  miaPuntata.giocatore=1;
  miaPuntata.scelta=PARI;
  sanRemo.accettaPuntata(miaPuntata);
  cout << "il totale delle puntate ammonta a " << sanRemo.getTotPuntate() << endl;
  miaPuntata.tipo=PariDispari;
  miaPuntata.importo=100;  
  miaPuntata.giocatore=4;
  miaPuntata.scelta=PARI;
  sanRemo.accettaPuntata(miaPuntata);
  cout << "il totale delle puntate ammonta a " << sanRemo.getTotPuntate() << endl;
  miaPuntata.tipo=PariDispari;
  miaPuntata.importo=150;  
  miaPuntata.giocatore=2;
  miaPuntata.scelta=DISPARI;
  sanRemo.accettaPuntata(miaPuntata);
  cout << "il totale delle puntate ammonta a " << sanRemo.getTotPuntate() << endl;
  miaPuntata.tipo=PariDispari;
  miaPuntata.importo=80;  
  miaPuntata.giocatore=3;
  miaPuntata.scelta=DISPARI;
  sanRemo.accettaPuntata(miaPuntata);
  cout << "il totale delle puntate ammonta a " << sanRemo.getTotPuntate() << endl;
  //giro la routa e leggo il numero estratto
  sanRemo.estrai();
  cout << "Il numero uscito e' " << sanRemo.getEstratto() << endl;
  //test della stampa vincite da pagare
  cout << "Il totale delle vincite e' " << sanRemo.getVincite() << endl;
  //test della stampa vincita del banco
  cout << "Il banco vince " << sanRemo.getVincitaBanco() << endl;  
  //test del pagamento
  sanRemo.pagaVincite() ;
  cout << "Il nuovo capitale del banco e' " << sanRemo.getCapitale() << endl;
  //test del distruttore: e' chiamato in automatico alla fine
  system ("pause");
}

